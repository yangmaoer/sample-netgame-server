#ifndef client_socket_h
#define client_socket_h

#include <netinet/in.h>

struct socket;

int socket_connect(const char * addr, int port, struct socket **s);

int64_t socket_send(struct socket *s, const void * buffer, int sz);

int socket_send_remainbuffer(struct socket *s);

typedef int (*dispatch_cb)(const char * buffer, int size);
void socket_msgdispatch(struct socket * s, dispatch_cb);

#endif
