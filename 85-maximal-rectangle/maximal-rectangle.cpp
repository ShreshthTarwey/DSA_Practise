class Solution {
public:
    vector<int>getNSL(vector<int>& height){
        stack<int>st;
        vector<int>left(height.size());
        for(int i=0;i<height.size();i++){
            if(st.empty()){
                left[i] = -1;
            }
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }
            if(st.empty()){
                left[i] = -1;
            }
            else{
                left[i] = st.top();
            }
            st.push(i);
        }
        return left;
    }
    vector<int>getNSR(vector<int>& height){
        stack<int>st;
        vector<int>right(height.size());
        for(int i=height.size()-1;i>=0;i--){
            if(st.empty()){
                right[i] = height.size();
            }
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }
            if(st.empty()){
                right[i] = height.size();
            }
            else{
                right[i] = st.top();
            }
            st.push(i);
        }
        return right;
    }
    int findMaxArea(vector<int>& height){
        vector<int>NSL = getNSL(height);
        vector<int>NSR = getNSR(height);

        vector<int>width(height.size());
        for(int i=0;i<height.size();i++){
            width[i] = NSR[i] - NSL[i] - 1;
        }

        int maxArea = 0;
        for(int i=0;i<height.size();i++){
            int a = height[i] * width[i];
            maxArea = max(a, maxArea);
        }

        return maxArea;

    }
    int solution(vector<vector<char>>& matrix){
                int n = matrix.size();
        int m = matrix[0].size();
        vector<int>height(m);
        for(int i=0;i<m;i++){
            height[i] = (matrix[0][i] == '1') ? 1 : 0;
        }

        int maxArea = findMaxArea(height);

        for(int row = 1;row<n;row++){
            for(int col = 0;col<m;col++){
                if(matrix[row][col] == '0'){
                    height[col] = 0;
                }
                else{
                    height[col] += 1;
                }
            }
            maxArea = max(maxArea, findMaxArea(height));
        }
        return maxArea;
    }

    int largestAreaHistogram(vector<int>& heights){
        stack<int>st1, st2;
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
            int leftWidth = i - prevSmaller[i] - 1;
            int rightWidth = nextSmaller[i] - i - 1;
            int area = (leftWidth + 1 + rightWidth) * (heights[i]);
            ans = max(ans, area);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        // return solution(matrix);
        //---------------------------------------------Revision-----------------------------------------------

        vector<vector<int>>v(matrix.size(), vector<int>(matrix[0].size()));

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                v[i][j] = (matrix[i][j] - '0');
            }
        }

        int area = largestAreaHistogram(v[0]);
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(v[i][j] != 0)
                    v[i][j] += v[i-1][j];
            }
            area = max(area, largestAreaHistogram(v[i]));
        }
        return area;
    }
};