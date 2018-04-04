#include<fstream.h>
#include<conio.h>
#include<string.h>
void cal(char *qwe)
{
  int i;
  ifstream fin(qwe);
  fin>>i;
  clrscr();
  cout<<i;
  cout<<"\n";
  getch();
    fin.close();
}
void main()
{
  char ch[10];
  strcpy(ch,"qwe.txt");
  cal(ch);


}
