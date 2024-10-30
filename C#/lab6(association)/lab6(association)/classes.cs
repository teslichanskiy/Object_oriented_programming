using System;


namespace Lab_6
{
    class D1
    {
        public D1() { }
        ~D1() { }
        public E1 e { set; get; }
        public int f() { return 2; }
    }

    class E1
    {
        public E1() { }
        ~E1() { }
        public D1 d { set; get; }
        public int f() { return 5; }
    }

    class E
    {
        public E() { N = 5; this.d = new D[N]; }
        public E(int N)
        {
            this.N = N;
            this.d = new D[N];
        }
        ~E() { }

        public void setD(D d) { if (size < N) { this.d[size] = d; size++; } }

        public D getNext(int index)
        {
            if (index < size)
            {
                return d[index];
            }
            return null;
        }

        private int N = 0;
        private D[] d = null;
        private int size = 0;
    }

    class D
    {
        public D() { }
        public D(E e) { e.setD(this); }
        ~D() { }
        public int f() { return v; }
        private int v = 11;
        public E e { set; get; }
    }
}
