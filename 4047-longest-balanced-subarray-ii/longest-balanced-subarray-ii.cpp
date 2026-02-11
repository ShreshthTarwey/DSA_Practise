class Solution {
public:
    vector<int> segMin, segMax, lazy;
    int n;

    void propagate(int i, int l, int r) {
        if (lazy[i] != 0) {
            segMin[i] += lazy[i];
            segMax[i] += lazy[i];

            if (l != r) {
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i] = 0;
        }
    }

    // Range add val to [start, end]
    void updateRange(int start, int end, int i, int l, int r, int val) {
        propagate(i, l, r); //make sure to propagate before hand

        if (l > end || r < start) return;

        //[start...end[ is fully inside range of current node [l..r]
        if (l >= start && r <= end) {
            lazy[i] += val;
            propagate(i, l, r);
            return;
        }

        int mid = (l + r) / 2;
        updateRange(start, end, 2*i+1, l, mid, val);
        updateRange(start, end, 2*i+2, mid+1, r, val);

        segMin[i] = min(segMin[2*i+1], segMin[2*i+2]);
        segMax[i] = max(segMax[2*i+1], segMax[2*i+2]);
    }

    int findLeftMostZero(int i, int l, int r) {
        propagate(i, l, r);

        if(segMin[i] > 0 || segMax[i] < 0) {
            return -1;
        }

        if(l == r) {
            return l;
        }

        int mid = l + (r-l)/2;
        int leftResult = findLeftMostZero(2*i+1, l, mid);
        if(leftResult != -1)
            return leftResult;
        
        return findLeftMostZero(2*i+2, mid+1, r);
    }
    int bruteForce(vector<int>& nums){
        unordered_map<int, int>mp;
        vector<int>cummSum(n, 0);
        int maxL = 0;
        for(int r = 0; r<n; r++){
            // +1 for even and -1 for odd
            int val = (nums[r] % 2 == 0 ? 1 : -1);

            int prev = -1;
            if(mp.find(nums[r])!=mp.end()){
                prev = mp[nums[r]];
            }
            if(prev!=-1){
                //[0..prev] we are adding (-val) in range
                // for(int l=0;l<=prev;l++){
                //     cummSum[l]-=val; //Range Query Update in array in lon n T.C
                // }
                updateRange(0, prev, 0, 0, n-1, -val);
            }

            // for(int l=0;l<=r;l++){
                //[0..r] we are adding val
                // cummSum[l]+=val; //Range Query Update in array, which can be done in log n time
                updateRange(0, r, 0, 0, n-1, val);
            // }

            // for(int i=0;i<=r;i++){
            //     if(cummSum[i] == 0){
            //         //Finding first 0 in array
            //         maxL = max(maxL, r-i+1);//Search Query in segment tree, lon n time
            //         break;
            //     }
            // }
            int l = findLeftMostZero(0, 0, n-1);
            if(l!=-1){
                maxL = max(maxL, r-l+1);
            }
            mp[nums[r]] = r;

        }
        return maxL;
    }
    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        segMin.assign(4*n, 0);
        segMax.assign(4*n, 0);
        lazy.assign(4*n, 0);
        return bruteForce(nums); //TLE will come, but it is important to know why segment tree will be applied here

    }
};