//B. Vasudha 15CO211
//R. RuhiTaj 15CO239
//Gaming with OOP

#include <iostream>
#include<string.h>
#include <cstdlib>
# include <windows.h>
# include <mmsystem.h>
# include <graphics.h>
# include <conio.h>


int score=0;
using namespace std;
int track=0;

class game
{

public:
  //int score;
  string s;
  int p=0;
  game();
  ~game();

  friend ostream &operator<<(ostream &output, const game &g)
{
         output<<"\n\t\t\t"<<" "<<"'s SCORE : "<<score<<endl;

         return output;
}



inline void operator++()
{
score=score+1;
}

inline void operator--()
{
score=score-1;
}


virtual void display()
{
         cout<<s<<endl;
}


};


class RockPaper : public game
{
public:
char option;
RockPaper();

void display()
{
                 cout<<s<<endl;

}



};

class Music : public game
{
public:
char option;
Music();


void display()
{
cout<<s<<endl;

}
};

class mineSweeper : public game
{
public:
mineSweeper();
mineSweeper(int);



void display()
{
                 cout<<s<<endl;

}



};


mineSweeper::mineSweeper()

{
int nl=5;
int i;
int j;
int k=0;
cout<<"\n\n"<<endl;
for(i=0;i<nl;i++)
{
cout<<"\t\t";
for(j=0;j<nl;j++)
{
k=k+1;

if(k/10==0)
{
cout<<"[0"<<k<<"]\t";
}
else
{cout<<"["<<k<<"]\t";}


}
cout<<"\n\n";
}
int arr[40];
cout<<"Enter "<<((nl*nl)/3)<<" places, where you think , there are no bombs\n"<<endl;

for(i=0;i<(nl*nl)/3;i++)
{
 cin>>arr[i];
}
int flag;
int p;

int r;
k=0;
cout<<"\n\n"<<endl;
for(i=0;i<nl;i++)
{
cout<<"\t\t";
for(j=0;j<nl;j++)
{
 r = (rand() % 5) + 1;
k=k+1;
flag=0;

for(p=0;p<((nl*nl)/3);p++)
{
if(arr[p]==k && (r<=2))
{
flag=-1;
}
else if(arr[p]==k && (r>2))
{
flag=-3;
}

}


if(flag==-1)
{
   score=score-k;
   //cout<<"**decremented"<<score<<"\t"<<k<<endl;
}
else if(flag==-3)
{
 score=score+k;
   //cout<<"**incremented"<<score<<"\t"<<k<<endl;

}
if(k/10==0 && r>=3 )
{
cout<<"[0"<<k<<"]\t";
}
else if(r>=3)
{cout<<"["<<k<<"]\t";}
else if(r<3)
{
cout<<""<<"<!>"<<"\t";
}
}
cout<<"\n\n";
}



cout<<"\n\t\t\t"<<s<<"'s SCORE : "<<score<<endl;

}





mineSweeper::mineSweeper(int nl)
{
int i;
int j;
int k=0;
cout<<"\n\n"<<endl;
for(i=0;i<nl;i++)
{
cout<<"\t\t";
for(j=0;j<nl;j++)
{k=k+1;

if(k/10==0)
{
cout<<"[0"<<k<<"]\t";
}
else
{cout<<"["<<k<<"]\t";}


}
cout<<"\n\n";
}
//int arr[40];
int* arr  = NULL;   // Pointer initialized with null
arr  = new int[(nl*nl)/3];////////////////////////DYNAMIC MEMORY ALLOCATION

cout<<"Enter "<<((nl*nl)/3)<<" places, where you think , there are no bombs\n"<<endl;
for(i=0;i<(nl*nl)/3;i++)
{
 cin>>arr[i];
}
int flag;
int p;

cout<<"\t\tBOMB-  "<<"<!>"<<"\n"<<endl;

int r;
k=0;
cout<<"\n\n"<<endl;
for(i=0;i<nl;i++)
{
cout<<"\t\t";
for(j=0;j<nl;j++)
{
 r = (rand() % 5) + 1;
k=k+1;
flag=0;

for(p=0;p<((nl*nl)/3);p++)
{
if(arr[p]==k && (r<=2))
{
flag=-1;

}
else if(arr[p]==k && (r>2))
{
flag=-3;
}

}


if(flag==-1)
{
   score=score-k;
   //cout<<"**decremented"<<score<<"\t"<<k<<endl;
}
else if(flag==-3)
{
 score=score+k;
   //cout<<"**incremented"<<score<<"\t"<<k<<endl;
}
if(k/10==0 && r>=3 )
{
cout<<"[0"<<k<<"]\t";
}
else if(r>=3)
{cout<<"["<<k<<"]\t";}
else if(r<3)
{
cout<<""<<"<!>"<<"\t";
PlaySound(TEXT("bom.wav"),NULL,SND_SYNC);
}
}
cout<<"\n\n";
}

cout<<"\n\t\t\t"<<s<<"'s SCORE : "<<score<<endl;

}




Music::Music()
{
 int j=1;
int i=1;
int y;

cout<<"\n\n\t\tGUESS MUSIC"<<endl;
while(j)
{
switch(i)
{
case 1  :cout<<"\nPlaying Music......."<<endl;
         PlaySound(TEXT("MaaTujheSalaam.wav"),NULL,SND_SYNC);
         break;
case 2  :cout<<"\nPlaying Music......."<<endl;
         PlaySound(TEXT("wav.wav"),NULL,SND_SYNC);
         break;
case 3  :cout<<"\nPlaying Music......."<<endl;
         PlaySound(TEXT("The_Pink_Panther_Theme_Song_Original_Version_.wav"),NULL,SND_SYNC);
         break;

//case 3  :
//         break;

}
cout<<"\nGuess the music-\n\n\n1.Music composed by A.R.Rehman\n2.Indian Sensation - Baahubali\n3.Pink Panther\n4.Music by Taylor Swift\n5.Music by Illiyaraja\n\n";
cin>>y;
if(y==i)
{
 PlaySound(TEXT("correct_sound.wav"),NULL,SND_SYNC);
cout<<"\nYou are correct!"<<endl;
++score;
cout<<"\n\t\t\t"<<s<<"'s SCORE : "<<score<<endl;

}
else
{
PlaySound(TEXT("Wrong_Buzzer_-_Sound_Effect.wav"),NULL,SND_SYNC);
cout<<"\nOOPs! you lost!"<<endl;

--score;
cout<<"\n\t\t\t"<<s<<"'s SCORE : "<<score<<endl;

}

i=i+1;
if(i==4)
{

j=0;
}
}

}

RockPaper::RockPaper()

{


int r;
int i;
//score=0;
//cout<<"\n\nE
for(i=0;i<5;i++)
{
cout<<"\n\nEnter\n\t\t'r'-rock\t'p'-paper\t's'-scissor"<<endl;
cin>>option;
 r = (rand() % 3) + 1;

 switch(r)
 {
 case 1:
         if(option=='p' || option=='P')
         { PlaySound(TEXT("correct_sound.wav"),NULL,SND_SYNC);
           cout<<"You win"<<endl;
           ++score;
         }
         else if(option =='s'|| option=='S')
         {            PlaySound(TEXT("Wrong_Buzzer_-_Sound_Effect.wav"),NULL,SND_SYNC);

           cout<<"You lose"<<endl;
           --score;
         }
         else if(option =='r'|| option=='R')
         {
           cout<<"Tie"<<endl;
           score=score+0;
         }
         else
         {
                     PlaySound(TEXT("Wrong_Buzzer_-_Sound_Effect.wav"),NULL,SND_SYNC);

         cout<<"Exception occurred"<<endl;

         }
         cout<<"The computer entered Rock\n";
         cout<<"\n\t\t\t"<<s<<"'s SCORE : "<<score<<endl;

         break;
 case 2:
         if(option=='s'|| option=='S')
         { PlaySound(TEXT("correct_sound.wav"),NULL,SND_SYNC);
           cout<<"You win"<<endl;
           ++score;
         }
         else if(option =='r'|| option=='R')
         {            PlaySound(TEXT("Wrong_Buzzer_-_Sound_Effect.wav"),NULL,SND_SYNC);

           cout<<"You lose"<<endl;

           --score;
         }
         else if(option =='p'|| option=='P')
         {
           cout<<"Tie"<<endl;
           score=score+0;
         }
         else
         {
                     PlaySound(TEXT("Wrong_Buzzer_-_Sound_Effect.wav"),NULL,SND_SYNC);

         cout<<"Exception occurred"<<endl;

         }
         cout<<"The computer entered Paper\n";
         cout<<"\n\t\t\t"<<s<<"'s SCORE : "<<score<<endl;

         break;


 case 3:
         if(option=='R'|| option=='r')
         { PlaySound(TEXT("correct_sound.wav"),NULL,SND_SYNC);

           cout<<"You win"<<endl;
           ++score;
         }
         else if(option =='p'|| option=='P')
         {                    PlaySound(TEXT("Wrong_Buzzer_-_Sound_Effect.wav"),NULL,SND_SYNC);

           cout<<"You lose"<<endl;

           --score;
         }
         else if(option =='s'|| option=='S')
         {
           cout<<"Tie"<<endl;
           score=score+0;
            //PlaySound(TEXT("Wrong_Buzzer_-_Sound_Effect.wav"),NULL,SND_SYNC);

         }
         else
         {
                     PlaySound(TEXT("Wrong_Buzzer_-_Sound_Effect.wav"),NULL,SND_SYNC);

         cout<<"Exception occurred"<<endl;

         }
         cout<<"The computer entered Scissor\n";
         cout<<"\n\t\t\t"<<s<<"'s SCORE : "<<score<<endl;


         break;

 }


}
//cout<<"\n\t\t\t"<<s<<"'s SCORE : "<<score<<endl;

}
game::game()
{

  {cout<<"\nEnter User-name to start the game\n";
  cin>>s;}
  //cout<<"\nUser name is \n"<<s<<endl;

}
game::~game()
{
  s="\0";
  score=0;
 // cout<<"\n\nThe data is deleted\n";
}
/*
PlaySound(TEXT("MaaTujheSalaam.wav"),NULL,SND_SYNC);
    PlaySound(TEXT("wav.wav"),NULL,SND_SYNC);
*/








template <class T> class knowledge
{
public:
inline T add(T x , T y)
{
         return x+y;
}

inline T multiply(T x , T y)
{
         return x*y;
}

T subtraction (int , int);

};

template < class T >
T subtraction(T x, T y)
{
         return x-y;
}

class minutes
{
         int m;

public:
         minutes()
         {
                m=240;
         }

        int  get()
         {
                  return (m);
         }

void display()
{
         cout<<"\n\n \t\tMinutes : "<<m;
}


};



class hours
{
         int h;

         public:

                  void operator = (minutes x)
                  {
                            h=x.get()/60;
                  }

                  void display()
                  {
                           cout<<"\n\n\t\tHours : "<<h;
                  }


};





class data
{
         int x;

public:

         data()
         {
                  x=0;

         }


         data(int y)
         {
                  x=y;

         }

         operator int()
         {
                  return x;
         }

         void display()
         {
                  cout<<"\n\n\t\t\tx : "<<x;


         }
};


int main()
{
 /*char driver[]="C:\\tc\\bgi";
    int gd = DETECT, gm;
    initgraph(&gd,&gm, "C:\\tc\\bgi");
    circle(300,300,50);
    closegraph();
    getch();*/
 int run=1;
 int s;
 string sl;
 cout<<"\n\n A EXPERIMENT COMPRISING ENTERTAINMENT AND KNOWLEDGE WITH THE CONCEPTS OF OOP\n\n\n\n"<<endl;

 cout<<"\t\t----ENTERTAINMENT SESSION----\n\n"<<endl;

while(run)
   {
cout<<"Select a Team name for the upcoming three levels, played by three players of the same team:\t"<<endl;
         PlaySound(TEXT("23119990.wav"),NULL,SND_SYNC);

game g;
cout<<"\n\nSelect user name for level-1\n";
         PlaySound(TEXT("23119067.wav"),NULL,SND_SYNC);

  Music m;
  cout<<"\n\nSelect user name for level-2\n\n";

   cout<<"\n\n\t\t\t'ROCK-PAPER-SCISSOR'"<<endl;
            PlaySound(TEXT("23119067.wav"),NULL,SND_SYNC);
   RockPaper scissor;
    int box;

    cout<<"\n\n\t\t\t'MINE SWEEPER'"<<endl;
    cout<<"\n\nDo you want to decide no of boxes in minesweeper. Enter 1 for yes!"<<endl;
    cin>>s;
    if(s==1)
    {
         cout<<"\n\nEnter no of boxes :\n\n\n\t\tMIN:3\tMAX:6\n"<<endl;
         cin>>box;
         if(box<3)
         {
          box=3;
         }
         else if(box>6)
         {
          box=6;
         }
         cout<<"\n\nSelect user name for level-3\n";
         PlaySound(TEXT("23119067.wav"),NULL,SND_SYNC);

         mineSweeper name(box);
         sl=name.s;
    }
    else
    {cout<<"\n\nSelect user name for level-3\n";
     PlaySound(TEXT("23119067.wav"),NULL,SND_SYNC);
     mineSweeper name;
         sl=name.s;

    }

cout<<"\n\nEnter 0 , if you want to stop GAMING with OOP\n\n"<<endl;
cin>>run;
if(run==0)
{
cout<<"\t\t\tTHANK YOU FOR GAMING team-";
g.display();
cout<<"\n\n";
cout<<"\t\t\tTHANK YOU FOR GAMING player1-";
m.display();
cout<<"\n\n";
cout<<"\t\t\tTHANK YOU FOR GAMING player2-";
scissor.display();
cout<<"\n\n";
cout<<"\t\t\tTHANK YOU FOR GAMING player3-";
cout<<sl;
cout<<"\n\n";
}
   }

cout<<"\n\n\n\t\t\t---KNOWLEDGE SESSION---\n\n\n"<<endl;



int p,q,r,points=0;
knowledge < int > A;
cout<<"\n\nenter two integer numbers for addition:\t";
cin>>p>>q;
cout<<"\ngive your answer for addition:\t";
cin>>r;
int d=A.add(p,q);
if(r==d)
{
         cout<<"\n\n\t\t\tCORRECT ANSWER!!\n\n";
         points=points+1;
          cout<<"\t\t\tSCORE : "<<points;
}
else
{
         cout<<"\n\n\t\t\tINCORRECT ANSWER!!!\n\n";
         points=points-1;
          cout<<"\t\t\tSCORE : "<<points;
}




float m,n,o;
knowledge < float > B;
cout<<"\n\nenter two floating point numbers for multiplication:\t";
cin>>m>>n;
cout<<"\ngive your answer for multiplication:\t";
cin>>o;
float l=B.multiply(m,n);
if(o==l)
{
         cout<<"\n\n\t\t\tCORRECT ANSWER!!\n\n";
         points=points+1;
         cout<<"\t\t\tSCORE : "<<points;
}
else
{
         cout<<"\n\n\t\t\tINCORRECT ANSWER!!!\n\n";
         points=points-1;
          cout<<"\t\t\tSCORE : "<<points;
}





int e,f,g;
knowledge < int  > C;
cout<<"\n\nenter two integer numbers for subtraction:\t";
cin>>e>>f;
cout<<"\ngive your answer for subtraction:\t";
cin>>g;
int h=subtraction(e,f);
if(g==h)
{
         cout<<"\n\n\t\t\tCORRECT ANSWER!!\n\n";
         points=points+1;
         cout<<"\t\t\tSCORE : "<<points;
}
else
{
         cout<<"\n\n\t\t\tINCORRECT ANSWER!!!\n\n";
         points=points-1;
          cout<<"\t\t\tSCORE : "<<points;
}



cout<<"\n\n\t\tTYPE CONVERSION";

minutes minute;
hours hour;
hour = minute;
minute.display();
hour.display();

int j;
data z(5);
j=z;
cout<<"\n\n\t\t\tThe value of j : "<<j;


 return 0;
}
