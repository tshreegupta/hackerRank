//https://www.hackerrank.com/challenges/encryption
//Author: Tanushree Gupta<tshreegupta@gmail.com>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    char* s = (char *)malloc(10240 * sizeof(char));
    scanf("%s",s);
	int L = strlen(s);
    int row,col;
    row = sqrt(L);
	col = row;
    if(row*col<L)
	{
		col=row+1;
		if(row*col<L)
			row=col;
	}
	
	int i,j;
	for(j=0;j<col;j++)
	{
		for(i=0;i<row;i++)
		{
			if(i*col+j<L)
			printf("%c",*(s+i*col+j));
		}
		printf(" ");
		
	}
	
    return 0;
}
