#include <stdio.h>
#include <stdlib.h>

int feasi(int load,int array_size, int packets_weight[]);
int dynamic_Algorithm(int dynamic_Algorithm[][]);
    
int main(int argc, char** argv) {
int TRUCKS = 1; //Number of trucks we need
    int MAX_PACKETS; //number of packets to carry
int packets[MAX_PACKETS]; //array to enter the weight of each packet
    int MAX_LOAD = 4000; //the load that each truck can carry
    
    int dynamic_Algorithm[packets[MAX_PACKETS]][TRUCKS];
int k = 0, i = 0, l, m = 0, j; //counters
    
    printf("Introduce the maximum number of packets \n");
    scanf("%d",&MAX_PACKETS);
    
    system("cls");
    
    while(i<MAX_PACKETS){  
printf("Introduce the weight of the packet (%d / %d)\n", i+1, MAX_PACKETS);
        scanf("%d", &packets[i]);
        i++; 
    }
    
    system("cls");

printf("LOAD OF EACH TRUCK: %d \t \t NUMBER OF PACKETS: %d\n", MAX_LOAD, MAX_PACKETS);
printf("----------------------------------------\n");

for(l = 0; l < MAX_PACKETS; l++){
printf("BEFORE ORDERING --> PACKET[%d]: %d \n", l, packets[l]);
}
printf("----------------------------------------\n");
//Ordering...
while(k < MAX_PACKETS){
for(j = k; j < MAX_PACKETS; j++){
if(packets[k] > packets[j]){ //busca en el array un valor mayor a packets[k]
m = packets[k]; //salva el valor antes de intercambiarlo
packets[k] = packets[j]; //intercambia la posicion del valor mayor con el del menor
packets[j] = m; //coloca el valor del mayor donde estaba el menor
}
}
k++;
}
for(l = 0; l < MAX_PACKETS; l++){
printf("AFTER ORDERING --> PACKET[%d]: %d \n", l, packets[l]);
}
printf("----------------------------------------\n");
//MAX_LOAD = feasi(MAX_LOAD,MAX_PACKETS, packets);
printf("\n|||||||||||||||||||||||||||||||||||||||\n||LOAD LEFT:%d\t\t\t     ||\n|||||||||||||||||||||||||||||||||||||||", MAX_LOAD);
}  
int feasi(int load, int array_size, int packets_weight[]){
int m = 0;
while(m < array_size && load >= packets_weight[m]){
load = load - packets_weight[m];
printf("CHARGING \n");
printf("PACKET WITH A WEIGHT OF %d INSIDE THE TRUCK\n", packets_weight[m]);
printf("REMAINING CHARGE: %d \n", load);
printf("----------------------------------------\n");
m++;
}
if(m == array_size){
printf("ALL %d PACKETS HAVE BEEN PLACED AT THE TRUCK  \n", m);
}else{
printf("%d PACKETS HAVE BEEN PLACED AT THE TRUCK  \n", m);
while (m < array_size){
printf("THE PACKET WITH WEIGHT OF %d CANNOT BE CARRIED \n", packets_weight[m]);
m++;
}
}
return load;
    
}

int dynamic_Algorithm(int packets[], int dynamic_Algorithm[][5]){
}
