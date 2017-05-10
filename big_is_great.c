//https://www.hackerrank.com/challenges/bigger-is-greater
//Author: Tanushree Gupta<tshreegupta@gmail.com>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void sort_string(int*data,int start,int end)
{
	
	int i,j;
	int temp;
    int count=0;
    if(start==end)
        return;
	for(i=start;i<=end;i++)
	{
		int max=i;
		for(j=i;j<=end;j++)
		{
           
			if(data[j]<data[max])
			{
				temp =data[j];
				data[j] = data[max];
				data[max]=temp;
				
			}
				
		}
        count++;
       
	}
}
int main() 
{
	int T;
	char c[100];
	int ch[100];
	int i,j,k;
	scanf("%d\n",&T);
	for(i=0;i<T;i++)
	{
		scanf("%s",c);
		int L =strlen(c);
		int curr = c[L-1]-'a';
		ch[L-1]=curr;
		for(j=L-2;j>=0;j--)
		{
			curr = c[j]-'a';
			ch[j] = curr;
			if(curr<ch[j+1])
				break;
		}
		if(j==-1)
		{
			printf("no answer\n");
			continue;
		}
		else
		{
			int min = j+1; 
			for(k=j+1;k<L;k++)
			{
				if(ch[min]>ch[k]&&ch[k]>ch[j])
					min= k;  
			}
			//swap ch[min] and ch[j]
			int temp =ch[j];
			ch[j] = ch[min];
			ch[min]=temp;
            
			sort_string(ch,j+1,L-1);
			for(k=j;k<L;k++)
			{
				c[k]='a'+ch[k];
			}
			printf("%s\n",c);
		}
	}
    return 0;
}
