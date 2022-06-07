//
// Created by fschlute on 6/7/22.
//

#ifndef EX02_ARRAY_HPP
#define EX02_ARRAY_HPP

template<typename T>
class Array {
private:
	T *arr;
	unsigned int len;
public:
	Array() :\
			len(0), \
			arr(){
	}

	Array(unsigned int len) :\
			len(len){
			arr = new T[len];
	}

	Array(const Array &other){
		copyAttributes(other);
	}

	Array &operator=(const Array &other){
		if (this != &other)
		{
			delete[] arr;
			copyAttributes(other);
		}
		return *this;
	}

	~Array(){
		delete[] arr;
	}

	unsigned int	size() const {
		return len;
	}

	T &operator[](unsigned int i){
		if (i >= len || i < 0)
			throw std::exception();
		return arr[i];
	}

	void copyAttributes(const Array &other) {
		len = other.len;
		arr = new T[len];
		for (unsigned int i = 0; i < other.len; ++i) {
			arr[i] = other.arr[i];
		}
	}
};

#endif //EX02_ARRAY_HPP
