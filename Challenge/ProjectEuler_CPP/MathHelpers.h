#pragma once
#include <cstdint>

namespace MathHelpers
{
	inline bool IsPrime(int64_t nr)
	{
		if (nr == 2)
		{
			return true;
		}
		else if (nr % 2 == 0)
		{
			return false;
		}

		for (int64_t i = 3; i <= nr / 2; i += 2)
		{
			if (nr % i == 0)
			{
				return false;
			}
		}

		return true;
	}
}
