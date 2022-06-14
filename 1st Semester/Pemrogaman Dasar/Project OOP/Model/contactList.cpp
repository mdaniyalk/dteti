/**
 * Project Untitled
 */


#include "contactList.h"
#include <string>
#include <vector>

using namespace std;

/**
 * contactList implementation
 */
int Count = 0;
int current = 0;
vector <contactInfo> listContact;

contactInfo info;


void contactList::addContact(contactInfo contact) {
    listContact.push_back(contact);
    Count++;
    current = Count;
}

void contactList::contactDetail(contactInfo inf)
{
    cout << "Name: " << inf.firstName << " " << inf.lastName << endl;
    cout << "Cell Phone Number: " << inf.cellPhoneNumber << endl;
    cout << "Local Phone Number: " << inf.localPhoneNumber << endl;
    cout << "Address: " << inf.address << endl;
    cout << "Email: " << inf.email << endl;
    cout << "Relation: " << inf.relation << endl;
}

void contactList::navigateContact() {
    int temp;
    cout << "Choose the options" << endl;
    cout << "1. Previous contact" << end;
    cout << "2. Current contact" << endl;
    cout << "3. Next contact" << end;
    cout << "Input the number choosen: ";
    cin >> temp;

    if (temp == 1) {
        if (current =< 0){
            cout << "You're at the first contact on your list" << endl;
        } else {
            current--;
        }
    } else if (temp == 3) {
        current++;
    }
    info = listContact[current];
    contactList::contactDetail(info);



}

void contactList::deleteContact() {

}

void contactList::exportContact() {

}
/**
 * Class1 implementation
 */
