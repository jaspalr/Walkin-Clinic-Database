/*
 * List.cpp
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - Value-oriented list
 * 					 - Postion starts at 0
 * 					 - Dynamically Allocated 
 *
 * Author: Jaspal Raman
 * Date: Feb 4,2022
 */

#include <iostream>
#include <string>
#include "Patient.h"
#include "List.h"

using namespace std;
// Constructor
List::List(): elementCount(0){}

// Destructor
List::~List(){
    this->removeAll();
}

// Description: Returns the current numbers of elements in the List
int List::getElementCount() const {
    return elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and elementCount has been incremented. If elementCount == Max_ElEMENTS the function returns false and 
// doesn't add the element.
bool List::insert(const Patient& newElement){
    bool ableToInsert;
    if(elementCount == 0){ // zero case 
        elements = new Patient[INITIAL_CAPACITY];
        if(elements == NULL){
            ableToInsert = false;
            
            return ableToInsert;
        }
        capacity = INITIAL_CAPACITY;
        elements[0] = newElement;
        elementCount++;

        ableToInsert = true;
        return ableToInsert;
    }

    for(int i = 0; i < elementCount; i++){
        if(elements[i].operator==(newElement)){//checks if element is already in the List, if so returns false.
            ableToInsert = false;              // otherwise true
             return ableToInsert;
        }
    }

    if(elementCount == capacity){                                     //if array size equals capacity. Array size is increased by capacity + 
        Patient* temp = new Patient[capacity+INITIAL_CAPACITY];       // INITIAL_CAPACITY 
        if(temp == NULL){
            ableToInsert = false;
            return ableToInsert;
        }
        capacity = capacity + INITIAL_CAPACITY;
        for(int i = 0; i < elementCount; i++){
            temp[i] = elements[i];
        }
        delete[] elements;
            elements = NULL;
        elements = temp;
    }

    bool lessthan = false;
    int index = 0;
    while(!lessthan && index < elementCount){ //finds the index to insert the element
        if(elements[index].operator<(newElement)){
            lessthan = true;
        }
        else{
            index++;
        }
    }

    for(int i = elementCount; i > index  ; i--){
        elements[i] = elements[i - 1];
    }
        

    elements[index] = newElement;
    elementCount++;
    ableToInsert = true;
    return ableToInsert;
        
    
}

//Description: Removes an element in the list
//Postcondition: If element is in the list removes that and shifts other elements down one
bool List::remove( const Patient& toBeRemoved ){
    bool ableToRemove = false;
    int index = 0;
    while (!ableToRemove && index < elementCount){ 
        if(elements[index].getCareCard() == toBeRemoved.getCareCard()){
            ableToRemove = true;
        }
        else {index++;}
    }

    if(ableToRemove == true){ 
        if(elementCount==1){//one element case
            removeAll();
        }

        else{
            for(int from = index + 1 , to = from -1; from < elementCount;from++,to++){
                elements[to] = elements[from];
            }
            elementCount --;
  
        }

    }
    return ableToRemove;
}

//Description: Deletes the list and frees the memory used
//Postcondition: Memory used by the List is free and elementCount is zero.
void List::removeAll(){ 
    delete[] elements;
        elements = NULL;
    elementCount = 0;
}

//Description: Searchs for an element in the list
//Postconditon: Returns a pointer to the element if the list otherwise return a NULL
Patient* List::search(const Patient& target){
    bool found = false;
    int index = 0;
    while(!found && index < elementCount){
        if(elements[index].operator==(target)){
            found = true;

            return (elements + index);
        }
        else{
            index++;
        }

    }
    return NULL;
}

//Description: Prints the elements in the list
void List::printList(){
    if(elementCount == 0){
        cout << "No patients" << endl;
    }
    for(int i = 0; i < elementCount; i++){
        cout << elements[i];
    }
}
