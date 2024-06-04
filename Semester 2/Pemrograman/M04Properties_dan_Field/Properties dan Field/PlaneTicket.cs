using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Properties_dan_Field
{
    public class PlaneTicket
    {
        public int convert;
        public void Cetak (string Asal, string Destinasi, int Harga, int matuang)
        {
            Console.Clear();
            Console.WriteLine("\t+======================================+");
            Console.WriteLine("\t| Asal : {0}\t\t\t\t|", Asal);
            Console.WriteLine("\t| Destinasi: {0}\t\t\t|", Destinasi);
            Console.WriteLine("\t| Dengan Harga = {0} {1}\t\t\t|", Harga, (matuang == 2) ? "Rupiah" : "$");
            Console.WriteLine("\t| Konversi ke {0} = {1} {2}\t|", (matuang == 2) ? "USD" : "IDR", (matuang == 1) ? Harga * 15000 : Harga / 15000, (matuang == 2) ? "$" : "Rupiah");
            Console.WriteLine("\t+======================================+");
        }
      

    }
}
