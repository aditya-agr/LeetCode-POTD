class Event {
  public:
    int y;
    int t;
    int xs, xe;
    Event(int y, int t, int xs, int xe){
        this->y = y;
        this->t = t;
        this->xs = xs;
        this->xe = xe;
    }
};

class Solution {
public:
    vector<int> cnt, len;
    void updateTree(int node, int s, int e, int &l, int &r, int &value, vector<int> &x){
        if(r<=s || l>=e)
            return;
        if(l<=s && e<=r)
            cnt[node] += value;
        else{
            int mid = (s+e)/2;
            updateTree(2*node, s, mid, l, r, value, x);
            updateTree(2*node+1, mid, e, l, r, value, x);
        } 
        if(cnt[node] > 0){
            len[node] = x[e]-x[s];
        }
        else{
            if(e-s == 1)
                len[node] = 0;
            else
                len[node] = len[2*node]+len[2*node+1];
         }
    }
    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        set<int> st;
        for(vector<int> e : squares){
            int xs = e[0];
            int xe = e[0]+e[2];
            int ys = e[1];
            int ye = e[1]+e[2];
            events.push_back(Event(ys, 1, xs, xe));
            events.push_back(Event(ye, -1, xs, xe));
            st.insert(xs);
            st.insert(xe);
        }

        vector<int> sortx(st.begin(), st.end());
        int m = sortx.size();
        cnt.resize(4*m);
        len.resize(4*m);

        auto comp = [](Event &a, Event &b){
            return a.y < b.y;
        };
        sort(events.begin(),events.end(), comp);

        int prevY = events[0].y;
        int i = 0;
        int n = events.size();
        double sum = 0;
        vector<vector<int>> parts;
        while(i<n){
            int currY = events[i].y;
            if(currY > prevY){
                int h = currY - prevY;
                int w = len[1];
                sum += 1LL*h*w;
                parts.push_back({prevY, currY, w});
            }
            while(i<n && events[i].y == currY){
                Event e = events[i];
                int l = lower_bound(sortx.begin(), sortx.end(), e.xs) - sortx.begin();
                int r = lower_bound(sortx.begin(), sortx.end(), e.xe) - sortx.begin();
                updateTree(1, 0, m, l, r, e.t, sortx);
                i++;
            }
            prevY = currY;
        }
        if(sum == 0)
            return -1;
        double half = sum/2;
        double tot = 0;
        for(vector<int> &p : parts){
            int h = p[1]-p[0];
            int w = p[2];
            double a = 1LL*h*w;
            if(tot+a >= half){
                return p[0] + (half-tot)/w;
            }
            tot += a;
        }
        return -1;
    }
};