/*
ID:john1991
TASK:milk
LANG:C
*/
#include <stdio.h>
int main()
{
    FILE *fin  = fopen("milk.in","r");
    FILE *fout = fopen("milk.out","w");

    int i,j;
    int n,m,milk[5000][2];
    int money=0,sum=0;
    int tmp[2];
    
    fscanf(fin,"%d %d",&n,&m);
    for(i=0;i<m;i++){
        fscanf(fin,"%d %d",&milk[i][0],&milk[i][1]);
    }
    for(i=0;i<m;i++){
        for(j=0;j<m-i-1;j++){
            if(milk[j][0]>milk[j+1][0]){
                tmp[0]=milk[j][0];
                tmp[1]=milk[j][1];
                milk[j][0]=milk[j+1][0];
                milk[j][1]=milk[j+1][1];
                milk[j+1][0]=tmp[0];
                milk[j+1][1]=tmp[1];
            }
        }
    }
    for(i=0;sum<n;i++){
        if(sum+milk[i][1]<=n){
            sum+=milk[i][1];
            money+=milk[i][0]*milk[i][1];
        }
        else{
            money+=(n-sum)*milk[i][0];
            sum=n;
        }
    }
    fprintf(fout,"%d\n",money);
    return 0;
}
