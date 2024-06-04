using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TugasTaksi
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Taksi taksi = new Taksi("Jono", true, 69);
            taksi.InfoTaksi();
            taksi.MengambilPenumpang();
            taksi.MenurunkanPenumpang();

            Console.WriteLine("\n\nTaksi 2\n\n");

            Taksi punyaku = new Taksi("uyeb", false, 0);
            punyaku.InfoTaksi();
            punyaku.MengambilPenumpang();
            punyaku.MenurunkanPenumpang();
        }
    }
}
