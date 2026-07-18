class Solution {
private:
    int check(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        while (i < a.size() || j < b.size()) {
            int x = (i < a.size()) ? a[i] : 0; //if index out of bound it'll treated as 0
            int y = (j < b.size()) ? b[j] : 0;
            if(x > y) return 1; //case 1
            else if(x < y) return -1; //case 2
            i++;j++;
        }
        return 0;
    }

public:
    int compareVersion(string v1, string v2) {
        vector<int> a;
        vector<int> b;
        stringstream ss(v1);
        stringstream ss1(v2);
        string token;
        while (getline(ss, token, '.')) { //breaking string '.' using delimeter
            int x = stoi(token);
            a.push_back(x);
        }
        while (getline(ss1, token, '.')) {
            int x = stoi(token);
            b.push_back(x);
        }
        return check(a, b); //comparing using helper function
    }
};