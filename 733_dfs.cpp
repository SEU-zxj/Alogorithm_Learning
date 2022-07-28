class Solution {
public:
    const int arr_r[4] = {-1, 1, 0, 0};
    const int arr_c[4] = {0, 0, -1, 1};

    void DFS(vector<vector<int>>& image, int sr, int sc, int curColor, int newColor)
    {
        //第一步：改颜色
        image[sr][sc] = newColor;
        //第二步：遍历周围点并递归遍历
        for(int i = 0 ; i < 4 ; i++)
        {
            int r = sr + arr_r[i];
            int c = sc + arr_c[i]; 
            //没有超界
            if(r >= 0 && r < image.size() && c >= 0 && c < image[0].size())
            {
                //颜色是跟起点颜色一样的
                if(image[r][c] == curColor)
                {
                    DFS(image, r, c, curColor, newColor);
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int curColor = image[sr][sc];
        if(curColor != newColor)
        {
            //改变这个点的颜色并递归的遍历这个点周围的点
            DFS(image, sr, sc, curColor, newColor);
        }
        return image;
    }
};