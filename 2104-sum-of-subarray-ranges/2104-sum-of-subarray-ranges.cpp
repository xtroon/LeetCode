class Solution {
public:
    
    // previous smaller element
    vector<int> PSE(vector<int>& nums){
        vector<int> ans(nums.size());
        stack<int> st;
        for(int i=0; i<nums.size(); i++){
            while(!st.empty() && nums[st.top()]> nums[i]) st.pop();

            ans[i] = st.empty()? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    // next smaller and equal element
    vector<int> NSEE(vector<int>& nums){
        vector<int> ans(nums.size());
        stack<int> st;
        for(int i=nums.size()-1; i>=0; i--){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();

            ans[i] = st.empty()? nums.size() : st.top();
            st.push(i);
        }
        return ans;
    }

    // previous greater element
    vector<int> PGE(vector<int>& nums){
        vector<int> ans(nums.size());
        stack<int> st;
        for(int i=0; i<nums.size(); i++){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();

            ans[i] = st.empty()? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    // next greater and equal element
    vector<int> NGEE(vector<int>& nums){
        vector<int> ans(nums.size());
        stack<int> st;
        for(int i=nums.size()-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();

            ans[i] = st.empty()? nums.size() : st.top();
            st.push(i);
        }
        return ans;
    }
    
    long long sumSubArrayMax(vector<int>& nums){
        long long int sum = 0;
        vector<int> left = PGE(nums);
        vector<int> right = NGEE(nums);

        for(int i=0; i<nums.size(); i++){
            int l = i - left[i];
            int r = right[i] - i;

            long long prod = (1LL * l * r * nums[i]);
            sum += prod;
        }
        return sum;
    }

    long long sumSubArrayMin(vector<int>& nums){
        long long int sum = 0;
        vector<int> left = PSE(nums);
        vector<int> right = NSEE(nums);

        for(int i=0; i<nums.size(); i++){
            int l = i - left[i];
            int r = right[i] - i;

            long long prod = (1LL * l * r * nums[i]);
            sum += prod;
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return ( sumSubArrayMax(nums) - sumSubArrayMin(nums));
    }
};