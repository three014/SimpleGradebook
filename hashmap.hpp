#pragma once

#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <typeinfo>
#include <string>

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

		HashNode<K, V>* dummy;

	public:
		HashMap(K, V);
		~HashMap();
		int hash_code(K);
		void insert_node(K, V);
		V delete_node(K);
		V get(K);
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
inline Tools::HashMap<K, V>::HashMap(K dummyK, V dummyV)
{
	capacity = 20;
	size = 0;
	arr = new HashNode<K, V>*[capacity];

	for (int i = 0; i < capacity; i++)
	{
		arr[i] = nullptr;
	}

	dummy = new HashNode<K, V>(dummyK, dummyV);
}

template<typename K, typename V>
Tools::HashMap<K, V>::~HashMap()
{
	delete[] arr;
}

template<typename K, typename V>
inline int Tools::HashMap<K, V>::hash_code(K key)
{
	long x = *(long*)&key; // probably not a great idea; took it from Fast Inv. Sqrt. (Quake III)

	if (x < 0)
	{
		x *= -1;
	}
	int hash = x % capacity;

	return hash;
}

template<typename K, typename V>
void Tools::HashMap<K, V>::insert_node(K key, V value)
{
	HashNode<K, V>* temp = new HashNode<K, V>(key, value);

	int hash_index = hash_code(key);

	if (typeid(key) == typeid("string")) // if the key type is a string, compare strings with string methods
	{
		while (arr[hash_index] != nullptr 
				&& ((std::string) arr[hash_index]->key).compare((std::string) key) != 0 
				&& ((std::string) arr[hash_index]->key).compare((std::string) dummy->key) != 0)
		{
			hash_index++;
			hash_index %= capacity;
		}

		if (arr[hash_index] == nullptr 
				|| ((std::string) arr[hash_index]->key).compare((std::string) dummy->key) == 0)
		{
			size++;
		}
	}
	else
	{
		while (arr[hash_index] != NULL 
				&& arr[hash_index]->key != key 
				&& arr[hash_index]->key != dummy->key)
		{
			hash_index++;
			hash_index %= capacity;
		}

		if (arr[hash_index] == nullptr || arr[hash_index]->key == dummy->key)
		{
			size++;
		}
	}
	
	arr[hash_index] = temp;
}

template<typename K, typename V>
V Tools::HashMap<K, V>::delete_node(K key)
{
	int hash_index = hash_code(key);

	bool key_matches = false;

	while (arr[hash_index] != nullptr)
	{
		if (typeid(key) == typeid("string") 
				&& ((std::string) arr[hash_index]->key).compare((std::string) key) == 0)
		{
			key_matches = true;
		}
		else if (typeid(key) != typeid("string") && arr[hash_index]->key == key)
		{
			key_matches = true;
		}
		
		if (key_matches)
		{
			HashNode<K, V>* temp = arr[hash_index];

			arr[hash_index] = dummy;

			size--;
			V val = temp->value;
			delete temp;
			return val;
		}
	}
	
	return nullptr;
}

template<typename K, typename V>
V Tools::HashMap<K, V>::get(K key)
{
	int hash_index = hash_code(key);
	int counter = 0;

	bool key_matches = false;

	while (arr[hash_index] != nullptr)
	{
		if (counter > capacity)
		{
			return NULL;
		}
		else
		{
			counter++;
		}
		if (typeid(key) == typeid("string") 
				&& ((std::string) arr[hash_index]->key).compare((std::string) key) == 0)
		{
			key_matches = true;
		}
		else if (typeid(key) != typeid("string") && arr[hash_index]->key == key)
		{
			key_matches = true;
		}

		if (key_matches)
		{
			return arr[hash_index]->value;
		}
		hash_index++;
		hash_index %= capacity;
	}
	
	return nullptr;
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
