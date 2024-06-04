using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Tugas
{
    public class Epson : InterfacePrinter
    {
        public void show()
        {
            Console.WriteLine("Laser jet dimesi: 10*11");

        }

        public void Print()
        {
            Console.WriteLine("Printer Epson Sedang mencetak...");
        }
    }

    public class LaserJet : InterfacePrinter
    {
        public void show()
        {
            Console.WriteLine("Laser jet dimesi: 12*12");

        }
       

        public void Print()
        {
            Console.WriteLine("Printer Laser jet Sedang mencetak...");
        }
    }

    public class Cannon : InterfacePrinter
    {
        public void show()
        {
            Console.WriteLine("Cannon dimesi: 9.5*12");

        }

        public void Print()
        {
            Console.WriteLine("Printer Cannon Sedang mencetak...");
        }
    }

}
