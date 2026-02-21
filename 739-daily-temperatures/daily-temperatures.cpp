class Solution {
public:
    vector<int> mainMethod(vector<int>& arr){
        stack<int>st;
        vector<int>result(arr.size(),0);
        for(int i=arr.size()-1;i>=0;i--){
            // if(st.empty()){
            //     continue;
            // }
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                result[i] = st.top() - i;
            }
            st.push(i);
        }
        return result;
    }
    vector<int> dailyTemperatures(vector<int>& arr) {
        // return mainMethod(arr);
        //Revision
        stack<int>st;
        vector<int>ans(arr.size(), 0);
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top() - i;
            }
            st.push(i);

        }
        return ans;
    }
};