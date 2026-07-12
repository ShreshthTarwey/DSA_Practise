class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int>mp;
        int n = arr.size();
        vector<int>temp = arr;
        sort(temp.begin(), temp.end());
        int rank = 1;
        for(int i=0;i<n;i++){
            if(mp.find(temp[i])==mp.end()){
                mp[temp[i]] = rank++;
            }
        }
        vector<int>result;
        for(int i=0;i<n;i++){
            result.push_back(mp[arr[i]]);
        }
        return result;
    }
};