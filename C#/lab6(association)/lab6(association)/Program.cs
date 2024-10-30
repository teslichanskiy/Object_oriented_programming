using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lab_6;

class Program
{
    static void Main(string[] args)
    {
        D1 d1 = new D1();
        E1 e1 = new E1();
        d1.e = e1;
        e1.d = d1;


        Console.WriteLine(" d1.e.f() = {0}", d1.e.f());
        Console.WriteLine(" e1.d.f() = {0}", e1.d.f());

        E e = new E();
        E eS = new E(8);

        D d_1 = new D();
        e.setD(d_1);
        d_1.e = e;
        Console.WriteLine(" d_1.e.getNext().f() = {0}", d_1.e.getNext(0).f());

        Console.WriteLine(" e.getNext().f() = {0}", e.getNext(0).f());
        D d_2 = new D(e);
        e.setD(d_2);
        d_2.e = e;

        Console.ReadKey();
    }
}
