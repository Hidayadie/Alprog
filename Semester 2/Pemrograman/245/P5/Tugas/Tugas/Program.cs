using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tugas
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Tugas keberapa? ");
            Console.WriteLine("1. Kalkulator");
            Console.WriteLine("2. Konstruktor");
            int pil = int.Parse(Console.ReadLine());
            //(pil == 1) ? Tugas1() : cetakHasil("Ha");
            switch (pil)
            {
                case 1:
                    Tugas1();
                    break;
                case 2:
                    Tugas2();
                    break;
                case 3:
                    Tugas3();
                    break;
                default:
                    //ha();
                    break;
            }
            //Tugas1();
        }

        static void Tugas1()
        {
            int hasil;
            Console.Clear();
            kalkulatod kalkulator = new kalkulatod();

            hasil = kalkulator.penambahan(10, 2);
            cetakHasil("hasil tambah: " + hasil);

            hasil = kalkulator.penambahan(10, 2, 5);
            cetakHasil("hasil tambah: " + hasil);

            hasil = kalkulator.pengurangan(10, 2);
            cetakHasil("hasil tambah: " + hasil);

            hasil = kalkulatod.perkalian(10, 2);
            cetakHasil("hasil tambah: " + hasil);

        }

        static void Tugas2()
        {
            Console.Clear();
            Mahasiswa mhs1 = new Mahasiswa();
            cetakHasil2(mhs1);
            
            Mahasiswa mhs2 = new Mahasiswa("123", "Hahaha");
            cetakHasil2(mhs2);


        }

        static void Tugas3()
        {
            Tugas hahaha = new Tugas();

            Console.WriteLine("minimum #1: {0}", hahaha.Minimum(3, 1));
            Console.WriteLine("minimum #2: {0}", hahaha.Minimum(3, 2, 4));
            Console.WriteLine("maximum #1: {0}", hahaha.Maximum(3, 1));
            Console.WriteLine("maximum #2: {0}", hahaha.Maximum(3, 2, 4));
        }
        static void cetakHasil(string hasil)
        {
            Console.WriteLine(hasil);
        }
        static void cetakHasil2(Mahasiswa mhs)
        {
            Console.WriteLine("Nim: {0}", mhs.nim);
            Console.WriteLine("Nama: {0}", mhs.nama);
            Console.WriteLine("----------");
        }




        //static void ha()
        //{
        //    string lorem = "Hello World";
        //    Console.WriteLine(lorem[0]);

        //}


        //static void rekur(string kalimat)
        //{
        //    int panjang = kalimat.Length;
        //    for (int i = 0; i < panjang; i++)
        //    {
        //        char dolor = kalimat[i];
        //        char ipsum = 'A';
        //        while (ipsum != dolor)
        //        {
        //            Console.Write
        //        }
        //    }
        //}
    }

}
