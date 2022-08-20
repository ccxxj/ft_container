// #define CATCH_CONFIG_MAIN

#include "catch_amalgamated.hpp"
// #include "../catch2/Catch2/extras/catch_amalgamated.hpp"
#include "../vector.hpp"
#include <vector>

namespace tests {
	TEST_CASE ("Test ft::vectors", "[iterators]"){
		SECTION("operators") {
			ft::vector<int> a;
			ft::vector<int> empty;
			ft::vector<int>::iterator iter;
			ft::vector<int>::iterator iter1;
			ft::vector<int>::iterator iter2;
			ft::vector<int>::iterator iter3;
			std::vector<int> standard;
			std::vector<int>::iterator stdIter;
			std::vector<int>::iterator stdIter1;
			std::vector<int>::iterator stdIter2;
			std::vector<int>::iterator stdIter3;

			for(int i = 0; i < 8; i++)
				a.push_back(i);
			for(int i = 0; i < 8; i++)
				standard.push_back(i);
			iter = a.begin();
			stdIter = standard.begin();
			CHECK(*iter == *stdIter);
			*iter = 100;
			*stdIter = 100;
			CHECK(*iter == *stdIter);
			CHECK(*(++iter) == *(++stdIter));
			CHECK(*(iter++) == *(stdIter++));
			CHECK(*(iter) == *(stdIter));
			CHECK(*iter++ == *stdIter++);
			CHECK(*iter-- == *stdIter--);
			CHECK(*(iter+2) == *(stdIter+2));
			CHECK(*(2 + iter) == *(2 + stdIter));
			CHECK(a.size() == standard.size());
			CHECK(a.capacity() == standard.capacity());
			CHECK((empty.begin() == empty.end()) == true);
			iter1 = a.begin();
			iter2 = iter1 + 1;
			iter3 = iter2 + 1;
			stdIter1 = standard.begin();
			stdIter2 = stdIter1 + 1;
			stdIter3 = stdIter2 + 1;
			CHECK((iter2 - iter1) == (stdIter2 - stdIter1));
			CHECK((iter3 - iter1) == (stdIter3 - stdIter1));
			CHECK((iter1 - iter2) == (stdIter1 - stdIter2));
			CHECK((iter2 < iter1) == (stdIter2 < stdIter1));
			CHECK((iter2 > iter1) == (stdIter2 > stdIter1));
			CHECK((iter2 >= iter1) == (stdIter2 >= stdIter1));
			CHECK((iter2 <= iter1) == (stdIter2 <= stdIter1));
		}
		
	}
	TEST_CASE ("Test ft::vectors", "[element access]"){
		SECTION("element access") {
			ft::vector<std::string> ftvector;
			std::vector<std::string> stdvector;
			for(int i = 0; i < 8; i++)
				ftvector.push_back(std::to_string(i));
			for(int i = 0; i < 8; i++)
				stdvector.push_back(std::to_string(i));
			CHECK(ftvector.at(5) == stdvector.at(5));
			// CHECK(ftvector.at(8) == stdvector.at(8));
			CHECK(ftvector[2] == stdvector[2]);
			CHECK(ftvector.size() == stdvector.size());
			CHECK(ftvector.capacity() == stdvector.capacity());
		}
	}
	
}