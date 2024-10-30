using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lab_2;

class Program
{
    static void Main(string[] args)
    {
        A a = new A();
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