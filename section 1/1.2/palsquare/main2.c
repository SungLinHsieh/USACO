/*
ID:john1991
TASK:palsquare
LANG:C
*/
#include <stdio.h>
int main()
{
    FILE *fin  = fopen("palsquare.in","r");
    FILE *fout = fopen("palsquare.out","w");

    int base;
    int tmp;
    int i,j;
    int n[10],m[10],digit,digit2;
    int p,q; //Palindromic or not

    fscanf(fin,"%d",&base);

    for(i=1;i<=300;i++){
        p=1;
        q=1;
        digit=0;
        digit2=0;
        tmp=i;
        do{
            digit++;
            n[digit-1]=tmp%base;
            tmp=(tmp-tmp%base)/base;
        }while(tmp!=0);
        for(j=0;j<(digit/2);j++){
            if(n[j]!=n[digit-1-j]){
                p=0;
                break;
            }
        }
        if(p==1){
            tmp=i*i;
            do{
                digit2++;
                m[digit2-1]=tmp%base;
                tmp=(tmp-tmp%base)/base;
            }while(tmp!=0);
            for(j=0;j<(digit2/2);j++){
                if(m[j]!=m[digit2-1-j]){
                    q=0;
                    break;
                }
            }
            if(q==1){
                for(j=0;j<digit;j++)
                {
                    if(n[digit-j-1]<10)
                        fprintf(fout,"%d",n[digit-j-1]);
                    else
                        fprintf(fout,"%c",(char)(n[digit-j-1]+55));
                }
                fprintf(fout," ");
                for(j=0;j<digit2;j++)
                {
                    if(m[digit2-j-1]<10)
                        fprintf(fout,"%d",m[digit2-j-1]);
                    else
                        fprintf(fout,"%c",(char)(m[digit2-j-1]+55));
                }
                fprintf(fout,"\n");
            }
        }
    }
    return 0;
}
