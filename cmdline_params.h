
#ifndef TKQUAKE_CMDLINE_PARAMS_H
#define TKQUAKE_CMDLINE_PARAMS_H

#define CMDLINE_DEF(x, str) cmdline_param_ ## x

typedef enum {
#include "cmdline_params_ids.h"
	num_cmdline_params
} cmdline_param_id;

#undef CMDLINE_DEF

#endif // TKQUAKE_CMDLINE_PARAMS_H

