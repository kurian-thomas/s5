#include<stdio.h>
//round robin

 struct prio{
 	int burst_time,arival_time;
 }obj[20],temp1;

int main(){

	int n,i,j,k,quant,fl=0,wait[20],tr[20],bt[20];
	float avgw=0,avgt=0;

	printf("\n enter total number of processes\n");
	scanf("%d%*c",&n);
	
	for(i=0;i<=n;i++){						//innitial empty case of wait array
		wait[i]=-33;
	}

	for(i=0;i<n;i++){						//accepting burst time 

		printf("burst time for process[%d]",i+1);
		scanf("%d%*c",&obj[i].burst_time);
		bt[i]=obj[i].burst_time;

	}
	printf("\nenter time quanta \n");		//accepting quanta
	scanf("%d%*c",&quant);

	k=0;
	for(i=0;;i++){							//processing lop 
		fl=0;
		if(obj[i].burst_time<quant && obj[i].burst_time>0){ //to increment time as per lesser burst time 
			k+=obj[i].burst_time;
			k=k-quant;
		}

		if(obj[i].burst_time>0)				//to not increment after a process is serviced 
			k+=quant;
		

		obj[i].burst_time=obj[i].burst_time-quant; //burst time left 


		if(obj[i].burst_time<=0){			//after a process is serviced add to wait and tr if not empty 
			if(wait[i]==-33){
				wait[i]=k;
				tr[i]=k;
			}	
		}
		if(obj[i].burst_time>=0){		//to output the non consumed processess
			printf("burst time for process[%d]: %d \n",i+1,obj[i].burst_time);

		}
		


		if(i==n-1)					//circular loop
			i=-1;

		for(int j=0;j<n;j++){		//check if all processes is consumed 
			if(obj[j].burst_time>0)
				fl=1;
		}
		if(fl==0)					//to exit loop if all are consumed 
			break;


	}


	 for(i=0;i<n;i++){           //cal of wait time and turnaround time 
	 	avgw+=wait[i]-bt[i];
	 	avgt+=tr[i];
	 }
	printf("\n average waiting time:%.4f\n",avgw/n);
	printf("\n average turnaround time:%.4f\n",avgt/n);


}	