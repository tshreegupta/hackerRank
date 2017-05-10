//https://www.hackerrank.com/challenges/the-grid-search
//Author: Tanushree Gupta<tshreegupta@gmail.com>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <iostream>
using namespace std;

int main()
{
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++)
	{
        int R; 
        int C; 
        scanf("%d %d",&R,&C);
        char G[1000][1000];
        
        for(int G_i = 0; G_i < R; G_i++)
		{
           //for(int i=0;i<C; i++) 
            cin>>G[G_i];
        }
        int r; 
        int c; 
        scanf("%d %d",&r,&c);
        char P[1000][1000];
        for(int P_i = 0; P_i < r; P_i++)
		{
           //for(int i=0;i<c; i++)
            cin>>P[P_i];
        }
        
		int ret = 0;
		for(int G_i = 0; G_i <= R-r && !ret; G_i++)
			for(int G_j = 0; G_j <= C-c && !ret; G_j++){
                ret=1;
				for(int P_i = 0; P_i < r && ret; P_i++)
				   for(int P_j = 0; P_j < c; P_j++)
					   if(G[G_i+P_i][G_j+P_j]!=P[P_i][P_j])
                       {
                           ret = 0;
                           break;
                       }
            }
        if(ret==1)
              printf("YES\n");
        else
              printf("NO\n");
        
		 
    }
	
    return 0;
}
