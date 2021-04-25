#pragma once
#include <iostream>
#include "DoublyNodeType.h"
#include "DoublyIterator.h"
#include "ItemType.h"

template <typename T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>;

private:
	DoublyNodeType<T>* m_pFirst;	// pointer - first node
	DoublyNodeType<T>* m_pLast;		// pointer - last node
	int m_nLength;	// record number in the list

public:
	DoublySortedLinkedList()
	{
		// header과 trailer 역할을 할 2개의 dummy node 생성
		m_pFirst = new DoublyNodeType<T>;
		m_pLast = new DoublyNodeType<T>;

		// 두 노드가 서로를 가리키도록 연결
		m_pFirst->next = m_pLast;
		m_pLast->prev = m_pFirst;

		// 앞과 뒤는 null로 초기화
		m_pLast->next = NULL;
		m_pFirst->prev = NULL;

		// 길이는 0
		m_nLength = 0;
	}

	~DoublySortedLinkedList() {}

	/**
* @brief   Check this list is full or not.
* @pre     none.
* @post    none.
* @return  if the iist is full, return true, otherwise return false.
*/
//	bool IsFull();			// Check list is full


	/**
	* @brief	Make the list empty.
	* @pre		The list is allocated.
	* @post		The list is empty.
	*/
	void MakeEmpty() // Make list empty
	{
		DoublyIterator<T> itor(*this);
		DoublyNodeType<T> temp;

		while (itor.NotEnd())
		{
			temp = itor.m_pCurPointer;
			itor.Next();
			delete temp;
		}
		m_nLength = 0;
	}

	/**
* @breif	Return the item number in the list.
* @pre		none.
* @post		none.
* @return	the item number in the list.
*/
	int GetLength() const	// return the item number in the list
	{
		return m_nLength;
	}

	/**
	* @brief	Add the item in the list.
	* @pre		The list doesn't have the item. (The list can't be 'full' because it is linked list!)
	* @post		The item is added.
	* @param	The item which is added in the list.
	* @return	If this function works well, return true, otherwise return false.
	*/
	bool Add(T item)		// Add the new record
	{
		DoublyIterator<T> itor(*this);
		itor.Begin();
		for (itor.Begin(); itor.NotEnd(); itor.Next())
		{
			if (item < itor.m_pCurPointer->data) // item보다 itor가 크면 itor 앞에 추가
			{
				break;
			}

			else if (item == itor.m_pCurPointer->data)	// 동일하면
			{
				cout << "\t [!] This item already exist.\n";
				return false;
			}

			itor.Next();
		}

		// item < itor.m_pCurPointer->data 또는 m_pCurPointer == m_pLast 로 끝났을 때
		DoublyNodeType<T>* pItem = new DoublyNodeType<T>;
		// pItem 넣어주기
		pItem->data = item;
		pItem->prev = itor.m_pCurPointer->prev;
		pItem->next = itor.m_pCurPointer;
		itor.m_pCurPointer->prev->next = pItem;
		itor.m_pCurPointer->prev = pItem;
		m_nLength++;
		return true;
	}

	/**
	* @brief	Delete the item in the list.
	* @pre		The list is not empty and have the item.
	* @post		The item is deleted.
	* @param	The item which is deleted in the list.
	* @return	If this function works well, return true, otherwise return false.
	*/
	void Delete(T item)	// Delte the record
	{
		DoublyIterator<T> itor(*this);
		itor.Begin();
		for (itor.Begin(); itor.NotEnd(); itor.Next())
		{

			if (item == itor.m_pCurPointer->data)	// 동일하면
			{
				itor.m_pCurPointer->prev->next = itor.m_pCurPointer->next;
				itor.m_pCurPointer->next->prev = itor.m_pCurPointer->prev;
				m_nLength--;
				return true;
			}

			itor.Next();
		}

		cout << "\t [!] There is no data to delete.\n";
		return false;

	}


	/**
	* @brief	Replace the item in the list.
	* @pre		The list has the item.
	* @post		The item information is changed.
	* @param	The item which information will be changed.
	* @return	If this function works well, return true, otherwise return false.
	*/
	bool Replace(T item)	// Replace the record
	{
		DoublyIterator<T> itor(*this);
		if (m_nLength == 0)
		{
			cout << "\t [!] The list is empty.\n";
			return false;
		}

		for (itor.Begin(); itor.NotEnd(); itor.Next())
		{
			if (*itor.GetCurrentNode() == item)
			{
				*itor.GetCurrentNode() = item;
				return true;
			}
		}
		cout << "\t [!] There is no data to replace.\n";
		return false;
	}

	/**
	*	@brief	Retrieve list element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	*   @param	The item which want to retrieve in the list.
	*	@return	1 if any element's primary key matches with item's, otherwise 0.
	*/
	bool Get(T& item)		// Search the item with primary key and get the item's data.
	{

		DoublyIterator<T> itor(*this);


		for (itor.Begin(); itor.NotEnd(); itor.Next())
		{
			if (*itor.GetCurrentNode() == item)
			{
				item = *itor.GetCurrentNode();
				return true;
			}
		}
		return false;
	}

	/**
* @brief   Check this list is empty or not.
* @pre     none.
* @post    none.
* @return  if the iist is empty, return true, otherwise return false.
*/
	bool IsEmpty()
	{
		if (m_nLength == 0)
			return true;
		else
			return false;
	}


	/**
	* @brief	Make the current pointer points to next node and get the next node.
	* @pre		current pointer is defined. Element at current pointer is not last in list.
	* @post		current pointer is updated to next position. item is a copy of element at current pointer.
	*/
	int GetNextItem(T& item)
	{
		DoublyIterator<T> itor(*this);
		itor.Next();

		if (itor.NotEnd())
		{
			item = itor.m_pCurPointer->data;
			return true;
		}

		else
		{
			return -1;
		}
	}
};
