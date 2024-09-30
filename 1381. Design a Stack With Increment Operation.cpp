class CustomStack {
public:
    vector<int> stack;
    vector<int> incre;
    int top;
    int n;

    CustomStack(int maxSize) {
        stack = vector<int>(maxSize);
        incre = vector<int>(maxSize);
        top = -1;
        n = maxSize;
    }
    
    void push(int x) {
        if(top<n-1){
            top++;
            stack[top] = x;
        }
    }
    
    int pop() {
        if(top>-1){
            int idx = stack[top] + incre[top];
            if(top>0) incre[top-1] += incre[top];
            incre[top] = 0;
            top--;
            return idx;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        if(top==-1)
            return;
        int i = min(k-1, top); 
        incre[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */