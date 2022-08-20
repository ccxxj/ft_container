#include "vector.hpp"
#include <iostream>
#include <vector>

int main() {
	//ft::vector<int> a((unsigned int)3, (const long)5);
	try{
		ft::vector<int> a;
		ft::vector<int> b(1, 2);
		std::cout << b[0] << std::endl;
		b[0] = 5;
		std::cout << b[0] << std::endl;
		b.assign(5, 3);
		std::cout << "within bound " << b[0] << std::endl;
		std::cout << "out of bound " << b[7] << std::endl;
		std::cout << "within bound " << b.at(4) << std::endl;
		std::cout << "out of bound " << b.at(7) << std::endl;
		std::cout << "within bound for front " << b.front() << std::endl;
		std::cout << "within bound for back " << b.back() << std::endl;
		std::cout << "out of bound for front " << a.front() << std::endl;
		std::cout << "out of bound for back " << a.back() << std::endl;
	}
	catch(std::exception) {
		std::cout << "caught exception\n";
	}



	
}