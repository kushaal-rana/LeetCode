class Solution {
public:
//Approach-1 : (Recursion + Memoization)

    bool checkPartition(int idx, int currSum, int num, string square){
        if(idx==square.size()) return currSum==num;
        if(currSum>num) return false;
        // if(currSum==num) return true;
        for(int j=idx;j<square.size();j++){
            //  currSum += stoi(square.substr(idx, j-idx+1));
            // this will modify the currSum value for all interations do it inside recrusion
            int val = stoi(square.substr(idx, j-idx+1));
            if(checkPartition(j+1,currSum+val,num,square)){
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {
        int punish = 0;
        for(int num = 1; num <=n; num ++){            
            string square = to_string(num * num);
            if(checkPartition(0,0,num,square)){
                punish += stoi(square);
            }
        }
        return punish;
    }
};

class Solution {
public:
//Approach-1 : (Memoization)
//T.C : O(n * 2^(log10(n^2)))
//S.C : O(n * log10(n^2))
    bool checkPartition(int idx, int currSum, int num, string square, vector<vector<int>> &dp){
        if(idx==square.size()) return currSum==num;
        if(currSum>num) return false;
        // if(currSum==num) return true;
        if(dp[idx][currSum]!=-1) return dp[idx][currSum];
        for(int j=idx;j<square.size();j++){ //log(n^2)
            //  currSum += stoi(square.substr(idx, j-idx+1));
            // this will modify the currSum value for all interations do it inside recrusion
            int val = stoi(square.substr(idx, j-idx+1));
            if(checkPartition(j+1,currSum+val,num,square,dp)){ //2^log(N^2)
                return dp[idx][currSum] = true;
            }
        }
        return dp[idx][currSum] = false;
    }
    int punishmentNumber(int n) {
        int punish = 0;
        for(int num = 1; num <=n; num ++){   //O(N)
            string square = to_string(num * num);
            vector<vector<int>> dp(square.size(), vector<int>(num+1,-1));
            if(checkPartition(0,0,num,square,dp)){
                punish += stoi(square);
            }
        }
        return punish;
    }
};