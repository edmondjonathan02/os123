#include <stdio.h>
int main()
{
    int count = 0, m, n, process, temp, resource;
    int allocation_table[5] = {0, 0, 0, 0, 0};
    int available[5], current[5][5], maximum_claim[5][5];
    int maximum_resources[5], running[5], safe_state = 0;
    printf("\nEnter The Total Number Of Processes: ");
    scanf("%d", &process);
    for (m = 0; m < process; m++)
    {
        running[m] = 1;
        count++;
    }
    printf("\nEnter The Total Number Of Resources: ");
    scanf("%d", &resource);
    printf("\nEnter The Resource Vector: ");
    for (m = 0; m < resource; m++)
    {
        scanf("%d", &maximum_resources[m]);
    }
    printf("\nEnter Allocation Matrix:\n");
    for (m = 0; m < process; m++)
    {
        for (n = 0; n < resource; n++)
        {
            scanf("%d", &current[m][n]);
        }
    }
    printf("\nEnter The Claim Matrix:\n");
    for (m = 0; m < process; m++)
    {
        for (n = 0; n < resource; n++)
        {
            scanf("%d", &maximum_claim[m][n]);
        }
    }
    for (m = 0; m < process; m++)
    {
        for (n = 0; n < resource; n++)
        {
            allocation_table[n] = allocation_table[n] + current[m][n];
        }
    }
    printf("\nAllocated Resources \n");
    for (m = 0; m < resource; m++)
    {
        printf("%d \t", allocation_table[m]);
    }
    for (m = 0; m < resource; m++)
    {
        available[m] = maximum_resources[m] - allocation_table[m];
    }
    printf("\nAvailable Vector:");
    for (m = 0; m < resource; m++)
    {
        printf("%d \t", available[m]);
    }
    printf("\n");
    while (count != 0)
    {
        safe_state = 0;
        for (m = 0; m < process; m++)
        {
            if (running[m])
            {
                temp = 1;
                for (n = 0; n < resource; n++)
                {
                    if (maximum_claim[m][n] - current[m][n] > available[n])
                    {
                        temp = 0;
                        break;
                    }
                }
                if (temp)
                {
                    printf("\nProcess %d \n", m + 1);
                    running[m] = 0;
                    count--;
                    safe_state = 1;
                    for (n = 0; n < resource; n++)
                    {
                        available[n] = available[n] + current[m][n];
                    }
                    break;
                }
            }
        }
        if (safe_state == 0)
        {
            printf("\nThe Processes Are In An Unsafe State \n");
            break;
        }
        else
        {
            printf("\nAvailable Vector\n");
            for (m = 0; m < resource; m++)
            {
                printf("\t%d", available[m]);
            }
            printf("\n");
        }
    }
    return 0;
}

/*OUTPUT
Enter The Total Number Of Processes: 4

Enter The Total Number Of Resources: 3

Enter The Resource Vector: 9 3 6

Enter Allocation Matrix:
1 0 0
0 1 2
2 1 1
0 0 2

Enter The Claim Matrix:
3 2 2
6 1 3
3 1 4
4 2 2

Allocated Resources
3       2       5
Available Vector:6      1     1

Process 2

Available Vector
        6       2       3

Process 1

Available Vector
        7       2       3

Process 3

Available Vector
        9       3       4

Process 4

Available Vector
        9       3       6*/