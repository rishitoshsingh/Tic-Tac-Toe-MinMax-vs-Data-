#include<fstream.h>
void main()
{
  int mv[10];
  ifstream fin("games.txt");
  ofstream q("0.txt");
  ofstream w("1.txt");
  ofstream e("2.txt");
  ofstream a("3.txt");
  ofstream s("4.txt");
  ofstream d("5.txt");
  ofstream z("6.txt");
  ofstream x("7.txt");
  ofstream c("8.txt");
  while(!fin.eof())
  {
    for(int i=0;i<10;i++)
    fin>>mv[i];
    if(mv[0]==0)
    {
      for(i=0;i<10;i++)
        q<<mv[i]<<" ";
      q<<"\n";
    }
    if(mv[0]==1)
    {
      for(i=0;i<10;i++)
        w<<mv[i]<<" ";
      w<<"\n";
    }
    if(mv[0]==2)
    {
      for(i=0;i<10;i++)
        e<<mv[i]<<" ";
      e<<"\n";
    }
    if(mv[0]==3)
    {
      for(i=0;i<10;i++)
        a<<mv[i]<<" ";
      a<<"\n";
    }
    if(mv[0]==4)
    {
      for(i=0;i<10;i++)
        s<<mv[i]<<" ";
      s<<"\n";
    }
    if(mv[0]==5)
    {
      for(i=0;i<10;i++)
        d<<mv[i]<<" ";
      d<<"\n";
    }
    if(mv[0]==6)
    {
      for(i=0;i<10;i++)
        z<<mv[i]<<" ";
      z<<"\n";
    }
    if(mv[0]==7)
    {
      for(i=0;i<10;i++)
        x<<mv[i]<<" ";
      x<<"\n";
    }
    if(mv[0]==8)
    {
      for(i=0;i<10;i++)
        c<<mv[i]<<" ";
      c<<"\n";
    }
  }
  fin.close();q.close();w.close();e.close();a.close();s.close();d.close();z.close();x.close();c.close();
}
