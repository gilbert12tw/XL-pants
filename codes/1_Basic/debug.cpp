void abc() { cerr << endl; }
template <typename T, typename... U>
void abc(T a, U... b) {
  cerr << a << ' ', abc(b...);
}
#ifdef debug
#define test(args...) abc("[" + string(#args) + "]", args)
#else
#define test(args...) void(0)
#endif
