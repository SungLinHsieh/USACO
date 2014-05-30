/*
ID:john1991
TASK:ariprog
LANG:C
*/
#include <stdio.h>
int main()
{
    FILE *fin  = fopen("ariprog.in","r");
    FILE *fout = fopen("ariprog.out","w");
    
    int n,m;
    int a[250*250*2*2+1]={0};
    int result[1000][2],l=0;
    int i,j,k,tmp[2];

    fscanf(fin,"%d %d",&n,&m);

    for(i=0;i<=m;i++){
        for(j=0;j<=m;j++){
            a[i*i+j*j]=1;
        }
    }

    for(i=0;i<=m*m*2;i++){
        if(a[i]){
            for(j=i+1;j<=i+(m*m*2-i)/(n-1);j++){
                for(k=1;k<=n-1 && a[i+(j-i)*k];k++);
                if(k==n){
                    result[l][0]=i;
                    result[l][1]=j-i;
                    l++;
                }
            }
        }
    }
    for(i=0;i<l;i++){
        for(j=0;j<l-i-1;j++){
            if(result[j][1]>result[j+1][1] /*|| (result[i][1]==result[j][1] && result[i][0]> result[j][0])*/){
                tmp[0]=result[j][0];
                tmp[1]=result[j][1];
                result[j][0]=result[j+1][0];
                result[j][1]=result[j+1][1];
                result[j+1][0]=tmp[0];
                result[j+1][1]=tmp[1];
            }
        }
    }
    for(i=0;i<l;i++){
        fprintf(fout,"%d %d\n",result[i][0],result[i][1]);
        //printf("%d %d\n",result[i][0],result[i][1]);
    }
    if(l==0)
        fprintf(fout,"NONE\n");
    

    return 0;
}
