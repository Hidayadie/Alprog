using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P9
{
    public class Animal
    {
        public string Name { get; set; }
        public virtual void Bunyi()
        {
            Console.WriteLine("Hewan ini berbunyi");
        }
    }
}
