//
// Created by mindyeoi on 2021/04/03.
//

#ifndef LAB04_SORTEDLINKEDLIST_H
#define LAB04_SORTEDLINKEDLIST_H

#pragma once
#include <iostream>
#include "NodeType.h"
#include "ItemType.h"
using namespace std;

template <typename T>
class SortedLinkedList
{
private:
    NodeType<T>* m_pList;			// ����Ʈ ������. ù ��带 ����Ŵ.
    NodeType<T>* m_pCurPointer;		// current pointer.
    int m_nLength;					// ����Ʈ�� ����� ���ڵ� ��.

public:
    SortedLinkedList();	// default constructor

    ~SortedLinkedList();	// destructor

    /**
    * @brief	Make the list empty.
    * @pre		The list is allocated.
    * @post		The list is empty.
    */
    void MakeEmpty();

    /**
    * @breif	Return the item number in the list.
    * @pre		none.
    * @post		none.
    * @return	the item number in the list.
    */
    int GetLength()	const;

    /**
    * @brief	Add the item in the list.
    * @pre		The list doesn't have the item. (The list can't be 'full' because it is linked list!)
    * @post		The item is added.
    * @param	The item which is added in the list.
    * @return	If this function works well, return true, otherwise return false.
    */
    bool Add(T item);

    /**
    * @brief	Delete the item in the list.
    * @pre		The list is not empty and have the item.
    * @post		The item is deleted.
    * @param	The item which is deleted in the list.
    * @return	If this function works well, return true, otherwise return false.
    */
    bool Delete(T item);


    /**
    *	@brief	Retrieve list element whose key matches item's key (if present).
    *	@pre	Key member of item is initialized.
    *	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
    *   @param	The item which want to retrieve in the list.
    *	@return	1 if any element's primary key matches with item's, otherwise 0.
    */
    bool Retrieve(T& item);

    /**
    * @brief	Replace the item in the list.
    * @pre		The list has the item.
    * @post		The item information is changed.
    * @param	The item which information will be changed.
    * @return	If this function works well, return true, otherwise return false.
    */
    bool Replace(T& item);

    /**
    * @brief	Reset the current Pointer. (ResetList)
    * @pre		The current pointer.
    * @post		The current pointer is initialized.
    */
    void ResetCurPointer();

    /**
    * @brief	Make the current pointer points to next node and get the next node.
    * @pre		current pointer is defined. Element at current pointer is not last in list.
    * @post		current pointer is updated to next position. item is a copy of element at current pointer.
    */
    bool GetNextItem(T& item);

};

template <typename T>
SortedLinkedList<T>::SortedLinkedList()	// default constructor
{
    m_pList = NULL;
    m_pCurPointer = NULL;
    m_nLength = 0;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()	// default constructor
{
    MakeEmpty();
}

template <typename T>
void SortedLinkedList<T>::MakeEmpty()
{
    NodeType<T>* tempPtr;
    while (m_pList != NULL) {	// m_pList �� list�� ù ��带 ����Ű�µ�
        // m_pList�� NULL �̸� ù ��尡 ���ٴ� �Ŵϱ� �� ��!
        tempPtr = m_pList;
        m_pList = m_pList->next;
        delete tempPtr;
    }
    m_nLength = 0;
}

template <typename T>
int SortedLinkedList<T>::GetLength() const
{
    return m_nLength;
}

template <typename T>
bool SortedLinkedList<T>::Add(T item)
{
    bool bMoreToSearch = true;
    NodeType<T>* curNode = m_pList;
    NodeType<T>* prevNode = m_pList;
    NodeType<T>* itemNode;

    itemNode = new NodeType<T>;
    itemNode->info = item;


    if (m_pList == NULL)
    {
        m_pList = itemNode;
        m_pList->next = NULL;
        m_nLength++;
    }

    else
    {
        while (bMoreToSearch)
        {
            // 1. item > curNode->info �̸� ��� ã��
            if (item > curNode->info)
            {
                prevNode = curNode;
                curNode = curNode->next;
                bMoreToSearch = (curNode != NULL);
            }

                // 2. item < curNode->info �̸� �׸� ã�� �� �ڸ��� �־�� ��!
            else if (item < curNode->info)
            {
                bMoreToSearch = false;
            }

                // 3. item == curNode->info �̸� �̹� �ִ� item �̹Ƿ� ����x
            else
            {
                bMoreToSearch = false;
                cout << "[!] This item already exist.\n";
                return false;
            }
        }

        // ���� �ڸ� ã�ٰ� �� ���� ����
        if (curNode == NULL)
        {
            prevNode->next = itemNode;
            itemNode->next = NULL;
            m_nLength++;
        }

            // prevNode == curNode �̸�, �� ���� ���� �ڸ���� ��
        else if (prevNode == curNode)
        {
            NodeType<T>* temp;
            temp = m_pList;
            m_pList = itemNode;
            m_pList->next = temp;
            m_nLength++;

            //itemNode->next = m_pList;
            //m_pList = itemNode;		// �� ó���� itemNode�� ����!!
            //						// �� �� m_pList���� �̷��� �ص� �������� ����. ������ itemNode->next�� �����س����ϱ�!!
            //m_nLength++;
        }

            // �߰��� �־���Ѵٸ�
        else
        {
            prevNode->next = itemNode;
            itemNode->next = curNode;
            m_nLength++;
        }
    }
}

template <typename T>
bool SortedLinkedList<T>::Delete(T item)
{
    NodeType<T>* curNode = m_pList;
    NodeType<T>* prevNode = m_pList;
    NodeType<T>* itemNode;
    itemNode = new NodeType<T>;
    itemNode->info = item;
    itemNode->next = NULL;

    // ���� ����Ʈ�� ����ٸ�
    if (m_pList == NULL)
    {
        cout << "[!] The list is empty.\n";
        return false;
    }

    else
    {
        bool bMoreToSearch = true;
        while (bMoreToSearch)
        {
            // 1. ���� item == curNode->info �̸�
            if (item == curNode->info)
            {
                bMoreToSearch = false;
                prevNode->next = curNode->next; // ���� ����� ������ ���� ����� ������ ����Ű�� �ϰ�
                delete curNode;	// ���� ��带 ������
                m_nLength--;
                return true;
            }

                //2. ���� item�� ���� ��庸�� �� �۴ٸ� ���� ã�ƺ��� �ϴϱ�
            else
            {
                prevNode = curNode;
                curNode = curNode->next;
                if (curNode == NULL)	// ���� ���� ��尡 NULL �̸�, �� ���̶�� �Ŵϱ�
                {
                    cout << "[!] There is no data to delete.\n";
                    return false;
                }
            }
        }
        if (bMoreToSearch == false)
        {
            cout << "[!] Fail to delete\n";
            return false;
        }
    }
}

template <typename T>
bool SortedLinkedList<T>::Retrieve(T& item)
{
    NodeType<T>* curNode = m_pList;
    NodeType<T>* itemNode;
    itemNode = new NodeType<T>;
    itemNode->info = item;
    itemNode->next = NULL;

    // ���� ����Ʈ�� ����ٸ�
    if (m_pList == NULL)
    {
        cout << "[!] The list is empty.\n";
        return false;
    }

    else
    {
        bool bMoreToSearch = true;
        while (bMoreToSearch)
        {
            // 1. ���� item == curNode->info �̸�
            if (item == curNode->info)
            {
                bMoreToSearch = false;
                item = curNode->info;
                return true;
            }


                // 2. ���� item�� ���� ��庸�� �� �۴ٸ� ���� ã�ƺ��� �ϴϱ�
            else
            {
                curNode = curNode->next;
                if (curNode == NULL)	// ���� ���� ��尡 NULL �̸�, �� ���̶�� �Ŵϱ�
                {
                    cout << "curNode is at the end of the list \n[!] There is no data to retrieve.\n";
                    return false;
                }
            }
        }
        if (bMoreToSearch == false)
        {
            cout << "[!] Fail to Retrieve. \n";
            return false;
        }
    }
}

template <typename T>
bool SortedLinkedList<T>::Replace(T& item)
{
    NodeType<T>* curNode = m_pList;
    NodeType<T>* itemNode;
    itemNode = new NodeType<T>;
    itemNode->info = item;
    itemNode->next = NULL;

    // ���� ����Ʈ�� ����ٸ�
    if (m_pList == NULL)
    {
        cout << "[!] The list is empty.\n";
        return false;
    }

    else
    {
        bool bMoreToSearch = true;
        while (bMoreToSearch)
        {
            // 1. ���� item == curNode->info �̸�
            if (item == curNode->info)
            {
                bMoreToSearch = false;
                curNode->info = item;
                return true;
            }

                // 3. ���� item�� ���� ��庸�� �� �۴ٸ� ���� ã�ƺ��� �ϴϱ�
            else
            {
                curNode = curNode->next;
                if (curNode == NULL)	// ���� ���� ��尡 NULL �̸�, �� ���̶�� �Ŵϱ�
                {
                    cout << "[!] There is no data to replace.\n";
                    return false;
                }
            }
        }
        if (bMoreToSearch == false)
        {
            cout << "[!] Fail to Replace. \n";
            return false;
        }
    }
}

template <typename T>
void SortedLinkedList<T>::ResetCurPointer()
{
    m_pCurPointer = NULL;
}

template <typename T>
bool SortedLinkedList<T>::GetNextItem(T& item)
{
    if (m_pList == NULL)
    {
        cout << "[!] The list is empty.\n";
        return false;
    }

    // ���� curPointer == NULL�̶��, ������ ����
    if (m_pCurPointer == NULL)
    {
        m_pCurPointer = m_pList;
        item = m_pCurPointer->info;
    }

    else
    {
        m_pCurPointer = m_pCurPointer->next;

        if (m_pCurPointer == NULL) // �� �ڸ� �Ѿ�ٸ�
        {
            return false;
        }
        else
        {
            // item�� CurPointer->info �־���
            item = m_pCurPointer->info;
            return true;
        }
    }
}

#endif //LAB04_SORTEDLINKEDLIST_H
