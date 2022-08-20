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
			size_type dataCapacity;//TODO check if this is needed. Also make sure to update properly, e.g. push back. Should this be the actual size, or the capacity??

			struct Iterator {//implement iterator per container
				typedef T value_type;
				typedef typename std::ptrdiff_t difference_type;
				typedef typename std::random_access_iterator_tag iterator_category;//TODO is this the right tag to go>>
				typedef T* pointer;
				typedef T& reference;

				Iterator(pointer inputPtr): ptr(inputPtr) {}
				bool operator == (const Iterator& other) {
					return this->ptr == other.ptr;
				}

				private:
					pointer ptr;
			};
		
		public:
		/*******Member function*******/	
			/******constructor******/
			vector() {
				dataSize = 0;
				dataCapacity = 0;
			}
			// vector() noexcept(noexcept(Allocator())); TODO this is for c++ 17
			explicit vector(size_type count, const T& value){
				dataSize = count;
				dataCapacity = count;
				dataArray = alloc.allocate(count);
				for(size_type i = 0; i < count; i++) {
					dataArray[i] = value;
				}
			}
			// explicit vector(size_type count, const T& value, const Allocator& alloc = Allocator());
			/******Others******/
			~vector() {
				alloc.deallocate(dataArray, dataCapacity);
			}
			vector& operator=(const vector& other) {

			}
			void assign(size_type count, const T& value) {
				if(count != dataCapacity) {
					alloc.deallocate(dataArray, dataCapacity);//TODO should I check the size see if needed to deallocate?
					dataArray = alloc.allocate(count);
					dataSize = count;
					dataCapacity = count;
				}
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

			T& back() {//TODO question: should be the real last one, or capacity
				return dataArray[dataSize - 1];
			}

			T *data() {
				return dataArray;
			}

			/******Iterators******/
			Iterator begin() const {//TODO how to remove const, or use cbegin for empty
			// Iterator begin() {
				return Iterator(dataArray);
			}

			Iterator end() const {
				return Iterator(dataArray + dataSize);
			}

			/******Capacity******/
			bool empty() const {
				return ((*this).begin() == (*this).end()); 
			}

			size_type size() const {
				return dataSize;//TODO is this the correct way? according to cpp, std::distance(end() - begin())
			}

			size_type max_size() const {
				return INT8_MAX;//TODO return what value
			}

			void reserve(size_type new_cap) {
				if(new_cap > max_size())
					throw std::length_error("the new_cap is longer than max_cap\n");
				else if(new_cap > dataCapacity) {
					T* newArray = alloc.allocate(new_cap);
					for(int i = 0; i < dataSize; i++)
						newArray[i] = dataArray[i];
					alloc.deallocate(dataArray, dataCapacity);
					dataArray = newArray;
					dataCapacity = new_cap;
 				}
			}

			size_type capacity() const {
				return dataCapacity;
			}

			/******Modifiers******/
			void push_back(const T& value) {
				if(dataCapacity == dataSize)
					this->reserve(2 * dataCapacity);
				dataSize++;
				dataArray[dataSize - 1] = value;
			}
			
		// friend:


	};
}
