namespace Test.Infrastructure.Utils
{
    using System;
    using System.Windows;
    using System.Windows.Threading;
    public static class UIThreadHelper
    {
        public static void CheckAndInvokeOnUIDispatcher(Action act)
        {
            if (act is null)
            {
                return;
            }

            if (Application.Current.Dispatcher.CheckAccess())
            {
                act();
            }
            else
            {
                Application.Current.Dispatcher.BeginInvoke(act);
            }
        }
        public static void CheckAndInvokeOnUIDispatcherLogView(Action act)
        {
            if (act is null)
            {
                return;
            }

            if (Application.Current.Dispatcher.CheckAccess())
            {
                act();
            }
            else
            {
                Application.Current.Dispatcher.BeginInvoke(DispatcherPriority.ApplicationIdle, act);
            }
        }
    }
}
