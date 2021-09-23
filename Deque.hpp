#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Deque_DEFINE(t)                                                        \
    struct Deque_##t##_Iterator;                                               \
    struct Deque_##t;                                                          \
                                                                               \
    struct Deque_##t##_Iterator {                                              \
      int index;                                                               \
      t type;                                                                  \
      t* pointer;                                                              \
      t& reference;                                                            \
      Deque_##t *deque;                                                        \
      void (*inc)(Deque_##t##_Iterator* it);                                   \
      void (*dec)(Deque_##t##_Iterator* it);                                   \
      t& (*deref)(Deque_##t##_Iterator*);                                      \
    };                                                                         \
                                                                               \
    struct Deque_##t {                                                         \
      t* data=new t[10];                                                       \
      const char* type_name=(const char*)malloc(sizeof(t&));                   \
      size_t sz=0;                                                             \
      int head=0;                                                              \
      int tail=0;                                                              \
      int iterHead=0;                                                          \
      int iterTail=0;                                                          \
      void (*push_front)(Deque_##t*, t);                                       \
      void (*push_back)(Deque_##t*, t);                                        \
      void (*dtor)(Deque_##t*);                                                \
      t &(*front)(Deque_##t*);                                                 \
      t &(*back)(Deque_##t*);                                                  \
      void (*pop_front)(Deque_##t*);                                           \
      void (*pop_back)(Deque_##t*);                                            \
      size_t (*size)(Deque_##t*);                                              \
      t &(*at)(Deque_##t*, int);                                               \
      void (*clear)(Deque_##t*);                                               \
      bool (*empty)(Deque_##t*);                                               \
      Deque_##t##_Iterator& (*begin)(Deque_##t *deq);                          \
      bool (*equal)(Deque_##t, Deque_##t);                                     \
      void (*sort)(Deque_##t *, Deque_##t##_Iterator, Deque_##t##_Iterator);   \
      Deque_##t##_Iterator& (*end)(Deque_##t *deq);                            \
      bool (*compare)(const t&, const t&);                                     \
    };                                                                         \
    bool Deque_##t##_Iterator_equal(Deque_##t##_Iterator it1, Deque_##t##_Iterator it2){ \
      return true;                                                             \
    }                                                                          \
    t& Deque_##t##_Iterator_deref(Deque_##t##_Iterator* it){                   \
      return *(it->pointer);                                                   \
    }                                                                          \
    void Deque_##t##_Iterator_inc(Deque_##t##_Iterator* it){                   \
      it=it+sizeof(it->type);                                                  \
    }                                                                          \
    void Deque_##t##_Iterator_dec(Deque_##t##_Iterator* it){                   \
      if(it->index==it->deque->head){                                          \
        it->index=it->deque->tail;                                             \
        it->pointer=&it->deque->data[it->deque->tail];                         \
      }                                                                        \
      else{                                                                    \
        it->index=it->index-1;                                                 \
        it->pointer=&it->deque->data[it->index];                               \
      }                                                                        \
    }                                                                          \
    t& Deque_##t##_at(Deque_##t *p, int i){                                    \
      return p->data[(p->head+i)%10];                                          \
    }                                                                          \
    void sort(Deque_##t *deq, Deque_##t##_Iterator it1, Deque_##t##_Iterator it2){ \
    }                                                                          \
    Deque_##t##_Iterator* Deque_##t##_Iterator_new(){                          \
      Deque_##t##_Iterator* iter=(Deque_##t##_Iterator*) malloc(sizeof(Deque_##t##_Iterator)); \
      iter->pointer=new t();                                                   \
      iter->inc=Deque_##t##_Iterator_inc;                                      \
      iter->dec=Deque_##t##_Iterator_dec;                                      \
      iter->deref=Deque_##t##_Iterator_deref;                                  \
      iter->deque=new Deque_##t();                                             \
      return iter;                                                             \
    }                                                                          \
    Deque_##t##_Iterator& Deque_##t##_Iterator_begin(Deque_##t *p){            \
      Deque_##t##_Iterator* iter=Deque_##t##_Iterator_new();                   \
      iter->index=p->head;                                                     \
      *(iter->deque)=*p;                                                       \
      *(iter->pointer)=p->data[p->head];                                       \
      return *iter;                                                            \
    }                                                                          \
    Deque_##t##_Iterator& Deque_##t##_Iterator_end(Deque_##t *p){              \
      Deque_##t##_Iterator* iter=Deque_##t##_Iterator_new();                   \
      iter->pointer=&p->data[p->iterTail];                                     \
      iter->index=p->iterTail;                                                     \
      *(iter->deque)=*p;                                                       \
      return (*iter);                                                          \
    }                                                                          \
    void Deque_##t##_dtor(Deque_##t *p){                                       \
    }                                                                          \
    t& Deque_##t##_front(Deque_##t *p){                                        \
      return p->data[p->head];                                                 \
    }                                                                          \
    t& Deque_##t##_back(Deque_##t *p){                                         \
      return p->data[p->tail];                                                 \
    }                                                                          \
    /*void Deque_##t##_pop_front(Deque_##t *p){                                \
      for(int i=0; i<=p->tail; i++){                                           \
        p->data[i]=p->data[i+1];                                               \
      }                                                                        \
      t* tmp=new t();                                                          \
      memcpy(tmp, &p->data[p->tail], sizeof(tmp));                             \
      p->tail--;                                                               \
    }*/                                                                        \
    void Deque_##t##_pop_front(Deque_##t *p){                                  \
      t* tmp=new t();                                                          \
      memcpy(tmp, &p->data[p->head], sizeof(tmp));                             \
      p->head=(p->head+1)%10;                                                  \
      p->sz=p->sz-1;                                                           \
    }                                                                          \
    void Deque_##t##_pop_back(Deque_##t *p){                                   \
      t* tmp=new t();                                                          \
      memcpy(tmp, &p->data[p->tail], sizeof(tmp));                             \
      p->tail--;                                                               \
      p->sz=p->sz-1;                                                           \
    }                                                                          \
    void Deque_##t##_push_back(Deque_##t *p, t item){                          \
      t* tmp=new t();                                                          \
      if(memcmp(tmp, &p->data[p->tail], sizeof(tmp))==0) p->data[p->tail]=item;\
      else{                                                                    \
        if(p->tail==9) p->tail=0;                                              \
        else p->tail++;                                                        \
        p->data[p->tail]=item;                                                 \
      }                                                                        \
      p->sz=p->sz+1;                                                           \
      p->iterTail=p->tail;                                                     \
    }                                                                          \
    /*void Deque_##t##_push_back(Deque_##t *p, t item){                        \
      p->tail++;                                                               \
      if(p->tail==sizeof(p->data)){                                            \
        p->tail-=1;                                                            \
        for(int i=sizeof(p->data)-1; i>0; i--) p->data[i-1]=p->data[i];        \
        p->data[p->tail]=item;                                                 \
      }                                                                        \
      else{                                                                    \
        p->data[p->tail]=item;                                                 \
      }                                                                        \
    }*/                                                                        \
    void Deque_##t##_push_front(Deque_##t *p, t item){                         \
      t* tmp=new t();                                                          \
      if(memcmp(tmp, &p->data[p->head], sizeof(tmp))==0) p->data[p->head]=item;\
      else{                                                                    \
        if(p->head==0) p->head=9;                                              \
        else p->head--;                                                        \
        p->data[p->head]=item;                                                 \
      }                                                                        \
      p->sz=p->sz+1;                                                           \
      p->iterHead=p->head;                                                     \
    }                                                                          \
    /*void Deque_##t##_push_front(Deque_##t *p, t item){                       \
      t* tmp=new t();                                                          \
      if(memcmp(&p->data[0], tmp, sizeof(p->data[0]))==0) p->data[0]=item;     \
      else{                                                                    \
        int i=0;                                                               \
        while(memcmp(&p->data[i], tmp, sizeof(p->data[i]))!=0&&i<10){          \
          i++;                                                                 \
        }                                                                      \
        int start=sizeof(p->data)/sizeof(p->data[0])-1;                        \
        for(int j=5; j>=0; j--) p->data[j]=p->data[j-1];                       \
        p->data[0]=item;                                                       \
      }                                                                        \
      delete tmp;                                                              \
      p->tail++;                                                               \
    }*/                                                                          \
    /*size_t& Deque_##t##_size(Deque_##t *p){                                  \
      size_t* n=(size_t*)malloc(sizeof(size_t));                               \
      *n=0;                                                                    \
      return *n;                                                               \
    }*/                                                                        \
    size_t Deque_##t##_size(Deque_##t *p){                                     \
      return p->sz;                                                            \
    }                                                                          \
    void Deque_##t##_clear(Deque_##t *p){                                      \
    }                                                                          \
    bool Deque_##t##_empty(Deque_##t *p){                                      \
      t* tmp=new t();                                                          \
      int c=memcmp(&p->data[0], tmp, sizeof(p->data[0]));                      \
      return p->tail==0 && c==0;                                              \
    }                                                                          \
    /*Deque_##t* Deque_##t_##_new(){                                           \
      Deque_##t* deque=(Deque_##t*)malloc(sizeof(Deque_##t));                  \
      deque->data=(t*)malloc(sizeof(1024));                                    \
      deque->front=&Deque_##t##_front;                                         \
      deque->back=&Deque_##t##_back;                                           \
      deque->at=&Deque_##t##_at;                                               \
      deque->size=&Deque_##t##_size;                                           \
      deque->empty=&Deque_##t##_empty;                                         \
      deque->push_back=&Deque_##t##_push_back;                                 \
      deque->sz=0;                                                             \
      return deque;                                                            \
    }*/                                                                        \
    bool Deque_##t##_equal(Deque_##t deq1, Deque_##t deq2){                    \
      if(deq1.sz!=deq2.sz) return false;                                       \
      if(deq1.head>deq1.tail){                                                 \
        for(int i=deq1.head; i<10; i++){                                       \
          if(deq1.compare(deq1.data[i], deq2.data[i])==true                  \
          || deq1.compare(deq2.data[i], deq1.data[i])==true) return false;  \
        }                                                                      \
        for(int i=0; i<deq1.tail; i++){                                        \
          if(deq1.compare(deq1.data[i], deq2.data[i])==true                  \
          || deq1.compare(deq2.data[i], deq1.data[i])==true) return false;  \
        }                                                                      \
      }                                                                      \
      else{                                                                  \
        for(int i=deq1.head; i<=deq1.tail; i++){                              \
          printf("%d\n", deq1.compare(deq1.data[i], deq2.data[i]));              \
          if(deq1.compare(deq1.data[i], deq2.data[i])==true                  \
          || deq1.compare(deq2.data[i], deq1.data[i])==true) return false;  \
        }                                                                    \
      }                                                                      \
      return true;                                                             \
    }                                                                          \
    void Deque_##t##_ctor(Deque_##t *deq, bool (*comp)(const t&, const t&)){   \
      Deque_##t d;                                                             \
      d.type_name=typeid(deq).name();                                          \
      d.front=&Deque_##t##_front;                                              \
      d.back=&Deque_##t##_back;                                                \
      d.at=&Deque_##t##_at;                                                    \
      d.size=&Deque_##t##_size;                                                \
      d.empty=&Deque_##t##_empty;                                              \
      d.push_back=&Deque_##t##_push_back;                                      \
      d.push_front=&Deque_##t##_push_front;                                    \
      d.begin=&Deque_##t##_Iterator_begin;                                     \
      d.end=&Deque_##t##_Iterator_end;                                         \
      d.pop_front=&Deque_##t##_pop_front;                                      \
      d.pop_back=&Deque_##t##_pop_back;                                        \
      d.clear=&Deque_##t##_clear;                                              \
      d.dtor=&Deque_##t##_dtor;                                                \
      d.sz=0;                                                                  \
      d.compare=comp;                                                          \
      d.equal=&Deque_##t##_equal;                                              \
      *deq=d;                                                                  \
    }                                                                          \
