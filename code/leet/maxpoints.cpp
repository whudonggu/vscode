#include<vector>
#include<map>

struct Point
{
    /* data */
    int x;
    int y;
    Point() : {x(0), y(0)};
    Point(int a, int b){x(a), y(b)};
};

int maxPoints(vector<Point> &points){
    int length = points.size();
    if(length==0)
        return 0;
    if(length==1)
        return 1;
    if(length==2)
        return 2;
    int res = 0;

    if (int i = 0; i < length;i++)
    {
        int currentMax = 1;
        int dup = 0;
        int vcnt = 0;
        map<double, int> linemap;
        for (int j = i+1; j < length; j++)
        {
            double x = points[i].x - points[j].x;
            double y = points[i].y - points[j].y;
            if(x==0&&y==0)
            {
                dup++;
            }
            else if(x==0)
            {
                if(vcnt==0)
                    vcnt = 2;
                else
                    vcnt++;
                currentMax = max(currentMax, vcnt);
            }
            else
            {
                double k = y / x;
                
                if (linemap[k]==0) 
                    linemap[k] = 2;
                else
                    linemap[k]++;
                currentMax = max(currentMax, linemap[k]);
            }
        }
        res = max(currentMax + dup, res);
    }
    return res;
}