using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace P9
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Animal hewan = new Animal();
            hewan.Bunyi();


            Cat kucing = new Cat();
            //kucing.Bunyi();
            hewan = kucing;
            hewan.Bunyi();


            Chicken ayam = new Chicken();
            ayam.Bunyi();

            Dog anjing = new Dog();
            anjing.Bunyi();
        }
    }
}
