/*
 * @Author: dsaDadas11
 * @Date: 2024-08-15 21:04:12
 * @LastEditTime: 2024-08-15 21:04:25
 * @Description: go for it!
 */
// 高精度除以低精度
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string s;
int b;
int a[N],c[N];
string fun_div(string s,int b,int &t) // t为余数
{
	memset(a,0,sizeof a);
	memset(c,0,sizeof c);
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		a[i]=s[i]-'0';
	}
	t=0;
	int x=0;
	for(int i=0;i<len;i++)
	{
		c[i]=(t*10+a[i])/b;
		t=(t*10+a[i])%b;
	}
	while(c[x]==0&&x<len-1) x++;
	string ans="";
	for(int i=x;i<len;i++)
	{
		ans+=to_string(c[i]);
	}
	return ans;
	
}
void solve()
{
	cin>>s>>b;
	int t=0;
	cout<<fun_div(s,b,t)<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}

/*
 高精度除以高精度
 头文件删去了哈~
//char型转成int型，顺便实现翻转
void change(char s[5010], int arr[5010], int len) {
	for (int i = 0; i < len; i++) {
		arr[i] = s[len-i-1] - '0';
	}
}

//实现数组b的移动，n表示移动的位数
void mov_b (int b[5010], int temp[5010], int n, int lenb) {
	for (int i = 0; i < lenb; i++) {
		temp[i+n] = b[i];
	}
}


//比较数组a与数组temp的大小,由于数组是反转的，所以我们倒着比较
int compare (int a[5010], int temp[5010], int lena, int lent) {
	if (lena < lent) 
		return 0;
	if (lena == lent) {
		for (int i = lena-1; i >= 0; i--) {
			if (a[i] > temp[i])
				return 1;
			if (a[i] < temp[i])
				return 0;
		}
	}
	return 1;
}


int deleteZero (int a[5010], int lena) {
	lena = lena-1;
	while (a[lena] == 0) {
		lena--;
	}
	return (lena+1);
}

int main () {
	char s1[5010], s2[5010];
	int a[5010] = {0}, b[5010] = {0}, c[5010] = {0};
	scanf("%s", s1);
	scanf("%s", s2);
	int lena = strlen(s1);
	int lenb = strlen(s2);
	
	change(s1,a,lena);
	change(s2,b,lenb);
	
	//当被除数小于除数或者被除数为0时直接输出0
	if (lena < lenb || a[lena-1] == 0) {
		printf("0");
	} else {
		int index = lena - lenb;
		int n = index;//用n先存在一下index的值
		while (n >= 0) {
			//移动b，将移动后的b赋值给数组temp
			//n表示移动位数
			int temp[5050] = {0};
			mov_b (b, temp, n, lenb);
			int lent = n + lenb;			
			int flag = compare(a,temp,lena,lent);
			while (flag != 0) {	
				for(int i = 0; i < lena; i++) {
					//高精度减法
					if (a[i] < temp[i]) {
						a[i] += 10;
						a[i+1] -= 1;
					}
					a[i] = a[i] - temp[i];
				}
				c[n]++;
				
				//改变数组a的值后再次比较，就是去除数组a的"前导0"
				lena = deleteZero (a, lena);				
				flag = compare(a,temp,lena,lent);	
			}
			n--;
		}
		
		//去除数组c的前导0，不用传参数，咱不调用那个方法
		while (c[index] == 0) {
			index--;
		}
		
		//输出
		for (int i = index; i >= 0; i--)
			printf("%d", c[i]);
	}
	
	return 0;
}
*/