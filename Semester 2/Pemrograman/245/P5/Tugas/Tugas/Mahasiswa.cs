using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tugas
{
    public class Mahasiswa
    {
        public String nim;
        public String nama;
        public Mahasiswa() { }
        public Mahasiswa(string nim, string nama)
        { 
            this.nim = nim;
            this.nama = nama;
        }
    }
}
