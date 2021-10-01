#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
  
int main(int argc, char *argv[]) 
{
	int number;
	
	
	if (argc < 1)
	{
		printf("Error taking inputs");
		
		return(-1);
	}
	else if (argc == 1)
	{
		printf("No argument entered. Please, enter one value as argument.\n");
	}
	else if (argc > 2)
	{
		printf("More than one argument entered. Please, enter only one value as argument.\n");
	}
	else
	{
		printf("You entered one value as argument.");
		
		if(!isNumeric(argv[1]))
		{
        	fprintf(stderr, "The value entered is not a number. Try again.\n");
        	
        	return(-1);
        }
        
        number = atoi(argv[1]);
        printf("The number entered is: %d\n", number);
        
        printf("The Collatz conjecture is: %d", number);
        
        while (number > 1)
        {
	    	printf(", ");
	    	
			if (number % 2 == 0) number = number / 2;
			else number = 3 * number + 1;
			
			printf("%d", number);
		}
		
		printf("\n");
	}
	
	return 0;
}

int isNumeric (const char * s)
{
    if (s == NULL || *s == '\0' || isspace(*s)) return 0;
    char * p;
    strtod (s, &p);
    return *p == '\0';
}
