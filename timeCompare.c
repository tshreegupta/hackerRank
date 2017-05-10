#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
char first[] = "First";
char second[]= "Second";
char* timeCompare(char* t1, char* t2){
    if(t1[5]!=t2[5])
	{
		if(t1[5]=='A')
			return first;
		else
			return second;
	}
	else
	{
		int time1 = 100*((10*(t1[0]-'0') +1*(t1[1]-'0'))%12) +10*(t1[3]-'0')+1*(t1[4]-'0');
		int time2 = 100*((10*(t2[0]-'0') +1*(t2[1]-'0'))%12) +10*(t2[3]-'0')+1*(t2[4]-'0');
		
			if(time1<time2)
				return first;
			else
				return second;
				
	}
		
}

int main() {
    int q; 
    scanf("%d", &q);
    for(int a0 = 0; a0 < q; a0++){
        char t1[10]; 
        char t2[10]; 
        scanf("%s %s", t1, t2);
        int result_size;
        char* result = timeCompare(t1, t2);
        printf("%s\n", result);
    }
    return 0;
}
