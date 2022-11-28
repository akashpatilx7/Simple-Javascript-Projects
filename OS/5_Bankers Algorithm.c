#include<stdio.h>
int max[10][10],allocation[10][10],need[10][10];
int avail[10];
int np,nr;

void readmatrix(int matrix[10][10])
{
    int i,j;
    for ( i = 0; i < np; i++)
    {
        for ( j = 0; j < nr; j++)
        {
            scanf("%d",&matrix[i][j]);
        }        
    }    
}

void display_matrix(int matrix[10][10])
{
    int i,j;
    for(i=0;i<np;i++)
    {
        printf("\n P%d ",i);
        for(j=0;j<nr;j++)
        {
            printf(" %d ",matrix[i][j]);
        }
    }
}

void calculate_need()
{
    int i,j;
    for(i=0;i<np;i++)
    {
        for(j=0;j<nr;j++)
        {
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
}

void banker()
{
    int i,j,k=0,flag;
    int finish[10],safe_seq[10];
    for(i=0;i<np;i++)
    {
        finish[i]=0;//Declare all processes are incomplete
    }
    for(i=0;i<np;i++)
    {
        flag=0;
        if(finish[i]==0)//Executes incomplete processes
        {
            for(j=0;j<nr;j++)
            {
                if(need[i][j]>avail[j])
                {
                    flag=1;//Break a loop as need is greater than avail and
                    break;
                }
            }
            if(flag==0)//need is lesser than avail so complete process
            {
                finish[i]=1;
                safe_seq[k]=i;
                k++;
                //Add allocated resources of finished process in available resource
                for(j=0;j<nr;j++)
                {
                    avail[j]+=allocation[i][j];
                }
                i=-1;
            }
        }
    }
    flag=0;//check  if all process are completed
    for(i=0;i<np;i++)
    {
        if(finish[i]==0)
        {
            printf("\n The system in deadlock");
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("\n The system is in safe state \n The safe sequence is ==>");
        for(i=0;i<np;i++)
        {
            printf(" P%d ",safe_seq[i]);
        }
    }
}

int main()
{
    int j;
    //read input
    printf("\nEnter the no of Processes :");
    scanf("%d",&np);
    printf("\nEnter the no of resources :");
    scanf("%d",&nr);
    printf("Enter initial allocation matrix :");
    readmatrix(allocation);
    printf("\n Enter max requirement matrix :");
    readmatrix(max);
    printf("\nEnter available resources :");
    for(j=0;j<nr;j++)
    {
        scanf("%d",&avail[j]); 
    }

    //Display Entered data
    printf("\n -------------------Entered Data----------------------\n\n");
    printf("\n Initial allocation: \n");
    display_matrix(allocation);
    printf("\n\n\n Maximum Requirement \n");
    display_matrix(max);
    printf("\n Available Resoueces\n");
    for(j=0;j<nr;j++)
    {
        printf(" %d",avail[j]);
    }

    //calculate and display function 
    calculate_need();
    printf("\n\n\n Need is \n");
    display_matrix(need);

    //Execute processes using bankers algorithm

    banker();
    printf("\n\n\n");
    return 0;

}