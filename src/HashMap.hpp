#pragma once

#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <functional>

namespace Tools 
{
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
		std::hash<K> hash_key;

		HashNode<K, V>* dummy;

	public:
		HashMap(K, V);
		~HashMap();
		int hash_code(K);
		bool insert_node(K, V);
		V delete_node(K);
		V get_value(K);
		int size_of_map();
		bool is_empty();
	};
}

template<typename K, typename V>
inline Tools::HashNode<K, V>::HashNode(K key, V value)
{
	this->value = value;
	this->key = key;
}

template<typename K, typename V>
inline Tools::HashMap<K, V>::HashMap(K dummy_key, V dummy_value)
{
	capacity = 20;
	size = 0;
	arr = new HashNode<K, V>*[capacity];

	for (int i = 0; i < capacity; i++)
	{
		arr[i] = nullptr;
	}

	dummy = new HashNode<K, V>(dummy_key, dummy_value);
}

template<typename K, typename V>
Tools::HashMap<K, V>::~HashMap()
{
	delete[] arr;
	delete dummy;
}

template<typename K, typename V>
inline int Tools::HashMap<K, V>::hash_code(K key)
{
	
	int hash = hash_key(key) % capacity;

	return hash;
}

template<typename K, typename V>
bool Tools::HashMap<K, V>::insert_node(K key, V value)
{
	HashNode<K, V>* temp = new HashNode<K, V>(key, value);

	int hash_index = hash_code(key);

	for (int i = 0; i < capacity; i++)
	{
		if (arr[hash_index] == nullptr || arr[hash_index] == dummy)
		{
			size++;
			arr[hash_index] = temp;
			return true;
		}

		hash_index++;
		hash_index %= capacity;
	}
	
	return false;
}

template<typename K, typename V>
V Tools::HashMap<K, V>::delete_node(K key)
{
	int hash_index = hash_code(key);
	size_t hash_value = hash_key(key);
	size_t hash_arr_key;

	for (int i = 0; i < capacity; i++)
	{
		if (arr[hash_index] == nullptr || arr[hash_index] == dummy)
		{
			hash_index++;
			hash_index %= capacity;
			continue;
		}

		hash_arr_key = hash_key(arr[hash_index]->key);
		if (hash_arr_key == hash_value)
		{
			HashNode<K, V>* temp = arr[hash_index];
			arr[hash_index] = dummy;

			size--;

			V val = temp->value;
			delete temp;
            arr[hash_index] = nullptr;
			return val;
		}

		hash_index++;
		hash_index %= capacity;
	}
	
	return dummy->value;
}

template<typename K, typename V>
V Tools::HashMap<K, V>::get_value(K key)
{
	int hash_index = hash_code(key);
	size_t hash_value = hash_key(key);
	size_t hash_arr_key;

	for (int i = 0; i < capacity; i++)
	{
		if (arr[hash_index] == nullptr || arr[hash_index] == dummy)
		{
			hash_index++;
			hash_index %= capacity;
			continue;
		}

		hash_arr_key = hash_key(arr[hash_index]->key);
		if (hash_arr_key == hash_value)
		{
			return arr[hash_index]->value;
		}

		hash_index++;
		hash_index %= capacity;
	}
	
	return dummy->value;
}

template<typename K, typename V>
inline int Tools::HashMap<K, V>::size_of_map()
{
	return size;
}

template<typename K, typename V>
inline bool Tools::HashMap<K, V>::is_empty()
{
	return size == 0;
}


#endif
