#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    scanf("%d", &n);

    int at[n], bt[n], pr[n], orgbt[n];
    int ct[n], tat[n], wt[n], pid[n];
    int gantt[n];

    for(int i=0; i<n; i++)
        scanf("%d", &at[i]);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &bt[i]);
        orgbt[i] = bt[i];
    }

    for(int i=0; i<n; i++)
        scanf("%d", &pr[i]);   // priority array (smaller = higher priority)

    for(int i=0; i<n; i++)
        pid[i] = i;

    int timey = 0;
    int done = 0;

    // Start at earliest arrival
    timey = *min_element(at, at+n);

    while(done < n)
    {
        int index = -1;
        int bestP = INT_MAX;

        // pick the highest priority (lowest priority number) among arrived processes
        for(int i=0; i<n; i++)
        {
            if(bt[i] != -1 && at[i] <= timey)
            {
                if(pr[i] < bestP)
                {
                    bestP = pr[i];
                    index = i;
                }
                else if(pr[i] == bestP)
                {
                    // tie → use arrival time
                    if(at[i] < at[index])
                        index = i;
                }
            }
        }

        // If nothing arrived yet, move time forward
        if(index == -1)
        {
            timey++;
            continue;
        }

        // Execute completely (non-preemptive)
        timey += bt[index];
        bt[index] = -1;

        ct[index] = timey;
        tat[index] = ct[index] - at[index];
        wt[index] = tat[index] - orgbt[index];

        gantt[done] = index;
        done++;
    }

    // Gantt chart process order
    for(int i=0; i<n; i++)
        cout << gantt[i] << " ";

    return 0;
}
