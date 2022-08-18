#ifndef GENERAL_TOOLS_H
#define GENERAL_TOOLS_H

#include <vector>

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


	template<typename K, typename V>
	class HashNode
	{
	public:
		V value;
		K key;

		HashNode(K, V);
	};


	template<typename K, typename V>
	class HashMap
	{
		HashNode<K, V>** arr;
		int capacity;
		int size;

	public:
		HashMap();
		int hash_code(K);
		void insert_node(K, V);
		V delete_node(int);
		V get(int);
		int size_of_map();
		bool is_empty();
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

template<typename K, typename V>
inline Tools::HashNode<K, V>::HashNode(K key, V value)
{
	this->value = value;
	this->key = key;
}

template<typename K, typename V>
inline Tools::HashMap<K, V>::HashMap()
{
	capacity = 20;
	size = 0;
	arr = new HashNode<K, V>*[capacity];

	for (int i = 0; i < capacity; i++)
	{
		arr[i] = NULL;
	}
}

template<typename K, typename V>
inline int Tools::HashMap<K, V>::hash_code(K key)
{
	long x = * ( long * ) &key; // probably not a great idea; took it from Fast Inv. Sqrt. (Quake III)
	
	if (x < 0)
	{
		x *= -1;
	}
	int hash = x % 20;

	return hash;
}

template<typename K, typename V>
void Tools::HashMap<K, V>::insert_node(K key, V value)
{
	HashNode<K, V>* temp = new HashNode<K, V>(key, value);

	int hash_index = hash_code(key);
	while (arr[hash_index] != NULL && arr[hash_index]->key != key)
	{
		hash_index++;
		hash_index %= capacity;
	}

	if (arr[hash_index] == NULL)
	{
		size++;
	}
	arr[hash_index] = temp;
}


#endif