/*
Copyright (C) 1996-1997 Id Software, Inc.

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

// the status bar is only redrawn if something has changed, but if anything
// does, the entire thing will be redrawn for the next vid.numpages frames.

#ifndef TKQUAKE_SBAR_HEADER
#define TKQUAKE_SBAR_HEADER

#define	SBAR_HEIGHT		24

extern	int			sb_lines;			// scan lines to draw

void Sbar_Init (void);

void Sbar_Changed (void);
// call whenever any of the client stats represented on the sbar changes

void Sbar_Draw (void);
// called every frame by screen

void Sbar_IntermissionOverlay (void);
// called each frame after the level has been completed

void Sbar_FinaleOverlay (void);

int Sbar_TopColor(player_info_t *player);
int Sbar_BottomColor(player_info_t *player);

void Sbar_DrawNum (int x, int y, int num, int digits, int color);

// covert quake pallete color number to rgb color
int Sbar_ColorForMap (int m);

#define STAT_MINUS		10	// num frame for '-' stats digit

void Sbar_DrawPic(int x, int y, mpic_t *pic);
void Sbar_DrawString(int x, int y, char *str);
qbool Sbar_IsStandardBar(void);

void Sbar_DrawTrackingString(void);
void Sbar_DrawSpectatorMessage(void);

#endif // #ifdef TKQUAKE_SBAR_HEADER
