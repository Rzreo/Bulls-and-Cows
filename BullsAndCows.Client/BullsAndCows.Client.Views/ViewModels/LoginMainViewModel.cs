﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows.Client.Views.ViewModels
{
    using BullsAndCows.Infrastructure;
    using BullsAndCows.Infrastructure.BaseClass;
    using BullsAndCows.Infrastructure.Net;
    using BullsAndCows.Infrastructure.OperationManagement;
    using BullsAndCows.Infrastructure.Utils;
    using Prism.Commands;
    using System.Collections.ObjectModel;
    using System.Windows.Data;
    using System.Windows.Interop;
    using System.Windows.Threading;

    class LoginMainViewModel : ViewModelBase
    {
        IDDSService _dds;
        IConfigService _config;
        object _lock = new object();
        public ObservableCollection<BAS_ROOM_DATA> RoomDatas { get; private set; }
        public LoginMainViewModel(IDDSService dds, IConfigService config)
        {
            this._dds = dds;
            this._config = config;

            RoomDatas = new ObservableCollection<BAS_ROOM_DATA>();
            BindingOperations.EnableCollectionSynchronization(RoomDatas, _lock);

            ConnectInit();
        }
        void ConnectInit()
        {
            _dds.Write(typeof(BAC_CONNECT_INIT_MESSAGE), nameof(BAC_CONNECT_INIT_MESSAGE),
                new BAC_CONNECT_INIT_MESSAGE()
                {
                    CLIENT_ID = _config.ClientID()
                });
            _dds.RegisterEvent(typeof(BAC_CONNECT_MESSAGE), nameof(BAC_CONNECT_MESSAGE) + _config.ClientID(), ReceiveMessage);
        }
        void ReceiveMessage(object s)
        {
            BAC_CONNECT_MESSAGE msg = s as BAC_CONNECT_MESSAGE;
            switch(msg.type)
            {
                case CLIENT_CONNECT_MESSAGE_TYPE.SERVER_CONNECT_SUCCESS: OnConnectSuccess(msg); break;
                case CLIENT_CONNECT_MESSAGE_TYPE.SEND_ROOM_LIST: OnSendRoomList(msg); break;

            }
        }

        void OnConnectSuccess(BAC_CONNECT_MESSAGE msg)
        {
            _dds.Write(typeof(BAC_CONNECT_MESSAGE), nameof(BAC_CONNECT_MESSAGE) + _config.ClientID(),
                   new BAC_CONNECT_MESSAGE()
                   {
                       type = CLIENT_CONNECT_MESSAGE_TYPE.GIVE_ROOM_LIST
                   });
        }

        void OnSendRoomList(BAC_CONNECT_MESSAGE msg)
        {
            UIThreadHelper.CheckAndInvokeOnUIDispatcher(
            () =>
            {
                RoomDatas = Newtonsoft.Json.JsonConvert.DeserializeObject<ObservableCollection<BAS_ROOM_DATA>>(msg.msg);
                BindingOperations.EnableCollectionSynchronization(RoomDatas, _lock);
            });
        }

        #region CreateRoom
        DelegateCommand _CreateRoomCommand;
        public DelegateCommand CreateRoomCommand
        {
            get
            {
                if (_CreateRoomCommand == null)
                {
                    _CreateRoomCommand = new DelegateCommand(CreateRoom, () => { return true; });
                }
                return _CreateRoomCommand;
            }
        }
        void CreateRoom()
        {
            _dds.Write(typeof(BAC_CONNECT_MESSAGE), nameof(BAC_CONNECT_MESSAGE) + _config.ClientID(),
                new BAC_CONNECT_MESSAGE()
                {
                    type = CLIENT_CONNECT_MESSAGE_TYPE.CREATE_ROOM
                });
        }
        #endregion
    }
}
