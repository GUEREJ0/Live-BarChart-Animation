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

 public:

    // default constructor:
    Bar() {
        
        // TO DO:  Write this constructor.
        
    }

    //
    // a second constructor:
    //
    // Parameter passed in constructor Bar object.
    //
    Bar(string name, int value, string category) {
        
        // TO DO:  Write this constructor.
        
    }

    // destructor:
    virtual ~Bar() {
        
        // TO DO:  Write this destructor or leave empty if not needed.
        
    }

    // getName:
	string getName() {
        
        // TO DO:  Write this function.
        
        return "";  // TO DO:  update this, it is only here so code compiles.
	}

    // getValue:
	int getValue() {
        
		// TO DO:  Write this function.
        
        return 0;    // TO DO:  update this, it is only here so code compiles.
	}

    // getCategory:
	string getCategory() {
        
        // TO DO:  Write this function.
        
        return ""; // TO DO:  update this, it is only here so code compiles.
	}

	// operators
    // TO DO:  Write these operators.  This allows you to compare two Bar
    // objects.  Comparison should be based on the Bar's value.  For example:
	bool operator<(const Bar &other) const {
        return true;  // TO DO:  update this, it is only here so code compiles.
	}

	bool operator<=(const Bar &other) const {
        return true;  // TO DO:  update this, it is only here so code compiles.
	}

	bool operator>(const Bar &other) const {
        return true;  // TO DO:  update this, it is only here so code compiles.
	}

	bool operator>=(const Bar &other) const {
        return true;  // TO DO:  update this, it is only here so code compiles.
	}
};

