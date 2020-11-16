#pragma once
#include "MathHelpers.h"
#include <iostream>
#include <cstdint>
#include <vector>
#include <cstdio>

using std::cout;
using std::endl;
using std::vector;

using namespace MathHelpers;

namespace Euler
{
	inline int Euler_01_MultiplesOf()
	{
		int sum = 0;
		for (size_t i = 0; i < 1000; i++)
		{
			if ((i % 3 == 0) || (i % 5 == 0))
			{
				sum += i;
			}
		}

		return sum;
	}

	inline int Euler_02_EvenFibonnaci()
	{
		int32_t fib = 0;
		int32_t sum = 0;
		int32_t a = 0;
		int32_t b = 1;

		while (a < 4000000 && b < 4000000)
		{
			fib = a + b;
			a = b;
			b = fib;

			if (fib % 2 == 0)
			{
				sum += fib;
			}

			cout << fib << endl;
		}

		return sum;
	}

	inline int64_t Euler_03_LargestPrime(int64_t nr)
	{
		int64_t highestPrime = 0;
		vector<int64_t> primeFactors;
		int remainder = 0;

		for (int64_t i = 2; i <= nr; i++)
		{
			if (IsPrime(i))
			{
				if (nr % i == 0)
				{
					nr /= i;
					primeFactors.push_back(i);
					highestPrime = i;
				}
				else
				{
					continue;
				}
			}
		}

		return highestPrime;
	}	

	inline bool Euler_04_IsPallindrome(int nr)
	{
		vector<int> digits;

		while (nr > 0)
		{
			int remainder = nr % 10;
			digits.push_back(remainder);
			nr /= 10;
		}

		auto size = digits.size();
		bool isPallindrome = true;

		for (int32_t i = 0; i != size / 2; ++i)
		{
			if (digits[i] != digits[size - 1 - i])
			{
				isPallindrome = false;
			}
		}

		return isPallindrome;
	}

	inline int Euler_04_FindLargestPalindrome()
	{
		int iterations = 0;
		int highest = 0;
		int product = 0;
		int highestI = 0, highestJ = 0;

		for (int i = 0; i < 999; i++)
		{
			for (int j = 0; j < 999; j++)
			{
				++iterations;
				product = i * j;

				if (Euler_04_IsPallindrome(product))
				{
					if (product > highest)
					{
						highest = product;
						highestI = i;
						highestJ = j;
					}
				}
			}
		}

		cout << "iterations: " << iterations << endl;
		cout << highestI << endl;
		cout << highestJ << endl;
		return highest;
	}

	inline int64_t Euler_05_SmallestMultiple()
	{
		int64_t multiple = 20;
		bool found = false;

		while (!found)
		{
			multiple++;
			found = true;
			for (int64_t i = 1; i < 21; ++i)
			{
				if (multiple % i != 0)
				{
					found = false;
				}
			}
		}

		return multiple;
	}

	inline int64_t Euler_06_SumSquareDifference()
	{
		int64_t sumOfSquares = 0;
		int64_t sum = 0;
		for (size_t i = 1; i <= 100; ++i)
		{
			sumOfSquares += (int64_t)pow(i, 2);
			sum += i;
		}

		return (int64_t)pow(sum, 2) - sumOfSquares;
	}

	inline int64_t Euler_07_Prime10001()
	{
		int index = 0;
		int nr = 1;

		while (index != 10001)
		{
			++nr;
			if (IsPrime(nr))
			{
				++index;
			}
		}

		return nr;
	}

	inline uint64_t Euler_08_LargestProductInSeries()
	{
		char bignr[] = "73167176531330624919225119674426574742355349194934"
			"96983520312774506326239578318016984801869478851843"
			"85861560789112949495459501737958331952853208805511"
			"12540698747158523863050715693290963295227443043557"
			"66896648950445244523161731856403098711121722383113"
			"62229893423380308135336276614282806444486645238749"
			"30358907296290491560440772390713810515859307960866"
			"70172427121883998797908792274921901699720888093776"
			"65727333001053367881220235421809751254540594752243"
			"52584907711670556013604839586446706324415722155397"
			"53697817977846174064955149290862569321978468622482"
			"83972241375657056057490261407972968652414535100474"
			"82166370484403199890008895243450658541227588666881"
			"16427171479924442928230863465674813919123162824586"
			"17866458359124566529476545682848912883142607690042"
			"24219022671055626321111109370544217506941658960408"
			"07198403850962455444362981230987879927244284909188"
			"84580156166097919133875499200524063689912560717606"
			"05886116467109405077541002256983155200055935729725"
			"71636269561882670428252483600823257530420752963450";

		printf("\n");
		printf("%s\n\n", bignr);

		unsigned long long largestProduct = 0;
		int totalDigits = strlen(bignr);

		for (int i = 0; i < totalDigits - 13; i++)
		{
			unsigned long long product = 1;
			for (int j = 0; j < 13; j++)
			{
				char digit = bignr[i + j];
				digit -= '0';
				product *= digit;
			}

			if (product > largestProduct)
			{
				largestProduct = product;
			}
		}

		return largestProduct;
	}

	inline void Euler_09_SpecialPythagoreanTriplet(void)
	{
		// Pythagorean triplet: if a < b < c => a²+ b² = c²
		// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
		// Find the product abc.

		for (int a = 0; a < 1000; a++)
		{
			for (int b = a +1; b < 1000; b++)
			{
				float csquared = (float)(std::pow(a, 2) + std::pow(b, 2));

				float c = std::sqrt(csquared);
				if (c > b)
				{
					if ((a + b + c) == 1000)
					{
						printf("Found combination: %d - %d - %d\n", (int)a, (int)b, (int)c);

						printf("Product is: %d\n", (int)(a * b * c));
					}
				}
			}
		}
	}
}