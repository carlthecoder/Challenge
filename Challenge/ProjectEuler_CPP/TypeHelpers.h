#pragma once
#include <cstdint>
#include <iostream>

using std::cout;
using std::endl;

inline void DisplayTypeRanges()
{
	cout << "int8 min: " << INT8_MIN << endl;
	cout << "int8 max: " << INT8_MAX << endl;
	cout << "uint8 max: " << UINT8_MAX << endl;
	cout << "char min: " << CHAR_MIN << endl;
	cout << "char max: " << CHAR_MAX << endl;
	cout << "uchar max: " << UCHAR_MAX << endl;

	cout << endl << endl;

	cout << "int16 min: " << INT16_MIN << endl;
	cout << "int16 max: " << INT16_MAX << endl;
	cout << "uint16 max: " << UINT16_MAX << endl;
	cout << "short min: " << SHRT_MIN << endl;
	cout << "short max: " << SHRT_MAX << endl;
	cout << "ushort max: " << USHRT_MAX << endl;

	cout << endl << endl;

	cout << "int32 min: " << INT32_MIN << endl;
	cout << "int32 max: " << INT32_MAX << endl;
	cout << "uint32 max: " << UINT32_MAX << endl;
	cout << "int min: " << INT_MIN << endl;
	cout << "int max: " << INT_MAX << endl;
	cout << "uint max: " << UINT_MAX << endl;
	cout << "long min: " << LONG_MIN << endl;
	cout << "long max: " << LONG_MAX << endl;
	cout << "ulong  max: " << ULONG_MAX << endl;

	cout << endl << endl;

	cout << "int64 min: " << INT64_MIN << endl;
	cout << "int64 max: " << INT64_MAX << endl;
	cout << "uint64 max: " << UINT64_MAX << endl;
	cout << "long long min: " << LLONG_MIN << endl;
	cout << "long long max: " << LLONG_MAX << endl;
	cout << "ulong ulong  max: " << ULLONG_MAX << endl;
	
}
