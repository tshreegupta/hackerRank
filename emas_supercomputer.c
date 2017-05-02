#include <stdio.h>

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
#if 0
int main()
{
	int array[15][15]={(0)};
	int left[15][15]={(0)};
	int right[15][15]={(0)};
	int top[15][15]={(0)};
	int down[15][15]={(0)};
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
				array[i][j]=0;
			if(c=='G')
				array[i][j]=1;
			// printf("%d",array[i][j]);
		}
		// printf("\n");
	}
	printf("\n---------top----------\n");
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
			printf("%d",top[i][j]);	
				
		}
		printf("\n");
	}
	printf("\n---------down----------\n");
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
			printf("%d",down[i][j]);	
		}
		printf("\n");
	}
	printf("\n---------left----------\n");
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
			printf("%d",left[i][j]);	
		}
		printf("\n");
	}
	printf("\n---------right----------\n");
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
			printf("%d",right[i][j]);	
				
		}
		printf("\n");
	}
	int max =-1;
	int x,y;
	printf("\n---------max----------\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			top[i][j]=min4(top[i][j],right[i][j],down[i][j],left[i][j]);
			if(max<top[i][j])
			{
				max = top[i][j];
				x=i;
				y=j;
			}
			printf("%d",top[i][j]);	
		}
		printf("\n");
	}
	top[x][y]=0;
	for(i=1;i<=max-1;i++)
	{
		top[x][y-i]=0;
		top[x][y+i]=0;
		top[x-i][y]=0;
		top[x+i][y]=0;
	}
	
	int max_1 =-1;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			if(array[i][j])
			{
				if(max_1<top[i][j])
				{
					max_1 = top[i][j];
				}
			}
		}
	}
	int ans = ((max-1)*4+1)*((max_1-1)*4+1);
	printf("%d\n",ans);
	return 0;
}
#else
int main()
{
	int array[15][15]={(0)};
	int left[15][15]={(0)};
	int right[15][15]={(0)};
	int top[15][15]={(0)};
	int down[15][15]={(0)};
	int N,M;
	int i,j;
	int ans=1;
	scanf("%d %d",&N,&M);
	for(i=0;i<N;i++)
	{
		getc(stdin);
		for(j=0;j<M;j++)
		{
			char c=getc(stdin);
			if(c=='B')
				array[i][j]=0;
			if(c=='G')
				array[i][j]=1;
			// printf("%d",array[i][j]);
		}
		// printf("\n");
	}
	int ii;
	for(ii=0;ii<2;ii++)
	{
		printf("\n---------top----------\n");
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
				printf("%d",top[i][j]);	
					
			}
			printf("\n");
		}
		printf("\n---------down----------\n");
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
				printf("%d",down[i][j]);	
			}
			printf("\n");
		}
		printf("\n---------left----------\n");
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
				printf("%d",left[i][j]);	
			}
			printf("\n");
		}
		printf("\n---------right----------\n");
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
				printf("%d",right[i][j]);	
					
			}
			printf("\n");
		}
		int max =-1;
		int x,y;
		printf("\n---------max----------\n");
		for(i=0;i<N;i++)
		{
			for(j=0;j<M;j++)
			{
				top[i][j]=min4(top[i][j],right[i][j],down[i][j],left[i][j]);
				if(max<top[i][j])
				{
					max = top[i][j];
					x=i;
					y=j;
				}
				printf("%d",top[i][j]);	
			}
			printf("\n");
		}
		array[x][y]=0;
		for(i=1;i<=max-1;i++)
		{
			array[x][y-i]=0;
			array[x][y+i]=0;
			array[x+i][y]=0;
			array[x-i][y]=0;
		}
		
	
	ans *= ((max-1)*4+1);
	}
	
	printf("%d\n",ans);
	return 0;
}

#endif