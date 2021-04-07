//
// Created by mindyeoi on 2021/03/29.
//

#include "SortedList.h"


/*
	*	@brief	make the list empty.
	*	@pre	none.
	*	@post	the list is empty.
	*/
void SortedList::MakeEmpty()
{
    m_CurPointer = -1;
    m_Length = 0;
}

/*
*	@brief	Return the number of the records in current list.
*	@pre	none.
*	@post	none.
*	@return the number of records in current list.
*/
int SortedList::GetLength()
{
    return m_Length;
}

/*
*	@brief	Check the array is full.
*	@pre	none.
*	@post	none.
*	@return if the array capacity is filled, return true, otherwise return false.
*/
bool SortedList::IsFull()
{
    if (m_Length >= MAXSIZE)
        return true;
    else
        return false;
}

/*
*	@brief	Check the 'data' is exist in the array.
*	@pre	data should be available.
*	@post	none.
*	@param	data what we want to know whether existed.
*	@return	if exist, return index of array, otherwise return -1.
*/
int SortedList::IsExist(ItemType data)
{
    for (int i = 0; i < m_Length; i++)
    {
        if (m_Array[i] == data)
            return i;
    }
    return -1;
}

/*
*	@brief	Add the data at the point of list.
*	@pre	data should be available and list should be initialized.
*	@post	data is added to the list.
*	@param	data what we want to add.
*	@return	return 1 if 'Add' is successful, otherwise return -1.
*/
bool SortedList::Add(ItemType data)
{
    // list�� full�̸� return false
    if (IsFull())	 return false;

    // list�� empty�̸� �Ǿտ� �����ϰ� return true
    if (isEmpty())
    {
        m_Array[0] = data;
        m_Length++;
        return true;
    }

    // �� �׸��� ���� ��ġ iPos�� �˻�
    // ���� �����ϰų� data���� ũ�ų� ���� ������
    int iPos = 0;
    bool found = false;
    while (!found && iPos < m_Length)
    {
        if (data > m_Array[iPos])
            iPos++;
        else
            found = true;
    }

    // �ߺ�Ű�� ��� ���� �޽��� ���
    if (data == m_Array[iPos])
    {
        cout << "\n Same primary key exists in list\n";
        return false;
    }

    /* �߰��̳� �� ���� ���� */
    /*
    *  ������ ������ Ȯ���ϱ� ���Ͽ� iPos���� m_Length-1 ������ ��� �׸��� ��� �̵�
    *  iPos == m_Length�� ���� �̵����� ����
    */
    for (int i = m_Length; i > iPos; i--)
    {
        m_Array[i] = m_Array[i - 1];
    }
    // iPos�� �����ϰ� length ����
    m_Array[iPos] = data;
    m_Length++;
    return true;
}

/*
*	@brief	Reset the list. (Reset the current pointer)
*	@pre	list should be initialized.
*	@post	the current pointer is reset.
*/
void SortedList::ResetList()
{
    m_CurPointer = -1;
}

/**
*	@brief	move list iterator to the next item in list and get that item.
*	@pre	list and list iterator should not be initialized.
*	@post	iterator is moved to next item.
*	@param	data	get current iterator's item. it does not need to be initialized.
*	@return	index of current iterator's item if is not end of list, otherwise return -1.
*/
int SortedList::GetNextItem(ItemType& data)
{
    m_CurPointer++;
    if (m_CurPointer == m_Length)
        return -1;

    data = m_Array[m_CurPointer];

    return m_CurPointer;
}

bool SortedList::isEmpty()
{
    if (m_Length <= 0)
    {
        return true;
    }
    else
        return false;
}

/*
*	@brief  Check the 'data' is exist in the array.
*	@pre    data should be available.
*	@post	none.
*	@param	data what we want to know whether existed.
*	@return	if the data exists, return the data, otherwise return -1.
*/
int SortedList::Retrieve(ItemType& data)
{
    // curPos�� ù��° �׸��� ����Ű���� ����
    int curPos = 0;

    // curPos�� �̵���Ű�鼭 ���� �׸��� key�� data key�� ���Ѵ�.
    // ���� data <= m_array[curPos] �̸�, �̵� �ߴ��ϰ� moreToSearch = false, found = true
    bool moreToSearch = true;
    bool found = false;
    while (moreToSearch && !found)
    {
        if (data > m_Array[curPos])
        {
            curPos++;
            moreToSearch = curPos < m_Length;
        }

        else // data <= m_Array[curPos]
        {
            found = true;
            moreToSearch = false;
        }
    }


    // curPos�� �׸��� key�� data�� key�� ��ġ�ϴ� ���
    if (found && m_Array[curPos] == data)
    {
        data = m_Array[curPos];
        return curPos;
    }

        // curPos �׸��� key�� data key���� ū ���
    else return -1;
}

/**********RetrieveBySimpleType***********/
//	int SortedList::Retrieve(SimpleType& data)
//	{
//		// curPos�� ù��° �׸��� ����Ű���� ����
//		int curPos = 0;
//
//		// curPos�� �̵���Ű�鼭 ���� �׸��� key�� data key�� ���Ѵ�.
//		// ���� data <= m_array[curPos] �̸�, �̵� �ߴ��ϰ� moreToSearch = false, found = true
//		bool moreToSearch = true;
//		bool found = false;
//		while (moreToSearch && !found)
//		{
//			if (data > m_Array[curPos])
//			{
//				curPos++;
//				moreToSearch = curPos < m_Length;
//			}
//
//			else // data <= m_Array[curPos]
//			{
//				found = true;
//				moreToSearch = false;
//			}
//		}
//
//
//		// curPos�� �׸��� key�� data�� key�� ��ġ�ϴ� ���
//		if (found && m_Array[curPos] == data)
//		{
//			data = m_Array[curPos];
//			return curPos;
//		}
//
//		// curPos �׸��� key�� data key���� ū ���
//		else return -1;
//	}

/*
*	@brief  Check the 'data' is exist in the array using binary search.
*	@pre    data should be available.
*	@post	none.
*	@param	data what we want to know whether existed.
*	@return	if the data exists, return the data
*/
int SortedList::Retrieve_Binary(ItemType& inData)
{
    int low = 0;
    int high = m_Length - 1;

    bool bfound = false;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (m_Array[mid] > inData)
        {
            high = mid - 1;
        }
        else if (m_Array[mid] < inData)
        {
            low = mid + 1;
        }

        else
        {
            bfound = true;
            inData = m_Array[mid];
            return mid;
            break;
        }
    }

    //if(bfound == false)
    //{
    return -1;
    //}
}


/*
*	@brief  Delete the 'data' in the array.
*	@pre    data should be available and the array has the data.
*	@post	the array does not have the data.
*	@param	data what we want to delete.
*	@return	if successful, return 1, otherwhise return 0.
*/
bool SortedList::Delete(ItemType data)
{
    int index = IsExist(data);
    if (index == -1) return false;
    else
    {
        m_Array[index] = m_Array[m_Length - 1];		// �� �迭 �� ���� ������ ��!
        m_Length--;
        return true;
    }
}

/*
*	@brief  Replace a old 'data' with a new 'data(parameter)'.
*			(if old data's primary key is same to new data primary key.)
*	@pre    data should be available and the array has the old data has a same primary key
*			to new data's primary key.
*	@post	the array has a new data
*	@param	data what what we want to replace
*	@return	if successful, return 1, otherwhise return 0;
*/
bool SortedList::Replace(ItemType data)
{
    int index = IsExist(data);
    if (index == -1) return false;
    else
    {
        m_Array[index] = data;
        return true;
    }
}

//  bool SortedList::AddToBasket(ItemType& data)
//  {
//      m_Array[m_Length] = data;
//      m_Length++;
//      return true;
//  }