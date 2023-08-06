// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    while(b > 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int power(int base, int exp, int mod){
    unsigned long long int result = 1;
    for(int i=1; i <= exp; i++){
        result = (result * base) % mod;
    }
    return result;
}

int isPrime(int n){
    int i = 1;
    int k = 100;
    if(n <= 1  || n == 4)
        return 0;
    if(n == 2 || n == 3)
        return 1;
    while(i <= k){
        int a = 2 + rand() % (n - 3);
        if(gcd(a,n) != 1)
            return 0;
        if(power(a,n-1,n) != 1)
            return 0;
        i++;
    }
    return 1;
}

int main() {
    // Write C++ code here
    int n;
    cout << "Enter the Number: ";
    cin >> n;
    
    if(isPrime(n))
        cout << n << " is a prime number.";
    else
        cout << n << " is not a prime number.";
    

    return 0;
}