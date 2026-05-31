class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long mass2 = mass;
        for(int i=0;i<asteroids.size();i++){
            if(mass2<asteroids[i]){
                return false;
            }
            mass2 += asteroids[i];
        }
        return true;
    }
};