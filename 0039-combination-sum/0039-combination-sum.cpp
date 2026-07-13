class Solution {
public:
/*
every element in the array has the choice of being included(multiple times), included(single time) and excluded 

through recursion one thing we have to do in the function is at elevery element from i=0 to n-1
we have to i+1 when we include an elemnt in the array, but if the element is being included the second time then 'i' will remain same, and i+1 to exclude the element in the array 
in every recursive call we exclude the element in the array with the target, so when the target is zero then we have reached the base case  
basse case=> i==n all elements have been traversed, tar <0
in back tracking we pop the last element
*/
set<vector<int>> s;

void getComb(vector<int> &arr, int idx, int tar, vector<vector<int>> &ans, vector<int> &comb){

    //out of bound
    if(idx == arr.size() || tar < 0){
        return;
    }

    //found the ans
    if(tar == 0 ){
        if(s.find(comb) ==s.end()){
            ans.push_back(comb);
            s.insert(comb);
        }
        
        return;
    }

    comb.push_back(arr[idx]);
    //single
    getComb(arr, idx+1, tar-arr[idx], ans, comb);
    //multiple
    getComb(arr, idx, tar-arr[idx], ans, comb);
    
    comb.pop_back();

    //exclusion
    getComb(arr, idx+1, tar, ans, comb);
    
}
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int> comb;
        vector<vector<int>> ans;

        getComb(arr, 0, target, ans, comb);
    
        return ans;
    }
};