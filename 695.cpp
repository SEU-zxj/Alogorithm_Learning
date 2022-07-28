#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Point
{
    int x;
    int y;
    Point(): x(0), y(0){}
    Point(int x_in, int y_in): x(x_in), y(y_in){}
};
const Point arr[4] = {Point(-1, 0), Point(1, 0), Point(0, -1), Point(0, 1)};

//扫描到一个岛之后，用该函数统计这个岛的大小并返回
int AnalyzeArea(vector<vector<int>>& grid, vector<vector<bool>>& visit, 
                vector<vector<bool>>& analyzed, Point start, queue<Point>& explore)
{
    int area = 0;
    queue<Point> analyze;
    analyze.push(start);
    visit[start.x][start.y] = true;
    analyzed[start.x][start.y] = true;
    //如果队列没有空，执行while里面的语句
    while(!analyze.empty())
    {
        Point p = analyze.front();
        analyze.pop();
        //===========================想想问题出在哪里？===========================//
        //***********************之前visit[p.x][p.y] = true;*********************//
        //visit的含义：只要在队列里面就算visit了
        //否则会导致同一个节点重复进入队列
        area++;
        //看周围四个点是不是岛屿（这里只看上下左右）
        for(int dir = 0 ; dir < 4 ; dir++)
        {
            //没有超界
            Point cur = Point(p.x + arr[dir].x, p.y + arr[dir].y);
            if(cur.x >= 0 && cur.x < grid.size() && cur.y >= 0 && cur.y < grid[0].size())
            {
                //如果是岛屿且没有被统计过过就加入analyze队列
                if(grid[cur.x][cur.y] == 1 && !analyzed[cur.x][cur.y])
                {
                    analyze.push(cur);
                    visit[cur.x][cur.y] = true;
                    analyzed[cur.x][cur.y] = true;
                }
                //如果是海洋而且没有在访问队列中就加入explore队列
                if(grid[cur.x][cur.y] == 0 && !visit[cur.x][cur.y])
                {
                    visit[cur.x][cur.y] = true;
                    explore.push(cur);
                }
            }
        }
    }
    //返回岛屿面积
    return area;
}
int maxAreaOfIsland(vector<vector<int>>& grid) 
{
    //特殊情况
    if(grid.size() == 0)
    {
        return 0;
    }
    if(grid.size() != 0 && grid[0].size() == 0)
    {
        return 0;
    }

    //一般情况
    //当前节点是否被访问过
    vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
    //（仅对陆地有效）当前陆地是否被统计过
    vector<vector<bool>> analyzed(grid.size(), vector<bool>(grid[0].size(), false));
    queue<Point> explore;
    int ans = 0;
    Point curPoint(0, 0);
    visit[curPoint.x][curPoint.y] = true;
    //广度优先搜索，这里搜索的时候不仅仅局限于上下左右，而是一个各自周围8个都可以遍历
    explore.push(curPoint);
    //当队列非空时，执行while中的语句
    while(!explore.empty())
    {
        curPoint = explore.front();
        explore.pop();
        //注意这里有种可能为：curPoint是陆地，但是队列里面有这个陆地中的另一个点A
        //调用AnalyzeArea之后，A点会被访问，所以之后再访问到A点就不用再访问了
        //所以这里加一个判断：若这个点之前没有判断过

        //若为陆地，而且没有统计过面积
        //反意即为若统计过面积就算了
        if(grid[curPoint.x][curPoint.y] == 1 && !analyzed[curPoint.x][curPoint.y])
        {
            ans = max(ans, AnalyzeArea(grid, visit, analyzed, curPoint, explore));
        }
        //若为海洋
        if(grid[curPoint.x][curPoint.y] == 0)
        {
            for(int i = -1 ; i <= 1 ; i++)
            {
                for(int j = -1 ; j <= 1 ; j++)
                {
                    //如果是自己，不会加入队列，因为已经访问过了
                    Point p = Point(curPoint.x+i, curPoint.y+j);
                    //如果没超界
                    if(p.x >= 0 && p.x < grid.size() && p.y >= 0 && p.y < grid[0].size())
                    {
                        //如果没有访问过
                        if(!visit[p.x][p.y])
                        {
                            //加入队列
                            explore.push(p);
                            visit[p.x][p.y] = true;
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> grid(1,vector<int>(1, 1));
    cout << maxAreaOfIsland(grid);
}