#include "contactData.h"
#include "menu.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

//vector <contactData> contact;
//int current = 0;
//contactData tempContact;

bool compare(contactData c1, contactData c2){
    return (c1.firstName < c2.firstName);
}

menu menuC;
int i;

void init(){
    fstream file ("Data Contact.csv", ios::in);
    string temp[7];
    string word, line;
    if(file.is_open()) {
        int j = 0;
        while(getline(file, line))
		{

			stringstream str(line);
			i = 0;
			while(getline(str, word, ',')&&i < 7){
                if (i == 0 && j == 0){
                    word.erase(word.begin(), word.begin() + 3);
                }
				temp[i] = word;
                if (i == 0){
                    menuC.tempContact.firstName = temp[i];
                } else if (i == 1){
                    menuC.tempContact.lastName = temp[i];
                } else if (i == 2){
                    menuC.tempContact.cellPhoneNumber = temp[i];
                } else if (i == 3){
                    menuC.tempContact.localPhoneNumber = temp[i];
                } else if (i == 4){
                    menuC.tempContact.address = temp[i];
                } else if (i == 5){
                    menuC.tempContact.email = temp[i];
                } else if (i == 6){
                    menuC.tempContact.relation = temp[i];
                }
                i++;
			}
			menuC.contact.push_back(menuC.tempContact);
			j++;
		}
        //cout << "Showing your Contact List from 1-20.\n";
        menuC.sortContact();
        //int i = current;
        i = 0;
        //cout << "Menampilkan daftar kontak yang anda miliki.\n";
        menuC.contactList(i);
        //while(i < contact.size() ) {
        //    cout << "Name: " << contact[i].firstName << " " << contact[i].lastName << endl;
        //    cout << "Cell Phone Number: " << contact[i].cellPhoneNumber << endl;
        //    i++;
        //}
        cout << "\n To continue, please choose one of the menu listed bellow.";

    } else {
        cout << "Seems like you didn't have any contact on this app.\n Please add your first contact by filling the form bellow.";
        menuC.addContact();
    }
};

int main(){
    //init();
    menuC;
}
