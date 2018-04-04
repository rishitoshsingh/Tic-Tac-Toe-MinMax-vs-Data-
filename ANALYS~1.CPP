#include<fstream.h>
#include<iostream.h>
#include<conio.h>
void main()
{
  int mv[10];
  int i,cnt=0,tot=0,ws=0;
  clrscr();
  ifstream a("0.txt");
  while(!a.eof())
  {
    for(i=0;i<10;i++)
      a>>mv[i];
    for(i=0;i<9;i++)
      {
        if(mv[i]==-1)
          cnt++;
      }
      if(cnt==4)
      {
        tot++;
        if(mv[9]==0)
          ws++;
      }
      cnt=0;
  }
  cout<<"Waste sets 0 : "<<tot<<"\n";
  cout<<"Win 0 : "<<ws<<"\n";
  ws=0;
  tot=0;
  a.close();

  ifstream b("1.txt");
  while(!b.eof())
  {
    for(i=0;i<10;i++)
      b>>mv[i];
    for(i=0;i<9;i++)
      {
        if(mv[i]==-1)
          cnt++;
      }
      if(cnt==4)
      {
        tot++;
        if(mv[9]==0)
          ws++;
      }
      cnt=0;
  }
  cout<<"Waste sets 1 : "<<tot<<"\n";
  cout<<"Win 0 : "<<ws<<"\n";
  ws=0;
  tot=0;
  b.close();

  ifstream c("2.txt");
  while(!c.eof())
  {
    for(i=0;i<10;i++)
      c>>mv[i];
    for(i=0;i<9;i++)
      {
        if(mv[i]==-1)
          cnt++;
      }
      if(cnt==4)
      {
        tot++;
        if(mv[9]==0)
          ws++;
      }
      cnt=0;
  }
  cout<<"Waste sets 2 : "<<tot<<"\n";
  cout<<"Win 0 : "<<ws<<"\n";
  ws=0;
  tot=0;
  c.close();

  ifstream d("3.txt");
  while(!d.eof())
  {
    for(i=0;i<10;i++)
      d>>mv[i];
    for(i=0;i<9;i++)
      {
        if(mv[i]==-1)
          cnt++;
      }
      if(cnt==4)
      {
        tot++;
        if(mv[9]==0)
          ws++;
      }
      cnt=0;
  }
  cout<<"Waste sets 3 : "<<tot<<"\n";
  cout<<"Win 0 : "<<ws<<"\n";
  ws=0;
  tot=0;
  d.close();

  ifstream e("4.txt");
  while(!e.eof())
  {
    for(i=0;i<10;i++)
      e>>mv[i];
    for(i=0;i<9;i++)
      {
        if(mv[i]==-1)
          cnt++;
      }
      if(cnt==4)
      {
        tot++;
        if(mv[9]==0)
          ws++;
      }
      cnt=0;
  }
  cout<<"Waste sets 4 : "<<tot<<"\n";
  cout<<"Win 0 : "<<ws<<"\n";
  ws=0;
  tot=0;
  e.close();

  ifstream f("5.txt");
  while(!f.eof())
  {
    for(i=0;i<10;i++)
      f>>mv[i];
    for(i=0;i<9;i++)
      {
        if(mv[i]==-1)
          cnt++;
      }
      if(cnt==4)
      {
        tot++;
        if(mv[9]==0)
          ws++;
      }
      cnt=0;
  }
  cout<<"Waste sets 5 : "<<tot<<"\n";
  cout<<"Win 0 : "<<ws<<"\n";
  ws=0;
  tot=0;
  f.close();

  ifstream g("6.txt");
  while(!g.eof())
  {
    for(i=0;i<10;i++)
      g>>mv[i];
    for(i=0;i<9;i++)
      {
        if(mv[i]==-1)
          cnt++;
      }
      if(cnt==4)
      {
        tot++;
        if(mv[9]==0)
          ws++;
      }
      cnt=0;
  }
  cout<<"Waste sets 6 : "<<tot<<"\n";
  cout<<"Win 0 : "<<ws<<"\n";
  ws=0;
  tot=0;
  g.close();

  ifstream h("7.txt");
  while(!h.eof())
  {
    for(i=0;i<10;i++)
      h>>mv[i];
    for(i=0;i<9;i++)
      {
        if(mv[i]==-1)
          cnt++;
      }
      if(cnt==4)
      {
        tot++;
        if(mv[9]==0)
          ws++;
      }
      cnt=0;
  }
  cout<<"Waste sets 7 : "<<tot<<"\n";
  cout<<"Win 0 : "<<ws<<"\n";
  ws=0;
  tot=0;
  h.close();

  ifstream q("8.txt");
  while(!q.eof())
  {
    for(i=0;i<10;i++)
      q>>mv[i];
    for(i=0;i<9;i++)
      {
        if(mv[i]==-1)
          cnt++;
      }
      if(cnt==4)
      {
        tot++;
        if(mv[9]==0)
          ws++;
      }
      cnt=0;
  }
  cout<<"Waste sets 8 : "<<tot<<"\n";
  cout<<"Win 0 : "<<ws<<"\n";
  ws=0;
  tot=0;
  q.close();
getch();

}//end of main()
