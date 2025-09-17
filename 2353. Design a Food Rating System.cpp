class FoodRatings {
    unordered_map<string, set<pair<int, string>>> cuisine_high;
    unordered_map<string, int> rating; 
    unordered_map<string, string> cuisine; 
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0; i<n; i++){
            string food = foods[i];
            string cui = cuisines[i];
            int rate = ratings[i];
            cuisine_high[cui].insert({-rate, food});
            rating[food] = rate;
            cuisine[food] = cui;
        }
    }
    
    void changeRating(string food, int newRating) {
        string cui = cuisine[food];
        int rate = rating[food];
        cuisine_high[cui].erase({-rate, food});
        cuisine_high[cui].insert({-newRating, food});
        rating[food] = newRating;
    }
    
    string highestRated(string cui) {
        return cuisine_high[cui].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */