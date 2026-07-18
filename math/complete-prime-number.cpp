class Solution {
private:
    bool is_prime(int n) {
        if (n == 1) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    bool check(int n) { // prefix
        int s = 0;
        while (n > 0) {
            s = s * 10 + (n % 10);
            cout << s << " ";
            if (!is_prime(s)) {
                return false;
            }
            n /= 10;
        }
        return true;
    }
    bool check1(int n) { // suffix
        int s = 0, count = 0;
        while (n > 0) {
            s = (n % 10) * pow(10, count) + s;
            if (!is_prime(s)) {
                return false;
            }
            n /= 10;
            count++;
        }
        return true;
    }

public:
    bool completePrime(int num) {
        if (!is_prime(num)) {
            return false; // if no itself not prime
        }
        string a = to_string(num);
        reverse(a.begin(), a.end());
        int num1 = stoi(a);
        return (check1(num) && check(num1));
    }
};