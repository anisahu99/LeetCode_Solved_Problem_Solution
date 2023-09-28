class Solution {
public:
    // myself
    double champagneTower(int poured, int query_row, int query_glass) {
        // if(poured==0||poured==1&&query_row!=0||query_glass!=0) return (double) 0;
        // if(poured==1&&query_row==0&&query_glass==0) return (double) 1;
        //if((100*101)/2<=poured) return (double) 1;
        vector<vector<double>> glass(100);
        for(int i=0;i<100;i++){
            glass[i].resize(i+1);
        }
        glass[0][0]=poured;
        
        for(int row=1;row<100;row++){
            vector<double> extra(row);
            for(int col=0;col<row;col++){
                if(glass[row-1][col]>(double) 1){
                    double parts=glass[row-1][col]-1;
                    double divide=parts/2;
                    extra[col]=divide;
                    glass[row-1][col]=(double) 1;
                }
            }
            // for(double val:extra){
            //     cout<<val<<", ";
            // }
            
            // for(double val:glass[row]){
            //     cout<<val<<", ";
            // }
            // cout<<endl;
            for(int col=0;col<row+1;col++){
                if(col-1>=0){
                    glass[row][col]+=extra[col-1];
                }
                if(col<extra.size()){
                    glass[row][col]+=extra[col];
                }
            }
            // for(double val:glass[row]){
            //     cout<<val<<", ";
            // }
            // cout<<"next"<<endl;
        }
        
        for(int col=0;col<100;col++){
            if(glass[100-1][col]>(double) 1){
                glass[100-1][col]=(double) 1;
            }
        }
        return glass[query_row][query_glass];
    }
};