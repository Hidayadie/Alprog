using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pertemuan3_OOP
{
    public class Mahasiswa
    {

        public string Nim { get; set; }
        public string Nama { get; set; }
        public float IPK { get; set; }



        public void Registrasi()
        {
            Console.WriteLine("Nama: {0}", Nama);
            Console.WriteLine("NIM: {0}", Nim);
            Console.WriteLine("IPK: {0}", IPK);
            Console.WriteLine("Telah Melakukan Registrasi");
        }

        public void IsiKrs()
        {
            Console.WriteLine("{0} Sedang melakukan proses KRS \n", Nama);
        }


    }
}
