using System;

namespace Lab_0
{

    class Fraction
    {

        private int _numerator, _denominator;

        public Fraction() { }

        public Fraction(int _numerator, int _denominator)
        {
            this._numerator = _numerator;
            this._denominator = _denominator;
        }

        public void Print()
        {
            Console.WriteLine($" {_numerator}/{_denominator} ");
        }

        public static Fraction SumOnNumber(Fraction frac, int a)
        {
            int newNumerator = frac._numerator + a * frac._denominator;
            return new Fraction(newNumerator, frac._denominator);
        }

        public static Fraction DiffOnNumber(Fraction frac, int a)
        {
            int newNumerator = frac._numerator - a * frac._denominator;
            return new Fraction(newNumerator, frac._denominator);
        }

        public static Fraction MultiplyOnNumber(Fraction frac, int a)
        {
            int newNumerator = frac._numerator * a;
            return new Fraction(newNumerator, frac._denominator);
        }

        public static Fraction DivisionOnNumber(Fraction frac, int a)
        {
            int newDenominator = frac._denominator * a;
            return new Fraction(frac._numerator, newDenominator);
        }



        public static Fraction operator +(Fraction a, Fraction b)
        {
            int newNumerator = a._numerator * b._denominator + b._numerator * a._denominator;
            int newDenominator = a._denominator * b._denominator;
            return new Fraction(newNumerator, newDenominator);
        }

        public static Fraction operator -(Fraction a, Fraction b)
        {
            int newNumerator = a._numerator * b._denominator - b._numerator * a._denominator;
            int newDenominator = a._denominator * b._denominator;
            return new Fraction(newNumerator, newDenominator);
        }

        public static Fraction operator *(Fraction a, Fraction b)
        {
            int newNumerator = a._numerator * b._numerator;
            int newDenominator = a._denominator * b._denominator;
            return new Fraction(newNumerator, newDenominator);
        }

        public static Fraction operator /(Fraction a, Fraction b)
        {
            if (b._numerator == 0)
            {
                throw new DivideByZeroException("Деление на ноль.");
            }
            int newNumerator = a._numerator * b._denominator;
            int newDenominator = a._denominator * b._numerator;
            return new Fraction(newNumerator, newDenominator);
        }

        ~Fraction() { }
    }
}