
#ifndef TKQUAKE_MACRO_DEFINITIONS_H
#define TKQUAKE_MACRO_DEFINITIONS_H

#define MACRO_DEF(x) macro_ ## x

typedef enum {
#include "macro_ids.h"
	num_macros
} macro_id;

#undef MACRO_DEF

#endif // TKQUAKE_MACRO_DEFINITIONS_H
