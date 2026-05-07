class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        vector<int> res(2, -1);
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;

            if(nums[mid] >= target){
                if(nums[mid] == target) res[0] = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }

        lo = 0, hi = nums.size() -1;
        while(lo <=hi){
            int mid = lo + (hi-lo)/2;

            if(nums[mid] <= target){
                if(nums[mid] == target) res[1] = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }

        return res;
    }
};