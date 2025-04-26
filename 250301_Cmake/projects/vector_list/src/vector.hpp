#pragma once

#include <cstddef>
#include <iostream>
#include <stdexcept>

namespace biv {
	template <typename T> 
	class Vector {
		private:
			static const std::size_t START_CAPACITY = 4;

			T* arr = nullptr;
			std::size_t capacity = START_CAPACITY;
			std::size_t size = 0;

			void resize(std::size_t new_capacity) {
				T* new_arr = new T[new_capacity];
				for (std::size_t i = 0; i < size; ++i) {
					new_arr[i] = arr[i];
				}
				delete[] arr;
				arr = new_arr;
				capacity = new_capacity;
			}

		public:
			Vector() {
				arr = new T[capacity];
			}
			Vector(const Vector&) = delete;
			Vector& operator = (const Vector&) = delete;
			~Vector();
			
			std::size_t get_size() const noexcept;
			bool has_item(const T& value) const noexcept;
			bool insert(const std::size_t position, const T& value);
			void print() const noexcept;
			void push_back(const T& value);
			bool remove_first(const T& value);
	};
}
