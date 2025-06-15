#include "philo.h"

int ft_check_number(char *str)
{
        int     i;

        i = 0;
        if(!str[i])
                return(0);
        while(str[i])
        {
                if((str[i]) < '0' && str[i] > '9')
                        return(0);
                i++;
        }
        return(1);
}
int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long int	result;

	i = 0;
	result = 0;
        if (str[i] == '\0')
                return(-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
        if (result > 2147483647)
                return(-1);
        if (str[i] != '\0')
                return(-1);
	return ((int)result);
}
// int count_arg(char *str)
// {
//         char **number_arg;
//         int     i;

//         if(!str)
//                 return(0);
//         number_arg = ft_split(str, ' ');
//         while(number_arg)
//         {
//                 i++;
//         }
//         return(i);
// }

int    parse_args(int argc, char **argv)
{
        int     i;
        int     value;

        
        i = 1;
        if (argc != 5 && argc != 6)
                error_exit("Error: wrong number of arguments");
        while(i < argc)
        {
                if(!ft_check_number(argv[i]))
                        error_exit("Error: invalid input, only positive numbers allowed.");
                value = ft_atoi(argv[i]);5tr
                if(i == 1 && (value <= 0 || value > 200))
                        error_exit("Input invalid: the number of philosophers must be between 1 and 200");
                if (i != 1 && value == -1)
                        error_exit("Input invalid: the argument must be between 0 and 2147483647");
                i++;
        }
        return(0);
}