#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<iostream.h>
#include<stdio.h>
#include<math.h>

void main()
{
 int gd = DETECT,gm;
 int x,y,cx,cy,time,q,w,r,mins,secs,tsecs;//,a,u1,u2;
 float x1,y1,ang,id;
 float pi=3.142;
 char t[20];

 cout<<"Enter the time to count down (in seconds): ";
 cin>>time;

 initgraph(&gd,&gm,"C://TURBOC3/BGI");

 x=getmaxx();
 y=getmaxy();
 cx=(x/2);
 cy=(y/2);

 for(int i=0;i<=time;++i)
 {

  if(i<60)
  {
   q=i%10;
   w=i/10;
   r=0;
   mins=r;
   tsecs=w;
   secs=q;
   }
   else if(i>=60)
   {
    r=i/60;
    w=(i/10)-(6*r);
    q=i%10;
    mins=r;
    tsecs=w;
    secs=q;
    }

  id=i;

  ang=((id*6)*(pi/180));
  x1=180*sin(ang);
  y1=180*cos(ang);


  setcolor(1);
  circle(cx,cy,220);
  setcolor(14);

  line(cx,cy,cx+x1,cy-y1);
  settextstyle(4,HORIZ_DIR,4);
  outtextxy(cx-20,cy-210,"60");
  outtextxy(cx-20,cy+170,"30");
  outtextxy(cx-205,cy-20,"45");
  outtextxy(cx+170,cy-20,"15");

  sprintf(t,"%d:%d%d",mins,tsecs,secs);

  setcolor(4);
  settextstyle(7,HORIZ_DIR,5);
  outtextxy(cx-30,cy-100,t);

  delay(1000);

  if(i<time)
   {
    cleardevice();
    }
  }

 getch();
 closegraph();

 }


