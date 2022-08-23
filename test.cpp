#include <iostream>
#include <vector>

using namespace std;

int main() {
	// vector<int> a;
	// if(a.begin() == a.end())
	// 	cout << "a is empty\n";
	// else {
	// 	cout << *a.begin() << endl;
	// 	cout << *a.end() << endl;
	// }

	vector<int> a(5, 3);
	vector<int> c(5, 3);
	vector<string> b;
	b.push_back("hello");
	b.push_back("wolrd");
	vector<int>::iterator first = a.begin();
	first++;
	// a.insert(first, c.begin(), c.end());
	
}