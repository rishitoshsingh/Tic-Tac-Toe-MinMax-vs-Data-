#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
int map[9];
int mvp[10];
int mvf[10];
int chk(int pl)
{
	if(map[0]==pl&&map[1]==pl&&map[2]==pl)
		return 1;
	else if(map[3]==pl&&map[4]==pl&&map[5]==pl)
		return 1;
	else if(map[6]==pl&&map[7]==pl&&map[8]==pl)
		return 1;
	else if(map[0]==pl&&map[3]==pl&&map[6]==pl)
		return 1;
	else if(map[1]==pl&&map[4]==pl&&map[7]==pl)
		return 1;
	else if(map[2]==pl&&map[5]==pl&&map[8]==pl)
		return 1;
	else if(map[0]==pl&&map[4]==pl&&map[8]==pl)
		return 1;
	else if(map[2]==pl&&map[4]==pl&&map[6]==pl)
		return 1;
	else 
		return 0;
}

int turn(int pos, int pl)
{
	if(map[pos]==-1)
	{
		map[pos]=pl;
		return 1;
	}
	else
	{
		return 0;
	}
}

void displ()
{
	for(int i=0;i<9;i++)
	{
		cout<<" "<<map[i];
		if(i==2||i==5||i==8)
			cout<<"\n";
	}
}

void main()
{
	for(int j=0;j<9;j++)
	map[j]=-1;
	int i=0,blocks=9;
	int win=-1,pos;
	int pl=0;
	srand((int)time(0));
	for(int k=0;k<10;k++)
	mvp[k]=-1;
	while(win==-1&&blocks!=0)
	{
		clrscr();
		displ();
		delay(1000);
		pos=rand()%10;
		if(turn(pos,pl)==1)
		{
			blocks--;
			if(chk(pl))
			{
				win=pl;
				mvp[i++]=pos;
				mvp[9]=pl;
			}
			else
			{
				mvp[i++]=pos;
				if(pl==0)
					pl=1;
				else
					pl=0;
			}
		}
	}
	for(i=0;i<10;i++)
		cout<<mvp[i]<<" ";
	cout<<"\n\nPlayer "<<mvp[9]<<" wins";
	getch();
}