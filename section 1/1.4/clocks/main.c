/*
ID:john1991
TASK:clocks
LANG:C
*/
#include <stdio.h>
int main()
{
    FILE *fin  = fopen("clocks.in","r");
    FILE *fout = fopen("clocks.out","w");

    int i,j,k=0,tmp,n=0;
    int clock[10];
    int result[10];

    for(i=0;i<9;i++)
    {
        fscanf(fin,"%d",&tmp);
        clock[i]=4-tmp/3;
    }
    result[0]=(3*clock[0]+2*clock[1]+3*clock[2]+2*clock[3]+2*clock[4]+1*clock[5]+3*clock[6]+1*clock[7]+0*clock[8])%4;
    result[1]=(3*clock[0]+3*clock[1]+3*clock[2]+3*clock[3]+3*clock[4]+3*clock[5]+2*clock[6]+0*clock[7]+2*clock[8])%4;
    result[2]=(3*clock[0]+2*clock[1]+3*clock[2]+1*clock[3]+2*clock[4]+2*clock[5]+0*clock[6]+1*clock[7]+3*clock[8])%4;
    result[3]=(3*clock[0]+3*clock[1]+2*clock[2]+3*clock[3]+3*clock[4]+0*clock[5]+3*clock[6]+3*clock[7]+2*clock[8])%4;
    result[4]=(3*clock[0]+2*clock[1]+3*clock[2]+2*clock[3]+1*clock[4]+2*clock[5]+3*clock[6]+2*clock[7]+3*clock[8])%4;
    result[5]=(2*clock[0]+3*clock[1]+3*clock[2]+0*clock[3]+3*clock[4]+3*clock[5]+2*clock[6]+3*clock[7]+3*clock[8])%4;
    result[6]=(3*clock[0]+1*clock[1]+0*clock[2]+2*clock[3]+2*clock[4]+1*clock[5]+3*clock[6]+2*clock[7]+3*clock[8])%4;
    result[7]=(2*clock[0]+0*clock[1]+2*clock[2]+3*clock[3]+3*clock[4]+3*clock[5]+3*clock[6]+3*clock[7]+3*clock[8])%4;
    result[8]=(0*clock[0]+1*clock[1]+3*clock[2]+1*clock[3]+2*clock[4]+2*clock[5]+3*clock[6]+2*clock[7]+3*clock[8])%4;

    for(i=0;i<9;i++)
        n+=result[i];

    for(i=0;i<9;i++){
        for(j=0;j<result[i];j++){
            fprintf(fout,"%d",i+1);
            k++;
            if(k<n)
                fprintf(fout," ");
        }
    }
    fprintf(fout,"\n");
    return 0;
}
