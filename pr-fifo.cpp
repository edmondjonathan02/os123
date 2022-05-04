#include <stdio.h>
int main()
{
    int i, j, n, pages[50], frame[10], no, k, avail, miss = 0, hit = 0;
    printf("\nEnter total no of pages:\n");
    scanf("%d", &n);
    printf("\nEnter the page numbers:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &pages[i]);
    printf("\nEnter total no of frames:");
    scanf("%d", &no);
    for (i = 0; i < no; i++)
        frame[i] = -1;
    j = 0;
    printf("\n PAGES \t PAGE FRAMES \tMISS or HIT\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d\t\t", pages[i]);
        avail = 0;
        for (k = 0; k < no; k++)
            if (frame[k] == pages[i])
            {
                avail = 1;
                for (k = 0; k < no; k++)
                    printf("%d\t", frame[k]);
                hit++;
                printf("H\n");
                printf("\n------------------------------------------------------------------------\n");
            }
        if (avail == 0)
        {
            frame[j] = pages[i];
            j = (j + 1) % no;
            miss++;
            for (k = 0; k < no; k++)
                printf("%d\t", frame[k]);
            printf("M");
            printf("\n--------------------------------------------------------------\n");
        }
        printf("\n");
    }
    printf("Total miss is %d\n", miss);
    printf("Total hit is %d\n", hit);
    printf("Hit ratio = %d/%d\n", hit, n);
    printf("Miss ratio = %d/%d\n", miss, n);
    return 0;
}
/*OUTPUT
Enter total no of pages:
10

Enter the page numbers:
2
3
4
2
1
3
7
5
4
3

Enter total no of frames:3

 PAGES   PAGE FRAMES    MISS or HIT
2               2       -1      -1      M
--------------------------------------------------------------

3               2       3       -1      M
--------------------------------------------------------------

4               2       3       4       M
--------------------------------------------------------------

2               2       3       4       H

------------------------------------------------------------------------

1               1       3       4       M
--------------------------------------------------------------

3               1       3       4       H

------------------------------------------------------------------------

7               1       7       4       M
--------------------------------------------------------------

5               1       7       5       M
--------------------------------------------------------------

4               4       7       5       M
--------------------------------------------------------------

3               4       3       5       M
--------------------------------------------------------------

Total miss is 8
Total hit is 2
Hit ratio = 2/10
Miss ratio = 8/10*/
