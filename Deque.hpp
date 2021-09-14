struct Container{
  String* arr;
};

struct Iter{
  unsigned long address;
}


#define Deque_DEFINE(var)
    struct Deque_##var{
      void (*push_front)(var);
      void (*push_back)(var);
    };
    
