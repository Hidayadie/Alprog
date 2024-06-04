using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace M10Interface
{
    public class Program
    {
        static void Main(string[] args)
        {

            Mahasiswa mhs = new Mahasiswa("23.11.5757", "Hidayat Adie", "Hidayadie");

            Console.WriteLine("Pilih format...");
            Console.WriteLine("1. Json");
            Console.WriteLine("2. XML");
            Console.WriteLine("3. Csv\n");

            Console.Write("Nomor format 1,2,3");

            int nomor = Convert.ToInt32(Console.ReadLine());

            IConvertObject convert;


            if (nomor == 1) 
            {
                convert = new ConvertToJson();
            }
            else if (nomor == 2)
            {
                convert = new ConvertToXml();

            }
            else if (nomor == 3)
            {
                convert = new ConvertToCsv();
        
            }


            //convert.Convert(mhs);
            Console.ReadKey();
        }

    }
}
