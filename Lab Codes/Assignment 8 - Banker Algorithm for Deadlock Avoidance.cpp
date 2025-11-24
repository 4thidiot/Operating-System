#include <bits/stdc++.h>
using namespace std;

struct process
{
    int pid;
    int allocation[4];
    int max[4];
    int need[4];
    int completed;
}p[5];

int main() 
{
	int available[4];
	
	for(int i=0; i<5; i++)
	{
	    p[i].pid = i;
	    p[i].completed = 0;
	    for(int j=0; j<4; j++)
	    {
	        cin>>p[i].allocation[j]>>p[i].max[j];
	        p[i].need[j] = p[i].max[j] - p[i].allocation[j];
	    }
	}
	for(int i=0; i<4; i++)
	    cin>>available[i];
	    
	//Code for safe sequence starts here
	int done = 0;
	while(1)
	{
	    bool executed = false;
	    
	    for(int i=0; i<5; i++)
	    {
	        bool canrun = true;
	        
	        if(p[i].completed == 0)
	        {
    	        for(int j=0; j<4; j++) //to check if any scenario fail hoga
    	        {
    	            if(p[i].need[j] > available[j])
    	            {
    	                canrun = false;
    	                break;
    	            }
    	        }
    	        
    	        if(canrun) //safe sequence code
    	        {
    	            cout<<p[i].pid<<" ";
    	            for(int j=0; j<4; j++) //releasing the p[i].pid resources 
	                    available[j] += p[i].allocation[j];
	                    
	                p[i].completed = 1;
	                executed = true;
	                done++;
    	        }
	        }
	    }
	    if(done == 5)
        {
            cout << "System is SAFE\n";
            break;
        }
    
        if(!executed)
        {
            cout << "System is NOT in safe state\n";
            break;
        }
	}
	
    return 0;
}

