using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;

namespace ResponsiPemrograman5757
{
    public class Mahasiswa
    {
        public string Nim;
        public string Nama;
        public char Nilai;
        public string Hasil;
        public Mahasiswa(string Nim, string Nama, char Nilai) { 
            this.Nim = Nim;
            this.Nama = Nama;
            this.Nilai = Nilai;
            Hasil =  StatusKelulusan(this.Nilai);
        }

        public string StatusKelulusan(char Nilai)
        {
            
            return (Nilai == 'A' || Nilai == 'B') ?  "Lulus" : "Tidak Lulus";
            //return 
        }
    }
}
