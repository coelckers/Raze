//-------------------------------------------------------------------------
/*
Copyright (C) 1996, 2003 - 3D Realms Entertainment

This file is part of Duke Nukem 3D version 1.5 - Atomic Edition

Duke Nukem 3D is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

Original Source: 1996 - Todd Replogle
Prepared for public release: 03/21/2003 - Charlie Wiederhold, 3D Realms
*/
//-------------------------------------------------------------------------
#pragma once

BEGIN_DUKE_NS

enum
{
	ARROW = 20,
	FIRSTGUNSPRITE = 21,
	CHAINGUNSPRITE = 22,
	RPGSPRITE = 23,
	FREEZESPRITE = 24,
	SHRINKERSPRITE = 25,
	HEAVYHBOMB = 26,
	TRIPBOMBSPRITE = 27,
	SHOTGUNSPRITE = 28,
	DEVISTATORSPRITE = 29,
	HEALTHBOX = 30,
	AMMOBOX = 31,
	GROWSPRITEICON = 32,
	INVENTORYBOX = 33,
	FREEZEAMMO = 37,
	AMMO = 40,
	BATTERYAMMO = 41,
	DEVISTATORAMMO = 42,
	RPGAMMO = 44,
	GROWAMMO = 45,
	CRYSTALAMMO = 46,
	HBOMBAMMO = 47,
	AMMOLOTS = 48,
	SHOTGUNAMMO = 49,
	COLA = 51,
	SIXPAK = 52,
	FIRSTAID = 53,
	SHIELD = 54,
	STEROIDS = 55,
	AIRTANK = 56,
	JETPACK = 57,
	HEATSENSOR = 59,
	ACCESSCARD = 60,
	BOOTS = 61,
	MIRRORBROKE = 70,
	CLOUDYOCEAN = 78,
	CLOUDYSKIES = 79,
	MOONSKY1 = 80,
	MOONSKY2 = 81,
	MOONSKY3 = 82,
	MOONSKY4 = 83,
	BIGORBIT1 = 84,
	BIGORBIT2 = 85,
	BIGORBIT3 = 86,
	BIGORBIT4 = 87,
	BIGORBIT5 = 88,
	LA = 89,
	REDSKY1 = 98,
	REDSKY2 = 99,
	ATOMICHEALTH = 100,
	TECHLIGHT2 = 120,
	TECHLIGHTBUST2 = 121,
	TECHLIGHT4 = 122,
	TECHLIGHTBUST4 = 123,
	WALLLIGHT4 = 124,
	WALLLIGHTBUST4 = 125,
	ACCESSSWITCH = 130,
	SLOTDOOR = 132,
	LIGHTSWITCH = 134,
	SPACEDOORSWITCH = 136,
	SPACELIGHTSWITCH = 138,
	FRANKENSTINESWITCH = 140,
	NUKEBUTTON = 142,
	MULTISWITCH = 146,
	DOORTILE5 = 150,
	DOORTILE6 = 151,
	DOORTILE1 = 152,
	DOORTILE2 = 153,
	DOORTILE3 = 154,
	DOORTILE4 = 155,
	DOORTILE7 = 156,
	DOORTILE8 = 157,
	DOORTILE9 = 158,
	DOORTILE10 = 159,
	DOORSHOCK = 160,
	DIPSWITCH = 162,
	DIPSWITCH2 = 164,
	TECHSWITCH = 166,
	DIPSWITCH3 = 168,
	ACCESSSWITCH2 = 170,
	REFLECTWATERTILE = 180,
	FLOORSLIME = 200,
	BIGFORCE = 230,
	EPISODE = 247,
	MASKWALL9 = 255,
	W_LIGHT = 260,
	SCREENBREAK1 = 263,
	SCREENBREAK2 = 264,
	SCREENBREAK3 = 265,
	SCREENBREAK4 = 266,
	SCREENBREAK5 = 267,
	SCREENBREAK6 = 268,
	SCREENBREAK7 = 269,
	SCREENBREAK8 = 270,
	SCREENBREAK9 = 271,
	SCREENBREAK10 = 272,
	SCREENBREAK11 = 273,
	SCREENBREAK12 = 274,
	SCREENBREAK13 = 275,
	MASKWALL1 = 285,
	W_TECHWALL1 = 293,
	W_TECHWALL2 = 297,
	W_TECHWALL15 = 299,
	W_TECHWALL3 = 301,
	W_TECHWALL4 = 305,
	W_TECHWALL10 = 306,
	W_TECHWALL16 = 307,
	WATERTILE2 = 336,
	BPANNEL1 = 341,
	PANNEL1 = 342,
	PANNEL2 = 343,
	WATERTILE = 344,
	STATIC = 351,
	W_SCREENBREAK = 357,
	W_HITTECHWALL3 = 360,
	W_HITTECHWALL4 = 361,
	W_HITTECHWALL2 = 362,
	W_HITTECHWALL1 = 363,
	MASKWALL10 = 387,
	MASKWALL11 = 391,
	DOORTILE22 = 395,
	FANSPRITE = 407,
	FANSPRITEBROKE = 411,
	FANSHADOW = 412,
	FANSHADOWBROKE = 416,
	DOORTILE18 = 447,
	DOORTILE19 = 448,
	DOORTILE20 = 449,
	SPACESHUTTLE = 487,
	SATELLITE = 489,
	VIEWSCREEN2 = 499,
	VIEWSCREENBROKE = 501,
	VIEWSCREEN = 502,
	GLASS = 503,
	GLASS2 = 504,
	STAINGLASS1 = 510,
	MASKWALL5 = 514,
	SATELITE = 516,
	FUELPOD = 517,
	SLIMEPIPE = 538,
	CRACK1 = 546,
	CRACK2 = 547,
	CRACK3 = 548,
	CRACK4 = 549,
	FOOTPRINTS = 550,
	DOMELITE = 551,
	CAMERAPOLE = 554,
	CHAIR1 = 556,
	CHAIR2 = 557,
	BROKENCHAIR = 559,
	MIRROR = 560,
	WATERFOUNTAIN = 563,
	WATERFOUNTAINBROKE = 567,
	FEMMAG1 = 568,
	TOILET = 569,
	STALL = 571,
	STALLBROKE = 573,
	FEMMAG2 = 577,
	REACTOR2 = 578,
	REACTOR2BURNT = 579,
	REACTOR2SPARK = 580,
	GRATE1 = 595,
	BGRATE1 = 596,
	SOLARPANNEL = 602,
	NAKED1 = 603,
	ANTENNA = 607,
	MASKWALL12 = 609,
	TOILETBROKE = 615,
	PIPE2 = 616,
	PIPE1B = 617,
	PIPE3 = 618,
	PIPE1 = 619,
	CAMERA1 = 621,
	BRICK = 626,
	SPLINTERWOOD = 630,
	PIPE2B = 633,
	BOLT1 = 634,
	W_NUMBERS = 640,
	WATERDRIP = 660,
	WATERBUBBLE = 661,
	WATERBUBBLEMAKER = 662,
	W_FORCEFIELD = 663,
	VACUUM = 669,
	FOOTPRINTS2 = 672,
	FOOTPRINTS3 = 673,
	FOOTPRINTS4 = 674,
	EGG = 675,
	SCALE = 678,
	CHAIR3 = 680,
	CAMERALIGHT = 685,
	MOVIECAMERA = 686,
	IVUNIT = 689,
	POT1 = 694,
	POT2 = 695,
	POT3 = 697,
	PIPE3B = 700,
	WALLLIGHT3 = 701,
	WALLLIGHTBUST3 = 702,
	WALLLIGHT1 = 703,
	WALLLIGHTBUST1 = 704,
	WALLLIGHT2 = 705,
	WALLLIGHTBUST2 = 706,
	LIGHTSWITCH2 = 712,
	WAITTOBESEATED = 716,
	DOORTILE14 = 717,
	STATUE = 753,
	MIKE = 762,
	VASE = 765,
	SUSHIPLATE1 = 768,
	SUSHIPLATE2 = 769,
	SUSHIPLATE3 = 774,
	SUSHIPLATE4 = 779,
	DOORTILE16 = 781,
	SUSHIPLATE5 = 792,
	OJ = 806,
	MASKWALL13 = 830,
	HURTRAIL = 859,
	POWERSWITCH1 = 860,
	LOCKSWITCH1 = 862,
	POWERSWITCH2 = 864,
	ATM = 867,
	STATUEFLASH = 869,
	ATMBROKE = 888,
	BIGHOLE2 = 893,
	STRIPEBALL = 901,
	QUEBALL = 902,
	POCKET = 903,
	WOODENHORSE = 904,
	TREE1 = 908,
	TREE2 = 910,
	CACTUS = 911,
	MASKWALL2 = 913,
	MASKWALL3 = 914,
	MASKWALL4 = 915,
	FIREEXT = 916,
	TOILETWATER = 921,
	NEON1 = 925,
	NEON2 = 926,
	CACTUSBROKE = 939,
	BOUNCEMINE = 940,
	BROKEFIREHYDRENT = 950,
	BOX = 951,
	BULLETHOLE = 952,
	BOTTLE1 = 954,
	BOTTLE2 = 955,
	BOTTLE3 = 956,
	BOTTLE4 = 957,
	FEMPIC5 = 963,
	FEMPIC6 = 964,
	FEMPIC7 = 965,
	HYDROPLANT = 969,
	OCEANSPRITE1 = 971,
	OCEANSPRITE2 = 972,
	OCEANSPRITE3 = 973,
	OCEANSPRITE4 = 974,
	OCEANSPRITE5 = 975,
	GENERICPOLE = 977,
	CONE = 978,
	HANGLIGHT = 979,
	HYDRENT = 981,
	MASKWALL14 = 988,
	TIRE = 990,
	PIPE5 = 994,
	PIPE6 = 995,
	PIPE4 = 996,
	PIPE4B = 997,
	BROKEHYDROPLANT = 1003,
	PIPE5B = 1005,
	NEON3 = 1007,
	NEON4 = 1008,
	NEON5 = 1009,
	BOTTLE5 = 1012,
	BOTTLE6 = 1013,
	BOTTLE8 = 1014,
	SPOTLITE = 1020,
	HANGOOZ = 1022,
	MASKWALL15 = 1024,
	BOTTLE7 = 1025,
	HORSEONSIDE = 1026,
	GLASSPIECES = 1031,
	HORSELITE = 1034,
	DONUTS = 1045,
	NEON6 = 1046,
	MASKWALL6 = 1059,
	CLOCK = 1060,
	RUBBERCAN = 1062,
	BROKENCLOCK = 1067,
	PLUG = 1069,
	OOZFILTER = 1079,
	FLOORPLASMA = 1082,
	REACTOR = 1088,
	REACTORSPARK = 1092,
	REACTORBURNT = 1096,
	DOORTILE15 = 1102,
	HANDSWITCH = 1111,
	CIRCLEPANNEL = 1113,
	CIRCLEPANNELBROKE = 1114,
	PULLSWITCH = 1122,
	MASKWALL8 = 1124,
	BIGHOLE = 1141,
	ALIENSWITCH = 1142,
	DOORTILE21 = 1144,
	HANDPRINTSWITCH = 1155,
	BOTTLE10 = 1157,
	BOTTLE11 = 1158,
	BOTTLE12 = 1159,
	BOTTLE13 = 1160,
	BOTTLE14 = 1161,
	BOTTLE15 = 1162,
	BOTTLE16 = 1163,
	BOTTLE17 = 1164,
	BOTTLE18 = 1165,
	BOTTLE19 = 1166,
	DOORTILE17 = 1169,
	MASKWALL7 = 1174,
	JAILBARBREAK = 1175,
	DOORTILE11 = 1178,
	DOORTILE12 = 1179,
	VENDMACHINE = 1212,
	VENDMACHINEBROKE = 1214,
	COLAMACHINE = 1215,
	COLAMACHINEBROKE = 1217,
	CRANEPOLE = 1221,
	CRANE = 1222,
	BARBROKE = 1225,
	BLOODPOOL = 1226,
	NUKEBARREL = 1227,
	NUKEBARRELDENTED = 1228,
	NUKEBARRELLEAKED = 1229,
	CANWITHSOMETHING = 1232,
	MONEY = 1233,
	BANNER = 1236,
	EXPLODINGBARREL = 1238,
	EXPLODINGBARREL2 = 1239,
	FIREBARREL = 1240,
	SEENINE = 1247,
	SEENINEDEAD = 1248,
	STEAM = 1250,
	CEILINGSTEAM = 1255,
	PIPE6B = 1260,
	TRANSPORTERBEAM = 1261,
	RAT = 1267,
	TRASH = 1272,
	FEMPIC1 = 1280,
	FEMPIC2 = 1289,
	BLANKSCREEN = 1293,
	PODFEM1 = 1294,
	FEMPIC3 = 1298,
	FEMPIC4 = 1306,
	FEM1 = 1312,
	FEM2 = 1317,
	FEM3 = 1321,
	FEM5 = 1323,
	BLOODYPOLE = 1324,
	FEM4 = 1325,
	FEM6 = 1334,
	FEM6PAD = 1335,
	FEM8 = 1336,
	HELECOPT = 1346,
	FETUSJIB = 1347,
	HOLODUKE = 1348,
	SPACEMARINE = 1353,
	INDY = 1355,
	FETUS = 1358,
	FETUSBROKE = 1359,
	MONK = 1352,
	LUKE = 1354,
	COOLEXPLOSION1 = 1360,
	WATERSPLASH2 = 1380,
	FIREVASE = 1390,
	SCRATCH = 1393,
	FEM7 = 1395,
	APLAYERTOP = 1400,
	APLAYER = 1405,
	PLAYERONWATER = 1420,
	DUKELYINGDEAD = 1518,
	DUKETORSO = 1520,
	DUKEGUN = 1528,
	DUKELEG = 1536,
	SHARK = 1550,
	BLOOD = 1620,
	FIRELASER = 1625,
	TRANSPORTERSTAR = 1630,
	SPIT = 1636,
	LOOGIE = 1637,
	FIST = 1640,
	FREEZEBLAST = 1641,
	DEVISTATORBLAST = 1642,
	SHRINKSPARK = 1646,
	TONGUE = 1647,
	MORTER = 1650,
	SHRINKEREXPLOSION = 1656,
	RADIUSEXPLOSION = 1670,
	FORCERIPPLE = 1671,
	LIZTROOP = 1680,
	LIZTROOPRUNNING = 1681,
	LIZTROOPSTAYPUT = 1682,
	LIZTOP = 1705,
	LIZTROOPSHOOT = 1715,
	LIZTROOPJETPACK = 1725,
	LIZTROOPDSPRITE = 1734,
	LIZTROOPONTOILET = 1741,
	LIZTROOPJUSTSIT = 1742,
	LIZTROOPDUCKING = 1744,
	HEADJIB1 = 1768,
	ARMJIB1 = 1772,
	LEGJIB1 = 1776,
	CANNONBALL = 1817,
	OCTABRAIN = 1820,
	OCTABRAINSTAYPUT = 1821,
	OCTATOP = 1845,
	OCTADEADSPRITE = 1855,
	INNERJAW = 1860,
	DRONE = 1880,
	EXPLOSION2 = 1890,
	COMMANDER = 1920,
	COMMANDERSTAYPUT = 1921,
	RECON = 1960,
	TANK = 1975,
	PIGCOP = 2000,
	PIGCOPSTAYPUT = 2001,
	PIGCOPDIVE = 2045,
	PIGCOPDEADSPRITE = 2060,
	PIGTOP = 2061,
	LIZMAN = 2120,
	LIZMANSTAYPUT = 2121,
	LIZMANSPITTING = 2150,
	LIZMANFEEDING = 2160,
	LIZMANJUMP = 2165,
	LIZMANDEADSPRITE = 2185,
	FECES = 2200,
	LIZMANHEAD1 = 2201,
	LIZMANARM1 = 2205,
	LIZMANLEG1 = 2209,
	EXPLOSION2BOT = 2219,
	USERWEAPON = 2235,
	HEADERBAR = 2242,
	JIBS1 = 2245,
	JIBS2 = 2250,
	JIBS3 = 2255,
	JIBS4 = 2260,
	JIBS5 = 2265,
	BURNING = 2270,
	FIRE = 2271,
	JIBS6 = 2286,
	BLOODSPLAT1 = 2296,
	BLOODSPLAT3 = 2297,
	BLOODSPLAT2 = 2298,
	BLOODSPLAT4 = 2299,
	OOZ = 2300,
	OOZ2 = 2309,
	WALLBLOOD1 = 2301,
	WALLBLOOD2 = 2302,
	WALLBLOOD3 = 2303,
	WALLBLOOD4 = 2304,
	WALLBLOOD5 = 2305,
	WALLBLOOD6 = 2306,
	WALLBLOOD7 = 2307,
	WALLBLOOD8 = 2308,
	BURNING2 = 2310,
	FIRE2 = 2311,
	CRACKKNUCKLES = 2324,
	SMALLSMOKE = 2329,
	SMALLSMOKEMAKER = 2330,
	FLOORFLAME = 2333,
	ROTATEGUN = 2360,
	GREENSLIME = 2370,
	WATERDRIPSPLASH = 2380,
	SCRAP6 = 2390,
	SCRAP1 = 2400,
	SCRAP2 = 2404,
	SCRAP3 = 2408,
	SCRAP4 = 2412,
	SCRAP5 = 2416,
	ORGANTIC = 2420,
	BETAVERSION = 2440,
	PLAYERISHERE = 2442,
	PLAYERWASHERE = 2443,
	SELECTDIR = 2444,
	F1HELP = 2445,
	NOTCHON = 2446,
	NOTCHOFF = 2447,
	GROWSPARK = 2448,
	DUKEICON = 2452,
	BADGUYICON = 2453,
	FOODICON = 2454,
	GETICON = 2455,
	MENUSCREEN = 2456,
	MENUBAR = 2457,
	KILLSICON = 2458,
	FIRSTAID_ICON = 2460,
	HEAT_ICON = 2461,
	BOTTOMSTATUSBAR = 2462,
	BOOT_ICON = 2463,
	FRAGBAR = 2465,
	JETPACK_ICON = 2467,
	AIRTANK_ICON = 2468,
	STEROIDS_ICON = 2469,
	HOLODUKE_ICON = 2470,
	ACCESS_ICON = 2471,
	DIGITALNUM = 2472,
	DUKECAR = 2491,
	CAMCORNER = 2482,
	CAMLIGHT = 2484,
	LOGO = 2485,
	TITLE = 2486,
	NUKEWARNINGICON = 2487,
	MOUSECURSOR = 2488,
	SLIDEBAR = 2489,
	DREALMS = 2492,
	BETASCREEN = 2493,
	WINDOWBORDER1 = 2494,
	TEXTBOX = 2495,
	WINDOWBORDER2 = 2496,
	DUKENUKEM = 2497,
	THREEDEE = 2498,
	INGAMEDUKETHREEDEE = 2499,
	TENSCREEN = 2500,
	PLUTOPAKSPRITE = 2501,
	DEVISTATOR = 2510,
	KNEE = 2521,
	CROSSHAIR = 2523,
	FIRSTGUN = 2524,
	FIRSTGUNRELOAD = 2528,
	FALLINGCLIP = 2530,
	CLIPINHAND = 2531,
	HAND = 2532,
	SHELL = 2533,
	SHOTGUNSHELL = 2535,
	CHAINGUN = 2536,
	RPGGUN = 2544,
	RPGMUZZLEFLASH = 2545,
	FREEZE = 2548,
	CATLITE = 2552,
	SHRINKER = 2556,
	HANDHOLDINGLASER = 2563,
	TRIPBOMB = 2566,
	LASERLINE = 2567,
	HANDHOLDINGACCESS = 2568,
	HANDREMOTE = 2570,
	HANDTHROW = 2573,
	TIP = 2576,
	GLAIR = 2578,
	SCUBAMASK = 2581,
	SPACEMASK = 2584,
	FORCESPHERE = 2590,
	SHOTSPARK1 = 2595,
	RPG = 2605,
	LASERSITE = 2612,
	SHOTGUN = 2613,
	BOSS1 = 2630,
	BOSS1STAYPUT = 2631,
	BOSS1SHOOT = 2660,
	BOSS1LOB = 2670,
	BOSSTOP = 2696,
	BOSS2 = 2710,
	BOSS3 = 2760,
	SPINNINGNUKEICON = 2813,
	BIGFNTCURSOR = 2820,
	SMALLFNTCURSOR = 2821,
	STARTALPHANUM = 2822,
	ENDALPHANUM = 2915,
	BIGALPHANUM = 2940,
	BIGPERIOD = 3002,
	BIGCOMMA = 3003,
	BIGX = 3004,
	BIGQ = 3005,
	BIGSEMI = 3006,
	BIGCOLIN = 3007,
	THREEBYFIVE = 3010,
	BIGAPPOS = 3022,
	BLANK = 3026,
	MINIFONT = 3072,
	BUTTON1 = 3164,
	GLASS3 = 3187,
	RESPAWNMARKERRED = 3190,
	RESPAWNMARKERYELLOW = 3200,
	RESPAWNMARKERGREEN = 3210,
	BONUSSCREEN = 3240,
	VIEWBORDER = 3250,
	VICTORY1 = 3260,
	ORDERING = 3270,
	TEXTSTORY = 3280,
	LOADSCREEN = 3281,
	E1ENDSCREEN = 3292,
	E2ENDSCREEN = 3293,
	BORNTOBEWILDSCREEN = 3370,
	BLIMP = 3400,
	FEM9 = 3450,
	FOOTPRINT = 3701,
	FRAMEEFFECT1_13= 3999,
	POOP = 4094,
	FRAMEEFFECT1 = 4095,
	PANNEL3 = 4099,
	SCREENBREAK14 = 4120,
	SCREENBREAK15 = 4123,
	SCREENBREAK19 = 4125,
	SCREENBREAK16 = 4127,
	SCREENBREAK17 = 4128,
	SCREENBREAK18 = 4129,
	W_TECHWALL11 = 4130,
	W_TECHWALL12 = 4131,
	W_TECHWALL13 = 4132,
	W_TECHWALL14 = 4133,
	W_TECHWALL5 = 4134,
	W_TECHWALL6 = 4136,
	W_TECHWALL7 = 4138,
	W_TECHWALL8 = 4140,
	W_TECHWALL9 = 4142,
	BPANNEL3 = 4100,
	W_HITTECHWALL16 = 4144,
	W_HITTECHWALL10 = 4145,
	W_HITTECHWALL15 = 4147,
	W_MILKSHELF = 4181,
	W_MILKSHELFBROKE = 4203,
	PURPLELAVA = 4240,
	LAVABUBBLE = 4340,
	DUKECUTOUT = 4352,
	TARGET = 4359,
	GUNPOWDERBARREL = 4360,
	DUCK = 4361,
	HATRACK = 4367,
	DESKLAMP = 4370,
	COFFEEMACHINE = 4372,
	CUPS = 4373,
	GAVALS = 4374,
	GAVALS2 = 4375,
	POLICELIGHTPOLE = 4377,
	FLOORBASKET = 4388,
	PUKE = 4389,
	DOORTILE23 = 4391,
	TOPSECRET = 4396,
	SPEAKER = 4397,
	TEDDYBEAR = 4400,
	ROBOTDOG = 4402,
	ROBOTPIRATE = 4404,
	ROBOTMOUSE = 4407,
	MAIL = 4410,
	MAILBAG = 4413,
	HOTMEAT = 4427,
	COFFEEMUG = 4438,
	DONUTS2 = 4440,
	TRIPODCAMERA = 4444,
	METER = 4453,
	DESKPHONE = 4454,
	GUMBALLMACHINE = 4458,
	GUMBALLMACHINEBROKE = 4459,
	PAPER = 4460,
	MACE = 4464,
	GENERICPOLE2 = 4465,
	XXXSTACY = 4470,
	WETFLOOR = 4495,
	BROOM = 4496,
	MOP = 4497,
	LETTER = 4502,
	PIRATE1A = 4510,
	PIRATE4A = 4511,
	PIRATE2A = 4512,
	PIRATE5A = 4513,
	PIRATE3A = 4514,
	PIRATE6A = 4515,
	PIRATEHALF = 4516,
	CHESTOFGOLD = 4520,
	SIDEBOLT1 = 4525,
	FOODOBJECT1 = 4530,
	FOODOBJECT2 = 4531,
	FOODOBJECT3 = 4532,
	FOODOBJECT4 = 4533,
	FOODOBJECT5 = 4534,
	FOODOBJECT6 = 4535,
	FOODOBJECT7 = 4536,
	FOODOBJECT8 = 4537,
	FOODOBJECT9 = 4538,
	FOODOBJECT10 = 4539,
	FOODOBJECT11 = 4540,
	FOODOBJECT12 = 4541,
	FOODOBJECT13 = 4542,
	FOODOBJECT14 = 4543,
	FOODOBJECT15 = 4544,
	FOODOBJECT16 = 4545,
	FOODOBJECT17 = 4546,
	FOODOBJECT18 = 4547,
	FOODOBJECT19 = 4548,
	FOODOBJECT20 = 4549,
	HEADLAMP = 4550,
	TAMPON = 4557,
	SKINNEDCHICKEN = 4554,
	FEATHEREDCHICKEN = 4555,
	ROBOTDOG2 = 4560,
	JOLLYMEAL = 4569,
	DUKEBURGER = 4570,
	SHOPPINGCART = 4576,
	CANWITHSOMETHING2 = 4580,
	CANWITHSOMETHING3 = 4581,
	CANWITHSOMETHING4 = 4582,
	SNAKEP = 4590,
	DOLPHIN1 = 4591,
	DOLPHIN2 = 4592,
	NEWBEAST = 4610,
	NEWBEASTSTAYPUT = 4611,
	NEWBEASTJUMP = 4690,
	NEWBEASTHANG = 4670,
	NEWBEASTHANGDEAD = 4671,
	BOSS4 = 4740,
	BOSS4STAYPUT = 4741,
	FEM10 = 4864,
	TOUGHGAL = 4866,
	MAN = 4871,
	MAN2 = 4872,
	WOMAN = 4874,
	PLEASEWAIT = 4887,
	NATURALLIGHTNING = 4890,
	WEATHERWARN = 4893,
	DUKETAG = 4900,
	SIGN1 = 4909,
	SIGN2 = 4912,
	JURYGUY = 4943,


	// New names from World Tour
	WIDESCREENSTATUSBAR = 5120,
	RPGGUNWIDE = 5121,
	FIRSTGUNRELOADWIDE = 5122,
	FREEZEWIDE = 5123,
	FREEZEFIREWIDE = 5124,
	SHRINKERWIDE = 5127,
	CRACKKNUCKLESWIDE = 5129,
	ONFIRESMOKE = 5143,
	LAVASPLASH = 5371,
	BOSS2STAYPUT = 2711,
	BOSS3STAYPUT = 2761,
	WTGLASS1 = 5736,
	WTGLASS2 = 5737,
	FLAMETHROWERSPRITE = 5134,
	FLAMETHROWERAMMO = 5135,
	FLAMETHROWER = 5138,
	ONFIRE = 5152,
	LAVAPOOL = 5304,
	LAVAPOOLBUBBLE = 5207,
	WHISPYSMOKE = 5268,
	FLAMETHROWERFIRE = 5139,
	FLAMETHROWERFLAME = 1891,
	FLAMETHROWERPILOT = 5174,
	FIREBALL = 5163,
	BURNEDCORPSE = 5173,
	FIREFLY = 5180,
	FIREFLYSHRINKEFFECT = 5360,
	FIREFLYGROWEFFECT = 5367,
	FIREFLYFLYINGEFFECT = 5296,
	DEVELOPERCOMMENTARY = 5294,
	BOSS5 = 5310,
	BOSS5STAYPUT = 5311,
	SERIOUSSAM = 5846
};

END_DUKE_NS