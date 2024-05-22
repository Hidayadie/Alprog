// See https://aka.ms/new-console-template for more information
//Console.WriteLine("Hello, World!");
namespace M03_Pengenalan_OOP {

	Class Program {
		static void main() {
			Mahasiswa mahasiswa = new Mahasiswa();
	
			mahasiswa.Nama = "Jono";
			mahasiswa.Nim = "12345";
			mahasiswa.Ipk = 5;

			mahasiswa.Registrasi();
			mahasiswa.IsiKrs();		
		}
	}
}
