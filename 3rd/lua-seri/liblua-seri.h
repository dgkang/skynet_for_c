#ifndef SKYNET_LIBLUA_SERI_H
#define SKYNET_LIBLUA_SERI_H

#define LS_TYPE_NIL 0
#define LS_TYPE_BOOLEAN 1
// hibits 0 false 1 true
#define LS_TYPE_NUMBER 2
// hibits 0 : 0 , 1: byte, 2:word, 4: dword, 6: qword, 8 : double
#define LS_TYPE_NUMBER_ZERO 0
#define LS_TYPE_NUMBER_BYTE 1
#define LS_TYPE_NUMBER_WORD 2
#define LS_TYPE_NUMBER_DWORD 4
#define LS_TYPE_NUMBER_QWORD 6
#define LS_TYPE_NUMBER_REAL 8

#define LS_TYPE_USERDATA 3
#define LS_TYPE_SHORT_STRING 4
// hibits 0~31 : len
#define LS_TYPE_LONG_STRING 5
#define LS_TYPE_TABLE 6

struct lua_seri_handle;

struct lua_seri_handle* lua_seri_init();

void lua_seri_free(struct lua_seri_handle*);

void lua_seri_push_string(struct lua_seri_handle* h, const char *str, int len);

void lua_seri_push_integer(struct lua_seri_handle* h, int v);

void lua_seri_push_real(struct lua_seri_handle* h, double v);

void* lua_seri_buffer(struct lua_seri_handle* h);

void lua_seri_buffer_free(void* buf);

int lua_seri_buffer_len(struct lua_seri_handle* h);

#endif //SKYNET_LIBLUA_SERI_H