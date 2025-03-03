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

#ifndef TKQUAKE_VK_VAO_HEADER
#define TKQUAKE_VK_VAO_HEADER

#include "r_vao.h"

void VK_DeleteVAOs(void);
void VK_GenVertexArray(r_vao_id vao, const char* name);
qbool VK_VertexArrayCreated(r_vao_id vao);
void VK_BindVertexArray(r_vao_id vao);
qbool VK_InitialiseVAOHandling(void);

#endif // TKQUAKE_VK_VAO_HEADER

