<!--
 * @Author: leung
 * @Date: 2021-10-17 17:47:27
 * @LastEditTime: 2021-10-18 13:25:53
 * @LastEditors: leung
 * @Description: 
-->
# Data-Structure
Data-Structure Study Notes

## 01-线性表
**广义**
> 零个或多个数据元素的有限序列

**数学定义**
> 若将线性表记为$(a_{1}, ···, a_{i-1}, a_{i}, a_{i+1}, ···, a_{n} $), 称$a_{i-1}$是$a_{i}$的直接前驱元素, $a_{i+1}$是$a_{i}$的直接后继元素。当$i=1, 2, ···,n-1$时, $a_{i}$仅有一个直接后继, 当$i=2, 3, ···,n$时, 有且仅有一个直接前驱。数据元素之间的关系时一对一。

>线性表元素的个数$n(n\geq0)$定义为线性表的长度, 当$n=0$时, 称为空表

**线性表的抽象数据类型定义**:
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
