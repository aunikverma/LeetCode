class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& arr, int k) {
        // gain lambda function in c++
        auto gain = [](int pass, int size) {
            double c = (double)(pass + 1) / (size + 1) - (double)pass / size;
            return c;
        };

        priority_queue<pair<double, pair<int, int>>> pq;//gain and pass and size to store

        for (int i = 0; i < arr.size(); i++) {
            double r = gain(arr[i][0], arr[i][1]); // calculating gain for 1 student
            pq.push({r, {arr[i][0], arr[i][1]}});
        }

        while (k--) {//higher gain means increase the students 
            auto [ratio, size] = pq.top();
            pq.pop();
            pq.push({gain(size.first + 1, size.second + 1),{size.first + 1, size.second + 1}});
        }//incrementing +1 for new student

        double total = 0;

        while (!pq.empty()) {//calculating new total ratio
            auto [value, p] = pq.top();
            pq.pop();
            total += (double)p.first / p.second;
        }

        return total / arr.size();//total ratio
    }
};