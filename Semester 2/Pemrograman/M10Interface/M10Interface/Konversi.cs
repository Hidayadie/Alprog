using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Newtonsoft.Json;

using System.IO;
using System.Xml.Serialization;


namespace M10Interface
{
    public class ConvertToJson : IConvertObject
    {
        public void Convert(Mahasiswa mhs)
        {
            string json = JsonConvert.SerializeObject(mhs);

            Console.WriteLine("Hasil konversi: {json}");
        }
    }

    public class ConvertToXml : IConvertObject
    {
        public void Convert(Mahasiswa mhs) 
        {
            using (StringWriter writer = new StringWriter())
            {

                XmlSerializer serializer = new XmlSerializer(typeof(Mahasiswa));
                serializer.Serialize(writer, mhs);

                string xml = writer.ToString();

                Console.WriteLine("Hasil xml: {xml}");
             }
        }
    }

    public class ConvertToCsv : IConvertObject
    {
        public void Convert(Mahasiswa mhs)
        {
            string csv = string.Format("{0},{1},{2}", mhs.npm, mhs.nama, mhs.email);
            Console.WriteLine("Hasil konversi Csv: {csv}");
        }
    }
}
