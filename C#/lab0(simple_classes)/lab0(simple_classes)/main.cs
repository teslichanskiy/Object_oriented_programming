using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lab_0;
using static System.Runtime.InteropServices.JavaScript.JSType;


class MainProgram
{
    static void Main()
    {
        var frac = new Fraction(1, 3);
        var frac1 = new Fraction(2, 8);
        var frac_res = new Fraction();
        int a = 4;
        Console.WriteLine($"Fraction is: ");
        frac.Print();
        frac_res = Fraction.SumOnNumber(frac, a);
        Console.WriteLine($"SumOnNumber is: ");
        frac_res.Print();
        frac_res = Fraction.DiffOnNumber(frac, a);
        Console.WriteLine($"DiffOnNumber is: ");
        frac_res.Print();
        frac_res = Fraction.MultiplyOnNumber(frac, a);
        Console.WriteLine($"MultiplyOnNumber is: ");
        frac_res.Print();
        frac_res = Fraction.DivisionOnNumber(frac, a);
        Console.WriteLine($"DivisionOnNumber is: ");
        frac_res.Print();

        Console.WriteLine($"\nSecond fraction is: ");
        frac1.Print();
        frac_res = frac + frac1;
        Console.WriteLine($"Summ is: ");
        frac_res.Print();
        frac_res = frac - frac1;
        Console.WriteLine($"Diff is: ");
        frac_res.Print();
        frac_res = frac * frac1;
        Console.WriteLine($"Multiply is: ");
        frac_res.Print();
        frac_res = frac / frac1;
        Console.WriteLine($"Division is: ");
        frac_res.Print();
    }
}