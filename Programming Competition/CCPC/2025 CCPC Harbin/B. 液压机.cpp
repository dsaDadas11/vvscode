/*
 * @Author: dsaDadas11
 * @Date: 2025-11-11 17:28:10
 * @LastEditTime: 2025-11-11 17:28:26
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
// #define double long double
using namespace std;
const double eps=1e-5;
void solve()
{
	
	cout<<fixed<<setprecision(15);
	
	double xb,yb,vx,vy;
	double y1,y2,vy1,vy2;
	double x1,x2,vx1,vx2;
	cin>>xb>>yb>>vx>>vy;
	cin>>y1>>y2>>vy1>>vy2;
	cin>>x1>>x2>>vx1>>vx2;
	
	double t=(y2-y1)/(vy1+vy2);
	double ansy=y1+t*vy1;
	
	// 判断 x的情况
	if(vx>0) // 正向移动
	{
		if(vx<=vx2)
		{
			cout<<xb+vx*t<<' '<<ansy<<endl;
		}
		else
		{
			double t2=(x2-xb)/(vx-vx2);
			if(t2-t>=eps)
			{
				cout<<xb+t*vx<<' '<<ansy<<endl;
			}
			else
			{
				t-=t2;
				x2+=vx2*t2,xb+=vx*t2,x1-=vx1*t2;
				if(vx1>=vx)
				{
					cout<<xb-t*vx<<' '<<ansy<<endl;
                    return;
				}

                if((int)vx1==0&&(int)vx2==0)
                {
                    double tzhou=((x2-x1)/vx)*(double)(2);
                    t=fmod(t,tzhou);
                }
				
				bool sign=1; // 从正到负
                double s,sv;
				while(t>eps)
				{
					s=(sign?x1:x2);
					sv=(sign?vx1:vx2);
					t2=fmin(t,fabs(s-xb)/(vx-sv));
					t-=t2;
					// 更新坐标
					x1-=t2*vx1,x2+=t2*vx2;
					if(sign)
					{
						xb-=t2*vx;
					}
					else
					{
						xb+=t2*vx;
					}
					sign=sign^1;
				}
				
				cout<<xb<<' '<<ansy<<endl;
			}
		}
	}
    else // 负向移动
    {
        vx=fabs(vx);
        if(vx<=vx1)
		{
			cout<<xb-vx*t<<' '<<ansy<<endl;
		}
		else
		{
			double t2=(xb-x1)/(vx-vx1);
			if(t2-t>=eps)
			{
				cout<<xb-t*vx<<' '<<ansy<<endl;
			}
			else
			{
				t-=t2;
				x2+=vx2*t2,xb-=vx*t2,x1-=vx1*t2;
				if(vx2>=vx)
				{
					cout<<xb+t*vx<<' '<<ansy<<endl;
                    return;
				}

                if((int)vx1==0&&(int)vx2==0)
                {
                    double tzhou=((x2-x1)/vx)*(double)(2);
                    t=fmod(t,tzhou);
                }
				
				bool sign=0; // 从负到正
                double s,sv;
				while(t>eps)
				{
					s=(sign?x1:x2);
					sv=(sign?vx1:vx2);
					t2=fmin(t,fabs(s-xb)/(vx-sv));
					t-=t2;
					// 更新坐标
					x1-=t2*vx1,x2+=t2*vx2;
					if(sign)
					{
						xb-=t2*vx;
					}
					else
					{
						xb+=t2*vx;
					}
					sign=sign^1;
				}
				
				cout<<xb<<' '<<ansy<<endl;
			}
		}
    }
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}