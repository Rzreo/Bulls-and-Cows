namespace Server
{
    using MainModule;
    using Prism.DryIoc;
    using Prism.Ioc;
    using Prism.Modularity;
    using Prism.Regions;
    using Server.Views;
    using System.IO;
    using System.Windows;

    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : PrismApplication
    {

        public App()
        {

        }
        protected override Window CreateShell()
        {
            return Container.Resolve<MainWindow>();
        }

        protected override void InitializeShell(Window shell)
        {
            base.InitializeShell(shell);
        }

        /// <summary>
        /// Modules 또는 다른 폴더에 있는 Dll로드 or 기본 Module Catalog 생성
        /// </summary>
        /// <returns>Custom Module Catalog 또는 Base Module Catalog</returns>
        protected override IModuleCatalog CreateModuleCatalog()
        {
            string Path = @".\Modules\";
            if (Directory.Exists(Path))
            {
                var catalog = new DirectoryModuleCatalog()
                {
                    ModulePath = Path,
                };
                return catalog;
            }
            else
            {
                return base.CreateModuleCatalog();
            }
        }

        /// <summary>
        /// 생성된 카탈로그를 수정하는부분 모듈의 로드순서를 제어 가능 함.
        /// </summary>
        /// <param name="moduleCatalog"></param>
        protected override void ConfigureModuleCatalog(IModuleCatalog moduleCatalog)
        {
            //DDS , Serial 통신
            //moduleCatalog.AddModule<MyModel>();

            moduleCatalog.AddModule<MainModule.MainModuleModule>();
            moduleCatalog.AddModule<BullsAndCows.Server.Net.NetModule>();
            //moduleCatalog.AddModule<showModule>();
        }

        protected override void RegisterTypes(IContainerRegistry containerRegistry)
        {

        }

        protected override void OnInitialized()
        {
            base.OnInitialized();

            Container.Resolve<IRegionManager>().RequestNavigate("ContentRegion", "MainView");

        }
    }
}
