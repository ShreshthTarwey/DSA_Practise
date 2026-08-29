class Solution {
public:
    vector<int> bruteForce(vector<int>& nums, int limit){
        int n = nums.size();
        for(int i=0;i<n;i++){
            int num = nums[i];
            bool flag = false;
            for(int j=i+1;j<n;j++){
                if(num>nums[j] && abs(num - nums[j])<=limit){
                    flag = true;
                    swap(nums[i], nums[j]);
                    break;
                }
            }
            if(flag){
                i--;
            }
        }
        return nums;
    }
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // return bruteForce(nums, limit);
        //Optimized ------------------------------------------------------------------
        vector<int>vec = nums;
        int n = nums.size();
        sort(vec.begin(), vec.end());
        unordered_map<int, list<int>>groupToVec;
        unordered_map<int, int>numToGroup;
        int groupNum = 0;

        groupToVec[groupNum].push_back(vec[0]);
        numToGroup[vec[0]] = groupNum;

        for(int i=1;i<n;i++){
            if(abs(vec[i] - vec[i-1])>limit){
                groupNum++;
            }
            groupToVec[groupNum].push_back(vec[i]);
            numToGroup[vec[i]] = groupNum;
        }

        vector<int>result(n);
        for(int i=0;i<n;i++){
            int num = nums[i];
            int group = numToGroup[num];
            int element = *(groupToVec[group].begin());
            result[i] = element;
            groupToVec[group].pop_front();
        }
        return result;
    }
};