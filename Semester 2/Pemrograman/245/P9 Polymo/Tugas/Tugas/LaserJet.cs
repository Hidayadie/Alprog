using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tugas
{
    public class LaserJet : Printer
    {
        public override void show()
        {
            Console.WriteLine("Laser jet dimesi: 12*12");

        }
        public override void print()
        {
            Console.WriteLine("Printer Laser jet Sedang mencetak...");
        }
    }
}
