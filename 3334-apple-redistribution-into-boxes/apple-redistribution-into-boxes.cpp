class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());
        int capIndex = 0;
        for(int i=0;i<apple.size();i++){
            if( capIndex<capacity.size() &&(apple[i]>capacity[capIndex])){
                apple[i]-=capacity[capIndex];
                capacity[capIndex++] = 0;
                i--;
            }
            else{
                capacity[capIndex] -= apple[i];
                // i++;
            }
        }
        return capIndex+1;
    }
};