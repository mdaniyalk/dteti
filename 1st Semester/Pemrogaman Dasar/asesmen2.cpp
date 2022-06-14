#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    float volume, radius, tinggi;
    string bentuk;
    cout << "Masukkan nilai radius : ";
    cin >> radius;
    cout << "Masukkan nilai tinggi : ";
    cin >> tinggi;
    cout << "Masukkan bentuk (kerucut atau tabung) : ";
    cin >> bentuk;
    
    if (bentuk == "kerucut" || bentuk == "Kerucut" || bentuk == "KERUCUT")
    {
        volume = radius * radius * M_PI * tinggi / 3;
    } else 
    {
        volume = radius * radius * M_PI * tinggi;
    }
    cout << "Volume bangun ruang " << bentuk << " anda adalah " << volume;

    return 0;
}
