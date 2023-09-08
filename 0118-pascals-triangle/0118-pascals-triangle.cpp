class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
            vector<vector<int>> output(numRows);
            for(int i=0;i<numRows;i++){
                    vector<int>temp(i+1);
                    for(int j=0;j<=i;j++){
                            if(j==0){
                            temp[j]=1;
                            }
                            else if(i==j){
                                    temp[j]=1;
                            }
                            else{
                            temp[j]=output[i-1][j-1]+output[i-1][j];
                            }
            }
                    output[i]=temp;
            }
            return output;
    }
};