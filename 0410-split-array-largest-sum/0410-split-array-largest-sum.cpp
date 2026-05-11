class Solution {
public:
    
    int check(vector<int>& nums, int k, int mid){
        int NoOfSubAry = 1;
        int sum =  0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > mid) return false;

            if(nums[i] + sum <= mid){
                sum += nums[i];
            }
            else{
                NoOfSubAry++;
                if(NoOfSubAry > k) return false;
                sum = nums[i];
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        if(nums.size() < k) return -1;
        int lo = *max_element(nums.begin(), nums.end());
        int sum = 0;
        for(int x : nums) sum += x;
        int hi = sum;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(check(nums, k, mid)){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return lo;
    }
};