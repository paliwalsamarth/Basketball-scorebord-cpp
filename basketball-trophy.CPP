#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h> //for delay function

int display(int,int);//prototype
void match();//prototype

 class team       //A class whose objects are the different teams
{
 static int count;
 char name[20];
 int score,foul,win;

 void supdate(int points)//for updating scores
 {
  score=score+points;
 }

 public:

 team()//constructor
 {
  score=0;
  foul=0;
  win=0;
 }

 void getname();//for getting name

 void putname();//for putting name

 void fupdate();//for updating foul

 void free_throw();//updating score for free throw

 void two_point();//updating score for normal basket

 void three_point();//updating score for three pointer

 int rscore();//return score

 int rfoul();//return foul

 void rematch();//if scores are same then rematch

 void newmatch();//to reset winning teams score

 int counting();//returning static member count

 void resetf();//for reseting foul to 0 after every quater

}obj[10];

int team::count=0;

void team::getname()
{
 count++;
 gets(name);
}

void team::putname()
{
 cout<<name;
}

void team::fupdate()
{
 foul+=1;
}

void team::free_throw()
{
 supdate(1);
}

void team::two_point()
{
 supdate(2);
}

void team::three_point()
{
 supdate(3);
}

int team::rscore()
{
 return score;
}

int team::rfoul()
{
 return foul;
}

void team::rematch()
{
 score=0;
 foul=0;
}

void team::newmatch()
{
 win++;
 score=0;
 foul=0;
}

int team::counting()
{
 return count;
}

void team::resetf()
{
 foul=0;
}

int main()     //Main function
{
 clrscr();
 int u;

 beganing:     //A label for goto command

 cout<<"\n\t\t\tSt. Arnold Basketball Trophy ";

 start:        //Another label for goto command

 cout<<"\n\n\n\tTasks: \n\t 1)Enter name of teams(default 10 teams) \n\t 2)Match Map \n\t 3)Start Match \n\t 4)Exit\n\n\t\t";
 cin>>u;
 switch(u)
 {
  case 1://for entering names of teams

  for(int p=0;p<=9;p++)
  {
   cout<<"\nEnter name of team "<<p+1<<"\n";
   obj[p].getname();
  }

  clrscr();
  goto beganing;

  case 2://for showing how match is going to take place 
  if((obj[0].counting()==1)||(obj[0].counting()!=10))
  {
   cout<<"\n First enter the names.......\n";
   cout<<"\n Enter any key to continue\n";
   getch();
   clrscr();
   goto beganing;
  }
  else
  {
   clrscr();
   cout<<"\n\n\t\tMATCH MAP";
   cout<<"\nRound 1 Match 1:\n Team ";obj[3].putname();cout<<" VS Team ";obj[4].putname();cout<<"                \t--> Winning team 1 ";
   cout<<"\nRound 1 Match 2:\n Team ";obj[5].putname();cout<<" VS Team ";obj[6].putname();cout<<"                \t--> Winning team 2 ";
   cout<<"\nRound 2 Match 1:\n Team ";obj[0].putname();cout<<" VS Team ";obj[1].putname();cout<<"                \t--> Winning team 3 ";
   cout<<"\nRound 2 Match 2:\n Team ";obj[2].putname();cout<<" VS Winning Team 1         \t--> Winning team 4 ";
   cout<<"\nRound 2 Match 3:\n Winning Team 2 VS Team ";obj[7].putname();cout<<"         \t--> Winning team 5 ";
   cout<<"\nRound 2 Match 4:\n Team ";obj[8].putname();cout<<" VS Team ";obj[9].putname();cout<<"                \t--> Winning team 6 ";
   cout<<"\nRound 3 Match 1:\n Winning Team 3 VS Winning Team 4 \t--> Winning team 7 ";
   cout<<"\nRound 3 Match 2:\n Winning Team 5 VS Winning Team 6 \t--> Winning team 8 ";
   cout<<"\nRound 4 Match 1:\n Winning Team 7 VS Winning Team 8 \t--> Winner of the match ";
   cout<<"\npress any key to continue\n";
   getch();
   clrscr();
   goto beganing;
  }
  case 3://for begainging the game
  if((obj[0].counting()==1)||(obj[0].counting()!=10))
  {
   cout<<"\n First enter the names.......\n";
   cout<<"\n Enter any key to continue\n";
   getch();
   clrscr();
   goto beganing;
  }
  else
  {
   match();
   clrscr();
   goto beganing;
  }
  case 4 :exit(0);//for exiting the program
  default:cout<<"wrong choice ";
	 break;
 }
  getch();
  return 0;
}

int w=0;
const int m=9;

void match()//defination for how match is going to take place
{
 int r,r1m1,r1m2,r2m1,r2m2,r2m3,r2m4,r3m1,r3m2,r4m1;
 char ch[m][30];
 clrscr();
 cout<<"\nround 1";
 cout<<"\nMatch 1\n"<<"Team A: ";obj[3].putname();   cout<<" vs "<<"Team B: ";obj[4].putname();cout<<"\n\n";
 r1m1=display(3,4);

 clrscr();
 cout<<"\nround 1";
 cout<<"\nMatch 2\n"<<"Team A: ";obj[5].putname();   cout<<" vs "<<"Team B: ";obj[6].putname();cout<<"\n\n";
 r1m2=display(5,6);

 clrscr();
 cout<<"\nround 2";
 cout<<"\nMatch 1\n"<<"Team A: ";obj[0].putname();   cout<<" vs "<<"Team B: ";obj[1].putname();cout<<"\n\n";
 r2m1=display(0,1);

 clrscr();
 cout<<"\nround 2";
 cout<<"\nMatch 2\n"<<"Team A: ";obj[2].putname();   cout<<" vs "<<"Team B: ";obj[r1m1].putname();cout<<"\n\n";
 r2m2=display(2,r1m1);

 clrscr();
 cout<<"\nround 2";
 cout<<"\nMatch 3\n"<<"Team A: ";obj[r1m2].putname();   cout<<" vs "<<"Team B: ";obj[7].putname();cout<<"\n\n";
 r2m3=display(r1m2,7);

 clrscr();
 cout<<"\nround 2";
 cout<<"\nMatch 4\n"<<"Team A: ";obj[8].putname();   cout<<" vs "<<"Team B: ";obj[9].putname();cout<<"\n\n";
 r2m4=display(8,9);

 clrscr();
 cout<<"\nround 3";
 cout<<"\nMatch 1\n"<<"Team A: ";obj[r2m1].putname();   cout<<" vs "<<"Team B: ";obj[r2m2].putname();cout<<"\n\n";
 r3m1=display(r2m1,r2m2);

 clrscr();
 cout<<"\nround 3";
 cout<<"\nMatch 2\n"<<"Team A: ";obj[r2m3].putname();   cout<<" vs "<<"Team B: ";obj[r2m4].putname();cout<<"\n\n";
 r3m2=display(r2m3,r2m4);

 clrscr();
 cout<<"\nround 4";
 cout<<"\nMatch 1\n"<<"Team A: ";obj[r3m1].putname();   cout<<" vs "<<"Team B: ";obj[r3m2].putname();cout<<"\n\n";
 r4m1=display(r3m1,r3m2);

 cout<<"\nWinner of match series: ";
 obj[r4m1].putname();
 cout<<"\nPress any key to continue\n";
 getch();
}

 int display(int i,int j)//defination for displaying scoreboard
{
 int a=i,b=j,c,d,e,p=1;
 char ch1;
 status:
 cout<<"\t--------------------------------------------------\n\t";
 cout<<"|       TEAM 1                         TEAM 2    |\n\t   ";
 obj[a].putname();
 cout<<"\t\t\t\t  ";
 obj[b].putname();
 cout<<"\n\t|                                                |\n\t";
 cout<<"|       SCORE                          SCORE     |\n\t";
 cout<<"|         "<<obj[a].rscore()<<"                              "<<obj[b].rscore()<<"       |\n\t";
 cout<<"|                                                |\n\t";
 cout<<"|                    QUATERS		         |\n\t";
 cout<<"|                       "<<p<<"                        |\n\t";
 cout<<"|                               	         |\n\t";
 cout<<"|       FOULS                          FOULS     |\n\t";
 cout<<"|         "<<obj[a].rfoul()<<"                              "<<obj[b].rfoul()<<"       |\n\t";
 cout<<"--------------------------------------------------\n\t";

 cout<<"choose whose status is changed\n 1) team 1\n 2) team 2\n 3) Quater over\n 4) Time over\n 5) exit\n";
 cin>>c;

 if(c<1||c>5)//if any other value is entered
 {
  cout<<"\nwrong chioce(wait)\n";
  delay(3000);
  clrscr();
  goto status;
 }
 else if(c==4)//for ending of current match
 {
  X:
  cout<<"\nNow the results are\n";
  if(obj[a].rscore()>obj[b].rscore())
  {
   cout<<"\n Winner is : ";obj[a].putname();
   obj[a].newmatch();
   cout<<"\npress any key to continue\n";
   getch();
   w=a;
   return w;
  }
  else if(obj[b].rscore()>obj[a].rscore())
  {
   cout<<"\n Winner is : ";obj[b].putname();
   obj[b].newmatch();
   cout<<"\npress any key to continue\n";
   getch();
   w=b;
   return w;
  }
  else
  {
   cout<<"\nIts a tie. Time for a rematch .......(now wait 5 sec) \n";
   obj[a].rematch();
   obj[b].rematch();
   p=1;
   delay(5000);
   clrscr();
   goto status;
  }
 }
 else if(c==5)//for exiting the program
 exit(0);

 else if(c==1)//if team 1 status is changed
 {
  cout<<"1) A basket \n2) A three pointer \n3) A foul \n4)a free throw basket\n";
  cin>>d;
  switch(d)
  {
   case 1:obj[a].two_point();
	  clrscr();
	  goto status;
   case 2:obj[a].three_point();
	  clrscr();
	  goto status;
   case 3:obj[a].fupdate();
	  clrscr();
	  goto status;
   case 4:obj[a].free_throw();
	  clrscr();
	  goto status;
   default:cout<<"wrong choice";
	   clrscr();
	   goto status;
  }
 }
 else if(c==2)//if team 2 status is changed
 {
  cout<<"1) A basket \n2) A three pointer \n3) A foul \n4)a free throw basket\n";
  cin>>e;
  switch(e)
  {
   case 1:obj[b].two_point();
	  clrscr();
	  goto status;
   case 2:obj[b].three_point();
	  clrscr();
	  goto status;
   case 3:obj[b].fupdate();
	  cout<<"Enter any key to continue";
	  getch();
	  clrscr();
	  goto status;
   case 4:obj[b].free_throw();
	  clrscr();
	  goto status;
   default:cout<<"wrong choice";
	   clrscr();
	   goto status;
  }
 }
 else if(c==3)//if the current quater is over
 {
  p++;

  if(obj[a].rfoul()==5) //free throw command for b
  {
   cout<<"\n1 free throw is awarded to team ";obj[b].putname();
  }
  else if(obj[a].rfoul()==6)
  {
   cout<<"\n2 free throw is awarded to team ";obj[b].putname();
  }
  else if(obj[a].rfoul()==7)
  {
   cout<<"\n3 free throw is awarded to team ";obj[b].putname();
  }
  else if(obj[a].rfoul()==8)
  {
   cout<<"\n4 free throw is awarded to team ";obj[b].putname();
  }
  else if(obj[a].rfoul()==9)
  {
   cout<<"\n5 free throw is awarded to team ";obj[b].putname();
  }
  else if(obj[a].rfoul()==10)
  {
   cout<<"\n1 free throw is awarded to team ";obj[b].putname();
  }

  if(obj[b].rfoul()==5) //free throw command for a
  {
   cout<<"\n1 free throw is awarded to team ";obj[a].putname();
  }
  else if(obj[b].rfoul()==6)
  {
   cout<<"\n2 free throw is awarded to team ";obj[a].putname();
  }
  else if(obj[b].rfoul()==7)
  {
   cout<<"\n3 free throw is awarded to team ";obj[a].putname();
  }
  else if(obj[b].rfoul()==8)
  {
   cout<<"\n4 free throw is awarded to team ";obj[a].putname();
  }
  else if(obj[b].rfoul()==9)
  {
   cout<<"\n5 free throw is awarded to team ";obj[a].putname();
  }
  else if(obj[b].rfoul()==10)
  {
   cout<<"\n1 free throw is awarded to team ";obj[a].putname();
  }
  obj[a].resetf();
  obj[b].resetf();

  if(p==5)
  {
   cout<<"\n All  Quaters are over. Heading over to Results \n";
   goto X;
  }
  cout<<"\npress any key to continue\n";
  getch();
  clrscr();
  goto status;
 }
 return 0;
}









