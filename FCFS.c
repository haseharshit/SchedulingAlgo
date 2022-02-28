#include<stdio.h>
int main(){
int n, bt[20], wt[20], tat[20], avwt = 0, i,j;
int avtat = 0;
printf("Enter total number of processes: ");
scanf("%d",&n);
printf("\nEnter burst times\n");
printf("\ncalculating burst time");

for(i = 0; i<n; i++){
	printf("p[%d]",i+1);
	scanf("%d", &bt[i]);
}

wt[0] = 0;

for(i = 0; i < n; i++){
	wt[i] = 0;
	for(j = 0; j < i; j++){
		wt[i] += bt[j];
	}	
}
printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround time");

for(i = 0; i < n; i++){
	tat[i] = bt[i] + wt[i];
	avwt += wt[i];
	avtat += tat[i];
	printf("\np[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
}
//avwt = avwt / i;
//avtat = avtat /i;

printf("\nAverage waiting time: %f\nAverage turn around time: %f", (float)avwt/i,(float)avtat/i);
return 0;
}
