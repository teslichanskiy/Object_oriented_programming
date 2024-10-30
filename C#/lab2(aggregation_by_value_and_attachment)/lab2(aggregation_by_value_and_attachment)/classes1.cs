using System;

namespace Lab_2
{
    class A
    {
        public A() { b = new B(); c = new C(); j = new J(); }
        ~A() { }

        public void mA() { Console.WriteLine("method of A"); }

        public B bA { get { Console.Write("get b ->"); return b; } }
        public C cA { get { Console.Write("get c ->"); return c; } }
        public J jA { get { Console.Write("get j ->"); return j; } }

        private B b;
        private C c;
        private J j;
    }

    class B
    {
        public B() { d = new D(); }
        ~B() { }
        public void mB() { Console.WriteLine("method of B"); }
        public D dA { get { Console.Write("get d ->"); return d; } }

        private D d;
    }

    class C
    {
        public C() { k = new K(); f = new F(); e = new E(); }

        ~C() { }

        public void mC() { Console.WriteLine("method of C"); }
        public K kA { get { Console.Write("get k -> "); return k; } }
        public F fA { get { Console.Write("get f -> "); return f; } }
        public E eA { get { Console.Write("get e ->"); return e; } }

        private K k;
        private F f;
        private E e;

    }

    class D
    {
        public D() { }
        ~D() { }
        public void mD() { Console.WriteLine(" method of D"); }
    }

    class E
    {
        public E() { }
        ~E() { }
        public void mE() { Console.WriteLine(" method of E"); }
    }

    class F
    {
        public F() { }
        ~F() { }
        public void mF() { Console.WriteLine(" method of F"); }
    }

    class J
    {
        public J() { }
        ~J() { }
        public void mJ() { Console.WriteLine(" method of J"); }
    }

    class K
    {
        public K() { }
        ~K() { }
        public void mK() { Console.WriteLine(" method of K"); }
    }
}
