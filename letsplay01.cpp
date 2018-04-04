#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int map[9];
int mvp[10];
int blk=9;
int lastmove,i,cnt=0,maxcnt=0,line=0,randline;
int movenumber=-1;
int loading=0;
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

int turn(int pos, int pl)
{
	if(map[pos]==-1)
	{
		movenumber++;
		map[pos]=pl;
		lastmove=pos;
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


void mvpc()
{
	if(blk==9)
	{
		int t=turn(4,0);
	}
	else
	{
		maxcnt=0;cnt=0;line=0;
		//cout<<"\nMoving pc";getch();
		ifstream fin("curr.txt");
		ofstream fout("profit.txt",ios::trunc);
		//cout<<"\nfound profit.txt";getch();
		while(!fin.eof())
		{
			for(i=0;i<10;i++)
				fin>>mvp[i];
			for(i=0;i<9;i++)
			{
				if(mvp[i]==-1)
					cnt++;
			}
			if(maxcnt<cnt&&mvp[9]==0)    //		if(maxcnt<cnt&&cnt!=4&&mvp[9]==0)
				maxcnt=cnt;
			if(mvp[9]==0)  //			if(mvp[9]==0&&cnt<4)
			{
				for(i=0;i<10;i++)
					fout<<mvp[i]<<" ";
				fout<<"\n";
			}
			cnt=0;
		}
		fin.close();
		fout.close();
		//cout<<"\nMaxcnt : "<<maxcnt;getch();
		//cout<<"\nCreated profit.txt";
		//getch();
		ifstream dec("profit.txt");
		ofstream op("temp.txt");
		cnt=0;//--------------------------------------------------
		while(!dec.eof())
		{
			for(i=0;i<10;i++)
				dec>>mvp[i];
			for(i=0;i<9;i++)
			{
				if(mvp[i]==-1)
					cnt++;
				}
			//cout<<"\ncnt : "<<cnt;
			if(cnt==maxcnt)
			{
				//cout<<"\nfound";getch();
				line++;
				for(i=0;i<10;i++)
					op<<mvp[i]<<" ";
				op<<"\n";
			}
			cnt=0;//-------------------------------------------------

		}
		dec.close();
		op.close();

		//cout<<"\nWill remove profit.txt";getch();
		if(remove("profit.txt")!=0)
		{
			cout<<"\nError in removing profit.txt";getch();
		}
		//cout<<"\nRemoved\nRenaming temp.txt to profit.txt";getch();
		if(rename("temp.txt","profit.txt")!=0)
		{
			cout<<"\nError in renaming temp.txt to profit.txt";getch();
		}
		//cout<<"\nRenamed";getch();
		//cout<<"\nUpdated profit.txt";getch();
		//cout<<"\n Generating random number";getch();
		//cout<<"Lines : "<<line;getch();
		srand((int)time(0));
		randline=(rand()%line)+1;

		//cout<<"\nTotal Lines : "<<line;
		//cout<<"\nRandom line number : "<<randline;
		//getch();
		line=0;
		ifstream tu("profit.txt");
		//cout<<"\nAgain opened profit.txt";getch();

		while(!tu.eof())
		{

			line++;
			for(i=0;i<10;i++)
				tu>>mvp[i];
			if(randline==line)
			{
				int t=turn(mvp[movenumber+1],0);
				//cout<<"\nFound line and moved pc";getch();
				break;
			}
		}
		displ();
		tu.close();


		//cout<<"\nExiting mvpc";getch();

	}//end of else blk!=9
	updateset();
}//end of mvpc()
void mvplayer()
{
	int te;

	re:
	displ();
	cout<<"\n\nEnter your move : ";
	cin>>te;
	if(!turn(te,1))
		goto re;

		cout<<"\n Total moves done : "<<movenumber;
		cout<<"\n Last move : "<<lastmove<<"\n";
	updateset();
}



void main()
{
	for(i=0;i<9;i++)
	map[i]=-1;
	int win=-1,pos;
	int pl=0;


	while(blk!=0)
	{
		mvpc();blk--;
		if(chk(0))						// 0 for pc
		{
			blk=0;
			win=0;
		}

		if(blk!=0)
		{
			mvplayer();blk--;
			if(chk(1))
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
