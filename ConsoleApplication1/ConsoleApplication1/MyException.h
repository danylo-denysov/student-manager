#pragma once
#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception
{
public:
	MyException() :exception("Empty value\n") {}
};

template <typename T>
bool isValueEmpty(const T& value);

template <>
bool isValueEmpty<string>(const string& value);

template <>
bool isValueEmpty<int>(const int& value);