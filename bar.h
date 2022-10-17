// bar.h
// TO DO:  add header comment here.  Also add function header comments below.

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
        
        // TO DO:  Write this destructor or leave empty if not needed.
        
    }

    // getName:
	string getName() const{
        
        // TO DO:  Write this function.
        
        return name;  // TO DO:  update this, it is only here so code compiles.
	}

    // getValue:
	int getValue() const{
        
		// TO DO:  Write this function.
        
        return value;    // TO DO:  update this, it is only here so code compiles.
	}

    // getCategory:
	string getCategory() const{
        
        // TO DO:  Write this function.
        
        return category; // TO DO:  update this, it is only here so code compiles.
	}

	// operators
    // TO DO:  Write these operators.  This allows you to compare two Bar
    // objects.  Comparison should be based on the Bar's value.  For example:
	bool operator<(const Bar &other) const {

        if(this->value < other.getValue()){return true;}
        return false;  // TO DO:  update this, it is only here so code compiles.
	}

	bool operator<=(const Bar &other) const {
        if(this->value <= other.getValue()){ return true;}
        return false;  // TO DO:  update this, it is only here so code compiles.
	}

	bool operator>(const Bar &other) const {
        if(this->value > other.getValue()){return true;}
        return false;  // TO DO:  update this, it is only here so code compiles.
	}

	bool operator>=(const Bar &other) const {
        if(this->value >= other.getValue()){return true;}
        
        return false;  // TO DO:  update this, it is only here so code compiles.
	}
};

