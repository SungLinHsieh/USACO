/*
ID:john1991
TASK:barn1
LANG:C
*/
#include <stdio.h>
int main()
{
    FILE *fin  = fopen("barn1.in","r");
    FILE *fout = fopen("barn1.out","w");

    int i,j;
    int m,s,c;
    int sum=0,tmp;
    int n[200],d[200];

    fscanf(fin,"%d %d %d",&m,&s,&c);
    
    if(m>=c)
        fprintf(fout,"%d\n",c);
    else{
    for(i=0;i<c;i++)
        fscanf(fin,"%d",&n[i]);
    for(i=0;i<c;i++){
        for(j=0;j<c-i-1;j++){
            if(n[j]>n[j+1]){
                tmp=n[j];
                n[j]=n[j+1];
                n[j+1]=tmp;
            }
        }
    }
    for(i=0;i<c-1;i++)
        d[i]=n[i+1]-n[i]-1;
    for(i=0;i<c;i++){
        for(j=0;j<c-i-2;j++){
            if(d[j]<d[j+1]){
                tmp=d[j];
                d[j]=d[j+1];
                d[j+1]=tmp;
            }
        }
    }
    for(i=0;i<m-1;i++){
        sum+=d[i];
    }
    
    fprintf(fout,"%d\n",n[c-1]-n[0]+1-sum);
    }

    return 0;
}
