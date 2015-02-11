#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

bool search_set(const int &size, int * array, const int target) {
	bool * current;
	bool * old;
	bool result = false;
	int element = 0;
	int push_index = 0;
	
	if (target == 0) {return true;}

	current = new bool[target + 1];
	old = new bool[target + 1];


	for (int i = 0; i <= target; i++) {
		current[i] = false;
		old[i] = false;
	}
	

	old[0] = true;

	for (int i = 0; i <= size - 1; i++) {
		element = *(array + i);

		for (int j = 0; j <= target; j++) {
			
			if (old[j] == true) {

				push_index = element + j;

				if (push_index <= target) {
					current[push_index] = true;

				}

			}
		}
		

		for (int k = 0; k <= target; k++) {
			if (current[k] == true || old[k] == true) {
				old[k] = true; 
			}
		}
		
		if (old[target] == true) {
			result = true;
		}
		else {
			result = false;
		}
	}
	delete[] old;
	delete[] current;
	return result;
}

int main() {
	string input = "";
	bool result = false;
	
	int size;
	int * full_set;
	int target;
	
	do {

		getline(cin, input);
		if (input == "") {break;}
		size = atoi(input.c_str());


		full_set = new int[size + 100];

		for (int i = 0; i < size; i++) {
			cin >> full_set[i];
		}

		cin >> target;

		cin.ignore();
		
		result = search_set(size, full_set, target);
		if (result == true) {
			cout << "True" << endl;
		}
		else {
			cout << "False" << endl;
		}

		delete[] full_set;
		input = "";
	} while(true);

	return 0;
}