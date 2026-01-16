class Solution {
public:
    void fillMap(vector<int>& arr, unordered_map<int, int>& mp){
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr.size();j++){
                if(i==j) continue;
                mp[abs(arr[i]-arr[j])]++;
            }
        }
    }
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_map<int, int>lengths;
        unordered_map<int, int>widths;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        fillMap(hFences, lengths);
        fillMap(vFences, widths);
        long long maxAns = -1;
        for(auto it: lengths){
            if(widths.find(it.first)!=widths.end()){
                maxAns = max(maxAns, (long long)it.first);
            }
        }
        if(maxAns==-1) return -1;
        return (maxAns * maxAns) % 1000000007;
    }
};