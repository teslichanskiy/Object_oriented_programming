using System;


namespace Lab_5
{

    public interface A //Интерфейс A содержит два метода: mA() и fA().
    {
        void mA();
        int fA();
    }

    public class B : A //Класс B реализует интерфейс A и имеет также свой собственный метод fB(). В конструкторах класса B инициализируется переменная b.
    {
        private int b;

        public B()
        {
            Console.WriteLine(" constructor B ()");
            b = 88;
        }

        public B(int b)
        {
            Console.WriteLine(" constructor B(int b) ");
            this.b = b;
        }

        public int fB() { return b; }

        public void mA() { }

        public int fA() { return 99; }
    }

    public interface C : A //Интерфейс C наследуется от интерфейса A и содержит два своих метода: fC() и mC().
    {
        int fC();
        void mC();
    }

    public class D : B, C //Класс D наследуется от класса B и реализует интерфейс C. В конструкторах класса D инициализируются переменные a и b.
    {
        public D() { a = fB(); }

        public D(int b, int a) : base(b)
        {
            Console.WriteLine(" constructor D");
            this.a = a;
        }

        public int fC() { return 66; }

        public void mC() { a = fA() + fC(); }

        private int a = 0;
    }
}
