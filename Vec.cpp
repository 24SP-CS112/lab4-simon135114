 /* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Simon Lin, Ben Li
 * Date:2/13/2014
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */
#include <iostream>
#include <string>
#include "Vec.h"

using namespace std;

//default.
Vec::Vec() {
    mySize = 0;
    myArray = nullptr;
}

//Destrctor
Vec::~Vec() {
    delete [] myArray;
    myArray = nullptr;
    mySize = 0;
}



// constructors
Vec::Vec(unsigned size) {
    mySize = size;
    if (size > 0) {
        myArray = new Item[size];
        for (unsigned int i = 0; i < size; i++){
            myArray[i] = 0;
        }
    }
    else {myArray = nullptr;}
}

Vec::Vec(const Vec& original) {
    if (original.mySize > 0) {
        myArray = new Item[original.mySize];
        for (unsigned int i = 0; i < original.mySize; i++){
            myArray[i] = original.myArray[i];
            
        }
    }
    else {myArray = nullptr;}
    mySize = original.mySize;
}

//getter
Item Vec::getItem(unsigned index) const {
    if (index < 0 || index >= mySize) {
     	throw range_error("Bad index");
	}
	return myArray[index];

   	}

unsigned Vec::getSize() const{
    return mySize;
}

//setter
void Vec::setItem(unsigned index, const Item& it) {
    if (index < 0 || index >= mySize) {
    	throw range_error("Bad index");
	}
	myArray[index] = it;

   	}

void Vec::setSize(unsigned newSize) {
    if (mySize == newSize) {
        if (newSize == 0) {
            delete [] myArray;
            myArray = nullptr;
            mySize = 0;
        }
        
    }
    else {
        Item* newArray;
        newArray = new Item[newSize];

        if (mySize < newSize) {
            for (unsigned int i = 0; i < newSize; i++) {
                newArray[i] = 0;

            }
            for (unsigned int i = 0; i < mySize; i++) {
                newArray[i] = myArray[i];

            }
        }
        else {
            for (unsigned int i = 0; i < newSize; i++) {
                newArray[i] = myArray[i];

            }
        }
        mySize = newSize;
        delete [] myArray;
        myArray = newArray;
    }
}

//opertors
Vec& Vec::operator=(const Vec& original) {
    if (this != &original) { 
        if (mySize != original.mySize) {
            if (mySize > 0){
                delete [] myArray;
                myArray = nullptr;
            }
            if (original.mySize > 0) {
            
                myArray = new Item[original.mySize];
            }
            mySize = original.mySize;
        }
        for (unsigned int i = 0; i < mySize; i++) {
            myArray[i] = original.myArray[i];
        }

    }
    return *this;
}


bool Vec::operator==(const Vec& v2) const {
    if (mySize != v2.mySize) {
        return false;
    }
    for (unsigned int i = 0; i < mySize; i++) {
        if (myArray[i] != v2.myArray[i]) {
            return false;
        }
    }
    return true;
}

void Vec::writeTo(ostream& out) const {
    for (unsigned int i = 0; i < mySize; i++) {
        out << myArray[i] << " ";
        
    }
}

void Vec::readFrom(istream& in) {
    for (unsigned int i = 0; i < mySize; i++) {
        in >> myArray[i];
        
    }
}











