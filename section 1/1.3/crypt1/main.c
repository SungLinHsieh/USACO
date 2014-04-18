/*
ID:john1991
TASK:crypt1
LANG:C
*/
#include <stdio.h>
int contain(int num,int d,int *number,int n);
int main()
{
    FILE *fin  = fopen("crypt1.in","r");
    FILE *fout = fopen("crypt1.out","w");

    int n,number[9];
    int i,j,k,s=0,p=-1;
    int hund[1000],p3[1000][11],l=0,rec[1000][10][2];
    int sum=0,tmp;

    fscanf(fin,"%d",&n);
    for(i=0;i<n;i++)
        fscanf(fin,"%d",&number[i]);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                hund[n*n*i+n*j+k]=100*number[i]+10*number[j]+number[k];
            }
        }
    }
//    for(i=0;i<n;i++)
//        printf("%d %d\n",i,number[i]);
//    for(i=0;i<n*n*n;i++)
//        printf("%d\n",hund[i]);
//    printf("%d\n",contain(222,3,number,n));
    for(i=0;i<n*n*n;i++){
        s=0;
        for(j=0;j<n;j++){
            tmp=hund[i]*number[j];
            if(tmp<1000 && tmp>110){
                if(contain(tmp,3,number,n)){
                    if(s==0){
                        s=1;
                        p++;
                        p3[p][0]=0;
                    }
                    p3[p][0]++;
                    p3[p][p3[p][0]]=tmp;
                    rec[p][p3[p][0]][0]=i;
                    rec[p][p3[p][0]][1]=j; 
                }
            }
        }
    }
//    for(i=0;i<=p;i++)
//        for(j=1;j<=p3[i][0];j++)
//            printf("%d * %d = %d\n",hund[rec[i][j][0]],number[rec[i][j][1]],p3[i][j]);
//    printf("\n");
    for(i=0;i<=p;i++){
        for(j=1;j<=p3[i][0];j++){
            for(k=1;k<=p3[i][0];k++){
                tmp=10*p3[i][j]+p3[i][k];
                if(tmp<10000 && tmp>1110){
                    if(contain(tmp,4,number,n)){
                        sum++;
                        //printf("%d , %d = %d\n",p3[i][j],p3[i][k],tmp);
                    }
                }
            }
        }
    }

    fprintf(fout,"%d\n",sum);

    return 0;
}
int contain(int num,int d,int *number,int n)
{
    int i,j;
    int check=0;
    for(i=1;i<=d;i++){
        check=0;
        for(j=0;j<n;j++){
            if(num%10==number[j]){
                check=1;
                break;
            }
        }
        num=(num-num%10)/10;
        if(check==0)
            break;
    }
    return check;
}
