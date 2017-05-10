//https://www.hackerrank.com/challenges/matrix-rotation-algo
//Author: Tanushree Gupta<tshreegupta@gmail.com>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
   int M,N,R;
   int matrix[300][300];
   cin>>M;
   cin>>N;
   cin>>R;
   for(int i=0;i<M;i++)
	   for(int j=0;j<N;j++)
		   cin>>matrix[i][j];
	
	int layer = min(M,N)/2;
	for(int i=0;i<layer;i++)
	{
		int start_r= i;
		int start_c= i;
		int end_r  = M-1-i;
		int end_c  = N-1-i;

		int len = 2*(N-1-2*i+M-1-2*i);  //length of layer
		int rot = R%len;
        int curr,prev;
		for(int j=0;j<rot;j++)
		{
			prev=matrix[start_r+1][end_c];
			for(int a=end_c;a>=start_c;a--)
			{
				curr = matrix[start_r][a];
				matrix[start_r][a] = prev;
				prev = curr;
			}
			
			for(int a=start_r+1;a<=end_r;a++)
			{
				curr = matrix[a][start_c];
				matrix[a][start_c] = prev;
				prev = curr;
			}
            
			for(int a=start_c+1;a<=end_c;a++)
			{
				curr = matrix[end_r][a];
				matrix[end_r][a] = prev;
				prev = curr;
			}
			
			for(int a=end_r-1;a>=start_r+1;a--)
			{
				curr = matrix[a][end_c];
				matrix[a][end_c] = prev;
				prev = curr;
			}
            
		}	
		
	}
	for(int i=0;i<M;i++)
    {
         for(int j=0;j<N;j++)
		   cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
	  
    return 0;
}
