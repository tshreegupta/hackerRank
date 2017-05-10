//https://www.hackerrank.com/challenges/bomber-man
//Author: Tanushree Gupta<tshreegupta@gmail.com>
#include<stdio.h>
#include<string.h>
int main()
{
	int R,C,N;
	int i,j,t;
	int field[200][7]={(0)}; //will be saved in the form of bits
	int data[20][200][7];
	char c;
	scanf("%d %d %d\n",&R,&C,&N);
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			int k=j/32;
			int l=j%32;
			c=getc(stdin);
			if(c=='.')
				field[i][k]+=1<<l;
		}
		
		getc(stdin);
	}
	if(N==1)
	{
		for(i=0;i<R;i++)
		{
			for(j=0;j<C;j++)
			{
				int k=j/32;
				int l=j%32;
				if(field[i][k]&(1<<l))
					printf(".");
				else 
					printf("O");
			}
			printf("\n");
		}
		return 0;
	}
int T= (N-1)/2;
int n=0;
	if((N-1)%2)   //when all the bomb are planted 
	{
		for(i=0;i<R;i++)
		{
			for(j=0;j<C;j++)
			{
					printf("O");
			}
			printf("\n");
		}
		return 0;
	}
	else
	{
       int repeat=-1;
		while(repeat<T-1)
		{
			
			repeat++;
            
			for(i=0;i<R;i++)
				for(j=0;j<C/32+1;j++)
                {
                    field[i][j]= ~field[i][j];
                
                }
		
			
			for(i=0;i<R;i++)
			{
				for(j=0;j<C;j++)
				{
					int k=j/32;
					int l=j%32;
					if(field[i][k]&(1<<l))
					{
                        data[repeat][i][k]|=(1<<l);
						if(i>0)
							data[repeat][i-1][k]|=(1<<l);
					
						if(i<R-1)
							data[repeat][i+1][k]|=(1<<l);
						if(j>0)
						{
							if(l>0)
							data[repeat][i][k]|=(1<<(l-1));
							else
							data[repeat][i][k-1]|=(1<<(31));
						}
						if(j<C-1)
						{
							if(l<31)
								data[repeat][i][k]|=(1<<(l+1));
							else
								data[repeat][i][k+1]|=(1<<(0));
							
						}
					}
				}
			
			}	
     
            memcpy(field,data[repeat],sizeof(int)*200*7);
			n=repeat;
			if(repeat>0)   //check if pattern is repeating
			{
				int flag = 1;
				for(i=0;i<R;i++)
				{
					for(j=0;j<C/32+1;j++)
					{
						flag=(flag&&(data[0][i][j]==field[i][j]));
						
					}
				}
				if(flag==1) //pattern matched 
				{
					n = (T-1)%repeat;
					break;   //break from the while loop
					
				}
			}
		}
		
		//print data[repeat]s
		for(i=0;i<R;i++)
		{
			for(j=0;j<C;j++)
			{
				int k=j/32;
				int l=j%32;
				if(data[n][i][k]&(1<<l))
					printf(".");
				else 
					printf("O");
			}
			printf("\n");
		}
	}
	return 0;
}