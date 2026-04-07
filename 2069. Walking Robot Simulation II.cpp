class Robot {
    int w, h, x, y;
    string d;
public:
    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        d = "East";
    }
    
    void step(int num) {
        int tot = 2*(w + h - 2);
        num = num%tot;
        if(num == 0 && x==0 && y==0)
            d = "South";
        for(int i=0; i<num; i++){
            if(d == "East"){
                if(x < w-1) x++;
                else {
                    y++;
                    d = "North";
                }
            }
            else if(d == "North"){
                if(y < h-1) y++;
                else{
                    x--;
                    d = "West";
                }
            }
            else if(d == "West"){
                if(x > 0) x--;
                else{
                    y--;
                    d = "South";
                }
            }
            else{
                if(y > 0) y--;
                else{
                    x++;
                    d = "East";
                }
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return d;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */