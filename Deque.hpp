struct Container{
  String* arr;
};

struct Iterator{
  int index;
}

#define Deque_DEFINE(t)
  struct Deque_##var{
    void (*push_front)(var);
    void (*push_back)(var);
  };
  void Deque_##t##_ctor(Deque_##t *p, int i) {
    p = (Deque_##t *) malloc(i);
  }
