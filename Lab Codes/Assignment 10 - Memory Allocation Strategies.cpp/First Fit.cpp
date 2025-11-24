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
        
	for(int i=0; i<4; i++)
	{
	    for(int j=0; j<6; j++)
	    {
	        if(given[i]<=space[j])
	        {
	            ans[j] = given[i];
	            space[j] -= given[i];
	            break;
	        }
	    }
	}
	
	for(int i=0; i<6; i++)  
	    cout<<ans[i]<<" ";
}
