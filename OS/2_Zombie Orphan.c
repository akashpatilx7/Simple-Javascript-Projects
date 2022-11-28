// Zombie 

#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<pthread.h>
#include<semaphore.h>

int main() 
{ 
  pid_t pid; 
  pid=fork(); 
  if(pid>0) 
    { 
      sleep(50); 
      printf("\nParent Process ID %d",getppid()); 
      printf("\nIn Parent Process\n");
      printf("\nParent Process Terminated\n");
    } 
  else if(pid==0) 
    { 
      printf("\nChild Process ID %d",getpid()); 
      printf("\nIn Child Process\n");
      printf("\nChild Process Terminated\n");
    } 
  return 1;
}





// Orphan

#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<pthread.h>
#include<semaphore.h>
int main()
{
    pid_t pid;
    pid=fork();
    
    if(pid>0)
    {
        sleep(10);
        printf("\nParent Process Terminated\n");
    }
    else
    {
        while(1)
        {
            printf("\nChild Process ID %d",getpid());
            printf("\nParent Process ID %d",getppid());
        
            sleep(5);
        }
    }
    return 0;
}