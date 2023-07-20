class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int &stone:asteroids){
            if(stone>0){
                st.push(stone);
            }
            else if(stone<0){
                bool flag=true;
                while(st.size()&&st.top()>0){
                    if(abs(stone)==st.top()){
                        st.pop();
                        flag=false;
                        break;
                    }
                    else if(abs(stone)>st.top()){
                        st.pop();
                        continue;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
                if(flag) st.push(stone);
            }
        }
        asteroids.clear();
        while(!st.empty()){
            asteroids.push_back(st.top());
            st.pop();
        }
        reverse(asteroids.begin(),asteroids.end());
        return asteroids;
    }
};