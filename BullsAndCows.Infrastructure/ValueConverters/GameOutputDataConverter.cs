using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Data;
using System.Windows.Markup;

namespace BullsAndCows.Infrastructure
{
    [MarkupExtensionReturnType(typeof(IValueConverter))]
    public class GameOutputDataConverter : MarkupExtension, IValueConverter
    {
        static GameOutputDataConverter converter;
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value.GetType() != typeof(BAC_GAME_OUTPUT_DATA))
                throw new Exception("Value DFF");

            BAC_GAME_OUTPUT_DATA data = (BAC_GAME_OUTPUT_DATA)value;
            return $"{1} Try => Strike : {data.nStrike}, Ball : {data.nBall}, Out : {data.nOut}";
        }
        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
        public override object ProvideValue(IServiceProvider serviceProvider)
        {
            if (converter == null)
            {
                converter = new GameOutputDataConverter();
            }

            return converter;
        }
    }
}
