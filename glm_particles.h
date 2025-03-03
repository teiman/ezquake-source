/*
Copyright (C) 2018 tkQuake team.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef TKQUAKE_GLM_PARTICLES_HEADER
#define TKQUAKE_GLM_PARTICLES_HEADER

#include "glm_texture_arrays.h"
#include "r_texture.h"

extern texture_ref particletexture_array;
extern int particletexture_array_index;

void GLM_LoadParticleTextures(void);
void Part_ImportTexturesForArrayReferences(texture_flag_t* texture_flags);
void Part_FlagTexturesForArray(texture_flag_t* texture_flags);

#endif // TKQUAKE_GLM_PARTICLES_HEADER
