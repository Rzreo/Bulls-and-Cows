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
    using BullsAndCows.Infrastructure.BaseClass;
    using BullsAndCows.Infrastructure.Utils.Regions;
    using Prism.Ioc;
    using Prism.Regions;

    public partial class PlayFrame : UserControl
    {
        public PlayFrame(IContainerProvider ioc)
        {
            InitializeComponent();

            Loaded += (s, e) =>
            {
                var regionManager = ioc.Resolve<IRegionManager>();
                regionManager.RequestNavigate(ClientRegions.Play_PlayRegion, nameof(Views.PlayView));
                regionManager.RequestNavigate(ClientRegions.Play_InputRegion, nameof(Views.NumberInputsView));
            };
        }
    }
}
