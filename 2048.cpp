#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include"2048_mouse.cpp"
typedef struct block
{
	int val,x,y;

}b;
void draw()
{
	rectangle(150,100,450,400);
	setfillstyle(1,8);
	floodfill(152,102,15);
	line(150,150,450,150);
	line(150,200,450,200);
	line(150,250,450,250);
	line(150,300,450,300);
	line(150,350,450,350);

	line(200,100,200,400);
	line(250,100,250,400);
	line(300,100,300,400);
	line(350,100,350,400);
	line(400,100,400,400);


}
void main()
{
	int gd=0,gm,i,j,k,h,l,xval,yval,win=0;
	char c[1];
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	block a[6][6];
	xval=170;
	yval=120;
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	rectangle(339,420,255,450); //start box
	outtextxy(260,427,"Start");
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			a[i][j].val=0;
			a[i][j].x=xval;
			a[i][j].y=yval;
			xval=xval+50;
		}
		yval=yval+50;
		xval=170;
	}
	a[0][0].val=2;
	a[1][3].val=2;
	a[2][5].val=4;
	a[2][3].val=4;
	a[5][1].val=2;
	a[3][4].val=2;

	settextstyle(DEFAULT_FONT,HORIZ_DIR,1.7);
	draw();

	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			if(a[i][j].val!=0)
			{
				if(a[i][j].val==2)
				  {
					 setfillstyle(1,3);
					 floodfill(a[i][j].x+2,a[i][j].y+2,15);
				  }
				  if(a[i][j].val==4)
				  {
					 setfillstyle(1,6);
					 floodfill(a[i][j].x+2,a[i][j].y+2,15);
				  }
				sprintf(c,"%d",a[i][j].val);
				outtextxy(a[i][j].x,a[i][j].y,c);
			}
		}
	}
	ini_mouse();
	int b=0,xmou,ymou;
	while(1)
	{
		mouseread(&b,&xmou,&ymou);
		if(b==1 && (xmou>255 && xmou<339) && (ymou>420 && ymou<450))
		{

			settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
			outtextxy(150,70,"All set for kick start");
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1.7);
			goto game;
		}
	}
	game:
	while(1)
	{
	int key=getch();
	if(key==0 || key==224)
	{
	    key=getch()+256;
	}
	cleardevice();
	if(key==336)//down
	{
	    for(i=5;i>=0;i--)
	    {
		for(j=5;j>=0;j--)
		{
		    if(a[i][j].val!=0)
		    {
			if(i==0)
			{
			    for(l=5;l>i;l--)
			    {
				if(a[l][j].val==0)
				{
				    a[l][j].val=a[i][j].val;
				    a[i][j].val=0;
				    break;
				}
			    }
			}
			else
			{
			    for(k=i-1;k>=0;k--)
			    {
				if(a[k][j].val!=0 || k==0)
				{
				    if(a[i][j].val==a[k][j].val)
				    {
					a[i][j].val=a[i][j].val+a[k][j].val;
					a[k][j].val=0;
				    }
				    for(l=5;l>i;l--)
				    {
					if(a[l][j].val==0)
					{
					    a[l][j].val=a[i][j].val;
					    a[i][j].val=0;
					    break;
					}
				    }
				    break;
				}
			    }
			}
		    }
		}
	    }
	}
	if(key==331)//left
	{
	    for(i=0;i<6;i++)
	    {
		for(j=0;j<6;j++)
		{
		    if(a[i][j].val!=0)
		    {
			if(j==5)
			{
			    for(l=0;l<j;l++)
			    {
				if(a[i][l].val==0)
				{
				    a[i][l].val=a[i][j].val;
				    a[i][j].val=0;
				    break;
				}
			    }
			}
			else
			{
			    for(k=j+1;k<6;k++)
			    {
				if(a[i][k].val!=0 || k==5)
				{
				    if(a[i][k].val==a[i][j].val)
				    {
					a[i][j].val=a[i][j].val+a[i][k].val;
					a[i][k].val=0;
				    }
				    for(l=0;l<j;l++)
				    {
					if(a[i][l].val==0)
					{
					    a[i][l].val=a[i][j].val;
					    a[i][j].val=0;
					    break;
					}
				    }
				    break;
				}
			    }
			}
		    }
		}
	    }
	}
	if(key==333)
	{
	    for(i=0;i<6;i++)
	    {
		for(j=5;j>=0;j--)
		{
		    if(a[i][j].val!=0)
		    {
			if(j==0)
			{
			    for(l=5;l>j;l--)
			    {
				if(a[i][l].val==0)
				{
				    a[i][l].val=a[i][j].val;
				    a[i][j].val=0;
				    break;
				}
			    }
			}
			else
			{
			    for(k=j-1;k>=0;k--)
			    {
				if(a[i][k].val!=0 || k==0)
				{
				    if(a[i][k].val==a[i][j].val)
				    {
					a[i][j].val=a[i][k].val+a[i][j].val;
					a[i][k].val=0;
				    }
				    for(l=5;l>j;l--)
				    {
					if(a[i][l].val==0)
					{
					    a[i][l].val=a[i][j].val;
					    a[i][j].val=0;
					    break;
					}
				    }
				    break;
				}
			    }
			}
		    }
		}
	    }
	}
	if(key==328)
	{
	    for(i=0;i<6;i++)
	    {
		for(j=0;j<6;j++)
		{
		    if(a[i][j].val!=0)
		    {
			if(i==5)
			{
			    for(l=0;l<i;l++)
			    {
				if(a[l][j].val==0)
				{
				    a[l][j].val=a[i][j].val;
				    a[i][j].val=0;
				    break;
				}
			    }
			}
			else
			{
			    for(k=i+1;k<6;k++)
			    {
				if(a[k][j].val!=0 || k==5)
				{
				    if(a[k][j].val==a[i][j].val)
				    {
					a[i][j].val=a[i][j].val+a[k][j].val;
					a[k][j].val=0;
				    }
				    for(l=0;l<i;l++)
				    {
					if(a[l][j].val==0)
					{
					    a[l][j].val=a[i][j].val;
					    a[i][j].val=0;
					    break;
					}
				    }
				    break;
				}
			    }
			}
		    }
		}
	    }
	}
	if(key==27)
	{
		goto quit;
	}
	draw();
	outtextxy(1,53,"PRESS ESC TO EXIT...");
	for(i=0;i<6;i++)
	{
	    for(j=0;j<6;j++)
	    {
		if(a[i][j].val!=0)
		{
			if(a[i][j].val==2)
			 {
				 setfillstyle(1,3);
				 floodfill(a[i][j].x+2,a[i][j].y+2,15);
			 }
			 if(a[i][j].val==8)
			 {
				 setfillstyle(1,4);
				 floodfill(a[i][j].x+2,a[i][j].y+2,15);
			 }
			 if(a[i][j].val==16)
			 {
				 setfillstyle(1,10);
				 floodfill(a[i][j].x+2,a[i][j].y+2,15);
			 }
			 if(a[i][j].val==4)
			  {
				  setfillstyle(1,6);
				  floodfill(a[i][j].x+2,a[i][j].y+2,15);
			  }
			  if(a[i][j].val==32)
			 {
				 setfillstyle(1,6);
				 floodfill(a[i][j].x+2,a[i][j].y+2,15);
			 }
			 if(a[i][j].val>=64)
			 {
				 setfillstyle(1,5);
				 floodfill(a[i][j].x+2,a[i][j].y+2,15);
			 }
		    sprintf(c,"%d",a[i][j].val);
		    outtextxy(a[i][j].x,a[i][j].y,c);
		}
	    }
	}
      //fflush(stdin);
      int counter=0;
      random:
	int temp=rand();
	if(counter==20)
		goto back;
	i=rand()%6;
	j=rand()%6;

	if(a[i][j].val==0)
	{
		if(temp%2==0)
		{
			a[i][j].val=2;
			counter++;
		}
		else
		{
			a[i][j].val=4;
			counter++;
		}
	}
	else
	{
		counter++;
		goto random;
	}
	back:
	}

    quit:
	cleardevice();
	closegraph();
}
