/**
 * Project Untitled
 */


#include "contactInfo.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * contactInfo implementation
 */


void contactInfo::editContact(
                                string firstNew,
                                string lastNew,
                                string cellPhoneNew,
                                string localPhoneNew,
                                string _addressNew,
                                string _emailNew,
                                array relation
                                )
{
    firstName = firstNew;
    lastName = last;
    cellPhoneNumber = cellPhone;
    localPhoneNumber = localPhone;
    address = _address;
    email = _email;
    relation = relation;
}

contactInfo::contactInfo(
                             string first,
                             string last,
                             string cellPhone,
                             string localPhone,
                             string _address,
                             string _email,
                             array relation
                             )
{
    firstName = first;
    lastName = last;
    cellPhoneNumber = cellPhone;
    localPhoneNumber = localPhone;
    address = _address;
    email = _email;
    relation = relation;
}
