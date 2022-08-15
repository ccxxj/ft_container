#include "vector.hpp"

// using namespace ft;

// // template<typename T, std::allocator<T> Allocator>
// // template<typename T>
// vector::vector() {

// }
template<typename T>
ft::vector<T>::vector() {
	/*do nothing as it is empty*/
	// std::allocator<T> a;
	// a.allocate(1);
}

template<typename T>
ft::vector<T>::vector(size_type count, const T& value) {
	std::allocator<T> a;
	data = a.allocate(count);
	for(int i = 0; i < count; i++) {
		data[i] = value;
	}
}
