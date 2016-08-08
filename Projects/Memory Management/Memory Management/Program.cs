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
        public MyTestClass()
        {
            Console.WriteLine("Constructing");
        }

        public void Dispose()
        {
            Console.WriteLine("Disposing");
        }

        ~MyTestClass()
        {
            Console.WriteLine("Finalizing");
        }
    }
   
}
