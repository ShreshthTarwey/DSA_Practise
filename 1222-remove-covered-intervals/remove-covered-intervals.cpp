class Solution {
public:
    static bool comp(vector<int>&a, vector<int>& b){
        if(a[0]<b[0]){
            return true;
        }
        if(a[0]>b[0]){
            return false;
        }
        if(a[1]>b[1]){
            return true;
        }
        return true;
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        stack<pair<int, int>>st;
        for(auto &it: intervals){
            int a = it[0];
            int b = it[1];
            if(st.empty()){
                st.push({a, b});
                continue;
            }
            int c = st.top().first;
            int d = st.top().second;
            if(a>=c && b<=d){
                continue;
            }
            st.push({a, b});
        }
        return st.size();
    }
};