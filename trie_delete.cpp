#include<iostream>
using namespace std;
#define MAX 900000
#define MAX_SIZE 101
struct Node{
	int count;
	int child[26];
	int leafCount;
}node[MAX];
int index ;
int buffer[MAX_SIZE][2];
int buffer_index;
void getNewNode()
{
	index++;
	for(int i = 0; i< 26; i++)
	{
		node[index].child[i] = -1;
		
	}
	node[index].count = 0;
	node[index].leafCount = 0;
	
}
void init_trie()
{
	index = -1;
	//initialize root
	getNewNode();
}

void Tries_insert(const char *str)
{
	int i = 0;
	int ptr = 0;

	while(str[i] != '\0')
	{
		int ind = str[i] - 'a';
		if(node[ptr].child[ind] == -1)
		{
			getNewNode();
			node[ptr].child[ind] = index;	
		}

		ptr = node[ptr].child[ind];
		node[ptr].count++;
		i++;
	}
	node[ptr].leafCount++;
    
}

bool Tries_search(const char *str)
{
	int ptr = 0;
	int i = 0;
	

	while(str[i] != '\0')
	{
		int ind = str[i] - 'a';
		ptr = node[ptr].child[ind];
		if(ptr == -1)
			return false;

		i++;
	}
	if(node[ptr].leafCount>=1)
		return true;
	else
		return false;
}

int Tries_CountofkeysWithPrefix(const char *str)
{
	int ptr = 0;
	int i = 0;
	while(str[i] != '\0')
	{
		int ind = str[i] - 'a';
		ptr = node[ptr].child[ind];
		if(ptr == -1)
			return 0;

		i++;
	}

	return node[ptr].count;
}


void Tries_deleteKey(const char *key)
{
	bool found = false;
	int ptr = 0;
	int i = 0;
	buffer_index = -1;
	buffer[++buffer_index][0] = 0;
	buffer[buffer_index][1] = 0;

	while(key[i] != '\0')
	{
		int ind = key[i] - 'a';
		ptr = node[ptr].child[ind];
		buffer[++buffer_index][0] = ptr;
		buffer[buffer_index][1] = node[ptr].count;
		if(ptr == -1)
			break;

		i++;
	}
	if(ptr!=-1 && node[ptr].leafCount >= 1)
		found = true;
	else
		found = false;
	//case:1 not present======================
	if(!found)
	{
		return;
	}
	
	//case 2: unique key===================
	bool uniqueKey = true;
	for(int i = 1; i <= buffer_index; i++)
	{
		if(buffer[i][1] != 1)
		{
			uniqueKey = false;
			break;
		}
			
	}

	if(uniqueKey)
	{
		//just change the root;
		int ind = key[0] - 'a';
		node[0].child[ind] = -1;
		return;
	}
	
	//case 3:key is prefix of another long key================
	bool isPrefix = false;
	int ptr = buffer[buffer_index][0];
	for(int i = 0; i < 26; i++)
	{
		if(node[ptr].child[i] != -1)
			isPrefix = true;
	}

	for(int i = 1; i <= buffer_index; i++)
	{
		node[buffer[i][0]].count--;
	}
	node[buffer[buffer_index][0]].leafCount--;

	if(isPrefix)
	{
		return;
	}

	//case 4:some key is prefix of this key ====================
	//isPrefix==false
	for(int i = buffer_index; i >= 1; i--)
	{
		if(node[buffer[i][0]].leafCount == 1)
		{
			int tind = key[i-1] - 'a';
			node[buffer[i][0]].child[tind] = -1;
			break;
		}
	}

}
