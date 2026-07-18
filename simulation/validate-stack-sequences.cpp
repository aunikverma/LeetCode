class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;
        for (int n : pushed) {
            s.push(n); //we push until popped[i] == s.top()
            while (!s.empty() && i < popped.size() && s.top() == popped[i]) { //then pop till s.top() == popped[i++]
                s.pop();
                i++;
            }
        }
        return (i == popped.size()); //if all elements is popped correctly
    }
};