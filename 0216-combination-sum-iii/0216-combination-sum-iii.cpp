class Solution {
public:
    void getComb(vector<int>& nums, int idx, int k, int n, vector<int>& curr, vector<vector<int>>& ans){
        //base cases
        if(curr.size() == k && n==0){
            ans.push_back(curr);
            return;
        }

        //optimised base case
        if(idx >= nums.size() || n<0 || curr.size() > k) return;

        // take it and move next
        curr.push_back(nums[idx]);
        getComb(nums, idx+1, k, n-nums[idx], curr, ans);

        //backtrack
        curr.pop_back();

        //don't take it and move next
        getComb(nums, idx+1, k, n, curr, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        //initialize nums
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        
        vector<vector<int>> ans;
        vector<int> curr;

        getComb(nums, 0, k, n, curr, ans);

        return ans;
    }
};