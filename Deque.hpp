struct Container{
  String* arr;
};

struct Iterator{
  int index;
}

#define Deque_DEFINE(t)                                                        \
    struct Deque_##t {                                                         \
        t type_name;                                                           \
        void (*push_front)(Deque_##t *deq, t item);                            \
        void (*push_back)(Deque_##t *deq, t item);                             \
        void (*dtor)(Deque_##t *p);                                            \
    };                                                                         \
    void Deque_##t##_dtor(Deque_##t *p){                                       \
    }                                                                          \
    void Deque_##t##_ctor(Deque_##t *p, int i) {                               \
      p = (Deque_##t *) malloc(i);                                             \
      p->type_name=t;                                                          \
      p->dtor=Deque_##t##_dtor;                                                \
    }                                                                          \
