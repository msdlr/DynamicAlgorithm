#include <stdio.h>
#include <stdlib.h>

#define MAX_LOAD 4000

int cmpfunc (const void * a, const void * b) {
        return ( *(int*)a - *(int*)b );
 
    }   //source: https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
    
int main(int argc, char** argv) {
	
    
    
	int n, j, k, l, i;
	
	printf("Introduce the maximum number of packets \n");
    scanf("%d",&n);
    
	int candidates[n];
	int candidates_aux[n];
	int M[n][MAX_LOAD/10]; 
	
    for(i = 0; i < n; i++){
		printf("Introduce the weight of the packet (%d / %d)\n", i+1, n);
        scanf("%d", &candidates[i]);
	}
	/*Ordering*/
        printf("WEIGHT ORDERING AND FEASIBILITY\n");
        qsort(candidates, n, sizeof(int), cmpfunc);
        
    candidates_aux[0] = candidates[0];
	for(i = 1; i < n; i++){
    	candidates_aux[i]+= (candidates_aux[i-1] + candidates[i]);
	}
	
	    
    for(i = 0; i < n; i++){
		for(j = 0; j < MAX_LOAD/10; j++){
			if((i == 0) || (candidates_aux[i] > j)){
				M[i][j] = n+1; //NULL SET --> N+1 ~ infinite
			}
			if(j == 0){
				M[i][j] = 0; // M(i,0) = 0
			}
			if( (i>0) && (M[i-1][j] < M[i][j])) //If the upper cell (i-1,j) is lower we take it 
				M[i][j] = M[i-1][j];
			}
			if()
			
		}
	}
}

	

