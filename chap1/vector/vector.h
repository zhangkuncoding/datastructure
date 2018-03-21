#pragma once

typedef int elem_t;

struct vector {
  int capacity;
  int size;
  elem_t *buffer;
};

enum cc_stat {
  CC_OK                   = 0,

  CC_ERR_ALLOC            = 1,
  CC_ERR_INVALID_CAPACITY = 2,
  CC_ERR_INVALID_RANGE    = 3,
  CC_ERR_MAX_CAPACITY     = 4,
  CC_ERR_KEY_NOT_FOUND    = 6,
  CC_ERR_VALUE_NOT_FOUND  = 7,
  CC_ERR_OUT_OF_RANGE     = 8,

  CC_ITER_END             = 9,
};


/* Allocate and destroy buffer for vector */
enum cc_stat vector_init(struct vector *vec, int cap);
void vector_destory(struct vector *vec);
enum cc_stat vector_reserve(struct vector *vec, int new_cap);

/* Print vector content */
void vector_print(struct vector *vec);

/* Insert element */
enum cc_stat vector_insert(struct vector *vec, int pos, elem_t value);
enum cc_stat vector_push_back(struct vector *vec, elem_t value);
enum cc_stat vector_push_front(struct vector *vec, elem_t value);

/* Find element */
int vector_find_first(struct vector *vec, elem_t value);
int vector_find_next(struct vector *vec, elem_t value, int start_pos);

/* Delete element */
enum cc_stat vector_remove_at(struct vector *vec, int pos);
enum cc_stat vector_pop_front(struct vector *vec);
enum cc_stat vector_pop_back(struct vector *vec);
void vector_delete_value(struct vector *vec, elem_t value);

/* Set operations */
void vector_union(struct vector *c, struct vector *a, struct vector *b);
void vector_intersection(struct vector *c, struct vector *a, struct vector *b);

/* Methods to be implemented */
void vector_reverse(struct vector *vec);
void vector_swap(struct vector *a, struct vector *b);
enum cc_stat vector_shrink_to_fit(struct vector *vec);
elem_t vector_at(struct vector *vec, int index);
