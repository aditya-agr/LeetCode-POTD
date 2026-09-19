class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        int dx = max(x1, min(xc, x2)) - xc;
        int dy = max(y1, min(yc, y2)) - yc;
        return dx*dx + dy*dy <= r*r;
    }
};