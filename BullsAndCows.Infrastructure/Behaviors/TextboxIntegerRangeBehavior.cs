namespace BullsAndCows.Infrastructure
{
    using Microsoft.Xaml.Behaviors;
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;
    using System.Windows.Input;
    using System.Windows;
    using System.Windows.Controls;

    // https://stackoverflow.com/questions/49896296/wpf-textbox-input-filtering-doesnt-work-as-expected-with-a-decimal
    public class IntegerRangeBehavior : Behavior<TextBox>
    {
        public string EmptyValue { get; set; } = "0";

        public static readonly DependencyProperty MaximumProperty =
            DependencyProperty.Register(nameof(Maximum), typeof(int), typeof(IntegerRangeBehavior), new PropertyMetadata(1));
        public int Maximum
        {
            get { return (int)GetValue(MaximumProperty); }
            set { SetValue(MaximumProperty, value); }
        }

        public static readonly DependencyProperty MinimumProperty =
           DependencyProperty.Register(nameof(Minimum), typeof(int), typeof(IntegerRangeBehavior), new PropertyMetadata(4));
        public int Minimum
        {
            get { return (int)GetValue(MinimumProperty); }
            set { SetValue(MinimumProperty, value); }
        }

        protected override void OnAttached()
        {
            base.OnAttached();

            AssociatedObject.PreviewTextInput += PreviewTextInputHandler;
            DataObject.AddPastingHandler(AssociatedObject, PastingHandler);
        }
        protected override void OnDetaching()
        {
            base.OnDetaching();

            AssociatedObject.PreviewTextInput -= PreviewTextInputHandler;
            DataObject.RemovePastingHandler(AssociatedObject, PastingHandler);
        }
        private void PastingHandler(object sender, DataObjectPastingEventArgs e)
        {
            if (e.DataObject.GetDataPresent(DataFormats.Text))
            {
                string text = Convert.ToString(e.DataObject.GetData(DataFormats.Text));

                if (!ValidateText(text))
                    e.CancelCommand();
            }
            else
                e.CancelCommand();
        }
        void PreviewTextInputHandler(object sender, TextCompositionEventArgs e)
        {
            string text;
            if (AssociatedObject.Text.Length < AssociatedObject.CaretIndex)
                text = AssociatedObject.Text;
            else
            {
                //  Remaining text after removing selected text.
                string remainingTextAfterRemoveSelection;

                text = TreatSelectedText(out remainingTextAfterRemoveSelection)
                    ? remainingTextAfterRemoveSelection.Insert(AssociatedObject.SelectionStart, e.Text)
                    : AssociatedObject.Text.Insert(this.AssociatedObject.CaretIndex, e.Text);
            }

            e.Handled = !ValidateText(text);
        }
        private bool TreatSelectedText(out string text)
        {
            text = null;
            if (AssociatedObject.SelectionLength <= 0)
                return false;

            var length = this.AssociatedObject.Text.Length;
            if (AssociatedObject.SelectionStart >= length)
                return true;

            if (AssociatedObject.SelectionStart + AssociatedObject.SelectionLength >= length)
                AssociatedObject.SelectionLength = length - AssociatedObject.SelectionStart;

            text = this.AssociatedObject.Text.Remove(AssociatedObject.SelectionStart, AssociatedObject.SelectionLength);
            return true;
        }
        private bool ValidateText(string text)
        {
            double number;
            if (!Double.TryParse(text, out number))
            {
                return false;
            }
            if (number < Minimum)
            {
                AssociatedObject.Text = Minimum.ToString();
                return false;
            }
            if (number > Maximum)
            {
                AssociatedObject.Text = Maximum.ToString();
                return false;
            }
            return true;
        }
    }
}
