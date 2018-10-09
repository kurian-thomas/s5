#include<stdio.h>

int main(){

	int fli,t,r,cd=0,p,q,fld,l,fl=0,n,k,rn,disp[100][100],max[100][100],need[100][100],i,j,available[100],safe[100];


	printf("\n enter the number of resources which needs resources\n");
	scanf("%d%*c",&n);

	printf("\n enter the number of resource types \n");
	scanf("%d%*c",&rn);

	printf("\n enter available resources\n");
	for (i = 0; i < rn; i++){
		printf("\n instance[%d]: ",i);
		scanf("%d%*c",&available[i]);
	}

	printf("\n enter the allocated number of resource \n");

	for (i = 0; i < n; i++)
		for (j= 0; j< rn;j++){
			printf("\n process[%d] resouce[%d]: ",i,j);
			scanf("%d%*c",&disp[i][j]);
		}
		
	for(i=0;i<n;i++)
		safe[i]=0;
		
	printf("\n enter the maximum allocation of each process \n");

	for (i=0;i<n;i++)
		for(j=0;j<rn;j++){
			printf("\n process[%d] max[%d]: ",i,j);
			scanf("%d%*c",&max[i][j]);
			need[i][j]=max[i][j]-disp[i][j];

		}	



	printf("\n");

	for(j=0;j<rn;j++)
			printf("\tR[%d]",j);

	printf("\tmax");	
	printf("\t\tavailable");
	printf("\t need \n");
	printf("\n");
	printf("\t\t\t\t\t");
	for (i = 0; i < rn; i++){
			printf("%d ",available[i]);
		}	


	for(i=0;i<n;i++){
		printf("\n");
		printf("p[%d] ",i);
		for(j=0;j<rn;j++)
			printf("\t%d",disp[i][j]);
		for(j=0;j<rn;j++)
			printf("\t%d",max[i][j]);
		printf("\t");				
		for(j=0;j<rn;j++)
			printf("\t\t%d",need[i][j]);
	}

	printf("\n");
	printf("\n");

	k=0;

	for(i=0;;i++){

		//printf("\n i=%d cd=%d",i,cd);	

		fl=0;
		fld=0;
		fli=0;
		for(t=0;t<k;t++){
			if(i==safe[t]){
				fli=1;
				break;
			}
		}
		if(fli==1)
			continue;

		for(j=0,r=0;j<rn;j++,r++){
			if(need[i][j]>available[r] )
				fl=1;
		}

		if(fl==1){
			cd++;
		}
		else{
			printf("\n process[%d] excecuted",i);
			safe[k++]=i;

			for(l=0;l<rn;l++){
					available[l]+=disp[i][l];
					disp[i][l]=0;
				}		

		}
	

		if(i==n-1)
			i=-1;

		for(p=0;p<n;p++)
			for(q=0;q<rn;q++){

				if(disp[p][q]!=0)
					fld=1;
			}
		if(fld==0)
			break;
		if(cd==n)
			break;



	}	

	printf("\nsafe sequence:");
	for(i=0;i<k;i++)
		printf("%d",safe[i]);

	printf("\n");

	

}