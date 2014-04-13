/*
ID:john1991
TASK:transform
LANG:C
*/
#include <stdio.h>
#include <stdlib.h>

int check(int *data_in,int *data_out,int i_in,int j_in,int i_out,int j_out,int n);
int rotated_i(int j,int n);
int rotated_j(int i);
int reflected_j(int j,int n);

int ro_90(int *data_in, int *data_out, int i_in, int j_in, int n);
int ro_180(int *data_in, int *data_out, int i_in, int j_in, int n);
int ro_270(int *data_in, int *data_out, int i_in, int j_in, int n);
int reflect(int *data_in, int *data_out, int i_in, int j_in, int n);
int re_90(int *data_in, int *data_out, int i_in, int j_in, int n);
int re_180(int *data_in, int *data_out, int i_in, int j_in, int n);
int re_270(int *data_in, int *data_out, int i_in, int j_in, int n);
int identical(int *data_in, int *data_out, int i_in, int j_in, int n);

int main()
{
    int n,i,j;
    char ele_tmp;
    int *data_in,*data_out;
    //int data_in[100], data_out[100];
    int survive[8];
    FILE *fin   = fopen("transform.in","r");
    FILE *fout  = fopen("transform.out","w");

    fscanf(fin,"%d",&n);
    data_in = (int*)malloc(n*n*sizeof(int));
    data_out= (int*)malloc(n*n*sizeof(int));
    fscanf(fin,"%c",&ele_tmp);
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
        {
            fscanf(fin,"%c",&ele_tmp);
            if(ele_tmp=='@'){
                data_in[i*n+j]=0;
            }
            else if(ele_tmp=='-'){
                data_in[i*n+j]=1;
            }
        }
    }
    /*
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d",data_in[i*n+j]);
        printf("\n");
    }
    */
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
        {
            fscanf(fin,"%c",&ele_tmp);
            //printf("%c", ele_tmp);
            //printf("%d", data_in[4]);
            if(ele_tmp=='@')
                data_out[i*n+j]=0;
            else if(ele_tmp=='-')
                data_out[i*n+j]=1;
            //printf("%d", data_in[4]);
        }
    }
/*
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d",data_out[i*n+j]);
        printf("\n");
    }
*/
    
    for(i=0;i<8;i++)
        survive[i]=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(survive[0]==1)
                if(!ro_90(data_in,data_out,i,j,n))
                    survive[0]=0;
            if(survive[1]==1)
                if(!ro_180(data_in,data_out,i,j,n))
                    survive[1]=0;
            if(survive[2]==1)
                if(!ro_270(data_in,data_out,i,j,n))
                    survive[2]=0;
            if(survive[3]==1)
                if(!reflect(data_in,data_out,i,j,n))
                    survive[3]=0;
            if(survive[4]==1)
                if(!re_90(data_in,data_out,i,j,n))
                    survive[4]=0;
            if(survive[5]==1)
                if(!re_180(data_in,data_out,i,j,n))
                    survive[5]=0;
            if(survive[6]==1)
                if(!re_270(data_in,data_out,i,j,n))
                    survive[6]=0;
            if(survive[7]==1)
                if(!identical(data_in,data_out,i,j,n))
                    survive[7]=0;
        }
    }
    if(survive[0]==1)
            fprintf(fout,"%d",1);
    else if(survive[1]==1)
            fprintf(fout,"%d",2);
    else if(survive[2]==1)
            fprintf(fout,"%d",3);
    else if(survive[3]==1)
            fprintf(fout,"%d",4);
    else if(survive[4]+survive[5]+survive[6]!=0)
            fprintf(fout,"5");
    else if(survive[7]==1)
            fprintf(fout,"6");
    else
            fprintf(fout,"7");

    fprintf(fout,"\n");
    /*
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d",data_in[i*n+j]);
        printf("\n");
    }
    */
    return 0;
}
int check(int *data_in,int *data_out,int i_in,int j_in,int i_out,int j_out,int n)
{
    return (data_in[i_out*n+j_out]==data_out[i_in*n+j_in]);
}
int rotated_i(int j,int n)
{
    return n-1-j;
}
int rotated_j(int i)
{
    return i;
}   
int reflected_j(int j,int n)
{
    return n-1-j;
}

int ro_90(int *data_in, int *data_out, int i_in, int j_in, int n)
{
    int i_out, j_out;
    i_out = rotated_i(j_in, n);
    j_out = rotated_j(i_in);
//    if (!check(data_in, data_out, i_in, j_in, i_out, j_out, n))
//        printf("i_in %d, j_in %d, i_out %d, j_out %d\n", i_in, j_in, i_out, j_out);

    return check(data_in, data_out, i_in, j_in, i_out, j_out, n);
}
int ro_180(int *data_in, int *data_out, int i_in, int j_in, int n){
    int i_out, j_out;
    i_out = rotated_i(rotated_j(i_in), n);
    j_out = rotated_j(rotated_i(j_in, n));
    return check(data_in, data_out, i_in, j_in, i_out, j_out, n);
}
int ro_270(int *data_in, int *data_out, int i_in, int j_in, int n){
    int i_out, j_out;
    i_out = rotated_i(rotated_j(rotated_i(j_in,n)), n);
    j_out = rotated_j(rotated_i(rotated_j(i_in), n));
    return check(data_in, data_out, i_in, j_in, i_out, j_out, n);
}
int reflect(int *data_in, int *data_out, int i_in, int j_in, int n){
    return check(data_in, data_out, i_in, j_in, i_in, reflected_j(j_in, n), n);
}
int re_90(int *data_in, int *data_out, int i_in, int j_in, int n){
    int i_out, j_out;
    i_out = rotated_i(j_in, n);
    j_out = reflected_j(rotated_j(i_in),n);
    return check(data_in, data_out, i_in, j_in, i_out, j_out, n);
}
int re_180(int *data_in, int *data_out, int i_in, int j_in, int n){
    int i_out, j_out;
    i_out = rotated_i(rotated_j(i_in), n);
    j_out = reflected_j(rotated_j(rotated_i(j_in, n)),n);
    return check(data_in, data_out, i_in, j_in, i_out, j_out, n);
}
int re_270(int *data_in, int *data_out, int i_in, int j_in, int n){
    int i_out, j_out;
    i_out = rotated_i(rotated_j(rotated_i(j_in,n)), n);
    j_out = reflected_j(rotated_j(rotated_i(rotated_j(i_in), n)),n);
    return check(data_in, data_out, i_in, j_in, i_out, j_out, n);
}
int identical(int *data_in, int *data_out, int i_in, int j_in, int n){
    return check(data_in, data_out, i_in, j_in, i_in, j_in, n);
}
