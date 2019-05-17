#include <stdio.h>
#include <stdlib.h>

// Calculate larry cycles????
int larryCycles(int randVal)
{
	/*
		For the sake of demonstration I'm simply returning
		a random value from 2 to 30 cycles...
	*/
	return randVal%28 + 2;
}

int main()
{
	// Vars for # of rand() calls
	// These will be much higher for the real deal
	int range = 5;
	int base = 11;
	
	int bestSeed;   // Best seed
	float bestSeedAvg; // Avg Larry cycles for best seed
	
	// Loop for every time seed
//	for (int s = 0; s <= INT_MAX; s++)
	for (int s = 0; s <= 4; s++) // Only doing 5, for demonstration...
	{
		srand(s); // Set seed
		
		printf("srand(%d)\n", s);
		
		float total = 0; // Used to calc average time
		
		// Loop for each of the # of calls in our range
		for (int r = 0; r < range; r++)
		{
			// Make calls to get to where we'd be at for Larry
			for (int c = 0; c < base + r; c++)
			{
				rand();
			}
			
			// Calculate Larry time
			int result = larryCycles(rand());
			printf("%2d calls -> %2d\n", base+r, result);
			
			// Add result to average
			total += result;
		}
		
		// Calculate average
		float avg = total / range;
		printf("Average cycles: %2.2f\n\n", avg);
		
		// Store best seed if...
		if(
			   s == 0            // we are on the first seed
			|| avg < bestSeedAvg // Or we find a new best seed
		)
		{
			bestSeed = s;
			bestSeedAvg = avg;
		}
	}
	
	printf(
		"BEST SEED: #%d with an avg of %.2f cycles\n"
		, bestSeed, bestSeedAvg
	);
	
	return 0;
}

