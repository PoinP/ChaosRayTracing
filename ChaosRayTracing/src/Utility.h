#ifndef UTILITY_H

#define UTILITY_H

#include <cstdlib>

namespace Utility
{
	// A seed must be set before use!
	inline int generateRandomNumber(unsigned min, unsigned max)
	{
		if (max == 0 || max < min)
			return 0;

		return rand() % max + min;
	}
}

#endif // !UTILITY_H

