#include<stdio.h>

 struct prio{
 	int burst_time,arival_time;
 }obj[20],temp1;

int main(){

	int temp,n,burst_time[20],turn_a_time[20],wait_time[20],i,j,quant,prio[20],name[20],r;

	printf("\n enter total number of processes\n");
	scanf("%d%*c",&n);
	r=n;

	for(i=0;i<n;i++){

		printf("bust time for process[%d]",i+1);scanf("%d%*c",&obj[i].burst_time);
		/*printf("\n");
		printf("prio for process[%d]",i+1);scanf("%d%*c",&obj[i].prio);
		printf("\n");
		*/
		name[i]=i+1;
	}
	printf("\nenter time quanta \n");
	scanf("%d%*c",&quant);

	for(i=0;r!=0;i++){

		printf("bust time for process[%d]: %d \n",i+1,obj[i].burst_time-quant);

		if(i==n-1)
			i=0;
		r--;
	}

}	