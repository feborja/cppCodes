#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, k, s, count, i0, j0;
    bool first = true;
	cin >> n >> m >> k;
    char enter;
	vector <vector <char>> grilla(n, vector<char>(m));
    // Lectura de grilla
    s = 0;
    count = 0;
    for (int i = 0; i < (n); i++){
        for (int j = 0 ; j < (m); j++){
            cin >> enter; 
            grilla[i][j] = enter;
            if (enter == '.'){
                s++;
                if(first){
                    first= false;
                    i0 = i; 
                    j0 = j;
                }
            }
        }
    }

	vector <int> dx = {1, 0, -1, 0};
	vector <int> dy = {0, 1, 0, -1};
	// dx y dy indican los cuatro movimientos posibles. Un vector de movimiento sería (dx[i], dy[i])
	queue <pair<int,int>> q; // Nuestros nodos ahora son pares (x, y)
	vector <vector <int>> dist(n, vector <int>(m,0)); // ahora nuestro vector dist es una matriz de nxm
	q.push({i0,j0}); // empezaremos desde el (0,0)
    dist[i0][j0] = 1;
    count = 1;
	while(!q.empty()){
		auto [x,y] = q.front();
		q.pop();
        if (grilla[x][y]=='#'){
                if(y<(m-1)){
                    y++;
                    q.push({x,y});
                }
                else{
                    x++;
                    q.push({x,y});
                }
                continue;
            }
		for(int dir=0; dir<4; dir++){
			int nx = x+dx[dir];
			int ny = y+dy[dir];
			if((nx < 0) or (nx >= n) or (ny < 0) or (ny >= m)){
                continue;
            }
			if(grilla[nx][ny]=='#') continue;
			if(dist[nx][ny] != 0) continue; // ya fue visitado
			dist[nx][ny] = 1; //dist[x][y]+1;
			q.push({nx,ny});
            count++;
            if(count > s-k){
                grilla[nx][ny] = 'X';
            }
		}
	}
	// la respuesta queda guardada en dist
    // Se printea el resultado
    for (int i = 0; i < (n); i++){
        for (int j = 0 ; j < (m); j++){
            cout << grilla[i][j];
        }
        cout << endl;
    }
    return 0;
}