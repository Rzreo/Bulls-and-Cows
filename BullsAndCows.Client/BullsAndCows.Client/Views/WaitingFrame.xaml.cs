using BullsAndCows.Infrastructure.Utils.Regions;
using Prism.Ioc;
using Prism.Regions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace BullsAndCows.Client.Views
{
    /// <summary>
    /// Interaction logic for WaitingFrame.xaml
    /// </summary>
    public partial class WaitingFrame : UserControl
    {
        public WaitingFrame(IContainerProvider ioc)
        {
            InitializeComponent(); 
            
            Loaded += (s, e) =>
            {
                var regionManager = ioc.Resolve<IRegionManager>();
                regionManager.RequestNavigate(ClientRegions.Waiting_ParticipantsListRegion, nameof(Views.WaitingMain));
            };
        }
    }
}
