using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TugasTaksi
{
    public class Taksi
    {
        public string Driver, Status;
        public bool Kerja;
        public int Penumpang;

        public Taksi(string penyetir, bool nyetir, int penumpang) {
            Driver = penyetir;
            Kerja = nyetir;
            Penumpang = penumpang;
        }
        public void InfoTaksi()
        {
            Console.WriteLine("Nama Driver: {0}", Driver);
            Console.WriteLine("Sedang kerja: {0}", Status = (Kerja == true) ? "Ya" : "Tidak");
            Console.WriteLine("Jumlah penumpang: {0}\n", Penumpang);
        }

        public void MengambilPenumpang()
        {
            if (Kerja == true)
            {

            Console.WriteLine("{0}, Sedang menjemput penumpang", Driver);
            }
        }

        public void MenurunkanPenumpang()
        {
            if (Kerja == true)
            {

            Console.WriteLine("{0}, Selesai mengantarkan penumpang", Driver);
            }
        }
    }
}
