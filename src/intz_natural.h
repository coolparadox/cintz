#ifndef _INTZ_NATURAL_H_
#define _INTZ_NATURAL_H_

struct intz_natural;
typedef struct intz_natural izn;

/**
 * @brief Instantiates a natural number.
 * @param value Initial value.
 * @return New instance of the number.
 * @see izn_free
 */
izn *izn_alloc(uint64_t value);

void izn_free(izn *value);
void izn_reset(izn *value);
int izn_is_zero(const izn *value);
void izn_add64(izn *target, uint64_t value);
void izn_add(izn *target, const izn *value);
void izn_mul64(izn *target, uint64_t value);
void izn_mul(izn *target, const izn *value);
void izn_sub64(izn *target, uint64_t value, uint64_t *borrow);
void izn_sub(izn *target, const izn *value, izn **borrow);
void izn_div64(izn *target, uint64_t value, uint64_t *remainder);
void izn_div(izn *target, const izn *value, izn **remainder);

#endif // _INTZ_NATURAL_H_
