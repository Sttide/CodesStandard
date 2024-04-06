# Linux内核代码链表实现借鉴

### 链表实现线性表

```markdown
1.线性表表示数据之间存在线性关系。
2.链表表示这种线性关系的方式，C语言中使用指针，
3.链表的数据结构，每一个数据元素中包含两部分，一部分用于表示线性关系，一部分用于表示数据。
```

### 单链表实现

#### 数据结构定义

```c
/* 只需要当前节点可以指向后继节点即可 */
typedef struct listNode{
    struct listnode *pstNext;
}LIST_NODE_S;
/* 数据部分定义 */
typedef struct GreatWall{
    LIST_NODE_S stList;
    int data1;
    int data2;
    int data3;
}GREAT_WALL_NODE_S, GREAT_WALL_LIST_S;

/* 这样声明链表时，可以控制部分只控制逻辑关系的变换，数据部分用于数据
   最好创建链表时，声明一个链表头。这样访问链表时可以轻松找到链表。 */
GREAT_WALL_LIST_S g_pstGreatWallHead;
```

#### 数据结构解释

```markdown
LIST_NODE_S用于控制逻辑关系转换。
在数据里包含LIST_NODE_S结构体，每次逻辑转换时控制stList.pstNext的指向
访问数据时，通过stList使用offset和contain_of找到整个数据结构的地址，访问即可。
（offset和contain_of见附录）
```

#### 链表添加节点

```c
/* 链表的添加 */
/* 在某个特定位置添加 */
void ListAdd(GREAT_WALL_LIST_S *Plist, int i, int data)
{
    LIST_NODE_S *pTmp = NULL;
    GREAT_WALL_NODE_S *pstNode = NULL;
    int j = 0;
    pTmp = &(plist->stList);
    while((pTmp != NULL) && (j < i))
    {
        /* 逻辑控制部分 */
        pTmp = pTmp->pstNext;
        j++;
    }
    if ((pTmp == NULL) && (j < i))
    {
        return;
    }
    
    pstNode = (GREAT_WALL_NODE_S*)malloc(sizeof(GREAT_WALL_NODE_S));
    if (pstNode == NULL)
    {
        return;
    }
    pstNode->data1 =data;
    /* 逻辑控制部分 */
    pTmp->pstNext = &(pstNode->stlist);
    pstNode->stList.pstNext = NULL;
    return;
}

/* 尾插法 */
void TailAdd(GREAT_WALL_LIST_S *Plist, int data)
{
    LIST_NODE_S *pTmp = NULL;
    GREAT_WALL_NODE_S *pstNode = NULL;
    int j = 0;
    pTmp = &(plist->stList);
    while(pTmp != NULL)
    {
        /* 逻辑控制部分 */
        pTmp = pTmp->pstNext;
        j++;
    }
    pstNode = (GREAT_WALL_NODE_S*)malloc(sizeof(GREAT_WALL_NODE_S));
    if (pstNode == NULL)
    {
        return;
    }
    pstNode->data1 =data;
    /* 逻辑控制部分 */
    pTmp->pstNext = &(pstNode->stlist);
    pstNode->stList.pstNext = NULL;
    return;
}
```

#### 链表查询和输出

```c
void GetElement(GREAT_WALL_LIST_S *Plist, int i)
{
    LIST_NODE_S *pTmp = NULL;
    GREAT_WALL_NODE_S *pstNode = NULL;

    pstTmp = pList->stList.pstNext;
    while (pstTmp != NULL)
    {
        /* contain_of的使用非常方便 */
        pTmpNode = contain_of(pstTmp, TEST_DATA_NODE_S, stList);  
        printf("%d\r\n", pTmpNode->data1);
        /* 逻辑关系的转换，只需要控制LIST_NODE_S这个结构体即可 */
        pstTmp = pstTmp->pNext;
    }
    return;
}
```



### 附录

#### offset和contain_of原理

```markdown
知道了一个成员变量，想要知道包含这个成员变量的结构体的起始位置。
思路：
成员变量在结构体里的偏移是固定的。可以先算出偏移，再获取成员变量的地址，用成员变量的地址减去偏移，就得到结构体的起始位置。
起始地址 = 成员变量地址 - 成员变量在结构体里的偏移
```

#### 宏定义实现

```c
#define offset(type, member)    \
    ((size_t)(&(((type*)0)->member)))

#define contain_of(ptr, type, member)   \
    (type*)(ptr - (offset(type, member)))
```

#### 代码详解

```markdown
怎么计算偏移offset
1.使用sizeof
已知结构体，把该成员变量前面声明的数据都计算一遍sizeof就知道了。（不具有普遍性）
2.借用已经运行的代码里的数据来求解。
数学思想，假设已经有一个在内存中被申请出来的结构体了，那么我们很清楚的就可以得到每个成员变量的地址，用成员变量地址减去起始地址可以得到偏移。
程序运行时，(type\*)0 ; 表示将0地址转成一个tpye 类型的指针， 这个时候，用这个指针访问他的成员变量member，（type\*）0->member,对这个成员变量计算地址，&(（type\*)0->member),用成员变量的地址减去起始地址0，得到偏移。

contain_of
包含成员变量的结构体的地址 = 指针（成员变量实际地址）-偏移
```
