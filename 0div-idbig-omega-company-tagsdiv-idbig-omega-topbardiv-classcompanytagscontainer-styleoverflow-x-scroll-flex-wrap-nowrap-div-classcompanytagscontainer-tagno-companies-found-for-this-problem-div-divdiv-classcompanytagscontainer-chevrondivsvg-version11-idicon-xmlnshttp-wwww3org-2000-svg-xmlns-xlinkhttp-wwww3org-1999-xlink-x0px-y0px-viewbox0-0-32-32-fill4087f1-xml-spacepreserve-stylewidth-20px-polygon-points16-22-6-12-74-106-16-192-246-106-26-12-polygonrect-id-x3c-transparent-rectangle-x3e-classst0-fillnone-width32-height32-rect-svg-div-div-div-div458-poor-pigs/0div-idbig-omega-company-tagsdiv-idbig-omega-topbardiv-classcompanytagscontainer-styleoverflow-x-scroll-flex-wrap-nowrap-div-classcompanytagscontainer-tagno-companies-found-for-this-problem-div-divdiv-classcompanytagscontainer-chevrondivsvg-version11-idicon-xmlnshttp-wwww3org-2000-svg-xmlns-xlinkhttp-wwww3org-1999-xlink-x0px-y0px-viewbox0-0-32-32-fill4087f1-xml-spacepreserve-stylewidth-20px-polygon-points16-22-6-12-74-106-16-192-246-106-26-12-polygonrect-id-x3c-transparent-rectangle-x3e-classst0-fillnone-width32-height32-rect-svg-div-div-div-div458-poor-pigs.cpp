class Solution {
public:
    //  https://www.youtube.com/watch?v=YQJLNxveyKg
    // code story with mik
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int T=minutesToTest/minutesToDie + 1;
        int pig=0;
        
        while(pow(T,pig)<buckets){
            pig++;
        }
        return pig;
    }
};