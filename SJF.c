#include<stdio.h>
int main(){
int n, bt[20],p[20], wt[20], tat[20], avwt = 0, i,j;
int total, pos, temp;
float avg_tat = 0, avg_wt = 0;
printf("Enter total number of processes: ");
scanf("%d",&n);
printf("\nEnter burst times\n");

for(i = 0; i<n; i++){
	printf("p[%d] = ",i+1);
	scanf("%d", &bt[i]);
	p[i] = i+1;
}

for(i = 0; i < n; i++){
	pos = i;
	for(j = i+1; j < n; j++){
		if( bt[j] < bt [pos])
			pos = j;
	}
	temp = bt[i];
	bt[i] = bt[pos];
	bt[pos] = temp;
	temp = p[i];
	p[i] = p[pos];
	p[pos] = temp;
}
wt[0] = 0;

for(i = 0; i < n; i++){
	wt[i] = 0;
	for(j = 0; j < i; j++)
		wt[i] += bt[j];
	total += wt[i];
 
}

avg_wt = (float) total / n;
total = 0;

printf("\nProcess Burst Time\tWaiting time\tTurn aroumd time");
for(i =0; i < n; i++){
	tat[i] = bt[i] + wt[i];
	total += tat[i];
	printf("\np%d\t\t%d\t\t%d\t\t%d", p[i], bt[i], wt[i], tat[i]);
}
avg_tat = (float)total / n;
printf("\nAverage Waiting time: %f", avg_wt);
printf("\nAverage turn around time: %f", avg_tat);
printf("\nAverage response time: %f", avg_wt);

return 0;
}
