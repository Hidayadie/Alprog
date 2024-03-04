//#include 
using System;
using System.Xml.Linq;

class Program
{

    static void Main()
    {

        Console.WriteLine("Halo,");
        int a = 10, b = 6, c;
        do
        {
            Console.WriteLine("Selamat datang di program kalkulator sederhana, silahkan pilih...\n");
            Console.WriteLine("0. Exit\n1. Penambahan\n2. Pengurangan\n3. Perkalian\n4. Pembagian\n5. modulo\n-> ");
            c = Convert.ToInt32(Console.ReadLine());

            if (c != 0)
            {
                Console.WriteLine("Nilai a: ");
                a = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Nilai b: ");
                b = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("\n");
            }

            if (c == 1)
            {
                Console.WriteLine("Hasil penambahan {0} + {1} = {2}", a, b, tambah(a, b));
            }
            else if (c == 2)
            {
                Console.WriteLine("Hasil pengurangan {0} - {1} = {2}", a, b, kurang(a, b));
            }
            else if (c == 3)
            {
                Console.WriteLine("Hasil perkalian {0} * {1} = {2}", a, b, kali(a, b));
            }
            else if (c == 4)
            {
                Console.WriteLine("Hasil pembagian {0} / {1} = {2}", a, b, bagi(a, b));
            }
            else if (c == 5)
            {
                Console.WriteLine("Hasil modulos {0} % {1} = {2}", a, b, modulo(a, b));
            }
            Console.WriteLine("Press any key to continue...");
            Console.ReadKey();
            Console.Clear();
        } while (c != 0);

    }

    static int tambah(int X, int y)
    {
        return (X + y);
    }
    static int kurang(int X, int y)
    {
        return (X - y);
    }
    static int kali(int X, int y)
    {
        return (X * y);
    }
    static float bagi(float X, float y)
    {
        return (X / y);
    }
    static int modulo(int x, int y)
    {
        return (x % y);
    }
}
