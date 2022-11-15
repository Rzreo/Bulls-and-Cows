using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace BullsAndCows.Infrastructure.Style.Controls
{
    public class CircleText : UserControl
    {
        static CircleText()
        {
            DefaultStyleKeyProperty.OverrideMetadata
            (
                typeof(CircleText),
                new FrameworkPropertyMetadata(typeof(UserControl))
            );
        }

        #region MouseCaptureWhenClicked
        /// <summary>
        /// True 면 클릭-드래그 시 원래 ListBox 동작인 마우스캡쳐를 함.
        /// </summary>
        public static readonly DependencyProperty TextProperty
            = DependencyProperty.Register(nameof(Text), typeof(string),
                typeof(CircleText), new UIPropertyMetadata(""));
        public string Text
        {
            get
            {
                return (string)GetValue(TextProperty);
            }
            set
            {
                SetValue(TextProperty, value);
            }
        }
        #endregion
    }
}
