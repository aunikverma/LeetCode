class Bank {
public:
    vector<long long> balance;
    long long n;

    Bank(vector<long long>& balance) {
        this->balance = balance;
        n = balance.size();
    }

    bool transfer(int acc1, int acc2, long long money) {
        if (acc1 < 1 || acc1 > n || acc2 < 1 || acc2 > n) {
            return false;
        }
        if (balance[acc1 - 1] >= money) {
            balance[acc1 - 1] -= money;
            balance[acc2 - 1] += money;
            return true;
        }
        return false;
    }

    bool deposit(int account, long long money) {
        if (account < 1 || account > n) {
            return false;
        }
        balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (account < 1 || account > n) {
            return false;
        }
        if (balance[account - 1] >= money) {
            balance[account - 1] -= money;
            return true;
        }
        return false;
    }
};