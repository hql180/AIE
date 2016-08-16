using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Memory_Management
{
    class Program
    {
        static void Main(string[] args)
        {
            BadFileIOExample();

            MyTestClass myTestClass = new MyTestClass();

            Console.ReadLine();

            myTestClass.Dispose();

            Console.ReadLine();
        }

        static void BadFileIOExample()
        {
            StreamWriter stream = new StreamWriter("test.txt");

            stream.WriteLine("Hello");
        }
    }

    class MyTestClass : IDisposable
    {
        private bool isDisposed = false;

        public MyTestClass()
        {
            Console.WriteLine("Constructing");
        }

        public void DoSomething()
        {
            if (isDisposed)
                throw new ObjectDisposedException("MyTestClass");

            // execute code down here if not disposed
        }

        public void Dispose()
        {
            if (!isDisposed)
            {
                isDisposed = true;
                Console.WriteLine("Disposing");
                GC.SuppressFinalize(this);
            }
            else
                throw new ObjectDisposedException("MyTestClass", "Already disposed");
        }

        ~MyTestClass()
        {
            Console.WriteLine("Finalizing");
            this.Dispose();
        }
    }
   
}
