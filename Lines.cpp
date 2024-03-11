#include <bits/stdc++.h>
using namespace std;
const int N = 50;
char mat[N][N];
int n;
vector<pair<int,int>> mov={{0,-1},{0,1},{1,0},{-1,0}};
bool vis[N][N];
int dis[N][N];
int par[N][N];
bool flag=false;

bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=n || mat[i][j]=='O') return false;
    return true;
}

void bfs(int si, int sj){
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj]=true;
    dis[si][sj]=0;
    
    while (!q.empty())
    {
        pair<int,int> pr = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int ci = pr.first + mov[i].first;
            int cj = pr.second + mov[i].second;
            if(valid(ci,cj) && !vis[ci][cj]){
                dis[ci][cj]=dis[pr.first][pr.second]+1;
                q.push({ci,cj});
                vis[ci][cj]=true;
                
                if(mat[ci][cj]=='X'){
                    flag=true;
                    
                }
                // mat[ci][cj]='+';
            }
        }
    }
    

}

 
int main() {
    
    cin>>n;
    int si,sj,di,dj;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
            if(mat[i][j]=='@'){
                si=i;
                sj=j;
            }
            if(mat[i][j]=='X'){
                di=i;
                dj=j;
            }
        }
    }
    bfs(si,sj);
    // cout<<si<<sj<<di<<dj;


    int curDist = dis[di][dj]; 
    int curI = di, curJ = dj;
    while (curDist > 0) {
        mat[curI][curJ] = '+';
        for (int i = 0; i < 4; i++) {
            int ni = curI + mov[i].first;
            int nj = curJ + mov[i].second;
            if (valid(ni,nj) &&  dis[ni][nj] == curDist - 1) {
                curI = ni;
                curJ = nj;
                curDist--;
                break;
            }
        }
    }


    if(flag){
        cout<<"Y"<<endl;
        mat[di][dj]='+';
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j];
                
            }
        cout<<endl;
        }
        // cout<<dis[di][dj];
    

    }
    else cout<<"N"<<endl;
    return 0;
}