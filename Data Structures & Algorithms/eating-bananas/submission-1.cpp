class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        vector<int> p = piles;
        std::sort(p.begin(), p.end());
        int end = piles.size()-1;

        int minspeed = 1;
        int maxspeed = p[end];
        int midspeed = maxspeed/2;
        int hours = 0;
        int result = maxspeed;

        while (minspeed <= maxspeed) {
            hours = 0;
            midspeed = (minspeed+maxspeed)/2;

            for (int i = 0; i < p.size(); i++) {
                // determine hours at speed
                hours += p[i]/midspeed;
                if (p[i]%midspeed > 0) hours++;
            }
            // if <= h, check slower speeds
            if (hours <= h) {
                result = midspeed;
                maxspeed = midspeed - 1;
                
            // if > h, check faster speeds
            } else if (hours > h) {
                minspeed = midspeed + 1;
            }
        }
        return result;
    }
};
