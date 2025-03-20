/*
 * @Author: dsaDadas11
 * @Date: 2024-08-09 14:12:09
 * @LastEditTime: 2024-08-09 14:12:32
 * @Description: go for it!
 */
/*
 开__int128过了...
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int __int128
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;

void print_int128(__int128 num) {
	if(num == 0) {
		cout << '0';
		return;
	}
	string result;
	bool is_negative = false;
	if (num < 0) {
		is_negative = true;
		num = -num;
	}
	while(num > 0) {
		result += '0' + num % 10;
		num /= 10;
	}
	if (is_negative) result += '-';
	reverse(result.begin(), result.end());
	cout << result;
}

void read_int128(__int128 &num) {
	string input;
	cin >> input;
	bool is_negative = false;
	if (input[0] == '-') {
		is_negative = true;
		input = input.substr(1);
	}
	num = 0;
	for(char c : input) {
		num = num * 10 + (c - '0');
	}
	if (is_negative) num = -num;
}

__int128 ggcd(__int128 a,__int128 b)
{
	__int128 r;
	while(a%b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return b;
}

void solve() {
	__int128 x, y;
	read_int128(x);
	read_int128(y);
	if(x % y == 0) {
		print_int128(y);
		cout << ' ';
		print_int128(x / y);
		cout << endl;
		return;
	}
	__int128 t = 2 * x;
	__int128 gg = ggcd(t, y);
	print_int128(y);
	cout << ' ';
	print_int128(t / gg);
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; 
	read_int128(T);
	while(T--) {
		solve();
	}
	return 0;
}
