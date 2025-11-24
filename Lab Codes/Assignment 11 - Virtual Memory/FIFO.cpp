#include <bits/stdc++.h>
using namespace std;

int frames[3] = {-1,-1,-1};
int resources[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};

int search(int val)
{
    for(int i=0; i<3; i++)
    {
        if(frames[i]==val)
            return 1;
    }
    return 0;
}

int main() 
{
	int faults=0, idx=0;
	
	for(int i=0; i<20; i++)
	{
	    if(search(resources[i]) == 0)
	    {
	        faults++;
	        frames[idx] = resources[i];
	        idx = (idx+1)%3;
	    }
	}
    
    cout<<faults;
    
    return 0;
}
