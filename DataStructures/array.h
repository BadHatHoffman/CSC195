#pragma once
#include <initializer_list>
#include <limits>

namespace nc
{
	template <typename T, size_t TSize>
	class array
	{
	public:
		array() {}
		array(const std::initializer_list<T>& ilist)
		{
			size_t i = 0;
			for (T item : ilist)
			{
				_elements[i] = item;
				i++;
			}
		}

		T& operator [] (size_t position)
		{
			return _elements[position];
		}

		T& at(size_t position)
		{
			return _elements[position];
		}

		const T& operator [] (size_t position) const
		{
			return _elements[position];
		}

		const T& at(size_t position) const
		{
			return _elements[position];
		}

		T& front();
		T& back();

		T* data() { return _elements; }

		void fill(const T& value) {
			for (int i = 0; i < TSize; i++) {
				_elements[i] = value;
			}
		}
		void swap(array& other) {
			for (size_t i = 0; i < TSize; i++) {
				T temp = _elements[i];
				_elements[i] = other._elements[i];
				other._elements[i] = temp;
			}
		}
	
		bool empty() const { return(_size == 0); }
		size_t size() const { return TSize; }
		size_t max_size() const { return std::numeric_limits<size_t>::max(); }

	private:
		T _elements[TSize]{};
		size_t _size{ 0 };
	};

	template <typename T, size_t TSize>
	T& array<T, TSize>::front()
	{
		return _elements[0];
	}

	template <typename T, size_t TSize>
	T& array<T, TSize>::back()
	{
		return _elements[TSize - 1];
	}
}

