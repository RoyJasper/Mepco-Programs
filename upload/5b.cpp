#include<iostream>
#include<math.h>
using namespace std;
class rec
{
    float xco;
    float yco;
    public:
        rec()
        {
            xco=0.0,yco=0.0;
        }
        rec(float x,float y)
        {
            xco=x;
            yco=y;
        }
        void display()
        {
            cout<<xco<<","<<yco;
        }
       int rec(polar p)
        {
          float m=p.getradius();
          float n=p.getangle();
          xco=m * cos(n);
          yco=m * sin(n);
        }
};
class polar
{
    float radius,angle;
    public:
        polar()
        {
            radius=0.0;
            angle=0.0;
        }
        polar (float a,float b)
        {
            radius=a;
            angle=b;
        }
        void show()
        {
            cout<<radius<<","<<angle;
        }
        float getradius()
        {
          return radius;
        }
        float getangle()
        {
          return angle;
        }
};
int main()
{
    rec r1;
    polar p1(23.2,11.1);
    r1=p1;
    p1.show();
    r1.display();
}

