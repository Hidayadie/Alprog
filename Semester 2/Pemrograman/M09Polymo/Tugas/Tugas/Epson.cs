using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tugas
{
    public class Epson : Printer
    {
        public override void show()
        {
            Console.WriteLine("Laser jet dimesi: 10*11");

        }
        public override void print()
        {
            Console.WriteLine("Printer Epson Sedang mencetak...");
            nulishori("tesss");
        }

    }
}
