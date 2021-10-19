<!--
 * @Author: leung
 * @Date: 2021-10-17 17:47:27
 * @LastEditTime: 2021-10-19 13:55:04
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
    LocalElem(L, e):  在线性表L中查找与给定值e相等的元素, 如果查找成功, 返回该元素在表中序号表示成功;否则, 返回0表示失败.
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