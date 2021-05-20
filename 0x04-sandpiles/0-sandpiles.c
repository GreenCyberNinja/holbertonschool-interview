#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}
void copy_grid(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for(i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid2[i][j];
		}
}
int is_stable(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				return(0);
			}
		}
	return(1);
}
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int  i, j;
	int isStable = 0;


	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	copy_grid(grid2, grid1);
	if (is_stable(grid1) == 0)
	{
		printf("=\n");
		print_grid(grid1);	
		while (isStable == 0)
		{
			isStable = 1;
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					if (grid1[i][j] > 3)
					{
						isStable = 0;
						grid2[i][j] -= 4;
						if (j - 1 >= 0)
							grid2[i][j-1] += 1;
						if (j + 1 < 3)
							grid2[i][j+1] += 1;
						if (i - 1 >= 0)
							grid2[i-1][j] += 1;
						if (i + 1 < 3)
							grid2[i+1][j] += 1;
					}
				}
			}
			copy_grid(grid1, grid2);
			if (is_stable(grid1) == 0)
			{
				printf("=\n");
				print_grid(grid1);
			}
		}
	}
}
