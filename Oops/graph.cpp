#include<bits/stdc++.h>
using namespace std;
class Node{
    int owner;
    int cnt;
    int maxCnt;
    public:
    Node(const int maxCnt):owner(-1),cnt(0),maxCnt(maxCnt){};
    void inc(){
        if(cnt<maxCnt)
            cnt++;
    }
    bool isUnstable(){
        return cnt==maxCnt;
    }
    int getCnt(){
        return cnt;
    }
    int getOwner(){
        return owner;
    }
    void setOwner(int owner){
        this->owner=owner;
    }
    void setCnt(int cnt){
        this->cnt=cnt;
    }
    void setMaxCnt(int cnt){
        this->maxCnt=cnt;
    }
};
class Graph{
    int m;
    int n;
    int playerCnt;
    int currChance;
    int totalCnt;
    int playerAliveCnt;
    vector<vector<Node*>> graph;
    vector<int> playerCellCnt;
    vector<bool> isAlive;
    static const vector<vector<int>> neig;
    public:
    Graph(const int m,const int n,const int playerCnt=2){
        this->m=m;
        this->n=n;
        this->playerCnt=playerCnt;
        this->isAlive=vector<bool> (n,true);
        this->playerCellCnt=vector<int> (playerCnt,0);
        this->currChance=0;
        this->totalCnt=0;
        this->playerAliveCnt=playerCnt;
        this->graph=vector<vector<Node*>> (m,vector<Node*>(n));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cnt=0;
                for(auto each:neig){
                    if(isValidPosition(i+each[0],j+each[1]))
                        cnt++;
                }
                graph[i][j]=new Node(cnt);
            }
        }
    }
    bool isGameOver(){
        if(totalCnt<=playerCnt)
            return false;
        return playerAliveCnt==1;
    }
    void print(){
        cout<<"Player Cell Cnts : ";
        for(int i=0;i<playerCnt;i++)
            cout<<playerCellCnt[i]<<" ";
        cout<<endl;
        cout<<"Player Alive : ";
        cout<<playerAliveCnt<<endl;
        for(int j=0;j<=7*n;j++)
                cout<<"-";
            cout<<endl;
        for(int i=0;i<m;i++){
            cout<<"| ";
            for(int j=0;j<n;j++){
                for(int k=0;k<4;k++)
                    cout<<((k<graph[i][j]->getCnt())?(char)('A'+graph[i][j]->getOwner()):' ');
                cout<<" | ";
            }
            cout<<endl;
            
            for(int j=0;j<=7*n;j++)
                cout<<"-";
            cout<<endl;
        }
        cout<<endl;
    }
    bool isValidPosition(int x,int y){
        return x>=0 && x<m && y>=0 && y<n;
    }
    void gameOverMessage(){
        cout<<"Game Over"<<endl;
        cout<<"Player "<<(currChance+1)<<" Won!!"<<endl;
        print();
    }
    void input(int x,int y){
        cout<<"Turn "<<currChance+1<<endl;
        cout<<"Inserting "<<x<<" "<<y<<endl;
        x--;
        y--;
        if(!isValidPosition(x,y)){
            cout<<"Incorrect Location!!"<<endl;
            return;
        }
        int cellOwner=graph[x][y]->getOwner();
        if(cellOwner!=-1 && cellOwner!=currChance){
            cout<<"You cannot place here!!"<<endl;
            return;
        }
        totalCnt++;
        if(cellOwner==-1){
            playerCellCnt[currChance]++;
            graph[x][y]->setOwner(currChance);
        }
        graph[x][y]->inc();
        if(graph[x][y]->isUnstable()){
            queue<pair<int,int>> qu;
            qu.push({x,y});
            
            while(!qu.empty()){
                if(isGameOver())
                    break;
                print();
                int cx=qu.front().first;
                int cy=qu.front().second;
                qu.pop();
                int currCellOwner=graph[cx][cy]->getOwner();
                playerCellCnt[currCellOwner]--;
                if(playerCellCnt[currCellOwner]==0){
                    playerAliveCnt--;
                    isAlive[currCellOwner]=false;
                }
                graph[cx][cy]->setCnt(0);
                graph[cx][cy]->setOwner(-1);
                for(auto each:neig){
                    int nx=cx+each[0];
                    int ny=cy+each[1];
                    if(isValidPosition(nx,ny)){
                        int neigOwner=graph[nx][ny]->getOwner();
                        if(neigOwner!=currChance){
                            if(neigOwner!=-1){
                                playerCellCnt[neigOwner]--;
                                if(playerCellCnt[neigOwner]==0){
                                    playerAliveCnt--;
                                    isAlive[neigOwner]=false;
                                }
                            }
                            playerCellCnt[currChance]++;
                            if(playerCellCnt[currChance]==1)
                            playerAliveCnt++;
                        }
                        graph[nx][ny]->inc();
                        graph[nx][ny]->setOwner(currChance);
                        if(graph[nx][ny]->isUnstable())
                            qu.push({nx,ny});
                    }
                }
            }
        }
        if(isGameOver()){  
            gameOverMessage();
            return;
        }
        do{
            currChance=(currChance+1)%playerCnt;
        }while(!isAlive[currChance]);
        
    }
    ~Graph(){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                delete(graph[i][j]);
        }
    }
};
const vector<vector<int>> Graph::neig={{-1,0},{1,0},{0,-1},{0,1}};
int main(){
    Graph *g=new Graph(3,3,3);
    g->print();
    g->input(1,1);
    g->print();
    return 0;
}