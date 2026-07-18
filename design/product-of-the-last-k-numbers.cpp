class ProductOfNumbers {
private:
    vector<int> arr;
    int prod;

public:
    ProductOfNumbers() { prod = 1; }

    void add(int num) {
        if (num == 0) {
            arr.clear();
            prod = 1;
        } else {
            prod *= num;
            arr.push_back(prod);
        }
    }

    int getProduct(int k) {
        int n = arr.size();
        if (k > n)
            return 0;
        if (k == n)
            return arr[n - 1];
        return (arr[n - 1] / arr[n - k - 1]);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */