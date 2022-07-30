#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution 
{
public:
    struct Point
    {
        int x;
        int y;
        Point(): x(0), y(0){}
        Point(int x_in, int y_in): x(x_in), y(y_in){}
    };
    const Point dir[4] = {Point(-1, 0), Point(0, 1), Point(1, 0), Point(0, -1)};

    int orangesRotting(vector<vector<int>>& grid) 
    {
        int time = 0;
        int freshNum = 0;//当前时刻新鲜的桔子数量
        queue<Point> spread;
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++)
            {
                if(grid[i][j] == 1)
                {
                    freshNum++;
                }
                else if(grid[i][j] == 2)
                {
                    spread.push(Point(i, j));//不新鲜的橘子入队，准备开始传染给邻居
                }
                else{/*do nothing*/}
            }
        }
        if(freshNum == 0){return 0;}
        while(!spread.empty())
        {
            int size = spread.size();//这一层bfs要遍历多少次
            int temp = freshNum;//记录开始本层bfs开始时新鲜的桔子数量
            while(size != 0)
            {
                Point cur = spread.front();
                spread.pop();
                for(int i = 0 ; i < 4 ; i++)//对当前腐烂橘子四周的新鲜橘子进行传染
                {
                    Point next = Point(cur.x + dir[i].x, cur.y + dir[i].y);
                    if(next.x >= 0 && next.y >= 0 && next.x < grid.size() 
                    && next.y < grid[0].size())//没超界
                    {
                        if(grid[next.x][next.y] == 1)//是新鲜橘子
                        {
                            grid[next.x][next.y] = 2;
                            temp--;
                            spread.push(next);//加入队列，作为下层bfs
                        }
                    }
                }
                size--;
            }
            time++;

            if(temp == 0)
            {
                return time;
            }
            else if(freshNum == temp)//经过一轮bfs之后数量不变，说明有橘子永远不会腐烂
            {
                return -1;
            }
            else
            {
                freshNum = temp;
            }
        }
        return -1;//正常情况应该从while中返回了，还有一种特殊情况：所有橘子都新鲜，程序会执行至此
    }
};