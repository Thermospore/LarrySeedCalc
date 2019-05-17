// Currently is only in a demonstration state

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	int range;
	int base;
	
	// Get range values from user
	printf("enter \"[base] [range]\": ");
	scanf("%d %d", &base, &range);
	printf("\n");
	
	int bestSeed; // Best seed
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
	
	// Print final results
	printf(
		"Best seed: #%d with an avg of %.2f cycles\n"
		, bestSeed, bestSeedAvg
	);
	
	time_t startTime = (time_t)bestSeed; // Convert seed number to system time
	printf("Start game at: %s", ctime(&startTime));
	
	return 0;
}

