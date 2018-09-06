#include<stdio.h>
//round robin

 struct prio{
 	int burst_time,arival_time;
 }obj[20],temp1;

int main(){

	int n,i,j,k,l,quant,fl=0,ct[20],wait[20],pre,tr[20],bt[20];
	float avgw=0,avgt=0;

	printf("\n enter total number of processes\n");
	scanf("%d%*c",&n);
	
	for(i=0;i<=n;i++){
		ct[i]=0;
		wait[i]=-33;
	}

	for(i=0;i<n;i++){

		printf("bust time for process[%d]",i+1);
		scanf("%d%*c",&obj[i].burst_time);
		bt[i]=obj[i].burst_time;

	}
	printf("\nenter time quanta \n");
	scanf("%d%*c",&quant);

	k=0;
	l=-1;
	for(i=0;;i++){
		fl=0;
		if(obj[i].burst_time<quant && obj[i].burst_time>0){
			k+=obj[i].burst_time;
			k=k-quant;
		}
		if(obj[i].burst_time>0)
			k+=quant;

		if(obj[i].burst_time>0){
			ct[i]+=1;
		}
		

		obj[i].burst_time=obj[i].burst_time-quant;


		if(obj[i].burst_time<=0){
			if(wait[i]==-33){
				wait[i]=k;
				tr[i]=k;
			}	
		//	printf("tr[%d]:%d",i+1,tr[i] );
		}
		if(obj[i].burst_time>=0){
			printf("burst time for process[%d]: %d \n",i+1,obj[i].burst_time);

		}
		
		//printf("\n %d %d \n ",k,pre);


		if(i==n-1)
			i=-1;

		for(int j=0;j<n;j++){
			//printf("obj[%d]: %d ",j+1,obj[j].burst_time);
			if(obj[j].burst_time>0)
				fl=1;
		}
		//printf("\n%d\n",fl );
		pre=k;
		if(fl==0)
			break;


	}

	   //for(j=0;j<n;j++){
	   	//	printf("\n wait[%d]:%d",j+1,wait[j]);
	 	// 	printf("\n ct[%d]:%d",j+1,ct[j]);
	   	//}

	 for(i=0;i<n;i++){
	 	avgw+=wait[i]-bt[i];
	 	avgt+=tr[i];
	 }
	printf("\n average waiting time:%.4f\n",avgw/n);
	printf("\n average turnaround time:%.4f\n",avgt/n);

	// printf("\nburst time values \n\n");
	// for(i=0;i<n;i++){
	// 		printf("burst time for process[%d]: %d \n",i+1,obj[i].burst_time);
	// 	}
}	