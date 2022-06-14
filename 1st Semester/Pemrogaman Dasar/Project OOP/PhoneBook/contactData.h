#ifndef _CONTACTDATA_H
#define _CONTACTDATA_H

using namespace std;

#include <string>


class contactData {
public:

    void setData();
    string firstName;
    string lastName;
    string cellPhoneNumber;
    string localPhoneNumber;
    string address;
    string email;
    string relation;


private:

    string nullinput = " ";

};

#endif //_CONTACTDATA_H
