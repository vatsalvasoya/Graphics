#include<iostream.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
typedef struct block
{
	int val,x,y;

}b;

void main()
{
	int gd=0,gm,i,j,k,l,xval,yval;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	block a[6][6];
	xval=170;
	yval=120;
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
	a[2][3].val=2;
	a[3][0].val=2;
	a[4][0].val=2;
	a[1][0].val=2;

	rectangle(150,100,450,400);

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

	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	char c[1];
  //	sprintf(c,"%d",a[0][0].val);
//	outtextxy(a[0][0].x,a[0][0].y,c);
       //	sprintf(c,"%d",a[2][3].val);
       //	outtextxy(a[2][3].x,a[2][3].y,c);
       for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			if(a[i][j].val!=0)
			{
				sprintf(c,"%d",a[i][j].val);
				outtextxy(a[i][j].x,a[i][j].y,c);
			}
		}
	}

	int key=getch();
	if(key==0 || key==224)
	{
		key=getch()+256;
	}
	cleardevice();

	if(key==336)
	{
	for(i=5;i>=0;i--)
	{
		for(j=5;j>=0;j--)
		{
			if(a[i][j].val!=0)
			{
				for(k=i-1;k>=0;k--)
				{
					if(a[k][j].val!=0 || k==0)
					{
						a[i][j].val=a[i][j].val+a[k][j].val;
						a[k][j].val=0;
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
	rectangle(150,100,450,400);

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
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			if(a[i][j].val!=0)
			{
				sprintf(c,"%d",a[i][j].val);
				outtextxy(a[i][j].x,a[i][j].y,c);
			}
		}
	}



	fflush(stdin);
	getch();
	cleardevice();
	closegraph();
}

