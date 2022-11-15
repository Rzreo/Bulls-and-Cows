using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Publisher.ViewModels
{
    using Prism.Ioc;
    class MainWindowViewModel
    {
        IContainerProvider _provider;
        public MainWindowViewModel(IContainerProvider provider)
        {
        }
    }
}
