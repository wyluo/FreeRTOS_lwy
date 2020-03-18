#include "list.h"

void vListInitialiseItem( ListItem_t * const pxItem )
{
    pxItem->pvContainer = NULL;
}


/* 链表根节点初始化 */
void vListInitialise( List_t * const pxList )
{
    /* 将链表索引指针指向最后一个节点 */ 
    pxList->pxIndex = ( ListItem_t * ) & ( pxList->xListEnd );

	/* 将链表最后一个节点的辅助排序的值设置为最大，确保该节点就是链表的最后节点 */
	pxList->xListEnd.xItemValue = portMAX_DELAY;

	/* 将最后一个节点的pxNext 和 pxPrevious 指针均指向节点自身，表示链表为空 */
	pxList->xListEnd.pxNext = ( ListItem_t * ) & ( pxList->xListEnd );
	pxList->xListEnd.pxPrevious = ( ListItem_t * ) & ( pxList->xListEnd );

	/* 初始化链表节点计数器的值为0，表示链表为空 */
	pxList->uxNumberOfItems = (UBaseType_t) 0U;
}
