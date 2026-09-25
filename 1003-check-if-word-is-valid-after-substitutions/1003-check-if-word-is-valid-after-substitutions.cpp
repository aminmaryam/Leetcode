class Solution {
public:

/*
we have t=" " and we have to make that s by inserting abc at any position.
if formation of s with t is possible then return true otherwise false
*/
#define MAX 10

class Stack{
	
	public:
		
	int front;
	int arr[MAX];
	
	Stack(){
		front = -1;
	}
	
	void push(char c){
		if(front == MAX - 1){
			cout<<"array is full."<<endl;
			return;
		}
		
		arr[++front] = c;
	}
	
	
	void pop(){
		if(front == -1){
			cout<<"array is empty."<<endl;
			return;
		}
		
		front--;
	}
	
	char top(){
		return arr[front];
	}
	
	 bool empty(){

        return front == -1;
    }
};


bool isValid(string str) {
    Stack s;

    for(int i=0; i<str.size(); i++) {

        s.push(str[i]);

        if(str[i] == 'c' && s.front >= 2) {

            if(s.arr[s.front-2] == 'a' &&
               s.arr[s.front-1] == 'b' &&
               s.arr[s.front] == 'c') {

                s.pop();
                s.pop();
                s.pop();
            }
        }
    }

    if(s.empty()) {
        return true;
    }

    return false;
}
};