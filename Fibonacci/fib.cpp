
#include <iostream>
using namespace std;

#define TOTAL_BITS 32
#define MAX_POWER 9

int setBits[TOTAL_BITS];
long int matrix[2][MAX_POWER*2];

void init();
void printInBinary();
int decToBinary(int n);
void calculatePowerOfMatrix();

void init()
{
  for(int i=0;i<TOTAL_BITS;i++){
    setBits[i]=0;
  }
}

void printInBinary(){
  cout<<"Number in binary is:\n";
  for(int i=TOTAL_BITS;i>=0;i--){
    cout<<setBits[i];
  }
}
// Function that convert Decimal to binary
int decToBinary(int n)
{
	// Size of an integer is assumed to be 32 bits
	for (int i = TOTAL_BITS-1; i >= 0; i--) {
		int k = n >> i;
		if (k & 1){
      setBits[i]=1;
    }
	}
}

void calculatePowerOfMatrix(){
   matrix[0][0]=0;
   matrix[0][1]=matrix[1][0]=matrix[1][1]=1;

   for(int i=1;i<MAX_POWER;i++){
     for(int j=0;j<2;j++){
       for(int k=(i*2-2);k<=(i*2-1);k++){
         matrix[j][k+2]=0;
         for(int l=0;l<2;l++){
           cout<<"j,k+2,i,j,k,l:"<<j<<" "<<k+2<<" "<<j<<" "<<2*i-2+l<<" "<<l<<" "<<k<<endl;
           matrix[j][k+2]+=matrix[j][2*i-2+l]*matrix[l][k];

         }

           cout<<"mat:"<<matrix[j][k+2]<<endl;
       }
     }
   }
}

void printPowerMatrix(){
  for(int i=0;i<2;i++){
    cout<<endl;
    for(int j=0;j<MAX_POWER*2;j++){
      cout<<matrix[i][j]<<" ";
    }
  }
}

// driver code
int main(){

  init();
  calculatePowerOfMatrix();
  printPowerMatrix();

  return 0;
}
