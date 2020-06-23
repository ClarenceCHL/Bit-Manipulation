#include<stdio.h>
#include<string.h>

unsigned short NUM;

void comp(int n){
    NUM = ( 1 << n ) ^ NUM;
}

void set(int n, int v){
    if(v == 1){
        NUM = ( 1 << n ) | NUM;
    } else {
        NUM = (~( 1 << n )) & NUM;
    }
}

int get(int n){
    int GetBit = ((NUM >> n) & 1);
    return GetBit;
}

int main(int argc, char* argv[])
{
    FILE* readfile = fopen(argv[1], "r");
    fscanf(readfile, "%hd\n", &NUM);
    int A, B;
    char str[5];
    
    while((!feof(readfile))){
        fscanf(readfile, "%s\t%d\t%d\n", str, &A, &B);
        switch (str[0]) {
            case 'c':
                comp(A);
                printf("%d\n", NUM);
                break;
            case 'g':
                printf("%d\n", get(A));
                break;
            case 's':
                set(A, B);
                printf("%d\n", NUM);
                break;
            default:
                break;
        }
    }
    fclose(readfile);
    return 0;
}
