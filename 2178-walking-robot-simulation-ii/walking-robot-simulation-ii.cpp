class Robot {
public:
    int x,y,width,height;
    pair<int, int>dir;
    Robot(int width, int height) {
        x = 0;
        y = 0;
        this->width = width;
        this->height = height;
        this->dir.first = 1;
        this->dir.second = 0;
    }
    void step(int num) {
        int cycle = 2 * (width + height - 2);
        num %= cycle;
        if(num == 0) num = cycle;
        for(int i=0;i<num;i++){
            int newX = x + dir.first;
            int newY = y + dir.second;
            if(newX>=width || newY>=height || newX<0 || newY < 0){
                i--;
                dir = {-dir.second, dir.first};
                continue;
            }
            x = newX;
            y = newY;
        }
    }
    
    vector<int> getPos() {
        vector<int>res = {x,y};
        return res;
    }
    
    string getDir() {
        if(dir == make_pair(0,1)){
            return "North";
        }
        else if(dir == make_pair(1, 0)){
            return "East";
        }
        else if(dir == make_pair(-1, 0)){
            return "West";
        }
        else{
            return "South";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */