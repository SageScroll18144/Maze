#include <bits/stdc++.h>

#define ii pair<int, int>
#define iii pair<int, ii>
#define iiii pair<ii, ii>

using namespace std;

int l[] = {1, -1, 0, 0, -1, 1, -1, 1};
int c[] = {0, 0, 1, -1, -1, 1, 1, -1};

const int N = 1e4+10;
const int inf = 1e9+7;

int maze[N][N];
int dist[N][N];
int solved[N][N];
ii parent[N][N];
int n;

vector<iiii> path;

int find_indexOf(ii element){
    int left = 0;
    int right = path.size()-1;

    while(left<=right){
        int mid = (left+right)/2;
        if(path[mid].first.first == element.first){
            if(path[mid].first.second == element.second) return mid;
            return -1;
        }
        else if(path[mid].first.first < element.first) left = mid + 1;
        else if(path[mid].first.first > element.first) right = mid - 1; 

    }
    return -1;
}
void push_path(ii init_point, ii arrival_point){
    path.push_back({init_point, arrival_point});
    sort(path.begin(), path.end());
}

void remove_path(int index){
    if(index==-1) return;
    path.erase(path.begin()+index);

}

void init(){
    for(int i=0;i<N;i++) for(int j=0;j<N;j++){
        dist[i][j] = inf;
    }
}

void dijkstra(int x, int y){
    init();
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push({0, {x, y}});
    dist[x][y] = 0;

    while(!pq.empty()){

        int d = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();
        if(d > dist[u][v]) continue;

        solved[u][v]++;

        for(int i=0;i<(sizeof(l)/sizeof(int));i++){
            int a = u + l[i];
            int b = v + c[i];

            if(a<0||a>=n||b<0||b>=n) continue;

            if(dist[a][b] > dist[u][v]+maze[a][b]){
                dist[a][b] = dist[u][v]+maze[a][b];
                pq.push({dist[a][b], {a, b}});
                parent[a][b] = {u, v};
            }
        }   

    }

}
 

int main(){

    scanf("%d",&n);

    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        scanf("%d", &maze[i][j]);
    }
    dijkstra(0, 0);

    printf("%d\n", maze[0][0]+dist[n-1][n-1]);

    for(int i=0;i<n;i++){ 
        for(int j=0;j<n;j++){
            printf("%d ", solved[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<n;i++){ 
        for(int j=0;j<n;j++){
            printf("(%d, %d) -> (%d, %d)", parent[i][j].first, parent[i][j].second, i, j);
            printf("\n");   
        }
        
    }

    push_path({1,1},{1,1});

    remove_path(-1);

    cout<<path.size()<<endl;
    return 0;   
}