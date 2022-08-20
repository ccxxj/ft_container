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
			std::vector<int> standard;
			std::vector<int>::iterator stdIter;
			std::vector<int>::iterator stdIter1;
			std::vector<int>::iterator stdIter2;

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
			iter1++ = a.begin();
			iter2++ = iter1++;
			stdIter1++ = standard.begin();
			stdIter2++ = stdIter1++;
			CHECK((iter2 - iter1) == (stdIter2 - stdIter1));
			CHECK((iter2 < iter1) == (stdIter2 < stdIter1));
			CHECK((iter2 > iter1) == (stdIter2 > stdIter1));
			CHECK((iter2 >= iter1) == (stdIter2 >= stdIter1));
			CHECK((iter2 <= iter1) == (stdIter2 <= stdIter1));
			
		}
		
	}
	TEST_CASE ("Test ft::vectors", "[element access]"){
		SECTION("element access") {
			ft::vector<int> b(5, 2);
			CHECK(b[2] == 2);
			CHECK(b.size() == 5);
			CHECK(b.capacity() == 5);
		}
	}
	
}