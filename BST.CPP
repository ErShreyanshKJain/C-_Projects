#include<iostream.h>
#include<conio.h>
#include<graphics.h>
class bst
{
	int root,left,left1,right,right1,temp,num[10],i,j,t1,t2,d1,d2;
	char s[10];
	public:
	void input();
	void create();
};
void bst::input()
{
	cout<<"\n enter 4 numbers \n";
	for(i=0;i<7;i++)
	{
		cin>>num[i];
	}
}

void bst::create()
{
	root=left=left1=right=right1=NULL;
	t1=320;
	t2=48;
	d1=320;
	d2=48;
	for(j=0;j<7;j++)
	{
		if(root==NULL)
		{
			root=num[j];
			circle(t1,t2,15);
			sprintf(s,"%d",num[j]);
			outtextxy(t1-5,t2,s);
		}
		if(num[j]>root)
		{
		temp=root;
		while(temp!=NULL)
		{
			if(num[j]<temp)
			{
				if(left1==NULL)
				{
					left1=num[j];
					if(right1==NULL && num[j]<temp)
					circle(t1=t1-40,t2=t2+48,15);
					sprintf(s,"%d",num[j]);
					outtextxy(t1-5,t2,s);
					break;
				}
				else
				{
					temp=left1;
					left1=NULL;
				}
			}
			if(num[j]>temp)
			{
				if(right1==NULL)
				{
					right1=num[j];
					if(left1==NULL && num[j]>temp)
					circle(t1=t1+64,t2=t2+48,15);
					sprintf(s,"%d",num[j]);
					outtextxy(t1-5,t2,s);
					break;
				}
				else
				{
					temp=right1;
					right1=NULL;
				}
			}
		}
		}
		if(num[j]<root)
		{
		temp=root;
		while(temp!=NULL)
		{
			if(num[j]<temp)
			{
				if(left==NULL)
				{
					left=num[j];
					if(right==NULL && num[j]<temp)
					circle(d1=d1-64,d2=d2+48,15);
					sprintf(s,"%d",num[j]);
					outtextxy(d1-5,d2,s);
					break;
				}
				else
				{
					temp=left;
					left=NULL;
				}
			}
			if(num[j]>temp)
			{
				if(right==NULL)
				{
					right=num[j];
					if(left==NULL && num[j]>temp)
					circle(d1=d1+40,d2=d2+48,15);
					sprintf(s,"%d",num[j]);
					outtextxy(d1-5,d2,s);
					break;
				}
				else
				{
					temp=right;
					right=NULL;
				}
			}
		}
		}
	}
}

void main()
{
	int gd=0,gm=0;
	clrscr();
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	bst b;
	b.input();
	b.create();
	getch();
}


