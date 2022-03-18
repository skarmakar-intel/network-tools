# network-tools
Utilities for network device

sock-family: This enumerates the list of interfaces available and supported family using getifaddrs, then uses Ethtool IOCTL to get link details
Following sample o/p, the system had 1 wired and 1 wireless card, with wired card linked at 1 G

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

