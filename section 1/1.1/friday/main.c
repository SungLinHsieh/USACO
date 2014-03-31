/*
ID:john1991
LANG: C
TASK: friday
*/
#include <stdio.h>
int main()
{
    FILE *fin  = fopen ("friday.in", "r");
    FILE *fout = fopen ("friday.out", "w");
    int w[7]={0},n,i,d=0;
    fscanf(fin,"%d",&n);
    for(i=0;i<n;i++)
    {
        if((1900+i)%4==0&&(((1900+i)%100))!=0||(1900+i)%400==0)
        {
            w[d]+=1;
            w[(d+1)%7]+=2;
            w[(d+2)%7]+=2;
            w[(d+3)%7]+=1;
            w[(d+4)%7]+=2;
            w[(d+5)%7]+=3;
            w[(d+6)%7]+=1;
            d=(d+2)%7;
        }
        else
        {
            w[d]+=1;
            w[(d+1)%7]+=3;
            w[(d+2)%7]+=1;
            w[(d+3)%7]+=2;
            w[(d+4)%7]+=2;
            w[(d+5)%7]+=2;
            w[(d+6)%7]+=1;
            d=(d+1)%7;
        }
    }
    for(i=0;i<7;i++)
    {
        fprintf(fout,"%d",w[(i+5)%7]);
        if(i<6)
            fprintf(fout," ");
        else
            fprintf(fout,"\n");
    }
    return 0;
}
