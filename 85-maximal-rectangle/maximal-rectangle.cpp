class Solution {
public:
    int largestRectangle(vector<int>& arr){
        stack<int>st1,st2;
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
            while(!st2.empty() && arr[st2.top()]>=arr[i]){
                st2.pop();
            }
            if(!st2.empty()){
                nextSmaller[i] = st2.top();
            }
            st2.push(i);
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            int leftWidth = i - prevSmaller[i] - 1;
            int rightWidth = nextSmaller[i] - i - 1;

            ans = max(ans, (leftWidth + 1 + rightWidth)*arr[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>v(matrix.size(), vector<int>(matrix[0].size()));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                v[i][j] = (matrix[i][j] - '0');
            }
        }

        int area = largestRectangle(v[0]);
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(v[i][j]!=0){
                    v[i][j] += v[i-1][j];
                }
            }
            area = max(area, largestRectangle(v[i]));
        }
        return area;
    }
};