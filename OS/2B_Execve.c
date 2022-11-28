#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(int argc , char * argv[])
{
    char *newargv[10]={};
    char *newenviron[]={NULL};
    printf("Main Program To sort the array");
    pid_t pid;
    int n,arr[10],temp;
    printf("Enter No.of Elements To be Sorted");
    scanf("%d",&n);
    printf("Enter %d elements : \n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("\nArray in sorted Order :\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

    newargv[0] = argv[1];
    for(int i=0;i<n;i++)
    {
        char a[sizeof(int)];
        snprintf(a,sizeof(int),"%d",arr[i]);
        newargv[i+1]=malloc(sizeof(a));
        strcpy(newargv[i+1],a);
    }
    newargv[n+1]=NULL;
    pid=fork();
    if(pid == 0)
    {
    
        execve(argv[1],newargv,newenviron);
            perror("Error in Execve Call");
    }

}





// My Echo

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char * argv[])
{
    int j=argc;
    for(int i=argc;i>=1;i--)
    {
        printf("%s\t",&argv[i]);
    }
}
