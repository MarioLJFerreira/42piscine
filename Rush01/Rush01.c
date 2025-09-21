/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:36:53 by dansimoe          #+#    #+#             */
/*   Updated: 2025/09/21 01:05:41 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char    **alloc_matrix(int rows, int columns)
{
	int i;
	
	i = 0;
	char	**matrix = malloc(rows *sizeof(char *) + 1);
	if (!matrix)
		return(NULL);
	while (i < rows)
	{
	matrix[i] = malloc(columns * sizeof(char) + 1);
	i++;
	}
	matrix[i] = NULL;
	return matrix;
}

void    free_matrix(char **matrix, int rows)
{
    int i;
    i = 0;
    while(i < rows)
    {
        free(matrix[i]);
        i++;
    }
    free(matrix);
}

char    **grid_checks_helper(char **grid)
{
    grid[10] = "224132";
    grid[11] = "224313";
    grid[12] = "231241";
    grid[13] = "231422";
    grid[14] = "232141";
    grid[15] = "232412";
    grid[16] = "234122";
    grid[17] = "234213";
    grid[18] = "141232";
    grid[19] = "141323";
    grid[20] = "142132";
    grid[21] = "142313";
    grid[22] = "143123";
    grid[23] = "143214";
    grid[24] = NULL;
    return(grid);
}
char    **grid_checks(char **grid)
{
    grid = alloc_matrix(24, 6);
    grid[0] = "412341";
    grid[1] = "312432";
    grid[2] = "313241";
    grid[3] = "313422";
    grid[4] = "214232";
    grid[5] = "214323";
    grid[6] = "321341";
    grid[7] = "221432";
    grid[8] = "323141";
    grid[9] = "323412";
    grid = grid_checks_helper(grid);
    return(grid);
}

void	pre_start(char **Matrix, int row_s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < row_s)
	{
		j = 0;
		while (j < row_s)
		{
			Matrix[i][j] = '0';
			j++;
		}
	i++;
	}
}

void	start3(char **Matrix, int row_s)
{
	int	i[2];

	i[0] = 0;
	i[1] = 0;
	while (i[0] < row_s - 1)
	{
		if (Matrix[0][i[0]] == '4')
		{
			i[1] = 1;
			while (i[1] < row_s - 1)
			{
				Matrix[i[1]][i[0]] = i[1] + '0';
				i[1]++;
			}
		}
		if (Matrix[row_s - 1][i[0]] == '4')
		{
			i[1] = 1;
			while (i[1] < row_s - 1)
			{
				Matrix[row_s - 1 - i[1]][i[0]] = i[1] + '0';
				i[1]++;
			}
		}
	i[0]++;
	}
}

void	start2(char ** Matrix, int row_s)
{
	int	i[2];

	i[0] = 0;
	i[1] = 0;
	while (i[0] < row_s - 1)
	{
		if (Matrix[i[0]][0] == '4')
		{
			i[1] = 1;
			while (i[1] < row_s - 1)
			{
				Matrix[i[0]][i[1]] = i[1] + '0';
				i[1]++;
			}
		}
		if (Matrix[i[0]][row_s - 1] == '4')
		{
			i[1] = 1;
			while (i[1] < row_s - 1)
			{
				Matrix[i[0]][row_s - 1 - i[1]] = i[1] + '0';
				i[1]++;
			}
		}
	i[0]++;
	}
}

void	start1(char **Matrix, int row_s)
{
	int	i;

	i = 1;
	while (i < row_s - 1)
	{
		if (Matrix[0][i] == '1')
			Matrix[1][i] = '4';
		if (Matrix[row_s - 1][i] == '1')
			Matrix[row_s - 2][i] = '4';
		if (Matrix[i][0] == '1')
			Matrix[i][1] = '4';
		if (Matrix[i][row_s - 1] == '1')
			Matrix[i][row_s - 2] = '4';
	i++;
	}
}

void	start(char **Matrix, int row_s)
{
	start1(Matrix, row_s);
	start2(Matrix, row_s);
	start3(Matrix, row_s);
}

void	inicial(char *argv, char **Param, int row_s)
{
	int	j;
	int	t;

	t = 0;
	j = 0;	
	while (++j < row_s - 1)
		Param[0][j] = argv[t++];
	j = 0;
	while (++j < row_s - 1)
		Param[row_s - 1][j] = argv[t++];
	j = 0;
	while (++j < row_s - 1)
		Param[j][0] = argv[t++];
	j = 0;
	while (++j < row_s - 1)
		Param[j][row_s - 1] = argv[t++];
}

void	write_Matrix(char **M, int row_s)
{
	int	j = 1;
	int	i = 1;
	while ( i < row_s - 1)
	{
		j = 1;
		write(1, &M[i][j], 1);
		while ( ++j < row_s - 1)
		{
			write(1, " ", 1);
			write(1, &M[i][j], 1);
		}
		write(1, "\n", 1);
		i++;
	}
}

void	spaces(char *argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		argv[j] = argv[i];
		j++;
		i += 2;
	}
	argv[j] = '\0';
}

int	calculatefurther(char **Matrix, int x, int y, int row_s)
{
	char	**Mcomb;
	char	**Mtestcol;
	char	**Mtestrow;
	int	i[4];

	Mcomb = grid_checks(Mcomb);
	Mtestcol = alloc_matrix(24, 6);
	Mtestrow = alloc_matrix(24, 6);

	i[0] = 0;
	i[1] = 0;
	while (Mcomb[i[0]])
	{
		if (Matrix[0][y] == Mcomb[i[0]][0] && Matrix[row_s - 1][y] == Mcomb[i[0]][5])
		{
			i[2] = 1;
			i[3] = 1;
			while (i[2] < row_s)
			{
				if (Matrix[i[2]][y] == '0' || Matrix[i[2]][y] == Mcomb[i[0]][i[2]])
					i[3]++;	
				i[2]++;
			}
			if (i[3] == row_s)
			{
				Mtestcol[i[1]] = Mcomb[i[0]];
				i[1]++;
			}
		}
		i[0]++;
	}
	if (i[1] == 1)
	{
		i[1] = 1;
		while (i[1] < row_s - 1)
		{
			Matrix[i[1]][y] = Mtestcol[0][i[1]];
			i[1]++;
		}
	}
	
	i[0] = 0;
	i[1] = 0;
	while (Mcomb[i[0]])
	{
		if (Matrix[x][0] == Mcomb[i[0]][0] && Matrix[x][row_s - 1] == Mcomb[i[0]][5])
		{
			i[2] = 1;
			i[3] = 1;
			while (i[2] < row_s)
			{
				if (Matrix[x][i[2]] == '0' || Matrix[x][i[2]] == Mcomb[i[0]][i[2]])
					i[3]++;	
				i[2]++;
			}
			if (i[3] == row_s)
			{
				Mtestrow[i[1]] = Mcomb[i[0]];
				i[1]++;
			}
		}
		i[0]++;
	}
	if (i[1] == 1)
	{
		i[1] = 1;
		while (i[1] < row_s - 1)
		{
			Matrix[x][i[1]] = Mtestrow[0][i[1]];
			i[1]++;
		}
	}
	return(i[1]);

	i[0] = 0;
	i[1] = 0;
	while (i[0] < row_s)
	{
		while (i[1] < row_s)
		{
			if  (Mtestrow[i[0]][y] == Mtestcol[i[1]][x])
				i[3]++;	
		}
		if (i[3] == row_s)
		{
			i
			while (
			Mtestrow[i[1]] = Mcomb[i[0]];
			i[1]++;
		}

	if (i[1] == 1)
	{
		i[1] = 1;
		while (i[1] < row_s - 1)
		{
			Matrix[x][i[1]] = Mtestrow[0][i[1]];
			i[1]++;
		}
	}
	return(i[1]);



}

void	calculate(char **Matrix, int row_s)
{
	int 	i[3];
	char	a;

	i[0] = 1;
	while (i[0] < row_s - 1)
	{
		i[1] = 1;
		while (i[1] < row_s - 1)
		{
			if (Matrix[i[0]][i[1]] == '0')
			{
				i[2] = calculatefurther(Matrix, i[0], i[1], row_s);
				a = i[2] + '0';
			}
			i[1]++;
		}
		i[0]++;
	}
}

int	main(int argc, char **argv)
{
	char	**M;
	int	row_s;
	int	t;

	t = 0;
	row_s = 6;
	
	if (argc == 2)
	{
		M = alloc_matrix(row_s, row_s);
		spaces(argv[1]);
		pre_start(M, row_s);
		inicial(argv[1], M, row_s);
		start(M, row_s);
		calculate(M,row_s);
		write_Matrix(M, row_s);
	}
	return (0);

}
