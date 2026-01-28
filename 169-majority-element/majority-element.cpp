class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int counter = 1;
        for(int i=1;i<nums.size();i++){
            if(majority == nums[i]){
                counter+=1;
            }
            else{
                counter -= 1;
            }
            if(counter == -1){
              majority = nums[i];
              counter = 1;  
            } 
        }
        return majority;
    }
};