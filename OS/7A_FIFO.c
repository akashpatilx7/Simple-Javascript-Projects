// 7A : Program 1

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
    char * fifo1="file1";
    char * fifo2="file2";
    char str1[100],str2[100];
    int fd1,fd2;
    fd1=mkfifo(fifo1,0666);
    fd2=mkfifo(fifo2,0666);

    printf("Enter sentences a ending with fullstop");
    fgets(str1,100,stdin);

    fd1=open(fifo1,O_WRONLY);
    write(fd1,str1,100);

    fd2=open(fifo2,O_RDONLY);
    read(fd2,str2,100);

    printf("Contents Readed From File are :\n");
    orintf("%s",str2);
}



// 7A : Program 2

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
    FILE *fp;
    char * fifo1="file1";
    char * fifo2="file2";
    char str1[100],str2[100];
    int fd1,fd2,nw=0,nl=0,nc=0,len;
    char ch;

    fd1=open(fifo1,O_RDONLY);
    read(fd1,str1,100);
    print("\nPipe 1 : %s",&str1);
    close(fd1);

    len=strlen(str1);

    for(int i=0;i<strlen;i++)
    {
        if(str1[i] == ' ' || str1[i]=='.')
            nw++;
        if(str1[i]=='.' || str1[i]=="\n")
            nl++;
    }
    nc=strlen(str1);

    fp=open("abc.txt","w");
    fprintf(fp,"\n No.oF characters : ",nc);
    fprintf(fp,"\n No.oF characters : ",nc);
    fprintf(fp,"\n No.oF characters : ",nc);
    //fprintf(fp,"\0");
    fclose(fp);

    fp=open("abc.txt","r");
    int i=0;
    while((fgetc(ch)) != EOF)
    {
        str2[i]=ch;
        i++;
    }
    fclose(fp);

    fd2=open(fifo2,O_RDONLY);
    read(fd2,str2,100);
    
}
