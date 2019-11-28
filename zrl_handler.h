#ifndef HANDLER_H
#define HANDLER_H
#include"utility.h"

int listen_handler(conn_ctx*ctx);
int conn_handler(conn_ctx*ctx);
int request_handler(conn_ctx*ctx);
int response_handler(conn_ctx*ctx);


#endif