class Solution {
public:
    double angleClock(int hour, int minutes) {
        //Part 1-> Finding angle of hr hand
        double hrAngle = hour * 30;
        // hrAngle = hrAngle % 360.0;
        double minAngle = minutes * 6.0;
        hrAngle += (double)minutes/2.0;
        double diff = abs(hrAngle - minAngle);
        return min(diff, 360.0-diff);
    }
};