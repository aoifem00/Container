#define Deque_DEFINE(t)                                                        \
    struct Deque_##t##_Iterator {                                              \
      t type;                                                                  \
      t* pointer;                                                              \
      t& reference;                                                            \
      Deque_##t##_Iterator (*inc)(Deque_##t##_Iterator* it);                   \
      t (*deref)(Deque_##t##_Iterator *it);                                    \
    };                                                                         \
    struct Deque_##t {                                                         \
      t* data;                                                                 \
      t type_name;                                                             \
      void (*push_front)(Deque_##t *deq, t item);                              \
      void (*push_back)(Deque_##t *deq, t item);                               \
      void (*dtor)(Deque_##t *p);                                              \
      t (*front)(Deque_##t *p);                                                \
      t (*back)(Deque_##t *p);                                                 \
      void (*pop_front)(Deque_##t *p);                                         \
      void (*pop_back)(Deque_##t *p);                                          \
      int (*size)(Deque_##t *p);                                               \
      t (*at)(Deque_##t *p, int i);                                            \
      void (*clear)(Deque_##t *p);                                             \
      bool (*empty)(Deque_##t *p);                                             \
      void (*ctor)(t* t1, bool b);                                             \
      Deque_##t##_Iterator (*begin)(Deque_##t *deq);                           \
      bool (*Deque_##t##_equal)(t item1, t item2);                             \
      void (*sort)(Deque_##t *deq, Deque_##t##_Iterator it1, Deque_##t##_Iterator it2); \
      Deque_##t##_Iterator (*end)(Deque_##t *deq);                             \
    };                                                                         \
    void Deque_##t##_Iterator_equal(Deque_##t##_Iterator it1, Deque_##t##_Iterator it2){ \
                                                                               \
    }                                                                          \
    t deref(Deque_##t##_Iterator* it){                                         \
      return (t)(*it);                                                         \
    }                                                                          \
    Deque_##t##_Iterator inc(Deque_##t##_Iterator* it){                        \
      return &(it+sizeof(it->type));                                           \
    }                                                                          \
    t at(Deque_##t *p, int i){                                                 \
      return (p->data+i);                                                      \
    }                                                                          \
    void sort(Deque_##t *deq, Deque_##t##_Iterator it1, Deque_##t##_Iterator it2){ \
    }                                                                          \
    Deque_##t##_Iterator begin(Deque_##t *p){                                  \
      return (unsigned long)(&p->data);                                        \
    }                                                                          \
    void Deque_##t##_dtor(Deque_##t *p){                                       \
    }                                                                          \
    t Deque_##t##_front(Deque_##t *p){                                         \
      return *(p->data);                                                       \
    }                                                                          \
    t Deque_##t##_back(Deque_##t *p){                                          \
      return *(p->data+size);                                                  \
    }                                                                          \
    void Deque_##t##_pop_front(Deque_##t *p){                                  \
    }                                                                          \
    void Deque_##t##_pop_back(Deque_##t *p){                                   \
    }                                                                          \
    int Deque_##t##_size(Deque_##t *p){                                        \
      return 0;                                                                \
    }                                                                          \
    void Deque_##t##_clear(Deque_##t *p){                                      \
    }                                                                          \
    bool Deque_##t##_empty(Deque_##t *p){                                      \
      return true;                                                             \
    }                                                                          \
    void Deque_##t##_ctor(Deque_##t *deq, bool b){                             \
    }                                                                          \
    bool Deque_##t##_equal(Deque_##t deq1, Deque_##t deq2){                    \
      return true;                                                             \
    }                                                                          \
