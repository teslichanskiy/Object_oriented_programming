using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lab_3;

public class Program
{
    public static void Main(string[] args)
    {
        // Создание объектов фигур
        Triangle triangle = new Triangle(3, 4, 5);
        Lab_3.Rectangle rectangle = new Lab_3.Rectangle(2, 3);
        Circle circle = new Circle(5);


        // Вычисление и вывод площади и периметра для каждой фигуры
        Console.WriteLine("Triangle - Area: {0}, Perimeter: {1}", triangle.GetArea(), triangle.GetPerimeter());
        Console.WriteLine("Rectangle - Area: {0}, Perimeter: {1}", rectangle.GetArea(), rectangle.GetPerimeter());
        Console.WriteLine("Circle - Area: {0}, Perimeter: {1}", circle.GetArea(), circle.GetPerimeter());

        Square square = new Square(5);
        Console.WriteLine("Square Area: " + square.GetArea());
        Console.WriteLine("Square Perimeter: " + square.GetPerimeter());

        IsoscelesTriangle isoscelesTriangle = new IsoscelesTriangle(4, 6);
        Console.WriteLine("Isosceles Triangle Area: " + isoscelesTriangle.GetArea());
        Console.WriteLine("Isosceles Triangle Perimeter: " + isoscelesTriangle.GetPerimeter());

        EquilateralTriangle equilateralTriangle = new EquilateralTriangle(5);
        Console.WriteLine("Equilateral Triangle Area: " + equilateralTriangle.GetArea());
        Console.WriteLine("Equilateral Triangle Perimeter: " + equilateralTriangle.GetPerimeter());

        RightTriangle rightTriangle = new RightTriangle(4, 3);
        Console.WriteLine("Right Triangle Area: " + rightTriangle.GetArea());
        Console.WriteLine("Right Triangle Perimeter: " + rightTriangle.GetPerimeter());


        Console.ReadLine();
    }
}
