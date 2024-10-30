using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lab_8;


public class Program
{
    public static void Main(string[] args)
    {
        Lab_8.Queue<int> queue = new Lab_8.Queue<int>();

        queue.Push(1);
        queue.Push(2);
        queue.Push(3);
        queue.Push(0);
        queue.Push(5);
        queue.Push(8);
        queue.PrintQueue();

        Console.WriteLine("Peek: " + queue.Peek());

        int poppedElement = queue.Pop();
        Console.WriteLine("Popped: " + poppedElement);

        queue.PrintQueue();
    }
}
