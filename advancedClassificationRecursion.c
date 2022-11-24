int calcArmstrongSum(int n, int digits);
int getDigitCount(int n);
int reverse(int n);
int myPow(int x, int a);

int isArmstrong(int n){
    int digits = getDigitCount(n);
    int sum = calcArmstrongSum(n, digits);
    return sum == n;
}

int armstrong_sum = 0;
int calcArmstrongSum(int n, int digits){
    if(n == 0) {
        int tmp = armstrong_sum;
        armstrong_sum = 0;
        return tmp;
    }

    armstrong_sum = armstrong_sum + myPow(n % 10, digits);
    return calcArmstrongSum(n / 10, digits);  
}

int getDigitCount(int n){
    if(n == 0) return 0;
    return 1 + getDigitCount(n / 10);
}

int isPalindrome(int n){
    int rev = reverse(n);
    return n == rev;
}

int reverse_sum = 0;
int reverse(int n){
    if(n == 0) {
        int tmp = reverse_sum;
        reverse_sum = 0;
        return tmp;
    }

    reverse_sum = reverse_sum * 10 + n % 10;
    return reverse(n / 10);    
}

//x^a
int myPow(int x, int a){
    if(a == 0 || a == 1) return 1;
    return x * myPow(x, a - 1);
}