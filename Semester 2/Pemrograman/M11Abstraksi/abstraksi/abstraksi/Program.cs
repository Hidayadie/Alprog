using Source;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace abstraksi
{
    internal class Program
    {

        static void Main(string[] args)
        {
            Mahasiswa mhs = new Mahasiswa();
            mhs.email = "asdadasdad";
            mhs.nama = "Asdawd";
            mhs.npm = "asdwad";

            Console.WriteLine("Pilih format...");
            Console.WriteLine("1. Json");
            Console.WriteLine("2. XML");
            Console.WriteLine("3. Csv\n");

            Console.Write("Nomor format 1,2,3 : ");

            int nomor = Convert.ToInt32(Console.ReadLine());

        IConvertObject ha = null;
            


            if (nomor == 1)
            {
                ha = new ConvertToJson();
            }
            else if (nomor == 2)
            {
                ha = new ConvertToXml();

            }
            else if (nomor == 3)
            {
                ha = new ConvertToCsv();

            }


            ha.Convert(mhs);
            Console.ReadKey();
        }
    }
}
