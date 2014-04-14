/*
ID:john1991
TASK:dualpal
LANG:C
*/
#include <stdio.h>
int main()
{
    int n,s,num;
    int count=0;
    int i,j,number[20],digit,tmp;
    int p; //count for palindromes
    int q; //palindromes or not

    FILE *fin  = fopen("dualpal.in","r");
    FILE *fout = fopen("dualpal.out","w");

    fscanf(fin,"%d %d",&n,&s);

    num = s+1;
    do{
        p=0;
        for(i=2;i<11;i++){
            if(p==2 || (i==10 && p==0))
                break;
            else{
                q=1;
                digit=0;
                tmp=num;
                do{
                    digit++;
                    number[digit-1]=tmp%i;
                    tmp=(tmp-tmp%i)/i;
                }while(tmp!=0);
                for(j=0;j<(digit/2);j++){
                    if(number[j]!=number[digit-1-j]){
                        q=0;
                        break;
                    }
                }
                if(q==1)
                    p++;
            }
        }
        if(p==2)
        {
            fprintf(fout,"%d\n",num);
            count++;
        }
        num++;
    }while(count<n);
    
    return 0;
}
