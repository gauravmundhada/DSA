class Bank {
public:
    vector<long long> _balance;
    int n;
    Bank(vector<long long>& balance) {
        _balance = balance;
        n = _balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        // acc 1 -> acc 2
        // invalid accounts
        if (account1 > n || account2 > n || account1 < 1 || account2 < 1) {
            return false;
        }

        // insufficient balance
        if (_balance[account1-1] < money) {
            return false;
        }

        _balance[account1-1] -= money; // debit from acc 1
        _balance[account2-1] += money; // credit into acc 2
        return true; // transfer successful 
    }
    
    bool deposit(int account, long long money) {
        if (account < 1 || account > n) return false; // invalid acc

        _balance[account-1] += money;

        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account < 1 || account > n) return false;

        if (_balance[account - 1] < money) return false;

        _balance[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */