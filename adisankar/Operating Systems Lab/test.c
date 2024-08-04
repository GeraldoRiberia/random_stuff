#include<stdio.h>
#include<stdlib.h>

int main(){
 int n,j,temp,i,index;
  printf("enter the no of process\n");
  scanf("%d",&n);
  int bt[n],p[n];
  for(i=0;i<n;i++){
    p[i]=i+1;
    printf("enter the burst time  of p%d :",(i+1));
    scanf("%d",&bt[i]);
    printf("\n");
  }

  int at[n],wt[n];
  int tat=0,twt=0;
  for(i=0;i<n;i++){
    wt[i]=0;
    for(j=0;j<i;j++){
      wt[i] += bt[j];
    }
    at[i] =wt[i] +bt[i];
    twt +=wt[i];
    tat += at[i];
  }
  printf("process\tburst_time\twaiting_time\tturnaround_time\n");
  for (i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],at[i]);
  }

  printf("average turn around time = %f",((float)tat/n));
  printf("average waiting time = %f",((float)twt/n));
}