#pragma once

#include <memory>

typedef size_t size_type;	

namespace ft {
	// template<typename T, std::allocator<T> Allocator>
	template<typename T>
	class vector{
		private:

		
		public:
		//there is more versions per function
			//constructor
			vector();
			// vector() noexcept(noexcept(Allocator())); TODO this is for c++ 17
			explicit vector(size_type count, const T& value);
			// explicit vector(size_type count, const T& value, const Allocator& alloc = Allocator());

			~vector();
			vector& operator=(const vector& other);
			void assign(size_type count, const T& value);
			allocator_type get_allocator() const;

		// friend:


	};
}
