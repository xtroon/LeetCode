class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo= 0, hi = nums.size() -1;
        int ans = nums[lo];
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(nums[lo]==nums[mid] && nums[mid]==nums[hi]){
                ans = min(ans,nums[mid]);
                lo++;
                hi--;
                continue;
            }

            if(nums[mid] <= nums[hi]){
                ans = min(ans,nums[mid]);
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};