#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<fstream.h>
int map[9];
int mvp[10];
int mvnum=0;
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
		mvp[mvnum++]=pos;
		return 1;
	}
	else
	{
		return 0;
	}
}
/*
void displ()
{
	for(int i=0;i<9;i++)
	{
		cout<<" "<<map[i];
		if(i==2||i==5||i==8)
			cout<<"\n";
	}
}
*/

void upload()
{
	ofstream fin("games.txt",ios::app);
	for(int i=0;i<10;i++)
			fin<<mvp[i]<<" ";
	fin<<"\n";
	fin.close();

}

void main()
{
	for(int j=0;j<9;j++)
		map[j]=-1;
	for(int k=0;k<10;k++)
		mvp[k]=-1;
	long int totalnum=0;

	clrscr();

	int q,w,e,r,t,y,u,i,o;
	for(q=0;q<9;q++)
	{
		if(turn(q,0))//if turned
		{
			if(!chk(0))//if triplet not found
			{//################################################################################################################################
				for(w=0;w<9;w++)
				{
					if(turn(w,1))//if turned
					{
						if(!chk(1))//if triplet not found
						{//##########################################################################################################################
							for(e=0;e<9;e++)
							{
								if(turn(e,0))//if turned
								{
									if(!chk(0))//if triplet not found
									{//####################################################################################################################
										for(r=0;r<9;r++)
										{
											if(turn(r,1))//if turned
											{
												if(!chk(1))//if triplet not found
												{//##############################################################################################################
													for(t=0;t<9;t++)
													{
														if(turn(t,0))//if turned
														{
															if(!chk(0))//if triplet not found
															{//########################################################################################################
																for(y=0;y<9;y++)
																{
																	if(turn(y,1))//if turned
																	{
																		if(!chk(1))//if triplet not found
																		{//##################################################################################################
																			for(u=0;u<9;u++)
																			{
																				if(turn(u,0))//if turned
																				{
																					if(!chk(0))//if triplet not found
																					{//###########################################################################################
																						for(i=0;i<9;i++)
																						{
																							if(turn(i,1))//if turned
																							{
																								if(!chk(1))//if triplet not found
																								{//####################################################################################
																									for(o=0;o<9;o++)
																									{
																										if(turn(o,0))//if turned
																										{
																											if(chk(0)==1)
																												mvp[9]=0;
																											else
																												mvp[9]=-1;
																											upload();
																											mvp[9]=-1;
																											map[o]=-1;
																											mvp[--mvnum]=-1;

																											/*if(!chk(0))//if triplet not found
																											{//#############################################################################
																												upload();

																											}//#############################################################################
																											else
																											{
																												mvp[9]=0;
																												upload();
																												mvp[9]=-1;
																												map[o]=-1;
																												mvp[--mvnum]=-1;
																											}*/
																										}
																									}//o
																									map[i]=-1;
																									mvp[--mvnum]=-1;
																								}//####################################################################################
																								else
																								{
																									mvp[9]=1;
																									upload();
																									mvp[9]=-1;
																									map[i]=-1;
																									mvp[--mvnum]=-1;
																								}
																							}
																						}//i
																						map[u]=-1;
																						mvp[--mvnum]=-1;
																					}//###########################################################################################
																					else
																					{
																						mvp[9]=0;
																						upload();
																						mvp[9]=-1;
																						map[u]=-1;
																						mvp[--mvnum]=-1;
																					}
																				}
																			}//u
																			map[y]=-1;
																			mvp[--mvnum]=-1;
																		}//##################################################################################################
																		else
																		{
																			mvp[9]=1;
																			upload();
																			mvp[9]=-1;
																			map[y]=-1;
																			mvp[--mvnum]=-1;
																		}
																	}
																}//y
																map[t]=-1;
																mvp[--mvnum]=-1;
															}//########################################################################################################
															else
															{
																mvp[9]=0;
																upload();
																mvp[9]=-1;
																map[t]=-1;
																mvp[--mvnum]=-1;
															}
														}
													}//t
													map[r]=-1;
													mvp[--mvnum]=-1;
												}//##############################################################################################################
												else
												{
													mvp[9]=1;
													upload();
													mvp[9]=-1;
													map[r]=-1;
													mvp[--mvnum]=-1;
												}
											}
										}//r
										map[e]=-1;
										mvp[--mvnum]=-1;
									}//####################################################################################################################
									else
									{
										mvp[9]=0;
										upload();
										mvp[9]=-1;
										map[e]=-1;
										mvp[--mvnum]=-1;
									}
								}
							}//e
							map[w]=-1;
							mvp[--mvnum]=-1;
						}//##########################################################################################################################
						else
						{
							mvp[9]=1;
							upload();
							mvp[9]=-1;
							map[w]=-1;
							mvp[--mvnum]=-1;
						}
					}
				}//w
				map[q]=-1;
				mvp[--mvnum]=-1;
			}//###############################################################################################################################
			else
			{
				mvp[9]=0;
				upload();
				mvp[9]=-1;
				map[q]=-1;
				mvp[--mvnum]=-1;
			}
		}
	}//q
getch();
}




/*
void temp()
{
	do{
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

		if(chkfile()==0)
		{
			ofstream fout("gameset.txt",ios::app);
			for(i=0;i<10;i++)
				fout<<mvp[i]<<" ";
			fout<<"\n";
			fout.close();

			totalnum=totalnum+1;
			num.seekp(0,ios::beg);
			num<<totalnum;

			cout<<"Total GameSets : "<<totalnum<<"\n";

		}
	}while(totalnum!=255168);
	getch();
	num.close();
}
*/
