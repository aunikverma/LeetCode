class Solution {
    class Node {
    public:
        int data;
        int i;
        int j;
        Node(int d, int r, int c) // data,row,col
        {
            data = d;
            i = r;
            j = c;
        }
    };
    class compare {
    public:
        bool operator()(Node* a, Node* b) { return (a->data > b->data); }
    };

public:
    vector<int> smallestRange(vector<vector<int>>& a) {
        int k = a.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        priority_queue<Node*, vector<Node*>, compare> pq;

        // insert 1 element
        for (int i = 0; i < k; i++) {
            int element = a[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            pq.push(new Node(element, i, 0)); // data row col
        }

        int start = mini, end = maxi;

        while (!pq.empty()) {
            Node* temp = pq.top();
            pq.pop();
            mini = temp->data;
            if ((maxi - mini) < (end - start)) {
                start = mini;
                end = maxi;
            }
            if (temp->j + 1 < a[temp->i].size()) // col < n
            {
                maxi = max(maxi, a[temp->i][temp->j + 1]);
                pq.push(new Node(a[temp->i][temp->j + 1], temp->i, temp->j + 1));
            } else {
                break;
            }
        }
        return {start, end};
    }
};