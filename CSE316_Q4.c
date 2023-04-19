#include<stdio.h>
#include<string.h>

void main()
{
    char p[10][5],temp[5];
    int i,j,pt[10],wt[10],totwt=0,pr[10],temp1,n;
    float avgwt;
    printf("enter no of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter process%d name:",i+1);
        scanf("%s",&p[i]);
        printf("enter process time:");
        scanf("%d",&pt[i]);
        printf("enter priority:");
        scanf("%d",&pr[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pr[i]>pr[j])
            {
                temp1=pr[i];
                pr[i]=pr[j];
                pr[j]=temp1;
                temp1=pt[i];
                pt[i]=pt[j];
                pt[j]=temp1;
                strcpy(temp,p[i]);
                strcpy(p[i],p[j]);
                strcpy(p[j],temp);
            }
        }
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+wt[i-1];
        totwt=totwt+wt[i];
    }
    avgwt=(float)totwt/n;
    printf("p_name\t p_time\t priority\t w_time\n");
    for(i=0;i<n;i++)
    {
       printf(" %s\t %d\t %d\t %d\n" ,p[i],pt[i],pr[i],wt[i]);
    }
    printf("total waiting time=%d\n avg waiting time=%f",totwt,avgwt);
   
    int ts,pid[10],need[10],wt1[10],tat[10],i1,j1,n2,n1;
    int bt[10],flag[10],ttat=0,twt=0;
    float awt,atat;
    printf("\nEnter the number of Processors \n");
    scanf("%d",&n);
    n1=n;
    printf("\n Enter the Timeslice \n");
    scanf("%d",&ts);
    for(i=1;i<=n;i++)
    {
        printf("\n Enter the process ID %d",i);
        scanf("%d",&pid[i]);
        printf("\n Enter the Burst Time for the process");
        scanf("%d",&bt[i]);
        need[i]=bt[i];
    }
    for(i=1;i<=n;i++)
    {
        flag[i]=1;
        wt[i]=0;
    }
    while(n!=0)
    {
        for(i=1;i<=n;i++)
        {
            if(need[i]>=ts)
            {
                for(j=1;j<=n;j++)
                {
                    if((i!=j)&&(flag[i]==1)&&(need[j]!=0))
                    wt[j]+=ts;
                }
                need[i]-=ts;
                if(need[i]==0)
                {
                    flag[i]=0;
                    n--;
                }
            }
            else
            {
                for(j=1;j<=n;j++)
                {
                    if((i!=j)&&(flag[i]==1)&&(need[j]!=0))
                    wt[j]+=need[i];
                }
                need[i]=0;
                n--;
                flag[i]=0;
            }
        }
    }
    for(i=1;i<=n1;i++)
    {
        tat[i]=wt[i]+bt[i];
        twt=twt+wt[i];
        ttat=ttat+tat[i];
    }
    awt=(float)twt/n1;
    atat=(float)ttat/n1;
    printf("\n\n Process \t Process ID  \t BurstTime \t Waiting Time \t TurnaroundTime \n ");
    for(i=1;i<=n1;i++)
    {
        printf("\n %5d \t %5d \t\t %5d \t\t %5d \t\t %5d \n", i,pid[i],bt[i],wt[i],tat[i]);
    }
    printf("\n The average Waiting Time=4.2f",awt);
    printf("\n The average Turn around Time=4.2f",atat);
}
