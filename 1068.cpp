//https://www.acmicpc.net/problem/1068
//변수 초기화를 하자.

#include <stdio.h>
#include <queue>

using namespace std;

queue<int> q;

int main(void){
	int i, j, x, cnt=0, N, K, tree[50];
	
	scanf("%d", &N);
	for(i=0;i<N;i++){
		scanf("%d", &tree[i]);
	}
	scanf("%d", &K);
	
	q.push(K);
	while(!q.empty()){
		x = q.front();
		tree[x] = -10;
		q.pop();
		for(i=0;i<N;i++){
			if(tree[i] == x){
				q.push(i);
			}
		}
	}

	for(i=0;i<N;i++){
		if(tree[i]==-1){
			q.push(i);
		}
	}

	while(!q.empty()){
		x = q.front();
		q.pop();
		for(i=j=0;i<N;i++){
			if(tree[i]==x){
				q.push(i);
				j++;
			}
		}
		if(!j)cnt++;
	}printf("%d\n", cnt);
	return 0;
}