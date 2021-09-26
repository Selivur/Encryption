#include <stdio.h>
int main()
{
    char key[10];
    char *p, c;
    FILE *fp1, *fp2;
    char f1[10], f2[10];
    printf("\n Source file:  ");
    scanf("%s", f1);
    printf("\n File for crypt: ");
    scanf("%s", f2);
    printf("\n Enter key: ");
    scanf("%s", key);
    if ((fp1 = fopen(f1, "rb")) == NULL)
    {
        printf("\n Error %s", f1);
        return 0;
    }
    fp2 = fopen(f2, "wb");
    p = key;
    while ((c = getc(fp1)) != EOF)
    {
        putchar(c ^ *p); 
        putc(c ^ *p, fp2);
        if (!*++p)
            p = key;
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
