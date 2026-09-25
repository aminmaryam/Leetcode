
#define MAX 100000

class Stack {
public:

    int front;
    int arr[MAX];

    Stack() {
        front = -1;
    }

    void push(int value) {
        arr[++front] = value;
    }

    void pop() {
        front--;
    }

    int top() {
        return arr[front];
    }

    bool empty() {
        return front == -1;
    }
};

class Solution {
public:

    vector<int> dailyTemperatures(vector<int>& temperatures) {

        Stack s;

        int n = temperatures.size();

        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--) {

            while(!s.empty() &&
                  temperatures[i] >= temperatures[s.top()]) {

                s.pop();
            }

            if(s.empty()) {
                ans[i] = 0;
            }
            else {
                ans[i] = s.top() - i;
            }

            s.push(i);
        }

        return ans;
    }
};