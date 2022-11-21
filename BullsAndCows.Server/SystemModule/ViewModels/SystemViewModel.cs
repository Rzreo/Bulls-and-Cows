namespace SystemModule.ViewModels
{
    using BullsAndCows.Server.Net;
    using BullsAndCows.Infrastructure;
    using Prism.Commands;
    using Prism.Mvvm;
    using Reactive.Bindings;
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Windows.Forms;
    using BullsAndCows.Infrastructure.Net;
    using BullsAndCows.Infrastructure.Utils;
    using System.Reactive.Disposables;
    using System.Windows.Data;
    using ICSharpCode.AvalonEdit.Document;
    using System.ComponentModel;
    using System.Threading;
    using GameModel;
    using Newtonsoft.Json;

    public class SystemViewModel : BindableBase, IDisposable
    {
        public class RoomInfoData
        {
            public BAC_ROOM_DATA RoomData { get; set; }
            public List<string> Clients { get; set; }
        }
        public class Clients
        {
            public string ClientInfo { get; set; }
        }
        public ReactiveCollection<Clients> ConnectList { get; }
        public Dictionary<string,int> ClientRoomPair { get; set; }

        public ReactiveCollection<RoomInfoData> JoinableList { get; }

        public ReactiveCollection<RoomInfoData> PlayingList { get; }



        /// <summary>
        /// //
        /// </summary>
        public ReactiveCollection<MSGcontainer> RecvMessages { get; }

        public ReactiveCollection<MSGcontainer> SendMessages { get; }

        public ReactiveCommand SendClearFunction { get; set; } = new ReactiveCommand();
        public ReactiveCommand RecvClearFunction { get; set; } = new ReactiveCommand();

        public ReactiveProperty<MSGcontainer> SelectedLogLeft { get; set; } = new ReactiveProperty<MSGcontainer>();
        public ReactiveProperty<MSGcontainer> SelectedLogRight { get; set; } = new ReactiveProperty<MSGcontainer>();
        public ReactiveProperty<TextDocument> LogDocumentLeft { get; } = new ReactiveProperty<TextDocument>();

        public ReactiveProperty<TextDocument> LogDocumentRight { get; } = new ReactiveProperty<TextDocument>();

        public ReactiveProperty<RoomInfoData> SelectedJoinLeft { get; set; } = new ReactiveProperty<RoomInfoData>();
        public ReactiveProperty<TextDocument> JoinDocumentLeft { get; } = new ReactiveProperty<TextDocument>();

        private DDSService dds;
        object _lock = new object();
        int RoomCount;
        GameModel model;
        public SystemViewModel(DDSService dds, GameModel _model)
        {
            ConnectList = new ReactiveCollection<Clients>();
            BindingOperations.EnableCollectionSynchronization(ConnectList, _lock);

            JoinableList = new ReactiveCollection<RoomInfoData>();
            BindingOperations.EnableCollectionSynchronization(JoinableList, _lock);

            PlayingList = new ReactiveCollection<RoomInfoData>();
            BindingOperations.EnableCollectionSynchronization(PlayingList, _lock);

            LogDocumentLeft.Value = new TextDocument();
            LogDocumentLeft.Value.UndoStack.SizeLimit = 0;

            LogDocumentRight.Value = new TextDocument();
            LogDocumentRight.Value.UndoStack.SizeLimit = 0;

            JoinDocumentLeft.Value = new TextDocument();
            JoinDocumentLeft.Value.UndoStack.SizeLimit = 0;

            //unitTest.SelectedItem.Subscribe((data) =>
            //{
            //    LogDocument.Value.Text = string.Empty;

            //    if (data != null)
            //        LogDocument.Value.Text = data.Values;
            //}).AddTo(disposables);


            SendClearFunction.Subscribe(() => {
                dds.SendClearEvent();
            });
            RecvClearFunction.Subscribe(() => {
                dds.RecvClearEvent();
            });
            SelectedLogLeft.Subscribe(item =>
            {
                if (item is null) return;
                LogDocumentLeft.Value.Text = string.Empty;

                if (item != null)
                {
                    OpenContainer(item, true);
                }
            });

            SelectedLogRight.Subscribe(item =>
            {
                if (item is null) return;
                LogDocumentRight.Value.Text = string.Empty;

                if (item != null)
                {
                    OpenContainer(item, false);
                }

            });

            SelectedJoinLeft.Subscribe(item =>
            {
                if (item is null) return;
                JoinDocumentLeft.Value.Text = string.Empty;

                if (item != null)
                {
                    OpenRoomInfo(item, true);
                }
            });

            ClientRoomPair = new Dictionary<string, int>();
            this.dds = dds;
            this.model = _model;
            RoomCount = 1;
            RecvMessages = dds.RCVmessages;
            SendMessages = dds.SNDmessages;
            InitializeDDS();
        }

        public void OpenContainer(MSGcontainer container, bool left)
        {
            if (container.data.GetType() == typeof(BAC_CONNECT_INIT_MESSAGE))
            {
                BAC_CONNECT_INIT_MESSAGE init = (BAC_CONNECT_INIT_MESSAGE)container.data;
                if(left) LogDocumentLeft.Value.Text = $"Clinet_id: {init.CLIENT_ID}";
                else LogDocumentRight.Value.Text = $"Clinet_id: {init.CLIENT_ID}";
            }
            else if (container.data.GetType() == typeof(BAC_CLIENT_CONNECT_MESSAGE))
            {
                BAC_CLIENT_CONNECT_MESSAGE init = (BAC_CLIENT_CONNECT_MESSAGE)container.data;
                if (left) LogDocumentLeft.Value.Text = $"Type: {init.type}\nMsg: {init.msg.Replace(',', '\n')}";
                else LogDocumentRight.Value.Text = $"Type: {init.type}\nMsg: {init.msg.Replace(',', '\n')}";
            }
            else if (container.data.GetType() == typeof(BAC_SERVER_CONNECT_MESSAGE))
            {
                BAC_SERVER_CONNECT_MESSAGE init = (BAC_SERVER_CONNECT_MESSAGE)container.data;
                if (left) LogDocumentLeft.Value.Text = $"Type: {init.type}\nMsg: {init.msg.Replace(',', '\n')}";
                else LogDocumentRight.Value.Text = $"Type: {init.type}\nMsg: {init.msg.Replace(',', '\n')}";
            }
        }

        public void OpenRoomInfo(RoomInfoData container, bool left)
        {
            string text = $"RoomID: {container.RoomData.RoomID}\nMaxMembers: {container.RoomData.Max_Num_Participants}\nCurmembers: {container.RoomData.Cur_Num_Participants}\nClients: \n";
            foreach (string s in container.Clients) { text += $"{s}\n"; }
            if (left) JoinDocumentLeft.Value.Text = text;
            //else PlayingDocumentRight.Value.Text = text;
            
        }
        public void InitializeDDS()
        {
            dds.RegisterEvent(typeof(BAC_CONNECT_INIT_MESSAGE), nameof(BAC_CONNECT_INIT_MESSAGE), data => ReceiveConnectMsg(data as BAC_CONNECT_INIT_MESSAGE));
            //dds.RegisterEvent(typeof(BAC_SERVER_CONNECT_MESSAGE), nameof(BAC_SERVER_CONNECT_MESSAGE) + "1-0", data => ReceiveServerMsg(data as BAC_SERVER_CONNECT_MESSAGE, "123")); ;
        }

        private void ReceiveClientMsg(BAC_CLIENT_CONNECT_MESSAGE data, string _clientid) // 메세지 수신 시
        {
            if (data is null) return;
            else if (data.type == CLIENT_CONNECT_MESSAGE_TYPE.CREATE_ROOM) RoomMake(data, _clientid);
            else if (data.type == CLIENT_CONNECT_MESSAGE_TYPE.REQUEST_ROOM_LIST) SendRoomList(data, _clientid);
            else if (data.type == CLIENT_CONNECT_MESSAGE_TYPE.ENTER_ROOM) EnterRoom(data, _clientid);
            else if (data.type == CLIENT_CONNECT_MESSAGE_TYPE.REQUEST_ROOM_DATA) ResendRoomData(data, _clientid);
            else if (data.type == CLIENT_CONNECT_MESSAGE_TYPE.SEND_GAME_INPUT) SendGameoutput(data, _clientid); 
        }

        struct RoomListContainer//페이지 전송을 위한 구조체
        {
            public double pageNum { get; set; }
            public List<BAC_ROOM_DATA> RoomList { get; set; }
        }
        private void SendRoomList(BAC_CLIENT_CONNECT_MESSAGE data, string _clientid) //입장 가능한 방 정보 전송
        {
            try
            {
                if (!Int32.TryParse(data.msg, out int pnum)) return;
                if (pnum > Math.Ceiling((double)JoinableList.Count / 8)) return;
                List<RoomInfoData> copy;
                if (pnum * 8 > JoinableList.Count) copy = JoinableList.ToList().GetRange((pnum - 1) * 8, JoinableList.Count - (pnum - 1) * 8);
                else copy = JoinableList.ToList().GetRange((pnum - 1) * 8, 8);

                List<BAC_ROOM_DATA> temp = new List<BAC_ROOM_DATA>();
                foreach (RoomInfoData r in copy)
                {
                    temp.Add(r.RoomData);
                }
                RoomListContainer container = new RoomListContainer() { pageNum = Math.Ceiling((double)JoinableList.Count / 8), RoomList = temp };
                //System.Diagnostics.Debug.WriteLine(container.RoomList.Count);

                string ans = Newtonsoft.Json.JsonConvert.SerializeObject(container);
                UIThreadHelper.CheckAndInvokeOnUIDispatcher(() => {
                    dds.Write(typeof(BAC_SERVER_CONNECT_MESSAGE), nameof(BAC_SERVER_CONNECT_MESSAGE) + _clientid,
                        new BAC_SERVER_CONNECT_MESSAGE
                        {
                            type = SERVER_CONNECT_MESSAGE_TYPE.SEND_ROOM_LIST,
                            msg = ans
                        }
                    );
                });
            }
            catch(Exception e)
            {
                return;
            }

            
        }
        private void RoomMake(BAC_CLIENT_CONNECT_MESSAGE d, string _clientid) //방 생성
        {
            if (!Int32.TryParse(d.msg, out int mem)) return;
            RoomInfoData data = new RoomInfoData() { RoomData = new BAC_ROOM_DATA { RoomID=(uint)RoomCount++, Max_Num_Participants = (uint)mem, Cur_Num_Participants = 0} , Clients = new List<string>() };
            JoinableList.Add(data);
            System.Diagnostics.Debug.WriteLine(JoinableList.Count);
            string ans = Newtonsoft.Json.JsonConvert.SerializeObject(data.RoomData);
            Console.WriteLine(ans);
            UIThreadHelper.CheckAndInvokeOnUIDispatcher(() =>
            {
                dds.Write(typeof(BAC_SERVER_CONNECT_MESSAGE), nameof(BAC_SERVER_CONNECT_MESSAGE) + _clientid,
                    new BAC_SERVER_CONNECT_MESSAGE
                    {
                        type = SERVER_CONNECT_MESSAGE_TYPE.CREATE_ROOM_SUCCESS,
                        msg = ans
                    }
                ); ;
            });
        }
        private void ReceiveConnectMsg(BAC_CONNECT_INIT_MESSAGE data) //연결 메세지 수신 시
        {
            if (data is null) return;
            bool canConnect = true;
            foreach (Clients c in ConnectList)
            {
                if (c.ClientInfo.Equals(data.CLIENT_ID)) canConnect = false;
            }
            if (canConnect)
            {
                Clients _client = new Clients() { ClientInfo = data.CLIENT_ID };
                ConnectList.Add(_client);
                ClientRoomPair.Add(data.CLIENT_ID, 0);
            }
            SendJoinableList(data.CLIENT_ID);
        }

        void SendJoinableList(string clientId) //연결응답 보내기
        {
            UIThreadHelper.CheckAndInvokeOnUIDispatcher(() => {
                dds.Write(typeof(BAC_SERVER_CONNECT_MESSAGE), nameof(BAC_SERVER_CONNECT_MESSAGE) + clientId,
                    new BAC_SERVER_CONNECT_MESSAGE
                    {
                        type = SERVER_CONNECT_MESSAGE_TYPE.SERVER_CONNECT_SUCCESS,
                        msg = "connect success"
                    }
                );
                dds.RegisterEvent(typeof(BAC_CLIENT_CONNECT_MESSAGE), nameof(BAC_CLIENT_CONNECT_MESSAGE) + clientId, data => ReceiveClientMsg(data as BAC_CLIENT_CONNECT_MESSAGE, clientId));
            });

        }

        private void EnterRoom(BAC_CLIENT_CONNECT_MESSAGE data, string clientId)
        {
            if (Int32.TryParse(data.msg, out int rId))
            {
                bool exist = false;
                RoomInfoData playRoom = new RoomInfoData();
                foreach (RoomInfoData room in JoinableList)
                {
                    if (room.RoomData.RoomID == rId)
                    {
                        playRoom = room;
                        exist = true;
                        break;
                    }
                }
                if (exist && !playRoom.Clients.Contains(clientId))
                {
                    playRoom.RoomData = new BAC_ROOM_DATA() { RoomID = playRoom.RoomData.RoomID, Max_Num_Participants = playRoom.RoomData.Max_Num_Participants, Cur_Num_Participants = playRoom.RoomData.Cur_Num_Participants + 1 };
                    playRoom.Clients.Add(clientId);
                    ClientRoomPair[clientId] = (int)playRoom.RoomData.RoomID;
                    dds.Write(typeof(BAC_SERVER_CONNECT_MESSAGE), nameof(BAC_SERVER_CONNECT_MESSAGE) + clientId,
                            new BAC_SERVER_CONNECT_MESSAGE
                            {
                                type = SERVER_CONNECT_MESSAGE_TYPE.ENTER_ROOM_SUCCESS,
                                msg = "enter room success"
                            }
                        );
                    if (playRoom.RoomData.Cur_Num_Participants >= playRoom.RoomData.Max_Num_Participants) GameStart(playRoom);
                    return;//들어갔다고 답변 전송
                }

            }

            dds.Write(typeof(BAC_SERVER_CONNECT_MESSAGE), nameof(BAC_SERVER_CONNECT_MESSAGE) + clientId,
                    new BAC_SERVER_CONNECT_MESSAGE
                    {
                        type = SERVER_CONNECT_MESSAGE_TYPE.ENTER_ROOM_SUCCESS,
                        msg = ""
                    }
                );
            return;//못들어갔다고 답변전송
        }

        private void GameStart(RoomInfoData playRoom)
        {
            PlayingList.Add(playRoom);
            foreach(string CleintId in playRoom.Clients)
            {
                for (int i = 0; i < 10; i++)
                {
                    dds.Write(typeof(BAC_SERVER_CONNECT_MESSAGE), nameof(BAC_SERVER_CONNECT_MESSAGE) + CleintId,
                    new BAC_SERVER_CONNECT_MESSAGE
                    {
                        type = SERVER_CONNECT_MESSAGE_TYPE.REQUEST_GAME_START,
                        msg = "game start"
                    }
                    );
                }
            }
            model.GameStart((int)playRoom.RoomData.RoomID, playRoom.Clients);
            JoinableList.Remove(playRoom);
        }
        public void ResendRoomData(BAC_CLIENT_CONNECT_MESSAGE data, string _clientId)
        {
            if (!Int32.TryParse(data.msg, out int Rnum)) return;

            if(Rnum == 0)
            {
                bool exist = false;
                BAC_ROOM_DATA RoomData = new BAC_ROOM_DATA();
                foreach(RoomInfoData room in JoinableList)
                {
                    if(room.Clients.Contains(_clientId)) { exist= true; RoomData = room.RoomData; break; }
                }
                if (!exist)
                {
                    foreach (RoomInfoData room in PlayingList)
                    {
                        if (room.Clients.Contains(_clientId)) { exist = true; RoomData = room.RoomData; break; }
                    }
                }
                if (exist)
                {
                    string ans = Newtonsoft.Json.JsonConvert.SerializeObject(RoomData);
                    dds.Write(typeof(BAC_SERVER_CONNECT_MESSAGE), nameof(BAC_SERVER_CONNECT_MESSAGE) + _clientId,
                            new BAC_SERVER_CONNECT_MESSAGE
                            {
                                type = SERVER_CONNECT_MESSAGE_TYPE.SEND_ROOM_DATA,
                                msg = ans
                            }
                        );
                }
                return;
            }
            else
            {
                bool exist = false;
                BAC_ROOM_DATA RoomData = new BAC_ROOM_DATA();
                foreach (RoomInfoData room in JoinableList)
                {
                    if (room.RoomData.RoomID == (uint)Rnum) { exist = true; RoomData = room.RoomData; break; }
                }
                if (!exist)
                {
                    foreach (RoomInfoData room in PlayingList)
                    {
                        if (room.RoomData.RoomID == (uint)Rnum) { exist = true; RoomData = room.RoomData; break; }
                    }
                }
                if (exist)
                {
                    string ans = Newtonsoft.Json.JsonConvert.SerializeObject(RoomData);
                    dds.Write(typeof(BAC_SERVER_CONNECT_MESSAGE), nameof(BAC_SERVER_CONNECT_MESSAGE) + _clientId,
                            new BAC_SERVER_CONNECT_MESSAGE
                            {
                                type = SERVER_CONNECT_MESSAGE_TYPE.SEND_ROOM_DATA,
                                msg = ans
                            }
                        );
                }
                return;
            }
        }

        public void SendGameoutput(BAC_CLIENT_CONNECT_MESSAGE data, string _clientId)
        {
            BAC_GAME_INPUT_DATA input = JsonConvert.DeserializeObject<BAC_GAME_INPUT_DATA>(data.msg);
            string str = ""+input.A+input.B+input.C;
            BAC_GAME_OUTPUT_DATA output = model.CountResult(ClientRoomPair[_clientId], _clientId, str);
            string ans = JsonConvert.SerializeObject(output);

            dds.Write(typeof(BAC_SERVER_CONNECT_MESSAGE), nameof(BAC_SERVER_CONNECT_MESSAGE) + _clientId,
                           new BAC_SERVER_CONNECT_MESSAGE
                           {
                               type = SERVER_CONNECT_MESSAGE_TYPE.SEND_GAME_OUTPUT_DATA,
                               msg = ans
                           }
                   );

            /////////////게임 종료 메세지
            if (output.nStrike == 3)
            {
                bool exist = false;
                List<string> cs = new List<string>();
                foreach (RoomInfoData room in PlayingList)
                {
                    if (room.RoomData.RoomID == (uint)ClientRoomPair[_clientId]) { exist = true; cs = room.Clients; break; }
                }
                if (exist)
                {
                    BAC_GAME_RESULT_DATA endData = new BAC_GAME_RESULT_DATA() { TryCount = "" , WinnerClientID = _clientId };
                    string ans2 = JsonConvert.SerializeObject(endData);
                    foreach (string cid in cs)
                    {
                        dds.Write(typeof(BAC_SERVER_CONNECT_MESSAGE), nameof(BAC_SERVER_CONNECT_MESSAGE) + cid,
                                new BAC_SERVER_CONNECT_MESSAGE
                                {
                                    type = SERVER_CONNECT_MESSAGE_TYPE.REQUEST_GAME_END,
                                    msg = ans2
                                }
                            );
                    }
                }
            }

           
        }

        private DelegateCommand msgsend;
        public DelegateCommand MsgSend =>
            msgsend ?? (msgsend = new DelegateCommand(ExecuteMsgSend));
        void ExecuteMsgSend()
        {
            dds.Write(typeof(BAC_CONNECT_INIT_MESSAGE), nameof(BAC_CONNECT_INIT_MESSAGE),
                new BAC_CONNECT_INIT_MESSAGE()
                {
                    CLIENT_ID = "1-0"
                });
        }

        private DelegateCommand roomsend;
        public DelegateCommand RoomSend =>
            roomsend ?? (roomsend = new DelegateCommand(ExecuteRoomSend));

        void ExecuteRoomSend()
        {
            dds.Write(typeof(BAC_CLIENT_CONNECT_MESSAGE), nameof(BAC_CLIENT_CONNECT_MESSAGE) + "1-0",
                new BAC_CLIENT_CONNECT_MESSAGE()
                {
                    type = CLIENT_CONNECT_MESSAGE_TYPE.CREATE_ROOM,
                    msg = "5"
                });
        }

        private DelegateCommand showroom;

        public DelegateCommand ListSend =>
            showroom ?? (showroom = new DelegateCommand(ExecuteListSend));

        void ExecuteListSend()
        {
            dds.Write(typeof(BAC_CLIENT_CONNECT_MESSAGE), nameof(BAC_CLIENT_CONNECT_MESSAGE) + "1-0",
                new BAC_CLIENT_CONNECT_MESSAGE()
                {
                    type = CLIENT_CONNECT_MESSAGE_TYPE.REQUEST_ROOM_LIST,
                    msg = "1"
                });
        }










        /// <summary>
        /// ///////////////////////////////////////
        /// </summary>
        protected CompositeDisposable disposables { get; } = new CompositeDisposable();

        private bool disposedValue;

        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        protected virtual void Dispose(bool disposing)
        {
            if (!disposedValue)
            {
                if (disposing)
                {
                    this.disposables.Dispose();
                }
                disposedValue = true;
            }
        }


    }
}

