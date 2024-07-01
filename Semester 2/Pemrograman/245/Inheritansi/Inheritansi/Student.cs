using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritansi
{
    public class Student : Person
    {

        public string StudentID;
        public string Email;
        public Student(string Name, int Age, string StudentID, string Email) : base (Name, Age)
        {
            this.Name = Name;
            this.Age = Age;
            this.StudentID = StudentID;
            this.Email = Email;
            
        }
    }
}
