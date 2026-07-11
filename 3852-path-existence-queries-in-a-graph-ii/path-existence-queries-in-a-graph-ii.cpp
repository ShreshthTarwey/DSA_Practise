class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>>ancestor;
    int customUpperBound(vector<pair<int, int>>& arr, int target){
        int n = arr.size();
        int l = 0;
        int r = n-1;
        int result = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(arr[mid].first<=target){
                result = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return result;
    }
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>>arr(n);
        for(int i=0;i<n;i++){
            arr[i] = {nums[i], i};
        }
        sort(arr.begin(), arr.end());
        //Now Map arr index for fast lookups
        vector<int>nodeTo(n);
        for(int i=0;i<n;i++){
            int node = arr[i].second;
            nodeTo[node] = i;
        }
        //Creating and filling ancestor table
        rows = n;
        cols = log2(n)+1;
        ancestor.resize(rows, vector<int>(cols, 0));

        //filling 0th col
        for(int node=0;node<n;node++){
            int farthest = customUpperBound(arr, arr[node].first+maxDiff);
            ancestor[node][0] = farthest;
        }

        //filling the remaining columns
        for(int j=1;j<cols;j++){
            for(int node=0;node<n;node++){
                ancestor[node][j] = ancestor[ ancestor[node][j-1] ][j-1];
            }
        }
        
        //Filling the result vector
        vector<int>result;
        for(auto &it: queries){
            int u = it[0];
            int v = it[1];

            int a = nodeTo[u];
            int b = nodeTo[v];

            if(a==b){
                result.push_back(0);
                continue;
            }
            if(a>b){
                swap(a,b);
            }
            //Confused part-> I am still a little confused in this portion
            int curr = a;
            int jumps = 0;
            //Trying to place curr at the farthest position possible
            for(int j=cols-1;j>=0;j--){
                if(ancestor[curr][j] < b){
                    curr = ancestor[curr][j];
                    jumps += (1<<j);
                }
            }
            if(ancestor[curr][0]>=b){
                result.push_back(jumps+1);
            }
            else{
                result.push_back(-1);
            }
        }
        return result;
    }
};