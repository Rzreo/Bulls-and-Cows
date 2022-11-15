using System;
using System.Collections.Generic;
using System.Linq;
using System.Reactive.Linq;
using System.Reactive.Threading.Tasks;
using System.Threading.Tasks;

namespace enNet
{
    public class RequestReply<W, R>
    {
        //private readonly DataWriter<W> writer;
        private readonly DataReaderRx<R> readerRx;

        public RequestReply(/*DataWriter<W> writer,*/ DataReaderRx<R> readerRx)
        {
            //this.writer = writer ?? throw new ArgumentNullException(nameof(writer));
            this.readerRx = readerRx ?? throw new ArgumentNullException(nameof(readerRx));
        }

        public void Request(W request, Action<bool, R> reply, TimeSpan? timeout = default, Func<W, R, bool> matcher = default)
        {
            if (EqualityComparer<W>.Default.Equals(request, default) || reply == default) return;

            var replies = this.readerRx.Samples;
            if (matcher != default) replies = replies.Where(v =>
            {
                try
                {
                    return matcher(request, v);
                }
                catch
                {
                    return false;
                }
            });

            Task.Run(async () =>
            {
                try
                {
                    if (timeout == default)
                    {
                        reply(true, await replies.Take(1).ToTask());
                    }
                    else
                    {
                        reply(true, await replies.Take(1).Timeout((TimeSpan)timeout).ToTask());
                    }
                }
                catch
                {
                    reply(false, default);
                }
            });
        }
    }
}