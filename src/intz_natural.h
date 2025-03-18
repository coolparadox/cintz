#ifndef _INTZ_NATURAL_H_
#define _INTZ_NATURAL_H_

/**
 * Unbounded natural numbers.
 * by coolparadox@gmail.com
 */

/**
 * struct intz_natural represents an unbounded natural number.
 */
struct intz_natural;
typedef struct intz_natural izn;

/**
 * @brief Instantiates a natural number.
 * @param value Initial value.
 * @return Pointer to the number (dynamically allocated).
 * @note The caller owns the returned pointer.
 * @see izn_free
 */
izn *izn_alloc(uint64_t value);

/**
 * @brief Release a number.
 * @param value Number created with iz_alloc.
 * @post This call invalidates value.
 */
void izn_free(izn *value);

/**
 * @brief Set to zero.
 * @param[in,out] value Number created with iz_alloc.
 * @post value assumes zero.
 */
void izn_reset(izn *value);

/**
 * @brief Is a number equal to zero?
 * @param[in] value Number created with iz_alloc.
 * @return Whether the value is equal to zero.
 */
int izn_is_zero(const izn *value);

/**
 * @brief Get a representation of a number by coefficients.
 * @param[out] coefficients Buffer that receives the coefficients.
 * @param[in,out] len Size of the coefficients buffer. Receives the amount of coefficients
 *                    that were written to the buffer.
 * @note Given a base B=2^64 and a coefficients array C, the represented value is numerically
 *       equal to C[0] + C[1]*B + C[2]*B^2 + C[3]+B^3 + ...
 * @return Whether the buffer was large enough to fit all coefficients.
 */
int izn_get_coeff(uint64_t *coefficients, size_t *len, const izn *value);

/**
 * @brief Natural addition.
 * @param[in,out] target Number created with iz_alloc.
 * @param value Value to be added to target.
 * @post target increases by value.
 */
void izn_add64(izn *target, uint64_t value);
void izn_add(izn *target, const izn *value);

/**
 * @brief Natural multiplication.
 * @param[in,out] target Number created with iz_alloc.
 * @param value Value to be multiplied to target.
 * @post target gets multiplied by value.
 */
void izn_mul64(izn *target, uint64_t value);
void izn_mul(izn *target, const izn *value);

/**
 * @brief Natural subtraction.
 * @param[in,out] target Number created with iz_alloc.
 * @param value Value to be subtracted from target.
 * @param[out] borrow Ignored if null. Otherwise, receives zero if target >= value.
 *                    Otherwise, receives value - target.
 * @post target gets subtracted by value if target >= value. Otherwise, assumes zero.
 */
void izn_sub64(izn *target, uint64_t value, uint64_t *borrow);
void izn_sub(izn *target, const izn *value, izn **borrow);

/**
 * @brief Natural division.
 * @param[in,out] target Number created with iz_alloc.
 * @param value Value to divide target by.
 * @param[out] remainder Ignored if null. Otherwise, receives the remainder of dividing target by value.
 * @post target gets divided by value.
 */
void izn_div64(izn *target, uint64_t value, uint64_t *remainder);
void izn_div(izn *target, const izn *value, izn **remainder);

#endif // _INTZ_NATURAL_H_
