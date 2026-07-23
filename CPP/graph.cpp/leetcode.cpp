//                     547. Number of Provinces

class Solution {
public:
    void dfs(int i, vector<vector<int>>& g, vector<int>& vis){
        vis[i] = 1;
        for(int j = 0; j < g.size(); j++){
            if(g[i][j] == 1 && !vis[j])
                dfs(j, g, vis);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int count = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, isConnected, vis);
                count++;
            }
        }
        return count;
    }
};

//                                733. Flood Fill



class Solution {
public:
    void dfs(vector<vector<int>>& img, int r, int c, int oldColor, int newColor){
        if(r < 0 || c < 0 || 
           r >= img.size() || 
           c >= img[0].size() || 
           img[r][c] != oldColor)
            return;

        img[r][c] = newColor;

        dfs(img, r+1, c, oldColor, newColor);
        dfs(img, r-1, c, oldColor, newColor);
        dfs(img, r, c+1, oldColor, newColor);
        dfs(img, r, c-1, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if(oldColor != color)
            dfs(image, sr, sc, oldColor, color);
        return image;
    }
};