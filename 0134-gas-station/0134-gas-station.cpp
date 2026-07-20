class Solution {
public:
/*
gas = {1, 2, 4, 5, 9}
cost = {3, 4, 1, 10, 1}

Gas array is the starting points from where we can go to the next station but we have to look at the corrosponding index of cost array to find if we have enough fuel to go to the next station

for example: at we are at station 1 and we have gas of 1 Litre then to go to the next station we would need 3 Litres that means we cannot go to the next station
but if we are at 3rd station and our gas is 4L and we need 1L to go to the next station, so that is possible

for a valid solution total gas should be >= totalCost, otherwise return -1

=>we are going to traverse throught the gas array and assume every index is the valid answer


*/
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int st = 0;
        int currGas = 0;
        
        for(int val : gas){
            totalGas += val;
        }
        for(int val : cost){
            totalCost += val;
        }

        if(totalGas < totalCost){
            return -1;
        }

        for(int i=0; i<gas.size(); i++){
            currGas += gas[i] - cost[i];

            if(currGas < 0){
                st = i+1;
                currGas = 0;
            }
        }

        return st;

    }
};