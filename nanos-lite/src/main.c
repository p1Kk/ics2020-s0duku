#include <common.h>
#include <proc.h>

void init_mm(void);
void init_device(void);
void init_ramdisk(void);
void init_irq(void);
void init_fs(void);
void init_proc(void);
void naive_uload(PCB *pcb, const char *filename);

int main() {
  extern const char logo[];
  printf("%s", logo);
  Log("'Hello World!' from Nanos-lite");
  Log("Build time: %s, %s", __TIME__, __DATE__);

  init_mm();

  init_device();

  init_ramdisk();

#ifdef HAS_CTE
  init_irq();
#endif

  init_fs();

  init_proc();

  Log("Finish initialization");

  
  naive_uload(NULL, "/bin/menu");
  naive_uload(NULL, "/bin/hello");
  

#ifdef HAS_CTE
  yield();
#endif

  

  panic("Should not reach here");
}
