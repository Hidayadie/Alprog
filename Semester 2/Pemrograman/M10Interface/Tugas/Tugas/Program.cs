﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Tugas
{
    public class Program
    {
        static void Main(string[] args)
        {
            InterfacePrinter printer;

            Console.WriteLine("pilih:");
            Console.WriteLine("1. Epson");
            Console.WriteLine("2. Cannon");
            Console.WriteLine("3. LaserJet");
            Console.WriteLine("4. Gabut\n");
            Console.Write("-> ");
            int pilih = Convert.ToInt32(Console.ReadLine());
            //printer.Print("a");
            switch (pilih)
            {
                case 1:
                    //Epson epson = new Epson();
                    printer = new Epson();
                    break;
                case 2:
                    //Cannon cannon = new Cannon();
                    printer = new Cannon();
                    break;
                case 3:
                    //LaserJet laserJet = new LaserJet();
                    printer = new LaserJet();
                    break;

                default:
                    Console.Write("Pilihan tidak tersedia");
                    Console.Write("\b\b\bhhhh");
                    Console.ReadKey();
                    break;

            }
            Console.Clear();

            printer.Print();
            printer.show();
        }
    }
}
