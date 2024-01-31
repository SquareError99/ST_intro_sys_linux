#include<stdio.h>
#include<string.h>

int main()
{
	char str[50];
	
	while (1)
	{
	    printf("aihlaa masa ealayk > ");
	    fgets(str, 50, stdin);
	    str[strcspn(str, "\n")] = '\0';
	    if(strcmp(str, "exit")==0)
	    	break;
	    else
	        printf("Khaliyk fi halik: %s\n",str); 
	}
	printf("Good Bye:)\n");
   	return 0;
}
