// Program 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define FIFO1 "fifo1"
#define FIFO2 "fifo2"

int main()
{
	char buf[100],buf1[100];
	int fd,fd1;
	printf("\n__________________________________________\n");
	printf("\nEnter a string with fullstop at end : \n");
	printf("\n__________________________________________\n");
	
	scanf("%[^\n]",buf);
	
	mkfifo(FIFO1,0666);
	fd=open(FIFO1,O_WRONLY);

	write(fd,buf,100);
	printf("\n__________________________________________\n");
	printf("\nMessage sent");
	printf("\n__________________________________________\n");
	close(fd);
	//unlink(FIFO1);
	fd1=open(FIFO2,O_RDONLY);
	read(fd1,buf1,sizeof(buf1)+1);
	printf("\n__________________________________________\n");
	printf("\nMessage received");
	printf("\n__________________________________________\n");
	printf("\n%s",buf1);
	close(fd1);
	
	return 0;
}



// Program 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define FIFO1 "fifo1"
#define FIFO2 "fifo2"

int main()
{
	char buf[100],buf1[100];
	int fd,fd1;
	int words,lines,characters,len,i;
	char ch;
	FILE *fp;
	fd=open(FIFO1,O_RDONLY);
	read(fd,buf,100);
	printf("\n__________________________________________\n");
	printf("\nMessage received");
	printf("\n__________________________________________\n");
	printf("\n%s",buf);
	len=strlen(buf);
//	printf("\n %d ",sizeof(buf));
	words=0;
	lines=0;
	characters=0;
	for(i=0;i < len;i++)
	{
		if(buf[i] == ' ' || buf[i] == '.')
			words++;
	    if(buf[i] == '.')
			lines++;
	}
	characters=strlen(buf);
	printf("\n__________________________________________\n");
	printf("\nCharacters = %d ",characters);
	printf("\nWords = %d ",words);
	printf("\nLines = %d ",lines);
        printf("\n__________________________________________\n");
	fp=fopen("abc.txt","w");
	printf("\n__________________________________________\n");
	fprintf(fp,"\nCharacters = %d.",characters);
	fprintf(fp,"\nWords = %d.",words);
	fprintf(fp,"\nLines = %d.",lines);
	fclose(fp);
	
	fp=fopen("abc.txt","r");
	i=0;
	while((ch=fgetc(fp)) != EOF)
	{
		buf1[i]=ch;
		i++;
	}
		
	printf("\nBuffer contents\n");
	printf("\n%s",buf1);
	fclose(fp);
	//unlink(FIFO1);
	mkfifo(FIFO2,0666);
	fd1=open(FIFO2,O_WRONLY);
	write(fd1,buf1,sizeof(buf1)+1);
	printf("\n__________________________________________\n");
	printf("\nMessage sent");
	printf("\n__________________________________________\n");	
	return 0;
}
