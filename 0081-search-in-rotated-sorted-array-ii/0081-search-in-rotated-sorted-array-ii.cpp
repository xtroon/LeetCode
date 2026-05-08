class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(nums[mid] == target) return true;

            if(nums[mid] == nums[lo] && nums[mid] == nums[hi]){
                lo++;
                hi--;
            } 

            else if(nums[mid] <= nums[hi]){
                if(nums[mid]< target && target<=nums[hi]) lo = mid + 1;
                else hi = mid -1;
            }
            else{
                if(nums[mid] > target && nums[lo] <= target){
                    hi = mid -1;
                }
                else lo = mid + 1;
            }
        }
        return false;
    }
};