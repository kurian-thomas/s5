#include<stdio.h>
#include<math.h>
void sort(int *arr,int l){
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
	int n,h,arr[100],i,seek=0,previous,left[100],right[100],j,k,cy;
	printf("Enter the number of cylinders");
	scanf("%d",&cy);
	printf("Enter the current position of the head");
	scanf("%d",&h);
	printf("Enter the total number of requests");
	scanf("%d",&n);
	previous=h;
	j=0;
	k=0;
	for(i=0;i<n;i++){
		printf("\n enter position of data");
		scanf("%d",&arr[i]);
		if(arr[i]>h)
			right[j++]=arr[i];
		else
			left[k++]=arr[i];
	}
	sort(right,j);
	sort(left,k);
	for(i=0;i<j;i++){
		seek=seek+fabs(previous-right[i]);
		previous=right[i];
		printf("\n%d",right[i]);
	}
	seek=seek+cy-previous;
	previous=cy;
	for(i=k-1;i>=0;i--){
		seek=seek+fabs(previous-left[i]);
		previous=left[i];
		printf("\n%d",left[i]);
	}
	seek=seek+previous;
	seek=seek/n;
	printf("\nAverage seek time= %d",seek);
}