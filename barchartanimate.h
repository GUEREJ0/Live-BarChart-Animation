// barchartanimate.h
// barchart.h
// Luis de Santos
// CS251 - Adam Koehler
// UIN : ldesa3
// MacOSX using VScode

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
    string title;
    string xlabel;
    string source;
    map<string, string> ColorMap;

    int ColorVectorItr = 0; // To loop through the iterator only used by AddFrame 

 public:

    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
        barcharts = new BarChart[4]; //Allocate memory for a an array of BarChart size 4
        size  = 0;
        capacity = 4;
        this->title = title;
        this->xlabel = xlabel;
        this->source = source;
        
    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() {
        delete[] barcharts; // De-allocating the array
        size = 0;
        capacity = 0;
        title = "";
        xlabel = "";
        source = "";
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    void addFrame(ifstream &file) {
         // Initializing variables

        string line, frame, country, name, value, category;
        int nLines = -1;
    	
        getline(file, line); // Grabbing the number of lines to grab barchart information
        getline(file, line);
        if(line == ""){return;} // Tells us we're at the end of the file, so exit the function
        nLines = stoi(line);
        BarChart bc(nLines); 

        for(int i = 0; i < nLines; i++){

            getline(file, line);
            stringstream ss(line);

            while(ss.good()){ // Using stringstream and it's delimter, I grab the string up until the end of line and 
                // store them in their respective variables
                getline(ss, frame, ',');
                getline(ss, name, ',');
                getline(ss, country, ',');
                getline(ss, value, ',');
                getline(ss, category, ',');

                if(ColorVectorItr == COLORS.size()){ColorVectorItr = 0;} // Incase if we already used all the colors in the vector, we start over

                if(ColorMap.find(category) == ColorMap.end()){ // Adding colors to each unique Category
                    ColorMap.emplace(category, COLORS.at(ColorVectorItr));
                    ColorVectorItr++;
                }

                bc.addBar(name, stoi(value), category); // Adding bar to barchart
                bc.setFrame(frame); // Setting frame
            }
        }
        if(size == capacity -1){ // Dynamically growing the array.
            capacity = capacity * 2; // Doubling capacity
            BarChart* temp = new BarChart[capacity];

            for(int i = 0; i < size; i++){ // Copying elements over
                temp[i] = barcharts[i];
            }

            delete[] barcharts; // De-allocate old array
            barcharts = temp;
            barcharts[size] = bc;
            size++;

        }else{
            barcharts[size] = bc;
            size++;
        }   
    }

    void dump(){ // Debugging function just to see if add frame is working properly.
        for(int i = 0; i < size; i++){
            barcharts[i].dump(cout);
        }
        return;
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

        if(endIter == -1 || endIter >= size){endIter = size;} // User input, error checking

        for(int i = 0; i < endIter; i++){ // Looping through the array of BarCharts and printing
            cout << RESET << title << endl;
            cout << RESET << source << endl;
            barcharts[i].graph(cout, ColorMap, top);
            cout << RESET << xlabel << endl;
            cout << RESET << "Frame: " << barcharts[i].getFrame() << endl;
            usleep(3 * microsecond);
            cout << CLEARCONSOLE;
        }

	}
    // Creative component that lets you freeze at certain frames, step through and continue.
    // Kind of like a GDB for this program
    void animate(ostream &output, int top, int endIter, string freeze) {
		unsigned int microsecond = 50000;
        char input;

        if(endIter == -1 || endIter >= size){endIter = size;}

        for(int i = 0; i < endIter; i++){
            cout << RESET << title << endl;
            cout << RESET << source << endl;
            barcharts[i].graph(cout, ColorMap, top);
            cout << RESET << xlabel << endl;
            cout << RESET << "Frame: " << barcharts[i].getFrame() << endl;
            usleep(3 * microsecond);
            if(barcharts[i].getFrame() == freeze){
                cout << RESET;
                output << "1) Enter C to continue the animation to the end.\n";
                output << "2) Enter N to move onto the next frame.\n";
                output << "3) Enter B to set another breakpoint at a certain frame.\n";
                output << "4) Enter E to end program.\n";
                cin >> input;
                if(input == 'N' || input == 'n'){
                    freeze = barcharts[i+1].getFrame();
                }
                else if(input == 'e' || input == 'E'){
                    return;
                }else if(input == 'B' || input == 'b'){
                    output << "Enter desired frame to stop at : ";
                    cin >> freeze;
                }
            }
            
            cout << CLEARCONSOLE;
        }
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
        
        if(i > 0 && i < capacity){
            return barcharts[i];
        }else{
            throw("BarChartAnimate: i out of bounds");
        }
    }
};
