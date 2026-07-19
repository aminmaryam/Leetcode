class MyStack {
public:
    MyStack() {
        
    }
    
    /*
    we will have to make 2 queues, push(1) in queue1 then, to push another element we have to copy the elements of queue1 to queue2 then delete queue1 elements and push(2) in queue1 then again copy queue2 elements in queue1 from rear end
    */

    queue<int> q1;
    queue<int> q2;
    
    void push(int x) {
        //copy elements from q1 to q2
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        //push new Element to q1
        q1.push(x);

        //copy elements of q2 to q1
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }

    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */