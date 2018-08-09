#include<stdio.h>

int main(){

	int n,burst_time[20],turn_a_time[20],wait_time[20],i,j,quant,at[20];

	printf("\n enter total number of processes\n");
	scanf("%d%*c",&n);

	for(i=0;i<n;i++){

		printf("bust time for process[%d]",i+1);scanf("%d%*c",&burst_time[i]);
		printf("bust time for process[%d]",i+1);scanf("%d%*c",&at[i]);
		
	}

	puts("\n enter time quanta \n");
	scanf("%d%*c",&quant);

	while(1){
		for(i=0;i<quant;i++){
				
		}
	}