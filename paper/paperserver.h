/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _PAPERSERVER_H_RPCGEN
#define _PAPERSERVER_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct add_article_in {
	char *author;
	char *title;
	struct {
		u_int content_len;
		char *content_val;
	} content;
};
typedef struct add_article_in add_article_in;

struct articles {
	long num;
	char *author;
	char *title;
	struct {
		u_int content_len;
		char *content_val;
	} content;
	struct articles *next;
};
typedef struct articles articles;

struct list_article_out {
	long num;
	char *author;
	char *title;
	struct list_article_out *next;
};
typedef struct list_article_out list_article_out;

struct article_info_out {
	char *author;
	char *title;
};
typedef struct article_info_out article_info_out;

struct fetch_article_out {
	struct {
		u_int content_len;
		char *content_val;
	} content;
};
typedef struct fetch_article_out fetch_article_out;

typedef long article_num;

struct info_res {
	int err;
	union {
		article_info_out info;
	} info_res_u;
};
typedef struct info_res info_res;

struct list_res {
	int err;
	union {
		list_article_out list;
	} list_res_u;
};
typedef struct list_res list_res;

#define PAPERSERVER_PROG 0x20004321
#define PAPERSERVER_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define ADD 1
extern  article_num * add_1(add_article_in *, CLIENT *);
extern  article_num * add_1_svc(add_article_in *, struct svc_req *);
#define LIST 2
extern  list_res * list_1(void *, CLIENT *);
extern  list_res * list_1_svc(void *, struct svc_req *);
#define INFO 3
extern  info_res * info_1(article_num *, CLIENT *);
extern  info_res * info_1_svc(article_num *, struct svc_req *);
#define REMOVE 4
extern  int * remove_1(article_num *, CLIENT *);
extern  int * remove_1_svc(article_num *, struct svc_req *);
#define FETCH 5
extern  fetch_article_out * fetch_1(article_num *, CLIENT *);
extern  fetch_article_out * fetch_1_svc(article_num *, struct svc_req *);
extern int paperserver_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define ADD 1
extern  article_num * add_1();
extern  article_num * add_1_svc();
#define LIST 2
extern  list_res * list_1();
extern  list_res * list_1_svc();
#define INFO 3
extern  info_res * info_1();
extern  info_res * info_1_svc();
#define REMOVE 4
extern  int * remove_1();
extern  int * remove_1_svc();
#define FETCH 5
extern  fetch_article_out * fetch_1();
extern  fetch_article_out * fetch_1_svc();
extern int paperserver_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_add_article_in (XDR *, add_article_in*);
extern  bool_t xdr_articles (XDR *, articles*);
extern  bool_t xdr_list_article_out (XDR *, list_article_out*);
extern  bool_t xdr_article_info_out (XDR *, article_info_out*);
extern  bool_t xdr_fetch_article_out (XDR *, fetch_article_out*);
extern  bool_t xdr_article_num (XDR *, article_num*);
extern  bool_t xdr_info_res (XDR *, info_res*);
extern  bool_t xdr_list_res (XDR *, list_res*);

#else /* K&R C */
extern bool_t xdr_add_article_in ();
extern bool_t xdr_articles ();
extern bool_t xdr_list_article_out ();
extern bool_t xdr_article_info_out ();
extern bool_t xdr_fetch_article_out ();
extern bool_t xdr_article_num ();
extern bool_t xdr_info_res ();
extern bool_t xdr_list_res ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_PAPERSERVER_H_RPCGEN */