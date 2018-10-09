#include <stdio.h>

void main()
{
int i,x,n,t[20],d,h,c[20],k,temp,pos,cur_pos,tt,seek,seek_avg;

printf("\nEnter the number of process:\n");
scanf("%d%*c",&n);
x=n;
printf("\nEnter the disk size\n");
scanf("%d%*c",&d);

for(i=0;i<n;i++)
{
        printf("\nEnter the data position:");
        scanf("%d%*c",&t[i]);
        c[i]=i+1;

}

printf("\nEnter the starting position of the disk head:");
scanf("%d",&h);

 for(k=0;k<n-1;k++) 
	for(i=0;i<n-k-1;i++) {
            if(t[i] > t[i+1] ) {
                temp = t[i];
                t[i] = t[i+1];
                t[i+1] = temp;
 }


}


for(k=0;k<n;k++)
{
        if(t[k]>=h) 
        {       cur_pos=k;
                break;
        }
}

if(t[cur_pos]-h<h-t[cur_pos-1])
{seek=d-h+t[k-1];
seek_avg=(seek)/n;


printf("\nOrder:");
for(i=k;i<n;i++)
{
        printf("\n%d",t[i]);

}

for(i=0;i<=k-1;i++)
{
        printf("\n%d",t[i]);
}
}

else
{   seek=h+d-t[cur_pos];
    printf("\nOrder:");
for(i=k-1;i>=0;i--)
{
        printf("\n%d",t[i]);

}

for(i=n-1;i>=k;i--)
{
        printf("\n%d",t[i]);
}
seek_avg=(seek)/n;



}
printf("\nAverage:%d",seek_avg);
printf("\n total seek:%d \n",seek);

}

