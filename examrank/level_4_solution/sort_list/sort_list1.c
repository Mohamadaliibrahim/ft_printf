#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
    if (!lst)
        return 0;
    int c;
    t_list *head = lst;
    while(lst->next)
    {
        if (!(cmp(lst->data,lst->next->data)))
        {
            c = lst->data;
            lst->data = lst->next->data;
            lst->next->data = c;
            lst = head;
        }
        else
            lst = lst->next;
    }
    return head;
}