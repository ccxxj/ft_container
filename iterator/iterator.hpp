#pragma once

#include <iostream>

namespace ft{
	template<typename T, 
			typename difference_type=std::ptrdiff_t,
			typename iterator_category=std::random_access_iterator_tag,
			typename pointer = T*,
			typename reference = T&>
	class Iterator {//implement iterator per container
	private:
		pointer ptr;
	public:
		typedef T value_type;

		Iterator() {}
		Iterator(const Iterator& other) {ptr = other.ptr;}
		Iterator(pointer inputPtr): ptr(inputPtr) {}
		Iterator& operator = (Iterator other) {
			ptr = other.ptr;
			return *this;
		}
		bool operator == (Iterator other) {return other.ptr == ptr;}
		bool operator != (Iterator other) {return !(*this == other);}
		reference operator * () {return *ptr;}
		reference operator -> () {return ptr;}
		Iterator operator++() {return ++ptr;}//pre increase
		Iterator operator++(int) {//post increase
			Iterator temp;
			temp.ptr = ptr++;
			return temp;
		}
		Iterator operator--() {return --ptr;}
		Iterator operator--(int) {
			Iterator temp;
			temp.ptr = ptr--;
			return temp;
		}
		Iterator operator + (int a) {return ptr + a;}
		// reference operator (int) + (Iterator a) {return a;}
		Iterator operator - (int a) {return ptr - a;}
		long operator - (Iterator& other){return (ptr - other.ptr);}
		Iterator operator += (const std::ptrdiff_t offset) {
			ptr += offset;
			return (*this);
		}
		bool operator < (Iterator& other){return (ptr < other.ptr);}
		bool operator > (Iterator& other){return (ptr > other.ptr);}
		bool operator <= (Iterator& other){return (ptr <= other.ptr);}
		bool operator >= (Iterator& other){return (ptr >= other.ptr);}


	// friend:
		// const Iterator operator+(const std::ptrdiff_t offset, Iterator out) {
		friend const Iterator operator+(const int offset, Iterator out) {
			out += offset;
			return out;
		}
		// friend const Iterator operator+( Iterator out, const int offset) {
		// 	out += offset;
		// 	return out;
		// }



	};

}
