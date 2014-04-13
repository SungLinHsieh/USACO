#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fin = fopen("dict.txt","r");
    char s[20];
    int d;
    fscanf(fin,"%s",s);
    printf("%s\n",s);
    d = strlen(s);
    printf("%d\n",d);
    return 0;
}
