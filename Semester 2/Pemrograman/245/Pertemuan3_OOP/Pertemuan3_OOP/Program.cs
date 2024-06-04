using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pertemuan3_OOP
{
    public class Program
    {
        static void Main(string[] args)
        {
            Mahasiswa mahasiswa = new Mahasiswa();
            Mahasiswa mahasiswa2 = new Mahasiswa();

            mahasiswa.Nama = "Jono";
            mahasiswa.Nim = "1234";
            mahasiswa.IPK = 3.56f;
            mahasiswa2.Nama = "Tono";
            mahasiswa2.Nim = "1235";
            mahasiswa2.IPK = 3.90f;

            mahasiswa.Registrasi();
            mahasiswa.IsiKrs();

            mahasiswa2.Registrasi();
            mahasiswa2.IsiKrs();

    
        }
    }
}
