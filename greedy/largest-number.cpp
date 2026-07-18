class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        string ans = "";
        for (int i : nums) {
            s.push_back(to_string(i));
        }
        // Custom comparator to sort the numbers
        sort(s.begin(), s.end(),[](string& a, string& b) { return a + b > b + a; });
        if(s[0] == "0") return "0";  
        for (auto v : s) {
            ans += v;
        }
        return ans;
    }
};