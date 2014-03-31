/*
ID:john1991
TASK:milk2
LANG:C
*/
#include <stdio.h>
int write(int *t,int start,int end);
int find(int *t,int o,int M);
int main()
{
    int t[1000050]={0};
    int n,i,start,end,M=0;
    FILE *fin = fopen("milk2.in","r");
    FILE *fout = fopen("milk2.out","w");
    fscanf(fin,"%d",&n);
    for(i=0;i<n;i++)
    {
        fscanf(fin,"%d %d",&start,&end);
        write(t,start,end);
        if(end>M)
            M=end;
    }
    fprintf(fout,"%d %d\n",find(t,1,M)-1,find(t,0,M)+1);
    return 0;
}
int write(int *t,int start,int end)
{
    int i;
    for(i=start;i<=end;i++)
        t[i]=1;
    return 0;
}
int find(int *t,int o,int M)
{   
    int i,l=0,tmp=0;
    for(i=1;i<M;i++)
    {
        if(t[i]==o)
        {
            tmp++;
            if(t[i+1]==(1-o)&&tmp>l)
            {
                l=tmp;
                tmp=0;
            }
        }
    }
    return l;
}
