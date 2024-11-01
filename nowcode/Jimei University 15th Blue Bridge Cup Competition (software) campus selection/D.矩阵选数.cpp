/*
 * @Author: dsaDadas11
 * @Date: 2024-01-20 20:30:51
 * @LastEditTime: 2024-01-20 20:31:12
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cout<<"23366"<<endl;
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 13; // 矩阵的大小
const int INF = 1e9; // 无穷大

int matrix[N][N]; // 矩阵
int lx[N], ly[N]; // 顶点的标号
int match[N]; // 匹配的结果，match[i]表示第i列与哪一行匹配
bool vx[N], vy[N]; // 记录顶点是否被访问过
int slack[N]; // 记录顶点的松弛量

// 寻找增广路，返回是否找到
bool find(int x) {
	vx[x] = true; // 标记第x行被访问过
	for (int y = 0; y < N; y++) { // 遍历每一列
		if (vy[y]) continue; // 如果第y列已经被访问过，跳过
		int t = lx[x] + ly[y] - matrix[x][y]; // 计算顶点标号之和与边权值的差
		if (t == 0) { // 如果是可行边
			vy[y] = true; // 标记第y列被访问过
			if (match[y] == -1 || find(match[y])) { // 如果第y列未匹配，或者可以找到增广路
				match[y] = x; // 更新匹配
				return true; // 返回找到增广路
			}
		} else { // 如果不是可行边
			slack[y] = min(slack[y], t); // 更新松弛量
		}
	}
	return false; // 返回没有找到增广路
}

// KM算法主函数，返回最大权匹配的权值之和
int km() {
	memset(match, -1, sizeof(match)); // 初始化匹配为空
	memset(ly, 0, sizeof(ly)); // 初始化y部的标号为0
	for (int i = 0; i < N; i++) { // 初始化x部的标号为与之相连的最大边权
		lx[i] = 0;
		for (int j = 0; j < N; j++) {
			lx[i] = max(lx[i], matrix[i][j]);
		}
	}
	for (int x = 0; x < N; x++) { // 依次寻找每个x部顶点的匹配
		for (int i = 0; i < N; i++) slack[i] = INF; // 初始化松弛量为无穷大
		while (true) { // 不断地寻找增广路，直到找到为止
			memset(vx, false, sizeof(vx)); // 初始化x部的访问标记为false
			memset(vy, false, sizeof(vy)); // 初始化y部的访问标记为false
			if (find(x)) break; // 如果找到了增广路，退出循环
			int d = INF; // 初始化顶点标号的改变量为无穷大
			for (int i = 0; i < N; i++) { // 遍历y部的每个顶点
				if (!vy[i]) d = min(d, slack[i]); // 找出最小的松弛量
			}
			for (int i = 0; i < N; i++) { // 根据最小的松弛量更新顶点的标号
				if (vx[i]) lx[i] -= d;
				if (vy[i]) ly[i] += d;
				else slack[i] -= d;
			}
		}
	}
	int res = 0; // 记录最大权匹配的权值之和
	for (int i = 0; i < N; i++) { // 遍历y部的每个顶点
		if (match[i] != -1) res += matrix[match[i]][i]; // 累加匹配边的权值
	}
	return res; // 返回最大权匹配的权值之和
}

int main() {
	// 输入矩阵
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];
		}
	}
	// 输出最大权匹配的权值之和
	cout << km() << endl;
	return 0;
}

*/