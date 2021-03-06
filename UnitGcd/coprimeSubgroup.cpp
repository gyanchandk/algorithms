#include<iostream>
using namespace std;
//#define L 1000006
//long int  SIZE;
#define SIZE 1000006
long int arr[SIZE];
long int set[SIZE];
long int count[SIZE];

int hashTable[SIZE];
int chainTable[SIZE];

void init()
{

  for(long int i=0;i<SIZE;i++)
  {
    arr[i]=-1;
    hashTable[i]=chainTable[i]=-1;
    count[i]=0;
  }

  for(long int i=2;i<=SIZE/2;i++)
  {
    if(arr[i]!=-1)continue;
    long int num=i;
    while(num<SIZE)
    {
      if(arr[num]==-1)
      {
        arr[num]=i;
      }
      num+=i;
    }
  }

  //cout<<"\ninit done\n";

}
void assignSet()
{
  set[1]=1;
  set[0]=1;
  for(long int i=2;i<SIZE;i++)
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

  //cout<<"\nassign set done\n";
}

void createSet()
{

  for(long int i=1;i<SIZE;i++)
  {
    //cout<<set[i]<<" ";
    long int h=set[i];
    chainTable[i]=hashTable[h];
    hashTable[h]=i;
    count[set[i]]++;

  }

  //cout<<"\ncreate set done\n";
}

// void print()
// {
//   for(long int i=1;i<=SIZE/2;i++)
//   {
//     for(long int j=hashTable[i];j!=-1;j=chainTable[j])
//     {
//       cout<<j<<" ";
//     }
//
//     cout<<endl;
//   }
//
//   cout<<"\nprint done\n";
//
//
//
// }
int main()
{

  //print();
  //cout<<"done\n";

  int t;
  //cin>>t;
  scanf("%d",&t );


  init();
  assignSet();
  createSet();

  for(int i=0;i<t;i++)
  {

    long int n;
    scanf("%ld",&n );
    if(n==1){
      //cout<<"1\n1 1\n";
      printf("1\n1 1\n");
      continue;
    }
    //cout<<n/2<<endl;
    printf("%ld\n",n/2 );
    for(long int i=1;i<=n/2;i++)
    {
      bool flag=true;
      long int tempCount=0;
      for(long int j=hashTable[i];j!=-1;j=chainTable[j])
      {
        if(j>n)
        {
            tempCount++;
        }
        else
        {
          if(flag)
          {
            //cout<<count[i]-tempCount<<" ";
            printf("%ld", count[i]-tempCount);
            flag=false;
          }
          //cout<<j<<" ";
          printf(" %ld",j );
        }

      }

      //cout<<endl;
      printf("\n" );
    }

    fflush(stdin);

  }

  return 0;
}
