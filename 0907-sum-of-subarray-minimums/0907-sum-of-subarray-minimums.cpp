class Solution {
public:
    vector<int> NRSE(vector<int>&arr, int n){
        vector<int> ans(n,n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            if(st.empty()) ans[i] = n;
            else ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }

    vector<int> NLSE(vector<int>&arr, int n){
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> NRS = NRSE(arr, n);
        vector<int> NLS = NLSE(arr, n);

        long long int sum = 0;
        int modulo = 1e9 + 7;

        for(int i = 0; i<n; i++){   
            int lhs = (i - NLS[i]);
            int rhs = (NRS[i] - i);

            long long prod = (1LL* lhs* rhs* arr[i])%modulo;
            sum = sum + prod;
        }

        return sum%modulo;

    }
};