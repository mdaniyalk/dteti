
using namespace std;
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <limits>


#include "contactData.h"



bool checknum(string a){
    int b;
    bool isnum = false;
    for (b = 0; b < a.size(); b++){
        if (!isdigit(a[b])){
            isnum = false;
            break;
        } else {
            isnum = true;
        }
    }

    return isnum;
};

void contactData::setData() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter the following details\n";
    cout << "First Name: " ;
    getline(cin, firstName);
    if (firstName.empty()){
        istringstream istr(firstName);
        istr >> nullinput;
    }
    //cin >> firstName;
    cout << "\nLast Name: ";
    getline(cin, lastName);
    if (lastName.empty()){
        istringstream istr(lastName);
        istr >> nullinput;
    }
    //cin >> lastName;
    cellPhoneNumber = "a";
    while (!checknum(cellPhoneNumber)){
        cout << "Cell Phone Number: ";
        getline(cin, cellPhoneNumber);
        if (cellPhoneNumber.empty()){
            cout << "You can't let the number empty. Please input the number. /n";
        } else if (!checknum(localPhoneNumber)){
            cout << "Your input should be a number. Please input the number. /n";
        }
    }
    //cin >> cellPhoneNumber;
    localPhoneNumber = "a";
    while (!checknum(localPhoneNumber)){
        cout << "Local Phone Number: ";
        getline(cin, localPhoneNumber);
        if (localPhoneNumber.empty()){
            istringstream istr(localPhoneNumber);
            istr >> nullinput;
        } else if (!checknum(localPhoneNumber)){
            cout << "Your input should be a number. Please input the number. /n";
        }
    }
    //cin >> localPhoneNumber;
    cout << "Address: ";
    getline(cin, address);
    if (address.empty()){
        istringstream istr(address);
        istr >> nullinput;
    }
    //cin >> address;
    cout << "E-Mail: ";
    getline(cin, email);
    if (email.empty()){
        istringstream istr(email);
        istr >> nullinput;
    }
    //cin >> email;
    cout << "Relation: ";
    getline(cin, relation);
    if (relation.empty()){
        istringstream istr(relation);
        istr >> nullinput;
    }
    //cin >> relation;
};



