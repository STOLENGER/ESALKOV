//
// Created by Egor Salkov on 20.05.2020.
//

#include "UnorderedMap.h"
template<class KeyType, class DataType, class Hash>
using iterator = typename list<std::pair<const KeyType, DataType>>::iterator;

template<class KeyType, class DataType, class Hash>
iterator UnorderedMap<KeyType, DataType, Hash>:: end()
{
    return storage.end();
}

template<class KeyType, class DataType, class Hash>
void UnorderedMap<KeyType, DataType, Hash>::clear()
{
    num_elem = 0;
    table.clear();
    table.resize(table_sz);
    storage.clear();
}

template<class KeyType, class DataType, class Hash>
void UnorderedMap<KeyType, DataType, Hash>::erase(KeyType key) {
    num_elem = 0;
    table.clear();
    table.resize(table_sz);
    storage.clear();
}