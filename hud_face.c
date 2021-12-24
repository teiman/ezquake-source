/*
Copyright (C) 2011 azazello and tkQuake team

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "quakedef.h"
#include "common_draw.h"
#include "hud.h"
#include "hud_common.h"


float HUD_CalcBobY(void);
float HUD_CalcBobX(void);

// face
void SCR_HUD_DrawFace(hud_t *hud)
{
	extern mpic_t  *sb_faces[5][2]; // 0 is dead, 1-4 are alive
									// 0 is static, 1 is temporary animation
	extern mpic_t  *sb_face_invis;
	extern mpic_t  *sb_face_quad;
	extern mpic_t  *sb_face_invuln;
	extern mpic_t  *sb_face_invis_invuln;
	
	int     f, anim;
	int     x, y;
	float   scale;
	float	current_health = HUD_Stats(STAT_HEALTH);

	static cvar_t *v_scale = NULL;
	if (v_scale == NULL)  // first time called
	{
		v_scale = HUD_FindVar(hud, "scale");
	}

	scale = max(v_scale->value, 0.01);

	if (cl.spectator != cl.autocam)
		return;	

	if (!HUD_PrepareDraw(hud, 24 * scale, 24 * scale, &x, &y))
		return;

	x = 8;
	y = y - sb_faces[0][0]->height+4;

	float ff = (fabs(sin(cl.time * 16)) + 0.8 * 3) / 4;
	if (current_health >= 100)
		f = 4;
	else
		f = max(0, current_health) / 20;

	if (cl.time <= cl.faceanimtime)
		anim = 1;
	else
		anim = 0;

	x = x + (float)HUD_CalcBobX();
	y = y + (float)HUD_CalcBobY();

	if (current_health<1) {
		Draw_SAlphaPic(x, y, sb_faces[0][anim], ff, scale);//SB_FACE5, death
		return;
	}

	if ((HUD_Stats(STAT_ITEMS) & (IT_INVISIBILITY | IT_INVULNERABILITY))
		== (IT_INVISIBILITY | IT_INVULNERABILITY)) {
		Draw_SAlphaPic(x, y, sb_face_invis_invuln, 1, scale);
		Draw_SAlphaPic(x, y, sb_faces[f][anim], 1 - ff, scale);
		return;
	}
	if (HUD_Stats(STAT_ITEMS) & IT_QUAD) {
		Draw_SAlphaPic(x, y, sb_face_quad, 1, scale);
		Draw_SAlphaPic(x, y, sb_faces[f][anim], 1 - ff, scale);
		return;
	}
	if (HUD_Stats(STAT_ITEMS) & IT_INVISIBILITY) {
		Draw_SAlphaPic(x, y, sb_face_invis, 1, scale);
		Draw_SAlphaPic(x, y, sb_faces[f][anim], 1 - ff, scale);
		return;
	}
	if (HUD_Stats(STAT_ITEMS) & IT_INVULNERABILITY) {		
		Draw_SAlphaPic(x, y, sb_face_invuln, 1, scale);
		Draw_SAlphaPic(x, y, sb_faces[f][anim], 1 - ff, scale);
		return;
	}
	
	Draw_SAlphaPic(x, y, sb_faces[f][anim], ff, scale);
}

void Face_HudInit(void)
{
	// player face (health indicator)
	HUD_Register(
		"face", NULL, "Your bloody face.",
		HUD_INVENTORY, ca_active, 0, SCR_HUD_DrawFace,
		"1", "screen", "center", "bottom", "0", "0", "0", "0 0 0", NULL,
		"scale", "1",
		NULL
	);
}
