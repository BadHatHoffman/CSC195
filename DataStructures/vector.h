#pragma once
#include <initializer_list>
#include <limits>

namespace nc
{
	template<typename T>
	class vector
	{
	public:
		vector() {}
		vector(size_t size, const T& value)
		{
			_elements = new T[size];
			_capacity = size;
			_size = size;
			for (size_t i = 0; i < _size; i++) {
				_elements[i] = value;
			}
		}
		vector(const std::initializer_list<T>& ilist) {
			_capacity = ilist.size();
			_size = ilist.size();
			_elements = new T[_capacity];
			size_t i = 0;
			for (auto iter = ilist.begin(); iter != ilist.end(); iter++)
			{
				_elements[i] = *iter;
				i++;
			}
		}
		vector(size_t capacity)
		{
			_elements = new T[capacity];
			_capacity = capacity;
		}
		vector(const vector& other) {
			_capacity = other._capacity;
			_size = other._size;
			_elements = new T[_capacity];

			for (size_t i = 0; i < _size; i++) {
				_elements[i] = other._elements[i];
			}
		}
		~vector()
		{
			if (_elements) // 0 = false, everything else = true
			{
				delete[] _elements;
			}
		}

		vector& operator = (const vector& other) {
			_capacity = other._capacity;
			_size = other._size;
			if (_elements) {
				delete[] _elements;
			}
			_elements = new T[_capacity];

			for (size_t i = 0; i < _size; i++) {
				_elements[i] = other._elements[i];
			}
			return *this;
		}


		T& operator [] (size_t position)
		{
			return _elements[position];
		}

		T& at(size_t position)
		{
			return _elements[position];
		}

		T& operator [] (size_t position) const
		{
			return _elements[position];
		}

		T& at(size_t position) const
		{
			return _elements[position];
		}

		void push_back(const T& value)
		{
		
			_elements[_size] = value;
			_size++;
		}

		void pop_back()
		{
			if (_size > 0)
			{
				_size--;
			}
		}

		T& front() {return _elements[0];}
		T& back(){ return _elements[_size - 1]; }

		void reserve(size_t capacity) {
			if (capacity < _capacity) return;

			T* new_elements = new T[capacity];
			for (size_t i = 0; i < _size; i++) {
				new_elements[i] = _elements[i];
			}
			if (_elements) {
				delete[] _elements;
			}

			_elements = new_elements;
			_capacity = capacity;
		}

		void resize(size_t size, T value = T{})
		{
			if (size > _size)
			{
				if (size > _capacity)
				{
					reserve(size);
				}
				for (size_t i = _size; i < size; i++)
				{
					_elements[i] = value;
				}
			}
			_size = size;
		}

	
		void clear()
		{
			if (_elements) {
				delete[] _elements;
				_elements = nullptr;

			}
			_size = 0;
			_capacity = 0;
		}

		void swap(vector& other) {
			T* temp_elements = _elements;
			size_t temp_size = _size;
			size_t temp_capacity = _capacity;

			_elements = other._elements;
			_size = other._size;
			_capacity = other._capacity;

			other._elements = temp_elements;
			other._size = temp_size;
			other._capacity = temp_capacity;
		}

		T* data() { return _elements;};

		bool empty() const { return(_size == 0); }
		size_t size() const { return _size; }
		size_t max_size() const { return std::numeric_limits<size_t>::max(); }
		size_t capacity() const { return _capacity; }

	private:
		T* _elements{ nullptr };
		size_t _size{ 0 };
		size_t _capacity{ 0 };
	};

}