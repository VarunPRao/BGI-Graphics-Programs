#include<graphics.h>
#include<conio.h>
#include<iostream.h>
#include<math.h>
#include<dos.h>
#include<stdio.h>

double radians(float x)
{
 double pi=3.14159;
 double rad=x*(pi/180);
 return rad;
 }
void main()
{
 int gm, gd = DETECT,qwer=1;
 initgraph(&gd,&gm,"C://TURBOC3/BGI");
 int mx,my,g=10,iv,a,vX,vY,x=1,dis,hp,mvY,mg=2,qwe=1,tx,marg=4,mrcY,bpXc;
 double ang,vx,vy,d,t;
 char string[5];
 mx=getmaxx();
 my=getmaxy();
 int counter=0;

 int bpX=40,bpY=my-80,mpX=40,mpY=my-80,q,p,i=0,j,ovY,mrX=40,mrY=my-90;
 cout<<"Enter the initial velocity (in metres/second): ";
 cin>>iv;
 cout<<"Enter the angle (in degrees) at which the projectile is launched: ";
 cin>>a;
 ang=radians(a);
 vX=cos(ang)*iv;
 vY=sin(ang)*iv;
 ovY=vY;
 mvY=vY;
 mrcY=vY;
 vx=cos(ang)*iv;
 vy=sin(ang)*iv;
 t=vy/5;
 d=t*vx;

 cout<<"\n\nScale: 1 pixel=1 metre";
 cout<<"\nBlue: Moon";
 cout<<"\nGreen: Earth";
 cout<<"\nRed: Mars";

 q=my-70;
 p=my-60;

 do
 {
  j=i*50;
  line(bpX+j,q,bpX+j,p);
  sprintf(string,"%d",j);
  outtextxy(bpX+j,p,string);
  i++;
  }while(i<=12);

 line(bpX,p,bpX,p-250);

 for(i=0;i<6;++i)
 {
  j=i*50;
  line(bpX,my-70-j,bpX-10,my-70-j);
  }

 setfillstyle(SOLID_FILL,BLUE);
 line(0,my-70,mx,my-70);
 circle(bpX,bpY,10);
 floodfill(bpX,bpY,WHITE);

 while(1)
 {
  bpX+=vX;
  mpX+=vX;
  mrX+=vX;

  mpY-=mvY;
  bpY-=vY;
  mrY-=mrcY;

  if(kbhit())
   break;

  if(qwe==1)
  {
   circle(bpX,bpY,10);
   setfillstyle(SOLID_FILL,GREEN);
   floodfill(bpX+1,bpY-9,WHITE);
   tx=x;
   bpXc=bpX;
   }

  circle(mpX,mpY,10);
  setfillstyle(SOLID_FILL,BLUE);
  floodfill(mpX+1,mpY+1,WHITE);

  if(qwer==1)
  {
   circle(mrX,mrY,10);
   setfillstyle(SOLID_FILL,RED);
   floodfill(mrX,mrY,WHITE);
   }

  vY-=g;
  mvY-=mg;
  mrcY-=marg;

  if(bpY+10>=my-80)
  {
   qwe=0;
   if(counter==0)
   {
    sound(1000);
    delay(3000);
    nosound();
    counter=1;
    }
   }
  if(mrY+10>=my-80)
   qwer=0;
  if((bpY+10>=my-80)&&(mpY+10>=my-80)&&(mrY+10>=my-80))
   break;

  x++;
  delay(900);
  }

 dis=bpXc-40;
 getch();
 cleardevice();
 closegraph();

 cout<<"On Earth: ";
 cout<<"\n_________";
 cout<<"\nAs per simulation: ";
 cout<<"\nX-component of veloctity (m/s): "<<vX;
 cout<<"\nY-component of velocity (m/s): "<<ovY;
 cout<<"\nTime taken (s): "<<tx;
 cout<<"\nDistance travelled (m): "<<dis;
 cout<<"\n\nAs per calculations: ";
 cout<<"\nX-component of veloctity (m/s): "<<vx;
 cout<<"\nY-component of velocity (m/s): "<<vy;
 cout<<"\nTime taken (s): "<<t;
 cout<<"\nDistance travelled (m): "<<d;

 getch();
 }
