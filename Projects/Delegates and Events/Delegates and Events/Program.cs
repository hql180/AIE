using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Delegates_and_Events
{
    class Program
    {
        static void Main(string[] args)
        {
            //ListWithChangedEvent list = new ListWithChangedEvent();

            //EventListener listener = new EventListener(list);

            //list.Add("hello");
            //list.Add("world");
            //list.Clear();
            //listener.Detach();

            //Console.ReadKey();

            KeyboardHandler handler = new KeyboardHandler();

            handler.Subscribe((ConsoleKeyInfo info) => { Console.WriteLine(info); } );

            while(true)
            {
                handler.Update();
                
            }
        }

        public delegate void ChangedEventHandler(object sender, EventArgs e);

        class ListWithChangedEvent : ArrayList
        {
            public ChangedEventHandler Changed;

            protected virtual void OnChanged(EventArgs e)
            {
                if (Changed != null)
                    Changed(this, e);
            }

            public override int Add(object value)
            {
                int i = base.Add(value);
                OnChanged(EventArgs.Empty);
                return i;
            }

            public override void Clear()
            {
                base.Clear();
                OnChanged(EventArgs.Empty);
            }

            public override object this [int index]
            {
                set
                {
                    base[index] = value;
                    OnChanged(EventArgs.Empty);
                }
            }
        }

        class EventListener
        {
            private ListWithChangedEvent List;

            public EventListener(ListWithChangedEvent list)
            {
                List = list;
                List.Changed += new ChangedEventHandler(OnListChanged);
            }

            private void OnListChanged(object sender, EventArgs e)
            {
                Console.WriteLine("list changed event receieved");
            }

            public void Detach()
            {
                List.Changed -= new ChangedEventHandler(OnListChanged);
                List = null;
            }
        }

       

        class KeyboardHandler
        {
            public delegate void Keycheck(ConsoleKeyInfo key);

            private Keycheck KeyPressedEvent = (ConsoleKeyInfo key) => {};

            public void Subscribe(Keycheck keycheck)
            {
                KeyPressedEvent += keycheck;
            }

            public void Update()
            {
                if(Console.KeyAvailable)
                {
                    //ConsoleKeyInfo keyInfo = Console.ReadKey();
                    
                    KeyPressedEvent(Console.ReadKey());
                }
            }
        }
    }
}
