int reverse(int n);
int myPow(int x, int a);

int isArmstrong(int n){
    int temp = n;
    int sum = 0;

    int digits = 0;
    while(n != 0) {
        n /= 10;
        digits++;
    }

    n = temp;
    while(n != 0){
        sum = sum + myPow(n % 10, digits);
        n /= 10;
    }

    return sum == temp;
}

int isPalindrome(int n){
    int rev = reverse(n);
    return n == rev;
}

int reverse(int n){
    int ret = 0;

    while(n != 0){
        ret = ret * 10 + n % 10;
        n /= 10;
    }
    return ret;
}

//x^a
int myPow(int x, int a){
    int ret = 1;
    while(a-- > 0){
        ret *= x;
    }
    return ret;
}