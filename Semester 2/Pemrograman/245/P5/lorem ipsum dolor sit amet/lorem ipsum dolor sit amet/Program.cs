using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace lorem_ipsum_dolor_sit_amet
{
    internal class Program
    {
        static void Main(string[] args)
        {
            char ha = 'A';
            for (int i = 0; i <26; i++)
            {
                Console.WriteLine(ha);
                ha++;
                Thread.Sleep(10);
            }
        }
    }
}
