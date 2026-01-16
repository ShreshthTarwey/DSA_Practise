class Solution {
public:
    void fillMap(vector<int>& arr, unordered_set<int>& mp){
        sort(arr.begin(), arr.end());
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                // if(i==j) continue;
                mp.insert(arr[j]-arr[i]);
            }
        }
    }
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_set<int>lengths;
        unordered_set<int>widths;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        fillMap(hFences, lengths);
        fillMap(vFences, widths);
        long long maxAns = -1;
        for(auto it: lengths){
            if(widths.find(it)!=widths.end()){
                maxAns = max(maxAns, (long long)it);
            }
        }
        if(maxAns==-1) return -1;
        return (maxAns * maxAns) % 1000000007;
    }
};