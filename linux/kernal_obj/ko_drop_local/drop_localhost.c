#include <linux/module.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/netdevice.h> 

static struct nf_hook_ops netfilter_ops_in;

unsigned int netfilter_input_hook(unsigned int hooknum, struct sk_buff **skb,
                  const struct net_device *in, const struct net_device *out, 
                  int (*okfn)(struct skbuff*))
{
  char interface[] = "lo";
  if(strcmp(in->name, interface) == 0)
  { 
    printk(KERN_INFO "Dropping loopback ip packet");
    return NF_DROP; 
  }

  return NF_ACCEPT;
}


int init_module()
{
  netfilter_ops_in.hook = netfilter_input_hook;
  netfilter_ops_in.pf = PF_INET;
  netfilter_ops_in.hooknum =  NF_INET_PRE_ROUTING;
  netfilter_ops_in.priority               =       NF_IP_PRI_FIRST;
  nf_register_hook(&netfilter_ops_in);
  return 0;
}
void cleanup_module()
{
  nf_register_hook(&netfilter_ops_in);
}
