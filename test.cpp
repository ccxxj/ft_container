#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> a;
	if(a.begin() == a.end())
		cout << "a is empty\n";
	else {
		cout << *a.begin() << endl;
		cout << *a.end() << endl;
	}
}