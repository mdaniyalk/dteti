#ifndef _MENU_H
#define _MENU_H

#include <string>
#include <vector>

class menu {

public:

    menu();

    void mainmenu(int imenu);

    void viewContact(contactData viewcont);

    void contactList(int cpos);

    void editContact(contactData edcont);

    void addContact();

    void importContact();

    void exportContact();

    void deleteContact(contactData delcont);

    void searchContact(string keywords);

    void sortContact();

    void exit();

    void templateCSV();

    string filename;

    int state;

    int position;

    vector <contactData> contact;

    contactData tempContact;

    int i;

    string keywords;

private:

    //void sortContact();


};

#endif //_MENU_H
