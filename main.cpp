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

		// std::vector<int>::iterator iter4;

		std::cout << "this is my beautify ft::vector\n";
		ft::vector<int>::iterator iter;
		for(int i = 0; i < 7; i++)
			a.push_back(i);
		iter = a.begin();
		iter++;
		ft::vector<int>::iterator result = a.insert(iter, 100);
		std::cout <<"result is "<< *result << std::endl;
		a.print();
		a.insert(result,2, 300);
		// a.print();
		// ft::vector<std::string> input(3, "abd");
		// ft::vector<std::string>::iterator first = input.begin();
		// ft::vector<std::string>::iterator last = input.end();
		ft::vector<int> input(3, 1000);
		ft::vector<int>::iterator first = input.begin();
		ft::vector<int>::iterator last = input.end();
		std::cout << "test insert template \n";
		a.insert(a.begin(), first, last);
		a.print();

		std::cout << "test assign template\n";
		ft::vector<int> test1(3, 5);
		ft::vector<int> test2(4, 6);
		// test2.print();

		// test1.assign(test2.begin(), test2.end());
		test1.print();

		test1 = test2;
		test1.print();
		test2.print();




		// std::cout << *iter << std::endl;
		// std::cout << *iter + 1 << std::endl;
		// std::cout << "print here " << *iter++ << std::endl;
		// std::cout << (*iter) << std::endl;
		// std::cout << *(++iter) << std::endl;
		// std::cout << (*iter) << std::endl;
		// ft::vector<int>::iterator iter3 = 1 + iter;
		// std::cout << *iter3 << std::endl;


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