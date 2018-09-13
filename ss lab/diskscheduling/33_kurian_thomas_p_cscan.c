#include<stdio.h>
#include<math.h>
void sort(int *arr,int l){     //sort funtion 
	int i,j,temp;
	for(i=0;i<l-1;i++)
		for(j=i+1;j<l;j++)
			if(arr[j]<arr[i]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
}
int main(){
	int n,h,arr[100],i,seek=0,pre,left[100],right[100],j,k,cy;

	printf("\n enter cylinder size \n"); //accepting cylinder size  position of head and no of requests
	scanf("%d",&cy);

	printf("\n Enter the current position of the head\n");
	scanf("%d",&h);

	printf("\nEnter the total number of requests\n");
	scanf("%d",&n);

	pre=h;
	j=0;
	k=0;

	for(i=0;i<n;i++){

		printf("\n enter position of data");
		scanf("%d",&arr[i]);

		if(arr[i]>h)                      //mapping out position of right and left data
			right[j++]=arr[i];
		else
			left[k++]=arr[i];
	}

	sort(right,j);						//sorting
	sort(left,k);

	for(i=0;i<j;i++){									//seektime calculation right

		seek=seek+fabs(previous-right[i]);
		previous=right[i];
		printf("\n%d",right[i]);
	}

	seek=seek+cy-previous;											//to traverse across to the other side

	previous=0;

	//seek+=cy;

	for(i=0;i<k;i++){                              //seektitime calculation left

		seek=seek+fabs(previous-left[i]);
		previous=left[i];
		printf("\n%d",left[i]);
	}

	seek=seek+previous;
	seek=seek/n;
	                                              //output
	printf("\nAverage seek time= %d",seek);
}