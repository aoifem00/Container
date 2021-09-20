#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Deque_DEFINE(t)                                                        \
    struct Deque_##t##_Iterator {                                              \
      t type;                                                                  \
      t* pointer;                                                              \
      t& reference;                                                            \
      void (*inc)(Deque_##t##_Iterator* it);                                   \
      void (*dec)(Deque_##t##_Iterator* it);                                   \
      t& (*deref)(Deque_##t##_Iterator*);                                      \
    };                                                                         \
    struct Deque_##t {                                                         \
      t* data;                                                                 \
      t type_name;                                                             \
      int sz;                                                                  \
      void (*push_front)(Deque_##t*, t);                                       \
      void (*push_back)(Deque_##t*, t);                                        \
      void (*dtor)(Deque_##t*);                                                \
      t &(*front)(Deque_##t*);                                                 \
      t &(*back)(Deque_##t*);                                                  \
      void (*pop_front)(Deque_##t *p);                                         \
      void (*pop_back)(Deque_##t *p);                                          \
      size_t& (*size)(Deque_##t *p);                                           \
      t& (*at)(Deque_##t *p, int i);                                           \
      void (*clear)(Deque_##t *p);                                             \
      bool (*empty)(Deque_##t *p);                                             \
      Deque_##t##_Iterator (*begin)(Deque_##t *deq);                           \
      bool (*Deque_##t##_equal)(t item1, t item2);                             \
      void (*sort)(Deque_##t *deq, Deque_##t##_Iterator it1, Deque_##t##_Iterator it2); \
      Deque_##t##_Iterator (*end)(Deque_##t *deq);                             \
    };                                                                         \
    Deque_##t##_Iterator* Deque_##t##_Iterator_new(){                           \
      Deque_##t##_Iterator* iter=(Deque_##t##_Iterator*) malloc(sizeof(Deque_##t##_Iterator)); \
      return iter;                                                             \
    }                                                                          \
    bool Deque_##t##_Iterator_equal(Deque_##t##_Iterator it1, Deque_##t##_Iterator it2){ \
      return true;                                                             \
    }                                                                          \
    t& deref(Deque_##t##_Iterator* it){                                         \
      return *(it->pointer);                                                   \
    }                                                                          \
    void inc(Deque_##t##_Iterator* it){                                        \
      it=it+sizeof(it->type);                                                  \
    }                                                                          \
    void dec(Deque_##t##_Iterator* it){                                        \
      it=it-sizeof(it->type);                                                  \
    }                                                                          \
    t& Deque_##t##_at(Deque_##t *p, int i){                                    \
      return *(p->data+i);                                                     \
    }                                                                          \
    void sort(Deque_##t *deq, Deque_##t##_Iterator it1, Deque_##t##_Iterator it2){ \
    }                                                                          \
    Deque_##t##_Iterator begin(Deque_##t *p){                                  \
      Deque_##t##_Iterator* iter=Deque_##t##_Iterator_new();                   \
      iter->pointer=p->data;                                                   \
      return (*iter);                                                          \
    }                                                                          \
    void Deque_##t##_dtor(Deque_##t *p){                                       \
    }                                                                          \
    t& Deque_##t##_front(Deque_##t *p){                                        \
      return *(p->data);                                                       \
    }                                                                          \
    t& Deque_##t##_back(Deque_##t *p){                                         \
      return *(p->data+p->sz);                                                 \
    }                                                                          \
    void Deque_##t##_pop_front(Deque_##t *p){                                  \
    }                                                                          \
    void Deque_##t##_pop_back(Deque_##t *p){                                   \
    }                                                                          \
    size_t& Deque_##t##_size(Deque_##t *p){                                    \
      size_t* n=(size_t*)malloc(sizeof(size_t));                               \
      *n=0;                                                                    \
      return *n;                                                               \
    }                                                                          \
    void Deque_##t##_clear(Deque_##t *p){                                      \
    }                                                                          \
    bool Deque_##t##_empty(Deque_##t *p){                                      \
      return true;                                                             \
    }                                                                          \
    void Deque_##t##_ctor(Deque_##t *deq, bool b){                             \
      deq = (Deque_##t*) malloc(sizeof(Deque_##t));                            \
      deq->front=&Deque_##t##_front;                                           \
      deq->back=&Deque_##t##_back;                                             \
      deq->at=&Deque_##t##_at;                                                 \
    }                                                                          \
    bool Deque_##t##_equal(Deque_##t deq1, Deque_##t deq2){                    \
      return true;                                                             \
    }                                                                          \
