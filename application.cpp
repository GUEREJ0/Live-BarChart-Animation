// Bar Chart Animation
//
// This application uses BarChartAnimate (which uses BarChart, which uses Bar)
// to produce an animated bar chart.
//
// Once your three class/abstraction files are completed and tested, run with
// this application to see your final creation.
//
// TO DO: Nothing for the standard application, just compile and run! However,
// before submitting you need to add your creative component.
//
// Adam Koehler
// U. of Illinois, Chicago
// Fall 2022
//
// Original iteration of program developed by:
// Shanon Reckinger
// U. of Illinois, Chicago 

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "barchartanimate.h"
using namespace std;


int main() {
	char input;
	string freezeFrame;
	string filename = "cities.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);
	string line;
	BarChartAnimate bca(title, xlabel, source);

	
	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}


	cout << "Enter # to control the animation, if not enter anything else...\n";
	cin >> input;

	if(input == '#'){
		cout << "Enter which frame you would like to freeze at :";
		cin >> freezeFrame;
		bca.animate(cout, 12, -1, freezeFrame);
	}else{
		bca.animate(cout, 12, -1);
	}

	return 0;
}
