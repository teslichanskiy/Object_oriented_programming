using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lab_7;
//Подключаемые пространства имен System для базовых системных классов и функций, для работы с обобщенными коллекциями и т.п.

class Program
{
    static void Main(string[] args)
    {
        B b = new B();  // Создаем экземпляр класса B
        A a = new A();  // Создаем экземпляр класса A
        a.m(b);  // Вызываем метод 'm' класса A, передав экземпляр класса B в качестве аргумента

        a.utility();  // Вызываем метод utility класса A
        C.f();  // Вызываем статическую функцию f класса C

        Console.ReadKey();
    }
}

