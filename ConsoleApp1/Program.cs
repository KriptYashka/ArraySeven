using System;

namespace ConsoleApp1
{
    class Coord<T> where T : class
    {
        public T Position { set; get; }
        public void Write<T>(T data)
        {
            Console.Write(data.ToString() + Position.ToString());
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Coord<string> x = new Coord<string>()
            {
                Position = "3.0"
            };
            x.Write("x: ");
            Coord<double> y = new Coord<double>()
            {
                Position = 4.0
            };
            y.Write("y: ");
        }
    }
}
