#include<stdio.h>
#include<math.h>
int main(){
	int n,h,arr[100],i,seek=0,previous;
	printf("Enter the number of requests");
	scanf("%d",&n);
	printf("Enter the current position of the head");
	scanf("%d",&h);
	previous=h;
	for(i=0;i<n;i++){
		printf("\n enter position of data");
		scanf("%d",&arr[i]);
		seek=seek+fabs(previous-arr[i]);
		previous=arr[i];
	}
	for(i=0;i<n;i++)
		printf("\n%d",arr[i]);
	printf("Average seek time= %d",seek/n);
}