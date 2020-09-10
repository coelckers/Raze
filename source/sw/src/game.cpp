//-------------------------------------------------------------------------
/*
Copyright (C) 1997, 2005 - 3D Realms Entertainment

This file is part of Shadow Warrior version 1.2

Shadow Warrior is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

Original Source: 1997 - Frank Maddin and Jim Norwood
Prepared for public release: 03/28/2005 - Charlie Wiederhold, 3D Realms
*/
//-------------------------------------------------------------------------

#include "ns.h"

#define MAIN
#define QUIET
#include "build.h"
#include "names2.h"
#include "panel.h"
#include "game.h"
#include "interp.h"
#include "interpso.h"
#include "tags.h"
#include "sector.h"
#include "sprite.h"
#include "weapon.h"
#include "player.h"
#include "lists.h"
#include "network.h"
#include "pal.h"
#include "automap.h"
#include "statusbar.h"


#include "mytypes.h"

#include "menus.h"

#include "gamecontrol.h"

#include "misc.h"

#include "misc.h"
#include "break.h"
#include "light.h"
#include "misc.h"
#include "jsector.h"

#include "gameconfigfile.h"
#include "printf.h"
#include "m_argv.h"
#include "debugbreak.h"
#include "menu.h"
#include "raze_music.h"
#include "statistics.h"
#include "gstrings.h"
#include "mapinfo.h"
#include "v_video.h"
#include "raze_sound.h"
#include "secrets.h"

#include "screenjob.h"
#include "inputstate.h"
#include "gamestate.h"
#include "d_net.h"

//#include "crc32.h"

CVAR(Bool, sw_ninjahack, false, CVAR_ARCHIVE | CVAR_GLOBALCONFIG | CVAR_SERVERINFO);
CVAR(Bool, sw_darts, false, CVAR_ARCHIVE | CVAR_GLOBALCONFIG);
CVAR(Bool, sw_bunnyrockets, false, CVAR_SERVERINFO | CVAR_CHEAT);   // This is a cheat, so don't save.

BEGIN_SW_NS

void Logo(const CompletionFunc& completion);
void StatScreen(int FinishAnim, CompletionFunc completion);


void pClearSpriteList(PLAYERp pp);

extern int sw_snd_scratch;

int GameVersion = 20;

bool NoMeters = false;
int FinishAnim = 0;
bool ReloadPrompt = false;
bool NewGame = false;
bool SavegameLoaded = false;
//Miscellaneous variables
bool FinishedLevel = false;
short screenpeek = 0;

bool PreCaching = true;
int GodMode = false;
short Skill = 2;
short TotalKillable;

const GAME_SET gs_defaults =
{
// Network game settings
    0, // GameType
    0, // Monsters
    false, // HurtTeammate
    true, // SpawnMarkers Markers
    false, // TeamPlay
    0, // Kill Limit
    0, // Time Limit
    0, // Color
    true, // nuke
};
GAME_SET gs;

bool PlayerTrackingMode = false;
bool SlowMode = false;

bool DebugOperate = false;
void LoadingLevelScreen(void);

uint8_t FakeMultiNumPlayers;

int totalsynctics;

int OrigCommPlayers=0;
extern uint8_t CommPlayers;
extern bool CommEnabled;

bool CameraTestMode = false;

char ds[645];                           // debug string

extern short NormalVisibility;
bool CommandSetup = false;

char buffer[80], ch;

uint8_t DebugPrintColor = 255;

FString ThemeSongs[6];
int ThemeTrack[6];

/// L O C A L   P R O T O T Y P E S /////////////////////////////////////////////////////////
void SybexScreen(void);
/////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
//
//
//
//---------------------------------------------------------------------------

void GameInterface::app_init()
{
    GameTicRate = 40;
    InitCheats();
    automapping = 1;

    gs = gs_defaults;

    for (int i = 0; i < MAX_SW_PLAYERS; i++)
        INITLIST(&Player[i].PanelSpriteList);

    DebugOperate = true;
    enginecompatibility_mode = ENGINECOMPATIBILITY_19961112;

    if (SW_SHAREWARE)
        Printf("SHADOW WARRIOR(tm) Version 1.2 (Shareware Version)\n");
    else
        Printf("SHADOW WARRIOR(tm) Version 1.2\n");

    if (sw_snd_scratch == 0)    // This is always 0 at this point - this check is only here to prevent whole program optimization from eliminating the variable.
        Printf("Copyright (c) 1997 3D Realms Entertainment\n");

    registerosdcommands();

    engineInit();
    auto pal = fileSystem.LoadFile("3drealms.pal", 0);
    if (pal.Size() >= 768)
    {
        for (auto& c : pal)
            c <<= 2;

        paletteSetColorTable(DREALMSPAL, pal.Data(), true, true);
    }
    InitPalette();
    // sets numplayers, connecthead, connectpoint2, myconnectindex

	numplayers = 1; myconnectindex = 0;
	connecthead = 0; connectpoint2[0] = -1;

    if (SW_SHAREWARE && numplayers > 4)
    {
        I_FatalError("To play a Network game with more than 4 players you must purchase "
            "the full version.  Read the Ordering Info screens for details.");
    }

    TileFiles.LoadArtSet("tiles%03d.art");
    InitFonts();

    //Connect();
    SortBreakInfo();
    parallaxtype = 1;
    SW_InitMultiPsky();

    memset(Track, 0, sizeof(Track));
    memset(Player, 0, sizeof(Player));
    for (int i = 0; i < MAX_SW_PLAYERS; i++)
        INITLIST(&Player[i].PanelSpriteList);

    LoadKVXFromScript("swvoxfil.txt");    // Load voxels from script file
    LoadPLockFromScript("swplock.txt");   // Get Parental Lock setup info
	LoadCustomInfoFromScript("engine/swcustom.txt");	// load the internal definitions. These also apply to the shareware version.
    if (!SW_SHAREWARE)
        LoadCustomInfoFromScript("swcustom.txt");   // Load user customisation information
 
    if (!loaddefinitionsfile(G_DefFile())) Printf(PRINT_NONOTIFY, "Definitions file loaded.\n");
    TileFiles.SetBackup();
    userConfig.AddDefs.reset();
    InitFX();
}

//---------------------------------------------------------------------------
//
//
//
//---------------------------------------------------------------------------

void GameInterface::DrawBackground(void)
{
    const int TITLE_PIC = 2324;
    twod->ClearScreen();
    DrawTexture(twod, tileGetTexture(TITLE_PIC), 0, 0, DTA_FullscreenEx, FSMode_ScaleToFit43, DTA_LegacyRenderStyle, STYLE_Normal,
        DTA_Color, shadeToLight(20), TAG_DONE);

    if (CommEnabled)
    {
        MNU_DrawString(160, 170, "Lo Wang is waiting for other players...", 1, 16, 0);
        MNU_DrawString(160, 180, "They are afraid!", 1, 16, 0);
    }
}

//---------------------------------------------------------------------------
//
//
//
//---------------------------------------------------------------------------

void InitLevelGlobals(void)
{
    ChopTics = 0;
    automapMode = am_off;
    PlayerGravity = 24;
    wait_active_check_offset = 0;
    PlaxCeilGlobZadjust = PlaxFloorGlobZadjust = Z(500);
    FinishedLevel = false;
    AnimCnt = 0;
    left_foot = false;
    screenpeek = myconnectindex;
    numinterpolations = short_numinterpolations = 0;

    gNet.TimeLimitClock = gNet.TimeLimit;

    serpwasseen = false;
    sumowasseen = false;
    zillawasseen = false;
    memset(BossSpriteNum,-1,sizeof(BossSpriteNum));
}

//---------------------------------------------------------------------------
//
// GLOBAL RESETS NOT DONE for LOAD GAME
//
//---------------------------------------------------------------------------

void InitLevelGlobals2(void)
{
    InitTimingVars();
    TotalKillable = 0;
    Bunny_Count = 0;
    FinishAnim = false;
}

//---------------------------------------------------------------------------
//
//
//
//---------------------------------------------------------------------------

void InitLevel(MapRecord *maprec)
{
    Terminate3DSounds();

    // A few IMPORTANT GLOBAL RESETS
    InitLevelGlobals();

    Mus_Stop();

    if (!maprec)
    {
        I_Error("Attempt to start game without level");
        return;
    }
    InitLevelGlobals2();

    if (NewGame)
    {
        for (int i = 0; i < MAX_SW_PLAYERS; i++)
        {
            // don't jack with the playerreadyflag
            int ready_bak = Player[i].playerreadyflag;
            int ver_bak = Player[i].PlayerVersion;
            memset(&Player[i], 0, sizeof(Player[i]));
            Player[i].playerreadyflag = ready_bak;
            Player[i].PlayerVersion = ver_bak;
            INITLIST(&Player[i].PanelSpriteList);
        }

        memset(puser, 0, sizeof(puser));
    }

    int16_t ang;
    if (engineLoadBoard(maprec->fileName, SW_SHAREWARE ? 1 : 0, (vec3_t*)&Player[0], &ang, &Player[0].cursectnum) == -1)
    {
        I_Error("Map not found: %s", maprec->fileName.GetChars());
    }
    currentLevel = maprec;
    SECRET_SetMapName(currentLevel->DisplayName(), currentLevel->name);
    STAT_NewLevel(currentLevel->fileName);
    Player[0].q16ang = IntToFixed(ang);

    SetupPreCache();

    if (sector[0].extra != -1)
    {
        NormalVisibility = g_visibility = sector[0].extra;
        sector[0].extra = 0;
    }
    else
        NormalVisibility = g_visibility;

    //
    // Do Player stuff first
    //

    InitAllPlayers();

    QueueReset();
    PreMapCombineFloors();
    InitMultiPlayerInfo();
    InitAllPlayerSprites();

    //
    // Do setup for sprite, track, panel, sector, etc
    //

    // Set levels up
    InitTimingVars();

    SpriteSetup();
    SpriteSetupPost(); // post processing - already gone once through the loop
    InitLighting();

    TrackSetup();

    PlayerPanelSetup();
    SectorSetup();
    JS_InitMirrors();
    JS_InitLockouts();   // Setup the lockout linked lists
    JS_ToggleLockouts(); // Init lockouts on/off

    PlaceSectorObjectsOnTracks();
    PlaceActorsOnTracks();
    PostSetupSectorObject();
    SetupMirrorTiles();
    initlava();

    // reset NewGame
    NewGame = false;
	setLevelStarted(maprec);
}

//---------------------------------------------------------------------------
//
//
//
//---------------------------------------------------------------------------

void InitPlayerGameSettings(void)
{
    int pnum;

    if (CommEnabled)
    {
        // everyone gets the same Auto Aim
        TRAVERSE_CONNECT(pnum)
        {
            if (gNet.AutoAim)
                SET(Player[pnum].Flags, PF_AUTO_AIM);
            else
                RESET(Player[pnum].Flags, PF_AUTO_AIM);
        }
    }
    else
    {
        if (cl_autoaim)
            SET(Player[myconnectindex].Flags, PF_AUTO_AIM);
        else
            RESET(Player[myconnectindex].Flags, PF_AUTO_AIM);
    }
}

//---------------------------------------------------------------------------
//
//
//
//---------------------------------------------------------------------------

void InitRunLevel(void)
{
    Mus_Stop();

    DoTheCache();

    // auto aim / auto run / etc
    InitPlayerGameSettings();

    // send packets with player info
    InitNetPlayerOptions();

    // Initialize Game part of network code
    InitNetVars();

    if (currentLevel)
    {
        PlaySong(currentLevel->labelName, currentLevel->music, currentLevel->cdSongId);
    }

    InitPrediction(&Player[myconnectindex]);

    InitTimingVars();

    if (snd_ambience)
        StartAmbientSound();
}


//---------------------------------------------------------------------------
//
//
//
//---------------------------------------------------------------------------

void TerminateLevel(void)
{
    videoFadePalette(0, 0, 0, 0);
    if (!currentLevel) return;

    int i, nexti, stat, pnum, ndx;
    SECT_USERp* sectu;

    // Free any track points
    for (ndx = 0; ndx < MAX_TRACKS; ndx++)
    {
        if (Track[ndx].TrackPoint)
        {
            FreeMem(Track[ndx].TrackPoint);
            // !JIM! I added null assigner
            Track[ndx].TrackPoint = NULL;
        }
    }

    // Clear the tracks
    memset(Track, 0, sizeof(Track));

    StopFX();

    // Clear all anims and any memory associated with them
    // Clear before killing sprites - save a little time
    //AnimClear();

    for (stat = STAT_PLAYER0; stat < STAT_PLAYER0 + numplayers; stat++)
    {

        pnum = stat - STAT_PLAYER0;

        TRAVERSE_SPRITE_STAT(headspritestat[stat], i, nexti)
        {
            if (User[i])
                memcpy(&puser[pnum], User[i], sizeof(USER));
        }
    }

    // Kill User memory and delete sprites
    // for (stat = 0; stat < STAT_ALL; stat++)
    for (stat = 0; stat < MAXSTATUS; stat++)
    {
        TRAVERSE_SPRITE_STAT(headspritestat[stat], i, nexti)
        {
            KillSprite(i);
        }
    }

    // Free SectUser memory
    for (sectu = &SectUser[0];
        sectu < &SectUser[MAXSECTORS];
        sectu++)
    {
        if (*sectu)
        {
            FreeMem(*sectu);
            *sectu = NULL;
        }
    }

    //memset(&User[0], 0, sizeof(User));
    memset(&SectUser[0], 0, sizeof(SectUser));

    TRAVERSE_CONNECT(pnum)
    {
        PLAYERp pp = Player + pnum;

        // Free panel sprites for players
        pClearSpriteList(pp);

        pp->cookieTime = 0;
        memset(pp->cookieQuote, 0, sizeof(pp->cookieQuote));
        pp->DoPlayerAction = NULL;

        pp->SpriteP = NULL;
        pp->PlayerSprite = -1;

        pp->UnderSpriteP = NULL;
        pp->PlayerUnderSprite = -1;

        memset(pp->HasKey, 0, sizeof(pp->HasKey));

        //pp->WpnFlags = 0;
        pp->CurWpn = NULL;

        memset(pp->Wpn, 0, sizeof(pp->Wpn));
        memset(pp->InventoryTics, 0, sizeof(pp->InventoryTics));

        pp->Killer = -1;

        INITLIST(&pp->PanelSpriteList);
    }

    JS_UnInitLockouts();
}


void GameInterface::LevelCompleted(MapRecord *map, int skill)
{
	//ResetPalette(mpp);
	COVER_SetReverb(0); // Reset reverb
	Player[myconnectindex].Reverb = 0;
	StopSound();

	StatScreen(FinishAnim, [=](bool)
		{
			if (map == nullptr)
			{
				STAT_Update(true);
				FinishAnim = false;
				PlaySong(nullptr, ThemeSongs[0], ThemeTrack[0]);
				if (SW_SHAREWARE) gameaction = ga_creditsmenu;
				else gameaction = ga_mainmenu;
			}
			else gameaction = ga_nextlevel;
		});

}
//---------------------------------------------------------------------------
//
//
//
//---------------------------------------------------------------------------

void GameInterface::NextLevel(MapRecord *map, int skill)
{
	if (skill != -1) Skill = skill;
	ShadowWarrior::NewGame = false;
	InitLevel(map);
	InitRunLevel();
}

//---------------------------------------------------------------------------
//
//
//
//---------------------------------------------------------------------------

void GameInterface::NewGame(MapRecord *map, int skill)
{
	if (skill != -1) Skill = skill;
	ShadowWarrior::NewGame = true;
	InitLevel(map);
	InitRunLevel();
}

//---------------------------------------------------------------------------
//
//
//
//---------------------------------------------------------------------------

void GameInterface::Ticker(void)
{
	if (SavegameLoaded)
	{
		InitLevelGlobals();
		SavegameLoaded = false;
		// contains what is needed from calls below
		if (snd_ambience)
			StartAmbientSound();
	}

    int i;
    TRAVERSE_CONNECT(i)
    {
        auto pp = Player + i;
        pp->lastinput = pp->input;
        pp->input = playercmds[i].ucmd;
    }

    domovethings();
    r_NoInterpolate = paused;
}

//---------------------------------------------------------------------------
//
//
//
//---------------------------------------------------------------------------

void GameInterface::Render()
{
    if (paused)
    {
        smoothratio = MaxSmoothRatio;
    }
    else
    {
        smoothratio = I_GetTimeFrac() * MaxSmoothRatio;
    }

    drawtime.Reset();
    drawtime.Clock();
    drawscreen(Player + screenpeek, smoothratio);
    drawtime.Unclock();
}


void GameInterface::Startup()
{
    if (userConfig.CommandMap.IsNotEmpty())
    {
    }
    else
    {
		if (!userConfig.nologo) Logo([](bool) 
            { 
                gameaction = ga_mainmenunostopsound;
            });
        else gameaction = ga_mainmenu;
    }
}


void GameInterface::ErrorCleanup()
{
    // Make sure we do not leave the game in an unstable state
    TerminateLevel();
    SavegameLoaded = false;
    FinishAnim = false;
}
//---------------------------------------------------------------------------
//
//
//
//---------------------------------------------------------------------------

int RandomRange(int range)
{
    uint32_t rand_num;
    uint32_t value;

    if (range <= 0)
        return 0;

    rand_num = RANDOM();

    if (rand_num == 65535U)
        rand_num--;

    // shift values to give more precision
    value = (rand_num << 14) / ((65535UL << 14) / range);

    if (value >= (uint32_t)range)
        value = range - 1;

    return value;
}

//---------------------------------------------------------------------------
//
//
//
//---------------------------------------------------------------------------

int StdRandomRange(int range)
{
    uint32_t rand_num;
    uint32_t value;

    if (range <= 0)
        return 0;

    rand_num = STD_RANDOM();

    if (rand_num == RAND_MAX)
        rand_num--;

    // shift values to give more precision
#if (RAND_MAX > 0x7fff)
    value = rand_num / (((int)RAND_MAX) / range);
#else
    value = (rand_num << 14) / ((((int)RAND_MAX) << 14) / range);
#endif

    if (value >= (uint32_t)range)
        value = range - 1;

    return value;
}

//---------------------------------------------------------------------------
//
//
//
//---------------------------------------------------------------------------

#include "saveable.h"

saveable_module saveable_build{};

void Saveable_Init_Dynamic()
{
    static saveable_data saveable_build_data[] =
    {
        {sector, MAXSECTORS*sizeof(sectortype)},
        {sprite, MAXSPRITES*sizeof(spritetype)},
        {wall, MAXWALLS*sizeof(walltype)},
    };

    saveable_build.data = saveable_build_data;
    saveable_build.numdata = NUM_SAVEABLE_ITEMS(saveable_build_data);
}

//---------------------------------------------------------------------------
//
//
//
//---------------------------------------------------------------------------

ReservedSpace GameInterface::GetReservedScreenSpace(int viewsize)
{
    return { 0, 48 };
}

::GameInterface* CreateInterface()
{
	return new GameInterface;
}

GameStats GameInterface::getStats()
{
	PLAYERp pp = Player + myconnectindex;
	return { pp->Kills, TotalKillable, pp->SecretsFound, LevelSecrets, PlayClock / 120, 0 };
}

void GameInterface::FreeGameData()
{
    TerminateLevel();
}

void GameInterface::FreeLevelData()
{
    TerminateLevel();
    ::GameInterface::FreeLevelData();
}

END_SW_NS
