/*
ID:john1991
TASK:milk2
LANG:C
*/
#include <stdio.h>
int main()
{
    FILE *fin  = fopen("milk2.in","r");
    FILE *fout = fopen("milk2.out","w");
    int i,j,tmp[2];
    int n,m;
    int l,cl;
    int start[5000],end[5000],fs[5000],fe[5000];
    fscanf(fin,"%d",&n);
    for(i=0;i<n;i++)
        fscanf(fin,"%d %d\n",&start[i],&end[i]);
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if(start[j]<start[j-1])
            {
                tmp[1]=start[j];
                tmp[0]=end[j];
                start[j]=start[j-1];
                end[j]=end[j-1];
                start[j-1]=tmp[1];
                end[j-1]=tmp[0];
            }
        }
    }
    fs[0]=start[0];
    fe[0]=end[0];
    m=0;
    for(i=1;i<n;i++)
    {
        if(start[i] > fe[m])
        {
            fs[m+1]=start[i];
            fe[m+1]=end[i];
            m=m+1;
        }
        else if(end[i] > fe[m])
            fe[m]=end[i];
    }
    l=fe[0]-fs[0];
    cl=0;
    for(i=1;i<=m;i++)
    {
        if((fe[i]-fs[i])>l)
            l=fe[i]-fs[i];
        if((fs[i]-fe[i-1])>cl)
            cl=fs[i]-fe[i-1];
    }
    fprintf(fout,"%d %d\n",l,cl);
    return 0;
}
