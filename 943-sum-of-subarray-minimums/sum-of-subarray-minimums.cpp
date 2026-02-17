class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        stack<int>st1, st2;
        int n = arr.size();
        vector<int>prevSmaller(n, -1);
        vector<int>nextSmaller(n, n);
        //PrevSmaller
        for(int i=0;i<n;i++){
            while(!st1.empty() && arr[st1.top()]>=arr[i]){
                st1.pop();
            }
            if(!st1.empty()){
                prevSmaller[i] = st1.top();
            }
            st1.push(i);
        }
        //nextSmaller
        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && arr[st2.top()]>arr[i]){
                st2.pop();
            }
            if(!st2.empty()){
                nextSmaller[i] = st2.top();
            }
            st2.push(i);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            long long leftCount = i - prevSmaller[i];
            long long rightCount = nextSmaller[i] - i;
            long long total = ((leftCount * rightCount)%MOD * 1ll*arr[i]) % MOD;
            ans = (total + ans)%MOD;
        }
        return ans;

    }
};