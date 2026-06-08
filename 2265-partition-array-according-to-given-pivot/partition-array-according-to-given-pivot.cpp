class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans;
        queue<int>q1, q2;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                q1.push(nums[i]);
            }
            else if(nums[i]>pivot){
                q2.push(nums[i]);
            }
            else{
                count++;
            }
        }
        while(!q1.empty()){
            ans.push_back(q1.front());
            q1.pop();
        }
        for(int i=0;i<count;i++){
            ans.push_back(pivot);
        }
        while(!q2.empty()){
            ans.push_back(q2.front());
            q2.pop();
        }
        return ans;
    }
};