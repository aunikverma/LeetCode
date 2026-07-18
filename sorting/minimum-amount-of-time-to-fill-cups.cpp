class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int>p;
        for(int i : amount)
        {
            if(i > 0) //only if i > 0
            {
                p.push(i);
            }
        }
        if(p.size() == 1) return p.top(); //if only one element
        int count = 0;
        while(p.size() > 1)
        {
            int a = p.top(); p.pop();
            int b = p.top(); p.pop();
            if(a - 1 != 0) p.push(--a); //if a-1 or b-1 == 0 not push
            if(b - 1 != 0) p.push(--b);
            count++; //count++
        }
        if(!p.empty()) return count + p.top(); 
        return count; //if p.empty()
    }
};