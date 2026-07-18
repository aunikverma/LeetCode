struct Comp {
    bool operator()(const pair<int, string>& a,
                    const pair<int, string>& b) const {
        // We want max rating first, and for ties lexicographically smallest
        // food.
        if (a.first != b.first)
            return (a.first < b.first); // bigger rating first
        return (a.second > b.second);   // lexicographically smaller first
    }
};

class FoodRatings {
    unordered_map<string, pair<int, string>> mp; // food -> {rating,cuisine}
    unordered_map<string, priority_queue<pair<int, string>,
                                         vector<pair<int, string>>, Comp>>
        mp1; // cuisine -> heap
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            mp[foods[i]] = {ratings[i], cuisines[i]};
            mp1[cuisines[i]].push({ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = mp[food].second;
        mp[food].first = newRating;
        mp1[cuisine].push({newRating, food});
    }

    string highestRated(string cuisine) {
        auto& pq = mp1[cuisine];
        while (!pq.empty()) {
            auto [rating, food] = pq.top();
            if (mp[food].first == rating)
                return food; // current rating
            pq.pop();        // stale entry
        }
        return "";
    }
};
