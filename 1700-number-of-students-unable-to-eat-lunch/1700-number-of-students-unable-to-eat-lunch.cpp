class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int top=0;
        queue<int> q;
        int z=0;
        int o=0;
        for(int &stud:students){
            q.push(stud);
            stud==1?o++:z++;
        }
        //cout<<o<<"-"<<z<<endl;
        while(!q.empty()){
            int sd=sandwiches[top];
            int stud=q.front();q.pop();
            if(sd!=stud){
                if(stud==1&&o==q.size()+1){
                    return q.size()+1;
                }
                else if(stud==0&&z==q.size()+1){
                    return q.size()+1;
                }
                q.push(stud);
            }else{
                top++;
                stud==1?o--:z--;
                
            }
        }
        return 0;
    }
};