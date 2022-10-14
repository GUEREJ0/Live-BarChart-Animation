// barchartanimate.h
// TO DO:  add header comment here.  Also add function header comments below.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used by graders, do not remove
#include "barchart.h"
  
using namespace std;

//
// BarChartAnimate
//
class BarChartAnimate {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    //
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    map<string, string> colorMap;

 public:

    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
        barcharts = new BarChart[4];
        size  = 4;
        capacity = 0;
        
        // TO DO:  Write this constructor.
        
    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() {
        delete[] barcharts;
        size = 0;
        capacity = 0;
        
        // TO DO:  Write this destructor.
        
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    void addFrame(ifstream &file) {


        string line, frame, country, name, value, category;
        int nLines = -1;
    	
        getline(file, line);
        getline(file, line);
        if(line == ""){return;}
        nLines = stoi(line);
        BarChart bc(nLines);

        for(int i = 0; i < nLines; i++){
            getline(file, line);
            stringstream ss(line);

            while(ss.good()){
                // cout << line << endl;
                getline(ss, frame, ',');
                getline(ss, country, ',');
                getline(ss, name, ',');
                getline(ss, value, ',');
                getline(ss, category, ',');


                bc.addBar(name, stoi(value), category);
            }
            bc.setFrame(frame); 
        }
        if(capacity == size -1){
            // cout << "!GROWING!\n";
            size = size * 2;
            BarChart* temp = new BarChart[size];
            for(int i = 0; i < capacity; i++){
                temp[i] = barcharts[i];
            }
            delete[] barcharts;
            barcharts = temp;
            barcharts[capacity] = bc;
            capacity++;
        }else{
            barcharts[capacity] = bc;
            capacity++;
        }   
    }

    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000;

        if(endIter == -1 || endIter >= capacity){endIter = capacity;}

        for(int i = 0; i < endIter; i++){
            usleep(3 * microsecond);
            barcharts[i].graph(cout, ColorMap, top);
            cout << CLEARCONSOLE;
        }
        
        // TO DO:  Write this function.
			
	}

    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize(){return size;}

    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    //
    BarChart& operator[](int i){
        BarChart bc;
        
        // TO DO:  Write this function.
        
        return bc; // TO DO:  update this, it is only here so code compiles.
    }
};
