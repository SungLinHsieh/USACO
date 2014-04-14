
/*
ID:john1991
TASK:namenum
LANG:C
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int digit,temp;
    char tmp;
    char name[20],numofname[20],number[20];
    int length;
    int i,none;
    int f;

    FILE *fin   = fopen("namenum.in","r");
    FILE *fout  = fopen("namenum.out","w");
    FILE *dict  = fopen("dict.txt","r");

    fscanf(fin,"%s",number);
    digit=strlen(number);
    
    none = 1;

    while(fscanf(dict,"%s",name)!=EOF)
    {
        length = strlen(name);
        if(length == digit)
        {
            for(i=0;i<digit;i++)
            {
                temp=name[i];
                if (temp<81)
                {   
                    f = floor((temp-65)/3)+2;
                    numofname[i]=(char)(f+48);
                }
                else if(temp>81)
                {   
                    f = floor((temp-66)/3)+2;
                    numofname[i]=(char)(f+48);
                }
            }
            if(strncmp(numofname,number,digit)==0)
            {
                fprintf(fout,"%s\n",name);
                none =0;
            }
        }
    }
    if(none == 1)
        fprintf(fout,"NONE\n");
    return 0;
}
