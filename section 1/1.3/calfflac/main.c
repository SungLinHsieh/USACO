/*
ID:john1991
TASK:calfflac
LANG:C
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    FILE *fin  = fopen("calfflac.in","r");
    FILE *fout = fopen("calfflac.out","w");

    char input[20000],tmp;
    
    int index[20000],li=0;
    int temp;
    int l=0;
    int i,j=0;
    int lp,right,left;
    int max[4]={0}; //length,locate,left,right
    float half;

    while(fscanf(fin,"%c",&tmp)!=EOF){
        input[l]=tmp;
        temp=(int)tmp;
        if((temp<=122 && temp >=97) || (temp<=90 && temp >= 65)){
            index[li]=l;
            li++;
        }
        l++;
    }
    for(i=1;i<2*li-2;i++){
        half=i;
        half=half/2;
        left=(int)floor(half-0.5);
        right=(int)ceil(half+0.5);
        //printf("1:left %d,right %d\n",left,right);
        //printf("1: i=%d left %d,rigt %d\n",i,left,right);
        while(input[index[left]]==input[index[right]] ||abs((int)input[index[left]]-(int)input[index[right]])==32){
            left--;
            right++;
            if(left==-1 || right == li)
                break;
        }
        left++;
        right--;
        if(right-left+1>max[0]){
            max[0]=right-left+1;
            max[1]=i;
            max[2]=left;
            max[3]=right;
            //printf("%d %d %d %d\n",max[0],max[1],max[2],max[3]);
        }
    }
    fprintf(fout,"%d\n",max[0]);
    for(i=index[max[2]];i<=index[max[3]];i++)
        fprintf(fout,"%c",input[i]);
    fprintf(fout,"\n");
    /*
    for(i=0;i<li;i++)
    {
        printf("%d %d %c\n",i,index[i],input[index[i]]);
    }
    */
    return 0;
}
