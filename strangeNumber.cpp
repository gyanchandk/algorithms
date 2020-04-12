
#include <bits/stdc++.h>
using namespace std;

int primeFactors(long int n,long int k)
{

	long int arr[2][100000];
	long int index=-1;
	while (n % 2 == 0)
	{
		//cout << 2 << " ";

		if(index==-1 ||arr[0][index]!=2)
			{
			    index++;
			    arr[0][index]=2;
			    arr[1][index]=1;
			}
			else{

			        arr[1][index]+=1;

			}
		//cout<<"ind2:"<<index<<endl;
		n = n/2;
	}


	for (long int i = 3; i <= sqrt(n); i = i + 2)
	{
		// While i divides n, print i and divide n
		while (n % i == 0)
		{
			//cout << i << " ";
			n = n/i;


			if(index==-1 ||arr[0][index]!=i)
			{
			    index++;
			    arr[0][index]=i;
			    arr[1][index]=1;
			}
			else{

			        arr[1][index]+=1;

			}
		}
	}

	// This condition is to handle the case when n
	// is a prime number greater than 2
	if (n > 2) {
	    	//cout << n << " ";
	    	if(index==-1 ||arr[0][index]!=n)
			{
			    index++;
			    arr[0][index]=n;
			    arr[1][index]=1;
			}
			else{

			        arr[1][index]+=1;

			}

	}

	//cout<<"index:"<<index<<endl;

  long int numberOfFactors=index;
  long int powerSum=0;
	for(int i=0;i<=index;i++){
	   powerSum+=arr[1][index];
	}

  if(powerSum>=k)
  {
    return 1;
  }
  else{
    return 0;
  }

}

/* Driver code */
int main()
{

    int t;
    cin>>t;
    long int arr[2][100001];
    for(int i=0;i<t;i++)
    {
        cin>>arr[0][i]>>arr[1][i];
    }

    for(int i=0;i<t;i++){

	  cout<<primeFactors(arr[0][i],arr[1][i])<<endl;
    }

	return 0;
}
