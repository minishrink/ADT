
#pragma once

#include <cstdlib>
#include <vector>     // values
#include <iostream>

// alias for ease
#define Hash Hashtbl<K, V>

// key and value types
template <typename K, typename V> class Hashtbl {

  // pointer to hash_function providing value index
  typedef int &hash_function (K key);

  // data members
  private:
    const int len;
    // does this initialise to the correct size?
    // std::vector<K> keys;
    std::vector<V> values;
    hash_function hash_f;

  public:

    // TODO : is explicit required in constructor?
    Hash (hash_function f, const int n) {
      len = n;
      &hash_f = f;
      std::vector<V> values = new std::vector<V>(len);
    }

    // compute hash
    int index(K key)  {
      return hash_f(key);
    }

    // getter with hash_fn
    V get(K key)  {
      return values.at(index(key));
    }

    // setter for values
    void set(int i, V value) {
      values.at(i) = value;
    }

    void remove(K key)  {
      values.erase(values.begin()+index(key));
    }

    // FIXME unsure what to do about K, V types
    void del() {
      // deallocate pointers to value objects
      for (const V & i : values) {
        delete i;
      }
      // now destroy vector itself
      delete values;
      std::cout << "Hashtbl values vector deleted\n";
      // finally, deallocate hashtbl object
      delete &this;
      std::cout << "Hashtbl deleted\n";
    }
};
