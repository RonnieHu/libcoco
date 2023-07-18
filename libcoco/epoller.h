#ifndef _EPOLLER_H_
#define _EPOLLER_H_


class Epoller {
public:
    static int epoll_init();
    static int epoll_ev_register();
    static int epoll_wait_for(uint64_t interval);
};


#endif
