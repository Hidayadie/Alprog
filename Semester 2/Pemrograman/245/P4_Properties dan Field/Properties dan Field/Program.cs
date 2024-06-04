using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace Properties_dan_Field
{
    public class Program
    {
        static void Main(string[] args)
        {
            PlaneTicket ticket = new PlaneTicket();

            string destinasi;
            int harga = 0, pil;

            Console.Write("\nAsal: ");
            string asal = Console.ReadLine();
            Console.Write("Tujuan: ");
            destinasi = Console.ReadLine();
            Console.Write("Harga,\n Pilih 1 untuk USD\n Pilih 2 untuk IDR\n = ");
            pil = int.Parse(Console.ReadLine());
            switch (pil)
            {
                case 1:
                    Console.Write("[USD] : ");
                    harga = int.Parse(Console.ReadLine());
                    break;
                case 2:
                    Console.Write("[IDR] : ");
                    harga = int.Parse(Console.ReadLine());
                    break;

            }
            ticket.Cetak(asal, destinasi, harga, pil);


        }
    }
}
