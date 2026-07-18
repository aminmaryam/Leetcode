class Solution {
public:
/*
arr = {3, 6, 5, 4, 2}
=> we can copy all the elements of the array after the last element of the orignal array(only for dry rn we dont create it in the program)
like: arr = {3, 6, 5, 4, 2, 3, 6, 5, 4, 2}
=>size of array will convert from n to 2n
=>stack will contain index of all greater elements
=> we will traverse through the array in reverse

//idx = i%n because if the index exceeds size of array then after i%2 it would still point of the corresponding array
e.g arr = {3, 6, 5, 4, 2, 3, 6, 5, 4, 2}
i=9 then idx=i%2 =>9%2 => idx = 4 
now idx 4 contains 2 just like idx 9

*/
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();

        vector<int> ans(n, -1);
        stack<int> s;

        for(int i=2*n-1; i>=0; i--){
            while(s.size() > 0 && arr[i%n] >= arr[s.top()]){ //explanation of i%2 above, arr[s.top()] because s.top() contains the idx
                s.pop();
            }

            if(s.empty()){
                ans[i%n] = -1;
            }
            else{
                ans[i%n] = arr[s.top()];
            }

            s.push(i%n);
        }

        return ans;

    }
};