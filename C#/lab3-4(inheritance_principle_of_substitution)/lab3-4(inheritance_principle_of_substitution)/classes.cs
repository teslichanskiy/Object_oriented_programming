using System;

namespace Lab_3
{
    // Абстрактный класс геометрической фигуры
    public abstract class Shape
    {
        // Абстрактный метод для вычисления площади фигуры
        public abstract double GetArea();

        // Абстрактный метод для вычисления периметра фигуры
        public abstract double GetPerimeter();
    }

    // Класс треугольника, наследуется от Shape
    public class Triangle : Shape
    {
        private double side1;
        private double side2;
        private double side3;

        public Triangle(double s1, double s2, double s3)
        {
            side1 = s1;
            side2 = s2;
            side3 = s3;
        }

        public override double GetArea()
        {
            // Формула Герона для вычисления площади треугольника
            double p = GetPerimeter() / 2;
            return Math.Sqrt(p * (p - side1) * (p - side2) * (p - side3));
        }

        public override double GetPerimeter()
        {
            return side1 + side2 + side3;
        }
    }

    public class IsoscelesTriangle : Triangle
    {
        public IsoscelesTriangle(double baseSide, double legs)
        : base(baseSide, legs, legs) { }
    }

    // Класс равностороннего треугольника, наследуется от Triangle
    public class EquilateralTriangle : Triangle
    {
        public EquilateralTriangle(double side)
        : base(side, side, side) { }
    }

    // Класс прямоугольного треугольника, наследуется от Triangle
    public class RightTriangle : Triangle
    {
        public RightTriangle(double baseSide, double height)
        : base(baseSide, height, Math.Sqrt(baseSide * baseSide + height * height)) { }
    }

    // Класс прямоугольника, наследуется от Shape
    public class Rectangle : Shape
    {
        private double width;
        private double height;

        public Rectangle(double w, double h)
        {
            width = w;
            height = h;
        }

        public override double GetArea()
        {
            return width * height;
        }

        public override double GetPerimeter()
        {
            return 2 * (width + height);
        }
    }

    //Класс квадрата, наследуется от прямоугольника
    public class Square : Rectangle
    {
        public Square(double side)
        : base(side, side) { }
    }

    // Класс круга, наследуется от Shape
    public class Circle : Shape
    {
        protected double radius;

        public Circle(double r)
        {
            radius = r;
        }

        public override double GetArea()
        {
            return Math.PI * radius * radius;
        }

        public override double GetPerimeter()
        {
            return 2 * Math.PI * radius;
        }
    }
}
