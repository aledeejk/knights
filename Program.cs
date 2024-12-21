using System;

public class FermatTheorem
{
    public static void Main(string[] args)
    {
        Console.WriteLine("Программа для проверки Великой теоремы Ферма.");

        Console.Write("Введите значение a: ");
        if (!int.TryParse(Console.ReadLine(), out int a))
        {
            Console.WriteLine("Ошибка: Некорректное значение для a.");
            return;
        }

        Console.Write("Введите значение b: ");
        if (!int.TryParse(Console.ReadLine(), out int b))
        {
            Console.WriteLine("Ошибка: Некорректное значение для b.");
            return;
        }

        Console.Write("Введите значение n (n > 2): ");
        if (!int.TryParse(Console.ReadLine(), out int n) || n <= 2)
        {
            Console.WriteLine("Ошибка: Некорректное значение для n. n должно быть целым числом больше 2.");
            return;
        }


        try
        {
           
            if (a < 0 || b < 0)
            {
                Console.WriteLine("Ошибка: a и b должны быть положительными числами.");
                return;
            }

           
            double result = Math.Pow(a, n) + Math.Pow(b, n);
            double expected = Math.Pow(a, n) + Math.Pow(b, n);
           
            if (expected == (int)expected) 
            {
                Console.WriteLine($"a = {a}, b = {b}, n = {n} \n Решение невозможно, т.к. a^n + b^n не может быть целым числом.");
            }
            else
            {
                Console.WriteLine($"a = {a}, b = {b}, n = {n} \n Решение возможно.");
            }

        }
        catch (Exception ex)
        {
            Console.WriteLine($"Ошибка: {ex.Message}");
        }
    }
}
