using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritansi
{
    public class Teacher : Person
    {
        public string TeacherID { get; set; }
        public string Subject { get; set; }

        public Teacher(string Name, int Age, string TeacherID, string Subject) : base(Name, Age)
        {
            this.Name = Name;
            this.Age = Age;
            this.TeacherID = TeacherID;
            this.Subject = Subject;
            
        }
    }
}
