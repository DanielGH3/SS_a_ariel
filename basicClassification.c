int fact(int d);

int isPrime(int n){
    int flag = 1;
    for(int i = 2; i < n && flag; i++){
        if(n % i == 0)
            flag = 0;
    }
    return flag;
}

int isStrong(int n) {
    int temp = n;
    int sum = 0;

    while(n != 0){
        sum = sum + fact(n % 10);
        n /= 10;
    }
    
    return sum == temp;
}

int fact(int d){
    if(d == 1 || d == 0) return 1;
    return d * fact(d - 1);
}