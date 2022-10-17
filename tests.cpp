#include <iostream>
#include "barchartanimate.h"
using namespace std;



bool testBarDefaultConstructor() {
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}

bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}

bool testBarOperatorOverload(){
	Bar b1("Chicago", 20, "US");
	Bar b2("New York", 50, "US");
	if(b2 < b1){
		cout << "testBarOperatorOverload: >operator failed\n";
		return false;
	}
	else if(b2 <= b1){
		cout << "testBarOperatorOverload: >= operator failed\n";
		return false;
	}
	else if(b2 < b1){
		cout << "testBarOperatorOverload: >= operator failed\n";
		return false;
	}
	else if(b2 <= b1){
		cout << "testBarOperatorOverload: >= operator failed\n";
		return false;
	}
	cout << "testBarOperatorOverload passed!\n";
	return true;
	
}

void testBarChart(){
	BarChart bc(3);
	bc.addBar("Chicago", 1020, "NA");
	bc.addBar("Paris", 1200, "Europe");
	bc.addBar("Chicago", 1300, "NA");
	BarChart test(10);
	test = bc;
	BarChart test2(bc);
	cout << "bc Dump().\n";
	bc.dump(cout);
	cout << "copy constructor test dump().\n";
	test.dump(cout);
	cout << "second copy constructor test dump().\n";
	test2.dump(cout);
	cout << "End of testBarChart().\n";
}

void testGraph(map<string, string> colorMap){
	BarChart bc(3);
	bc.addBar("Chicago", 1020, "North America");
	bc.addBar("Paris", 1200, "Europe");
	bc.addBar("Chicago", 1300, "North America");
	bc.graph(cout, colorMap, 3);
	return;

}

void testBarChartAnimate(){
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

	bca.animate(cout, 12, -1);
}

void testGameOfThrones(){
	string filename = "game-of-thrones.txt";
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

	bca.animate(cout, 12, -1);
}

void testCreativeComponent(){
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
}

void testEqualsOperator(){
	Bar b1("Guada", 156, "Europe");
	Bar b2("Guangzhou", 156, "Europe");

	if(b1 >= b2 && b2 <= b1){
		cout << GREEN << "Equals passed.\n";
	}else{
		cout << RED << "Equals failed.\n";
	}

	cout << RESET;
	return;
}

void testAddFrameThrones(){
	string filename = "game-of-thrones.txt";
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

	bca.dump();
}

void testAddFramesCities(){
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

	bca.dump();
}

int main(){
	testBarDefaultConstructor();
	testBarParamConstructor();
	testBarOperatorOverload();
	testEqualsOperator();

	// cout << " ==========================================================\n";
	// testBarChart(); // Function to test copy constructors and for memory leaks.
	// cout << " ==========================================================\n";
	// testGraph(colorMap);
	// cout << "===========================================================\n";
	testAddFrameThrones();
	// cout << "===========================================================\n";
	// testBarChartAnimate();
	// cout << "===========================================================\n";
	// testGameOfThrones();
	// cout << "===========================================================\n";
	// testCreativeComponent();
    return 0;
}