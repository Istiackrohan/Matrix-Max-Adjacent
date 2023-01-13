#include <stdio.h>

int n;
int grid[100][100];

// Function to find the cell with maximum sum of adjacent cells
void find_max_sum_cell(int n, int grid[][100])
{
    int max_sum = 0;
    int max_i = 0;
    int max_j = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            // Summing up the adjacent cells
            if (i > 0)
            {
                sum += grid[i - 1][j];
                if (i + 1 > 0) 
                    sum += grid[i + 1][j];
            }
            if (i < n - 1)
            {
                sum += grid[i + 1][j];
                if (i - 1 > 0)
                    sum += grid[i - 1][j];
            }
            if (j > 0)
            {
                sum += grid[i][j - 1];
                if (i - 1 > 0)
                    sum += grid[i - 1][j - 1];
                if (i + 1 > 0)
                    sum += grid[i + 1][j - 1];
                if (j + 1)
                {
                    sum += grid[i][j - 1];
                    if (i - 1 > 0)
                        sum += grid[i - 1][j - 1];
                    if (i + 1 > 0)
                        sum += grid[i + 1][j - 1];
                }
            }
            if (j < n - 1)
            {
                sum += grid[i][j + 1];
                if (i + 1 > 0)
                    sum += grid[i + 1][j + 1];
                if (i - 1 > 0)
                    sum += grid[i - 1][j + 1];
                if (j - 1 > 0)
                {
                    sum += grid[i][j - 1];
                    if (i + 1 > 0)
                        sum += grid[i + 1][j - 1];
                    if (i - 1 > 0)
                        sum += grid[i - 1][j - 1];
                }
            }
            // Checking if current cell has greater sum than previous cells
            if (sum > max_sum)
            {
                max_sum = sum;
                max_i = i;
                max_j = j;
            }
        }
    }
    printf("Cell with maximum sum of adjacent cells: %d, %d\n", max_i + 1, max_j + 1);
}

int main()
{
    // Taking input from user
    printf("Enter the size of the grid (nxn): ");
    scanf("%d", &n);

    printf("Enter elements for grid:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter element for cell %d, %d: ", i + 1, j + 1);
            scanf("%d", &grid[i][j]);
        }
    }

    // Print the grid
    printf("Grid:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Finding the cell with maximum sum of adjacent cells
    find_max_sum_cell(n, grid);

    return 0;
}
