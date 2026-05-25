class Solution {
public:
    const int Mod = 1e9 + 7;
    long long findPower(long long a, long long b){
        if( b == 0) return 1;

        long long half = findPower(a, b/2);
        long long res = (half * half)%Mod;

        if(b%2  == 1) res = (res*a)%Mod;
        return res;
    }
    int countGoodNumbers(long long n) {
        long long evenDig = (n+1)/2;
        long long oddDig = n/2;

        int res = findPower(5,evenDig)* findPower(4, oddDig) % Mod;
        return res;
    }
};