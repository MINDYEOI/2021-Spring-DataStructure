#pragma once
#include <iostream>
#include "DoublyNodeType.h"
#include "DoublySortedLinkedList.h"


template <typename T>
class DoublyIterator
{

private:
	const DoublySortedLinkedList<T>& m_List;
	DoublyNodeType<T>* m_pCurPointer;

public:

	friend class DoublySortedLinkedList<T>;

	//constructor
	DoublyIterator(const DoublySortedLinkedList<T>& list)
		: m_List(list), m_pCurPointer(list.m_pFirst) {};


	void Begin()
	{
		m_pCurPointer = m_List.m_pFirst->next;
	}


	void Next()
	{
		m_pCurPointer = m_pCurPointer->next;
	}


	T* GetCurrentNode()
	{
		return &m_pCurPointer->data;
	}

	bool NotEnd()
	{
		if (m_pCurPointer->next == NULL)
			return false;
		else
			return true;
	}

};