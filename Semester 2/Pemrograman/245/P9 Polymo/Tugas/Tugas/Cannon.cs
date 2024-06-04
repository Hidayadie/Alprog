using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tugas
{
    public class Cannon : Printer
    {
        public override void show()
        {
            Console.WriteLine("Cannon dimesi: 9.5*12");

        }
        public override void print()
        {
            Console.WriteLine("Printer Cannon Sedang mencetak...");
        }
    }
}
