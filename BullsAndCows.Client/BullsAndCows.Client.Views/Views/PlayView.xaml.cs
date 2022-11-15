using System;
using System.Collections.Generic;
using System.Windows.Controls;
using Prism.Common;
using Prism.Regions;

namespace BullsAndCows.Client.Views.Views
{
    /// <summary>
    /// Interaction logic for PlayView.xaml
    /// </summary>
    public partial class PlayView : UserControl
    {
        public PlayView()
        {
            InitializeComponent();
            RegionContext.GetObservableContext(this).PropertyChanged += PlayView_PropertyChanged;
        }

        private void PlayView_PropertyChanged(object sender, System.ComponentModel.PropertyChangedEventArgs e)
        {
            //var context = (ObservableObject<object>)sender;
            //(DataContext as PlayVM).GameOutput = context.Value as GameOutput;
        }
    }
}
