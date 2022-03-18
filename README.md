# network-tools
Utilities for network device

sock-family: Enumerates available interfaces using getifaddrs, then opens a socket to the device and sends Ethtool IOCTL to get link details
Following is a sample o/p, the system had 1 wired and 1 wireless card, with wired card linked at 1 G

lo       AF_PACKET (17) 65609 
eno1     AF_PACKET (17) 69699 
wlp1s0   AF_PACKET (17) 69699 
lo       AF_INET (2) 65609 
eno1     AF_INET (2) 69699 
wlp1s0   AF_INET (2) 69699 
lo       AF_INET6 (10) 65609 
eno1     AF_INET6 (10) 69699 
Link is Up 
eno1 Speed 1000 Mbps Duplex: Full

