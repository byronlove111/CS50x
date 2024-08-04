#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void    print_grid(int *grid[]);

int     missing_on_row(int _case, int **grid, int row)
{
        int i = 0;

        while(i < 9)
        {
                if(_case == grid[row][i])
                {
                        return 1;
                }
                i++;
        }

        return 0;
}

int     missing_on_column(int _case, int **grid, int index_case)
{
        int i = 0;

        while(i < 9)
        {
                if(_case == grid[i][index_case])
                {
                        return 1;
                }
                i++;
        }

        return 0;
}

int     missing_on_block(int _case, int** grid, int row, int index_case)
{
        int _row = row - ( row % 3 );
        int _index_case = index_case - ( index_case % 3);

        row = _row;
        while(row < _row +3)
        {
                index_case = _index_case;
                while(index_case < _index_case+3)
                {
                        if (grid[row][index_case] == _case)
                        {
                                return 1;
                        }
                        index_case++;
                }
                row++;
        }
        return 0;
}

int     isValide(int **grid, int position)
{
        int row = position / 9;
        int column = position % 9;
        int i = 1;

        if(position == 81)
                return 0;

        if(grid[row][column] != 0)
                return isValide(grid, position+1);

        while(i <= 9)
        {
                if((missing_on_block(i, grid, row, column) == 0) && (missing_on_row(i, grid, row) == 0) && (missing_on_column(i, grid, column) == 0))
                {
                        grid[row][column] = i;
                        print_grid(grid);

                        if( isValide(grid, position+1) == 0 )
                                return 0;
                }
                i++;
        }

        grid[row][column] = 0;

        return 1;
}

void    print_grid(int *grid[])
{
        int i = 0;
        int k = 0;
        while(i < 9)
        {
                while(k < 9)
                {
                        printf("%d ", grid[i][k]);
                        k++;
                }
                printf("\n");
                k = 0;
                i++;
        }

        printf("\n--------------------------------------------\n");
}

void    free_grid(int *grid[])
{
        int i = 0;

        while(i < 9)
        {
                free(grid[i]);
                i++;
        }
}

int     ft_atoi(char c)
{
        if(c == '.')
                return 0;

        c = c - '0';

        return c;
}

void    create_grid(int *grid[], char *row, int index)
{
        int i = 0;
        int *row_int;
        row_int = (int*)malloc(9 * sizeof(int));

        while(i < 9)
        {
                row_int[i] = ft_atoi(row[i]);
                i++;
        }
        grid[index] = row_int;
}

void    main(int argc, char *argv[])
{
        int     *grid[9];
        int     *tab[9];
        int i = 1;
        int index = 0;

        if(argc < 10)
                return;

        while(i < 10)
        {
                create_grid(grid, argv[i], index);
                create_grid(tab, argv[i], index);
                index++;
                i++;
        }

        if(isValide(grid, 0) == 0)
        {
                printf("\n BEFORE: \n\n");
                print_grid(tab);
                printf("\nSOLUTION: \n\n");
        }
        else
                printf("\nERROR\n");


        print_grid(grid);
}
