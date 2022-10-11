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
	bc.dump(cout);
	test.dump(cout);
	test2.dump(cout);
}

void testGraph(map<string, string> colorMap){
	BarChart bc(3);
	bc.addBar("Chicago", 1020, "NA");
	bc.addBar("Paris", 1200, "Europe");
	bc.addBar("Chicago", 1300, "NA");
	bc.dump(cout);
	bc.graph(cout, colorMap, 3);
	return;

}

int main() {
	testBarDefaultConstructor();
	testBarParamConstructor();
	testBarOperatorOverload();

	map <string, string> colorMap;
	colorMap.emplace("CYAN", CYAN);
	colorMap.emplace("GREEN", GREEN);
	colorMap.emplace("GOLD", GOLD);
	colorMap.emplace("RED", RED);
	colorMap.emplace("PURPLE", PURPLE);
	colorMap.emplace("BLUE", BLUE);
	colorMap.emplace("WHITE", WHITE);
	colorMap.emplace("RESET", RESET);

	cout << " ==========================================================\n";
	// testGraph(colorMap);
	testBarChart(); // Function to test copy constructors and for memory leaks.
	
	
    return 0;
}