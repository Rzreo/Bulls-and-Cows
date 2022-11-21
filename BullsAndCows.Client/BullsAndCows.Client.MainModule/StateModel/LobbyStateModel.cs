namespace BullsAndCows.Client.MainModule
{
    using System.Collections.ObjectModel;
    using System.Windows.Data;
    using Prism.Services.Dialogs;
    using Reactive.Bindings;
    using BullsAndCows.Infrastructure;
    using BullsAndCows.Infrastructure.ClientServices;
    using BullsAndCows.Infrastructure.OperationManagement;
    using BullsAndCows.Infrastructure.Utils;
    using Newtonsoft.Json;
    using Newtonsoft.Json.Linq;
    using System.Windows.Interop;

    public class LobbyStateModel : StateModel
    {
        IServerConnectingService _connect;
        IGameManageService _game;
        object _lock = new object();
        Task? background;
        public ObservableCollection<BAC_ROOM_DATA> RoomDatas { get; private set; }
        public ReactiveProperty<int> CurrentPageNumber { get; private set; } = new ReactiveProperty<int>() { Value = 0 };
        public ReactiveProperty<int> LastPageNumber { get; private set; } = new ReactiveProperty<int>() { Value = 0 };
        public LobbyStateModel(IServerConnectingService connect, IGameManageService game)
        {
            this._connect = connect;
            this._game = game;

            RoomDatas = new ObservableCollection<BAC_ROOM_DATA>();
            BindingOperations.EnableCollectionSynchronization(RoomDatas, _lock);

            EnterState();
            _connect.StartConnect();
        }

        #region StateModel
        protected override void EnterState()
        {
            _connect.ReceiveServerMessageOnUI += ReceiveMessageOnUI;           
            background = Task.Factory.StartNew(UpdateRoomData);

            base.EnterState();
        }
        protected override void ExitState()
        {
            base.ExitState();

            _connect.ReceiveServerMessageOnUI -= ReceiveMessageOnUI;
            background?.Wait();
        }
        public override bool bValidState { get; protected set; }
        #endregion

        void UpdateRoomData()
        {
            while (bValidState)
            {
                _connect.RequestRoomList(0);
                Thread.Sleep(500);
            }
        }

        #region Receive Message

        public event Action<BAC_SERVER_CONNECT_MESSAGE>? ReceivedRoomList;
        void ReceiveMessageOnUI(object s)
        {
            if (s is BAC_SERVER_CONNECT_MESSAGE msg)
            {
                switch (msg.type)
                {
                    case SERVER_CONNECT_MESSAGE_TYPE.SERVER_CONNECT_SUCCESS: OnConnectSuccess(msg); break;
                    case SERVER_CONNECT_MESSAGE_TYPE.SEND_ROOM_LIST: OnReceiveRoomList(msg); break;
                    case SERVER_CONNECT_MESSAGE_TYPE.CREATE_ROOM_SUCCESS: OnCreateRoomSuccess(msg); break;
                    case SERVER_CONNECT_MESSAGE_TYPE.ENTER_ROOM_SUCCESS: OnEnterRoomSuccess(msg); break;
                }
            }
        }
        void OnConnectSuccess(BAC_SERVER_CONNECT_MESSAGE msg)
        {
            UIThreadHelper.CheckAndInvokeOnUIDispatcher(() =>
            {
                _connect.RequestRoomList(CurrentPageNumber.Value = 1);
            });
        }
        void OnReceiveRoomList(BAC_SERVER_CONNECT_MESSAGE msg)
        {
            UIThreadHelper.CheckAndInvokeOnUIDispatcher(() =>
            {
                JObject obj = JObject.Parse(msg.msg);
     
                LastPageNumber.Value = obj["pageNum"]?.Value<int>() ?? default(int);

                RoomDatas.Clear();
                foreach (var data in (obj["RoomList"] as JArray).OrEmptyIfNull())
                {
                    BAC_ROOM_DATA roomData = JsonConvert.DeserializeObject<BAC_ROOM_DATA>(data.ToString());
                    RoomDatas.Add(roomData);
                }

                ReceivedRoomList?.Invoke(msg);
            });
        }
        void OnCreateRoomSuccess(BAC_SERVER_CONNECT_MESSAGE msg)
        {
            UIThreadHelper.CheckAndInvokeOnUIDispatcher(() =>
            {
                BAC_ROOM_DATA room_data = JsonConvert.DeserializeObject<BAC_ROOM_DATA>(msg.msg);
                _connect.EnterRoom(room_data.RoomID);
            });
        }
        void OnEnterRoomSuccess(BAC_SERVER_CONNECT_MESSAGE msg)
        {
            UIThreadHelper.CheckAndInvokeOnUIDispatcher(() =>
            {
                ExitState();
                _game.GoToWaitting();
            });
        }

        #endregion
    }
}
