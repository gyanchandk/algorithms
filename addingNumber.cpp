#include<iostream>
#include <stdlib.h>
using namespace std;
#define NUMBER_OF_BITS 500
enum Number{
  FIRST=0,
  SECOND=1,
  RESULT=2
};
int const ROWS=3;
int number[ROWS][NUMBER_OF_BITS];


void init()
{
  number[FIRST][0]=number[SECOND][0]=number[RESULT][0]=0;
  for(int i=0;i<ROWS;i++)
  {
    for(int j=1;j<NUMBER_OF_BITS;j++)
    {
      //number[i][j]=rand()%10;
      number[i][j]=0;

    }
  }
  number[SECOND][NUMBER_OF_BITS-1]=1;
}

void add()
{
  int carry=0,sum=0;
  for(int i=NUMBER_OF_BITS-1;i>0;i--)
  {
    sum=carry+number[FIRST][i]+number[SECOND][i];
    number[RESULT][i]=sum%10;
    carry=sum/10;
  }
  number[RESULT][0]=carry;
}
void copy()
{
  for(int i=0;i<NUMBER_OF_BITS;i++)
  {
    number[FIRST][i]=number[SECOND][i];
    number[SECOND][i]=number[RESULT][i];
  }
}
void print()
{
  // cout<<" \t";
  // for(int i=0;i<NUMBER_OF_BITS;i++)
  // {
  //   cout<<number[FIRST][i];
  // }
  // cout<<"\n+\t";
  // for(int i=0;i<NUMBER_OF_BITS;i++)
  // {
  //   cout<<number[SECOND][i];
  // }
  // cout<<"\n\t";
  // for(int i=0;i<NUMBER_OF_BITS;i++)
  // {
  //   cout<<"-";
  // }
  //cout<<"\n\t";
//   {"0":
//          { "fibNumber": "0", "numberOfDigits": "1"},
//
// "1": { "fibNumber": "1", "numberOfDigits": "1"}}

  bool flag=false;
  int count=0;
  for(int i=0;i<NUMBER_OF_BITS;i++)
  {
    if(number[RESULT][i])flag=true;

    if(flag)
    {
      cout<<number[RESULT][i];
      count++;
    }
    //else{cout<<".";}

  }
  cout<<":"<<count<<":x\n";

}
int main()
{
  init();
  //cout<<"INDEX : FIBONACCI NUMBER : NUMBER OF DIGITS \n";
  //cout<<"--------------------------------------------\n";
  cout<<"0:0:1:x\n";
  for(int i=1;i<=500;i++)
  {
    cout<<i<<":";
    add();
    print();
    copy();
  }
  //cout<<endl;
  return 0;
}
