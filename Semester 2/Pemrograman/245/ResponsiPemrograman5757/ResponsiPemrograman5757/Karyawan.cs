using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ResponsiPemrograman5757
{
    public class Karyawan
    {
        public string NIK;
        public string Nama;
        public int GajiBulanan;

        public Karyawan(string NIK, string Nama, int GajiBulanan) {
            this.NIK = NIK;
            this.Nama = Nama;
            this.GajiBulanan = GajiBulanan;
        }
    }
}
