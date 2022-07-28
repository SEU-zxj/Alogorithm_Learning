#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Point
{
    int x;
    int y;
    Point(): x(0), y(0){}
    Point(int x_in, int y_in): x(x_in), y(y_in){}
};

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
{
    //得到图像的行数与列数
    int m = image.size();
    int n = (m == 0) ? 0 : image[0].size(); 
    vector<vector<int>> result = image;
    queue<Point> q;
    Point start(sr, sc);
    int color_change = image[sr][sc];
    //如果要更换的颜色和原来起点像素的颜色相同，没有必要继续操作，因为继续操作得到的结果和image一样
    if(color_change == color)
    {
        return result;
    }
    q.push(start);
    //申请两个数列，分别存储1个点变换到周围四个点横纵坐标的变化值
    int arr_r[4] = {-1, 1, 0, 0};
    int arr_c[4] = {0, 0, -1, 1};
    //若q非空
    while(!q.empty())
    {
        Point cur = q.front();
        q.pop();
        int row = cur.x;
        int colume = cur.y;
        result[row][colume] = color;
        //看cur的周围四个点
        for(int i = 0 ; i < 4 ; i++)
        {
            //当前判断图像中像素的坐标
            int r = row + arr_r[i];
            int c = colume + arr_c[i];
            //没有超界
            if(r >= 0 && r < m && c >= 0 && c < n)
            {
                if(result[r][c] == color_change)
                {
                    result[r][c] = color;
                    q.push(Point(r, c));
                }
            }      
        }   
    }
    return result;
}
int main()
{
    vector<vector<int>> image(2, vector<int>(3, 0));
    // image[0][0] = 1;
    // image[0][1] = 1;
    // image[0][2] = 1;
    // image[1][0] = 1;
    // image[1][1] = 1;
    // image[2][0] = 1;
    // image[2][2] = 1;

    floodFill(image, 0, 0, 0);
}