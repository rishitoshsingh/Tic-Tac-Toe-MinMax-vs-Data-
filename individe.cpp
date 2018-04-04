#include<fstream.h>
void main()
{
  int mv[10];
  int i;
 
  ifstream q("0.txt");
  ofstream q0("win00.txt");
  ofstream q1("win01.txt");
  ofstream qd("draw0d.txt");
  while(!q.eof())
  {
    for(i=0;i<10;i++)
      q>>mv[i];
    if(mv[9]==0)
    {
      for(i=0;i<10;i++)
        q0<<mv[i]<<" ";
      q0<<"\n";
    }
    else if(mv[9]==1)
    {
      for(i=0;i<10;i++)
        q1<<mv[i]<<" ";
      q1<<"\n";
    }
    else
    {
      for(i=0;i<10;i++)
        qd<<mv[i]<<" ";
      qd<<"\n";
    }
  }
  q.close();
  q0.close();
  q1.close();
  qd.close();


  ifstream w("1.txt");
  ofstream w0("win10.txt");
  ofstream w1("win11.txt");
  ofstream wd("draw1d.txt");
  while(!w.eof())
  {
    for(i=0;i<10;i++)
      w>>mv[i];
    if(mv[9]==0)
    {
      for(i=0;i<10;i++)
        w0<<mv[i]<<" ";
      w0<<"\n";
    }
    else if(mv[9]==1)
    {
      for(i=0;i<10;i++)
        w1<<mv[i]<<" ";
      w1<<"\n";
    }
    else
    {
      for(i=0;i<10;i++)
        wd<<mv[i]<<" ";
      wd<<"\n";
    }
  }
  w.close();
  w0.close();
  w1.close();
  wd.close();

  ifstream e("2.txt");
  ofstream e0("win20.txt");
  ofstream e1("win21.txt");
  ofstream ed("draw2d.txt");

  while(!e.eof())
  {
    for(i=0;i<10;i++)
      e>>mv[i];
    if(mv[9]==0)
    {
      for(i=0;i<10;i++)
        e0<<mv[i]<<" ";
      e0<<"\n";
    }
    else if(mv[9]==1)
    {
      for(i=0;i<10;i++)
        e1<<mv[i]<<" ";
      e1<<"\n";
    }
    else
    {
      for(i=0;i<10;i++)
        ed<<mv[i]<<" ";
      ed<<"\n";
    }
  }
  e.close();
  e0.close();
  e1.close();
  ed.close();

  ifstream a("3.txt");
  ofstream a0("win30.txt");
  ofstream a1("win31.txt");
  ofstream ad("draw3d.txt");

  while(!a.eof())
  {
    for(i=0;i<10;i++)
      a>>mv[i];
    if(mv[9]==0)
    {
      for(i=0;i<10;i++)
        a0<<mv[i]<<" ";
      a0<<"\n";
    }
    else if(mv[9]==1)
    {
      for(i=0;i<10;i++)
        a1<<mv[i]<<" ";
      a1<<"\n";
    }
    else
    {
      for(i=0;i<10;i++)
        ad<<mv[i]<<" ";
      ad<<"\n";
    }
  }
  a.close();
  a0.close();
  a1.close();
  ad.close();

  ifstream s("4.txt");
  ofstream s0("win40.txt");
  ofstream s1("win41.txt");
  ofstream sd("draw4d.txt");

  while(!s.eof())
  {
    for(i=0;i<10;i++)
      s>>mv[i];
    if(mv[9]==0)
    {
      for(i=0;i<10;i++)
        s0<<mv[i]<<" ";
      s0<<"\n";
    }
    else if(mv[9]==1)
    {
      for(i=0;i<10;i++)
        s1<<mv[i]<<" ";
      s1<<"\n";
    }
    else
    {
      for(i=0;i<10;i++)
        sd<<mv[i]<<" ";
      sd<<"\n";
    }
  }
  s.close();
  s0.close();
  s1.close();
  sd.close();

  ifstream d("5.txt");
  ofstream d0("win50.txt");
  ofstream d1("win51.txt");
  ofstream dd("draw5d.txt");

  while(!d.eof())
  {
    for(i=0;i<10;i++)
      d>>mv[i];
    if(mv[9]==0)
    {
      for(i=0;i<10;i++)
        d0<<mv[i]<<" ";
      d0<<"\n";
    }
    else if(mv[9]==1)
    {
      for(i=0;i<10;i++)
        d1<<mv[i]<<" ";
      d1<<"\n";
    }
    else
    {
      for(i=0;i<10;i++)
        dd<<mv[i]<<" ";
      dd<<"\n";
    }
  }
  d.close();
  d0.close();
  d1.close();
  dd.close();

  ifstream z("6.txt");
  ofstream z0("win60.txt");
  ofstream z1("win61.txt");
  ofstream zd("draw6d.txt");

  while(!z.eof())
  {
    for(i=0;i<10;i++)
      z>>mv[i];
    if(mv[9]==0)
    {
      for(i=0;i<10;i++)
        z0<<mv[i]<<" ";
      z0<<"\n";
    }
    else if(mv[9]==1)
    {
      for(i=0;i<10;i++)
        z1<<mv[i]<<" ";
      z1<<"\n";
    }
    else
    {
      for(i=0;i<10;i++)
        zd<<mv[i]<<" ";
      zd<<"\n";
    }
  }
  z.close();
  z0.close();
  z1.close();
  zd.close();

  ifstream x("7.txt");
  ofstream x0("win70.txt");
  ofstream x1("win71.txt");
  ofstream xd("draw7d.txt");

  while(!x.eof())
  {
    for(i=0;i<10;i++)
      x>>mv[i];
    if(mv[9]==0)
    {
      for(i=0;i<10;i++)
        x0<<mv[i]<<" ";
      x0<<"\n";
    }
    else if(mv[9]==1)
    {
      for(i=0;i<10;i++)
        x1<<mv[i]<<" ";
      x1<<"\n";
    }
    else
    {
      for(i=0;i<10;i++)
        xd<<mv[i]<<" ";
      xd<<"\n";
    }
  }
  x.close();
  x0.close();
  x1.close();
  xd.close();

  ifstream c("8.txt");
  ofstream c0("win80.txt");
  ofstream c1("win81.txt");
  ofstream cd("draw8d.txt");

  while(!c.eof())
  {
    for(i=0;i<10;i++)
      c>>mv[i];
    if(mv[9]==0)
    {
      for(i=0;i<10;i++)
        c0<<mv[i]<<" ";
      c0<<"\n";
    }
    else if(mv[9]==1)
    {
      for(i=0;i<10;i++)
        c1<<mv[i]<<" ";
      c1<<"\n";
    }
    else
    {
      for(i=0;i<10;i++)
        cd<<mv[i]<<" ";
      cd<<"\n";
    }
  }
  c.close();
  c0.close();
  c1.close();
  cd.close();


}
