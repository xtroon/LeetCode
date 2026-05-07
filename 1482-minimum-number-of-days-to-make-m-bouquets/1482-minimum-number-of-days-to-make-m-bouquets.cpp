class Solution {
public:
    // to check if is possible to make
    bool check(vector<int>& arr, int day, int m, int k) {
        int cnt = 0, btq = 0;

        for(int i=0; i< arr.size(); i++){
            if(arr[i] <= day){
                cnt++;
                if(cnt == k){
                    btq++;
                    cnt = 0;
                }
            } 
            else{
                cnt = 0;
            }
        }
        return btq >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL * m * k > bloomDay.size()) return -1;

        // real bs fxn
        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());

        while(lo <= hi){
            int mid = lo + (hi-lo)/2;

            bool res = check(bloomDay, mid, m, k);

            if(res) hi = mid-1;
            else lo = mid + 1;
        }
        return lo;
    }
};