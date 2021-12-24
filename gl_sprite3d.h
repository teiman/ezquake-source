
#ifndef TKQUAKE_GL_SPRITE3D_HEADER
#define TKQUAKE_GL_SPRITE3D_HEADER

#include "r_sprite3d.h"
#include "r_sprite3d_internal.h"

// GL only
extern GLenum glPrimitiveTypes[r_primitive_count];

void GL_DrawSequentialBatchImpl(gl_sprite3d_batch_t* batch, int first_batch, int last_batch, int index_offset, GLuint maximum_batch_size);

extern int indexes_start_quads;
extern int indexes_start_flashblend;
extern int indexes_start_sparks;

#endif // #ifndef TKQUAKE_GL_SPRITE3D_HEADER
