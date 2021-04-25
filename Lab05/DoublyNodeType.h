#pragma once
template<typename T>
struct DoublyNodeType
{
	T data;					// data
	DoublyNodeType* prev;	// Pointer of previous node
	DoublyNodeType* next;	// Pointer of next node
};
