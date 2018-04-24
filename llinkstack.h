#pragma once
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

#define HEADER printf("\n===============%s================\n",__FUNCTION__);
typedef char linkstacktype;
typedef struct linkstack{
    linkstacktype data;
    struct linkstack *next;
}linkstack;
linkstack *head;
void linkstack_init(linkstack **head);
void linkstack_pushfront(linkstack **head,linkstacktype value);
void linkstack_popfront(linkstack **head);
int linkstack_getfront(linkstack **head,linkstacktype *value);
void linkstack_print(linkstack *head);
void linkstack_destroy(linkstack **head);
linkstack *linkstack_creat(linkstacktype value);
