#include <linux/linkage.h>
#include <linux/module.h>
#include <linux/irq.h>

asmlinkage long sys_read_int(void) {
  int i = 0;
  for (i = 0; i < 10; i++) {
    printk("posicao %d:\nirq: %d\thwirq: %d\tcount: %d\n\n",i, int_array[i].irq_number, int_array[i].hwirq_number, int_array[i].count);
  }
  return 0;
}

static int __init sys_int_init(void) {
  int i = 0;
  for (i = 0; i < 10; i++) {
    int_array[i].hwirq_number = -1;
    int_array[i].irq_number = -1;
    int_array[i].count = 0;
  }
  return 0;
}

static void __exit sys_int_exit(void)
{
  memset(int_array, 0, sizeof(int_array));
}

module_init(sys_int_init);
module_exit(sys_int_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Matheus Felix <matheus.felix.silva@usp.br>");
MODULE_AUTHOR("Bruno Eidi Nishimoto <bruno.nishimoto@usp.br>");
MODULE_DESCRIPTION("Simple interrupt array module");
