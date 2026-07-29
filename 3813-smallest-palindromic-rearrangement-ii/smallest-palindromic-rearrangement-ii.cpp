class Solution {
public:

    int nCr(int n, int r, int k){
        r = min(r, n-r);
        long long result = 1;
        for(int i=1;i<=r;i++){
            result = result * (n-r+i)/i;
            if(result>=k) return k;
        }
        return result;
    }
    string smallestPalindrome(string s, int k) {
        int n = s.length();

        char mid = ' ';
        if(n%2==1){
            mid = s[n/2];
        }

        vector<int>count(26, 0);
        for(int i=0; i<s.length(); i++){
            if(n%2==1 && i == n/2) continue;
            count[s[i]-'a']++;
        }

        //half freq will be used for building halfResult
        for(int i=0;i<26;i++){
            count[i] /= 2;
        }

        string halfResult = "";
        int half = n/2;

        for(int i=0;i<half;i++){
            bool placed = false;
            for(int j=0;j<26;j++){ //which char to put
                if(count[j] > 0){
                    count[j] -= 1;

                    long long ways = 1;
                    int letters = 0;
                    for(int c=0; c<26; c++){
                        letters += count[c];
                    }

                    for(int c=0;c<26;c++){
                        if(count[c]>0){
                            ways *= nCr(letters, count[c], k);
                            letters -= count[c];
                        }
                        if(ways>=k){
                            break;
                        }
                    }

                    if(ways>=k){ //This block contains my answer
                        halfResult.push_back(j + 'a');
                        placed = true;
                        break;
                    }

                    k-=ways;
                    count[j] += 1;
                }
            }
            if(!placed) return "";
        }


        string rev = halfResult;
        reverse(rev.begin(), rev.end());
        if(mid != ' '){
            halfResult.push_back(mid);
        }
        return halfResult + rev;
    }
};