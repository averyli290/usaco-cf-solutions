# address checks:	out-of-bounds access, use-after-free, memory leaks
# undefined checks: signed overflows, null dereferences, bad casts
# memory checks:	use of uninitialized memory
# -g checks: adds debug symbols so the sanitizer can show source line number, performance slows down (2x–3x)
#
# ON ERROR: CHECK STACK TRACE BELOW LINE SIMILAR TO
# ==79103==ERROR: AddressSanitizer: stack-buffer-underflow on address 0x00016d24ecfc at pc 0x000102bb5b48 bp 0x00016d24ecd0 sp 0x00016d24ecc8
#
g++ -std=c++17 -fsanitize=address -g a.cpp && ./a.out < input
g++ -std=c++17 -fsanitize=address,undefined -g a.cpp && ./a.out < input
g++ -std=c++17 -fsanitize=memory -g a.cpp && ./a.out < input

# normal run
g++ -std=c++17 a.cpp && ./a.out < input