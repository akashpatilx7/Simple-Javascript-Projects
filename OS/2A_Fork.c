#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<pthread.h>
#include<semaphore.h>

void bubble(int arr[],int n){
    int i,j,temp;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d\t", arr[i]);
    }
}

int main(){
    int arr[20],n;
    printf("Enter The Size Of Array To Be Sorted: ");
    scanf("%d",&n);
    
    printf("Enter %d Array Elements: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    pid_t pid;
    pid=fork();
    
    if(pid==0){
        printf("\nSorting In Child Process\n");
        bubble(arr,n);
        printf("\n");
    }
    
    else if(pid>0){
        wait(NULL);
        printf("\nSorting In Parent Process\n");
        bubble(arr,n);
    }
    
    else{
        printf("\nFork Failure");
    }
    return 0;
}