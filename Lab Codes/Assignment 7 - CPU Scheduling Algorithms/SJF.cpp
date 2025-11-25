#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    scanf("%d", &n);

    int at[n], bt[n], orgbt[n], pid[n];
    int ct[n], tat[n], wt[n];
    int gantt[n];

    for(int i=0; i<n; i++)
        scanf("%d", &at[i]);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &bt[i]);
        orgbt[i] = bt[i];
    }

    for(int i=0; i<n; i++)
        pid[i] = i;

    int timey = 0;
    int done = 0;

    // make sure time starts at first arrival
    timey = *min_element(at, at+n);

    while(done < n)
    {
        int index = -1;
        int minbt = INT_MAX;

        // find process with shortest burst that has arrived
        for(int i=0; i<n; i++)
        {
            if(bt[i] != -1 && at[i] <= timey)
            {
                if(bt[i] < minbt)
                {
                    minbt = bt[i];
                    index = i;
                }
            }
        }

        // if nothing arrived yet, move time forward
        if(index == -1)
        {
            timey++;
            continue;
        }

        // run this process
        timey += bt[index];
        bt[index] = -1;      // mark finished

        ct[index] = timey;
        tat[index] = ct[index] - at[index];
        wt[index] = tat[index] - orgbt[index];

        gantt[done] = index;
        done++;
    }

    // print gantt chart
    for(int i=0; i<n; i++)
        cout << gantt[i] << " ";

    return 0;
}
