class Solution {
public:
    double calcPow(double x, long long num){
        if(num == 0) return 1;
        if(num == 1) return x;

        double half = calcPow(x, num/2);

        if(num%2 == 0) return half*half;
        else return x* half*half;

    }

    double myPow(double x, int n) {
        long long num = n;

        if(num < 0){
            x = 1/x;
            num = -num;
        }

        return calcPow(x, num);
    }
};