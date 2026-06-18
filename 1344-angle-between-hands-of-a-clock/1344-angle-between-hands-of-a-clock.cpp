class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour %= 12;
        double hrDistance = hour*30 + minutes*0.5;
        double minsDistance = minutes*6;
        double diff = abs(hrDistance - minsDistance);
        return min(diff, 360-diff);
    }
};