class Solution {
public:
    int minimumPushes(string word) {
        vector<int>count(26, 0);
        for(char c: word){
            count[c - 'a']++;
        }
        vector<vector<int>>arr;
        for(int i=0;i<26;i++){
            if(count[i]){
                arr.push_back({count[i], i+'a'});
            }
        }
        sort(arr.begin(), arr.end(), greater<>());
        int i = 1;
        int cost = 0;
        int num = 0;
        for(int j=0;j<arr.size();j++){
            if(num == 8){
                i++;
                num = 0;
            }
            cost += count[arr[j][1] - 'a'] * i;
            num++;
        }
        return cost;
    }
};