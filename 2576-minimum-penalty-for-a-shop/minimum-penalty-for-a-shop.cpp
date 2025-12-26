class Solution {
public:
    int bestClosingTime(string customers) {
        int yCount = 0;
        int nCount = 0;
        // counting number of Ns
        for(auto it: customers){
            if(it=='N'){
                nCount++;
            }
        }

        vector<int>prefixSum(customers.length()+1, 0);

        for(int i=prefixSum.size()-1;i>=0;i--){
            if(i==prefixSum.size()-1){
                prefixSum[i] = nCount;
                continue;
            }

            if(customers[i] == 'N'){
                nCount--;
                prefixSum[i] = nCount + yCount;
            }
            else{
                yCount++;
                prefixSum[i] = nCount + yCount;
            }
        }

        auto it = min_element(prefixSum.begin(), prefixSum.end());


        int index = distance(prefixSum.begin(), it);

        return index;
    }
};