using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritansi
{
    public class Person
    {
        public string Name;
        public int Age;
        
        public Person(string Name, int Age) 
        {
            this.Name = Name;
            this.Age = Age;
            GetNameAndAge();
        }
        
        public void GetNameAndAge()
        {
            Console.WriteLine("Nama: {0} dan berumur {1}", Name, Age);
        }
    }
}

//  public string Name { get; set; }
// public int Age { get; set; }