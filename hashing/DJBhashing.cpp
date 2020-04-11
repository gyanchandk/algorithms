#include<iostream>
using namespace std;
#define TABLE_SIZE 500
typedef struct ENTRY{
  bool valid;
  string name;
  string email;
}Entry;
typedef struct RECORD{
  long int validEntries;
  long int currIndex;
  Entry entry[TABLE_SIZE];
}Record;

Record record;
long int nameHashTable[TABLE_SIZE],nameChainTable[TABLE_SIZE];
long int emailHashTable[TABLE_SIZE],emailChainTable[TABLE_SIZE];

void init()
{
  for(long int i=0;i<TABLE_SIZE;i++)
  {
    nameHashTable[i]=nameChainTable[i]=-1;
    emailHashTable[i]=emailChainTable[i]=-1;
    record.entry[i].valid=false;
  }
  record.validEntries=0;
  record.currIndex=-1;
}
long int getIndexFromRecord()
{
  if(record.validEntries==TABLE_SIZE)
  {
    cout<<"\nTABLE IS EXHAUSTED !";
    return -1;
  }

  long int index=record.currIndex;

  while(true)
  {
    index=(index==TABLE_SIZE)?0:(index+1);
    if(record.entry[index].valid==false)
    {
      return index;
    }
  }
}
unsigned int DJBHash(string str)
{
   unsigned int hash = 5381;
   unsigned int i    = 0;

   for(i = 0;str[i]!='\0'; i++)
   {
      hash = (((hash << 5) + hash) + str[i])%TABLE_SIZE;
   }

   return hash;
}

void addToRecord(string name,string email)
{

  long int index=getIndexFromRecord();
  if(index==-1)
  {
    //do nothing
    return ;
  }
  record.entry[index].name=name;
  record.entry[index].email=email;
  record.entry[index].valid=true;
  record.validEntries+=1;
  record.currIndex=index;

  unsigned int h=DJBHash(name);
  nameChainTable[index]=nameHashTable[h];
  nameHashTable[h]=index;

  h=DJBHash(email);
  emailChainTable[index]=emailHashTable[h];
  emailHashTable[h]=index;
}
long int deleteFromRecordByEmail(string email)
{
  long int count=0;
  unsigned int h=DJBHash(email);
  cout<<"\n DELETED ENTRIES ARE:";
  for(long int i=emailHashTable[h];i!=-1;i=emailChainTable[i])
  {
    if(record.entry[i].valid && (email.compare(record.entry[i].email))==0)
    {
      cout<<"\n"<<record.entry[i].name<<" , "<<record.entry[i].email;
      record.entry[i].valid=false;
      record.validEntries-=1;
      count++;
    }
  }

  cout<<"\n\n TOTAL ENTRIES DELETED: "<<count<<endl;
}
void searchInRecordByEmail(string email)
{
  cout<<"\n ENTRIES FOUND:";
  unsigned int h=DJBHash(email);
  for(long int i=emailHashTable[h];i!=-1;i=emailChainTable[i])
  {
    if(record.entry[i].valid && (email.compare(record.entry[i].email))==0)
    {
      cout<<"\n"<<record.entry[i].name<<" , "<<record.entry[i].email;
    }
  }

  cout<<endl;
}
int main()
{
  init();
  addToRecord("gyanchand","gyan1294@gmail.com");
  addToRecord("kewatgyanchand","gyan1294@gmail.com");
  addToRecord("abhishek","abhishek1996@gmail.com");

  searchInRecordByEmail("gyan1294@gmail.com");
  deleteFromRecordByEmail("gyan1294@gmail.com");
  searchInRecordByEmail("gyan1294@gmail.com");
  return 0;
}
