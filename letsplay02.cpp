#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int map[9];
int mvp[10];
int blk=9;
int pc,play;
int win=-1,pos;
char file[5];
int flcr=0;
int lastmove,i,cnt=0,maxcnt=0,mincnt=5,lwin=0,ldraw=0,llost=0,randline,lcurr=0,winp=0,lostp=0;
int movenumber=-1;
int loading=0;
int flag=0;

int turn(int pos, int pl)
{
	if(map[pos]==-1)
	{
		map[pos]=pl;
		movenumber++;
		lastmove=pos;
		return 1;
	}
	else
	{
		return 0;
	}
}


void chktri()
{
	ifstream ao("curr.txt");
	while(!ao.eof())
	{	cout<<"chrcking";getch();
		for(i=0;i<10;i++)
			ao>>mvp[i];
		if(mvp[movenumber+2]==-1&&mvp[9]==play)
		{
			cout<<"set found";getch();
			flag=1;
			int qweasd=turn(mvp[movenumber+1],pc);
			ao.close();
			return ;
		}
	}
	ao.close();
}

void updateset()
{
	ifstream curr("curr.txt");
	ofstream tempcurr("temp.txt");
	while (!curr.eof())
	{
		for(i=0;i<10;i++)
			curr>>mvp[i];
		if(mvp[movenumber]==lastmove)
		{
			for(i=0;i<10;i++)
				tempcurr<<mvp[i]<<" ";
			tempcurr<<"\n";
		}
	}
	curr.close();
	tempcurr.close();
	if(remove("curr.txt")!=0)
	{
		cout<<"\nError in removing curr.txt";getch();
	}
	if(rename("temp.txt","curr.txt")!=0)
	{
		cout<<"\nError in renaming temp.txt to profit.txt";getch();
	}
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
}


void createset(int pos)
{
	if(pos==0)
		strcpy(file,"0.txt");
	if(pos==1)
		strcpy(file,"1.txt");
	if(pos==2)
		strcpy(file,"2.txt");
	if(pos==3)
		strcpy(file,"3.txt");
	if(pos==4)
		strcpy(file,"4.txt");
	if(pos==5)
		strcpy(file,"5.txt");
	if(pos==6)
		strcpy(file,"6.txt");
	if(pos==7)
		strcpy(file,"7.txt");
	if(pos==8)
		strcpy(file,"8.txt");
	ifstream fir(file);
	ofstream oir("curr.txt",ios::trunc);
	while(!fir.eof())
	{
		for(i=0;i<10;i++)
			fir>>mvp[i];
		for(i=0;i<10;i++)
			oir<<mvp[i]<<" ";
		oir<<"\n";
	}
	fir.close();
	oir.close();
}


void crcfofl()
{
	lcurr=0;
	lwin=0;
	ldraw=0;
	llost=0;
	maxcnt=0;
	mincnt=5;
	cnt=0;
	ifstream in("curr.txt");
	ofstream o1("win.txt",ios::trunc);
	ofstream o2("draw.txt",ios::trunc);
	ofstream o3("lost.txt",ios::trunc);
	ofstream o4("cnt4.txt",ios::trunc);

	while(!in.eof())
	{
		lcurr++;
		for(i=0;i<10;i++)
			in>>mvp[i];
		for(i=0;i<9;i++)
		{
			if(mvp[i]==-1)
			cnt++;
		}

		if(maxcnt<cnt&&cnt!=4)
			maxcnt=cnt;
		if(mincnt>cnt)
			mincnt=cnt;

		//cout<<"\nMaxcnt : "<<maxcnt;
		//cout<<"\nMincnt : "<<mincnt;
		if(mvp[9]==pc&&cnt!=4)
		{
			lwin++;
			for(i=0;i<10;i++)
				o1<<mvp[i]<<" ";
			o1<<"\n";
		}
		else if(mvp[9]==play&&cnt!=4)
		{
			llost++;
			for(i=0;i<10;i++)
				o3<<mvp[i]<<" ";
			o3<<"\n";
		}
		else if(mvp[9]==-1&&cnt!=4)
		{
			ldraw++;
			for(i=0;i<10;i++)
				o2<<mvp[i]<<" ";
			o2<<"\n";
		}
		else
		{
			for(i=0;i<10;i++)
				o4<<mvp[i]<<" ";
			o4<<"\n";
		}
		cnt=0;
	}
in.close();
o1.close();
o2.close();
o3.close();
o4.close();
cnt=0;
winp=0;lostp=0;
//##############################################################################Pushing profit moves in win.txt
ifstream ii("win.txt");
ofstream tp("temp.txt",ios::trunc);
while(!ii.eof())
{
	for(i=0;i<10;i++)
		ii>>mvp[i];
	for(i=0;i<9;i++)
	{
		if(mvp[i]==-1)
		cnt++;
	}
	if(cnt==maxcnt)
	{
		winp++;
		for(i=0;i<10;i++)
			tp<<mvp[i]<<" ";
		tp<<"\n";
	}
	cnt=0;
}
ii.close();
tp.close();
if(remove("win.txt")!=0)
{
	cout<<"\nError in removing win.txt";getch();
}
if(rename("temp.txt","win.txt")!=0)
{
	cout<<"\nError in renaming temp.txt to win.txt";getch();
}


cnt=0;
//##############################################################################Pushing profit moves in lost.txt
ifstream i2("lost.txt");
ofstream tp2("temp.txt",ios::trunc);
while(!i2.eof())
{
	for(i=0;i<10;i++)
		i2>>mvp[i];
	for(i=0;i<9;i++)
	{
		if(mvp[i]==-1)
		cnt++;
	}
	if(cnt==mincnt)
	{
		lostp++;
		for(i=0;i<10;i++)
			tp2<<mvp[i]<<" ";
		tp2<<"\n";
	}
	cnt=0;
}
i2.close();
tp2.close();
if(remove("lost.txt")!=0)
{
	cout<<"\nError in removing lost.txt";getch();
}
if(rename("temp.txt","lost.txt")!=0)
{
	cout<<"\nError in renaming temp.txt to lost.txt";getch();
}
}//end of crcfofl()


//#################################################################    move player
void mvplayer()
{
	if(play==0&&flcr==0)
	{
		do{
		cout<<"\nEnter your move : ";cin>>pos;--pos;
		}while(!(pos>=0&&pos<=8));
		createset(pos);
		int q=turn(pos,play);
		flcr++;
	}
	else
	{
		do{
		cout<<"\nEnter your move : ";cin>>pos;--pos;
		}while(!turn(pos,play));
		updateset();
	}
}//end of mvplayer()


//#################################################################    move pc
void mvpc()
{
	char tempf[10];
	if(pc==0&&flcr==0)
	{
		int q=turn(4,pc);
		createset(4);
		crcfofl();
		flcr++;
	}
	else
	{
		crcfofl();                                //Creates win, draw, lost, cnt4 files
		chktri();


		if(flag)
			if(lwin!=0)																//some chance of win
			{
				srand((int)time(0));
				randline=(rand()%winp)+1;
				strcpy(tempf,"win.txt");
			}
			else if(ldraw!=0)													//no chance of win than draw
			{
				srand((int)time(0));
				randline=(rand()%ldraw)+1;
				strcpy(tempf,"draw.txt");
			}
			else if(llost!=0)													//no chance of draw also then lost
			{
				srand((int)time(0));
				randline=(rand()%lostp)+1;
				strcpy(tempf,"lost.txt");
			}

		///////////////////////////////////////////////////////////////..........need improvement........................
		/*
		else if(pc==1)
		{

			chktri();

			if(ldraw!=0)																//some chance of win
			{
				srand((int)time(0));
				randline=(rand()%winp)+1;
				strcpy(tempf,"win.txt");
			}
			else if(lwin!=0)													//no chance of win than draw
			{
				srand((int)time(0));
				randline=(rand()%ldraw)+1;
				strcpy(tempf,"draw.txt");
			}
			else if(llost!=0)													//no chance of draw also then lost
			{
				srand((int)time(0));
				randline=(rand()%lostp)+1;
				strcpy(tempf,"lost.txt");
			}
		}*/
		int teln=0;
		ifstream qw(tempf);
		while(!qw.eof())
		{
			teln++;
			for(i=0;i<10;i++)
				qw>>mvp[i];
			if(randline==teln)
			{
				int t=turn(mvp[movenumber+1],pc);
				//cout<<"\nFound line and moved pc";getch();
				break;
			}
		}
		updateset();
	}
}//end of mvpc()
void qwaszx()
{
	cout<<"\nLwin : "<<lwin;
	cout<<"\nLlost : "<<llost;
	cout<<"\nLdraw : "<<ldraw;
	cout<<"\nWinp : "<<winp;
	cout<<"\nLostp : "<<lostp;
	cout<<"\nlcurr : "<<lcurr;
	cout<<"\nrandomline : "<<randline;
	getch();
}

void main()
{
	clrscr();
  for(i=0;i<9;i++)
	map[i]=-1;
	//srand((int)time(0));
	int qwert=(rand()%6)+1;
  if(qwert%2==0)
  {
    pc=0;play=1;
		cout<<"PC : 0\nPlayer : 1";getch();
  }
  else
  {
    pc=1;play=0;
		cout<<"PC : 1\nPlayer : 0";getch();
  }
	//pc=0;play=1;
	clrscr();
	displ();
	//
	qwaszx();
	//
	while(blk!=0)
	{
    if(pc==0)
    {
      mvpc();
			clrscr();
			displ();
			//
			qwaszx();
			//
      blk--;
      if(chk(pc))
      {
        blk=0;
        win=pc;
      }
      if(blk!=0)
      {
        mvplayer();
				clrscr();
				displ();
				//
				qwaszx();
				//
        blk--;
        if(chk(play))
        {
          blk=0;
          win=play;
        }
      }
    }
    else
    {
      mvplayer();
			clrscr();
			displ();
			//
			qwaszx();
			//
      blk--;
      if(chk(play))
      {
        blk=0;
        win=play;
      }
      if(blk!=0)
      {
        mvpc();
				clrscr();
				displ();
				//
				qwaszx();
				//
        blk--;
        if(chk(pc))
        {
          blk=0;
          win=pc;
        }
      }
    }
	}
	clrscr();
	displ();
	//
	qwaszx();
	//
	if(win==-1)
	cout<<"\nDRAW";
	else if(win==pc)
	cout<<"\nPC wins";
	else
	cout<<"\nYou win";
	getch();
	//
	qwaszx();
	//
}
