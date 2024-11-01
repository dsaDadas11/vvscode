#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
class Point
{
	//private: 不建议使用,使用protected:
	protected: //属性，数据
		int X,Y;
	public: //对对象进行的操作
		Point(){X=Y=0;cout<<"OK"<<endl;} //初始化
		Point(int x,int y){X=x,Y=y;cout<<"OK"<<endl;} //初始化，和上面函数构成重载函数
		void setP(int x,int y){X=x,Y=y;} //设置点位置
		void disP(){cout<<X<<" "<<Y<<endl;}; //显示点位置
		double disto(){return sqrt(X*X+Y*Y);}; //到原点距离
		double dis(Point &p) //两点距离
        {
            int x,y;
            x=X-p.X,y=Y-p.Y;
            return sqrt(x*x+y*y);
        }
		int getx(){return X;} //获得自己横坐标
		int gety(); //获得自己纵坐标

};
int Point::gety(){return Y;}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	Point p1; //无参时初始化为0，避免出现随机值
    // p1.X=10; 报错，受保护
    p1.disP();
    p1.setP(10,10);
    p1.disP();
	Point p2(9,9);
	p2.disP();
	return 0;
}
//Point(int x=0,int y=0):X(x),Y(y){} 进行初始化