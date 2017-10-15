void Menu()
{
 int mx,my,cy,qx,mmenu=1,menu;
 mx=getmaxx();
 my=getmaxy();
 cy=my/5;
 qx=mx/4;
 settextstyle(8,HORIZ_DIR,5);
 outtextxy(qx,cy,"MAIN MENU");
 settextstyle(4,HORIZ_DIR,4);
 outtextxy(qx,cy+100,"Play");
 outtextxy(qx,cy+150,"Exit");
 setcolor(15);
 circle(qx-5,cy+115,3);

 again:;
 menu=getch();

 if(menu==80)
 {
  mmenu=0;
  setcolor(0);
  circle(qx-5,cy+115,3);
  setcolor(15);
  circle(qx-5,cy+165,3);
  goto again;
  }
 else if(menu==72)
 {
  mmenu=1;
  setcolor(15);
  circle(qx-5,cy+115,3);
  setcolor(0);
  circle(qx-5,cy+165,3);
  goto again;
  }
 else if(menu==13)
 {
  if(mmenu==0)
  {
   exit(0);
   }
  else if(mmenu==1)
  {
   goto cont;
   }
  }
 else
  goto again;

 cont:;
 cleardevice();
 
 }
