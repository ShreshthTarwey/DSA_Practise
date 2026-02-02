class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long sum = 0;
        set<pair<long long, int>>minElement;
        set<pair<long long, int>>remaining;

        int i = 1;
        while((i-dist)<1){
            minElement.insert({nums[i], i});
            sum+=nums[i];
            //Now if we got k-1 min elements, but window size is still not completed, then...
            if(minElement.size()>k-1){
                pair<long long, int>p = *minElement.rbegin();
                minElement.erase(p);
                remaining.insert(p);
                sum-=p.first;
            }
            i++;
        }

        //Now till this point i......in, that is the max window distance that we can streach, to keep it below dist

        long long result = LLONG_MAX;

        while(i<nums.size()){
            minElement.insert({nums[i], i});
            sum+=nums[i];

            if(minElement.size()>k-1){
                pair<long long, int>p = *minElement.rbegin();
                minElement.erase(p);
                remaining.insert(p);
                sum-=p.first;
            }
            //Store min result

            result = min(result, sum);

            pair<long long, int>remove = {nums[i-dist], i-dist};
            if(minElement.count(remove)){
                minElement.erase(remove);
                sum-=remove.first;
                if(!remaining.empty()){
                    pair<long long, int>r = *remaining.begin();
                    sum+=r.first;
                    remaining.erase(r);
                    minElement.insert(r);
                }
            }
            else{
                remaining.erase(remove);
            }
            i++;
        }
        return nums[0] + result;
    }
};