# Kalkulator Pecahan C++

Program untuk menghitung penjumlahan, pengurangan, perkalian, dan pembagian pecahan dengan penyederhanaan otomatis pakai FPB.

## Struktur Kode
- `struct Pecahan { int pembilang; int penyebut; };`
- `cariFPB(a,b)` pakai algoritma Euclidean untuk menyederhanakan hasil.

## Cara Jalan
g++ "kalkulator pecahan.cpp" -o kalkulator
./kalkulator

## Contoh
Input: 1/2 + 1/3
Output: 5/6
