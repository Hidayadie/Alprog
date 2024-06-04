using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ResponsiPemrograman5757
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Mahasiswa paijo = new Mahasiswa("12345", "Paijo", 'A');
            Mahasiswa Jhono = new Mahasiswa("33431", "Jhono", 'B');
            Mahasiswa Adi = new Mahasiswa("55481", "Adi", 'C');
            Console.WriteLine("No. Nim/Nama\t\tNilai\t\tStatus");
            Console.WriteLine("=========================================");
            Console.WriteLine("1. {0} {1} \t\t{2}\t\t{3}", paijo.Nim, paijo.Nama, paijo.Nilai, paijo.Hasil);
            Console.WriteLine("2. {0} {1} \t\t{2}\t\t{3}", Jhono.Nim, Jhono.Nama, Jhono.Nilai, Jhono.Hasil);
            Console.WriteLine("3. {0} {1} \t\t{2}\t\t{3}", Adi.Nim, Adi.Nama, Adi.Nilai, Adi.Hasil);


            Console.WriteLine("\n\n\n");

            
        }
    }
}
/*
gaji = gaji + (gaji 
    (gaji)) */