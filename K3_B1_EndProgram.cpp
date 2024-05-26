#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct kurir_motor
{
    string jenis_kecepatan;
    string deskripsi_kecepatan;
    string harga;
};

struct kurir_mobil
{
    string jenis_kecepatan;
    string deskripsi_kecepatan;
    string harga;
};


struct jenis_kurir
{
    kurir_motor motor;
    kurir_mobil mobil;
};
jenis_kurir kurir[100];

struct pesanan_motor
{
    string nama;
    string alamat_barang;
    string no_telp;
    string jenis_kurir;
    string harga;
    int jarak;
    int harga_total;
};

struct pesanan_mobil
{
    string nama;
    string alamat_barang;
    string no_telp;
    string jenis_kurir;
    string harga;
    int jarak;
    int harga_total;
};

struct pesanan
{
    pesanan_motor psn_motor;
    pesanan_mobil psn_mobil;
};
pesanan order[100];

int jml_data = 0;
int indx_motor, indx_mobil, indx_pesanan, idx;

void BubbleSortHargaMotorAscending(struct jenis_kurir kurir[], int n) 
{ 
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (!kurir[j].motor.jenis_kecepatan.empty() && !kurir[j + 1].motor.jenis_kecepatan.empty()) {
                if (stoi(kurir[j].motor.harga) > stoi(kurir[j + 1].motor.harga)) {
                    swap(kurir[j], kurir[j + 1]);
                }
            }
        }
    }
}

void BubbleSortHargaMobilAscending(struct jenis_kurir kurir[], int n) 
{ 
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (!kurir[j].mobil.jenis_kecepatan.empty() && !kurir[j + 1].mobil.jenis_kecepatan.empty()) {
                if (stoi(kurir[j].mobil.harga) > stoi(kurir[j + 1].mobil.harga)) {
                    swap(kurir[j], kurir[j + 1]);
                }
            }
        }
    }
}

void BubbleSortNamaMotorAscending(struct pesanan order[], int n) 
{ 
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (!order[j].psn_motor.nama.empty() && !order[j + 1].psn_motor.nama.empty()) 
            {
                if ((order[j].psn_motor.nama) > (order[j + 1].psn_motor.nama)) 
                {
                    swap(order[j], order[j + 1]);
                }
            }
        }
    }
}

void BubbleSortNamaMobilAscending(struct pesanan order[], int n) 
{ 
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (!order[j].psn_mobil.nama.empty() && !order[j + 1].psn_mobil.nama.empty()) 
            {
                if (stoi(order[j].psn_mobil.nama) > stoi(order[j + 1].psn_mobil.nama)) 
                {
                    swap(order[j], order[j + 1]);
                }
            }
        }
    }
}

void BinarySearch() 
{
    cout << "Jenis Pesanan Yang Dicari: " << endl;
    cout << "1. Pesanan Kurir Motor" << endl;
    cout << "2. Pesanan Kurir Mobil" << endl;
    cout << "Pilihan Anda: ";
    int pilihan;
    cin >> pilihan;
    cin.ignore();

    if (pilihan == 1) {
        BubbleSortNamaMotorAscending(order, jml_data);
        cout << "Masukkan Nomor Telepon Yang Digunakan Untuk Mendaftar: ";
        string nama;
        getline(cin, nama);

        int awal = 0;
        int akhir = jml_data - 1;
        int tengah;

        while (awal <= akhir) {
            tengah = (awal + akhir) / 2;
            if (nama == order[tengah].psn_motor.no_telp) 
            {
                cout << "Berikut Rincian Pesanan Anda: " << "\n" << "\n" << 
                "Nama: " << order[tengah].psn_motor.nama << "\n" <<
                "No. Telepon: " << order[tengah].psn_motor.no_telp << "\n" <<
                "Alamat Barang: " << order[tengah].psn_motor.alamat_barang << "\n" <<
                "Jenis Kurir: " << order[tengah].psn_motor.jenis_kurir << "\n" <<
                "Jarak: " << order[tengah].psn_motor.jarak << "\n" <<
                "Harga: " << order[tengah].psn_motor.harga << "\n" <<
                "Total Harga: " << order[tengah].psn_motor.harga_total << "\n" << endl;
                return;
            } 
            else if (nama < order[tengah].psn_motor.no_telp) 
            {
                akhir = tengah - 1;
            } 
            else 
            {
                awal = tengah + 1;
            }
        }
        cout << "Orderan Tidak Ditemukan" << endl;
    } 
    else if (pilihan == 2) 
    { 
        BubbleSortNamaMobilAscending(order, jml_data);
        cout << "Masukkan Nama Ikan Besar: ";
        string nama;
        getline(cin, nama);

        int awal = 0;
        int akhir = jml_data - 1;
        int tengah;

        while (awal <= akhir) {
            tengah = (awal + akhir) / 2;
            if (nama == order[tengah].psn_mobil.no_telp) 
            {
                cout << "Berikut Rincian Pesanan Anda: " << "\n" << "\n" << 
                "Nama: " << order[tengah].psn_mobil.nama << "\n" <<
                "No. Telepon: " << order[tengah].psn_mobil.no_telp << "\n" <<
                "Alamat Barang: " << order[tengah].psn_mobil.alamat_barang << "\n" <<
                "Jenis Kurir: " << order[tengah].psn_mobil.jenis_kurir << "\n" <<
                "Jarak: " << order[tengah].psn_mobil.jarak << "\n" <<
                "Harga: " << order[tengah].psn_mobil.harga << "\n" <<
                "Total Harga: " << order[tengah].psn_mobil.harga_total << "\n" << endl;
                return;
            } else if (nama < order[tengah].psn_mobil.no_telp) {
                akhir = tengah - 1;
            } else {
                awal = tengah + 1;
            }
        }
        cout << "Orderan Tidak Ditemukan." << endl;
    } 
    else 
    {
        cout << "Pilihan tidak valid" << endl;
    }

}

int total_harga(int *harga_kurir, int &jarak_alamat)
{

    if (jarak_alamat == 1)
    {
        return *harga_kurir;
    }

    else
    {
        jarak_alamat = jarak_alamat - 1;
        return *harga_kurir + total_harga(harga_kurir, jarak_alamat);
    }
}

void lihat_data_kurir()
{
    BubbleSortHargaMotorAscending(kurir, jml_data);
    cout << "Berikut Jenis Kurir Motor yang Available Beserta Harganya." << endl;
    cout << "" << endl;
    for (int i = 0; i < jml_data && !kurir[i].motor.jenis_kecepatan.empty(); i++)
    {
        cout << i + 1 << ". " << kurir[i].motor.jenis_kecepatan << " | " << kurir[i].motor.deskripsi_kecepatan << " | " << kurir[i].motor.harga << "/KM." << endl;
    }

    cout << "" << endl;

    BubbleSortHargaMobilAscending(kurir, jml_data);
    cout << "Berikut Jenis Kurir Mobil yang Available Beserta Harganya." << endl;
    cout << "" << endl;
    for (int i = 0; i < jml_data && !kurir[i].mobil.jenis_kecepatan.empty(); i++)
    {
        cout << i + 1 << ". " << kurir[i].mobil.jenis_kecepatan << " | " << kurir[i].mobil.deskripsi_kecepatan << " | " << kurir[i].mobil.harga << "/KM." << endl;
    }

    cout << "" << endl;
}

void lihat_orderan()
{
    cout << "Berikut List Orderan Kurir Motor yang telah dibuat." << "\n" << endl;
        for (int i = 0; i < jml_data && !order[i].psn_motor.nama.empty(); i++)
        {
            cout << i + 1 << ". Nama: " << order[i].psn_motor.nama << "\n" 
            << "Nomor Telepon: " << order[i].psn_motor.no_telp << "\n" 
            << "Alamat Barang: " << order[i].psn_motor.alamat_barang << "\n" 
            << "Kurir Yang Dipesan: " << order[i].psn_motor.jenis_kurir << "\n" 
            << "Jarak Penggunaan: "<< order[i].psn_motor.jarak << "Km" << "\n" 
            << "Harga: " << order[i].psn_motor.harga << "\n" << endl;
        }

    cout << "Berikut List Orderan Kurir Mobil yang telah dibuat." << "\n" << endl;
        for (int i = 0; i < jml_data && !order[i].psn_mobil.nama.empty(); i++)
        {
            cout << i + 1 << ". Nama: " << order[i].psn_mobil.nama << "\n" 
            << "Nomor Telepon: " << order[i].psn_mobil.no_telp << "\n" 
            << "Alamat Barang: " << order[i].psn_mobil.alamat_barang << "\n" 
            << "Kurir Yang Dipesan: " << order[i].psn_mobil.jenis_kurir << "\n" 
            << "Jarak Penggunaan: "<< order[i].psn_mobil.jarak << "Km" << "\n" 
            << "Harga: " << order[i].psn_mobil.harga << "\n" << endl;
        }
}

void tambah_data()
{
    lihat_data_kurir();
    string pilih1;
    string jenis_kurir;
    string deskripsi_kecepatan;
    string harga;
    cin.ignore();
    cout << "1. Kurir Motor" << endl;
    cout << "2. Kurir Mobil" << endl;
    cout << "Jenis Kurir yang Ingin Ditambahkan (1/2): ";
    getline(cin, pilih1);

    if (pilih1 == "1")
    {
        cout << "Masukkan Jenis Kurir: ";
        fflush(stdin);
        getline(cin, jenis_kurir);
        cout << "Masukkan Deskripsi Kecepatan Kurir: ";
        fflush(stdin);
        getline(cin, deskripsi_kecepatan);
        cout << "Harga Kurir: ";
        fflush(stdin);
        getline(cin, harga);
        kurir[indx_motor].motor.jenis_kecepatan = jenis_kurir;
        kurir[indx_motor].motor.deskripsi_kecepatan = deskripsi_kecepatan;
        kurir[indx_motor].motor.harga = harga;
        indx_motor++;
    }
    else if (pilih1 == "2")
    {
        cout << "Masukkan Jenis Kurir: ";
        fflush(stdin);
        getline(cin, jenis_kurir);
        cout << "Masukkan Deskripsi Kecepatan Kurir: ";
        fflush(stdin);
        getline(cin, deskripsi_kecepatan);
        cout << "Harga Kurir: ";
        fflush(stdin);
        getline(cin, harga);
        kurir[indx_mobil].mobil.jenis_kecepatan = jenis_kurir;
        kurir[indx_mobil].mobil.deskripsi_kecepatan = deskripsi_kecepatan;
        kurir[indx_mobil].mobil.harga = harga;
        indx_mobil++;
    }
    else
    {
        cout << "Input tidak valid!" << endl; // Error Handling
    }
    jml_data++;
    cout << "" << endl;
}

void edit_data()
{
    lihat_data_kurir();
    string pilih2;
    string jenis_kurir;
    string deskripsi_kecepatan;
    string harga;
    cin.ignore();
    cout << "1. Kurir Motor" << endl;
    cout << "2. Kurir Mobil" << endl;
    cout << "Jenis Kurir yang Ingin Diedit (1/2): ";
    getline(cin, pilih2);

    if (pilih2 == "1")
    {
        cout << "Masukkan urutan kurir yang ingin diedit: " << endl;
        cin >> idx;
        cin.ignore();
        cout << "Masukkan Jenis Kurir: ";
        fflush(stdin);
        getline(cin, jenis_kurir);
        cout << "Masukkan Deskripsi Kecepatan Kurir: ";
        fflush(stdin);
        getline(cin, deskripsi_kecepatan);
        cout << "Harga Kurir: ";
        fflush(stdin);
        getline(cin, harga);
        kurir[idx - 1].motor.jenis_kecepatan = jenis_kurir;
        kurir[idx - 1].motor.deskripsi_kecepatan = deskripsi_kecepatan;
        kurir[idx - 1].motor.harga = harga;
    }
    else if (pilih2 == "2")
    {
        cout << "Masukkan urutan kurir yang ingin diedit: " << endl;
        cin >> idx;
        cout << "Masukkan Jenis Kurir: ";
        fflush(stdin);
        getline(cin, jenis_kurir);
        cout << "Masukkan Deskripsi Kecepatan Kurir: ";
        fflush(stdin);
        getline(cin, deskripsi_kecepatan);
        cout << "Harga Kurir: ";
        fflush(stdin);
        getline(cin, harga);
        kurir[idx - 1].mobil.jenis_kecepatan = jenis_kurir;
        kurir[idx - 1].mobil.deskripsi_kecepatan = deskripsi_kecepatan;
        kurir[idx - 1].mobil.harga = harga;
    }
    else
    {
        cout << "Input tidak valid!" << endl; // Error Handling
    }
    jml_data++;
    cout << "" << endl;
}

void hapus_data()
{
    lihat_data_kurir();
    string pilih3;
    cout << "1. Kurir Motor" << endl;
    cout << "2. Kurir Mobil" << endl;
    cout << "Jenis Kurir yang Ingin Dihapus (1/2): ";
    cin.ignore();
    getline(cin, pilih3);

    if (pilih3 == "1")
    {
        cout << "Masukkan urutan kurir yang ingin dihapus: " << endl;
        cin >> idx;
        for (int i = idx - 1; i < indx_motor; i++)
        {
            kurir[i].motor.jenis_kecepatan = kurir[i + 1].motor.jenis_kecepatan;
            kurir[i].motor.deskripsi_kecepatan = kurir[i + 1].motor.deskripsi_kecepatan;
            kurir[i].motor.harga = kurir[i + 1].motor.harga;
        }
            kurir[indx_motor].motor.jenis_kecepatan = "";
            kurir[indx_motor].motor.deskripsi_kecepatan = "";
            kurir[indx_motor].motor.harga = "";
            indx_motor--;
        
    }
    else if (pilih3 == "2")
    {
        cout << "Masukkan urutan kurir yang ingin dihapus: " << endl;
        cin >> idx;
        for (int i = idx - 1; i < indx_mobil; i++)
        {
            kurir[i].mobil.jenis_kecepatan = kurir[i + 1].mobil.jenis_kecepatan;
            kurir[i].mobil.deskripsi_kecepatan = kurir[i + 1].mobil.deskripsi_kecepatan;
            kurir[i].mobil.harga = kurir[i + 1].mobil.harga;
        }
            kurir[indx_mobil].mobil.jenis_kecepatan = "";
            kurir[indx_mobil].mobil.deskripsi_kecepatan = "";
            kurir[indx_mobil].mobil.harga = "";
            indx_mobil--;
        
    }
    else
    {
        cout << "Input tidak valid!" << endl; // Error Handling
    }

    cout << "" << endl;
}

void Buat_Pesanan ()
{
    string pilih4;

    while (pilih4 != "3")
    {
        cin.clear();
        cin.ignore();
        cout << "" << endl;
        cout << "1. Kurir Motor (Untuk Barang Berat <= 5 Kg)" << endl;
        cout << "2. Kurir Mobil (Untuk Barang dengan Berat > 5 Kg)" << endl;
        cout << "3. Keluar" << endl;
        cout << "Masukkan Jenis Kurir yang Ingin Dipilih: ";
        getline(cin, pilih4);

        if (pilih4 == "1")
        {
            cin.clear();
            string nama, alamat, no_telp;
            int jarak, harga_kurir, hasil, pilih5, jarak_cek;

            while (pilih5 != 0)
            {
                cout << "" << endl;
                BubbleSortHargaMotorAscending(kurir, jml_data);
                for (int i = 0; i < jml_data && !kurir[i].motor.jenis_kecepatan.empty(); i++)
                {
                    cout << i + 1 << ". " << kurir[i].motor.jenis_kecepatan << " | " << kurir[i].motor.harga << "/KM." << endl;
                }
                cout << "0. Keluar" << endl;
                cout << "Masukkan Jenis Kurir yang Ingin Dipilih" << endl;
                cin >> pilih5;

                if (pilih5 <= jml_data && !kurir[pilih5].motor.jenis_kecepatan.empty())
                {
                    cin.ignore();
                    cout << "" << endl;
                    cout << "Masukkan Nama Pemesan: " << endl;
                    getline(cin, nama);
                    fflush stdin;
                    cout << "Masukkan Alamat Penjemputan Barang: " << endl;
                    getline(cin, alamat);
                    fflush stdin;
                    cout << "Masukkan Nomor Telepon Pemesan: " << endl;
                    getline(cin, no_telp);
                    fflush stdin;
                    cout << "Masukkan Jarak Penjemputan Barang: " << endl;
                    cin >> jarak;
                    jarak_cek = jarak;
                    

                    order[indx_pesanan].psn_motor.nama = nama;
                    order[indx_pesanan].psn_motor.alamat_barang = alamat;
                    order[indx_pesanan].psn_motor.no_telp = no_telp;
                    order[indx_pesanan].psn_motor.jarak = jarak;

                    idx = pilih5;
                    harga_kurir = stoi(kurir[idx - 1].motor.harga);
                    hasil = total_harga(&harga_kurir, jarak_cek);
                    order[indx_pesanan].psn_motor.harga_total = hasil;
                    order[indx_pesanan].psn_motor.jenis_kurir = kurir[idx - 1].motor.jenis_kecepatan;
                    order[indx_pesanan].psn_motor.harga = kurir[idx - 1].motor.harga;

                    cout << "" << endl;
                    cout << "Berikut Pesanan Anda: " << "\n" << "\n"
                    << "Nama Pemesan: " << nama << "\n"
                    << "Alamat Penjemputan Barang: " << alamat << "\n"
                    << "Nomor Telepon Pemesan: " << no_telp << "\n"
                    << "Jenis Kurir :" << order[indx_pesanan].psn_motor.jenis_kurir << "\n"
                    << "Jarak Penjemputan Barang: " << jarak << "Km" << "\n"
                    << "Harga Kurir: " << kurir[idx - 1].motor.harga << "\n"
                    << "Total Harga: " << hasil << "\n"
                    << "" << "\n"
                    << "Terima Kasih Telah Menggunakan Layanan Kami" << endl;
                    cout << "" << endl;
                    indx_pesanan++;

                    break;
                }
                else if (pilih5 == 0)
                {
                    cout << "" << endl;
                }               
                else
                {
                    cout << "Input tidak valid!" << endl;
                }
            }
        }
        else if (pilih4 == "2")
        {
            cin.clear();
            string nama, alamat, no_telp;
            int jarak, harga_kurir, hasil, pilih5, jarak_cek;

            while (pilih5 != 0)
            {
                cout << "" << endl;
                BubbleSortHargaMobilAscending(kurir, jml_data);
                for (int i = 0; i < jml_data && !kurir[i].mobil.jenis_kecepatan.empty(); i++)
                {
                    cout << i + 1 << ". " << kurir[i].mobil.jenis_kecepatan << " | " << kurir[i].mobil.harga << "/KM." << endl;
                }
                cout << "0. Keluar" << endl;
                cout << "Masukkan Jenis Kurir yang Ingin Dipilih" << endl;
                cin >> pilih5;

                if (pilih5 <= jml_data && !kurir[pilih5].mobil.jenis_kecepatan.empty())
                {
                    cin.ignore();
                    cout << "" << endl;
                    cout << "Masukkan Nama Pemesan: " << endl;
                    getline(cin, nama);
                    fflush stdin;
                    cout << "Masukkan Alamat Penjemputan Barang: " << endl;
                    getline(cin, alamat);
                    fflush stdin;
                    cout << "Masukkan Nomor Telepon Pemesan: " << endl;
                    getline(cin, no_telp);
                    fflush stdin;
                    cout << "Masukkan Jarak Penjemputan Barang: " << endl;
                    cin >> jarak;
                    jarak_cek = jarak;
                    

                    order[indx_pesanan].psn_mobil.nama = nama;
                    order[indx_pesanan].psn_mobil.alamat_barang = alamat;
                    order[indx_pesanan].psn_mobil.no_telp = no_telp;
                    order[indx_pesanan].psn_mobil.jarak = jarak;

                    idx = pilih5;
                    harga_kurir = stoi(kurir[idx - 1].mobil.harga);
                    hasil = total_harga(&harga_kurir, jarak_cek);
                    order[indx_pesanan].psn_mobil.harga = hasil;
                    order[indx_pesanan].psn_mobil.jenis_kurir = kurir[idx - 1].mobil.jenis_kecepatan;

                    cout << "" << endl;
                    cout << "Berikut Pesanan Anda: " << "\n" << "\n"
                    << "Nama Pemesan: " << nama << "\n"
                    << "Alamat Penjemputan Barang: " << alamat << "\n"
                    << "Nomor Telepon Pemesan: " << no_telp << "\n"
                    << "Jenis Kurir :" << order[indx_pesanan].psn_mobil.jenis_kurir << "\n"
                    << "Jarak Penjemputan Barang: " << jarak << "Km" << "\n"
                    << "Harga Kurir: " << kurir[idx - 1].mobil.harga << "\n"
                    << "Total Harga: " << hasil << "\n"
                    << "" << "\n"
                    << "Terima Kasih Telah Menggunakan Layanan Kami" << endl;
                    cout << "" << endl;
                    indx_pesanan++;

                    break;
                }
                else if (pilih5 == 0)
                {
                    cout << "" << endl;
                }               
                else
                {
                    cout << "Input tidak valid!" << endl;
                }
            }
        }
        else if (pilih4 == "3")
        {
            cout << "" << endl;
        }
        else
        {
            cout << "Pilihan Anda tidak Valid" << endl;
        }
    } 
}

void menu_admin ()
{
    string pilihan;

    while (pilihan != "6")
    {
        cout << "" << endl;
        cout << "1. Lihat Data Kurir" << endl;
        cout << "2. Tambah Data" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Edit Data" << endl;
        cout << "5. Lihat Orderan" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan pilihan anda: " << endl;
        cin >> pilihan;

            if (pilihan == "1")
            {
                lihat_data_kurir();
            }
            else if (pilihan == "2")
            {
                tambah_data();
            }
            else if (pilihan == "3")
            {
                hapus_data();
            }
            else if (pilihan == "4")
            {
                edit_data();
            }
            else if (pilihan == "5")
            {
                lihat_orderan();
            }
            else if (pilihan == "6")
            {
                cout << "Anda telah keluar dari menu admin." << endl;
            }
            else
            {
                cout << "Pilihan anda salah" << endl;
            }
        }
    

}

void menu_user ()
{
    string pilihan;  
    
    while (pilihan != "4")
    {
        cout << "" << endl;
        cout << "1. Lihat List Harga" << endl;
        cout << "2. Buat Pesanan" << endl;
        cout << "3. Lihat Pesanan" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan pilihan anda: " << endl;
        cin >> pilihan;

            if (pilihan == "1")
            {
                lihat_data_kurir();
            }
            else if (pilihan == "2")
            {
                Buat_Pesanan();
            }
            else if (pilihan == "3")
            {
                BinarySearch();
            }
            else if (pilihan == "4")
            {
                cout << "" << endl;
            }
            else
            {
                cout << "Pilihan anda salah" << endl;
            }
    }
}

int main()
{
    kurir[0].motor.jenis_kecepatan = "Kurir Express";
    kurir[0].motor.deskripsi_kecepatan = "Kurir yang dapat Memberikan pelayanan yang cepat dan tepat untuk pengguna.";
    kurir[0].motor.harga = "10000";

    kurir[1].motor.jenis_kecepatan = "Kurir Instant";
    kurir[1].motor.deskripsi_kecepatan = "Kurir yang dapat memberikan pelayanan SATSET kepada pengguna, bisa digunakan jika kamu sedang buru-buru.";
    kurir[1].motor.harga = "12000";

    kurir[2].motor.jenis_kecepatan = "Kurir Santai";
    kurir[2].motor.deskripsi_kecepatan = "Kurir yang dapat DIPESAN pada waktu yang telah ditentukan.";
    kurir[2].motor.harga = "10000";

    kurir[0].mobil.jenis_kecepatan = "Kurir Express";
    kurir[0].mobil.deskripsi_kecepatan = "Kurir yang dapat Memberikan pelayanan yang cepat dan tepat untuk pengguna.";
    kurir[0].mobil.harga = "15000";

    kurir[1].mobil.jenis_kecepatan = "Kurir Instant";
    kurir[1].mobil.deskripsi_kecepatan = "Kurir yang dapat memberikan pelayanan SATSET kepada pengguna, bisa digunakan jika kamu sedang buru-buru.";
    kurir[1].mobil.harga = "17000";

    kurir[2].mobil.jenis_kecepatan = "Kurir Santai";
    kurir[2].mobil.deskripsi_kecepatan = "Kurir yang dapat DIPESAN pada waktu yang telah ditentukan.";
    kurir[2].mobil.harga = "15000";

    jml_data = sizeof(kurir) / sizeof(kurir[0]);
    for (int i = 0; i < jml_data && !kurir[i].motor.jenis_kecepatan.empty(); i++)
    {
        indx_motor++;
    }
    for (int i = 0; i < jml_data && !kurir[i].mobil.jenis_kecepatan.empty(); i++)
    {
        indx_mobil++;
    }

    string pilihan;

    while (pilihan != "3")
    {
        cout << "" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Pengguna" << endl;
        cout << "3. Keluar" << endl;
        cout << "Masukkan pilihan anda: " << endl;
        cin >> pilihan;
        fflush (stdin);
        cout << "" << endl;

        if (pilihan == "1")
            {
                cin.ignore();
                int coba;
                coba = 0;
                while (coba < 3)
                {
                    string pass;
                    cout << "Masukkan Password: " << endl;
                    getline(cin, pass);

                    if (pass == "admin")
                        {
                            cout << "" << endl;
                            cout << "Berhasil Login!!" << endl;
                            menu_admin();
                            break;
                        }
                    else
                        {
                            cout << "Password anda salah" << endl;
                        }
                    if (coba == 2)
                        {
                            cout << "Percobaan mencapai batas maksimal. Coba lagi nanti." << endl;
                            return 0;
                        }
                        coba++;
                }    
                
                
            }
        else if (pilihan == "2")
            {
                menu_user();
            }
        else if (pilihan == "3")
            {
                cout << "Anda memilih Keluar" << endl;
                return 0;
            }
        else if (pilihan == "4")
            {
                BubbleSortNamaMotorAscending(order, jml_data);
            }
        else
            {
                cout << "Pilihan anda tidak tersedia" << endl;
            }
    }
}