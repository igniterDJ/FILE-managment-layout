#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point
{
    int x;
    char c[10];

}point;

int main()
{
    int i=0;
    FILE *file=fopen("input.txt","r");
    if(file==NULL)
    {
        printf("error");
        return 1;
    }

    char buffer[200];
    fgets(buffer,200,file);
    struct point points[10];
    while(!feof(file))
    {
        struct point *p=points +i;
        sscanf(buffer,"id %d name %s",&p->x,&p->c);
        fgets(buffer,200,file);
        i++;
    }
    int n=i;
    for(i=0;i<n;i++)
    {
        printf("id %d name %s\n",points[i].x,points[i].c);
    }

    fclose(file);



    points[3].x=4;
    strcat(points[3].c,"def");


    FILE *write=fopen("input.txt","w");
    if(write==NULL)
    {
        printf("error");
        return 1;
    }
    for(i=0;i<4;i++)
    {
        fprintf(write,"id %d name %s\n",points[i].x,points[i].c);
        //printf("%d %s\n",points[i].x,points[i].c);
    }
    fclose(write);

}
