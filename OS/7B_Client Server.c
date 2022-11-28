// 7B : Program 1

#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main()
{
    // ftok to generate unique key
    key_t key = ftok("shmfile",65);

    //shmget returns an identifier in shmid

    int shmid = shmget(key,1024,0666|IPC_CREAT);

    //shmat to attach to shared memory
    char *str = (char *) shmat(shmid,NULL,0);

    print("Write Data : ");
    fgets(str,100,stdin);

    printf("Data Written in the Shared Memory By server Program : %s\n",str);

    //Detach From shared Memory
    shmdt(str);

    return 0;
}

// 7B : Program 2

prog2
#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main()
{
    // ftok to generate unique key
    key_t key = ftok("shmfile",65);

    //shmget returns an identifier in shmid
    int shmid =shmget(key,1024,0666|IPC_CREAT);

    //shmat to attach to shared memory
    char *str = (char *) shmat(shmid,NULL,0);

    printf("Data Read From the Shared Memory by Client Program: %s\n",str);

    //Detach From shared Memory
    shmdt(str);

    //Destroy the shared memory
    shmctl(shmid,IPC_RMID,NULL);

    return 0;
}