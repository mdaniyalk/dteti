/**
 * Project Untitled
 */


#ifndef _CONTACTINFO_H
#define _CONTACTINFO_H

#include <string>
#include <vector>

using namespace std;

class contactDetail {

public:

    void editContact();

    void setName(string first, string last);

    string getFirstName() const;
    string getLastName() const;
    string cellPhoneNumber() const;
    string localPhoneNumber() const;
    string address() const;
    string email() const;
    array relation() const;

    contactDetail();

private:
    string firstName;
    string lastName;
    string cellPhoneNumber;
    string localPhoneNumber;
    string address;
    string email;
    array relation;

};

#endif //_CONTACTINFO_H
