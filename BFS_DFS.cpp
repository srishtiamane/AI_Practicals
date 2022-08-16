#include <iostream>
#include <vector>

using namespace std;

class edge{
    public:
        int v1;
        int v2;
        bool visited;

    edge(int vv1, int vv2){
        v1 = vv1;
        v2 = vv2;
        visited = false;
    }
};

void bfs(vector<int> s, vector<edge> ed, vector<int> visited){
    if (s.size() == 0){
        return;
    }
    
    for (int i = 0; i < ed.size(); i++){
        if (ed[i].visited == false){
            if (ed[i].v1 == s[0]){
                s.push_back(ed[i].v2);
                ed[i].visited = true;
            }

            if (ed[i].v2 == s[0]){
                s.push_back(ed[i].v1);
                ed[i].visited = true;
            }
        }        
    }

    bool print = true;

    for (int i = 0; i < visited.size(); i++){
        if(s[0] == visited[i]){
            print = false;
        }
    }

    if(print){
        cout<<s[0]<<" ";
        visited.push_back(s[0]);
    }

    s.erase(s.begin());
    bfs(s, ed, visited);
}

void dfs(vector<int> s, vector<edge> ed, vector<int> visited){
    if (s.size() == 0){
        return;
    }
    
    for (int i = 0; i < ed.size(); i++){
        if (ed[i].visited == false){
            if (ed[i].v1 == s[s.size() - 1]){
                s.insert(s.begin(), ed[i].v2);
                ed[i].visited = true;
            }

            if (ed[i].v2 == s[s.size() - 1]){
                s.insert(s.begin(), ed[i].v1);
                ed[i].visited = true;
            }
        }        
    }

    bool print = true;

    for (int i = 0; i < visited.size(); i++){
        if(s[s.size() - 1] == visited[i]){
            print = false;
        }
    }

    if(print){
        cout<<s[s.size() - 1]<<" ";
        visited.push_back(s[s.size() - 1]);
    }

    s.pop_back();
    bfs(s, ed, visited);
}

int main(){
    vector<int> ver = {0, 1, 2, 3};
    vector<edge> ed = {edge(0, 1), edge(0,2), edge(0, 3), edge(1, 2), edge(2, 3), edge(3, 0)};
    
    vector<int> s = {1};
    vector<int> v;
    bfs(s, ed, v);
    cout<<"\n";
    dfs(s, ed, v);
}
