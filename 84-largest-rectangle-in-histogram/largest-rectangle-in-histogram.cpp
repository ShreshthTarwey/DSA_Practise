class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st1;
        stack<int>st2;
        int n = heights.size();
        vector<int>prevSmaller(n, -1);
        vector<int>nextSmaller(n, n);

        //Filling prevSmaller

        for(int i=0;i<n;i++){
            while(!st1.empty() && heights[st1.top()]>=heights[i]){
                st1.pop();
            }
            if(!st1.empty()){
                prevSmaller[i] = st1.top();
            }
            st1.push(i);
        }

        //Filling nextSmaller

        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && heights[st2.top()]>=heights[i]){
                st2.pop();
            }
            if(!st2.empty()){
                nextSmaller[i] = st2.top();
            }
            st2.push(i);
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            int leftWidth = i-prevSmaller[i]-1;
            int rightWidth = nextSmaller[i] - i - 1;
            int area = (leftWidth + 1 + rightWidth) * (heights[i]);
            ans = max(ans, area);
        }
        return ans;
    }
};