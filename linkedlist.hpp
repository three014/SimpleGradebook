#pragma once

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

namespace Tools
{
	template<typename D> 
	class Node
	{
	public:
		Node(D item) { data = item; }
		D data;
		Node<D>* next;
	};

	template<typename D> 
	class LinkedList
	{
	private:
		size_t list_size;
	public:
		LinkedList() {}
		~LinkedList();
		Node<D>* head;
		Node<D>* tail;
		inline size_t get_size();
		inline void push(D);
		void pop();
		virtual void remove(D) = 0;
	};
}

template<typename D> 
Tools::LinkedList<D>::~LinkedList()
{
	if (head != NULL)
	{
		Node<D>* traverse = head;
		Node<D>* traverse_ahead = head->next;
		while (traverse != NULL)
		{
			delete traverse;
			traverse = traverse_ahead;
			if (traverse_ahead != NULL)
			{
				traverse_ahead = traverse_ahead->next;
			}
		}
	}
}

template<typename D> 
inline size_t Tools::LinkedList<D>::get_size() { return list_size; }

template<typename D> 
inline void Tools::LinkedList<D>::push(D item)
{
	Tools::Node<D>* new_node = new Tools::Node<D>(item);
	if (head == NULL)
	{
		head = new_node;
	}
	else
	{
		if (head->next == NULL)
		{
			head->next = new_node;
		}
		else
		{
			tail->next = new_node;
		}
	}

	tail = new_node;
	list_size++;
}

template<typename D> 
void Tools::LinkedList<D>::pop()
{
	Tools::Node<D>* traverse = head;
	Tools::Node<D>* prev = NULL;

	while (traverse->next != NULL)
	{
		prev = traverse;
		traverse = traverse->next;
	}
	delete traverse;
	if (prev != NULL)
	{
		tail = prev;
	}
	else
	{
		tail = NULL;
	}
	list_size--;
}

#endif
