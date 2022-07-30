#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INT_MAX 999999999

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

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        vector<vector<int>> dist = mat;
        //超级零最开始进入队列，之后便是所有0进入队列
        queue<Point> q;
        for(int i = 0 ; i < mat.size() ; i++)
        {
            for(int j = 0 ; j < mat[0].size() ; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push(Point(i, j));//超级0的所有邻居 —— 0入队
                }
                else
                {
                    dist[i][j] = INT_MAX;//所有1先初始化成∞
                }
            }
        }

        int level = 1;//当前BFS的层数
        while(!q.empty())
        {
            int size = q.size();//开始这层时，先记录一下这层要遍历多少次
            while(size != 0)
            {
                Point cur = q.front();
                q.pop();
                for(int i = 0 ; i < 4 ; i++)//遍历当前点的上下左右四个邻居
                {
                    Point adj = Point(cur.x + dir[i].x, cur.y + dir[i].y);
                    if(adj.x >= 0 && adj.x < mat.size() && adj.y >= 0 && adj.y < mat[0].size())
                    {
                        if(dist[adj.x][adj.y] == INT_MAX)
                        {
                            dist[adj.x][adj.y] = level;//更新成当前的层数
                            q.push(adj);//将邻居放入队列
                        }
                    }
                }
                size--;
            }
            level++;
        }
        return dist;        
    }
};