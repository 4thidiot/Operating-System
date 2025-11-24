#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int given[4];
	int space[6];
	int ans[6];
	
	for(auto& it : space)
	    cin>>it;
    
    for(auto& it : given)
	    cin>>it;
	
	for (int i=0; i<6; i++)
        ans[i] = -1;
        
    //main logic    
	for (int i = 0; i < 4; i++)
    {
        int bestBlock = -1;
        int minRemain = INT_MAX;

        for (int j = 0; j < 6; j++)
        {
            if (given[i] <= space[j]) //finding min block that fits
            {
                int remain = space[j] - given[i];
                if (remain < minRemain)
                {
                    minRemain = remain;
                    bestBlock = j;
                }
            }
        }

        if (bestBlock != -1) //assigning that block in ans
        {
            ans[bestBlock] = given[i];
            space[bestBlock] -= given[i];
        }
    }

    
	
	for(int i=0; i<6; i++)  
	    cout<<ans[i]<<" ";
}
