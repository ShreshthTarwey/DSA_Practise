class Solution {
public:
    int maxAreaHistogram(vector<int>& arr){
        int n = arr.size();
        vector<int>prevSmaller(n, -1);
        vector<int>nextSmaller(n, n);

        stack<int>st1,st2;

        //filling prevSmaller
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

        int ans = INT_MIN;

        for(int i=0;i<n;i++){
            int leftWidth = i - prevSmaller[i] - 1;
            int rightWidth = nextSmaller[i] - i - 1;

            ans = max(ans, (leftWidth + 1 + rightWidth)*arr[i]);
        }
        return ans;
    }
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>temp2 = matrix[0];
        sort(temp2.rbegin(), temp2.rend());
        int area = maxAreaHistogram(temp2);
        for(int i=1;i<n;i++){
            vector<int>temp;
            for(int j=0;j<m;j++){
                if(matrix[i][j] != 0){
                    temp.push_back(matrix[i][j] + matrix[i-1][j]);
                    matrix[i][j] += matrix[i-1][j];
                }
                else{
                    temp.push_back(0);
                }
            }
            sort(temp.begin(), temp.end(), greater<int>());
            area = max(area, maxAreaHistogram(temp));
        }
        return area;
    }
};