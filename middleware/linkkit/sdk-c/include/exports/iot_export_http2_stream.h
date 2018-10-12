/*
 * Copyright (C) 2015-2018 Alibaba Group Holding Limited
 */



#ifndef IOT_EXPORT_HTTP2_STREAM_H
#define IOT_EXPORT_HTTP2_STREAM_H
#include "iot_export_http2.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_HTTP2_HEADER_NUM                 (16)
#define EXT_HTTP2_HEADER_NUM                 (5)


typedef struct {
    char  *product_key;
    char  *device_name;
    char  *device_secret;
    char  *url;
    int   port;
} device_conn_info_t;

typedef struct {
    http2_header      nva[EXT_HTTP2_HEADER_NUM];
    int               num;
} header_ext_info_t;


typedef struct {
    char              *stream;
    uint32_t          stream_len;  //file content length
    uint32_t          send_len;   //data had sent length
    uint32_t          packet_len; //one packet length
    char              *identify;
} stream_data_info_t;


http2_connection_t *IOT_HTTP2_Stream_Connect( device_conn_info_t *conn_info);
int IOT_HTTP2_Stream_Open(http2_connection_t *connection, stream_data_info_t *info, header_ext_info_t *header);
int IOT_HTTP2_Stream_Send(http2_connection_t *connection, stream_data_info_t *info);
int IOT_HTTP2_Stream_Close(http2_connection_t *connection, stream_data_info_t *info);
int IOT_HTTP2_Stream_Ping(http2_connection_t *connection);
#ifdef __cplusplus
}
#endif

#endif /* IOT_EXPORT_FILE_UPLOADER_H */