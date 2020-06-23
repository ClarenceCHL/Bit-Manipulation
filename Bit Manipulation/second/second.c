int get(unsigned short int x, int n){
    int GetBit = ((x >> n) & 1);
    return GetBit;
}

int CountPairs(unsigned short int x){
    int pairs = 0;
    int i;
    for(i=0; i<16; i++){
        if(get(x, i) == 1 && get(x, i+1) == 1){
            pairs++;
            i++;
        } else {
            continue;
        }
    }
    return pairs;
}

int Parity(unsigned short int x){
    int a = 0;
    while(x){
        a += x & 1;
        x >>= 1;
    }
    return a;
}

int main(int argc, char* argv[])
{
    unsigned short NUM = atoi(argv[1]);
    if(Parity(NUM) % 2 == 1){
        printf("Odd-Parity\t%d\n", CountPairs(NUM));
    } else if(Parity(NUM) % 2 == 0){
        printf("Even-Parity\t%d\n", CountPairs(NUM));
    }
    return 0;
}
