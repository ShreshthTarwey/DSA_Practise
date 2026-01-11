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
    int maximalRectangle(vector<vector<char>>& matrix) {
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
};