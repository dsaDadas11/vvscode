/*
 * @Author: dsaDadas11
 * @Date: 2024-08-15 20:26:33
 * @LastEditTime: 2024-08-15 20:26:59
 * @Description: go for it!
 */
/*
 FFT-快速傅里叶变换：（时间复杂度O(nlogn)）
*/
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

struct C {
	double r, i;
	C() {}
	C(double _r, double _i) : r(_r), i(_i) {}
	inline C operator + (const C & a) const {
		return C(r + a.r, i + a.i);
	}
	inline C operator - (const C & a) const {
		return C(r - a.r, i - a.i);
	}
	inline C operator * (const C & a) const {
		return C(r*a.r - i*a.i, r*a.i + i*a.r);
	}
};

typedef long long LL;
const double pi = acos(-1.0);
const int N = 1e6+7;
C a[N<<2], b[N<<2];
char num1[N], num2[N];
LL ret[N<<2];

void brc(C *y, int L) {
	int i, j, k;
	for (i=1,j=L>>1; i<L-1; ++i) { // 二进制平摊反转置换 O(NlogN)
		if (i < j) swap(y[i], y[j]);
		k = L>>1;
		while (j >= k) {
			j -= k;
			k >>= 1;
		}
		j += k;
	}
}

void FFT(C *y, int L, int dir) {
	brc(y, L);
	for (int h = 2; h <= L; h <<= 1) { // 枚举所需计算的点数 
		C wn(cos(dir*2*pi/h), sin(dir*2*pi/h)); // h次单位复根 
		for (int j = 0; j < L; j += h) { // 原序列被分成了L/h段h长序列 
			C w(1, 0); // 旋转因子 
			for (int k = j; k < j+h/2; ++k) { // 因为折半定理，只需要计算枚举一半的长度即可 
				C u = y[k];
				C t = w*y[k+h/2];
				y[k] = u + t;
				y[k+h/2] = u - t;
				w = w * wn; // 更新旋转因子 
			}
		}
	}
	if (dir == 1) {
		for (int i = 0; i < L; ++i) {
			y[i] = y[i] * C(1.0/L, 0);
		}
	}
}

int main() {
	scanf("%s %s", num1, num2);
	int len1 = strlen(num1), len2 = strlen(num2);
	int ML = len1+len2-1, L = 1;
	while (L < ML) L <<= 1;
	for (int i = len1-1, j = 0; i >= 0; --i, ++j) {
		a[j] = C(num1[i]-'0', 0);
	}
	for (int i = len2-1, j = 0; i >= 0; --i, ++j) {
		b[j] = C(num2[i]-'0', 0);
	}
	for (int i = len1; i < L; ++i) a[i] = C(0, 0);
	for (int i = len2; i < L; ++i) b[i] = C(0, 0);
	FFT(a, L, -1), FFT(b, L, -1);
	for (int i = 0; i < L; ++i) {
		a[i] = a[i] * b[i];
	}
	FFT(a, L, 1);
	for (int i = 0; i < L; ++i) {
		ret[i] = (LL)floor(a[i].r + 0.5);
	}
	for (int i = 0; i < L; ++i) {
		ret[i+1] += ret[i] / 10;
		ret[i] %= 10;
	}
	int p = L;
	while (!ret[p] && p) --p;
	while (p >= 0) printf("%d", (int)ret[p--]);
	puts("");
	return 0;
}