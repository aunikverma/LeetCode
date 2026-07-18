class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        string ans;
        if ((numerator > 0) && (denominator > 0)) { //both + 
            ans += "";
        } else if ((numerator < 0) && (denominator < 0)) {//both -
            ans += "";
        } else { //else -
            ans += "-";
        }
        long long num = llabs(numerator);
        long long den = llabs(denominator);

        ans += to_string(num / den);
        long long remainder = num % den;
        if (remainder == 0) //if remainder zero return ans
            return ans;
        ans += ".";

        unordered_map<long long, int> seen;
        while (remainder != 0) {
            if (seen.count(remainder)) {
                ans.insert(seen[remainder], "(");
                ans += ")";
                break;
            }
            seen[remainder] = ans.size();
            remainder = remainder * 10; //adding decimal
            ans += to_string(remainder / den);
            remainder = remainder % den;
        }
        return ans;
    }
};