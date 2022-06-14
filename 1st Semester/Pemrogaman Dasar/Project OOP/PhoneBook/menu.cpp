#include "contactData.h"
#include "menu.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;


int current = 0;

bool compareSort(contactData c1, contactData c2){ //parameter for sorting algs
    if (c1.firstName != c2.firstName) {
        return (c1.firstName < c2.firstName);
    } else {
        if (c1.lastName != c2.lastName) {
            return (c1.lastName < c2.lastName);
        } else {
            return (c1.cellPhoneNumber < c2.cellPhoneNumber);

        }
    }
};

int binarysearch(string arr[], string x, int n){ //binary search algs. comparing using the sub string
    int l = 0 ;
    int r = n - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;

    int res = -1000;
    size_t found = arr[m].find(x);
    if (found != string::npos)
        res = 0;
        if (res == 0)
            return m;
        if (x > (arr[m]))
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
};

menu::menu(){
    //init();
    cout << "Welcome to the PhoneBook App.\n\n";
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
                    tempContact.firstName = temp[i];
                } else if (i == 1){
                    tempContact.lastName = temp[i];
                } else if (i == 2){
                    tempContact.cellPhoneNumber = temp[i];
                } else if (i == 3){
                    tempContact.localPhoneNumber = temp[i];
                } else if (i == 4){
                    tempContact.address = temp[i];
                } else if (i == 5){
                    tempContact.email = temp[i];
                } else if (i == 6){
                    tempContact.relation = temp[i];
                }
                i++;
			}
			contact.push_back(tempContact);
			j++;
		}
        sortContact();
    } else {
        cout << "Seems like you didn't have any contact on this app.\n";
    }
    mainmenu(current);
};

void menu::mainmenu(int imenu){
    i = imenu;
    cout << "You have " << contact.size() << " contact";
    if (contact.size() > 1){
        cout << "s listed bellow.\n\n";
        contactList(i);
        cout << "\n To continue, please choose one of the menu listed bellow.";
    } else if (contact.size() == 1) {
        cout <<" listed bellow.\n\n";
        contactList(i);
        cout << "\n To continue, please choose one of the menu listed bellow.";
    }
    if(contact.size() == 0) {
        cout << "Seems like you didn't have any contact on this app.\n";
        cout << "\n To continue, please choose one of the menu listed bellow.";
    }
    cout << "\n--------------------\n";
    cout << "1. View Contact Detail\n";
    cout << "2. Add Contact\n";
    cout << "3. Import Contact\n";
    cout << "4. Search Contact\n";
    cout << "5. Delete Contact\n";
    cout << "6. Export Contact\n";
    if (contact.size()>20){
        cout << "7. Next Contact List\n";
        cout << "8. Previous Contact List\n";
        cout << "9. Last Page of Contact List\n";
        cout << "0. First Page of  Contact List\n";
    }
    cout << "99. Exit";
    cout << "\n--------------------\n";
    cout << "Please input the menu number : ";
    cin >> state;
    int maxtry = 0;
    while (state < 0 && state > 9 && state != 99){
        cout << "\nUndefined input.\nPlease type your input again: ";
        cin >> state;
        maxtry++;
        if (maxtry >= 5){
            system("cls");
            cout << "Your type the wrong input 5 times.\n";
            cout << "The program will be close immediately";
            exit();
        }
    }
    if (state == 1){
        int cdet;
        if (contact.size() > 1 ){
            cout << "\nTo view contact detail. Please choose the index from the contact listed above from ";
            cout << i+1 << " to ";
            if(i+20 <= contact.size()){
                cout << (i+20);
            } else {
                cout << contact.size();
            }
            cout << ": ";
            cin >> cdet;
            cdet = cdet - 1;
        } else if (contact.size() == 0){
            system("cls");
            cout << "Seems like you didn't have any contact on this app. You need to add your first contact.\n";
            cout << "Choose one of the menu bellow";
            cout << "1. Add Contact";
            cout << "2. Import Contact";
            cout << "0. Back to main menu";
            int cdet;
            cin >> cdet;
            if (cdet == 1){
                addContact();
            } else if (cdet == 2){
                system("cls");
                importContact();
            } else if (cdet == 0){
                system ("cls");
                menu();
            } else {
                cout << "Undefined input. Forcing back to the main menu.\nPress enter to continue!\n";
                system("pause");
                system ("cls");
                menu();
            }
        } else {
            cdet = 0;
        }
        system("cls");
        viewContact(contact[cdet]);
    } else if (state == 2){
        addContact();
    } else if (state == 3){
        system("cls");
        importContact();
        //cout << "import";
        //system("pause");
    } else if (state == 4){
        system("cls");
        string key;
        cout << "Input your search keywords: ";
        cin >> key;
        searchContact(key);
        //cout << "search";
        //system("pause");
    } else if (state == 5){
        //system("cls");
        //deleteContact();
        int cdet;
        if (contact.size() >= 1 ){
            cout << "\nTo delete the contact. Please choose the index from the contact listed above from ";
            cout << i+1 << " to ";
            if(i+20 <= contact.size()){
                cout << (i+20);
            } else {
                cout << contact.size();
            }
            cout << ": ";
            cin >> cdet;
            cdet = cdet - 1;
        deleteContact(contact[cdet]);
        } else if (contact.size() == 0){
            system("cls");
            cout << "Seems like you didn't have any contact on this app. You need to add your first contact.\n";
            cout << "Choose one of the menu bellow";
            cout << "1. Add Contact";
            cout << "2. Import Contact";
            cout << "0. Back to main menu";
            int cdet;
            cin >> cdet;
            if (cdet == 1){
                addContact();
            } else if (cdet == 2){
                system("cls");
                importContact();
            } else if (cdet == 0){
                system ("cls");
                menu();
            } else {
                cout << "Undefined input. Forcing back to the main menu.\nPress enter to continue!\n";
                system("pause");
                system ("cls");
                menu();
            }
        }
    } else if (state == 6){
        system("cls");
        cout << "Please input your output file name: ";
        cin >> filename;
        exportContact();
        cout << "Export finished. Press enter to continue to main menu!\n";
        system("pause");
        system("cls");
        menu();
    } else if (state == 7){
        //next list
        int maxpage = contact.size() - (contact.size()%20);
        if (maxpage == contact.size()){
            maxpage = maxpage-20;
        }
        if (contact.size() > 20 && current < maxpage) {
            current = i + 20;
            system("cls");
            menu();
        } else {
            cout << "You're reaching the last page of your contact list.\n Press enter to back to menu.";
            system("pause");
            system("cls");
            menu();
        }
    } else if (state == 8){
        //previous list
        int firstpage = 1;
        if (contact.size() > 20 && current > firstpage+19) {
            current = i - 20;
            system("cls");
            menu();
        } else {
            cout << "You're reaching the first page of your contact list.\n Press enter to back to menu.";
            system("pause");
            system("cls");
            menu();
        }
    } else if (state == 9){
        //last page list
        int lastpage = contact.size() - (contact.size()%20);
        if (lastpage == contact.size()){
            lastpage = lastpage-20;
        }
        if (contact.size() > 20 && current < lastpage) {
            current = lastpage;
            system("cls");
            menu();
        } else {
            cout << "You're reaching the last page of your contact list.\n Press enter to back to menu.";
            system("pause");
            system("cls");
            menu();
        }
    } else if (state == 0){
        //first page list
        int firstpage = 1;
        if (contact.size() > 20 && current > firstpage+19) {
            current = firstpage-1;
            system("cls");
            menu();
        } else {
            cout << "You're reaching the first page of your contact list.\n Press enter to back to menu.";
            system("pause");
            system("cls");
            menu();
        }
    } else if (state == 99){
        exit();
    }
};

void menu::viewContact(contactData viewcont){
    // Viewing Contact Detail
    cout << "Displaying Contact Detail\n";
    cout << "Name: " << viewcont.firstName << " " << viewcont.lastName << endl;
    cout << "Cell Phone Number: " << viewcont.cellPhoneNumber << endl;
    cout << "Local Phone Number: " << viewcont.localPhoneNumber << endl;
    cout << "Address: " << viewcont.address << endl;
    cout << "E-Mail: " << viewcont.email << endl;
    cout << "Relations: " << viewcont.relation << endl;

    //diplaying sub menu inside contact detail menu.
    int vcmenu;
    cout << "Choose the options bellow: \n";
    cout << "1. Edit contact\n";
    cout << "2. Delete contact\n";
    cout << "0. Back to main menu\n";
    cin >> vcmenu;
    if (vcmenu == 1){
        editContact(viewcont);
    } else if (vcmenu == 2){
        cout << "Are you sure to delete this contact? (Y/N)\n";
        string isdelete;
        cin >> isdelete;
        if (isdelete == "Y" || isdelete == "y"){
            cout <<"Deleting your contact.\n";
            deleteContact(viewcont);
        } else if (isdelete == "N" || isdelete == "n"){
            cout << "Choose the options bellow: \n";
            cout << "1. Edit contact\n";
            cout << "0. Back to main menu\n";
            cin >> vcmenu;
            if (vcmenu == 1){
                editContact(viewcont);
            } else if (vcmenu != 1 && vcmenu != 0){
                cout << "Wrong input. Forcing back to main menu.\n";
            }
            system("cls");
            menu();
        }
    }else if (vcmenu > 2 && vcmenu < 0){
        cout << "Wrong input. Forcing back to main menu.\n";
    }
    system("cls");
    menu();
};

void menu::contactList(int cpos){
    // Showing all contact list (max 20 line) with just name and number info)
    int k = cpos;
    int endd;
    if (contact.size() >= k+20){
        endd = k+20;
    } else {
        endd = contact.size();
    }
    cout << "Showing Your Contact List from " << k+1 << "-" << endd << endl;
    while(k < endd && k < contact.size() ) {
        cout << k+1 << ".";
        if (k>=100)
            cout << " ";
        else if (k < 10){
            cout << "   ";
        } else if (k >= 10 && k < 100) {
            cout << "  ";
        }
        cout << "Name: " << contact[k].firstName << " " << contact[k].lastName << endl;
        cout << "     " << "Cell Phone Number: " << contact[k].cellPhoneNumber << endl << endl;
        k++;
    }
};


void menu::editContact(contactData edcont){
    // Edit the contact. call the set contact info by choosing the right index
    system("cls");
    cout << "You're editing your contact.\n";
    contactData beforeedit = edcont; //new variable to store old data
    edcont.setData();
    contact.push_back(edcont); // store new data

    //delete old data
    int sizearr = contact.size();
    string arr1[sizearr];
    string arr2[sizearr];
    for (int it = 0; it < sizearr; it++){
        arr1[it] = contact[it].firstName;
    }
    vector <contactData> searchresult;
    int spos = -2;
    int sres = 0;
    while (spos != -1){
        spos = binarysearch(arr1, beforeedit.firstName, sizearr);
        if (spos != -1){
            searchresult.push_back(contact[spos]);
            for (int it = spos; it < sizearr; it++){
                arr1[it] = arr1[it+1];
            }
            sizearr--;
        }
    }
    sort(searchresult.begin(), searchresult.end(), compareSort);
    for (int it = 0; it < contact.size(); it++){
        for (int ik = 0; ik < searchresult.size(); ik++){
            if (contact[it].firstName == searchresult[ik].firstName &&
                 contact[it].lastName == searchresult[ik].lastName &&
                 contact[it].cellPhoneNumber == searchresult[ik].cellPhoneNumber &&
                 contact[it].localPhoneNumber == searchresult[ik].localPhoneNumber &&
                 contact[it].email == searchresult[ik].email &&
                 contact[it].relation == searchresult[ik].relation
                 ){
                contact.erase(contact.begin()+it);
                break;
            }
        }
    }
    exportContact(); // exporting data and also to save it

    //sub menu from edit contact.
    int vcmenu;
    cout << "Choose the options bellow: \n";
    cout << "1. View contact detail\n";
    cout << "0. Back to main menu\n";
    cin >> vcmenu;
    if (vcmenu == 1){
        viewContact(edcont);
    }else if (vcmenu != 1 && vcmenu != 0){
        cout << "Wrong input. Forcing back to main menu.\n";
    }
    system("cls");
    menu();

};

void menu::addContact(){
    // Add new contact by calling set contact and store in index
    if (contact.size() < 1000){
        cout << "You're adding your contact.\n";
        tempContact.setData(); //saving contact in temp variable
        contact.push_back(tempContact); //saving to vector variable

        // save inside the main csv
        ofstream addtofile;
        addtofile.open("Data Contact.csv", ofstream::app);
            addtofile << tempContact.firstName << "," << tempContact.lastName << "," ;
            addtofile << tempContact.cellPhoneNumber << "," << tempContact.localPhoneNumber << "," ;
            addtofile << tempContact.address << "," << tempContact.email << "," ;
            addtofile << tempContact.relation<<endl;
        system("cls");
        cout << "Successfully added your contact. Here is the contact detail.\n";
        //showing contact detail
        viewContact(contact[contact.size() - 1]);
    } else {
        system("cls");
        cout << "Your contact already reach the limit of 1000 contacts.\n";
        cout << "Delete a contact to add new contact.\n";
        cout << "Going back to main menu.\n";
        cout << "Press enter to continue.\n";
        system("pause");
        system("cls");
        menu();
    }

};

void menu::importContact(){
    // Import contact from csv file.
    // maybe still unused because the algs seem not finished
    cout << "Importing your contact using CSV file.\n";
    cout << "Do you want to use the template? (Y/N)\n";
    string istempl;
    cin >> istempl;
    if (istempl == "Y" || istempl == "y"){
        templateCSV();
        cout << "Please check your program directories to find the template CSV file.\n";
        cout << "Don't use the header otherwise it will be error.\n";
    }
    if (contact.size()<1000){
        fstream file;
        string filepath;
        cout << "What is your file name (without .csv extension)? \n";
        cout << "(Attention! Case Sensitive input. Otherwise it will be error)\n";
        cin >> filepath;
        filepath = filepath + ".csv";
        file.open(filepath);
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
                        tempContact.firstName = temp[i];
                    } else if (i == 1){
                        tempContact.lastName = temp[i];
                    } else if (i == 2){
                        tempContact.cellPhoneNumber = temp[i];
                    } else if (i == 3){
                        tempContact.localPhoneNumber = temp[i];
                    } else if (i == 4){
                        tempContact.address = temp[i];
                    } else if (i == 5){
                        tempContact.email = temp[i];
                    } else if (i == 6){
                        tempContact.relation = temp[i];
                    }
                    i++;
                }
                contact.push_back(tempContact);
                j++;
            }
            sortContact();
        }
        system("cls");
        exportContact();
        cout << "Import Finished. Going back to main menu.\n";
        cout << "Press enter to continue.\n";
        system("pause");
        system("cls");
        menu();
    } else {
        cout << "Your contact already reach the limit of 1000 contacts.\n";
        cout << "Delete some contacts to add new contact.\n";
        cout << "Going back to main menu.\n";
        cout << "Press enter to continue.\n";
        system("pause");
        system("cls");
        menu();
    }
};

void menu::exportContact(){
    // Export contact to csv file.
    if (filename == "") { //used for null execption
        filename = "Data Contact";
    }
    filename = filename + ".csv";
    ofstream exprt;
    exprt.open(filename);
        for (i = 0; i < contact.size(); i++){
            exprt << contact[i].firstName << "," << contact[i].lastName << "," ;
            exprt << contact[i].cellPhoneNumber << "," << contact[i].localPhoneNumber << "," ;
            exprt << contact[i].address << "," << contact[i].email << "," ;
            exprt << contact[i].relation<<endl;
        }

};

void menu::deleteContact(contactData delcont){
    // removing the contact index and its value
    //search the given contact data
    int sizearr = contact.size();
    string arr1[sizearr];
    string arr2[sizearr];
    for (int it = 0; it < sizearr; it++){
        arr1[it] = contact[it].firstName;
    }
    vector <contactData> searchresult;
    int spos = -2;
    int sres = 0;
    while (spos != -1){
        spos = binarysearch(arr1, delcont.firstName, sizearr);
        if (spos != -1){
            searchresult.push_back(contact[spos]);
            for (int it = spos; it < sizearr; it++){
                arr1[it] = arr1[it+1];
            }
            sizearr--;
        }
    }
    sort(searchresult.begin(), searchresult.end(), compareSort);
    for (int it = 0; it < contact.size(); it++){
        for (int ik = 0; ik < searchresult.size(); ik++){
            if (contact[it].firstName == searchresult[ik].firstName &&
                 contact[it].lastName == searchresult[ik].lastName &&
                 contact[it].cellPhoneNumber == searchresult[ik].cellPhoneNumber &&
                 contact[it].localPhoneNumber == searchresult[ik].localPhoneNumber &&
                 contact[it].email == searchresult[ik].email &&
                 contact[it].relation == searchresult[ik].relation
                 ){
                contact.erase(contact.begin()+it); //delete the contact data
                break;
            }
        }
    }
    exportContact(); // exporting data and also to save it
    system("cls");
    cout << "Delete contact successfully.\nPress enter to continue to main menu!";
    system("pause");
    system("cls");
    menu();
};


void menu::sortContact(){
    //sorting algorithm using stl
    sort(contact.begin(), contact.end(), compareSort);
};

void menu::searchContact(string keywords){
    //search algorithm using binary search
    int sizearr = contact.size();
    string arr1[sizearr]; //array to store the first name parameter
    string arr2[sizearr]; //array to store the last name parameter
    for (int it = 0; it < sizearr; it++){ //initialize the first name from vector
        arr1[it] = contact[it].firstName;
    }
    for (int it = 0; it < sizearr; it++){ //initialize the last name from vector
        arr2[it] = contact[it].lastName;
    }
    vector <contactData> searchresult; //vector to store the search result from first name and last name parameter
    int spos = -2;
    int sres = 0;
    while (spos != -1){
        spos = binarysearch(arr1, keywords, sizearr); //calling binary search algs
        if (spos != -1){
            searchresult.push_back(contact[spos]);
            for (int it = spos; it < sizearr; it++){
                arr1[it] = arr1[it+1];
            }
            sizearr--;
        }
    }
    spos = -2;
    sizearr = contact.size();
    while (spos != -1){
        spos = binarysearch(arr2, keywords, sizearr); //calling binary search algs (2)
        if (spos != -1){
            searchresult.push_back(contact[spos]);
            for (int it = spos; it < sizearr; it++){
                arr2[it] = arr2[it+1];
            }
            sizearr--;
        }
    }
    vector <contactData> searchresult2; //vector to store the search result without same object
    //for-loop to find and merge the same object
    for (int it = 0; it < searchresult.size(); it++){
        if (it > 0 &&
            (searchresult[it].firstName != searchresult[it - 1].firstName ||
             searchresult[it].lastName != searchresult[it - 1].lastName ||
             searchresult[it].cellPhoneNumber != searchresult[it - 1].cellPhoneNumber ||
             searchresult[it].localPhoneNumber != searchresult[it - 1].localPhoneNumber ||
             searchresult[it].email != searchresult[it - 1].email ||
             searchresult[it].relation != searchresult[it - 1].relation
             )){
            searchresult2.push_back(searchresult[it]);
        } else if (it == 0) {
            searchresult2.push_back(searchresult[it]);
        }
    }
    searchresult.clear(); //deleting the unused vector
    sort(searchresult2.begin(), searchresult2.end(), compareSort); //sorting the vector result

    //displaying the result
    if (searchresult2.size() != 0){
        cout << "We found " << searchresult2.size() << " contact";
        if (searchresult2.size() > 1){
            cout << "s";
        }
        cout << " that match your keywords!\n";
        for (int it = 0; it < searchresult2.size(); it++){
            cout << "Name: " << searchresult2[it].firstName << " " << searchresult2[it].lastName << endl;
            cout << "Cell Phone Number: " << searchresult2[it].cellPhoneNumber << endl << endl;
        }
        cout << "Do you want to see the contact detail? (Y/N): "; //sub menu
        string isdetail;
        cin >> isdetail;
        if (isdetail == "Y" || isdetail == "y"){
            int cdet;
            if (searchresult2.size() > 1 ){
                cout << "\nPlease select the index from the search result from 1 to " << searchresult2.size();
                cin >> cdet;
                cdet = cdet - 1;
            } else {
                cdet = 0;
            }
            viewContact(searchresult2[cdet]);
        } else if (isdetail == "N" || isdetail == "n"){
            cout << "\nChoose the options bellow: \n"; //another sub menu
            cout << "1. Search another contact\n";
            cout << "2. Back to main menu\n";
            int smenu = 0;
            while (smenu != 1 && smenu != 2){ //while exception for input
                cin >> smenu;
                if (smenu == 1){
                    system("cls");
                    string key;
                    cout << "Input your keywords: ";
                    cin >> key;
                    searchContact(key);
                } else if (smenu == 2) {
                    menu();
                } else {
                    cout << "Undefined input. Forcing back to main menu.\n";
                    menu();
                }
            }
        }
    } else {
        cout << "Sorry, we can't find the contact that match your keywords.\n"; //another sub menu
        cout << "Choose the options bellow: \n";
        cout << "1. Search another contact\n";
        cout << "2. Back to main menu\n";
        int smenu = 0;
        while (smenu != 1 && smenu != 2){
            cin >> smenu;
            if (smenu == 1){
                system("cls");
                string key;
                cout << "Input your keywords: ";
                cin >> key;
                searchContact(key);
            } else if (smenu == 2) {
                menu();
            } else {
                cout << "Undefined input. Forcing back to main menu.\n";
                menu();
            }
        }
    }



};


void menu::templateCSV(){
    //template for csv for user. still unused
    ofstream templatecsv;
    templatecsv.open("template.csv");
    templatecsv << "firstName,lastName,cellPhoneNumber,";
    templatecsv << "localPhoneNumber,address,email,relation" << endl;
};

void menu::exit(){
    //exit menu.
    cout << "Do you want to exit? (Y/N)";
    string isexit;
    cin >> isexit;
    if (isexit == "Y" || isexit == "y"){
        exportContact();
    } else if (isexit == "N" || isexit == "n"){
        system("cls");
        menu();
    }
};


