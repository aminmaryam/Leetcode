class Solution {
public:

/*
we stack the stack with pushing -1
if opening bracket push the index of the string
if closing bracket , first pop, then check if s is empty, if yes then push index of curr, else calculate length = index - top

then if (length > maxLength) maxlength = length

*/
    int longestValidParentheses(string str) {
        stack<int> s;
        s.push(-1);
        int maxLength = 0;

        for(int i=0; i<str.size(); i++){

            //opening brscket
            if(str[i] == '('){
                s.push(i);
            }

            //closing bracket
            else{
                s.pop();
                if(s.empty()){
                    s.push(i);
                }   
                else{
                    int length = i - s.top();

                    if(length > maxLength){
                        maxLength = length;
                    }
                }
            }
        }
        return maxLength;
    }
};