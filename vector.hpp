#pragma once

#include <memory>
#include <iostream>

typedef size_t size_type;	

namespace ft {
	// template<typename T, std::allocator<T> Allocator>
	template<typename T>
	class vector{
		private:
			T *dataArray;
			std::allocator<T> alloc;
			size_type dataSize;//TODO check if this is needed. Also make sure to update properly, e.g. push back. Should this be the actual size, or the capacity??

			struct Iterator {//implement iterator per container
				typedef typename T value_type;
				typedef typename ptrdiff_t difference_type;
				typedef typename random_access_iterator_tag iterator_category;//TODO is this the right tag to go>>
				typedef typename T* pointer;
				typedef typename T& reference;

				Iterator(pointer inputPtr): ptr(inputPtr) {}

				private:
					pointer ptr;
			}
		
		public:
		/*******Member function*******/	
			/******constructor******/
			vector() {dataSize = 0;}
			// vector() noexcept(noexcept(Allocator())); TODO this is for c++ 17
			explicit vector(size_type count, const T& value){
				dataSize = count;
				dataArray = alloc.allocate(count);
				for(size_type i = 0; i < count; i++) {
					dataArray[i] = value;
				}
			}
			// explicit vector(size_type count, const T& value, const Allocator& alloc = Allocator());
			/******Others******/
			~vector() {
				alloc.deallocate(dataArray, dataSize);
			}
			vector& operator=(const vector& other) {

			}
			void assign(size_type count, const T& value) {
				alloc.deallocate(dataArray, dataSize);
				dataArray = alloc.allocate(count);
				dataSize = count;
				for(size_type i = 0; i < count; i++) {
					dataArray[i] = value;
				}
			}
			std::allocator<T> get_allocator() const {
				return alloc;
			}

			/******Element access******/
			T& at(size_type pos) {
				if(pos >= dataSize)
					throw std::out_of_range("out of range\n");
				else
					return dataArray[pos];
			}

			T& operator[](size_type pos) {//TODO is this indeed return as reference instead of copy of value
				return dataArray[pos];
			}

			T& front() {
				return dataArray[0];
			}

			T& back() {
				return dataArray[dataSize - 1];
			}

			T *data() {
				return dataArray;
			}

		// friend:


	};
}
