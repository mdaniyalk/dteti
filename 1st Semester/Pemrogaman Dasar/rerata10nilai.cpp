#include <iostream>

using namespace std;

int main()
{
    int num, sum = 0;
    float avg;
    cout<<"Masukkan nilai : ";
    for (int i=0; i<10; i++){
        num = 0;
        cin>> num;
        sum += num;
    }
    avg = sum/10;
    cout <<"Rata-rata dari 10 nilai yang diinputkan adalah " << avg;
}