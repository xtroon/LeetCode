class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lo = 0, hi = arr.size() - 1;

        while(lo <= hi){
            int mid = lo + (hi-lo)/2;

            // tell abt no. of msing elemts
            int miss = arr[mid] - (mid+1);

            if(miss < k){
                lo = mid + 1; //  move right to find more miss no.
            }
            else{
                hi = mid - 1; // mov left to find smalest
            }
        }   

        return hi + k + 1;
        // return lo + k;
    }
};