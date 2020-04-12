#include<iostream>
using namespace std;
#define SIZE 22
int arr[SIZE];
int set[SIZE];
int count[SIZE];
int list[SIZE];

int hashTable[SIZE];
int chainTable[SIZE];

void init()
{
  for(int i=0;i<SIZE;i++)
  {
    arr[i]=-1;
    hashTable[i]=chainTable[i]=-1;
    count[i]=0;
  }

  for(int i=2;i<SIZE/2;i++)
  {
    if(arr[i]!=-1)continue;
    int num=i;
    while(num<SIZE)
    {
      if(arr[num]==-1)
      {
        arr[num]=i;
      }
      num+=i;
    }
  }

  cout<<"\ninit done\n";

}
void assignSet()
{
  set[1]=1;
  for(int i=2;i<SIZE;i++)
  {
    if(arr[i]==i)
    {
      set[i]=1;
    }
    else
    {
      set[i]=set[i-arr[i]]+1;
    }
  }

  cout<<"\nassign set done\n";
}

void createSet()
{

  for(int i=1;i<SIZE;i++)
  {
    //cout<<set[i]<<" ";
    int h=set[i];
    chainTable[i]=hashTable[h];
    hashTable[h]=i;
    count[set[i]]++;

  }

  cout<<"\ncreate set done\n";
}

void print()
{
  for(int i=1;i<SIZE;i++)
  {
    for(int j=hashTable[i];j!=-1;j=chainTable[j])
    {
      cout<<j<<" ";
    }
    //cout<<i<<":"<<set[i]<<" ";
    cout<<endl;
  }




}
int main()
{
  init();
  assignSet();
  createSet();
  print();
  cout<<"done\n";

  // int t;
  // cin>>t;
  //
  // while (t--)
  // {
  //   int n;
  //   cin>>n;
  //
  //   int totalCount=0;
  //
  //   while(true)
  //   {
  //     int start=0;
  //     int end;
  //     for(int i=1;i<=SIZE/2;i++)
  //     {
  //       end=start+count[i];
  //       int localCount=0;
  //       int flag=true;
  //     //  cout<<"start:"<<start<<" end:"<<end<<endl;
  //       for(int j=start;j<end;j++)
  //       {
  //         if(list[j]>n)
  //         {
  //           localCount++;
  //         }
  //         else
  //         {
  //
  //
  //           if(flag)
  //           {
  //             flag=false;
  //             cout<<count[i]-localCount<<" ";
  //
  //           }
  //           cout<<list[j]<<" ";
  //           totalCount++;
  //         }
  //
  //         if(totalCount==n)break;
  //       }
  //
  //       if(totalCount==n)break;
  //       cout<<endl;
  //       start=end;
  //     }
  //
  //     if(totalCount==n)break;
  //
  //   }
  //
  //   cout<<endl;
  // }

  return 0;
}
