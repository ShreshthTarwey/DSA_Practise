class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int i=0;
        int j = colors.size()-1;
        while(j>=0 && colors[i] == colors[j]){
            j--;
        }
        int ans = 0;
        if(j>=0)
            ans = max(ans, j-i);
        j = colors.size()-1;
        while(i<colors.size() && colors[i] == colors[j]){
            i++;
        }
        if(i<colors.size())
            ans = max(ans, j-i);
        return ans;
    }
};