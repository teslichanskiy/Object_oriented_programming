using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lab_5;

class Program
{

    static void Main(string[] args) //В методе Main создаются объекты классов B и D, которые присваиваются переменным a и c соответственно. Затем выводятся значения различных методов.
    {
        A a = null;
        a = new B();
        Console.WriteLine(" B  a.fIA() = {0}", a.fA());

        C c = null;
        c = new D();
        Console.WriteLine(" C  c.fA() = {0}", c.fA() + c.fC());

        a = new D();

        Console.WriteLine(" +++++++++++++");

        a = new D(44, 55);

        Console.ReadKey();
    }
}
