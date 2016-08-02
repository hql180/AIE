using System;
using System.Collections.Generic;


namespace Introduction_CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World");
            Console.ReadKey(true);

            string name;

            name = Console.ReadLine();

            //Console.Write("Hello " + name + " World");
            string.Format("Hello {0} World", name);

            Console.Write(string.Format("{1}Hello {0} World", name, "test"));    


        }
    }
}
