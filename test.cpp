#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
	string input = "";
	getline(cin, input);
	if (input == "") {
		cout << "Its zero" << endl;
	}
	else {
		cout << "Its " << input << endl;
	}
}