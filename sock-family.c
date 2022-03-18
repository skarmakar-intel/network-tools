#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ifaddrs.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <linux/ethtool.h>
#include <linux/sockios.h>
#include <net/if.h>


int main(int argc, char const *argv[]) {
  struct ifaddrs *ifaddr;
  int family =0;

  if (getifaddrs(&ifaddr) == -1) {
    printf("getifaddrs returned error\n");
    return -1;
  }
  if (!ifaddr)
  {
    printf("ifaddr pointer is NULL\n");
    return -1;
  }

  printf("Interfaces: Family (num value) Flags :\n");
  do
  {
    family = ifaddr->ifa_addr->sa_family;
    printf("%-8s %s (%d) %d \n",
                        ifaddr->ifa_name,
                        (family == AF_PACKET) ? "AF_PACKET" :
                        (family == AF_INET) ? "AF_INET" :
                        (family == AF_INET6) ? "AF_INET6" : "???",
                        family, ifaddr->ifa_flags);
    ifaddr= ifaddr->ifa_next;
  } while (ifaddr->ifa_next != NULL);

  // ethtool ioctls
  int fd, ictl;
  struct ifreq ifr;
  char  name[IFNAMSIZ] = "eno1";
  struct ethtool_cmd eth_cmd;

  fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd == -1) {
    printf("Error creating socket\n");
  }
  strncpy(ifr.ifr_name, name, sizeof ifr.ifr_name);

  // check if link is there
  struct ethtool_value link;

  link.cmd = ETHTOOL_GLINK;
  ifr.ifr_data = (char *)&link;
  ictl= ioctl(fd, SIOCETHTOOL, &ifr);
  if (ictl < 0)
  {
    printf("ioctl error\n");
  } else
  {
    printf("Link is %s \n",(link.data ==1) ? "Up":"Down");
  }

  // speed and duplex
  eth_cmd.cmd = ETHTOOL_GSET;
  ifr.ifr_data = (char *)&eth_cmd;
  ictl= ioctl(fd, SIOCETHTOOL, &ifr);
  if (ictl < 0)
  {
    printf("ioctl error\n");
  } else
  {
    printf("eno1 Speed %d Mbps Duplex: %s\n",eth_cmd.speed,
                        (eth_cmd.duplex ==1) ? "Full":"Half");
  }
}
