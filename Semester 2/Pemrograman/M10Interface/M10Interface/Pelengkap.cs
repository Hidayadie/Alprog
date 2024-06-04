using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace M10Interface
{

    public class Mahasiswa
    {
        public string npm;
        public string nama;
        public string email;
        public Mahasiswa(string npm, string nama, string email) 
        {
            this.npm = npm;
            this.nama = nama;
            this.email = email;
        }
    }



    public interface IConvertObject
    {
        void Convert(Mahasiswa mhs);
    }
}
