#include "defs.h"

void definedClasses (**X, l, c) {

}


void FileScan(char *filename, long int *m, long int *d)
{
    FILE *fd;
    long int  i=0, ch, prev='\n', dim=0, lines=0;
    char *str, sep[]=": \t";
   
    str=(char *)malloc(MAXSTR*sizeof(char ));
 
    if((fd=fopen(filename,"r"))==NULL){
        perror(filename);
        exit(0);
    }

    while((ch=fgetc(fd)) != EOF){
        if(!lines)
            str[i++]=ch;
     
        if(ch=='\n')
            ++lines;
     
        prev=ch;
    }

    fclose(fd);
    if(prev != '\n')
        ++lines;
   
    i--;
    str[i]='\0';
    str=strtok(str,sep);
    str=strtok((char *)NULL,sep);
    while(str)
    {
        str=strtok((char *)NULL,sep);
        dim++;
    }
    *m=lines;
    *d=dim;
   
    free((char *) str);
}