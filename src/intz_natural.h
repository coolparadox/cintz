#ifndef _INTZ_NATURAL_H_
#define _INTZ_NATURAL_H_

struct intz_natural;
struct intz_natural *intz_natural_alloc(uint64_t value);
void intz_natural_free(struct intz_natural *value);
void intz_natural_gc(struct intz_natural *value);
void intz_natural_reset(struct intz_natural *value);
int intz_natural_is_zero(struct intz_natural *value);
void intz_natural_increment(struct intz_natural *value);
void intz_natural_add64(struct intz_natural *target, uint64_t value);
void intz_natural_add(struct intz_natural *target, struct intz_natural *value);
void intz_natural_mul64(struct intz_natural *target, uint64_t value);
void intz_natural_mul(struct intz_natural *target, struct intz_natural *value);
void intz_natural_sub64(struct intz_natural *target, uint64_t value, uint64_t *borrow);
void intz_natural_sub(struct intz_natural *target, const struct intz_natural *value, struct intz_natural **borrow);
void intz_natural_div64(struct intz_natural *target, uint64_t value, uint64_t *remainder);
void intz_natural_div(struct intz_natural *target, const struct intz_natural *value, struct intz_natural **remainder);

#endif // _INTZ_NATURAL_H_
