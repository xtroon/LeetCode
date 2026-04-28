class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        unordered_map<int, int> hash;

        for(int num : nums){
            hash[num]++;
        }

        for(auto it : hash){
            if(it.second > (n/3)) ans.push_back(it.first);
            if(ans.size() == 2) break;
        }

        return ans;

    }
};