#include <stdio.h>
#include <stdlib.h>

#define MAX_LOAD 200

int cmpfunc (const void * a, const void * b) {
        return ( *(int*)a - *(int*)b );
 
    }   //source: https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
    
int main(int argc, char** argv) {
	
    
    
	int n, j, k, l, i, weight;
	
	printf("Introduce the maximum number of packets \n");
    scanf("%d",&n);
    n++;
    
	int candidates[n];
	int M[n][(MAX_LOAD/10)+1]; 
	
    for(i = 0; i < n; i++){
    	if (i==0){
			candidates[i]=0;
			i++;
		}
		
		printf("Introduce the weight of the packet (%d / %d)\n", i, n-1);
		printf("Weight must be multiple of 10 and smaller than %d\n", MAX_LOAD/10);
		
        scanf("%d", &candidates[i]);
        if((candidates[i]%10!=0)&&(candidates[i] > MAX_LOAD/10)){
			printf("The data is not valid\n");
			i--;
		}
	}
	
	/*Ordering*/
        printf("WEIGHT ORDERING AND FEASIBILITY\n");
        
        qsort(candidates, n, sizeof(int), cmpfunc);
        
    for(i = 0; i < n; i++){
		for(j = 0; j <= MAX_LOAD/10; j++){
			if (i == 0) {
				M[i][j] = (j*100);
			} else if (candidates[i] > (j*100)) {
				M[i][j] = M[i-1][j];
			} else {
				if (M[i-1][j] < M[i-1][j - (candidates[i]/100)]) {
					M[i][j] = M[i-1][j];
				} else {
					M[i][j] = M[i-1][j - (candidates[i]/100)];
				}
			}
				}
			
		}
		
	// PRINT MATRIX
	printf ("\t|\t");
	for (j = 0 ; j <= MAX_LOAD/10 ; j++) {
		printf ("%3d  ", (j));
	}
	printf ("\n--------------------------------------------------------------------------------\n");
	for (i = 0 ; i < n ; i++) {
		printf ("%d\t|\t", candidates[i]);
		for (j = 0 ; j <= MAX_LOAD/10 ; j++) {
			printf ("%3d  ", M[i][j]);
		}
		printf ("\n\n");
	}
	printf ("\n\n");
	// END PRINT MATRIX
	weight = M[n - 1][MAX_LOAD/10 - 1];
	printf ("The unused weigth is: %d\n", weight);
	printf ("Using the goods: ");
	i = n - 1;
	j = MAX_LOAD/10 - 1;
	while (i>0&&j>0) {
		if (M[i][j] != M[i-1][j]) {
			printf ("[%d]", candidates[i]);
			j -= (candidates[i]/10);
		}
		i--;
	}
	}


	

