#include<stdio.h>
//priority 

 struct prio{
 	int burst_time,prio;
 }obj[20],temp1;

int main(){

	int temp,n,burst_time[20],turn_a_time[20],wait_time[20],i,j,quant,prio[20],name[20];

	printf("\n enter total number of processes\n");    //accepting burst time for each process
	scanf("%d%*c",&n);

	for(i=0;i<n;i++){								//display 

		printf("bust time for process[%d]",i+1);scanf("%d%*c",&obj[i].burst_time);
		printf("\n");
		printf("prio for process[%d]",i+1);scanf("%d%*c",&obj[i].prio);
		printf("\n");
		name[i]=i+1;								//array for the number name 
		
	}
	for(i=0;i<n-1;i++)								//sorting the priority
		for(j=i+1;j<n;j++){
				if(obj[i].prio>obj[j].prio){
						temp1=obj[i];
						obj[i]=obj[j];
						obj[j]=temp1;

						temp=name[i];
						name[i]=name[j];
						name[j]=temp;

				}
		}

	wait_time[0]=0;
	for(i=1;i<n;i++)							//total burst time for wach case 
    {
        wait_time[i]=0;
        for(j=0;j<i;j++)
            wait_time[i]+=obj[i].burst_time;
    }
    printf("\n          \tburst time \t wait time \t turn around time");
    for(i=0,j=0;i<n;i++,j++)				//display output
    {
        turn_a_time[i]=obj[i].burst_time+wait_time[i];

        printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d \n",name[j],obj[i].burst_time,wait_time[i],turn_a_time[i]);
    }

}    	