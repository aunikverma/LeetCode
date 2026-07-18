class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> P;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        // store k - 1 elements
        set<P> kmin;
        set<P> remaining;
        // sum of k min elements
        ll sum = 0;
        int i = 1;
        while (i - dist < 1) {
            kmin.insert({nums[i], i});
            sum += nums[i];
            if (kmin.size() > k - 1) {
                P temp = *kmin.rbegin();//max element
                sum -= temp.first;
                remaining.insert(temp);//add in remaining
                kmin.erase(temp);//del from kmin
            }
            i++;
        }
        // result
        ll result = LLONG_MAX;
        while (i < n) {
            kmin.insert({nums[i], i});
            sum += nums[i];
            if (kmin.size() > k - 1) {
                P temp = *kmin.rbegin();//max element
                sum -= temp.first;
                remaining.insert(temp);//add in remaining
                kmin.erase(temp);//del from kmin
            }
            result = min(result, sum);//choose min
            // shift window
            //  i - dist will get removed
            P remove = {nums[i - dist], i - dist};
            if (kmin.count(remove)) {
                kmin.erase(remove);
                sum -= remove.first;
                if (!remaining.empty()) {
                    P temp = *remaining.begin(); //add from remaing 
                    kmin.insert(temp);
                    sum += temp.first;
                    remaining.erase(temp);
                }
            } else {// if not in kmin del from remaining
                remaining.erase(remove);
            }
            i++;
        }
        return (nums[0] + result);
    }
};