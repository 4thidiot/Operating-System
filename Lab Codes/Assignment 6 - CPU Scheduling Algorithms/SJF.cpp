#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int at[n], bt[n], pid[n];
    int ct[n], tat[n], wt[n];
    int done[n];

    for(int i=0; i<n; i++)
        scanf("%d", &at[i]);

    for(int i=0; i<n; i++)
        scanf("%d", &bt[i]);

    for(int i=0; i<n; i++)
        pid[i] = i+1;

    for(int i=0; i<n; i++)
        done[i] = 0;

    int current = 0;
    int completed = 0;

    while(completed < n)
    {
        int ready[n], rsize = 0;

        // Collect arrived processes
        for(int i=0; i<n; i++)
        {
            if(done[i] == 0 && at[i] <= current)
            {
                ready[rsize++] = i;
            }
        }

        // If no process has arrived yet → jump to earliest arrival time
        if(rsize == 0)
        {
            int nxt = 1000000000;
            for(int i=0; i<n; i++)
                if(done[i] == 0 && at[i] < nxt)
                    nxt = at[i];

            current = nxt;
            continue;
        }

        // Pick shortest job (minimum BT)
        int best = ready[0];
        for(int i=0; i<rsize; i++)
        {
            int idx = ready[i];
            if(bt[idx] < bt[best])
                best = idx;
        }

        // Calculate times
        ct[best] = current + bt[best];
        tat[best] = ct[best] - at[best];
        wt[best] = tat[best] - bt[best];

        current = ct[best];
        done[best] = 1;
        completed++;
    }

    printf("pid AT BT WT TAT\n");
    for(int i=0; i<n; i++)
    {
        printf("%d %d %d %d %d\n",
               pid[i], at[i], bt[i], wt[i], tat[i]);
    }

    return 0;
}
