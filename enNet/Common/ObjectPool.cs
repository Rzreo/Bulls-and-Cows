namespace enNet
{
    public class ObjectPool<T> where T : new()
    {
        private object sync = new object();

        private int count;
        private T[] pool;

        private int offset;

        public ObjectPool(int count)
        {
            this.count = count;
            this.pool = new T[count];
            for (int i = 0; i < count; i++)
            {
                this.pool[i] = new T();
            }

            this.offset = 0;
        }

        public void Reset()
        {
            lock (this.sync)
            {
                this.offset = 0;
            }
        }

        public T Get()
        {
            lock (this.sync)
            {
                var ret = this.pool[this.offset++];
                if (this.offset >= this.count) this.offset = 0;
                return ret;
            }
        }
    }
}