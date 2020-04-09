#include<iostream>
using namespace std;
#define MAX_WORD_LENGTH 13
#define NUM_OF_ALPHABET 26
#define MAX 6000
#define MAX_WORDS 500

int q[MAX];
int front,rear;
char record[MAX_WORDS][MAX_WORD_LENGTH];

int recordIndex;
int trieIndex;
int root;

struct Trie{
  int children[NUM_OF_ALPHABET];
  int count;
  bool isLeaf;
  int recordPtr;
}trie[MAX];

int pop()
{
  if(front==-1 || front >rear)
  {
    front=rear=-1;
    return -1;
  }

  return q[front++];
}
void push(int val)
{
  if(front==-1)
  {
    front++;
  }
  q[++rear]=val;

}
void mstrcpy(char *dest,char const *src)
{
  int i=0;
  while(src[i]!='\0')
  {
    dest[i]=src[i];
    i++;
  }
  dest[i]='\0';
}
void initialize(int tIndex)
{
  for(int i=0;i<NUM_OF_ALPHABET;i++)
  {
    trie[tIndex].children[i]=-1;
  }
  trie[tIndex].isLeaf=false;
  trie[tIndex].count=0;
  trie[tIndex].recordPtr=-1;
}

void init()
{
  root=0;
  recordIndex=-1;
  trieIndex=-1;

  trieIndex++;
  initialize(trieIndex);
}
void bfs(int start)
{
  front=rear=-1;
  push(start);

  while(true)
  {
    int ind=pop();

    if(ind==-1)
      break;

    if(trie[ind].isLeaf)
    {
      int rInd=trie[ind].recordPtr;
      cout<<endl<<record[rInd]<<" fre:"<<trie[ind].count;
    }

    for(int i=0;i<NUM_OF_ALPHABET;i++)
    {
      int tInd=trie[ind].children[i];
      if(tInd!=-1)
        push(tInd);
    }
  }
}
void autoComplete(char const str[MAX_WORD_LENGTH])
{
  int ptr=root;
  int i=0;

  while(str[i]!='\0')
  {
    int ind=str[i]-'a';
    if(trie[ptr].children[ind]==-1)
    {
      cout<<"\n No match found\n";
      return;
    }
    ptr=trie[ptr].children[ind];
    i++;
  }

  bfs(ptr);



}
void insert(char const str[MAX_WORD_LENGTH])
{
  int ptr=root;
  int i=0;

  while(str[i]!='\0')
  {
    int ind=str[i]-'a';
    if(trie[ptr].children[ind]==-1)
    {
      trieIndex++;
      initialize(trieIndex);
      trie[ptr].children[ind]=trieIndex;

    }

    ptr=trie[ptr].children[ind];

    i++;
  }

  trie[ptr].isLeaf=true;
  trie[ptr].count++;
  if(trie[ptr].count==1)
  {
    recordIndex++;
    mstrcpy(record[recordIndex],str);
    trie[ptr].recordPtr=recordIndex;
  }
}
int main()
{
  init();
  insert("sing");
  insert("singer");
  insert("single");
  insert("sing");
  insert("singleton");


  autoComplete("sing");
  return 0;
}
