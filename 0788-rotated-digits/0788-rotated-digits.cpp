class Solution {
public:
    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i=1; i<=n; i++){
            int num = i;
            bool valid = true;
            bool same = false;
            while(num){
                int rem = num%10;

                if(rem == 7 || rem == 4 || rem == 3){
                    valid = false;
                    break;
                }
                if(rem == 2 || rem == 6 || rem == 5 || rem==9){
                    same = true;
                }

                num /= 10;
            }
            if(valid && same) cnt++;
        }
        return cnt;
    }
};