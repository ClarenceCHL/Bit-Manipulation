int get(short int x, int n){
    int GetBit = ((x >> n) & 1);
    return GetBit;
}

int main(int argc, char* argv[])
{
    unsigned short Num = atoi(argv[1]);
    int k;
    for(k=0; k<8; k++){
        if(get(Num, 15-k) != get(Num, k)){
            printf("Not-Palindrome\n");
            return 0;
        }
    }
    printf("Is-Palindrome\n");
    return 0;
}
