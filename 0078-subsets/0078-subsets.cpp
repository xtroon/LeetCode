class Solution {
public:
    void BCT(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums, int idx){
        //base case
        if(idx >= nums.size()){
            ans.push_back(curr);
            return;
        }

        //Include Next
        curr.push_back(nums[idx]);
        BCT(ans, curr, nums, idx+1);

        //backtrack
        curr.pop_back();

        //exclude next
        BCT(ans, curr, nums, idx+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        //calling recusive fxn
        BCT(ans, curr, nums, 0);

        //sorting
        sort(ans.begin(), ans.end());
        return ans;
    }
};