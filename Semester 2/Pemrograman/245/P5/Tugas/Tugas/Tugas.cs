using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tugas
{
    public class Tugas
    {
        
        public int Minimum(int a, int b)
        {
            return (a < b) ? a : b;
        }
        public int Minimum(int a, int b, int c)
        {
            return (a < b) ? a : (b < c) ? b : c;
        }
        public int Maximum(int a, int b)
        {
            return (a > b) ? a : b;
        }
        public int Maximum(int a, int b, int c)
        {
            return (c > b) ? c : (b > a) ? b : a;
        }
        /*
        public int Maximum(int a, int b, int c)
        {
            return a > b ? a : (c > b) ? c : b;
        }
        */
    }
}
