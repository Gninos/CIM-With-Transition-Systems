/* Created Wed Oct 23 23:27:51 2019 by frac version 2.5.0 */

#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

/* tts API version */
int ttsapiversion () {return 2;}

/* provider */
char *source_info[3] = {"frac","2.5.0","Wed Oct 23 23:27:51 2019"};
char **sourceinfo () {return source_info;}

/* fiacre and private headers */
#include "intersection.h"

/* storage headers */
#include "pack.h"
#include "store.h"

static storage_t values_storage;
#ifdef SHARE
static storage_t a2_storage;
static storage_t a3_storage;
#endif
#define lookup(s)   lookup_data(&values_storage,s)
#define store(v)    store_data(&values_storage,v)

static int avail;    /* for sprint_* */
static char tmpbuff[16]; /* for sprint_* */

/* utilities for structure a0 */

static int compare_a0 (struct a0 e1, struct a0 e2) {
  size_t i = 0;
  for (i=0; i<4; i++) {
    if ((e1.at[i]) < (e2.at[i])) return -1;
    if ((e1.at[i]) > (e2.at[i])) return 1;
  }
  return 0;
}

static char *sprint_a0 (char *buff, struct a0 *e, const struct pmap *pmap) {
  int j0;
  PUTS(pmap->a.l);
  for (j0=0; j0<4; j0++) {
    if (j0) {PUTS(pmap->a.s);}
    PUTV("%d",e->at[j0]);
  }
  PUTS(pmap->a.r);
  return buff;
}

static size_t pack_a0 (struct a0* a, char* data) {
  const char* orig = data;
  size_t i = 0;
  for (i = 0; i < 4; ++i) {
    data += pack_int(a->at[i], data);
  }
  return data - orig;
}

static size_t unpack_a0 (struct a0* a, char* data) {
  const char* orig = data;
  size_t i = 0;
  for (i = 0; i < 4; ++i) {
    data += unpack_int(&(a->at[i]), data);
  }
  return data - orig;
}

/* utilities for structure a1 */

static int compare_a1 (struct a1 e1, struct a1 e2) {
  size_t i = 0;
  for (i=0; i<2; i++) {
    if ((e1.at[i]) < (e2.at[i])) return -1;
    if ((e1.at[i]) > (e2.at[i])) return 1;
  }
  return 0;
}

static char *sprint_a1 (char *buff, struct a1 *e, const struct pmap *pmap) {
  int j1;
  PUTS(pmap->a.l);
  for (j1=0; j1<2; j1++) {
    if (j1) {PUTS(pmap->a.s);}
    PUTV("%hhd",e->at[j1]);
  }
  PUTS(pmap->a.r);
  return buff;
}

static size_t pack_a1 (struct a1* a, char* data) {
  const char* orig = data;
  size_t i = 0;
  for (i = 0; i < 2; ++i) {
    data += pack_char(a->at[i], data);
  }
  return data - orig;
}

static size_t unpack_a1 (struct a1* a, char* data) {
  const char* orig = data;
  size_t i = 0;
  for (i = 0; i < 2; ++i) {
    data += unpack_char(&(a->at[i]), data);
  }
  return data - orig;
}

/* utilities for structure a2 */

static int compare_a2 (struct a2 e1, struct a2 e2) {
  size_t i = 0;
  for (i=0; i<8; i++) {
    if ((e1.at[i]) < (e2.at[i])) return -1;
    if ((e1.at[i]) > (e2.at[i])) return 1;
  }
  return 0;
}

static char *sprint_a2 (char *buff, struct a2 *e, const struct pmap *pmap) {
  int j2;
  PUTS(pmap->a.l);
  for (j2=0; j2<8; j2++) {
    if (j2) {PUTS(pmap->a.s);}
    PUTV("%d",e->at[j2]);
  }
  PUTS(pmap->a.r);
  return buff;
}

static size_t pack_a2 (struct a2* a, char* data) {
  const char* orig = data;
  size_t i = 0;
  for (i = 0; i < 8; ++i) {
    data += pack_int(a->at[i], data);
  }
  return data - orig;
}

static size_t unpack_a2 (struct a2* a, char* data) {
  const char* orig = data;
  size_t i = 0;
  for (i = 0; i < 8; ++i) {
    data += unpack_int(&(a->at[i]), data);
  }
  return data - orig;
}

#ifdef SHARE
void pack_with_size_a2 (struct a2* x, char* data) {
  unsigned char size = sizeof(unsigned char);
  size += pack_a2(x,data + size);
  *(unsigned char *)data = size;
}

void unpack_with_size_a2 (struct a2* x, char* data) {
  unpack_a2(x,data + sizeof(unsigned char));
}

size_t size_a2 (char* data) {
  return *(unsigned char *)data;
}

#define pack_shared_a2(x,data)   pack_key(&a2_storage,x,data)
#define unpack_shared_a2(x,data) unpack_key(&a2_storage,x,data)

#else
#define pack_shared_a2(x,data)   pack_a2(x,data)
#define unpack_shared_a2(x,data) unpack_a2(x,data)
#endif

/* utilities for structure a3 */

static int compare_a3 (struct a3 e1, struct a3 e2) {
  size_t i = 0;
  for (i=0; i<8; i++) {
    {int r = compare_a2(e1.at[i],e2.at[i]); if (r) return r;}
  }
  return 0;
}

static char *sprint_a3 (char *buff, struct a3 *e, const struct pmap *pmap) {
  int j3;
  PUTS(pmap->a.l);
  for (j3=0; j3<8; j3++) {
    if (j3) {PUTS(pmap->a.s);}
    buff = sprint_a2 (buff,&e->at[j3],pmap);
  }
  PUTS(pmap->a.r);
  return buff;
}

static size_t pack_a3 (struct a3* a, char* data) {
  const char* orig = data;
  size_t i = 0;
  for (i = 0; i < 8; ++i) {
    data += pack_shared_a2(&a->at[i], data);
  }
  return data - orig;
}

static size_t unpack_a3 (struct a3* a, char* data) {
  const char* orig = data;
  size_t i = 0;
  for (i = 0; i < 8; ++i) {
    data += unpack_shared_a2(&(a->at[i]), data);
  }
  return data - orig;
}

#ifdef SHARE
void pack_with_size_a3 (struct a3* x, char* data) {
  unsigned char size = sizeof(unsigned char);
  size += pack_a3(x,data + size);
  *(unsigned char *)data = size;
}

void unpack_with_size_a3 (struct a3* x, char* data) {
  unpack_a3(x,data + sizeof(unsigned char));
}

size_t size_a3 (char* data) {
  return *(unsigned char *)data;
}

#define pack_shared_a3(x,data)   pack_key(&a3_storage,x,data)
#define unpack_shared_a3(x,data) unpack_key(&a3_storage,x,data)

#else
#define pack_shared_a3(x,data)   pack_a3(x,data)
#define unpack_shared_a3(x,data) unpack_a3(x,data)
#endif

/* Fiacre function coordinate */
struct a1 fcr_coordinate (char ti, struct a0 pxi, struct a0 pyi) {
    char xi; char yi; 
    xi=0; 
    yi=0; 
    {struct a1 a1; 
    if ((ti < 4)) {
      xi=pxi.at[ti]; 
      yi=pyi.at[ti]; 
      {struct a1 a0; 
      return ({a0.at[0]=xi; a0.at[1]=yi; a0;});
      }
    } else {
      return ({a1.at[0]=xi; a1.at[1]=yi; a1;});
    }
    }
}

/* Fiacre function cav */
int fcr_cav (char ti) {
    int vi; 
    vi=0; 
    if ((ti < 4)) {
      {struct a0 a2; 
      vi=({a2.at[0]=2; a2.at[1]=3; a2.at[2]=4; a2.at[3]=5; a2;}).at[ti]; 
      }
      return vi;
    } else {
      return vi;
    }
}

/* Fiacre function road */
int fcr_road (int vi) {
    int ri; 
    ri=0; 
    if ((vi == 2)) {
      ri=1; 
      return ri;
    } else {
      if ((vi == 3)) {
        ri=2; 
        return ri;
      } else {
        if ((vi == 4)) {
          ri=3; 
          return ri;
        } else {
          if ((vi == 5)) {
            ri=4; 
            return ri;
          } else {
            return ri;
          }
        }
      }
    }
}

/* Fiacre function oo */
struct a0 fcr_oo () {
    struct a0 oi; char i; 
    oi.at[0]=0; 
    oi.at[1]=0; 
    oi.at[2]=0; 
    oi.at[3]=0; 
    i=0; 
    for (i=0;i<=3;i++) {
      oi.at[i]=0; 
    }
    i--;
    return oi;
}

/* Process intersection_1 */

/* state type */

struct value {
  struct a0 intersection_1_vpx;
  struct a0 intersection_1_vpy;
  char intersection_1_vt;
  struct a3 intersection_1_va;
};

/* utilities for structure value */

int compare_value (struct value *e1, struct value *e2) {
  {int r = compare_a0(e1->intersection_1_vpx,e2->intersection_1_vpx); if (r) return r;}
  {int r = compare_a0(e1->intersection_1_vpy,e2->intersection_1_vpy); if (r) return r;}
  if ((e1->intersection_1_vt) < (e2->intersection_1_vt)) return -1;
  if ((e1->intersection_1_vt) > (e2->intersection_1_vt)) return 1;
  {int r = compare_a3(e1->intersection_1_va,e2->intersection_1_va); if (r) return r;}
  return 0;
}

static int sprint_value (int sz, char *buff, key s, const struct pmap *pmap) {
  struct value *v = lookup(s);
  avail = sz - 1;
  /* prints state into buff: */
  PUTS(pmap->r.l);
  PUTN(18,pmap->n,"intersection_1_vpx"); PUTS(pmap->r.b); buff = sprint_a0 (buff,&v->intersection_1_vpx,pmap);
  PUTS(pmap->r.s);
  PUTN(18,pmap->n,"intersection_1_vpy"); PUTS(pmap->r.b); buff = sprint_a0 (buff,&v->intersection_1_vpy,pmap);
  PUTS(pmap->r.s);
  PUTN(17,pmap->n,"intersection_1_vt"); PUTS(pmap->r.b); PUTV("%hhd",v->intersection_1_vt);
  PUTS(pmap->r.s);
  PUTN(17,pmap->n,"intersection_1_va"); PUTS(pmap->r.b); buff = sprint_a3 (buff,&v->intersection_1_va,pmap);
  PUTS(pmap->r.r);
  return (avail<0) ? -1 : (sz - avail - 1);
}

int sprint_state (int sz, char *buff, key s) {
  return sprint_value (sz, buff, s, &fcrPmap);
}

int sprint_json_state (int sz, char *buff, key s) {
  return sprint_value (sz, buff, s, &jsonPmap);
}

size_t pack_value (struct value* v, char* data) {
  const char* orig = data;
  data += pack_a0(&v->intersection_1_vpx, data);
  data += pack_a0(&v->intersection_1_vpy, data);
  data += pack_char(v->intersection_1_vt, data);
  data += pack_shared_a3(&v->intersection_1_va, data);
  return data - orig;
}

size_t unpack_value (struct value* v, char* data) {
  const char* orig = data;
  data += unpack_a0(&(v->intersection_1_vpx), data);
  data += unpack_a0(&(v->intersection_1_vpy), data);
  data += unpack_char(&(v->intersection_1_vt), data);
  data += unpack_shared_a3(&(v->intersection_1_va), data);
  return data - orig;
}


void pack_with_size_value (struct value* v, char* data) {
#ifdef SHARE
  unsigned char size = sizeof(unsigned char);
#else
  unsigned short size = sizeof(int) + sizeof(unsigned short);
#endif
  size += pack_value(v,data + size);
#ifdef SHARE
  *(unsigned char *)data = size;
#else
  *(unsigned short *)(data + sizeof(int)) = size;
  MurmurHash3_x86_32(data + sizeof(int), size - sizeof(int), 42, (void*)data);
#endif
}

void unpack_with_size_value (struct value* v, char* data) {
#ifdef SHARE
  unpack_value(v,data + sizeof(unsigned char));
#else
  unpack_value(v,data + sizeof(int) + sizeof(unsigned short));
#endif
}

size_t size_value(char* data) {
#ifdef SHARE
  return *(unsigned char *)(data);
#else
  return *(unsigned short *)(data + sizeof(int));
#endif
}

/* initializes temporaries and creates initial state */
key initial() {
  struct value start;
  /* state variables: */
  start.intersection_1_vpx.at[0]=2;
  start.intersection_1_vpx.at[1]=1;
  start.intersection_1_vpx.at[2]=4;
  start.intersection_1_vpx.at[3]=6;
  start.intersection_1_vpy.at[0]=1;
  start.intersection_1_vpy.at[1]=2;
  start.intersection_1_vpy.at[2]=6;
  start.intersection_1_vpy.at[3]=3;
  start.intersection_1_vt=0;
  start.intersection_1_va.at[0].at[0]=1;
  start.intersection_1_va.at[0].at[1]=1;
  start.intersection_1_va.at[0].at[2]=0;
  start.intersection_1_va.at[0].at[3]=0;
  start.intersection_1_va.at[0].at[4]=0;
  start.intersection_1_va.at[0].at[5]=0;
  start.intersection_1_va.at[0].at[6]=1;
  start.intersection_1_va.at[0].at[7]=1;
  start.intersection_1_va.at[1].at[0]=1;
  start.intersection_1_va.at[1].at[1]=1;
  start.intersection_1_va.at[1].at[2]=2;
  start.intersection_1_va.at[1].at[3]=0;
  start.intersection_1_va.at[1].at[4]=0;
  start.intersection_1_va.at[1].at[5]=0;
  start.intersection_1_va.at[1].at[6]=1;
  start.intersection_1_va.at[1].at[7]=1;
  start.intersection_1_va.at[2].at[0]=0;
  start.intersection_1_va.at[2].at[1]=3;
  start.intersection_1_va.at[2].at[2]=0;
  start.intersection_1_va.at[2].at[3]=0;
  start.intersection_1_va.at[2].at[4]=0;
  start.intersection_1_va.at[2].at[5]=0;
  start.intersection_1_va.at[2].at[6]=0;
  start.intersection_1_va.at[2].at[7]=0;
  start.intersection_1_va.at[3].at[0]=0;
  start.intersection_1_va.at[3].at[1]=0;
  start.intersection_1_va.at[3].at[2]=0;
  start.intersection_1_va.at[3].at[3]=0;
  start.intersection_1_va.at[3].at[4]=0;
  start.intersection_1_va.at[3].at[5]=0;
  start.intersection_1_va.at[3].at[6]=5;
  start.intersection_1_va.at[3].at[7]=0;
  start.intersection_1_va.at[4].at[0]=0;
  start.intersection_1_va.at[4].at[1]=0;
  start.intersection_1_va.at[4].at[2]=0;
  start.intersection_1_va.at[4].at[3]=0;
  start.intersection_1_va.at[4].at[4]=0;
  start.intersection_1_va.at[4].at[5]=0;
  start.intersection_1_va.at[4].at[6]=0;
  start.intersection_1_va.at[4].at[7]=0;
  start.intersection_1_va.at[5].at[0]=0;
  start.intersection_1_va.at[5].at[1]=0;
  start.intersection_1_va.at[5].at[2]=0;
  start.intersection_1_va.at[5].at[3]=0;
  start.intersection_1_va.at[5].at[4]=0;
  start.intersection_1_va.at[5].at[5]=0;
  start.intersection_1_va.at[5].at[6]=0;
  start.intersection_1_va.at[5].at[7]=0;
  start.intersection_1_va.at[6].at[0]=1;
  start.intersection_1_va.at[6].at[1]=1;
  start.intersection_1_va.at[6].at[2]=0;
  start.intersection_1_va.at[6].at[3]=0;
  start.intersection_1_va.at[6].at[4]=4;
  start.intersection_1_va.at[6].at[5]=0;
  start.intersection_1_va.at[6].at[6]=1;
  start.intersection_1_va.at[6].at[7]=1;
  start.intersection_1_va.at[7].at[0]=1;
  start.intersection_1_va.at[7].at[1]=1;
  start.intersection_1_va.at[7].at[2]=0;
  start.intersection_1_va.at[7].at[3]=0;
  start.intersection_1_va.at[7].at[4]=0;
  start.intersection_1_va.at[7].at[5]=0;
  start.intersection_1_va.at[7].at[6]=1;
  start.intersection_1_va.at[7].at[7]=1;
  /* storage initializations: */
  open_storage();
  values_storage = init_storage(sizeof(struct value), compare_value, pack_with_size_value, unpack_with_size_value, size_value);
#ifdef SHARE
  a2_storage = init_storage(sizeof(struct a2), compare_a2, pack_with_size_a2, unpack_with_size_a2, size_a2);
  a3_storage = init_storage(sizeof(struct a3), compare_a3, pack_with_size_a3, unpack_with_size_a3, size_a3);
#endif
  return store(&start);
  error: return 0;
}

int final(int debug) {
  finalize_storage("top", debug, &values_storage);
#ifdef SHARE
  finalize_storage("a2 ", debug, &a2_storage);
  finalize_storage("a3 ", debug, &a3_storage);
#endif
  return close_storage(debug);
}

/* -- predicates and actions */
/* by default, pre_t* returns true and act_t* is the identity function */

/* translation table for transition names */
char *transtable[51] = {"intersection_1_t0","intersection_1_t1","intersection_1_t2","intersection_1_t3","intersection_1_t4","intersection_1_t5","intersection_1_t6","intersection_1_t7","intersection_1_t8","intersection_1_t9","intersection_1_t10","intersection_1_t11","intersection_1_t12","intersection_1_t13","intersection_1_t14","intersection_1_t15","intersection_1_t16","intersection_1_t17","intersection_1_t18","intersection_1_t19","intersection_1_t20","intersection_1_t21","intersection_1_t22","intersection_1_t23","intersection_1_t24","intersection_1_t25","intersection_1_t26","intersection_1_t27","intersection_1_t28","intersection_1_t29","intersection_1_t30","intersection_1_t31","intersection_1_t32","intersection_1_t33","intersection_1_t34","intersection_1_t35","intersection_1_t36","intersection_1_t37","intersection_1_t38","intersection_1_t39","intersection_1_t40","intersection_1_t41","intersection_1_t42","intersection_1_t43","intersection_1_t44","intersection_1_t45","intersection_1_t46","intersection_1_t47","intersection_1_t48","intersection_1_t49","intersection_1_t50"};

char **transitions (int *sz) {
*sz =51;
return transtable;
}

bool pre_0 (key s) {
  /* intersection_1_t0 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vo=fcr_oo(); 
  if (!((! compare_a0(v->intersection_1_vpx,intersection_1_vo)))) return 0;
  if (!((! compare_a0(v->intersection_1_vpy,intersection_1_vo)))) return 0;
  return 1;
 error: return 0;
}

bool pre_1 (key s) {
  /* intersection_1_t1 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vpos.at[1]].at[intersection_1_vpos.at[0]] == 2))) return 0;
  if (!((intersection_1_vpos.at[1] == 6))) return 0;
  if (!(((((intersection_1_vpos.at[0] == 2) || (intersection_1_vpos.at[0] == 3)) || (intersection_1_vpos.at[0] == 4)) || (intersection_1_vpos.at[0] == 5)))) return 0;
  return 1;
 error: return 0;
}

bool pre_2 (key s) {
  /* intersection_1_t2 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vpos.at[1]].at[intersection_1_vpos.at[0]] == 2))) return 0;
  if (!((intersection_1_vpos.at[1] == 6))) return 0;
  if (!(((((intersection_1_vpos.at[0] == 2) || (intersection_1_vpos.at[0] == 3)) || (intersection_1_vpos.at[0] == 4)) || (intersection_1_vpos.at[0] == 5)))) return 0;
  return 1;
 error: return 0;
}

bool pre_3 (key s) {
  /* intersection_1_t3 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vpos.at[1]].at[intersection_1_vpos.at[0]] == 3))) return 0;
  if (!((intersection_1_vpos.at[0] == 6))) return 0;
  if (!(((((intersection_1_vpos.at[1] == 2) || (intersection_1_vpos.at[1] == 3)) || (intersection_1_vpos.at[1] == 4)) || (intersection_1_vpos.at[1] == 5)))) return 0;
  return 1;
 error: return 0;
}

bool pre_4 (key s) {
  /* intersection_1_t4 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vpos.at[1]].at[intersection_1_vpos.at[0]] == 3))) return 0;
  if (!((intersection_1_vpos.at[0] == 6))) return 0;
  if (!(((((intersection_1_vpos.at[1] == 2) || (intersection_1_vpos.at[1] == 3)) || (intersection_1_vpos.at[1] == 4)) || (intersection_1_vpos.at[1] == 5)))) return 0;
  return 1;
 error: return 0;
}

bool pre_5 (key s) {
  /* intersection_1_t5 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vpos.at[1]].at[intersection_1_vpos.at[0]] == 4))) return 0;
  if (!((intersection_1_vpos.at[1] == 1))) return 0;
  if (!(((((intersection_1_vpos.at[0] == 2) || (intersection_1_vpos.at[0] == 3)) || (intersection_1_vpos.at[0] == 4)) || (intersection_1_vpos.at[0] == 5)))) return 0;
  return 1;
 error: return 0;
}

bool pre_6 (key s) {
  /* intersection_1_t6 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vpos.at[1]].at[intersection_1_vpos.at[0]] == 4))) return 0;
  if (!((intersection_1_vpos.at[1] == 1))) return 0;
  if (!(((((intersection_1_vpos.at[0] == 2) || (intersection_1_vpos.at[0] == 3)) || (intersection_1_vpos.at[0] == 4)) || (intersection_1_vpos.at[0] == 5)))) return 0;
  return 1;
 error: return 0;
}

bool pre_7 (key s) {
  /* intersection_1_t7 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vpos.at[1]].at[intersection_1_vpos.at[0]] == 5))) return 0;
  if (!((intersection_1_vpos.at[0] == 1))) return 0;
  if (!(((((intersection_1_vpos.at[1] == 2) || (intersection_1_vpos.at[1] == 3)) || (intersection_1_vpos.at[1] == 4)) || (intersection_1_vpos.at[1] == 5)))) return 0;
  return 1;
 error: return 0;
}

bool pre_8 (key s) {
  /* intersection_1_t8 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vpos.at[1]].at[intersection_1_vpos.at[0]] == 5))) return 0;
  if (!((intersection_1_vpos.at[0] == 1))) return 0;
  if (!(((((intersection_1_vpos.at[1] == 2) || (intersection_1_vpos.at[1] == 3)) || (intersection_1_vpos.at[1] == 4)) || (intersection_1_vpos.at[1] == 5)))) return 0;
  return 1;
 error: return 0;
}

bool pre_9 (key s) {
  /* intersection_1_t9 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vo=fcr_oo(); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((v->intersection_1_vpx.at[v->intersection_1_vt] == 0))) return 0;
  if (!((v->intersection_1_vpy.at[v->intersection_1_vt] == 0))) return 0;
  if (!((!(! compare_a0(v->intersection_1_vpx,intersection_1_vo))))) return 0;
  if (!((!(! compare_a0(v->intersection_1_vpy,intersection_1_vo))))) return 0;
  return 1;
 error: return 0;
}

bool pre_10 (key s) {
  /* intersection_1_t10 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vo=fcr_oo(); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((v->intersection_1_vpx.at[v->intersection_1_vt] == 0))) return 0;
  if (!((v->intersection_1_vpy.at[v->intersection_1_vt] == 0))) return 0;
  if (!((!(! compare_a0(v->intersection_1_vpx,intersection_1_vo))))) return 0;
  if (!((!(! compare_a0(v->intersection_1_vpy,intersection_1_vo))))) return 0;
  return 1;
 error: return 0;
}

bool pre_11 (key s) {
  /* intersection_1_t11 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((intersection_1_vy < 6))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[intersection_1_vx] == 0))) return 0;
  if (!((intersection_1_vr == 1))) return 0;
  return 1;
 error: return 0;
}

bool pre_12 (key s) {
  /* intersection_1_t12 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((intersection_1_vy < 6))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[intersection_1_vx] == 0))) return 0;
  if (!((intersection_1_vr == 1))) return 0;
  return 1;
 error: return 0;
}

bool pre_13 (key s) {
  /* intersection_1_t13 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((intersection_1_vy < 6))) return 0;
  if (!((intersection_1_vx > 2))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0))) return 0;
  if (!((intersection_1_vr == 1))) return 0;
  return 1;
 error: return 0;
}

bool pre_14 (key s) {
  /* intersection_1_t14 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((intersection_1_vy < 6))) return 0;
  if (!((intersection_1_vx > 2))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0))) return 0;
  if (!((intersection_1_vr == 1))) return 0;
  return 1;
 error: return 0;
}

bool pre_15 (key s) {
  /* intersection_1_t15 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((intersection_1_vy < 6))) return 0;
  if (!((intersection_1_vx < 5))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0))) return 0;
  if (!((intersection_1_vr == 1))) return 0;
  return 1;
 error: return 0;
}

bool pre_16 (key s) {
  /* intersection_1_t16 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((intersection_1_vy < 6))) return 0;
  if (!((intersection_1_vx < 5))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0))) return 0;
  if (!((intersection_1_vr == 1))) return 0;
  return 1;
 error: return 0;
}

bool pre_17 (key s) {
  /* intersection_1_t17 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((!(v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[intersection_1_vx] == 0)))) return 0;
  if (!((!(v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0)))) return 0;
  if (!((!(v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0)))) return 0;
  if (!((intersection_1_vr == 1))) return 0;
  return 1;
 error: return 0;
}

bool pre_18 (key s) {
  /* intersection_1_t18 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!(((((intersection_1_vx == 2) && (!(v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[intersection_1_vx] == 0))) && (!(v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0))) || (((intersection_1_vx == 5) && (!(v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[intersection_1_vx] == 0))) && (!(v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0)))))) return 0;
  if (!((intersection_1_vr == 1))) return 0;
  return 1;
 error: return 0;
}

bool pre_19 (key s) {
  /* intersection_1_t19 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((!(v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[intersection_1_vx] == 0)))) return 0;
  if (!((!(v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0)))) return 0;
  if (!((!(v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0)))) return 0;
  if (!((intersection_1_vr == 1))) return 0;
  return 1;
 error: return 0;
}

bool pre_20 (key s) {
  /* intersection_1_t20 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!(((((intersection_1_vx == 2) && (!(v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[intersection_1_vx] == 0))) && (!(v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0))) || (((intersection_1_vx == 5) && (!(v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[intersection_1_vx] == 0))) && (!(v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0)))))) return 0;
  if (!((intersection_1_vr == 1))) return 0;
  return 1;
 error: return 0;
}

bool pre_21 (key s) {
  /* intersection_1_t21 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((intersection_1_vx < 6))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[IADD(intersection_1_vx,1,0,7)] == 0))) return 0;
  if (!((intersection_1_vr == 2))) return 0;
  return 1;
 error: return 0;
}

bool pre_22 (key s) {
  /* intersection_1_t22 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((intersection_1_vx < 6))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[IADD(intersection_1_vx,1,0,7)] == 0))) return 0;
  if (!((intersection_1_vr == 2))) return 0;
  return 1;
 error: return 0;
}

bool pre_23 (key s) {
  /* intersection_1_t23 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((intersection_1_vx < 6))) return 0;
  if (!((intersection_1_vy > 2))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0))) return 0;
  if (!((intersection_1_vr == 2))) return 0;
  return 1;
 error: return 0;
}

bool pre_24 (key s) {
  /* intersection_1_t24 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((intersection_1_vx < 6))) return 0;
  if (!((intersection_1_vy > 2))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0))) return 0;
  if (!((intersection_1_vr == 2))) return 0;
  return 1;
 error: return 0;
}

bool pre_25 (key s) {
  /* intersection_1_t25 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((intersection_1_vx < 6))) return 0;
  if (!((intersection_1_vy < 5))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0))) return 0;
  if (!((intersection_1_vr == 2))) return 0;
  return 1;
 error: return 0;
}

bool pre_26 (key s) {
  /* intersection_1_t26 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((intersection_1_vx < 6))) return 0;
  if (!((intersection_1_vy < 5))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0))) return 0;
  if (!((intersection_1_vr == 2))) return 0;
  return 1;
 error: return 0;
}

bool pre_27 (key s) {
  /* intersection_1_t27 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((!(v->intersection_1_va.at[intersection_1_vy].at[IADD(intersection_1_vx,1,0,7)] == 0)))) return 0;
  if (!((!(v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0)))) return 0;
  if (!((!(v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0)))) return 0;
  if (!((intersection_1_vr == 2))) return 0;
  return 1;
 error: return 0;
}

bool pre_28 (key s) {
  /* intersection_1_t28 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!(((((intersection_1_vy == 2) && (!(v->intersection_1_va.at[intersection_1_vy].at[IADD(intersection_1_vx,1,0,7)] == 0))) && (!(v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0))) || (((intersection_1_vy == 5) && (!(v->intersection_1_va.at[intersection_1_vy].at[IADD(intersection_1_vx,1,0,7)] == 0))) && (!(v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0)))))) return 0;
  if (!((intersection_1_vr == 2))) return 0;
  return 1;
 error: return 0;
}

bool pre_29 (key s) {
  /* intersection_1_t29 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((!(v->intersection_1_va.at[intersection_1_vy].at[IADD(intersection_1_vx,1,0,7)] == 0)))) return 0;
  if (!((!(v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0)))) return 0;
  if (!((!(v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0)))) return 0;
  if (!((intersection_1_vr == 2))) return 0;
  return 1;
 error: return 0;
}

bool pre_30 (key s) {
  /* intersection_1_t30 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!(((((intersection_1_vy == 2) && (!(v->intersection_1_va.at[intersection_1_vy].at[IADD(intersection_1_vx,1,0,7)] == 0))) && (!(v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0))) || (((intersection_1_vy == 5) && (!(v->intersection_1_va.at[intersection_1_vy].at[IADD(intersection_1_vx,1,0,7)] == 0))) && (!(v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0)))))) return 0;
  if (!((intersection_1_vr == 2))) return 0;
  return 1;
 error: return 0;
}

bool pre_31 (key s) {
  /* intersection_1_t31 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((intersection_1_vy > 1))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[intersection_1_vx] == 0))) return 0;
  if (!((intersection_1_vr == 3))) return 0;
  return 1;
 error: return 0;
}

bool pre_32 (key s) {
  /* intersection_1_t32 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((intersection_1_vy > 1))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[intersection_1_vx] == 0))) return 0;
  if (!((intersection_1_vr == 3))) return 0;
  return 1;
 error: return 0;
}

bool pre_33 (key s) {
  /* intersection_1_t33 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((intersection_1_vy > 1))) return 0;
  if (!((intersection_1_vx > 2))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0))) return 0;
  if (!((intersection_1_vr == 3))) return 0;
  return 1;
 error: return 0;
}

bool pre_34 (key s) {
  /* intersection_1_t34 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((intersection_1_vy > 1))) return 0;
  if (!((intersection_1_vx > 2))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0))) return 0;
  if (!((intersection_1_vr == 3))) return 0;
  return 1;
 error: return 0;
}

bool pre_35 (key s) {
  /* intersection_1_t35 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((intersection_1_vy > 1))) return 0;
  if (!((intersection_1_vx < 5))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0))) return 0;
  if (!((intersection_1_vr == 3))) return 0;
  return 1;
 error: return 0;
}

bool pre_36 (key s) {
  /* intersection_1_t36 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((intersection_1_vy > 1))) return 0;
  if (!((intersection_1_vx < 5))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0))) return 0;
  if (!((intersection_1_vr == 3))) return 0;
  return 1;
 error: return 0;
}

bool pre_37 (key s) {
  /* intersection_1_t37 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((!(v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[intersection_1_vx] == 0)))) return 0;
  if (!((!(v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0)))) return 0;
  if (!((!(v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0)))) return 0;
  if (!((intersection_1_vr == 3))) return 0;
  return 1;
 error: return 0;
}

bool pre_38 (key s) {
  /* intersection_1_t38 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!(((((intersection_1_vx == 2) && (!(v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[intersection_1_vx] == 0))) && (!(v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0))) || (((intersection_1_vx == 5) && (!(v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[intersection_1_vx] == 0))) && (!(v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0)))))) return 0;
  if (!((intersection_1_vr == 3))) return 0;
  return 1;
 error: return 0;
}

bool pre_39 (key s) {
  /* intersection_1_t39 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((!(v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[intersection_1_vx] == 0)))) return 0;
  if (!((!(v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0)))) return 0;
  if (!((!(v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0)))) return 0;
  if (!((intersection_1_vr == 3))) return 0;
  return 1;
 error: return 0;
}

bool pre_40 (key s) {
  /* intersection_1_t40 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!(((((intersection_1_vx == 2) && (!(v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[intersection_1_vx] == 0))) && (!(v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)] == 0))) || (((intersection_1_vx == 5) && (!(v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[intersection_1_vx] == 0))) && (!(v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0)))))) return 0;
  if (!((intersection_1_vr == 3))) return 0;
  return 1;
 error: return 0;
}

bool pre_41 (key s) {
  /* intersection_1_t41 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((intersection_1_vx > 1))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[ISUB(intersection_1_vx,1,0,7)] == 0))) return 0;
  if (!((intersection_1_vr == 4))) return 0;
  return 1;
 error: return 0;
}

bool pre_42 (key s) {
  /* intersection_1_t42 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((intersection_1_vx > 1))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[ISUB(intersection_1_vx,1,0,7)] == 0))) return 0;
  if (!((intersection_1_vr == 4))) return 0;
  return 1;
 error: return 0;
}

bool pre_43 (key s) {
  /* intersection_1_t43 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((intersection_1_vx > 1))) return 0;
  if (!((intersection_1_vy > 2))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0))) return 0;
  if (!((intersection_1_vr == 4))) return 0;
  return 1;
 error: return 0;
}

bool pre_44 (key s) {
  /* intersection_1_t44 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((intersection_1_vx > 1))) return 0;
  if (!((intersection_1_vy > 2))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0))) return 0;
  if (!((intersection_1_vr == 4))) return 0;
  return 1;
 error: return 0;
}

bool pre_45 (key s) {
  /* intersection_1_t45 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((intersection_1_vx > 1))) return 0;
  if (!((intersection_1_vy < 5))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0))) return 0;
  if (!((intersection_1_vr == 4))) return 0;
  return 1;
 error: return 0;
}

bool pre_46 (key s) {
  /* intersection_1_t46 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((intersection_1_vx > 1))) return 0;
  if (!((intersection_1_vy < 5))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0))) return 0;
  if (!((intersection_1_vr == 4))) return 0;
  return 1;
 error: return 0;
}

bool pre_47 (key s) {
  /* intersection_1_t47 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((!(v->intersection_1_va.at[intersection_1_vy].at[ISUB(intersection_1_vx,1,0,7)] == 0)))) return 0;
  if (!((!(v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0)))) return 0;
  if (!((!(v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0)))) return 0;
  if (!((intersection_1_vr == 4))) return 0;
  return 1;
 error: return 0;
}

bool pre_48 (key s) {
  /* intersection_1_t48 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt < 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!(((((intersection_1_vy == 2) && (!(v->intersection_1_va.at[intersection_1_vy].at[ISUB(intersection_1_vx,1,0,7)] == 0))) && (!(v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0))) || (((intersection_1_vy == 5) && (!(v->intersection_1_va.at[intersection_1_vy].at[ISUB(intersection_1_vx,1,0,7)] == 0))) && (!(v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0)))))) return 0;
  if (!((intersection_1_vr == 4))) return 0;
  return 1;
 error: return 0;
}

bool pre_49 (key s) {
  /* intersection_1_t49 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!((!(v->intersection_1_va.at[intersection_1_vy].at[ISUB(intersection_1_vx,1,0,7)] == 0)))) return 0;
  if (!((!(v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0)))) return 0;
  if (!((!(v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0)))) return 0;
  if (!((intersection_1_vr == 4))) return 0;
  return 1;
 error: return 0;
}

bool pre_50 (key s) {
  /* intersection_1_t50 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value *v = lookup(s);
  intersection_1_vva=fcr_cav(v->intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(v->intersection_1_vt,v->intersection_1_vpx,v->intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  if (!((v->intersection_1_vt == 3))) return 0;
  if (!((v->intersection_1_va.at[intersection_1_vy].at[intersection_1_vx] == intersection_1_vva))) return 0;
  if (!(((((intersection_1_vy == 2) && (!(v->intersection_1_va.at[intersection_1_vy].at[ISUB(intersection_1_vx,1,0,7)] == 0))) && (!(v->intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0))) || (((intersection_1_vy == 5) && (!(v->intersection_1_va.at[intersection_1_vy].at[ISUB(intersection_1_vx,1,0,7)] == 0))) && (!(v->intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)] == 0)))))) return 0;
  if (!((intersection_1_vr == 4))) return 0;
  return 1;
 error: return 0;
}

key act_0 (key s) {
  /* intersection_1_t0 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_1 (key s) {
  /* intersection_1_t1 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=0; 
  new.intersection_1_vpx.at[new.intersection_1_vt]=0; 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_2 (key s) {
  /* intersection_1_t2 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=0; 
  new.intersection_1_vpx.at[new.intersection_1_vt]=0; 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_3 (key s) {
  /* intersection_1_t3 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=0; 
  new.intersection_1_vpx.at[new.intersection_1_vt]=0; 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_4 (key s) {
  /* intersection_1_t4 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=0; 
  new.intersection_1_vpx.at[new.intersection_1_vt]=0; 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_5 (key s) {
  /* intersection_1_t5 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=0; 
  new.intersection_1_vpx.at[new.intersection_1_vt]=0; 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_6 (key s) {
  /* intersection_1_t6 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=0; 
  new.intersection_1_vpx.at[new.intersection_1_vt]=0; 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_7 (key s) {
  /* intersection_1_t7 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=0; 
  new.intersection_1_vpx.at[new.intersection_1_vt]=0; 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_8 (key s) {
  /* intersection_1_t8 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=0; 
  new.intersection_1_vpx.at[new.intersection_1_vt]=0; 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_9 (key s) {
  /* intersection_1_t9 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_10 (key s) {
  /* intersection_1_t10 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_11 (key s) {
  /* intersection_1_t11 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[intersection_1_vx]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=IADD(intersection_1_vy,1,0,7); 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_12 (key s) {
  /* intersection_1_t12 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[intersection_1_vx]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=IADD(intersection_1_vy,1,0,7); 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_13 (key s) {
  /* intersection_1_t13 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=IADD(intersection_1_vy,1,0,7); 
  new.intersection_1_vpx.at[new.intersection_1_vt]=ISUB(intersection_1_vx,1,0,7); 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_14 (key s) {
  /* intersection_1_t14 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=IADD(intersection_1_vy,1,0,7); 
  new.intersection_1_vpx.at[new.intersection_1_vt]=ISUB(intersection_1_vx,1,0,7); 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_15 (key s) {
  /* intersection_1_t15 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=IADD(intersection_1_vy,1,0,7); 
  new.intersection_1_vpx.at[new.intersection_1_vt]=IADD(intersection_1_vx,1,0,7); 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_16 (key s) {
  /* intersection_1_t16 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=IADD(intersection_1_vy,1,0,7); 
  new.intersection_1_vpx.at[new.intersection_1_vt]=IADD(intersection_1_vx,1,0,7); 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_17 (key s) {
  /* intersection_1_t17 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_18 (key s) {
  /* intersection_1_t18 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_19 (key s) {
  /* intersection_1_t19 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_20 (key s) {
  /* intersection_1_t20 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_21 (key s) {
  /* intersection_1_t21 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[intersection_1_vy].at[IADD(intersection_1_vx,1,0,7)]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpx.at[new.intersection_1_vt]=IADD(intersection_1_vx,1,0,7); 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_22 (key s) {
  /* intersection_1_t22 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[intersection_1_vy].at[IADD(intersection_1_vx,1,0,7)]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpx.at[new.intersection_1_vt]=IADD(intersection_1_vx,1,0,7); 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_23 (key s) {
  /* intersection_1_t23 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=ISUB(intersection_1_vy,1,0,7); 
  new.intersection_1_vpx.at[new.intersection_1_vt]=IADD(intersection_1_vx,1,0,7); 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_24 (key s) {
  /* intersection_1_t24 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=ISUB(intersection_1_vy,1,0,7); 
  new.intersection_1_vpx.at[new.intersection_1_vt]=IADD(intersection_1_vx,1,0,7); 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_25 (key s) {
  /* intersection_1_t25 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=IADD(intersection_1_vy,1,0,7); 
  new.intersection_1_vpx.at[new.intersection_1_vt]=IADD(intersection_1_vx,1,0,7); 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_26 (key s) {
  /* intersection_1_t26 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=IADD(intersection_1_vy,1,0,7); 
  new.intersection_1_vpx.at[new.intersection_1_vt]=IADD(intersection_1_vx,1,0,7); 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_27 (key s) {
  /* intersection_1_t27 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_28 (key s) {
  /* intersection_1_t28 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_29 (key s) {
  /* intersection_1_t29 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_30 (key s) {
  /* intersection_1_t30 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_31 (key s) {
  /* intersection_1_t31 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[intersection_1_vx]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=ISUB(intersection_1_vy,1,0,7); 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_32 (key s) {
  /* intersection_1_t32 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[intersection_1_vx]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=ISUB(intersection_1_vy,1,0,7); 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_33 (key s) {
  /* intersection_1_t33 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=ISUB(intersection_1_vy,1,0,7); 
  new.intersection_1_vpx.at[new.intersection_1_vt]=ISUB(intersection_1_vx,1,0,7); 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_34 (key s) {
  /* intersection_1_t34 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=ISUB(intersection_1_vy,1,0,7); 
  new.intersection_1_vpx.at[new.intersection_1_vt]=ISUB(intersection_1_vx,1,0,7); 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_35 (key s) {
  /* intersection_1_t35 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=ISUB(intersection_1_vy,1,0,7); 
  new.intersection_1_vpx.at[new.intersection_1_vt]=IADD(intersection_1_vx,1,0,7); 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_36 (key s) {
  /* intersection_1_t36 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[IADD(intersection_1_vx,1,0,7)]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=ISUB(intersection_1_vy,1,0,7); 
  new.intersection_1_vpx.at[new.intersection_1_vt]=IADD(intersection_1_vx,1,0,7); 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_37 (key s) {
  /* intersection_1_t37 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_38 (key s) {
  /* intersection_1_t38 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_39 (key s) {
  /* intersection_1_t39 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_40 (key s) {
  /* intersection_1_t40 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_41 (key s) {
  /* intersection_1_t41 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[intersection_1_vy].at[ISUB(intersection_1_vx,1,0,7)]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpx.at[new.intersection_1_vt]=ISUB(intersection_1_vx,1,0,7); 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_42 (key s) {
  /* intersection_1_t42 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[intersection_1_vy].at[ISUB(intersection_1_vx,1,0,7)]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpx.at[new.intersection_1_vt]=ISUB(intersection_1_vx,1,0,7); 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_43 (key s) {
  /* intersection_1_t43 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=ISUB(intersection_1_vy,1,0,7); 
  new.intersection_1_vpx.at[new.intersection_1_vt]=ISUB(intersection_1_vx,1,0,7); 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_44 (key s) {
  /* intersection_1_t44 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[ISUB(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=ISUB(intersection_1_vy,1,0,7); 
  new.intersection_1_vpx.at[new.intersection_1_vt]=ISUB(intersection_1_vx,1,0,7); 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_45 (key s) {
  /* intersection_1_t45 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=IADD(intersection_1_vy,1,0,7); 
  new.intersection_1_vpx.at[new.intersection_1_vt]=ISUB(intersection_1_vx,1,0,7); 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_46 (key s) {
  /* intersection_1_t46 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_va.at[IADD(intersection_1_vy,1,0,7)].at[ISUB(intersection_1_vx,1,0,7)]=intersection_1_vva; 
  new.intersection_1_va.at[intersection_1_vy].at[intersection_1_vx]=0; 
  new.intersection_1_vpy.at[new.intersection_1_vt]=IADD(intersection_1_vy,1,0,7); 
  new.intersection_1_vpx.at[new.intersection_1_vt]=ISUB(intersection_1_vx,1,0,7); 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_47 (key s) {
  /* intersection_1_t47 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_48 (key s) {
  /* intersection_1_t48 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_vt=IADD(new.intersection_1_vt,1,0,3); 
  return store(&new);
 error: return s;
}

key act_49 (key s) {
  /* intersection_1_t49 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

key act_50 (key s) {
  /* intersection_1_t50 */
  char intersection_1_vx;
  char intersection_1_vy;
  struct a1 intersection_1_vpos;
  int intersection_1_vva;
  int intersection_1_vr;
  struct a0 intersection_1_vo;
  struct value new = *(struct value*)lookup(s);
  intersection_1_vo=fcr_oo(); 
  intersection_1_vva=fcr_cav(new.intersection_1_vt); 
  intersection_1_vpos=fcr_coordinate(new.intersection_1_vt,new.intersection_1_vpx,new.intersection_1_vpy); 
  intersection_1_vx=intersection_1_vpos.at[0]; 
  intersection_1_vy=intersection_1_vpos.at[1]; 
  intersection_1_vr=fcr_road(intersection_1_vva); 
  new.intersection_1_vt=0; 
  return store(&new);
 error: return s;
}

/* -- independance relation for transitions, for partial order modes and reset in timed modes -- */
/* indices refer to transtable; specifies independance for ALL transitions */
bool independant (int t1, int t2) {
    /* always true */
    return 1;
}

/* -- state observers for kts output -- */
char *obsnames[73] = {"{intersection_1_vpx.at[0]}","{intersection_1_vpx.at[1]}","{intersection_1_vpx.at[2]}","{intersection_1_vpx.at[3]}","{intersection_1_vpy.at[0]}","{intersection_1_vpy.at[1]}","{intersection_1_vpy.at[2]}","{intersection_1_vpy.at[3]}","intersection_1_vt","{intersection_1_va.at[0].at[0]}","{intersection_1_va.at[0].at[1]}","{intersection_1_va.at[0].at[2]}","{intersection_1_va.at[0].at[3]}","{intersection_1_va.at[0].at[4]}","{intersection_1_va.at[0].at[5]}","{intersection_1_va.at[0].at[6]}","{intersection_1_va.at[0].at[7]}","{intersection_1_va.at[1].at[0]}","{intersection_1_va.at[1].at[1]}","{intersection_1_va.at[1].at[2]}","{intersection_1_va.at[1].at[3]}","{intersection_1_va.at[1].at[4]}","{intersection_1_va.at[1].at[5]}","{intersection_1_va.at[1].at[6]}","{intersection_1_va.at[1].at[7]}","{intersection_1_va.at[2].at[0]}","{intersection_1_va.at[2].at[1]}","{intersection_1_va.at[2].at[2]}","{intersection_1_va.at[2].at[3]}","{intersection_1_va.at[2].at[4]}","{intersection_1_va.at[2].at[5]}","{intersection_1_va.at[2].at[6]}","{intersection_1_va.at[2].at[7]}","{intersection_1_va.at[3].at[0]}","{intersection_1_va.at[3].at[1]}","{intersection_1_va.at[3].at[2]}","{intersection_1_va.at[3].at[3]}","{intersection_1_va.at[3].at[4]}","{intersection_1_va.at[3].at[5]}","{intersection_1_va.at[3].at[6]}","{intersection_1_va.at[3].at[7]}","{intersection_1_va.at[4].at[0]}","{intersection_1_va.at[4].at[1]}","{intersection_1_va.at[4].at[2]}","{intersection_1_va.at[4].at[3]}","{intersection_1_va.at[4].at[4]}","{intersection_1_va.at[4].at[5]}","{intersection_1_va.at[4].at[6]}","{intersection_1_va.at[4].at[7]}","{intersection_1_va.at[5].at[0]}","{intersection_1_va.at[5].at[1]}","{intersection_1_va.at[5].at[2]}","{intersection_1_va.at[5].at[3]}","{intersection_1_va.at[5].at[4]}","{intersection_1_va.at[5].at[5]}","{intersection_1_va.at[5].at[6]}","{intersection_1_va.at[5].at[7]}","{intersection_1_va.at[6].at[0]}","{intersection_1_va.at[6].at[1]}","{intersection_1_va.at[6].at[2]}","{intersection_1_va.at[6].at[3]}","{intersection_1_va.at[6].at[4]}","{intersection_1_va.at[6].at[5]}","{intersection_1_va.at[6].at[6]}","{intersection_1_va.at[6].at[7]}","{intersection_1_va.at[7].at[0]}","{intersection_1_va.at[7].at[1]}","{intersection_1_va.at[7].at[2]}","{intersection_1_va.at[7].at[3]}","{intersection_1_va.at[7].at[4]}","{intersection_1_va.at[7].at[5]}","{intersection_1_va.at[7].at[6]}","{intersection_1_va.at[7].at[7]}"};

char **obs_names (int *count) {*count = 73; return obsnames;}

/* returns values of observables for state s (abstractions for noninteger fields) */
int ovalues[73];

int *obs_values (key s) {
struct value *v = lookup(s);
ovalues[0]=(int)(v->intersection_1_vpx.at[0]);
ovalues[1]=(int)(v->intersection_1_vpx.at[1]);
ovalues[2]=(int)(v->intersection_1_vpx.at[2]);
ovalues[3]=(int)(v->intersection_1_vpx.at[3]);
ovalues[4]=(int)(v->intersection_1_vpy.at[0]);
ovalues[5]=(int)(v->intersection_1_vpy.at[1]);
ovalues[6]=(int)(v->intersection_1_vpy.at[2]);
ovalues[7]=(int)(v->intersection_1_vpy.at[3]);
ovalues[8]=(int)(v->intersection_1_vt);
ovalues[9]=(int)(v->intersection_1_va.at[0].at[0]);
ovalues[10]=(int)(v->intersection_1_va.at[0].at[1]);
ovalues[11]=(int)(v->intersection_1_va.at[0].at[2]);
ovalues[12]=(int)(v->intersection_1_va.at[0].at[3]);
ovalues[13]=(int)(v->intersection_1_va.at[0].at[4]);
ovalues[14]=(int)(v->intersection_1_va.at[0].at[5]);
ovalues[15]=(int)(v->intersection_1_va.at[0].at[6]);
ovalues[16]=(int)(v->intersection_1_va.at[0].at[7]);
ovalues[17]=(int)(v->intersection_1_va.at[1].at[0]);
ovalues[18]=(int)(v->intersection_1_va.at[1].at[1]);
ovalues[19]=(int)(v->intersection_1_va.at[1].at[2]);
ovalues[20]=(int)(v->intersection_1_va.at[1].at[3]);
ovalues[21]=(int)(v->intersection_1_va.at[1].at[4]);
ovalues[22]=(int)(v->intersection_1_va.at[1].at[5]);
ovalues[23]=(int)(v->intersection_1_va.at[1].at[6]);
ovalues[24]=(int)(v->intersection_1_va.at[1].at[7]);
ovalues[25]=(int)(v->intersection_1_va.at[2].at[0]);
ovalues[26]=(int)(v->intersection_1_va.at[2].at[1]);
ovalues[27]=(int)(v->intersection_1_va.at[2].at[2]);
ovalues[28]=(int)(v->intersection_1_va.at[2].at[3]);
ovalues[29]=(int)(v->intersection_1_va.at[2].at[4]);
ovalues[30]=(int)(v->intersection_1_va.at[2].at[5]);
ovalues[31]=(int)(v->intersection_1_va.at[2].at[6]);
ovalues[32]=(int)(v->intersection_1_va.at[2].at[7]);
ovalues[33]=(int)(v->intersection_1_va.at[3].at[0]);
ovalues[34]=(int)(v->intersection_1_va.at[3].at[1]);
ovalues[35]=(int)(v->intersection_1_va.at[3].at[2]);
ovalues[36]=(int)(v->intersection_1_va.at[3].at[3]);
ovalues[37]=(int)(v->intersection_1_va.at[3].at[4]);
ovalues[38]=(int)(v->intersection_1_va.at[3].at[5]);
ovalues[39]=(int)(v->intersection_1_va.at[3].at[6]);
ovalues[40]=(int)(v->intersection_1_va.at[3].at[7]);
ovalues[41]=(int)(v->intersection_1_va.at[4].at[0]);
ovalues[42]=(int)(v->intersection_1_va.at[4].at[1]);
ovalues[43]=(int)(v->intersection_1_va.at[4].at[2]);
ovalues[44]=(int)(v->intersection_1_va.at[4].at[3]);
ovalues[45]=(int)(v->intersection_1_va.at[4].at[4]);
ovalues[46]=(int)(v->intersection_1_va.at[4].at[5]);
ovalues[47]=(int)(v->intersection_1_va.at[4].at[6]);
ovalues[48]=(int)(v->intersection_1_va.at[4].at[7]);
ovalues[49]=(int)(v->intersection_1_va.at[5].at[0]);
ovalues[50]=(int)(v->intersection_1_va.at[5].at[1]);
ovalues[51]=(int)(v->intersection_1_va.at[5].at[2]);
ovalues[52]=(int)(v->intersection_1_va.at[5].at[3]);
ovalues[53]=(int)(v->intersection_1_va.at[5].at[4]);
ovalues[54]=(int)(v->intersection_1_va.at[5].at[5]);
ovalues[55]=(int)(v->intersection_1_va.at[5].at[6]);
ovalues[56]=(int)(v->intersection_1_va.at[5].at[7]);
ovalues[57]=(int)(v->intersection_1_va.at[6].at[0]);
ovalues[58]=(int)(v->intersection_1_va.at[6].at[1]);
ovalues[59]=(int)(v->intersection_1_va.at[6].at[2]);
ovalues[60]=(int)(v->intersection_1_va.at[6].at[3]);
ovalues[61]=(int)(v->intersection_1_va.at[6].at[4]);
ovalues[62]=(int)(v->intersection_1_va.at[6].at[5]);
ovalues[63]=(int)(v->intersection_1_va.at[6].at[6]);
ovalues[64]=(int)(v->intersection_1_va.at[6].at[7]);
ovalues[65]=(int)(v->intersection_1_va.at[7].at[0]);
ovalues[66]=(int)(v->intersection_1_va.at[7].at[1]);
ovalues[67]=(int)(v->intersection_1_va.at[7].at[2]);
ovalues[68]=(int)(v->intersection_1_va.at[7].at[3]);
ovalues[69]=(int)(v->intersection_1_va.at[7].at[4]);
ovalues[70]=(int)(v->intersection_1_va.at[7].at[5]);
ovalues[71]=(int)(v->intersection_1_va.at[7].at[6]);
ovalues[72]=(int)(v->intersection_1_va.at[7].at[7]);
return ovalues;
}

