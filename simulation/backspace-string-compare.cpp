class Solution {
private:
    void simulate(string& a,string& s)
    {
        for(char c : s)
        {
            if(c == '#' && a.length() >= 1) a.pop_back();
            else if(c != '#') a.push_back(c);
        }
    }
public:
    bool backspaceCompare(string s, string t) {
        string a = "";
        string b = "";
        simulate(a,s);
        simulate(b,t);
        cout << a << " - " << b;
        return (a == b);
    }
};