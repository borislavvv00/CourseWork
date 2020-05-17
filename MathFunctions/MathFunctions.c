#include <math.h>
#include <stdlib.h>
#include "MathFunctions.h"

float GenerateRandomFloat(const unsigned char numberOfCharectersBeforePoint, const unsigned char numberOfCharectersAfterPoint)
{
	float number = 0.0f; //Float number that will be returned.
	unsigned char countAfter = 1; // Tell in which position after decimal point chareter is.
	unsigned char countBefore = 0; // Tell in which position before decimal point chareter is.
	float temp = 0.0f; // Randow generated number. 

	while ((countAfter < (numberOfCharectersAfterPoint + 1)) || (countBefore < numberOfCharectersBeforePoint))
	{
		temp = (float)(rand() % 9);

		// Add charecters before decimal point.
		if (countBefore < numberOfCharectersBeforePoint)
		{
			// Add next charecter to the number.
			number += temp * (float)pow((double)10, (double)countBefore);
			countBefore++;
		}
		else // Add charecters after decimal point.
		{
			// Add next charecter to the number.
			number += temp / (float)pow((double)10, (double)countAfter);
			countAfter++;
		}
	}

	return number;
}