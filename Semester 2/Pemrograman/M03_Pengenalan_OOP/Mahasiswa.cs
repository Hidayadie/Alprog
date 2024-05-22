namespace M03_Pengenalan_OOP;

public class Mahasiswa
{
	public string Nim { get; set;}
	public string Nama {get; set;}
	public float Ipk {get; set;}

	public void Registrasi() {
		console.WriteLine("Nama: {0}", Nama);
		console.WriteLine("Nim: {0}", Nim);
		console.WriteLine("IPK: {0}", Ipk);
		console.WriteLine("Telah melakukan registrasi");
	}

	public void IsiKrs()
	{
		console.WriteLine("{0} Sedang melakukan prses Krs\n", Nama);
	}
}
