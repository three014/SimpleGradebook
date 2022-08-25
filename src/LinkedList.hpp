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
	protected:
		size_t list_size;
	public:
		LinkedList();
		virtual ~LinkedList();
		Node<D>* head;
		Node<D>* tail;
		inline size_t get_size();
		inline void push(D);
		D pop();
		virtual void remove(D) = 0;
	};
}

template<typename D>
inline Tools::LinkedList<D>::LinkedList()
{
	list_size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename D>
Tools::LinkedList<D>::~LinkedList()
{
	if (head != nullptr)
	{
		Node<D>* traverse = head;
		Node<D>* traverse_ahead = head->next;
		while (traverse != nullptr)
		{
			delete traverse;
			traverse = traverse_ahead;
			if (traverse_ahead != nullptr)
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
	if (head == nullptr)
	{
		head = new_node;
	}
	else
	{
		if (head->next == nullptr)
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
D Tools::LinkedList<D>::pop()
{
	Tools::Node<D>* traverse = head;
	Tools::Node<D>* prev = nullptr;
	D val;

	while (traverse->next != nullptr)
	{
		prev = traverse;
		traverse = traverse->next;
	}
	if (traverse != nullptr) 
	{
		val = traverse->data;
	}
	delete traverse;
	if (prev != nullptr)
	{
		tail = prev;
	}
	else
	{
		tail = nullptr;
	}
	list_size--;
	return val;
}

#endif
