//https://www.hackerrank.com/challenges/two-pluses
#include <stdio.h>
#include<string.h>
int min4(int a, int b, int c, int d)
{
	int min=a;
	if(min>a)
		min=a;
	if(min>b)
		min=b;
	if(min>c)
		min=c;
	if(min>d)
		min=d;
	return min;
}
int main()
{
	int parray[15][15]={(0)};
	int array[15][15]={(0)};
	int left[15][15]={(0)};
	int right[15][15]={(0)};
	int top[15][15]={(0)};
	int down[15][15]={(0)};
	int minm[15][15]={(0)};
	int mint[15][15]={(0)};
	
	int N,M;
	int i,j;
	
	scanf("%d %d",&N,&M);
	for(i=0;i<N;i++)
	{
		getc(stdin);
		for(j=0;j<M;j++)
		{
			char c=getc(stdin);
			if(c=='B')
			{
				array[i][j]=0;
				parray[i][j]=0;
			}
			if(c=='G')
			{
				array[i][j]=1;
				parray[i][j]=1;
			}
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			if(i==0)
				top[i][j]=array[i][j];
			else
			{
			if(array[i][j])
				top[i][j]=top[i-1][j]+1;
			else
				top[i][j]=0;
				
			}
				
		}
	}
	for(i=N-1;i>=0;i--)
	{
		for(j=M-1;j>=0;j--)
		{
			if(i==N-1)
				down[i][j]=array[i][j];
			else
			{
			if(array[i][j])
				down[i][j]=down[i+1][j]+1;
			else
				down[i][j]=0;
								
			}
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			if(j==0)
				left[i][j]=array[i][j];
			else
			{
			if(array[i][j])
				left[i][j]=left[i][j-1]+1;
			else
				left[i][j]=0;
				
			}
		}
	}
	for(i=N-1;i>=0;i--)
	{
		for(j=M-1;j>=0;j--)
		{
			if(j==M-1)
				right[i][j]=array[i][j];
			else
			{
			if(array[i][j])
				right[i][j]=right[i][j+1]+1;
			else
				right[i][j]=0;
				
			}
				
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			minm[i][j]=min4(top[i][j],right[i][j],down[i][j],left[i][j]);
			
		}
	}
/////////////////////////////////////don't touch above code
int count;
int max_ans =-1;
int x,y;
for(x =0;x<N;x++)
{
	for(y=0;y<M;y++)
	{
		if(minm[x][y])
		{
			int max =-1;
			int ans=1;
			array[x][y]=0;
			for(count=1;count<=minm[x][y]-1;count++)
			{		
				array[x][y-count]=0;
				array[x][y+count]=0;
				array[x+count][y]=0;
				array[x-count][y]=0;
			}	
			
			ans *= ((minm[x][y]-1)*4+1);
		
			for(i=0;i<N;i++)
			{
				for(j=0;j<M;j++)
				{
					if(i==0)
						top[i][j]=array[i][j];
					else
					{
					if(array[i][j])
						top[i][j]=top[i-1][j]+1;
					else
						top[i][j]=0;
						
					}
						
				}
			}
			for(i=N-1;i>=0;i--)
			{
				for(j=M-1;j>=0;j--)
				{
					if(i==N-1)
						down[i][j]=array[i][j];
					else
					{
					if(array[i][j])
						down[i][j]=down[i+1][j]+1;
					else
						down[i][j]=0;
										
					}
				}
			}
			for(i=0;i<N;i++)
			{
				for(j=0;j<M;j++)
				{
					if(j==0)
						left[i][j]=array[i][j];
					else
					{
					if(array[i][j])
						left[i][j]=left[i][j-1]+1;
					else
						left[i][j]=0;
						
					}
				}
			}
			for(i=N-1;i>=0;i--)
			{
				for(j=M-1;j>=0;j--)
				{
					if(j==M-1)
						right[i][j]=array[i][j];
					else
					{
					if(array[i][j])
						right[i][j]=right[i][j+1]+1;
					else
						right[i][j]=0;
						
					}
						
				}
			}
			for(i=0;i<N;i++)
			{
				for(j=0;j<M;j++)
				{
					mint[i][j]=min4(top[i][j],right[i][j],down[i][j],left[i][j]);
					if(max<mint[i][j])
					{
						max = mint[i][j];
					}
				}
			}
			ans*=(max-1)*4+1;
			//recalculation is done 
			
			if(max_ans<ans)
				max_ans = ans;
			memcpy(array,parray,sizeof(int)*15*15);
		}
	}
}
	
	
	
	
	
	printf("%d\n",max_ans);
	return 0;
}