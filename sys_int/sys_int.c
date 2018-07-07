#include <linux/linkage.h>
#include <linux/module.h>

struct int_data {
  int hwirq_number;
  int irq_number;
  int count;
};

static int int_array[4] = {1, 2, 3, 4 };

asmlinkage long sys_read_int(void) {
  int i = 0;
  for (i = 0; i < 4; i++) {
    printk("%d", int_array[i]);
  }
  printk("\n");
  return 0;
}

static int __init sys_int_init(void) {
  int_array[0] = 0;
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
