#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;
int N, M, K;

int recursion(int ind, int now, int apples);
int dist(int p1, int p2);

int x[1001];
int y[1001];
int t[1001];
int answer[1001];

int main()
{
	while(cin >> N >> M >> K && (N != 0 && M != 0 && K != 0))
	{
		for(int i = 1; i <= K; i++)
		{
			cin >> x[i] >> y[i] >> t[i];
			answer[i] = -42;
		};

		cin >> x[0] >> y[0];
		answer[0] = -1;
		int max = -1;

		for(int i = K; i >= 0; i-- )
		{
			answer[i] = 1;
			for(int j = i + 1; j <= K;j++ )
			{
				if( t[i] + dist(i,j) <= t[j] && answer[i] < answer[j] + 1 ) answer[i] = answer[j] + 1;
			}
		}
		for(int i = 0; i <= K; i++)
			if(answer[i] > max) max = answer[i];
		cout << answer[0] -1 << endl;		
	}
}

int recursion(int ind, int now, int apples)
{
	if(now > K) return 0;
	if(answer[now] != -42) return answer[now];
	else
	{
		int with = -1, without = 0;
		if( t[ind] + dist(ind,now) <= t[now] ) {with = 1 + recursion(now, now+1, apples+1); without = recursion(ind, now+1, apples);}
		else without = 0;
		answer[now] = without < with? with : without;
		printf("Exiting from %d, without an apple %d stayed with %d, and stay it %d\n", t[ind],t[now], without, with);
		if( without < with) printf("Catch  the  apple: %d\n", t[now]);

		return answer[now];
	}
}

int dist(int p1, int p2)
{
	int dx = x[p1] - x[p2];
	int dy = y[p1] - y[p2];
	if(dx<0) dx*=-1;
	if(dy<0) dy*=-1;

	return dx < dy? dy : dx;
}