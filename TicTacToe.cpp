#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>

class PVE
{
 int score1,score2,sel,markX,markY;
 int mx,my,cx,cy,p1,p2;

 void detect()
 {
  mx=getmaxx();
  my=getmaxy();
  cx=mx/2;
  cy=my/2;
  }

 void display()
 {
  setbkcolor(1);
  setcolor(15);
  for(int i=4;i>=0;--i)
  {
   line(p1,p2+81+i,p1+250,p2+81+i);
   line(p1,p2+166+i,p1+250,p2+166+i);
   line(p1+81+i,p2,p1+81+i,p2+250);
   line(p1+166+i,p2,p1+166+i,p2+250);
   }
  }

  void red()
  {
   cout<<markX<<" "<<markY;
   }
  void updatemark()
  {
   switch(sel)
   {
    case 77:  ++markX;
	      break;
     case 75: --markX;
	      break;
     case 72: --markY;
	      break;
     case 80: ++markY;
	      break;
    }
   if(markX>3)
    markX=3;
   if(markX<1)
    markX=1;
   if(markY>3)
    markY=3;
   if(markY<1)
    markY=1;
   }

 public:
 // void displayscores();
    PVE()
    {
     detect();
     p1=cx-250;
     p2=cy-125;
     markX=1;
     markY=1;
     }

    void playloop()
    {
     do
     {
      display();
      red();
      sel=getch();
      if(sel==13)
      {
     //drawplayer();
     //drawAI();
       }
      else
       updatemark();
      cleardevice();
      }while(sel!=27);
     }
 };

//class PVP: public PVE

void Menu(int x=0)
{
 int mx,my,cy,qx,mmenu=0,menu;
 mx=getmaxx();
 my=getmaxy();
 cy=my/5;
 qx=mx/4;
 setbkcolor(0);
 settextstyle(1,HORIZ_DIR,5);
 outtextxy(qx,cy,"MAIN MENU");
 settextstyle(4,HORIZ_DIR,4);
 outtextxy(qx,cy+100,"Play");
 outtextxy(qx,cy+150,"Settings");
 outtextxy(qx,cy+200,"Exit");
 setcolor(15);
 circle(qx-5,cy+115,3);

 again:;
 menu=getch();

 if(menu==80)
  mmenu++;
 else if(menu==72)
  mmenu--;

 else if(menu==13)
 {
  if(mmenu==0)
   goto cont;
  else if(mmenu==1)
   //settings(0);
   exit(0);
  else if(mmenu==2)
   exit(0);
  }

 if(mmenu<=0)
   mmenu=0;
 if(mmenu>=2)
   mmenu=2;

  if(mmenu==0)
  {
   setcolor(15);
   circle(qx-5,cy+115,3);
   setcolor(0);
   circle(qx-5,cy+167,3);
   circle(qx-5,cy+215,3);
   goto again;
   }

  if(mmenu==1)
  {
   setcolor(0);
   circle(qx-5,cy+115,3);
   circle(qx-5,cy+215,3);
   setcolor(15);
   circle(qx-5,cy+167,3);
   goto again;
   }

  if(mmenu==2)
  {
   setcolor(0);
   circle(qx-5,cy+115,3);
   circle(qx-5,cy+167,3);
   setcolor(15);
   circle(qx-5,cy+215,3);
   goto again;
   }

 cont:;
 cleardevice();
 }

void main()
{
 int gm,gd = DETECT;
 initgraph(&gd,&gm,"C://TURBOC3/BGI");
 PVE obj;

 while(1)
 {
  Menu();
  obj.playloop();
  }

 getch();
 cleardevice();
 closegraph();
	
 }
