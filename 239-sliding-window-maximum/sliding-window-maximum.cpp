class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        int i=0;
        int j=k-1;
        while(j<nums.size()){
            ans.push_back(nums[dq.front()]);
            if(dq.front()==i){
                dq.pop_front();
            }
            i++;
            j++;
            if(j>=nums.size()){
                break;
            }
            while(!dq.empty() && nums[dq.back()]<nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);
        }
        return ans;
    }
};