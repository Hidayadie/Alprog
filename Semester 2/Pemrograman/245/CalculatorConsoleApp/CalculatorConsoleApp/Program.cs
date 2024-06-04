using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace CalculatorConsoleApp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int a = 5, b = 6, c;
    
            Console.Title = "tes";
            
            do
            {
                Console.Clear();
                Console.WriteLine("Pilih menu kalkulator:\n\n1. Penambahan\n2. Pengurangan\n3. Perkalian\n4. Pembagian\n0. Exit");
                Console.Write("\n-> ");
                c = int.Parse(Console.ReadLine());
                if (c > 0 && c < 5)
                {
                    Console.Write("Nilai a: ");
                    a = int.Parse(Console.ReadLine());
                    Console.Write("Nilai b: ");
                    b = int.Parse(Console.ReadLine());
                    //Console.Clear();
                }
                else if (c >4 || c < 0)
                {
                    Console.WriteLine("g valid...");
                   // Console.WriteLine("\nPress any key to continue...");
                    Console.ReadKey();
                }
                if (c == 1)
                {

                    Console.WriteLine("Hasil Penambahan {0} + {1} = {2}", a, b, penambahan(a, b));

                }
                else if (c == 2)
                {

                    Console.WriteLine("Hasil pengurangan {0} - {1} = {2}", a, b, pengurangan(a, b));
                }
                else if (c == 3)
                {

                    Console.WriteLine("Hasil perkalian {0} * {1} = {2}", a, b, perkalian(a, b));
                }
                else if (c == 4)
                {

                    Console.WriteLine("Hasil pembagian {0} / {1} = {2}", a, b, pembagian(a, b));
                }

                Console.WriteLine("\nPress any key to continue...");
                Console.ReadKey();
            } while (c != 0);
            
          
            
        }

        static int penambahan(int a, int b)
        {
            return a + b;
        }
        
        static int pengurangan(int a, int b)
        {
            return a - b;
        }
        
        static int perkalian(int a, int b)
        {
            return a * b;
        }
        
        static float pembagian(float a, float b)
        {
            return a / b;
        }
    }
}
