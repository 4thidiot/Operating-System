#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n;
	cin>>n;
	int at[n], bt[n];
	int pid[n], ct[n], tat[n], wt[n];
	
	for(int i=0; i<n; i++)
	    cin>>at[i];
	for(int i=0; i<n; i++)
	    cin>>bt[i];
	for(int i=0; i<n; i++)
	    pid[i] = i+1;
	
	for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(at[j]>at[j+1])
            {
                swap(at[j], at[j+1]);
                swap(bt[j], bt[j+1]);
                swap(pid[j], pid[j+1]);
            }
        }
    }
	
	ct[0] = at[0] + bt[0]; 
	tat[0] = ct[0] - at[0];
  wt[0] = tat[0] - bt[0];
    
	for(int i=1; i<n; i++)
	{
	    ct[i] = max(ct[i-1], at[i]) + bt[i];
	    tat[i] = ct[i] - at[i];
	    wt[i] = tat[i] - bt[i];
	}
	
	for(int i=0; i<n; i++)
	    cout<<pid[i]<<" ";
	cout<<'\n';
	
	cout<<"pid AT BT WT TAT\n";
	  
	
	for(int i=0; i<n; i++)
	    cout<<pid[i]<<" "<<at[i]<<" "<<bt[i]<<" "<<wt[i]<<" "<<tat[i]<<'\n';
	
	return 0;
}
