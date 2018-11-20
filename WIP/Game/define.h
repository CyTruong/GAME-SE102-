#pragma once
#define SCREEN_WIDTH 300	
#define SCREEN_HEIGHT 200
#define FULLSCREEN 0
#define SPRITE_SOURCE "..\\Resources\\"  // nơi chứa sprite
#define ANIMATIONUPDATEDELAY 30 //ms

#define TRANSCOLOR D3DCOLOR_XRGB(255,255,255)

//Zero animation
#define ZERO_IDLE "Zero_Idle.json"
#define ZERO_IDLEID 0
#define ZERO_IDLEDELAY 4

#define ZERO_RUNRIGHT "Zero_Run.json"
#define ZERO_RUNRIGHTID DIK_RIGHTARROW
#define ZERO_RUNRIGHTDELAY 2


//Megaman animation
#define MEGAMAN_IDLE "Megaman_Idle.json"
#define MEGAMAN_IDLEID 0
#define MEGAMAN_IDLEDELAY 6

#define MEGAMAN_RUNRIGHT "Megaman_Run.json"
#define MEGAMAN_RUNRIGHTID DIK_RIGHTARROW
#define MEGAMAN_RUNRIGHTDELAY 2


#define MEGAMAN_CHARGE_RUN "Megaman_Charge_Run.json"
#define MEGAMAN_CHARGE_RUNID DIK_DOWNARROW
#define MEGAMAN_CHARGE_RUNDELAY 2

#define MEGAMAN_CHARGE "Megaman_Charge.json"
#define MEGAMAN_CHARGEID DIK_SPACE
#define MEGAMAN_CHARGEDELAY 6

#define MEGAMAN_JUMP "Megaman_Jump.json"
#define MEGAMAN_JUMPID DIK_X
#define MEGAMAN_JUMPDELAY 4

#define MEGAMAN_JUMP_SHOOT "Megaman_Jump_Shoot.json"
#define MEGAMAN_JUMP_SHOOTID DIK_UPARROW+DIK_SPACE
#define MEGAMAN_JUMP_SHOOTDELAY 4

#define MEGAMAN_SLIDE "Megaman_Slide.json"
#define MEGAMAN_SLIDEID DIK_Z
#define MEGAMAN_SLIDEDELAY 10

#define MEGAMAN_SLIDE_CHARGE "Megaman_Slide_Charge.json"
#define MEGAMAN_SLIDE_CHARGEID DIK_C
#define MEGAMAN_SLIDE_CHARGEDELAY 10