#include"llinkstack.h"

linkstack* linkstack_creat(linkstacktype value)
{
    linkstack *newnode = (linkstack *)malloc(sizeof(linkstack));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}
void linkstack_init(linkstack **head)
{
    if(head == NULL)
    {
        return;//非法输入
    }
    *head = NULL;
    return;
}
//int linkstack_lenth(linkstack *head)
//{
//    if(head == NULL)
//    {
//        return 0;
//    }
//    else
//    {
//        int len = 0;
//        while(head != NULL)
//        {
//            printf("haha\n");
//            len++;
//            head = head->next;
//
//        }
//        return len;
//    }
//
//}
void linkstack_pushfront(linkstack **head,linkstacktype value)//链表入栈
{
    if(head == NULL)
    {
        return;
    }
    //linkstack *tmp = *head;
    //(*head) = linkstack_creat(value);
    //(*head)->next = tmp;
    linkstack *new = linkstack_creat(value);
    new->next = *head;
    *head = new;
    //linkstack *tmp = *head;
    //*head = linkstack_creat(value);
    //(*head)->next = tmp;
    return;
    

}
void linkstack_pop(linkstack **head)
{
    if(head == NULL)
    {
        return;
    }
    if(*head == NULL)
    {
        return;
    }
    linkstack *cur = *head;

    *head = cur->next;
    free(cur);
    cur = NULL;
    return;
}
int  linkstack_gettop(linkstack *head,linkstacktype *value)
{
    if(head == NULL)
    {
        return 0;
    }
    *value = head->data;
    return 1;
}

//void linkstack_destory(linkstack **head)
//{
//    if(head == NULL)
//    {
//        return;
//    }
//    if(*head == NULL)
//    {
//        return;
//    }
//    linkstack *cur = *head;
//    while(cur)
//    {
//        linkstack *to_delete = cur;
//        cur = cur->next;
//        free(to_delete);
//        to_delete = NULL;
//
//    }
//    return;
//}



///////////////////////////
//测试函数
///////////////////////////

//void linkstack_print(linkstack*head)
//{
//    if(head == NULL)
//    {
//        return;
//    }
//    linkstack *cur = head;
//    while(cur)
//    {
//        printf("[%c|%p] ",cur->data,cur);
//        cur = cur->next;
//    }
//
//
//}
void linkstack_print(linkstack *head)
{
    if(head == NULL)
    {
        return;
    }
    else
    {
        linkstack *std = head;
        while(std != NULL)
        {
            printf("[%c] ",std->data);
            std = std->next;
        }
        printf("\n");
    }
}
void test_linkstack_pushfront()
{
    HEADER;
    linkstack *head;
    linkstack_init(&head);
    linkstack_pushfront(&head,'a');
    linkstack_pushfront(&head,'b');
    linkstack_pushfront(&head,'c');
    linkstack_pushfront(&head,'d');
    linkstack_print(head);
    //linkstack_lenth(head);
}
void testpop()
{
    HEADER;
    linkstack *head;
    linkstack_init(&head);
    linkstack_pushfront(&head,'a');
    linkstack_pushfront(&head,'b');
    linkstack_pushfront(&head,'c');
    linkstack_pushfront(&head,'d');
    linkstack_print(head);
    printf("出栈一个节点\n");
    linkstack_pop(&head);
    linkstack_print(head);
    printf("出栈一个节点\n");
    linkstack_pop(&head);
    linkstack_print(head);
    printf("出栈一个节点\n");
    linkstack_pop(&head);
    linkstack_print(head);
    printf("出栈一个节点\n");
    linkstack_pop(&head);
    linkstack_print(head);

}
void testgettop()
{
    HEADER;
    linkstack *head;
    linkstack_init(&head);
    linkstack_pushfront(&head,'a');
    linkstack_pushfront(&head,'b');
    linkstack_pushfront(&head,'c');
    linkstack_pushfront(&head,'d');
    linkstack_print(head);
    linkstacktype value;
    int ret = linkstack_gettop(head,&value);
    printf("expected is 1 ,actul is %d\n",ret);
    printf("expected is d ,actul is %c\n",value);
}


int main()
{
    test_linkstack_pushfront();
    testpop();
    testgettop();
    return 0;
}









