<!--
 * @Author: leung
 * @Date: 2021-10-17 17:47:27
 * @LastEditTime: 2021-11-10 12:46:30
 * @LastEditors: leung
 * @Description: 
-->
# Data-Structure
《大话数据结构》学习笔记

## 01-线性表
**广义**
> 零个或多个数据元素的有限序列

**数学定义**
> 若将线性表记为(a[1], ···, a[i-1], a[i], a[i+1], ···, a[n]), 称a[i-1]是a[i]的直接前驱元素, a[i+1]是a[i]的直接后继元素。当i=1, 2, ···,n-1时, a[i]仅有一个直接后继, 当i=2, 3, ···,n时, 有且仅有一个直接前驱。数据元素之间的关系时一对一。

**线性表的抽象数据类型定义**
```
ADT 线性表(List)
Data
    线性表的数据对象集合为{a[1], a[2], ..., a[n]}, 每个元素的类型均为DataType.
Operation
    InitList(*L):  初始化操作, 建立一个空的线性表L.
    ListEmpty(L):  若线性表为空, 返回true, 否则返回false.
    ClearList(*L): 将线性表清空.
    GetElem(L, i, *e):  将线性表L中的第i个位置元素值返回给e.
    LocateElem(L, e):  在线性表L中查找与给定值e相等的元素, 如果查找成功, 返回该元素在表中序号表示成功;否则, 返回0表示失败.
    ListInsert(*L, i, e):  在线性表L中的第i个位置插入新元素e.
    ListDelete(*L, i, *e): 删除线性表L中第i个位置元素, 并用e返回其值.
    ListLength(L): 返回线性表L中的元素个数.
endADT

```
### 线性表的顺序存储结构

**定义**
> 线性表的顺序存储结构, 指的是用一段地址连续的存储单元依次存储线性表的数据元素

线性表的顺序存储示意图
![SeqList](https://img-blog.csdnimg.cn/20200712095506538.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTA0OTE4OA==,size_16,color_FFFFFF,t_70)

### 线性表的链式存储结构

**定义**
> 把存储数据元素信息的域称为数据域, 把存储直接后继位置的域称为指针域, 指针域中存储的信息称作指针或链。这两部分信息组成数据元素ai的存储映像, 称为结点Node
> 
> n个结点链结成一个链表, 即为线性表的链式存储结构, 因为此链表的每一个结点中只包含一个指针域, 所以叫做单链表。
> 
> 链表中第一个结点的存储位置叫做头指针

线性表的链式存储示意图
![LinkList](https://www.dynamic-zheng.com/images/2019/%E5%8D%95%E9%93%BE%E8%A1%A8.jpg)


### 静态链表
定义
> 让数组中的元素由两个数据域组成，data和cur。数组中的每个下标都对应一个data和一个cur。数据域data，用来存放数据元素；而cur相当于单链表中的next指针，存放该元素的后继在数组中的下标。cur也叫做游标。这种使用数组描述的链表叫做静态链表。
> 
> 对数组中的第一个和最后一个元素作为特殊元素处理，不存数据。通常把未被使用的数组元素称为备用链表，数组中的一个元素(下标为0)的元素的cur用来存放备用链表的第一个结点的下标。而数组的最后一个元素的cur则存放第一个有数值的元素的下标, 相当于单链表中头结点的作用。

静态链表示意图:

![StaticLinkList](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/f1a12fbd97ac4d15aac0b211e3b3a020~tplv-k3u1fbpfcp-watermark.image)