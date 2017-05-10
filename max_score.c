#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long getMaxScore(int n, long int* a)
{
	long max=-1;
	long score[20];
	int first,second;
	long runingSum=0;
    for(int i=0;i<n;i++)
    {
	    for(int j=0;j<n;j++)
	    {
	 		if(i==j)
	 		   continue;
	 		if(max<a[i]%a[j])
	 		{
	 			max = a[i]%a[j];
	 			first =i;
	 			second =j;
	 		}
	    }
    }
	score[0]=0;
	score[1]=max;
	runingSum +=(a[first]+a[second]);
    a[first]=0;;
    a[second]=0;
    
	for(int i=0;i<n-2;i++)
    {
		max =0;
	    for(int j=0;j<n;j++)
	    {
			if(i==j||(!a[j]))
	 		   continue;
		   if(max<runingSum%a[j])
		   {
			   max = runingSum%a[j];
			   second =j;
		   }
		}
		score[i+2]=runingSum%a[second];
		runingSum +=a[second];
		a[second] =0;
	}
	long result=0;
	for(int i=0;i<n;i++)
		result+=score[i];
	return result;
}

int main() {
    int n; 
    scanf("%d", &n);
    long a[20] ;//= malloc(sizeof(long) * n);
    for(int a_i = 0; a_i < n; a_i++){
       scanf("%ld",&a[a_i]);
    }
    long maxScore = getMaxScore(n,a);
    printf("%ld\n", maxScore);
    return 0;
}
