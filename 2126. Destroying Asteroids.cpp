class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        for(int x : asteroids){
            if(x <= mass)
                mass += x;
            else
                return false;
            if(mass > 1e5+1)
                return true;
        }
        return true;
    }
};