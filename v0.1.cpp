#include<iostream.h>
#include<conio.h>
int map[9];
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
	for(int i=0;i<9;i++)
	map[i]=-1;
	int win=-1,pos;
	int pl=0;
	while(win==-1)
	{
		clrscr();
		displ();
		cout<<"\n\nEnter Player "<<pl<<"  move ";
		cin>>pos;
		if(!turn(pos,pl))
		{
			cout<<"\nCannot Move";
		}
		else
		{
			if(chk(pl))
				win=pl;
			else
				if(pl==0)
					pl=1;
				else
					pl=0;
		}
	}
	cout<<"\n\nPlayer "<<pl<<" wins";
	getch();
}