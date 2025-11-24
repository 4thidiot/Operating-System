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

int index(int idx, int curr)
{
    int a=INT_MAX, b=INT_MAX, c=INT_MAX; //page never used is at largest dist
    for(int i=0; i<3; i++)
    {
        for(int j=curr+1; j<20; j++)
        {
            if(frames[i]==resources[j])
            {
                if(i==0)
                    a = j - curr;
                else if(i==1)
                    b = j - curr;
                else
                    c = j - curr;
                break;
            }
        }
    }
    int maxi = max(max(a, b), c);
    
    if(maxi == a) return 0;
    if(maxi == b) return 1;
    return 2;
}

int main() 
{
	int faults=0, idx=0;
	
	for(int i=0; i<20; i++)
	{
	    if(search(resources[i]) == 0)
	    {
	        faults++;
	        idx = index(idx, i);
	        frames[idx] = resources[i]; //order ulta from last time
	    }
	}
    
    cout<<faults;
    
    return 0;
}
