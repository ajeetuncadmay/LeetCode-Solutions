class Solution {
public:
    double angleClock(int hour, int minutes) {
        if (hour == 12)
            hour = 0;

        double hourAngle = 30.0 * hour + 0.5 * minutes;
        double minuteAngle = 6.0 * minutes;

        double diff = abs(hourAngle - minuteAngle);

        return min(diff, 360.0 - diff);
    }
};