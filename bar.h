// bar.h
// barchart.h
// Luis de Santos
// CS251 - Adam Koehler
// UIN : ldesa3
// MacOSX using VScode

#include <iostream>
#include <string>
#include "myrandom.h" // used in graders, do not remove
using namespace std;

//
// Bar
//
class Bar {
 private:
    // Private member variables for a Bar object
    // TO DO:  Define private member variables for this class
    // NOTE: You should not be allocating memory on the heap for this class.
    string name;
    int value;
    string category;

 public:

    // default constructor:
    Bar() {
        
        // TO DO:  Write this constructor.
        name = "";
        value = 0;
        category = "";
        
    }

    //
    // a second constructor:
    //
    // Parameter passed in constructor Bar object.
    //
    Bar(string name, int value, string category) {
        
        // TO DO:  Write this constructor.
        this->name = name;
        this->value = value;
        this->category = category;
        
    }

    // destructor:
    virtual ~Bar() {
        
        name = "";
        value = 0;
        category = "";
        
    }

    // getName:
	string getName() const{return name;}

    // getValue:
	int getValue() const{return value;}

    // getCategory:
	string getCategory() const{return category;}

	// operators
    // Overload comparison operators to compare each object of Bar.h's value
	bool operator<(const Bar &other) const {

        if(this->value < other.getValue()){return true;}
        return false; 
	}

	bool operator<=(const Bar &other) const {
        if(this->value <= other.getValue()){ return true;}
        return false; 
	}

	bool operator>(const Bar &other) const {
        if(this->value > other.getValue()){return true;}
        return false; 
	}

	bool operator>=(const Bar &other) const {
        if(this->value >= other.getValue()){return true;}
        return false;
	}
};

