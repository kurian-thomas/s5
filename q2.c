#include<stdio.h>

int main(){

	int n,burst_time[20],turn_a_time[20],wait_time[20],i,j,temp,name[20];

	printf("\n enter total number of processes\n");
	scanf("%d%*c",&n);

	for(i=0;i<n;i++){

		printf("bust time for process[%d]",i+1);scanf("%d%*c",&burst_time[i]);
		name[i]=i+1;
	}

	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++){
				if(burst_time[i]>burst_time[j]){
						temp=burst_time[i];
						burst_time[i]=burst_time[j];
						burst_time[j]=temp;

						temp=name[i];
						name[i]=name[j];
						name[j]=temp;
				}
		}
	
	wait_time[0]=0;
	for(i=1;i<n;i++)
    {
        wait_time[i]=0;
        for(j=0;j<i;j++)
            wait_time[i]+=burst_time[j];
    }
    printf("\n          \tburst time \t wait time \t turn around time");
    for(i=0,j=0;i<n;i++,j++)
    {
        turn_a_time[i]=burst_time[i]+wait_time[i];

        printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d \n",name[j],burst_time[i],wait_time[i],turn_a_time[i]);
    }

    

}