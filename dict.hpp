
#include "hashtbl.hpp"

#define Hash Hashtbl<K, V>

template<typename K, typename V>
class Dict  {
  // placeholder function: map all to 0
  int id(K key)  {
    return 0;
  }

  private:
    const int len;
    Hash tbl;

  public:
    // is this constructor necessary?
    Dict();

    Dict (const int n)  {
      len = n;
      // initialise underyling hashtbl
      Hash tbl = new Hash(id, len);
    }

    V search(K key)  {
      try {
        return tbl.get(key);
      }
      catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
      }
      catch (...) {
        std::cerr << "Unexpected error occurred\n";
      }
      // FIXME best way to handle this?
      throw 0;
    }

    void insert(K key, V value) {
      int i = tbl.index(key);
      tbl.set(i, value);
    }

    void remove(K key)  {
      tbl.remove(key);
    }

    void del () {
      // hashtbl destructor handles internal stuff
      tbl.del();
      delete &this;
    }

};
