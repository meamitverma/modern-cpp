ate<typename Func, typename... Funcs>
void call(Func f, Funcs... fs) {
   f();
   call(fs...);
}