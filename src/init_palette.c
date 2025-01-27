

#include "../include/fractol.h"

void init_palette_R(int palette_R[20])
{
    palette_R[0] = 0x000000; 
    palette_R[1] = 0x330000; 
    palette_R[2] = 0x663300; 
    palette_R[3] = 0x993300; 
    palette_R[4] = 0xCC3300; 
    palette_R[5] = 0xFF3300; 
    palette_R[6] = 0xFF6633; 
    palette_R[7] = 0xFF9966; 
    palette_R[8] = 0xFFCC99; 
    palette_R[9] = 0xFFCC66; 
    palette_R[10] = 0xFFD966; 
    palette_R[11] = 0xFFE0B3; 
    palette_R[12] = 0xFFE6B3; 
    palette_R[13] = 0xFFB366; 
    palette_R[14] = 0xFF9966; 
    palette_R[15] = 0xFF4C00; 
    palette_R[16] = 0xCC6600; 
    palette_R[17] = 0x993300; 
    palette_R[18] = 0xFF3300; 
    palette_R[19] = 0xFFFFFF; 
}

void init_palette_B(int palette_B[20])
{
    palette_B[0] = 0x000000; 
    palette_B[1] = 0x000033; 
    palette_B[2] = 0x000066; 
    palette_B[3] = 0x000099; 
    palette_B[4] = 0x0000CC; 
    palette_B[5] = 0x0000FF; 
    palette_B[6] = 0x4C4CFF; 
    palette_B[7] = 0x8080FF; 
    palette_B[8] = 0xA6A6FF; 
    palette_B[9] = 0xB3B3FF; 
    palette_B[10] = 0xCCCCFF; 
    palette_B[11] = 0xD1A6FF; 
    palette_B[12] = 0xE0A6FF; 
    palette_B[13] = 0xF2A6FF; 
    palette_B[14] = 0xF2B3FF; 
    palette_B[15] = 0xF2CCE6; 
    palette_B[16] = 0xF2E0FF; 
    palette_B[17] = 0xE6E6FF; 
    palette_B[18] = 0x000099; 
    palette_B[19] = 0xFFFFFF; 
}


void init_palette_G(int palette_G[20])
{
    palette_G[0] = 0x000000;
    palette_G[1] = 0x003300; 
    palette_G[2] = 0x336600; 
    palette_G[3] = 0x669900; 
    palette_G[4] = 0x99CC00; 
    palette_G[5] = 0xCCFF00; 
    palette_G[6] = 0x99FF33; 
    palette_G[7] = 0xCCFF66; 
    palette_G[8] = 0xFFFF99; 
    palette_G[9] = 0xFFFF66; 
    palette_G[10] = 0xFFFF33; 
    palette_G[11] = 0xFFCC00; 
    palette_G[12] = 0xFF9900; 
    palette_G[13] = 0xFF6600; 
    palette_G[14] = 0xFF3300; 
    palette_G[15] = 0xFFFF00; 
    palette_G[16] = 0xFFFF33; 
    palette_G[17] = 0xCCFF00; 
    palette_G[18] = 0x99CC00; 
    palette_G[19] = 0xFFFFFF; 
}

void palette_init(t_palette *palette)
{
    int i;

    i = 0;
	init_palette_R(palette->palette_R);
	init_palette_B(palette->palette_B);
	init_palette_G(palette->palette_G);
    while (i < 20)
    {
        palette->palettes[0][i] = palette->palette_R[i];
        i++;
    }
    i = 0;
    while (i < 20)
    {
        palette->palettes[1][i] = palette->palette_G[i];
        i++;
    }
    i = 0;
    while (i < 20)
    {
        palette->palettes[2][i] = palette->palette_B[i];
        i++;
    }
}

