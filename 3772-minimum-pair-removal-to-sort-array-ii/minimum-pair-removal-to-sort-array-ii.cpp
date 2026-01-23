class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        // Creating long long vector for calculations
        int n = nums.size();
        vector<long long> temp(n, 0);
        for (int i = 0; i < n; i++) {
            temp[i] = nums[i];
        }

        // Creaating ordered set to store <sum, index> for every pair

        set<pair<long long, int>> minSet;
        vector<int> nextIndex(n);
        vector<int> prevIndex(n);

        for (int i = 0; i < n; i++) {
            nextIndex[i] = i + 1;
            prevIndex[i] = i - 1;
        }

        // Populating the set
        int badPairs = 0;
        for (int i = 0; i < n - 1; i++) {
            pair<long long, int> p = {temp[i] + temp[i + 1], i};
            minSet.insert(p);
            if (temp[i] > temp[i + 1]) {
                badPairs++;
            }
        }

        // Starting the operations the main brain of the program

        int operations = 0;

        while (badPairs) {
            int first = minSet.begin()->second;
            int second = nextIndex[first];
            int first_left = prevIndex[first];
            int second_right = nextIndex[second];

            minSet.erase({temp[first] + temp[second], first});

            if (temp[first] > temp[second]) {
                badPairs--;
            }

            // {d, a, b}
            // it was good pair and then it became bad
            if (first_left >= 0) {
                if (temp[first_left] <= temp[first] &&
                    temp[first_left] > (temp[first] + temp[second])) {
                    badPairs++;
                }
                // it was bad then became good
                else if (temp[first_left] > temp[first] &&
                         temp[first_left] <= (temp[first] + temp[second])) {
                    badPairs--;
                }
            }

            //{a,b, d}

            // it was good pair then it became bad
            if (second_right < n) {

                if (temp[second] <= temp[second_right] &&
                    (temp[first] + temp[second]) > temp[second_right]) {
                    badPairs++;
                }

                // it was bad then it became good
                else if (temp[second] > temp[second_right] &&
                         (temp[first] + temp[second] <= temp[second_right])) {
                    badPairs--;
                }
            }
            if(first_left>=0){
                minSet.erase({temp[first_left] + temp[first], first_left});
                minSet.insert({temp[first_left] + temp[first] + temp[second], first_left});
            }
            if(second_right<n){
                minSet.erase({temp[second] + temp[second_right], second});
                minSet.insert({temp[first] + temp[second] + temp[second_right], first});
                prevIndex[second_right] = first;
            }

            nextIndex[first] = second_right;
            temp[first] += temp[second];

            operations++;


        }
        return operations;
    }
};