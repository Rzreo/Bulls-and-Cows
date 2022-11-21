namespace SystemModule.ViewModels
{
    using Prism.Commands;
    using Prism.Mvvm;
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using GameModel;
    using System.Reactive.Disposables;

    public class GameViewModel : BindableBase//, IDisposable
    {
        /*
        private Dictionary<string, PrivateDetail> fieldName;
        public Dictionary<string, PrivateDetail> MyDictionary
        {
            get { return fieldName; }
            set { SetProperty(ref fieldName, value); }
        }
        public class info
        {
            public int TryCnt { get; set; }
            public string InputNum { get; set; }
            public int Strike { get; set; }
            public int Ball { get; set; }
            public int Out { get; set; }
        }

        GameModel model;
        public GameViewModel(GameModel _model, int roomId)
        {
            model = _model;
            MyDictionary = model.RoomInfo[roomId].Clients;

            SelectedClient.Subscribe(item =>
            {
                if (item is null) return;
                LogDocumentLeft.Value.Text = string.Empty;

                if (item != null)
                {
                    OpenContainer(item, true);
                }
            });
        }


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
                */
    }

}
