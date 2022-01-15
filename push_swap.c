/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 23:22:13 by izail             #+#    #+#             */
/*   Updated: 2022/01/10 23:22:15 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

char    *ft_strdup(const char *s1)
{
    char            *dst;
    unsigned int    len;
    unsigned int    i;

    len = 0;
    while (s1[len] != '\0')
        len++;
    dst = malloc(sizeof(char) * (len + 1));
    if (dst == NULL)
        return (NULL);
    i = 0;
    if (!s1)
        return (0);
    while (i != (len + 1))
    {
        dst[i] = s1[i];
        i++;
    }
    return (dst);
}

stack *push(stack **s, int data)
{
    stack *top;
    top = (stack *)malloc(sizeof(*top));
    if (!top)
    {
        printf("Stack overflow !");
        exit(1);
    }
    top->data = data;
    top->link = NULL;
    top->link = *s;
    *s = top;
    //free(top);
    return (*s);
}

stack *pop(stack **s)
{
    stack *tmp;
    tmp = *s;
    *s = (*s)->link;
    free(tmp);
    return (*s);
}

// void sorts(stack **start)
// {
//     stack   *tmp;
//     stack   *node;
//     int     tmpvar;

    
//     tmp = (stack *)malloc(sizeof(tmp));
//     node = (stack *)malloc(sizeof(node));
    
//     node = *start;
//     if (*start == NULL)
//     {
//         printf("sort is not possible\n");
//         exit(1);
//     }
//     while (node != NULL)
//     {
//         tmp = node;
//         while (tmp->link != NULL)
//         {
//             if (tmp->data > tmp->link->data)
//             {
//                 tmpvar = tmp->data;
//                 tmp->data = tmp->link->data;
//                 tmp->link->data = tmpvar;  
//             }
//             tmp = tmp->link;
//         }
//         node = node->link;
//     }
    
// }

stack    *ft_stacknew(int data)
{
    stack    *tmp;

    tmp = (stack *)malloc(sizeof(*tmp));
    if (!tmp)
        return (NULL);
    tmp->data = data;
    tmp->link = NULL;
    return (tmp);
}

void printStack(stack *s)
{
    //stack *s;
    //s = top;
    if (s == NULL)
    {
        printf("Stack is empty\n");
        exit(1);
    }
    printf("The stack elements are :");
    while (s)
    {
        printf("\n%d ", s->data);
        s = s->link;
    }
    printf("\n");
}

int main()
{

    stack *s1 , *s2, *s3;
    s1 = ft_stacknew(1);
    s2 = ft_stacknew(3);
   // s3 = ft_stacknew(2);
    push(&s2, 7);
    push(&s1, 8);
    push(&s1, 3);
    push(&s2, 2);
    //pop(&s1);
    //ft_ss(s1,s2);
    //ft_pa(&s1,&s2);
    //ft_pb(&s1,&s2);
    //ft_rotate(&s1);
    ft_ra(&s1);
    //ft_rr(&s1,&s2);
    printStack(s1);
    printStack(s2);
    return (0);

}