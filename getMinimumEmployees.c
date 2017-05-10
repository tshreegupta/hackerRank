#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int getMinimumEmployees(int n, int** e)
{
  
}

int main() {
    int n; 
    scanf("%d", &n);
    // Information for employees 1 through n - 1:
    // The first value is the employee's supervisor ID
    // The second value is the employee's burnout status (0 is burned out, 1 is not)
    int e[n-1][2];
    for(int e_i = 0; e_i < n-1; e_i++){
       for(int e_j = 0; e_j < 2; e_j++){
          
          scanf("%d",&e[e_i][e_j]);
       }
    }
    int minimumEmployees = getMinimumEmployees(n,e);
    printf("%d\n", minimumEmployees);
    return 0;
}
