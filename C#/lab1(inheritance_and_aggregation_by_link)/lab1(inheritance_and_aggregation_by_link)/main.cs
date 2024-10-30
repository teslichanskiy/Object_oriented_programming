using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lab_1;

class main
{
    static void Main(string[] args)
    {
        K k = new K();
        F f = new F();
        E e = new E();
        D d = new D();
        J j = new J();
        B b = new B(d);
        C c = new C(k, f, e);
        A a = new A(b, c, j);
        a.mA();
        a.bA.mB();
        a.cA.mC();
        a.jA.mJ();
        a.cA.kA.mK();
        a.cA.fA.mF();
        a.cA.eA.mE();
        a.bA.dA.mD();
        Console.ReadKey();
    }
}