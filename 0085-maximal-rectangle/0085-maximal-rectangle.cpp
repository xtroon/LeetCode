class Solution {
public:
    //previous smallelst element
    vector<int> PSE(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i=0; i< n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();

            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }

    //next smallelst element
    vector<int> NSE(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n, n);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();

            if(st.empty()) ans[i] = n;
            else ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }

    // find largest sum
    int LargestSum(vector<int>& nums){
        int area = 0;

        vector<int> left = PSE(nums);
        vector<int> right = NSE(nums);

        for(int i=0; i<nums.size(); i++){
            int width = right[i] - left[i] - 1;
            
            area = max(area, width*nums[i]);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int ans = 0;

        int col = matrix[0].size();
        vector<int> height(col, 0);

        for(int i=0; i< matrix.size(); i++){
            for(int j=0; j< col; j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            ans = max(ans, LargestSum(height));
        }
        return ans;
    }
};