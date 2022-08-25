#include <vector>
#include <iostream>

int main() {
	std::vector<int> a(2, 5);
	std::vector<int>::iterator first = a.begin();
	a.insert(first, 100);
	std::cout << a.capacity() << std::endl;
}