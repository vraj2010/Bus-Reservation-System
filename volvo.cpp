#include <iostream>
#include <cstring>
using namespace std;
static int p = 0;
class volvo //class name
{
  private : //by default -- private (DATA-MEMBERS)
  char busn[10];
  char driver[10];
  char arrival[10];
  char depart[10];
  char from[10];
  char to[10];
  char seat[9][5][20];
public: // MEMBER FUNCTIONS
  void install();
  void ticket();
  void empty();
  void show();
  void position (int l);
}bus[20];

void volvo::install() // Scope Resolution Operator
{
  cout<<endl;
  cout<<"Enter bus no: ";
  cin>>bus[p].busn;
  cout<<"Enter Driver's name: ";
  cin>>bus[p].driver;
  cout<<"Arrival time: ";
  cin>>bus[p].arrival;
  cout<<"Departure: ";
  cin>>bus[p].depart;
  cout<<"From: ";
  cin>>bus[p].from;
  cout<<"To: ";
  cin>>bus[p].to;
  bus[p].empty();
  p++;
  
  cout<<endl<<endl<<"Bus added Sucessfully "<< endl << endl;
}
void volvo::ticket() // Scope Resolution Operator
{
  int seat;
  char number[10];
  top:
  cout<<"Bus no: ";
  cin>>number;
  int n;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn , number)==0)
    break;
  }
  while(n<=p)
  {
    cout<<"Seat Number: ";
    cin>>seat;
    if(seat>45)
    {
      cout<<"There are only 45 seats available in this bus.";
    }
    else
    {
    if (strcmp(bus[n].seat[seat/5][(seat%5)-1] , "Empty")==0)
      {
        cout<<"Enter passanger's name: ";
        cin>>bus[n].seat[seat/5][(seat%5)-1];
        
        cout<<endl<<endl<<"Seat Reserved Sucessfully "<<endl <<endl;
        break;
      }
    else
      cout<<"This seat is already reserved."<< endl;
      }
      }
    if(n>p)
    {
      cout<<"Enter Correct Bus no."<<endl;
      goto top;
    }
  }
void volvo::show()
{
  int n;
  char number[5];
  cout<<"\t\t\tEnter bus no: ";
  cin>>number;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
while(n<=p)
{
  cout<<"Bus no: "<<bus[n].busn <<endl ; 
  cout<<"Driver: "<<bus[n].driver <<endl ;
  cout<<"Arrival time: "<<bus[n].arrival <<endl ;
  cout<<"Departure time: "<<bus[n].depart <<endl ;
  cout<<"From: "<<bus[n].from <<endl ;
  cout<<"To: "<<bus[n].to <<endl ;
  bus[0].position(n);
  int a=1;
  for (int i=0; i<8; i++)
  {
    for(int j=0;j<4;j++)
    {
      a++;
      if(strcmp(bus[n].seat[i][j],"Empty")!=0)
      cout<<"The seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
    }
  }
  break;
  }
  if(n>p)
    cout<<"Enter correct bus no: ";
}
void volvo::empty() // Scope Resolution Operator
{
  for(int i=0; i<9;i++)
  {
    for(int j=0;j<5;j++)
    {
      strcpy(bus[p].seat[i][j] , "Empty");
    }
  }
}
void volvo::position(int l)
{
  int s=0;p=0;
  for (int i =0; i<9;i++)
  {
    cout<<endl ;
    for (int j = 0;j<5; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "Empty")==0)
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<bus[l].seat[i][j];
          p++;
        }
        else
        {
        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<bus[l].seat[i][j];
        }
      }
    }
  cout<<"\n\n\t\t\tThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn<<endl;
  }
int main()
{
int ch;
  cout<<"Bus Reservation System Project in C++"<<endl <<endl ;
while (1)
{
  cout<<endl;
  
  // Screen Display 
  cout<<"1.Add Bus"<<endl;
  cout<<"2.Bus Reservation"<<endl;
  cout<<"3.Show"<<endl;
  cout<<"4.Exit"<<endl;
  cout<<endl<<"Enter your choice:-> ";
  cin>>ch;
  switch(ch) // Switch Case - Statement
  {
    case 1:  bus[p].install();
      break;
    case 2:  bus[p].ticket();
      break;
    case 3:  bus[p].show();
      break; 
    case 4:  cout<<"THANK YOU !!! WELCOME BACK AGAIN !!!" <<endl <<endl;
             exit(0); // Exiting the Program 
  }
 }
return 0;
}
