/*
* walkIn.cpp
* 
* Created Feburay 4, 2022
* Author Jaspal Raman
*/


#include <iostream>
#include <string>
#include "List.h"
#include "Patient.h"



//Description: Helper function used in modify and search. Searches the List using Carecard numbers for the function 
//returns the a pointer to that element or returns a Null if not in the list.
Patient* searchhelper(List* themembers){
    string card = "";

    cout << "Enter the Patients Carecard" << endl;
    cin >> card;
    Patient thePatient(card);
    Patient* findPatient = themembers->search(thePatient);
    return findPatient;
}


//enter a new patient into the system
void add(List* themembers){
    string card = "";
    string name = "";
    string address = "";
    string number = "";
    string email = "";
    cout << "Enter Carecard" << endl;
    cin >> card;
    Patient thePatient(card);
    
    if(thePatient.getCareCard() == "0000000000"){ //checks if vaild care card. If so contines otherwise ends the program and tells the user
        cout << "Invaild Carecard. Try again" << endl;
    }
    else{
        if(themembers->insert(thePatient)){
            
            Patient* patient = themembers->search(thePatient);
            cout << "Enter name" <<endl;
            cin >> name;
            patient->setName(name); // Each Patient as a name and address, phone number and email are optoinal. If no phone number or email 
            cout << "Enter Address" << endl; // value is NA and receptionist should comply 
            cin >> address;  
            patient->setAddress(address);
            cout << "Enter Phone Number" << endl;
            cin >> number;
            patient->setPhone(number);
            cout << "Enter Email" << endl;
            cin >> email;
            patient->setEmail(email);
            
            cout<< "Patient added to the system" << endl;

        }
        else{
            cout << "Unable to add  Patient. Check if Patient is already in the system." <<endl;
        }
    }
}

//remove a patient from the system
void remove(List* themembers){
    string card = "";

    cout << "Enter the Patients CareCard" << endl;
    cin >> card;
    Patient Patienttoremove(card);
    if(themembers->remove(Patienttoremove)){
        cout << "Patient removed" << endl;
        return;
    }
    else {
        cout << "Patient can't be removed" << endl;
        return;
        }
}

//search for an existing patient

void search(List* themembers){
    Patient* findPatient = searchhelper(themembers); // searchhelper define at the top
    if(findPatient ==NULL){
       cout <<"Patient not in the system" << endl;
    }
    else{
        cout << *findPatient;
    }
}

//modify a patient's record (for example, adding the patient's information or making a change of address, etc...).
void modify(List* themembers){
    char funinput = 0;
    bool done = false;
    string update;
    Patient* findPatient = searchhelper(themembers);//searchhelper define at the top
    if(findPatient == NULL){
       cout <<"Patient not in the system" << endl;
    }
    else{
        while (!done){//asks the user what field to modify. 6 ends the while loop
            cout << "To edit name press 1" << endl;
            cout << "To edit address press 2" << endl;
            cout << "To edit phone number press 3" << endl;
            cout << "To edit email press 4" << endl;
            cout << "To see changes press 5" << endl;
            cout << "If done press 6" << endl;
            cin >> funinput;

            switch (funinput){
                case '1' : cout<< "Enter new name" << endl;
                cin>>update;
                findPatient->setName(update);
                break;
                case '2' : cout<< "Enter new address" << endl;
                cin>>update;
                findPatient->setAddress(update);
                break;
                case '3': cout<< "Enter new phone number" <<endl;
                cin>>update;
                findPatient->setPhone(update);
                break;
                case '4' : cout<< "Enter new email" << endl;;
                cin>>update;
                findPatient->setEmail(update);
                break;
                case '5': cout << *findPatient;break;
                case '6': done = true; break;
                default: cout << "repeat input" << endl;
            }
        }
    }
}

//print all its patients by descending order of care card numbers.
void print(List* themembers){
    themembers->printList();
}

int main(){
    List* members = new List();
    bool done = false;
    char input;

    while (!done){
        cout << "Press 1 to add Patient" << endl;
        cout << "Press 2 to remove Patient" << endl;
        cout << "Press 3 to search for Patient" << endl;
        cout << "Press 4 to modify Patient" << endl;
        cout << "Press 5 to print Patients" << endl;
        cout << "Press x to exit" << endl;
        cout << "Your choice ";
        cin >> input;
        switch (input){
            case '1': add(members); break;
            case '2' : remove(members); break;
            case '3' : search(members);break;
            case '4': modify(members);break;
            case '5': print(members);break;
            case 'x' : cout << "Bye" << endl; done = true; break;
            default: cout << "repeat input" << endl;
        }
            
    }

    delete members;
    return 0;
 
}