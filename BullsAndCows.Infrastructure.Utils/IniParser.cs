namespace BullsAndCows.Infrastructure.Utils
{
    using System.Collections.Generic;
    using System.IO;
    using System.Linq;

    public static class IniParser
    {
        /// <summary>
        /// Parses the path.
        /// </summary>
        /// <param name="path">The path.</param>
        /// <returns>The sections.</returns>
        public static Dictionary<string, Dictionary<string, string>> Parse(string path)
        {
            if (File.Exists(path) == false)
            {
                return null;
            }

            var lines = File.ReadAllLines(path).Where(s => s.Count() > 0);

            var sections = new Dictionary<string, Dictionary<string, string>>();
            Dictionary<string, string> section = null;
            foreach (var line in lines)
            {
                if (line.First() == '[' && line.Last() == ']')
                {
                    section = new Dictionary<string, string>();
                    sections[line.Substring(1, line.Length - 2)] = section;
                }
                else
                {
                    var tokens = line.Split('=');
                    if (tokens.Count() >= 2)
                    {
                        section[tokens[0].Trim()] = tokens[1].Trim();
                    }
                }
            }

            return sections;
        }
    }
}
