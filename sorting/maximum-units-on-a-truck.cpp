class Solution {
public:
    int maximumUnits(vector<vector<int>>& box, int truckSize) {
        vector<pair<int, int>> p;
        for (int i = 0; i < box.size(); i++) {
            p.push_back({box[i][1], box[i][0]});
        }
        sort(p.rbegin(), p.rend()); //sorting box which have more units
        int ans = 0;
        for (auto& i : p) {
            if (truckSize - i.second >= 0) {
                ans += i.first * i.second;
                truckSize -= i.second; //taking boxes which has more units 
            } else {
                ans += truckSize * i.first;//when boxes are more take only left trucksize
                break;
            }
        }
        return ans;
    }
};