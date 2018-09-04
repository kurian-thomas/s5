#include<stdio.h>
//fcfs
int main(){

	int n,burst_time[20],turn_a_time[20],wait_time[20],i,j;

	printf("\n enter total number of processes\n");
	scanf("%d%*c",&n);

	for(i=0;i<n;i++){

		printf("bust time for process[%d]",i+1);scanf("%d%*c",&burst_time[i]);
	}

	wait_time[0]=0;
	for(i=1;i<n;i++)
    {
        wait_time[i]=0;
        for(j=0;j<i;j++)
            wait_time[i]+=burst_time[j];
    }
    printf("\n          \tburst time \t wait time \t tuen around time");
    for(i=0;i<n;i++)
    {
        turn_a_time[i]=burst_time[i]+wait_time[i];

        printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d \n",i+1,burst_time[i],wait_time[i],turn_a_time[i]);
    }

}



