class Solution 
{
public:
    //============================反思==============================//
    //之前做的过于麻烦是因为最开始思考时就过于困难，最开始思考时就用了两层bfs，感觉搞错了图遍历算法的意思
    //这个题目想让我们用算法的地方应该是遍历陆地的时候，而不是遍历所有海洋的时候

    //广度优先
    struct Point
    {
        int x;
        int y;
        Point(): x(0), y(0){}
        Point(int x_in, int y_in): x(x_in), y(y_in){}
    };
    const Point arr[4] = {Point(-1, 0), Point(1, 0), Point(0, -1), Point(0, 1)};

    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int ans = 0;
        queue<Point> explore;

        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++)
            {
                if(grid[i][j] == 1)
                {
                    explore.push(Point(i, j));
                }
                //当队列不空执行while内代码
                //每次执行while都代表可能在统计一个岛屿的面积
                int temp = 0;
                while(!explore.empty())
                {
                    Point cur = explore.front();
                    explore.pop();
                    //如果这个陆地已经被统计过了，跳过他
                    if(grid[cur.x][cur.y] == 0)
                    {
                        continue;
                    }
                    //反之就统计这块陆地
                    temp++;
                    grid[cur.x][cur.y] = 0;
                    for(int dir = 0 ; dir < 4 ; dir++)
                    {
                        //没超界
                        Point next = Point(cur.x + arr[dir].x, cur.y + arr[dir].y);
                        if(next.x >= 0 && next.x < grid.size() && next.y >= 0 && next.y < grid[0].size())
                        {
                            //如果是没统计过的陆地就继续
                            if(grid[next.x][next.y] == 1)
                            {
                                explore.push(next);
                            }
                        }
                    }
                }
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};