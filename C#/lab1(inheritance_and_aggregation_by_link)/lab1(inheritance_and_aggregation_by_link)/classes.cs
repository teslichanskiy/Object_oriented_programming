using System;

namespace Lab_1
{
    class A
    {
        public A(B b, C c, J j)
        {
            this.b = b;
            this.c = c;
            this.j = j;
        }

        ~A() { }

        public void mA() { Console.WriteLine("method of A"); }
        public B bA
        {
            set { Console.WriteLine("set b"); b = value; }
            get { Console.Write("get b ->"); return b; }
        }
        public C cA
        {
            set { Console.WriteLine("set c"); c = value; }
            get { Console.Write("get c ->"); return c; }
        }
        public J jA
        {
            set { Console.WriteLine("set j"); j = value; }
            get { Console.Write("get j ->"); return j; }
        }

        private B b = null;
        private C c = null;
        private J j = null;
    }

    class B
    {
        public B(D d) { this.d = d; }
        ~B() { }
        public void mB() { Console.WriteLine("method of B"); }

        public D dA
        {
            set { Console.WriteLine("set d"); d = value; }
            get { Console.Write("get d ->"); return d; }
        }

        private D d = null;
    }

    class C
    {
        public C(K k, F f, E e)
        {
            this.k = k;
            this.f = f;
            this.e = e;
        }

        ~C() { }

        public void mC() { Console.WriteLine("method of C"); }
        public K kA
        {
            set { Console.WriteLine("set k"); k = value; }
            get { Console.Write("get k -> "); return k; }
        }
        public F fA
        {
            set { Console.WriteLine("set f"); f = value; }
            get { Console.Write("get f -> "); return f; }
        }
        public E eA
        {
            set { Console.WriteLine("set e"); e = value; }
            get { Console.Write("get e ->"); return e; }
        }

        private K k = null;
        private F f = null;
        private E e = null;

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
