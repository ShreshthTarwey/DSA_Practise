class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int>st;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && ((nums[i]<0 && st.top()>0))){
                if(!st.empty() && abs(st.top())<abs(nums[i])){
                    st.pop();
                }
                else if(abs(st.top()) == abs(nums[i])){
                    nums[i] = 0;
                    st.pop();
                    break;
                }
                else{
                    nums[i] = 0;
                    break;
                }
            }
            if(nums[i] != 0)
                st.push(nums[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};