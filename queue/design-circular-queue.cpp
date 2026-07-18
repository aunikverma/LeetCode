class MyCircularQueue {
private:
    int* arr;
    int front;     // front pointer
    int rear;      // rear pointer
    int n;         // size of array
    int count = 0; // tracks no of element
public:
    MyCircularQueue(int k) {
        arr = new int[k];
        front = -1;
        rear = -1;
        n = k; // size
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        } else {
            if (isEmpty()) {
                front = rear = 0;
                arr[rear] = value;
            } else {
                rear = (rear + 1) % n;
                arr[rear] = value;
            }
            count++;
        }
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        } else {
            if (count == 1) {
                front = rear = -1;
            } else {
                front = (front + 1) % n;
            }
            count--;
        }
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        else return arr[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        else return arr[rear];
    }

    bool isEmpty() { return (count == 0); }

    bool isFull() { return (count == n); }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */