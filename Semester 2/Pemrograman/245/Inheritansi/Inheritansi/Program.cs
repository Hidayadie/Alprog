using System;
using System.Collections.Generic;
using System.Diagnostics.SymbolStore;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Inheritansi
{
    public class Program
    {
        static void Main(string[] args)
        {
            Person person = new Person("Mike", 20);
            Teacher teacher = new Teacher("Thomas", 30, "123", "Math");
            Student student = new Student("Abdul", 15, "32123", "haha");
      
            
            Console.ReadKey();
            string ha = "- = Hello World = -";
            string ah = "";
            char h = 'A';
            for (int i = 0; i < ha.Length; i++)
            {
                //Console.WriteLine(ah);
                for (int j = 0; j < 55; j++)
                {
                    Console.WriteLine(ah + h);
                    Thread.Sleep(5);
                    if (ha[i] == h)
                    {
                        ah += h;

                        break;
                    }
                    else if (ha[i] == ' ')
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
            //h = 'Z';
            /*
            for (int i = ha.Length; i >= 0; i--)
            {
                //Console.WriteLine(ah);
                for (int j = 0; j < 55; j++)
                {
                    
                    Thread.Sleep(5);
                    

                }
                h = 'A';
                
            }
            */
        }
    }
}
