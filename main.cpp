#include "vector.hpp"
#include <iostream>
#include <vector>

int main() {
	//ft::vector<int> a((unsigned int)3, (const long)5);
	try{
		ft::vector<int> a;
		ft::vector<int> b(1, 2);

		std::cout << "this is authentic std::vector\n";
		std::vector<int> c(6,2);
		std::vector<int>::iterator iter1;
		iter1 = c.begin();
		std::cout << *iter1 << std::endl;
		*iter1 = 5;
		std::cout << *iter1 << std::endl;
		std::cout << "?? " << *iter1++ << std::endl;
		std::cout << *iter1 << std::endl;
		
		std::vector<int>::iterator iter2 = 1 + iter1;
		std::cout << *iter2 << std::endl;


		std::cout << "this is my beautify ft::vector\n";
		ft::vector<int>::iterator iter;
		for(int i = 0; i < 8; i++)
			a.push_back(i);
		iter = a.begin();
		// std::cout << *iter << std::endl;
		// std::cout << *iter + 1 << std::endl;
		std::cout << "print here " << *iter++ << std::endl;
		std::cout << (*iter) << std::endl;
		
		std::cout << *(++iter) << std::endl;
		std::cout << (*iter) << std::endl;
		ft::vector<int>::iterator iter3 = 1 + iter;
		std::cout << *iter3 << std::endl;


		// *iter = 5;




		// std::cout << b[0] << std::endl;
		// b[0] = 5;
		// std::cout << b[0] << std::endl;
		// b.assign(5, 3);
		// std::cout << "within bound " << b[0] << std::endl;
		// std::cout << "out of bound " << b[7] << std::endl;
		// std::cout << "within bound " << b.at(4) << std::endl;
		// std::cout << "out of bound " << b.at(7) << std::endl;
		// std::cout << "within bound for front " << b.front() << std::endl;
		// std::cout << "within bound for back " << b.back() << std::endl;
		// std::cout << "out of bound for front " << a.front() << std::endl;
		// std::cout << "out of bound for back " << a.back() << std::endl;
	}
	catch(std::exception) {
		std::cout << "caught exception\n";
	}



	
}