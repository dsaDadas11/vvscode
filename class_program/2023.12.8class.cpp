#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
class Point
{
protected:
	int X,Y;
public:
	void setp(int,int);//可以不用写变量名
	int getx(){return X;}
	int gety(){return Y;}
	Point(){X=0,Y=0;cout<<'1'<<endl;}
	Point(int x,int y){X=x,Y=y;cout<<'1'<<endl;}
	//Point(int x=0,int y=0){x=x,y=y;} 将上面两个初始化函数合并
	Point(Point &p){X=p.X,Y=p.Y;cout<<'2'<<endl;} //X和p.X,Y和p.Y的顺序不要写反(我刚刚写反了debug半天)
	void show(){cout<<this->X<<" "<<this->Y<<endl;}//this是系统自带的指针
    friend void show2(Point &p); //友元函数 不需要加{},否则重复定义函数
	//析构函数
	~Point(){cout<<X<<" "<<Y<<endl;} //程序结束后删除创建的对象,类似栈删除
};
// void show1(Point &p)
// {
//     cout<<p.getx()<<" "<<p.gety()<<endl;
// }
void show2(Point &p)
{
    cout<<p.X<<" "<<p.Y<<endl;
}
void Point::setp(int x,int y){X=x,Y=y;}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	Point p1,p2(3,4),p3(p2);//p3为对象的复制
	p1.show();
    // show1(p1);
    // show2(p2);
	// p1=p2; //对象赋值
	// p1.show();
	p3.show();
	p2.show();
	return 0;
}