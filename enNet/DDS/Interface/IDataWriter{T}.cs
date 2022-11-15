namespace enNet
{
    public interface IDataWriter<T>
    {
        void Write(T sample);
    }
}