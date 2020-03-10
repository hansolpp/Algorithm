#include<iostream>
#include<fstream>
 
using namespace std;
 
int dy[4] = {-1,0,1,0};
int dx[4] = {0, 1, 0,-1};
 
int rotation_size[6] = {0,4,2,4, 4,1};
int camera_range[6][4] = {{}, {0}, {1,3}, {0, 1}, {0,1,3}, {0,1,2,3}};
int range_size[6] = {0,1,2,2,3,4};
 
int adj[8][8], n, m;
int min(int a, int b){return a < b ? a : b;}
int get_area(){
    int ret = 0;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            ret += adj[i][j] == 0;
        }
    }
    return ret;
}
 
int dfs(int r, int c){
	if(r == n) return get_area();
    int next_loc[2] = {r, c+1};
    if(next_loc[1] == m){
        next_loc[0] ++;
        next_loc[1] = 0;
    }
    int ret = 0x3f3f3f3f;
    if(adj[r][c] > 0 && adj[r][c] != 6){
        int cctv = adj[r][c];
        for(int rot = 0; rot < rotation_size[cctv]; rot++){
            for(int d= 0; d < range_size[cctv]; d++){
                int p[2] = {r,c};
                int dir = (rot+camera_range[cctv][d])%4;
                while(p[0] < n && p[1]< m && p[0] >= 0 && p[1] >= 0){
					if(adj[p[0]][p[1]] == 6) break;
                    if(adj[p[0]][p[1]] <= 0) adj[p[0]][p[1]]--;
                    p[0]+= dy[dir];
                    p[1]+= dx[dir];
                }
            }
            
            ret = min(ret, dfs(next_loc[0],next_loc[1]));
 
            for(int d = 0; d < range_size[cctv]; d++){
                int p[2] = {r,c};
                int dir =  (rot+camera_range[cctv][d])%4;
                
                while(p[0] >= 0 && p[1] >= 0 && p[0] < n && p[1] < m){
                    if(adj[p[0]][p[1]] == 6) break;
                    if(adj[p[0]][p[1]] < 0 ) adj[p[0]][p[1]]++;
                    p[0] += dy[dir];
                    p[1] += dx[dir];
                }
            }
        }
    }
    else{
        ret = dfs(next_loc[0], next_loc[1]);
    }
    return ret;
}
 
int main(){
	freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        for( int j = 0; j < m; j++){
            cin >> adj[i][j];
        }
    }
    cout << dfs(0,0)<< endl;
 
    return 0;
}

