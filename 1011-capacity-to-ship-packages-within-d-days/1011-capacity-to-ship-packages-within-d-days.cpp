class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = 0;
        for( int it : weights){
            hi += it;
        }

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            int d = 1, load = 0;
            for(int i=0; i<weights.size(); i++){
                if(load + weights[i] > mid){
                    d++;
                    load = weights[i];
                }
                else{
                    load += weights[i];
                }
            }

            if(d <= days) hi = mid - 1;
            else lo = mid + 1;
        }
        return lo;
    }
};