#include <iostream>

using namespace std;

int main()
{
    int n, val, sum = 0;
    float fahrenheit;
    cout<<"Enter  n (the number of even numbers): ";
    cin>>n;
    cout<<"\n| Value |  Sum  |";
    cout<<"\n|-------|-------|";
    for(int i = 1; i<=n; i++){
        val = i*2;
        sum += val;
        cout<<"\n|   " <<val<<"   |   "<<sum<<"   |";
        cout<<"\n|-------|-------|";
        
    }
    return 0;
}
