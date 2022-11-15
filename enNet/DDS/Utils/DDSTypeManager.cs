using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;

namespace enNet
{
    /// <summary>
    /// RTI DDS Type 를 관리
    /// </summary>
    public class DDSTypeManager
    {
        public bool Load(string path)
        {
            var asm = Assembly.LoadFrom(path);
            if (asm == default) return false;

            var types = asm.GetTypes()
                .Where(DDSTypeExtensions.IsDDSType)
                .ToDictionary(t => t.Name);

            this.Types = this.Types.Union(types).ToDictionary(v => v.Key, v => v.Value);

            return true;
        }

        public Dictionary<string, Type> Types { get; private set; } = new Dictionary<string, Type>();

        public Type GetType(string typeName)
        {
            return this.Types.ContainsKey(typeName) ? this.Types[typeName] : default;
        }
    }
}