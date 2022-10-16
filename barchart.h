// barchart.h
// TO DO:  add header comment here.  Also add function header comments below.

#include <iostream>
#include <algorithm>
#include <map>
#include "myrandom.h" // used in graders, do not remove
#include "bar.h"

using namespace std;

// Constants used for bar chart animation.  You will primarily
// use these in barchartanimate.h, but you might find some useful here.
const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";
// const string RESET("\033[0m");


//
// NOTE: COMMENT AND UNCOMMENT AS NEEDED BASED ON YOUR TERMINAL
//
// Color codes for light mode terminals
// const string RED("\033[1;36m");
// const string PURPLE("\033[1;32m");
// const string BLUE("\033[1;33m");
// const string CYAN("\033[1;31m");
// const string GREEN("\033[1;35m");
// const string GOLD("\033[1;34m");
// const string BLACK("\033[1;37m");
// const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

// Color codes for darker mode terminals
const string CYAN("\033[1;36m");
const string GREEN("\033[1;32m");
const string GOLD("\033[1;33m");
const string RED("\033[1;31m");
const string PURPLE("\033[1;35m");
const string BLUE("\033[1;34m");
const string WHITE("\033[1;37m");
const string RESET("\033[0m");
const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};
map<string, string> ColorMap = {{"East Asia", COLORS[3]}, {"Middle East", COLORS[4]}, {"South Asia", COLORS[5]}, {"Europe", COLORS[0]},
{"North America", COLORS[1]}, {"Latin America", COLORS[2]}};

//
// BarChart
//
class BarChart {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // Bars.  As a result, you must also keep track of the number of elements
    // stored (size) and the capacity of the array (capacity).  This is not a
    // dynamic array, so it does not expand.
    //
    Bar* bars;  // pointer to a C-style array
    int capacity;
    int size;
    string frame;
    
 public:
    
    // default constructor:
    BarChart() {

        bars = nullptr;
        capacity = 0;
        size = 0;
        frame = "";
        
    }
    
    // parameterized constructor:
    // Parameter passed in determines memory allocated for bars.
    BarChart(int n) {
        
        // TO DO:  Write this constructor.
        bars = new Bar[n];
        capacity = 0;
        size = n;
        frame = "";
        
    }

    //
    // copy constructor:
    //
    // Called automatically by C++ to create an BarChart that contains
    // a copy of an existing BarChart.  Example: this occurs when passing
    // BarChart as a parameter by value.
    //
    BarChart(const BarChart& other) {
        
        bars = new Bar[other.size];
        size = other.size;
        capacity = other.capacity;
        frame = other.frame;

        for(int i = 0; i < other.size; i++){
            bars[i] = other.bars[i];
        }

    }
    //
    // copy operator=
    //
    // Called when you assign one BarChart into another, i.e. this = other;
    //
    BarChart& operator=(const BarChart& other) {

        if(this == &other) {return *this;}
        
        if(bars != nullptr){delete [] bars;}

        bars = new Bar[other.size];
        this->size = other.size;
        this->capacity = other.capacity;
        this->frame = other.frame;

        for(int i = 0; i < other.getSize(); i++){
            this->bars[i] = other.bars[i];
        }

        return *this;
    }

    // clear
    // frees memory and resets all private member variables to default values.
    void clear() {

        delete[] bars; // Deallocate the array, and delete everything inside it.
        bars = nullptr;
        capacity = 0;
        size = 0;
        frame = "";
        
    }
    
    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated by the
    // BarChart.
    //
    virtual ~BarChart() {

        // TO DO:  Write this destructor.
        if(bars != nullptr){delete[] bars;}
        bars = nullptr;
        capacity = 0;
        size = 0;
        frame = "";
        
    }
    
    // setFrame
    void setFrame(string frame){
        this->frame = frame;
    }
    
    // getFrame()
    // Returns the frame of the BarChart oboject.
    string getFrame() {return frame;}

    // addBar
    // adds a Bar to the BarChart.
    // returns true if successful
    // returns false if there is not room
    bool addBar(string name, int value, string category) {
        // cout << "SIZE : " << size << endl;
        // cout << "Capacity : " << capacity << endl;

        if(capacity < size){
            Bar temp(name, value, category);
            bars[capacity] = temp;
            capacity++;
            // cout << "Added.\n";
            return true;
        }
        // cout << "Did not add.\n";
        return false;
    }
    
    // getSize()
    // Returns the size (number of bars) of the BarChart object.
    int getSize() const {return size;}
  
    // operator[]
    // Returns Bar element in BarChart.
    // This gives public access to Bars stored in the Barchart.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChart: i out of bounds"
    Bar& operator[](int i) {

        if(i > 0 && i < capacity){
            cout << bars[i].getName() << " " << bars[i].getValue() << " " << bars[i].getCategory() << endl;
        }else{
            throw out_of_range("BarChart: i out of bounds");
        }
        
        return bars[i];
    }
    
    // dump
    // Used for printing the BarChart object.
    // Recommended for debugging purposes.  output is any stream (cout,
    // file stream, or string stream).
    // Format:
    // "frame: 1
    // aname 5 category1
    // bname 4 category2
    // cname 3 category3" <-newline here
    void dump(ostream &output) {

        output << "frame:" << frame << endl; 
        for(int i = 0; i < capacity; i++){
            output << bars[i].getName() << " " << bars[i].getValue() << " " << bars[i].getCategory() << endl;
        }
    }
    
    // graph
    // Used for printing out the bar.
    // output is any stream (cout, file stream, string stream)
    // colorMap maps category -> color
    // top is number of bars you'd like plotted on each frame (top 10? top 12?)
    void graph(ostream &output, map<string, string> &colors, int top) {
    	int lenMax = 60;  // this is number of BOXs that should be printed
        double nBoxes = lenMax;
        string color;
                          // for the top bar (max value)
        sort(bars, bars+size, greater<Bar>());

        // cout << "Printing sort.\n";
        // for(int i = 0; i < capacity; i++){
        //     output << bars[i].getName() << " " << bars[i].getValue() << " " << bars[i].getCategory() << endl;
        // }

        // TO DO: read this example and this erase it.
        // e.g. Here I am plotting 60 red BOXs to output
        string barstr = "";
        for(int x = 0; x < top; x++){
            nBoxes = ((bars[x].getValue() * 1.0 / bars[0].getValue()* 1.0) * lenMax);
            for (int i = 0; i < nBoxes; i++) { // Print the box
                barstr += BOX;
            }
            color = colors.at(bars[x].getCategory());
            output << color << barstr << " " << bars[x].getName() << " " << bars[x].getValue() << endl;
            barstr.clear();
        }
        color = RESET;

        return;

    }
    
};

