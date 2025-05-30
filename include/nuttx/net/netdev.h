/****************************************************************************
 * include/nuttx/net/netdev.h
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: 2007, 2009, 2011-2018 Gregory Nutt. All rights reserved.
 * SPDX-FileCopyrightText: 2001-2003, Adam Dunkels. All rights reserved.
 * SPDX-FileContributor: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef __INCLUDE_NUTTX_NET_NETDEV_H
#define __INCLUDE_NUTTX_NET_NETDEV_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <sys/ioctl.h>
#include <stdint.h>

#include <nuttx/queue.h>

#include <net/if.h>
#include <net/ethernet.h>
#include <arpa/inet.h>

#include <nuttx/mm/iob.h>
#include <nuttx/net/netconfig.h>
#include <nuttx/net/net.h>
#include <nuttx/net/ip.h>
#include <nuttx/nuttx.h>

#ifdef CONFIG_NET_IGMP
#  include <nuttx/net/igmp.h>
#endif

#ifdef CONFIG_NET_MLD
#  include <nuttx/net/mld.h>
#endif

#ifndef CONFIG_NETDEV_STATISTICS_LOG_PERIOD
#  define CONFIG_NETDEV_STATISTICS_LOG_PERIOD 0
#endif

#if CONFIG_NETDEV_STATISTICS_LOG_PERIOD > 0
#  include <nuttx/wqueue.h>
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Determine the largest possible address */

#if defined(CONFIG_WIRELESS_IEEE802154) && defined(CONFIG_WIRELESS_PKTRADIO)
#  if CONFIG_PKTRADIO_ADDRLEN > 8
#    define RADIO_MAX_ADDRLEN CONFIG_PKTRADIO_ADDRLEN
#  else
#    define RADIO_MAX_ADDRLEN 8
#  endif
#elif defined(CONFIG_WIRELESS_IEEE802154)
#  define RADIO_MAX_ADDRLEN 8
#elif defined(CONFIG_WIRELESS_BLUETOOTH)
#  if CONFIG_PKTRADIO_ADDRLEN > 6
#    define RADIO_MAX_ADDRLEN CONFIG_PKTRADIO_ADDRLEN
#  else
#    define RADIO_MAX_ADDRLEN 6
#  endif
#else /* if defined(CONFIG_WIRELESS_PKTRADIO) */
#  define RADIO_MAX_ADDRLEN CONFIG_PKTRADIO_ADDRLEN
#endif

/* Helper macros for network device statistics */

#ifdef CONFIG_NETDEV_STATISTICS
#  define NETDEV_RESET_STATISTICS(dev) \
     memset(&(dev)->d_statistics, 0, sizeof(struct netdev_statistics_s))

#  define _NETDEV_STATISTIC(dev,name) ((dev)->d_statistics.name++)
#  define _NETDEV_ERROR(dev,name) \
     do \
       { \
         (dev)->d_statistics.name++; \
         (dev)->d_statistics.errors++; \
       } \
     while (0)

#define _NETDEV_BYTES(dev,name) \
    do { \
        (dev)->d_statistics.name += (dev)->d_len; \
    } while (0)

#  if CONFIG_NETDEV_STATISTICS_LOG_PERIOD > 0
#    define NETDEV_STATISTICS_WORK LPWORK
#    define _NETDEV_STATISTIC_LOG(dev,name) \
       do \
         { \
           _NETDEV_STATISTIC(dev,name); \
           if (work_available(&(dev)->d_statistics.logwork)) \
             { \
               work_queue(NETDEV_STATISTICS_WORK, \
                          &(dev)->d_statistics.logwork, \
                          netdev_statistics_log, (dev), \
                          SEC2TICK(CONFIG_NETDEV_STATISTICS_LOG_PERIOD)); \
             } \
         } \
       while (0)
#  else
#    define _NETDEV_STATISTIC_LOG(dev,name) _NETDEV_STATISTIC(dev,name)
#  endif

#  define NETDEV_RXPACKETS(dev) \
    do { \
        _NETDEV_STATISTIC_LOG(dev,rx_packets); \
        _NETDEV_BYTES(dev,rx_bytes); \
    } while (0)

#  define NETDEV_RXFRAGMENTS(dev) _NETDEV_STATISTIC(dev,rx_fragments)
#  define NETDEV_RXERRORS(dev)    _NETDEV_ERROR(dev,rx_errors)
#  ifdef CONFIG_NET_IPv4
#    define NETDEV_RXIPV4(dev)    _NETDEV_STATISTIC(dev,rx_ipv4)
#  else
#    define NETDEV_RXIPV4(dev)
#  endif
#  ifdef CONFIG_NET_IPv6
#    define NETDEV_RXIPV6(dev)    _NETDEV_STATISTIC(dev,rx_ipv6)
#  else
#    define NETDEV_RXIPV6(dev)
#  endif
#  ifdef CONFIG_NET_ARP
#    define NETDEV_RXARP(dev)     _NETDEV_STATISTIC(dev,rx_arp)
#  else
#    define NETDEV_RXARP(dev)
#  endif
#  define NETDEV_RXDROPPED(dev)   _NETDEV_STATISTIC(dev,rx_dropped)

#  define NETDEV_TXPACKETS(dev) \
    do { \
        _NETDEV_STATISTIC_LOG(dev,tx_packets); \
        _NETDEV_BYTES(dev,tx_bytes); \
    } while (0)

#  define NETDEV_TXDONE(dev)      _NETDEV_STATISTIC(dev,tx_done)
#  define NETDEV_TXERRORS(dev)    _NETDEV_ERROR(dev,tx_errors)
#  define NETDEV_TXTIMEOUTS(dev)  _NETDEV_ERROR(dev,tx_timeouts)
#  define NETDEV_ERRORS(dev)      _NETDEV_STATISTIC(dev,errors)

#else
#  define NETDEV_RESET_STATISTICS(dev)
#  define NETDEV_RXPACKETS(dev)
#  define NETDEV_RXFRAGMENTS(dev)
#  define NETDEV_RXERRORS(dev)
#  define NETDEV_RXIPV4(dev)
#  define NETDEV_RXIPV6(dev)
#  define NETDEV_RXARP(dev)
#  define NETDEV_RXDROPPED(dev)

#  define NETDEV_TXPACKETS(dev)
#  define NETDEV_TXDONE(dev)
#  define NETDEV_TXERRORS(dev)
#  define NETDEV_TXTIMEOUTS(dev)

#  define NETDEV_ERRORS(dev)
#endif

/* There are some helper pointers for accessing the contents of the IP
 * headers
 */

#define IPBUF(hl) ((FAR void *)(IOB_DATA(dev->d_iob) + (hl)))
#define NETLLBUF  ((FAR void *) \
                   ((FAR uint8_t *)IPBUF(0) - NET_LL_HDRLEN(dev)))

#define IPv4BUF ((FAR struct ipv4_hdr_s *)IPBUF(0))
#define IPv6BUF ((FAR struct ipv6_hdr_s *)IPBUF(0))

#ifdef CONFIG_NET_IPv6
#  ifndef CONFIG_NETDEV_MAX_IPv6_ADDR
#    define CONFIG_NETDEV_MAX_IPv6_ADDR 1
#  endif
#  define NETDEV_HAS_V6ADDR(dev) \
     (!net_ipv6addr_cmp(netdev_ipv6_srcaddr(dev, g_ipv6_unspecaddr), \
                        g_ipv6_unspecaddr))
#  define NETDEV_IS_MY_V6ADDR(dev,addr) \
     (netdev_ipv6_lookup(dev, addr, false) != NULL)
#  define NETDEV_V6ADDR_ONLINK(dev,addr) \
     (netdev_ipv6_lookup(dev, addr, true) != NULL)
#endif

/****************************************************************************
 * Public Types
 ****************************************************************************/

#ifdef CONFIG_NETDEV_STATISTICS
/* If CONFIG_NETDEV_STATISTICS is enabled and if the driver supports
 * statistics, then this structure holds the counts of network driver
 * events.
 */

struct netdev_statistics_s
{
  /* Rx Status */

  uint32_t rx_packets;     /* Number of packets received */
  uint32_t rx_fragments;   /* Number of fragments received */
  uint32_t rx_errors;      /* Number of receive errors */
#ifdef CONFIG_NET_IPv4
  uint32_t rx_ipv4;        /* Number of Rx IPv4 packets received */
#endif
#ifdef CONFIG_NET_IPv6
  uint32_t rx_ipv6;        /* Number of Rx IPv6 packets received */
#endif
#ifdef CONFIG_NET_ARP
  uint32_t rx_arp;         /* Number of Rx ARP packets received */
#endif
  uint32_t rx_dropped;     /* Unsupported Rx packets received */
  uint64_t rx_bytes;       /* Number of bytes received */

  /* Tx Status */

  uint32_t tx_packets;     /* Number of Tx packets queued */
  uint32_t tx_done;        /* Number of packets completed */
  uint32_t tx_errors;      /* Number of receive errors (incl timeouts) */
  uint32_t tx_timeouts;    /* Number of Tx timeout errors */
  uint64_t tx_bytes;       /* Number of bytes send */

  /* Other status */

  uint32_t errors;         /* Total number of errors */

#if CONFIG_NETDEV_STATISTICS_LOG_PERIOD > 0
  struct work_s logwork;   /* For periodic log work */
#endif
};
#endif

#if defined(CONFIG_NET_6LOWPAN) || defined(CONFIG_NET_BLUETOOTH) || \
    defined(CONFIG_NET_IEEE802154)
/* This structure is used to represent addresses of varying length.  This
 * structure is used to represent the address assigned to a radio.
 *
 * NOTE: the Bluetooth address is not variable, but shares struct
 * radio_driver_s which depends on this type.
 */

struct netdev_maxaddr_s
{
  uint8_t nm_addr[RADIO_MAX_ADDRLEN];
};

struct netdev_varaddr_s
{
  uint8_t nv_addr[RADIO_MAX_ADDRLEN];
  uint8_t nv_addrlen;
};
#endif

struct netdev_ifaddr6_s
{
  net_ipv6addr_t addr; /* Host IPv6 address */
  net_ipv6addr_t mask; /* Network IPv6 subnet mask */
};

#ifdef CONFIG_NETDEV_RSS
struct netdev_rss_s
{
  int      cpu;  /* CPU ID */
  uint32_t hash; /* Hash value with packet */
};
#endif // CONFIG_NETDEV_RSS

/* This structure collects information that is specific to a specific network
 * interface driver.  If the hardware platform supports only a single
 * instance of this structure.
 */

struct devif_callback_s; /* Forward reference */

struct net_driver_s
{
  /* This link is used to maintain a single-linked list of ethernet drivers.
   * Must be the first field in the structure due to blink type casting.
   */

#ifdef CONFIG_NET
  FAR struct net_driver_s *flink;

  /* This is the name of network device assigned when netdev_register was
   * called.
   * This name is only used to support socket ioctl lookups by device name
   * Examples: "eth0"
   */

  char d_ifname[IFNAMSIZ];
#endif

  /* Drivers interface flags.  See IFF_* definitions in include/net/if.h */

  uint32_t d_flags;

  /* Multi network devices using multiple link layer protocols are
   * supported
   */

  uint8_t d_lltype;             /* See enum net_lltype_e */
  uint8_t d_llhdrlen;           /* Link layer header size */
#ifdef CONFIG_NETDEV_IFINDEX
  uint8_t d_ifindex;            /* Device index */
#endif

  uint16_t d_pktsize;           /* Maximum packet size */

  /* Link layer address */

#if defined(CONFIG_NET_ETHERNET) || defined(CONFIG_NET_6LOWPAN) || \
    defined(CONFIG_NET_BLUETOOTH) || defined(CONFIG_NET_IEEE802154) || \
    defined(CONFIG_NET_TUN)
  union
  {
#  if defined(CONFIG_NET_ETHERNET) || defined(CONFIG_NET_TUN)
    /* Ethernet device identity */

    struct ether_addr ether;    /* Device Ethernet MAC address */
#  endif

#  if defined(CONFIG_NET_6LOWPAN) || defined(CONFIG_NET_BLUETOOTH) || \
      defined(CONFIG_NET_IEEE802154)
  /* The address assigned to an IEEE 802.15.4 or generic packet radio. */

    struct netdev_varaddr_s radio;
#  endif
  } d_mac;
#endif

  /* Network identity */

#ifdef CONFIG_NET_IPv4
  in_addr_t      d_ipaddr;      /* Host IPv4 address assigned to the network interface */
  in_addr_t      d_draddr;      /* Default router IP address */
  in_addr_t      d_netmask;     /* Network subnet mask */
#ifdef CONFIG_NET_ARP_ACD
  struct arp_acd_s d_acd;       /* ipv4 acd entry */
#endif /* CONFIG_NET_ARP_ACD */
#endif

#ifdef CONFIG_NET_IPv6
  /* Host IPv6 addresses assigned to the network interface.
   * For historical reason, we keep the old name d_ipv6addr and d_ipv6netmask
   * for backward compatibility. Please use d_ipv6 for new drivers.
   */

#  if defined(CONFIG_HAVE_ANONYMOUS_STRUCT) && \
      defined(CONFIG_HAVE_ANONYMOUS_UNION)
  union /* Try to limit the scope of backward compatibility alias. */
  {
    struct netdev_ifaddr6_s d_ipv6[CONFIG_NETDEV_MAX_IPv6_ADDR];
    struct
    {
      net_ipv6addr_t d_ipv6addr;    /* Compatible with previous usage */
      net_ipv6addr_t d_ipv6netmask; /* Compatible with previous usage */
    };
  };
#  else /* Without anonymous union/struct support, we can only use macros. */
  struct netdev_ifaddr6_s d_ipv6[CONFIG_NETDEV_MAX_IPv6_ADDR];
#    define d_ipv6addr    d_ipv6[0].addr /* Compatible with previous usage */
#    define d_ipv6netmask d_ipv6[0].mask /* Compatible with previous usage */
#  endif /* CONFIG_HAVE_ANONYMOUS_STRUCT && CONFIG_HAVE_ANONYMOUS_UNION */

  net_ipv6addr_t d_ipv6draddr;  /* Default router IPv6 address */
#endif /* CONFIG_NET_IPv6 */
  /* This is a new design that uses d_iob as packets input and output
   * buffer which used by some NICs such as celluler net driver. Case for
   * data input, note that d_iob maybe a linked chain only when using
   * d_iob to store reassembled datagrams, otherwise d_iob uses only
   * one buffer to hold the entire frame data. Case for data output, note
   * that d_iob also maybe a linked chain only when using d_iob to
   * store fragmented datagrams, otherwise d_iob uses only one buffer
   * to hold the entire frame data.
   *
   * In all cases mentioned above, d_buf always points to the beginning
   * of the first buffer of d_iob.
   */

  FAR struct iob_s *d_iob;

  /* Remember the outgoing fragments waiting to be sent */

#ifdef CONFIG_NET_IPFRAG
  FAR struct iob_queue_s d_fragout;
#endif

  /* The d_buf array is used to hold incoming and outgoing packets. The
   * device driver should place incoming data into this buffer.  When sending
   * data, the device driver should read the link level headers and the
   * TCP/IP headers from this buffer.  The size of the link level headers is
   * configured by the NET_LL_HDRLEN(dev) define.
   *
   * The network will handle only a single buffer for both incoming and
   * outgoing packets.  However, the driver design may be concurrently
   * sending and filling separate, break-off buffers.  That buffer
   * management must be controlled by the driver.
   *
   * The d_buf array must be aligned to two-byte, 16-bit address boundaries
   * in order to support aligned 16-bit accesses performed by the network.
   */

  FAR uint8_t *d_buf;

  /* d_appdata points to the location where application data can be read from
   * or written to in the packet buffer.
   */

  FAR uint8_t *d_appdata;

#ifdef CONFIG_NET_TCPURGDATA
  /* This pointer points to any urgent TCP data that has been received. Only
   * present if compiled with support for urgent data(CONFIG_NET_TCPURGDATA).
   */

  FAR uint8_t *d_urgdata;

  /* Length of the (received) urgent data */

  uint16_t d_urglen;
#endif

/* The length of the packet in the d_buf buffer.
 *
 * Holds the length of the packet in the d_buf buffer.
 *
 * When the network device driver calls the network input function,
 * d_len should be set to the length of the packet in the d_buf
 * buffer.
 *
 * When sending packets, the device driver should use the contents of
 * the d_len variable to determine the length of the outgoing
 * packet.
 */

  uint16_t d_len;

  /* When d_buf contains outgoing xmit data, d_sndlen is non-zero and
   * represents the amount of application data after d_appdata
   */

  uint16_t d_sndlen;

  /* Multicast group support */

#ifdef CONFIG_NET_IGMP
  sq_queue_t d_igmp_grplist;    /* IGMP group list */
#endif
#ifdef CONFIG_NET_MLD
  struct mld_netdev_s d_mld;    /* MLD state information */
#endif

#ifdef CONFIG_NETDEV_STATISTICS
  /* If CONFIG_NETDEV_STATISTICS is enabled and if the driver supports
   * statistics, then this structure holds the counts of network driver
   * events.
   */

  struct netdev_statistics_s d_statistics;
#endif

#if defined(CONFIG_NET_TIMESTAMP)
  /* Reception timestamp of packet being currently processed.
   * If CONFIG_ARCH_HAVE_NETDEV_TIMESTAMP is true, the timestamp is provided
   * by hardware driver. Otherwise it is filled in by kernel when packet
   * enters ipv4_input or ipv6_input.
   *
   * The timestamp is in CLOCK_REALTIME.
   */

  struct timespec d_rxtime;
#endif

  /* Application callbacks:
   *
   * Network device event handlers are retained in a 'list' and are called
   * for events specified in the flags set within struct devif_callback_s.
   *
   * There are two lists associated with each device:
   *
   *   1) d_conncb - For connection/port oriented events for certain
   *      socket-less packet transfers.  There events include:
   *
   *        ICMP data receipt:     ICMP_NEWDATA, ICMPv6_NEWDATA
   *        Driver Tx poll events: ARP_POLL, ICMP_POLL. ICMPv6_POLL
   *        IP Forwarding:         IPFWD_POLL
   *
   *   2) d_devcb - For non-data, device related events that apply to all
   *      transfers or connections involving this device:
   *
   *        NETDEV_DOWN - The network is down
   */

  FAR struct devif_callback_s *d_conncb;      /* This is the list head */
  FAR struct devif_callback_s *d_conncb_tail; /* This is the list tail */
  FAR struct devif_callback_s *d_devcb;

  /* Driver callbacks */

  CODE int (*d_ifup)(FAR struct net_driver_s *dev);
  CODE int (*d_ifdown)(FAR struct net_driver_s *dev);
  CODE int (*d_txavail)(FAR struct net_driver_s *dev);
#ifdef CONFIG_NET_MCASTGROUP
  CODE int (*d_addmac)(FAR struct net_driver_s *dev, FAR const uint8_t *mac);
  CODE int (*d_rmmac)(FAR struct net_driver_s *dev, FAR const uint8_t *mac);
#endif
#ifdef CONFIG_NETDEV_IOCTL
  CODE int (*d_ioctl)(FAR struct net_driver_s *dev, int cmd,
                      unsigned long arg);
#endif

  /* Drivers may attached device-specific, private information */

  FAR void *d_private;
};

typedef CODE int (*devif_poll_callback_t)(FAR struct net_driver_s *dev);
typedef CODE int (*devif_ipv6_callback_t)(FAR struct net_driver_s *dev,
                                          FAR struct netdev_ifaddr6_s *addr,
                                          FAR void *arg);

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Network device driver functions
 *
 * These functions are used by a network device driver for interacting
 * with the NuttX network.
 *
 * Process an incoming IP packet.
 *
 * This function should be called when the device driver has received
 * a packet from the network. The packet from the device driver must
 * be present in the d_buf buffer, and the length of the packet
 * should be placed in the d_len field.
 *
 * When the function returns, there may be an outbound packet placed
 * in the d_buf packet buffer. If so, the d_len field is set to
 * the length of the packet. If no packet is to be sent out, the
 * d_len field is set to 0.
 *
 * The usual way of calling the function is presented by the source
 * code below.
 *
 *     dev->d_len = devicedriver_poll();
 *     if (dev->d_len > 0)
 *       {
 *         ipv4_input(dev);
 *         if (dev->d_len > 0)
 *           {
 *             devicedriver_send();
 *           }
 *       }
 *
 * Note: If you are writing a network device driver that needs ARP
 * (Address Resolution Protocol), e.g., when running the network over
 * Ethernet, you will need to call the network ARP code before calling
 * this function:
 *
 *     dev->d_len = ethernet_devicedrver_poll();
 *     if (dev->d_len > 0)
 *       {
 *         if (ETHBUF->type == HTONS(ETHTYPE_IP))
 *           {
 *             arp_ipin();
 *             ipv4_input(dev);
 *             if (dev->d_len > 0)
 *               {
 *                 arp_out();
 *                 devicedriver_send();
 *               }
 *           }
 *         else if (ETHBUF->type == HTONS(ETHTYPE_ARP))
 *           {
 *             arp_input();
 *             if (dev->d_len > 0)
 *               {
 *                 devicedriver_send();
 *               }
 *           }
 *
 ****************************************************************************/

#ifdef CONFIG_NET_IPv4
int ipv4_input(FAR struct net_driver_s *dev);
#endif

#ifdef CONFIG_NET_IPv6
int ipv6_input(FAR struct net_driver_s *dev);
#endif

#ifdef CONFIG_NET_6LOWPAN
struct radio_driver_s;   /* Forward reference.  See radiodev.h */
struct iob_s;            /* Forward reference See iob.h */

int sixlowpan_input(FAR struct radio_driver_s *ieee,
                    FAR struct iob_s *framelist, FAR const void *metadata);
#endif

#ifdef CONFIG_NET_ARP

/****************************************************************************
 * Name: arp_input
 *
 * Description:
 *   This function should be called by the Ethernet device driver when an ARP
 *   packet has been received.   The function will act differently
 *   depending on the ARP packet type: if it is a reply for a request
 *   that we previously sent out, the ARP cache will be filled in with
 *   the values from the ARP reply.  If the incoming ARP packet is an ARP
 *   request for our IP address, an ARP reply packet is created and put
 *   into the d_buf buffer.
 *
 *   On entry, this function expects that an ARP packet with a prepended
 *   Ethernet header is present in the d_buf buffer and that the length of
 *   the packet is set in the d_len field.
 *
 *   When the function returns, the value of the field d_len indicates
 *   whether the device driver should send out the ARP reply packet or not.
 *   If d_len is zero, no packet should be sent; If d_len is non-zero, it
 *   contains the length of the outbound packet that is present in the d_buf
 *   buffer.
 *
 ****************************************************************************/

void arp_input(FAR struct net_driver_s *dev);

#else /* CONFIG_NET_ARP */

/* If ARP is disabled, stub out all ARP interfaces */

#  define arp_input(dev)

#endif /* CONFIG_NET_ARP */

/****************************************************************************
 * Polling of connections
 *
 * These functions will traverse each active network connection structure
 * and perform appropriate operations:  devif_poll() will perform TCP
 * and UDP polling operations. devif_poll() may be called asynchronously
 * from the network driver can accept another outgoing packet.
 *
 * In both cases, these functions will call the provided callback function
 * for every active connection. Polling will continue until all connections
 * have been polled or until the user-supplied function returns a non-zero
 * value (which it should do only if it cannot accept further write data).
 *
 * When the callback function is called, there may be an outbound packet
 * waiting for service in the device packet buffer, and if so the d_len field
 * is set to a value larger than zero. The device driver should then send
 * out the packet.
 *
 * Example:
 *   int driver_callback(FAR struct net_driver_s *dev)
 *   {
 *     if (dev->d_len > 0)
 *       {
 *         devicedriver_send();
 *         return 1; <-- Terminates polling if necessary
 *       }
 *     return 0;
 *   }
 *
 *   ...
 *   devif_poll(dev, driver_callback);
 *
 * Note: If you are writing a network device driver that needs ARP (Address
 * Resolution Protocol), e.g., when running the networ over Ethernet, you
 * will need to call the arp_out() function in the callback function
 * before sending the packet:
 *
 *   int driver_callback(FAR struct net_driver_s *dev)
 *   {
 *     if (dev->d_len > 0)
 *       {
 *         arp_out();
 *         devicedriver_send();
 *         return 1; <-- Terminates polling if necessary
 *       }
 *
 *     return 0;
 *   }
 *
 *   Compatible with all old flat buffer NICs
 *
 *                 tcp_poll()/udp_poll()/pkt_poll()/...(l3/l4)
 *                            /              \
 *                           /                \
 * devif_poll_[l3/l4]_connections()     devif_iob_send() (nocopy:udp/icmp/..)
 *            /                                   \      (copy:tcp)
 *           /                                     \
 *   devif_iob_poll(devif_poll_callback())  devif_poll_callback()
 *        /                                           \
 *       /                                             \
 *  devif_poll("NIC"_txpoll)                     "NIC"_send()(dev->d_buf)
 *
 ****************************************************************************/

int devif_poll(FAR struct net_driver_s *dev, devif_poll_callback_t callback);

/****************************************************************************
 * Name: neighbor_out
 *
 * Description:
 *   This function should be called before sending out an IPv6 packet. The
 *   function checks the destination IPv6 address of the IPv6 packet to see
 *   what L2 address that should be used as a destination L2 address.
 *
 *   If the destination IPv6 address is in the local network (determined
 *   by logical ANDing of netmask and our IPv6 address), the function
 *   checks the Neighbor Table to see if an entry for the destination IPv6
 *   address is found.  If so, an L2 header is prepended at the beginning
 *   of the packet and the function returns.
 *
 *   If no Neighbor Table entry is found for the destination IPv6 address,
 *   the packet in the d_buf is replaced by an ICMPv6 Neighbor Solicit
 *   request packet for the IPv6 address. The IPv6 packet is dropped and
 *   it is assumed that the higher level protocols (e.g., TCP) eventually
 *   will retransmit the dropped packet.
 *
 *   Upon return in either the case, a packet to be sent is present in the
 *   d_buf buffer and the d_len field holds the length of the L2 frame that
 *   should be transmitted.
 *
 ****************************************************************************/

#ifdef CONFIG_NET_IPv6
void neighbor_out(FAR struct net_driver_s *dev);
#endif /* CONFIG_NET_IPv6 */

/****************************************************************************
 * Name: netdev_ifup / netdev_ifdown
 *
 * Description:
 *   Bring the interface up/down
 *
 ****************************************************************************/

int netdev_ifup(FAR struct net_driver_s *dev);
int netdev_ifdown(FAR struct net_driver_s *dev);

/****************************************************************************
 * Carrier detection
 *
 * Call netdev_carrier_on when the carrier has become available and the
 * device is ready to receive/transmit packets.
 *
 * Call detdev_carrier_off when the carrier disappeared and the device has
 * moved into non operational state.
 *
 ****************************************************************************/

void netdev_carrier_on(FAR struct net_driver_s *dev);
void netdev_carrier_off(FAR struct net_driver_s *dev);

/****************************************************************************
 * Name: chksum
 *
 * Description:
 *   Calculate the raw change sum over the memory region described by
 *   data and len.
 *
 * Input Parameters:
 *   sum  - Partial calculations carried over from a previous call to
 *          chksum().  This should be zero on the first time that check
 *          sum is called.
 *   data - Beginning of the data to include in the checksum.
 *   len  - Length of the data to include in the checksum.
 *
 * Returned Value:
 *   The updated checksum value.
 *
 ****************************************************************************/

uint16_t chksum(uint16_t sum, FAR const uint8_t *data, uint16_t len);

/****************************************************************************
 * Name: chksum_iob
 *
 * Description:
 *   Calculate the Internet checksum over an iob chain buffer.
 *
 * Input Parameters:
 *   sum    - Partial calculations carried over from a previous call to
 *            chksum().  This should be zero on the first time that check
 *            sum is called.
 *   iob    - An iob chain buffer over which the checksum is to be computed.
 *   offset - Specifies the byte offset of the start of valid data.
 *
 * Returned Value:
 *   The updated checksum value.
 *
 ****************************************************************************/

uint16_t chksum_iob(uint16_t sum, FAR struct iob_s *iob, uint16_t offset);

/****************************************************************************
 * Name: net_chksum
 *
 * Description:
 *   Calculate the Internet checksum over a buffer.
 *
 *   The Internet checksum is the one's complement of the one's complement
 *   sum of all 16-bit words in the buffer.
 *
 *   See RFC1071.
 *
 *   If CONFIG_NET_ARCH_CHKSUM is defined, then this function must be
 *   provided by architecture-specific logic.
 *
 * Input Parameters:
 *
 *   buf - A pointer to the buffer over which the checksum is to be computed.
 *
 *   len - The length of the buffer over which the checksum is to be
 *         computed.
 *
 * Returned Value:
 *   The Internet checksum of the buffer.
 *
 ****************************************************************************/

uint16_t net_chksum(FAR uint16_t *data, uint16_t len);

/****************************************************************************
 * Name: net_chksum_iob
 *
 * Description:
 *   Calculate the Internet checksum over an iob chain buffer.
 *
 *   The Internet checksum is the one's complement of the one's complement
 *   sum of all 16-bit words in the buffer.
 *
 *   See RFC1071.
 *
 *   If CONFIG_NET_ARCH_CHKSUM is defined, then this function must be
 *   provided by architecture-specific logic.
 *
 * Input Parameters:
 *   sum    - Partial calculations carried over from a previous call to
 *            chksum().  This should be zero on the first time that check
 *            sum is called.
 *   iob    - An iob chain buffer over which the checksum is to be computed.
 *   offset - Specifies the byte offset of the start of valid data.
 *
 * Returned Value:
 *   The Internet checksum of the given iob chain buffer.
 *
 ****************************************************************************/

uint16_t net_chksum_iob(uint16_t sum, FAR struct iob_s *iob,
                        uint16_t offset);

#ifdef CONFIG_NET_IPv4

/****************************************************************************
 * Name: ipv4_upperlayer_header_chksum
 *
 * Description:
 *   Perform the checksum calculation over the IPv4, protocol headers,
 *   IP source and destination addresses
 *
 * Input Parameters:
 *   dev   - The network driver instance. The packet data is in the d_buf
 *           of the device.
 *   proto - The protocol being supported
 *
 * Returned Value:
 *   The calculated checksum with pseudo-header and IP source and
 *   destination addresses
 *
 ****************************************************************************/

uint16_t ipv4_upperlayer_header_chksum(FAR struct net_driver_s *dev,
                                       uint8_t proto);

/****************************************************************************
 * Name: ipv4_upperlayer_payload_chksum
 *
 * Description:
 *   Perform the checksum calculation over the iob data payload
 *
 * Input Parameters:
 *   dev   - The network driver instance. The packet data is in the d_buf
 *           of the device.
 *   sum   - The default checksum
 *
 * Returned Value:
 *   The calculated checksum with iob data payload and default checksum
 *
 ****************************************************************************/

uint16_t ipv4_upperlayer_payload_chksum(FAR struct net_driver_s *dev,
                                        uint16_t sum);

/****************************************************************************
 * Name: ipv4_upperlayer_chksum
 *
 * Description:
 *   Perform the checksum calculation over the IPv4, protocol headers, and
 *   data payload as necessary.
 *
 * Input Parameters:
 *   dev   - The network driver instance.  The packet data is in the d_buf
 *           of the device.
 *   proto - The protocol being supported
 *
 * Returned Value:
 *   The calculated checksum
 *
 ****************************************************************************/

uint16_t ipv4_upperlayer_chksum(FAR struct net_driver_s *dev, uint8_t proto);
#endif /* CONFIG_NET_IPv4 */

#ifdef CONFIG_NET_IPv6

/****************************************************************************
 * Name: ipv6_upperlayer_header_chksum
 *
 * Description:
 *   Perform the checksum calculation over the IPv6, protocol headers,
 *   IP source and destination addresses.
 *
 * Input Parameters:
 *   dev   - The network driver instance.  The packet data is in the d_buf
 *           of the device.
 *   proto - The protocol being supported
 *   iplen - The size of the IPv6 header.  This may be larger than
 *           IPv6_HDRLEN the IPv6 header if IPv6 extension headers are
 *           present.
 *
 * Returned Value:
 *   The calculated checksum
 *
 ****************************************************************************/

uint16_t ipv6_upperlayer_header_chksum(FAR struct net_driver_s *dev,
                                       uint8_t proto, unsigned int iplen);

/****************************************************************************
 * Name: ipv6_upperlayer_payload_chksum
 *
 * Description:
 *   Perform the checksum calculation over the iob data payload and
 *   default checksum.
 *
 * Input Parameters:
 *   dev   - The network driver instance.  The packet data is in the d_buf
 *           of the device.
 *   proto - The protocol being supported
 *   iplen - The size of the IPv6 header.  This may be larger than
 *           IPv6_HDRLEN the IPv6 header if IPv6 extension headers are
 *           present.
 *
 * Returned Value:
 *   The calculated checksum
 *
 ****************************************************************************/

uint16_t ipv6_upperlayer_payload_chksum(FAR struct net_driver_s *dev,
                                        unsigned int iplen, uint16_t sum);

/****************************************************************************
 * Name: ipv6_upperlayer_chksum
 *
 * Description:
 *   Perform the checksum calculation over the IPv6, protocol headers, and
 *   data payload as necessary.
 *
 * Input Parameters:
 *   dev   - The network driver instance.  The packet data is in the d_buf
 *           of the device.
 *   proto - The protocol being supported
 *   iplen - The size of the IPv6 header.  This may be larger than
 *           IPv6_HDRLEN the IPv6 header if IPv6 extension headers are
 *           present.
 *
 * Returned Value:
 *   The calculated checksum
 *
 ****************************************************************************/

uint16_t ipv6_upperlayer_chksum(FAR struct net_driver_s *dev,
                                uint8_t proto, unsigned int iplen);
#endif /* CONFIG_NET_IPv6 */

/****************************************************************************
 * Name: ipv4_chksum
 *
 * Description:
 *   Calculate the IPv4 header checksum of the packet header in d_buf.
 *
 *   The IPv4 header checksum is the Internet checksum of the 20 bytes of
 *   the IPv4 header.
 *
 *   If CONFIG_NET_ARCH_CHKSUM is defined, then this function must be
 *   provided by architecture-specific logic.
 *
 * Returned Value:
 *   The IPv4 header checksum of the IPv4 header in the d_buf buffer.
 *
 ****************************************************************************/

#ifdef CONFIG_NET_IPv4
uint16_t ipv4_chksum(FAR struct ipv4_hdr_s *ipv4);
#endif /* CONFIG_NET_IPv4 */

/****************************************************************************
 * Name: net_incr32
 *
 * Description:
 *
 *   Carry out a 32-bit addition.
 *
 *   By defining CONFIG_NET_ARCH_INCR32, the architecture can replace
 *   net_incr32 with hardware assisted solutions.
 *
 * Input Parameters:
 *   op32 - A pointer to a 4-byte array representing a 32-bit integer in
 *          network byte order (big endian).  This value may not be word
 *          aligned. The value pointed to by op32 is modified in place
 *
 *   op16 - A 16-bit integer in host byte order.
 *
 ****************************************************************************/

void net_incr32(FAR uint8_t *op32, uint16_t op16);

/****************************************************************************
 * Name: netdev_ipv4_hdrlen
 *
 * Description:
 *    Provide header length for interface based on device
 *
 * Input Parameters:
 *   dev Device structure pointer
 *
 ****************************************************************************/

#ifdef CONFIG_NET_IPv4
#  define netdev_ipv4_hdrlen(dev) (dev->d_llhdrlen)
#endif /* CONFIG_NET_IPv4 */

/****************************************************************************
 * Name: netdev_ipv6_hdrlen
 *
 * Description:
 *    Provide header length for interface based on device
 *
 * Input Parameters:
 *   dev Device structure pointer
 *
 ****************************************************************************/

#ifdef CONFIG_NET_IPv6
#  define netdev_ipv6_hdrlen(dev) dev->d_llhdrlen
#endif /* CONFIG_NET_IPv6 */

/****************************************************************************
 * Name: netdev_lladdrsize
 *
 * Description:
 *   Returns the size of the MAC address associated with a network device.
 *
 * Input Parameters:
 *   dev - A reference to the device of interest
 *
 * Returned Value:
 *   The size of the MAC address associated with this device
 *
 ****************************************************************************/

int netdev_lladdrsize(FAR struct net_driver_s *dev);

/****************************************************************************
 * Name: netdev_iob_prepare
 *
 * Description:
 *   Prepare data buffer for a given NIC
 *   The iob offset will be updated to l2 gruard size by default:
 *  ----------------------------------------------------------------
 *  |                     iob entry                                |
 *  ---------------------------------------------------------------|
 *  |<--- CONFIG_NET_LL_GUARDSIZE -->|<--- io_len/io_pktlen(0) --->|
 *  ---------------------------------------------------------------|
 *
 * Assumptions:
 *   The caller has locked the network.
 *
 * Returned Value:
 *   A non-zero copy is returned on success.
 *
 ****************************************************************************/

int netdev_iob_prepare(FAR struct net_driver_s *dev, bool throttled,
                       unsigned int timeout);

/****************************************************************************
 * Name: netdev_iob_prepare_dynamic
 *
 * Description:
 *   Pre-alloc the iob for the data to be sent.
 *
 * Assumptions:
 *   The caller has locked the network.
 *
 ****************************************************************************/

#ifdef CONFIG_IOB_ALLOC
void netdev_iob_prepare_dynamic(FAR struct net_driver_s *dev, uint16_t size);
#endif

/****************************************************************************
 * Name: netdev_iob_replace
 *
 * Description:
 *   Replace buffer resources for a given NIC
 *
 * Assumptions:
 *   The caller has locked the network and new iob is prepared with
 *   l2 gruard size as offset.
 *
 ****************************************************************************/

void netdev_iob_replace(FAR struct net_driver_s *dev, FAR struct iob_s *iob);

/****************************************************************************
 * Name: netdev_iob_clear
 *
 * Description:
 *   Clean up buffer resources for a given NIC
 *
 * Assumptions:
 *   The caller has locked the network and dev->d_iob has been
 *   released or taken away.
 *
 ****************************************************************************/

void netdev_iob_clear(FAR struct net_driver_s *dev);

/****************************************************************************
 * Name: netdev_iob_release
 *
 * Description:
 *   Release buffer resources for a given NIC
 *
 * Assumptions:
 *   The caller has locked the network.
 *
 ****************************************************************************/

void netdev_iob_release(FAR struct net_driver_s *dev);

/****************************************************************************
 * Name: netdev_iob_clone
 *
 * Description:
 *   Backup the current iob buffer for a given NIC by cloning it.
 *
 * Assumptions:
 *   The caller has locked the network.
 *
 ****************************************************************************/

FAR struct iob_s *netdev_iob_clone(FAR struct net_driver_s *dev,
                                   bool throttled);

/****************************************************************************
 * Name: netdev_ipv6_add/del
 *
 * Description:
 *   Add or delete an IPv6 address on the network device
 *
 * Returned Value:
 *   OK             - Success
 *   -EINVAL        - Invalid prefix length
 *   -EADDRNOTAVAIL - Delete on non-existent address
 *
 * Assumptions:
 *   The caller has locked the network.
 *
 ****************************************************************************/

#ifdef CONFIG_NET_IPv6
int netdev_ipv6_add(FAR struct net_driver_s *dev, const net_ipv6addr_t addr,
                    unsigned int preflen);
int netdev_ipv6_del(FAR struct net_driver_s *dev, const net_ipv6addr_t addr,
                    unsigned int preflen);
#endif

/****************************************************************************
 * Name: netdev_ipv6_srcaddr/srcifaddr
 *
 * Description:
 *   Get the source IPv6 address (RFC6724) to use for transmitted packets.
 *   If we are responding to a received packet, use the destination address
 *   from that packet. If we are initiating communication, pick a local
 *   address that best matches the destination address.
 *
 * Input parameters:
 *   dev - Network device that packet is being transmitted from
 *   dst - Address to compare against when choosing local address.
 *
 * Returned Value:
 *   A pointer to a net_ipv6addr_t contained in net_driver_s is returned on
 *   success.  It will never be NULL, but can be an address containing
 *   g_ipv6_unspecaddr.
 *
 * Assumptions:
 *   The caller has locked the network.
 *
 ****************************************************************************/

#ifdef CONFIG_NET_IPv6
FAR const uint16_t *netdev_ipv6_srcaddr(FAR struct net_driver_s *dev,
                                        const net_ipv6addr_t dst);
FAR const struct netdev_ifaddr6_s *
netdev_ipv6_srcifaddr(FAR struct net_driver_s *dev,
                      const net_ipv6addr_t dst);
#endif

/****************************************************************************
 * Name: netdev_ipv6_lladdr
 *
 * Description:
 *   Get the link-local address of the network device.
 *
 * Returned Value:
 *   A pointer to the link-local address is returned on success.
 *   NULL is returned if the address is not found on the device.
 *
 * Assumptions:
 *   The caller has locked the network.
 *
 ****************************************************************************/

#ifdef CONFIG_NET_IPv6
FAR const uint16_t *netdev_ipv6_lladdr(FAR struct net_driver_s *dev);
#endif

/****************************************************************************
 * Name: netdev_ipv6_lookup
 *
 * Description:
 *   Look up an IPv6 address in the network device's IPv6 addresses
 *
 * Input Parameters:
 *   dev     - The network device to use in the lookup
 *   addr    - The IPv6 address to be looked up
 *   maskcmp - If true, then the IPv6 address is compared to the network
 *             device's IPv6 addresses with mask compare.
 *             If false, then the IPv6 address should be exactly the same as
 *             the network device's IPv6 address.
 *
 * Returned Value:
 *   A pointer to the matching IPv6 address entry is returned on success.
 *   NULL is returned if the IPv6 address is not found in the device.
 *
 * Assumptions:
 *   The caller has locked the network.
 *
 ****************************************************************************/

#ifdef CONFIG_NET_IPv6
FAR struct netdev_ifaddr6_s *
netdev_ipv6_lookup(FAR struct net_driver_s *dev, const net_ipv6addr_t addr,
                   bool maskcmp);
#endif

/****************************************************************************
 * Name: netdev_ipv6_foreach
 *
 * Description:
 *   Enumerate each IPv6 address on a network device.  This function will
 *   terminate when either (1) all addresses have been enumerated or (2) when
 *   a callback returns any non-zero value.
 *
 * Input Parameters:
 *   dev      - The network device
 *   callback - Will be called for each IPv6 address
 *   arg      - Opaque user argument passed to callback()
 *
 * Returned Value:
 *  Zero:     Enumeration completed
 *  Non-zero: Enumeration terminated early by callback
 *
 * Assumptions:
 *  The network is locked.
 *
 ****************************************************************************/

#ifdef CONFIG_NET_IPv6
int netdev_ipv6_foreach(FAR struct net_driver_s *dev,
                        devif_ipv6_callback_t callback, FAR void *arg);
#endif

/****************************************************************************
 * Name: netdev_statistics_log
 *
 * Description:
 *   The actual implementation of the network statistics logging.  Log
 *   network statistics at regular intervals.
 *
 * Input Parameters:
 *   arg - The pointer to the network device
 *
 ****************************************************************************/

#if CONFIG_NETDEV_STATISTICS_LOG_PERIOD > 0
void netdev_statistics_log(FAR void *arg);
#endif

#endif /* __INCLUDE_NUTTX_NET_NETDEV_H */
