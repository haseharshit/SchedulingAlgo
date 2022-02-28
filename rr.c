#include<stdio.h>
int main(){
int count, j, n, time, remain, flag = 0, time_quantum;
int wait_time = 0, turn_around_time = 0;
int at[10], bt[10], rt[10];
printf("\nEnter the number of processes: ");
scanf("%d",&n);
remain = n;
for(count = 0; count < n; count++){
	printf("Enter the arrival and burst time for the process %d: ",count+1);
	scanf("%d", &at[count]);
	scanf("%d", &bt[count]);
	rt[count] = bt[count];
}
printf("\nEnter time quantum: ");
scanf("%d", &time_quantum);
printf("\nProcess\tturn around time\twaiting time\n");
for(time = 0,count = 0; remain != 0; count++){
	if(rt[count] <= time_quantum && rt[count] > 0){
		time += rt[count];
		rt[count] = 0;
		flag = 1;
	}
	else if (rt[count] > 0){
		rt[count] = rt[count] - time_quantum;
		time += time_quantum;
	}
	if(rt[count] == 0 && flag == 1){
		remain--;
		printf("p[%d]\t\t%d\t\t%d\n", count+1, time-at[count], time - at[count] - bt[count]);
		wait_time += time - at[count] - bt[count];
		turn_around_time += time - at[count];
		flag = 0;
	}
	if(count == n-1)
		count = 0;
	else if(at[count+1] <= time)
		count++;
	else
		count = 0;
}

printf("\nAverage waiting time = %f", wait_time * 1.0);
printf("\nAverage turn around time = %f\n", turn_around_time * 1.0);

return 0;
}
