#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int min(int a, int b)
{
	return(a>b)?b:a;
} 
int max(int a, int b)
{
	return(a>b)?a:b;
} 
bool visited[10000]={0};
void mysort(int route[][2],int m)
{
	for(int i=0;i<m;i++)
	{
		for(int j=i;j<m;j++)
		{
			if(route[i][0]>route[j][0])
			{
				int c1 =route[i][0];
				int c2 =route[i][1];
				route[i][0] =route[j][0];
				route[i][1] =route[j][1];
				route[j][0] = c1;
				route[j][1] = c2;
			}
		}
	}
}
void BFS(int route[][2],int city,int n, int m,int *count)
{
	visited[city]=1;
	(*count)++;
	int i;
	for(i=0;i<m;i++)
	{
		if(route[i][0]==city)
			break;
	}
	while(route[i][0]==city)
	{
		if(!visited[route[i][1]])
		{
			BFS(route,route[i][1],n,m,count);
			
		}
		i++;		
		printf("%d %d\n",route[i][0],route[i][1]);
	}
	return;
}
int max_tourism(int route[][2],int n, int m)
{

	int max_visit =0;
	int city =0;
	while(city<n)
	{
		int visit =0;
		if(!visited[city])
		{
			BFS(route,city,n,m,&visit);
			printf("i= %d, visit =%d\n",city,visit);
		}
		if(max_visit<visit)
			max_visit =visit;
		city++;
	}
	return max_visit;
}
int main() {
    int n; 
    int m; 
    scanf("%d %d", &n, &m);
    int route[2*m][2];
    for(int route_i = 0; route_i < m; route_i++)
	{
		int city1,city2;
		scanf("%d %d",&city1,&city2);
		route[route_i][0]=min(city1-1,city2-1);
		route[route_i][1]=max(city1-1,city2-1);
		route[route_i+m][0]=max(city1-1,city2-1);
		route[route_i+m][1]=min(city1-1,city2-1);
		
	}
	
	mysort(route,2*m);
	int ans =max_tourism(route,n,2*m);
	printf("%d\n",ans);
    return 0;
}
