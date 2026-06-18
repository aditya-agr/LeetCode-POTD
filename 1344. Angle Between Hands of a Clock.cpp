class Solution {
public:
    double angleClock(int hour, int minutes) {
        double min_percent = minutes/60.0;
        double hea = min_percent*30;
        double hrf = hour*30+hea;

        double mrf = minutes*6;

        double ang = abs(hrf-mrf);
        return min(ang, 360-ang);
    }
};