
/*
ID:john1991
TASK:namenum
LANG:C
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
long int trans(char *name);
int main()
{
    long int n;
    int digit;
    char name[20];
    int length;
    int i,none;

    FILE *fin   = fopen("namenum.in","r");
    FILE *fout  = fopen("namenum.out","w");
    FILE *dict  = fopen("dict.txt","r");

    fscanf(fin,"%ld",&n);
    digit = floor(log10(n))+1;
    none = 1;

//    printf("%ld",trans("KRISTOPHER"));
    
    while(fscanf(dict,"%s",name)!=EOF)
    {
        length = strlen(name);
        if(length == digit)
            if(trans(name)==n)
            {
                fprintf(fout,"%s\n",name);
                none =0;
            }
    }
    if(none == 1)
        fprintf(fout,"NONE\n");
    return 0;
}
long int trans(char *name)
{
    long int result;
    int i,tmp;
    result = 0;
    for(i=0;i<strlen(name);i++)
    {
        tmp=name[i];
        if (tmp<81)
            result = result*10+floor((tmp-65)/3)+2;
        else if(tmp>81)
            result = result*10+floor((tmp-66)/3)+2;
    }
    return result;
}
