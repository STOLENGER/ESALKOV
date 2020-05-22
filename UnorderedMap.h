//
// Created by Egor Salkov on 20.05.2020.
//

#ifndef LAB3_4_OOP_UNORDEREDMAP_H
#define LAB3_4_OOP_UNORDEREDMAP_H

#include <iostream>
#include <utility>
#include "List.h"
//KeyType тип ключа
//DataType тип данных
// Hash шаблонный параметр
template<class KeyType,class DataType, class Hash = std::hash<KeyType>>
class  UnorderedMap
{
    list<std::pair<const KeyType, DataType>> storage;
    std::vector<list<typename list<std::pair<const KeyType, DataType>>::iterator>> table;
    Hash hash_func;
    size_t table_sz;
    size_t num_elem;

    void realocator() {//переназначение памяти
        if (num_elem >= table_sz) {
            table_sz *= 2;
            table.clear();
            table.resize(table_sz);
            for (auto iter = storage.begin(); iter != storage.end(); ++iter) {
                table[my_hash((*iter).first)].push_front(iter);
            }
        }
    }
public:
    using iterator = typename list<std::pair<const KeyType, DataType>>::iterator;
    using const_iterator = typename list<std::pair<const KeyType, DataType>>::const_iterator;


    template <class Iter>
    UnorderedMap(Iter beg, Iter end, Hash hash = Hash())
    : hash_func(hash),
    table_sz(64),
    num_elem(0)
    {
        table.resize(table_sz);
        for (; beg != end; ++beg) {
            insert(*beg);
        }
    }
    UnorderedMap(std::initializer_list<std::pair<KeyType, DataType>> list,Hash hash = Hash())
    : hash_func(hash),
    table_sz(64),
    num_elem(0)
    {
        table.resize(table_sz);
        for (auto elem : list) {
            insert(elem);
        }
    }
    size_t size() const {
        return num_elem;
    }

    bool empty() const {
        return num_elem == 0;
    }

    Hash hash_function() const {
        return hash_func;
    }

    size_t my_hash(const KeyType& key) const {
        return hash_func(key) % table_sz;
    }
    const DataType& at(const KeyType& key) const {
        const_iterator iter = find(key);
        if (iter == storage.end()) {
            throw std::out_of_range("");
        }
        return (*iter).second;
    }
    DataType& operator[](const KeyType& key) {
        iterator iter = find(key);
        if (iter == storage.end()) {
            std::pair<const KeyType, DataType> couple = {key, DataType()};
            insert(couple);
            return (*(storage.begin())).second;
        }
        return (*iter).second;
    }
    iterator find(const KeyType& key) {
        for (auto iter : table[my_hash(key)]) {
            if ((*iter).first == key) {
                return iter;
            }
        }
        return storage.end();
    }
    void insert(const std::pair<KeyType, DataType>& couple) {
        if (find(couple.first) == storage.end()) {
            storage.push_front(couple);
            table[my_hash(couple.first)].push_front(storage.begin());
            ++num_elem;
        }
        realocator();
    }
    iterator begin() {
        return storage.begin();
    }
    iterator end();
    void erase(KeyType key);
    void clear();
    UnorderedMap& operator = (const UnorderedMap& other) {
        if (this != &other) {
            clear();
            for (auto it : other) {
                insert(it);
            }
        }
        return *this;
    }

};







#endif //LAB3_4_OOP_UNORDEREDMAP_H
