class Solution {
public:
    void getComb(vector<int>& nums, int idx, int k, int n, vector<int>& curr, vector<vector<int>>& ans){

        if(curr.size() == k && n==0){
            ans.push_back(curr);
            return;
        }

        if(idx >= nums.size()) return;
        
        curr.push_back(nums[idx]);
        getComb(nums, idx+1, k, n-nums[idx], curr, ans);

        curr.pop_back();
        getComb(nums, idx+1, k, n, curr, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> curr;

        getComb(nums, 0, k, n, curr, ans);

        return ans;
    }
};