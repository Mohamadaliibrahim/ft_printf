int	ft_atoi(const char *str)
{
    int i = 0;
    int r = 0;
    int s = 1;
    while (str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
        i++;
    if (str[i] == '-')
        s = -1;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        r = r * 10 + str[i] - '0';
        i++;
    }
    return r;
}