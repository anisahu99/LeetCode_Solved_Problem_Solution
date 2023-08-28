class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int sz=q.size();
        while(sz>1){
            q.push(q.front());
            q.pop();
            sz--;
        }
        int ans=q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        int sz=q.size();
        while(sz>1){
            q.push(q.front());
            q.pop();
            sz--;
        }
        int ans=q.front();
        q.pop();
        q.push(ans);
        return ans;
    }
    
    bool empty() {
        return q.empty();
    }
};