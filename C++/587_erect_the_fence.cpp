class Solution {
public:
    typedef int coord_t;
    typedef long long coord2_t;
    
    // cross product
    coord2_t cross(const Point &p1,const Point &p2,const Point &p3){
        return (p2.x-p1.x)*(coord2_t)(p3.y-p1.y)-(p2.y-p1.y)*(coord2_t)(p3.x-p1.x);
    }
    static bool cmp(Point &p1, Point &p2){
        return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
    }
    static bool equ(Point &p1,Point &p2){
        return p1.x==p2.x&&p1.y==p2.y;
    }
    
    vector<Point> outerTrees(vector<Point>& points) {
        int n = points.size(), k = 0;
        vector<Point> res(2 * n);
        sort(points.begin(), points.end(), cmp);

        // left to right
        for (int i = 0; i < n; i++){
           while(k >= 2 && cross(res[k - 2], res[k - 1], points[i]) < 0) k--;
           res[k++] = points[i];
        }

        // right to left
        for(int i = n - 2, t = k + 1; i >= 0; i--) {
           while (k >= t && cross(res[k - 2], res[k - 1], points[i]) < 0) k--;
           res[k++] = points[i];
        }

        res.resize(k);
        sort(res.begin(), res.end(), cmp);
        res.erase(unique(res.begin(), res.end(), equ), res.end());
        return res;
    }
};