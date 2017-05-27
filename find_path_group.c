/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:42:20 by abykov            #+#    #+#             */
/*   Updated: 2017/04/24 14:42:21 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void     compare_group(t_paths **res, t_paths **temp)
{
    
}

static int      has_dup_in_path(t_rlist *a, t_rlist *b)
{
    t_rlist     *curr;
    
    while (a->next)
    {
        curr = b;
        while (curr->next)
        {
            if (a->index == curr->index)
                return (1);
            curr = curr->next;
        }
        a = a->next;
    }
    return (0);
}

static int      has_dup_in_group(t_paths *group, t_paths *path)
{
    t_paths     *curr;
    
    while (group)
    {
        if (has_dup_in_path(group->head->next, path->head->next))
            return (1);
        group = group->next;
    }
    return (0);
}

static void     find_group_at(t_paths **dst, t_paths *src, int i)
{
    t_paths     *add;
    int         j;
    
    printf ("group #[%d]:\n", i);
    j = i;
    while (src)
    {
        if (!has_dup_in_group(*dst, src))
        {
            printf ("Added path #[%d]\n", j);
            add = (t_paths *)malloc(sizeof(t_paths));
            add->len = src->len;
            add->head = src->head;
            add->next = *dst;
            *dst = add;
        }
        src = src->next;
        j++;
    }
    printf ("===============\n\n");
}

void            find_path_group(t_data *data)
{
    t_paths     *res;
    t_paths     *temp;
    t_paths     *curr;
    int         i;
    
    i = 0;
    res = NULL;
    temp = NULL;
    find_group_at(&res, data->paths, i++);
    printf("INIT CREATED\n");
    curr = data->paths->next;
    while (curr)
    {
        find_group_at(&temp, curr, i++);
        compare_group(&res, &temp);
        temp = NULL;
        curr = curr->next;
    }
    
}
