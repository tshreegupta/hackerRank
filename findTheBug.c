#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int rc[2];
char grid[1000][1000];
int* findTheBug(int n){
	rc[0]=-1;
    rc[1]=-1;
	for(int i =0;i<n;i++)
		for(int j =0;j<n;j++)
		{
			if(grid[i][j]=='X')
			{
				rc[0]=i;
				rc[1]=j;
				return rc;
			}
		}
    printf("error\n");
    return rc;
}

int main() {
    int n; 
    scanf("%d", &n);
    
    for(int grid_i = 0; grid_i < n; grid_i++)
        scanf("%s",grid[grid_i]);
      
   
    // Return an array containing [r, c]
    int *result = findTheBug(n);
    for(int result_i = 0; result_i < 2; result_i++) {
        if(result_i) {
            printf(",");
        }
        printf("%d", result[result_i]);
    }
    puts("");
    

    return 0;
}
