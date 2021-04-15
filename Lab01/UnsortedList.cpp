#include "UnsortedList.h"
using namespace std;

/*
	*	@brief	make the list empty.
	*	@pre	none.
	*	@post	the list is empty.
	*/
void ArrayList::MakeEmpty()
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
int ArrayList::GetLength()
{
	return m_Length;
}

/*
*	@brief	Check the array is full.
*	@pre	none.
*	@post	none.
*	@return if the array capacity is filled, return true, otherwise return false.
*/
bool ArrayList::IsFull()
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
int ArrayList::IsExist(ItemType data)
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
int ArrayList::Add(ItemType data)
{
	if (IsFull())
		return -1;
	else if (IsExist(data) > -1)
		return -1;

	m_Array[m_Length] = data;
	m_Length++;

	return 1;
}

/*
*	@brief	Reset the list. (Reset the current pointer)
*	@pre	list should be initialized.
*	@post	the current pointer is reset.
*/
void ArrayList::ResetList()
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
int ArrayList::GetNextItem(ItemType& data)
{
	m_CurPointer++;
	if (m_CurPointer == m_Length)
		return -1;

	data = m_Array[m_CurPointer];

	return m_CurPointer;
}

bool ArrayList::isEmpty()
{
	if (m_Length <= 0)
	{
		return true;
	}
	else
		return false;
}

/************************************************************************/
/*
*	@brief  Check the 'data' is exist in the array.
*	@pre    data should be available.
*	@post	none.
*	@param	data what we want to know whether existed.
*	@return	if the data exists, return the data, otherwise return -1.
*/
int ArrayList::Retrieve(ItemType& data)
{
	int index = IsExist(data);
	if (index == -1) return -1;
	else
	{
		data = m_Array[index];
		return index;
	}
}
/************************************************************************/

/*
*	@brief  Delete the 'data' in the array.
*	@pre    data should be available and the array has the data.
*	@post	the array does not have the data.
*	@param	data what we want to delete.
*	@return	if successful, return 1, otherwhise return 0.
*/
bool ArrayList::Delete(ItemType data)
{
	int index = IsExist(data);
	if (index == -1) return false;
	else
	{
		m_Array[index] = m_Array[m_Length - 1];		// ★ 배열 맨 끝을 복사해 옴!
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
bool ArrayList::Replace(ItemType data)
{
	int index = IsExist(data);
	if (index == -1) return false;
	else
	{
		m_Array[index] = data;
		return true;
	}
}