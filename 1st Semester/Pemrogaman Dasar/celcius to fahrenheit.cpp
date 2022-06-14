#include <iostream>

using namespace std;

int main()
{
    int celcius = 0;
    float fahrenheit;
    cout<<"Konversi Suhu dari 0-105 derajat Celsius ke Fahrenheit";
    cout<<"\n|  C  |  F  |";
    cout<<"\n|-----|-----|";
    for(int i = 0; i<=7; i++){
        fahrenheit = (celcius*9/5) + 32;
        cout<<"\n|  " <<celcius<<"  |  "<<fahrenheit<<"  |";
        cout<<"\n|-----|-----|";
        celcius += 15;
    }
    return 0;
}
