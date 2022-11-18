using System;
using System.Globalization;
using System.Windows;
using System.Windows.Data;
using System.Windows.Markup;

namespace BullsAndCows.Infrastructure
{
    [MarkupExtensionReturnType(typeof(IValueConverter))]
    public class RoomDataShowConverter : MarkupExtension, IValueConverter
    {
        static RoomDataShowConverter converter;
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value.GetType() != typeof(BAC_ROOM_DATA))
                throw new Exception("Value DFF");

            BAC_ROOM_DATA data = (BAC_ROOM_DATA)value;
            return $"ID : {data.RoomID}, {data.Cur_Num_Participants} / {data.Max_Num_Participants}";
        }
        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Provides the value using the specified service provider.
        /// </summary>
        /// <param name="serviceProvider">The service provider.</param>
        /// <returns>The converter.</returns>
        public override object ProvideValue(IServiceProvider serviceProvider)
        {
            if (converter == null)
            {
                converter = new RoomDataShowConverter();
            }
        
            return converter;
        }
    }
}
