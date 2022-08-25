#pragma once

#include <memory>
#include <iostream>
#include <stdio.h>
#include "iterator/iterator.hpp"
#include "std_functions/enable_if.hpp"

typedef size_t size_type;	

namespace ft {
	// template<typename T, std::allocator<T> Allocator>
	template<typename T>
	class vector{
		private:
			T *dataArray;
			std::allocator<T> alloc;
			size_type dataSize;
			size_type dataCapacity;

			void back_copy(Iterator<T> inputBegin, Iterator<T> inputEnd, Iterator<T> result) {

				size_type indexEnd = inputEnd - inputBegin;
				for(int i = indexEnd - 1; i >= 0; i--) {
					*(result + i) = *(inputBegin + i);
				}
			}

			Iterator<T> unit_insert(Iterator<T> pos, size_type count, const T& value) {
				std::ptrdiff_t position = pos - this->begin();
				if(dataCapacity == dataSize)
					this->reserve(dataCapacity + count);
				print();
				pos = this->begin() + position;
				back_copy(pos, this->end(), pos + count);
				for(size_type i = 0; i < count; i++) {
					*pos = value;
					pos++;
				}
				dataSize += count;
				return pos;
			}
		
		public:
			typedef Iterator<T> iterator;

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
					alloc.construct(dataArray + i, value);//use construct to construct object to the uninitialzed memory space
				}
			}

			vector(const vector& other) {
				vector temp(other.begin(), other.end());
				*this = temp;
			}

			template< class InputIt >
			vector(InputIt first, InputIt last, typename enable_if<!std::is_integral<InputIt>::value, bool>::type* = nullptr){
				dataSize = last - first;
				if(dataSize > 0) {
					dataArray = alloc.allocate(dataCapacity);
					dataCapacity = dataSize;
					for(size_type i = 0; i < dataSize; i++) {
						alloc.construct(dataArray + i, *first);
						first++;
					}
				}
			}
			// explicit vector(size_type count, const T& value, const Allocator& alloc = Allocator());
			/******Others******/
			~vector() {
				// alloc.deallocate(dataArray, dataCapacity);
			}
			vector& operator=(const vector& other) {
				std::cout << "calling = here\n";
				if(dataArray != other.dataArray)//TODO is this really making sense
					assign(other.begin(), other.end());
				return *this;
			}

			void assign(size_type count, const T& value) {
				if(count != dataCapacity) {//reserve
					for(size_type i = 0; i < dataSize; i++) {
						alloc.destroy(dataArray + i);
					}
					if(dataCapacity > 0)
						alloc.deallocate(dataArray, dataCapacity);//TODO should I check the size see if needed to deallocate?
					dataArray = alloc.allocate(count);
					dataSize = count;
					dataCapacity = count;
				}
				for(size_type i = 0; i < count; i++) {
					alloc.construct(dataArray + i, value);//use construct to construct object to the uninitialzed memory space
					// dataArray[i] = value;
				}
			}
			template< class InputIt >
			void assign(InputIt first, InputIt last) {
				for(size_type i = 0; i < dataSize; i++) {
					alloc.destroy(dataArray + i);
				}
				if(dataCapacity > 0)
					alloc.deallocate(dataArray, dataCapacity);
				size_type count = last - first;
				dataArray = alloc.allocate(count);
				int i = 0;
				for(InputIt temp = first; temp != last; temp++) {
					alloc.construct(dataArray + i++, *temp);
				}
				dataSize = count;
				dataCapacity = count;
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


			// Iterator insert(Iterator pos, const T& value) {

			// }
			// void insert( iterator pos, size_type count, const T& value ) {}
			/******Iterators******/
			iterator begin() const {
				iterator begin(dataArray);
				return begin;
			}
			// reverse_iterator rbegin()

			iterator end() const {
				iterator end(dataArray + dataSize);
				return end;
			}

			/******Capacity******/
			bool empty() const {
				return ((*this).begin() == (*this).end()); 
			}

			size_type size() const {
				return dataSize;
			}

			size_type max_size() const {
				return INT8_MAX;//TODO return what value
			}

			void reserve(size_type new_cap) {
				if(new_cap > max_size())
					throw std::length_error("the new_cap is longer than max_cap\n");
				else if(new_cap > dataCapacity) {
					T* newArray = alloc.allocate(new_cap);
					for(size_type i = 0; i < dataSize; i++)
						newArray[i] = dataArray[i];
					if(dataCapacity > 0)
						alloc.deallocate(dataArray, dataCapacity);
					dataArray = newArray;
					dataCapacity = new_cap;
 				}
			}

			size_type capacity() const {
				return dataCapacity;
			}
			
			/******Modifiers******/
			void clear() {
				dataSize = 0;
				dataCapacity = 0;
				if(dataCapacity > 0)
					alloc.deallocate(dataArray, dataCapacity);
			}

			iterator insert(iterator pos, const T& value) {
				return unit_insert(pos, 1, value);
			}

			void insert( iterator pos, size_type count, const T& value ) {
				unit_insert(pos, count, value);
			}

			template <class InputIterator>
			//use enable_if to differentiate the inputIterator to the first insert function
    		void insert (iterator position, InputIterator first, InputIterator last, typename enable_if<!std::is_integral<InputIterator>::value, bool>::type* = nullptr) {
				size_type count = last - first;
				std::ptrdiff_t index = position - this->begin();
				if(dataCapacity == dataSize)
					this->reserve(dataCapacity + count);
				print();
				position = this->begin() + index;
				back_copy(position, this->end(), position + count);
				while(first != last) {
					*position = *first;
					position++;
					first++;
				}
				dataSize += count;
			}

			void print() {
				for(size_type i = 0; i < dataSize; i++) {
					std::cout << dataArray[i] << " ";
				}
				std::cout << std::endl;
			}

			void push_back(const T& value) {
				if(dataSize == 0){
					dataArray = alloc.allocate(1);
					dataCapacity = 1;
				}
				else if(dataSize == dataCapacity) {
					if(dataCapacity == dataSize)
						this->reserve(2 * dataCapacity);
				}
				dataArray[dataSize] = value;
				dataSize++;
			}

			void swap(vector& other) {
				T* temp = other.dataArray;
				size_type size = other.size();
				size_type capacity = other.capacity();
				other.dataArray = dataArray;
				other.dataSize = dataSize;
				other.dataCapacity = dataCapacity;
				dataArray = temp;
				dataSize = size;
				dataCapacity = capacity;
			}

	};

	
}
