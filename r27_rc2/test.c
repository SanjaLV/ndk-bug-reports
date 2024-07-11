extern int printf(const char *fmt, ...);

int main() {
  void* bytecode[2];
  bytecode[0] = &&VM__OP_1;
  bytecode[1] = &&VM__TERMINATE;

  int state = 0;
  int index = 0;

  while (1) {
    switch (state) {
    case 0:
      goto *bytecode[index];
    case 1:
      // NOTE: THIS IS ONLY REACHABLE VIA INDIRECT GOTOS
      VM__OP_1:
      state = 2;
      break;
    case 2:
      printf("OP_1:(instruction=%d)\n", index);
      index++;
      goto *bytecode[index];
    }
  }

VM__TERMINATE:
  printf("TERMINATE:(instruction=%d)\n", index);
  return 0;
}
