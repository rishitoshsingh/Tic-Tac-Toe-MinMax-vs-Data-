#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int map[9];
int tmap[9];
int mvp[10];
int blk=9;

int win=-1,pos;

struct move
{
  int mv;
  int score;
}


void cpy();
{
  for(i=0;i<10;i++)
    tmap[i]=map[i];
}

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
  if(!(pos>=0&&pos<=8))
    return 0;
	if(map[pos]==-1)
	{
		movenumber++;
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
		if(map[i]==-1)
			cout<<" *";
		else
			cout<<" "<<map[i];
		if(i==2||i==5||i==8)
			cout<<"\n";
	}
	cout<<"\n Total moves done : "<<movenumber;
	cout<<"\n Last move : "<<lastmove<<"\n";
}


void mvplayer()
{
  do{
  cout<<"\nEnter your move : ";cin>>pos;--pos;
  }while(!turn(pos,play));
}

struct move minmax(int mp[], int pl)
{
  if(chk(pc)==1)
    return
  else if(chk(play)==1)
    return
  else if()
    return

  for(i=0;i<9;i++)
  {
    if(turn(i,pl))
    {
      move ai;
      ai.mv=i;
      if(pl==pc)
        ai.score=minmax(mp,play);
      else
        ai.score=minmax(mp,pc);
      mp[i]=-1;
    }

  }
  if(pl==pc)
  {

  }
  else
  {

  }
}

void mvpc()
{

}


void main()
{
	for(i=0;i<9;i++)
	map[i]=-1;




	while(blk!=0)
	{
		mvplayer();blk--;
		if(chk(1))						// 0 for pc
		{
			blk=0;
			win=0;
		}

		if(blk!=0)
		{
			mvpc();blk--;
			if(chk(0))
			{
				blk=0;
				win=1;
			}
		}

	}


	clrscr();
	displ();
	if(win==-1)
	cout<<"\nDRAW";
	else if(win==0)
	cout<<"\nPC wins";
	else
	cout<<"\nYou win";
	getch();

}//end of main()
