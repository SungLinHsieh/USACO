/*
ID:john1991
LANG: C
TASK: gift1
*/
#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fin  = fopen ("gift1.in", "r");
    FILE *fout = fopen ("gift1.out", "w");
    int k,n,i,j,m,d,c,acc[10]={0};
    char list[10][15],prog[15],div[15];
    fscanf(fin,"%d",&n);
    for(i=0;i<n;i++)
        fscanf(fin,"%s",list[i]);
    for(i=0;i<n;i++)
    {
        fscanf(fin,"%s",prog);
        fscanf(fin,"%d %d",&m,&d);
        for(k=0;k<n;k++)
        {
            if(strcmp(list[k],prog)==0)
                break;
        }
        acc[k]-=m;
        if(d==0)
            continue;
        c=(m-m%d)/d;
        m-=c*d;
        acc[k]+=m;
        for(j=0;j<d;j++)
        {   
            fscanf(fin,"%s",div);
            for(k=0;k<n;k++)
            {
                if(strcmp(list[k],div)==0)
                    acc[k]+=c;   
            }
        }
    }
    for(i=0;i<n;i++)
        fprintf(fout,"%s %d\n",list[i],acc[i]);
    return 0;
}
