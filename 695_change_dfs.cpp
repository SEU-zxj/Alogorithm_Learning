class Solution 
{
public:
    //============================反思==============================//
    //之前做的过于麻烦是因为最开始思考时就过于困难，最开始思考时就用了两层bfs，感觉搞错了图遍历算法的意思
    //这个题目想让我们用算法的地方应该是遍历陆地的时候，而不是遍历所有海洋的时候

    //深度优先
    struct Point
    {
        int x;
        int y;
        Point(): x(0), y(0){}
        Point(int x_in, int y_in): x(x_in), y(y_in){}
    };
    const Point arr[4] = {Point(-1, 0), Point(1, 0), Point(0, -1), Point(0, 1)};

    //传入一个没有被统计过的岛，统计这个岛的面积并返回
    //将这个岛上所有的1变成0
    int DFS(vector<vector<int>>& grid, int r, int c)
    {
        int area = 1;
        grid[r][c] = 0;

        for(int i = 0 ; i < 4 ; i++)
        {
            int row = r + arr[i].x;
            int colume = c + arr[i].y;
            //没超界
            if(row >= 0 && row < grid.size() && colume >= 0 && colume < grid[0].size())
            {
                //是陆地
                if(grid[row][colume] == 1)
                {
                    area += DFS(grid, row, colume);
                }
            }
        }

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int ans = 0;
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++)
            {
                if(grid[i][j] == 1)
                {
                    ans = max(ans, DFS(grid, i, j));
                }
            }
        }
        return ans;
    }
};