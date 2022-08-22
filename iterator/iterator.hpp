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
		typedef Iterator<T, pointer, reference> iterator;

		Iterator() {}
		Iterator(const Iterator& other) {ptr = other.ptr;}
		Iterator(pointer inputPtr): ptr(inputPtr) {}
		// Iterator& operator = (Iterator &other) {
		iterator operator = (iterator &other) {
			ptr = other.ptr;
			return this;
		}
		bool operator == (Iterator &other) {return other.ptr == ptr;}
		bool operator != (Iterator &other) {return !(*this == other);}
		reference operator * () const {return *ptr;}
		reference operator -> () {return ptr;}
		Iterator operator ++() {return ++ptr;}//pre increase
		Iterator operator ++(int) {//post increase
			Iterator temp;
			temp.ptr = ptr++;
			return temp;
		}
		Iterator operator --() {return --ptr;}
		Iterator operator --(int) {
			Iterator	temp;
			temp.ptr = ptr--;
			return temp;
		}
		Iterator operator + (int a) {return ptr + a;}
		Iterator operator - (int a) {return ptr - a;}
		// std::ptrdiff_t operator - (Iterator<T>& other){return ptr - other.ptr;}
		std::ptrdiff_t operator - (Iterator other){return ptr - other.ptr;}
		Iterator operator += (const std::ptrdiff_t offset) {
			ptr += offset;
			return (*this);
		}
		bool operator < (Iterator &other){return (ptr < other.ptr);}
		bool operator > (Iterator &other){return (ptr > other.ptr);}
		bool operator <= (Iterator &other){return (ptr <= other.ptr);}
		bool operator >= (Iterator &other){return (ptr >= other.ptr);}

		friend Iterator operator +(const int offset, Iterator& out) {
			out += offset;
			return out;
		}
	};

}
