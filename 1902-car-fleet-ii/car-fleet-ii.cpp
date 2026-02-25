class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double>ans(n, -1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            //Check if car in front is faster 
            while(!st.empty() && cars[st.top()][1]>=cars[i][1]){
                st.pop();
            }   

            //Checking collosion
            while(!st.empty()){
                double colTime = (double)(cars[st.top()][0] - (double)cars[i][0]) / (double)(cars[i][1] - cars[st.top()][1]);
                if(ans[st.top()] == -1 || colTime<=ans[st.top()]){
                    ans[i] = colTime;
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }


};