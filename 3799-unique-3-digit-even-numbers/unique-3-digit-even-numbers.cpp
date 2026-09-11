class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count = 0;
        int n = digits.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                for(int k=0;k<n;k++){
                    if(i==j || j==k || i==k || digits[i] == 0){
                        continue;
                    }
                    if(digits[k]%2 == 0){
                        int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                        if(st.find(num) == st.end()){
                            count++;
                            st.insert(num);
                        }
                    }
                }
            }
        }
        return count;
    }
};