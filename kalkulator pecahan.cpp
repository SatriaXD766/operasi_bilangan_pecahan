#include <iostream>
#include <cmath>

using namespace std;

// Struktur data untuk menyimpan pembilang dan penyebut pecahan
struct Pecahan {
    int pembilang;
    int penyebut;
};

// Fungsi untuk mencari Faktor Persekutuan Terbesar (FPB)
int cariFPB(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Fungsi untuk menyederhanakan bentuk pecahan
void sederhanakan(Pecahan &p) {
    if (p.penyebut == 0) return;

    int fpb = cariFPB(p.pembilang, p.penyebut);
    p.pembilang /= fpb;
    p.penyebut /= fpb;

    // Memindahkan tanda negatif ke pembilang jika penyebut bernilai negatif
    if (p.penyebut < 0) {
        p.pembilang = -p.pembilang;
        p.penyebut = -p.penyebut;
    }
}

int main() {
    Pecahan p1, p2, hasil;
    char op;

    cout << "===================================\n";
    cout << "    KALKULATOR PECAHAN SEDERHANA   \n";
    cout << "===================================\n\n";

    // Input Pecahan Pertama
    cout << "Masukkan Pecahan Pertama:\n";
    cout << "  Pembilang : ";
    cin >> p1.pembilang;
    cout << "  Penyebut  : ";
    cin >> p1.penyebut;

    if (p1.penyebut == 0) {
        cout << "\n[Error] Penyebut tidak boleh bernilai 0!\n";
        return 1;
    }

    // Input Operasi Aritmatika
    cout << "\nPilih Operasi (+, -, *, /): ";
    cin >> op;

    // Input Pecahan Kedua
    cout << "\nMasukkan Pecahan Kedua:\n";
    cout << "  Pembilang : ";
    cin >> p2.pembilang;
    cout << "  Penyebut  : ";
    cin >> p2.penyebut;

    if (p2.penyebut == 0) {
        cout << "\n[Error] Penyebut tidak boleh bernilai 0!\n";
        return 1;
    }

    // Hitung berdasarkan operator
    switch (op) {
        case '+':
            hasil.pembilang = (p1.pembilang * p2.penyebut) + (p2.pembilang * p1.penyebut);
            hasil.penyebut = p1.penyebut * p2.penyebut;
            break;
        case '-':
            hasil.pembilang = (p1.pembilang * p2.penyebut) - (p2.pembilang * p1.penyebut);
            hasil.penyebut = p1.penyebut * p2.penyebut;
            break;
        case '*':
            hasil.pembilang = p1.pembilang * p2.pembilang;
            hasil.penyebut = p1.penyebut * p2.penyebut;
            break;
        case '/':
            if (p2.pembilang == 0) {
                cout << "\n[Error] Pembagian dengan pecahan bernilai 0 tidak diperbolehkan!\n";
                return 1;
            }
            hasil.pembilang = p1.pembilang * p2.penyebut;
            hasil.penyebut = p1.penyebut * p2.pembilang;
            break;
        default:
            cout << "\n[Error] Operator tidak valid!\n";
            return 1;
    }

    // Sederhanakan hasil pecahan
    sederhanakan(hasil);

    // Tampilkan Hasil
    cout << "\n===================================\n";
    cout << "HASIL: " << p1.pembilang << "/" << p1.penyebut << " " << op << " "
         << p2.pembilang << "/" << p2.penyebut << " = ";

    if (hasil.penyebut == 1) {
        cout << hasil.pembilang << "\n"; // Jika penyebut 1, tampilkan angka bulat saja
    } else if (hasil.pembilang == 0) {
        cout << "0\n";
    } else {
        cout << hasil.pembilang << "/" << hasil.penyebut << "\n";
    }
    cout << "===================================\n";

    return 0;
}