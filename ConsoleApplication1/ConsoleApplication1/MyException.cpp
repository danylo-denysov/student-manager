#include "MyException.h"

template <typename T>
bool isValueEmpty(const T& value) {
	return false;
}

template <>
bool isValueEmpty<string>(const string& value) {
	return value.empty();
}

template <>
bool isValueEmpty<int>(const int& value) {
	return value == 0;
}