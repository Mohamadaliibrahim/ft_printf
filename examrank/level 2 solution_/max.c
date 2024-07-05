int max(int *tab, unsigned int len)
{
    int i = 0;
    int c = tab[i];
    if (!tab)
        return 0;
    while (i < len)
    {
        if (c < tab[i])
            c = tab[i];
        i++;
    }
    return c;
}