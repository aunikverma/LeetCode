class Solution {
private:   
    int gcd(int a,int b)
    {
        return (b == 0) ? a : gcd(b, a % b);
    }
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int>mp;
        for(int i : deck) mp[i]++; //storing frequency
        vector<int>v; //in vector in v
        for(auto& i : mp) v.push_back(i.second); 
        int s = v[0];
        for(int i = 1;i < v.size();i++){ //taking gcd of all frequency 
            s = gcd(s,v[i]);
        }
        return (s > 1); //return gcd(all freq > 1)
    }
};