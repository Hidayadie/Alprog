using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Tugas
{
    public class Printer
    {
        public virtual void show()
        {
            Console.WriteLine("");
        }
        public virtual void print()
        {
            Console.WriteLine("");
        }
        private string nama;
        private char h;



        public virtual void nulishori(string para)
        {
            string ah = "";
            char h = 'A';
            for (int i = 0; i < para.Length / 2; i++)
            {
                //Console.WriteLine(ah);
                for (int j = 0; j < 55; j++)
                {
                    Console.Write(ah);
                    Console.Write("\b{0}", h);
                    Thread.Sleep(5);
                    if (para[i] == h)
                    {
                        ah += h;

                        break;
                    }
                    else if (para[i] == ' ')
                    {
                        ah += " ";
                        break;

                    }
                    else
                    {
                        h++;

                    }

                }
                h = 'A';
            }
        }
        public virtual void nulisverti(string para)
        {
            string ah = "";
            char h = 'A';
            for (int i = 0; i < para.Length; i++)
            {
                //Console.WriteLine(ah);
                for (int j = 0; j < 55; j++)
                {
                    Console.WriteLine(ah + h);
                    Thread.Sleep(5);
                    if (para[i] == h)
                    {
                        ah += h;

                        break;
                    }
                    else if (para[i] == ' ')
                    {
                        ah += " ";
                        break;

                    }
                    else
                    {
                        h++;

                    }

                }
                h = 'A';
            }
        }
    }
}
