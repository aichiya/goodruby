#include "global.h"
#include "battle_setup.h"
#include "battle.h"
#include "battle_transition.h"
#include "data2.h"
#include "event_data.h"
#include "field_control_avatar.h"
#include "field_fadetransition.h"
#include "field_message_box.h"
#include "field_player_avatar.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "fldeff_poison.h"
#include "main.h"
#include "metatile_behavior.h"
#include "palette.h"
#include "random.h"
#include "overworld.h"
#include "safari_zone.h"
#include "script.h"
#include "script_pokemon_80C4.h"
#include "secret_base.h"
#include "sound.h"
#include "starter_choose.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "trainer.h"
#include "constants/map_types.h"
#include "constants/maps.h"
#include "constants/opponents.h"
#include "constants/songs.h"
#include "constants/species.h"

extern u16 gSpecialVar_Result;

extern void (*gFieldCallback)(void);

EWRAM_DATA static u16 sTrainerBattleMode = 0;
EWRAM_DATA u16 gTrainerBattleOpponent = 0;
EWRAM_DATA static u16 sTrainerEventObjectLocalId = 0;
EWRAM_DATA static u8 *sTrainerIntroSpeech = NULL;
EWRAM_DATA static u8 *sTrainerDefeatSpeech = NULL;
EWRAM_DATA static u8 *sTrainerVictorySpeech = NULL;
EWRAM_DATA static u8 *sTrainerCannotBattleSpeech = NULL;
EWRAM_DATA static u8 *sTrainerBattleScriptRetAddr = NULL;
EWRAM_DATA static u8 *sTrainerBattleEndScript = NULL;

extern u16 gBattleTypeFlags;
extern u16 gSpecialVar_LastTalked;
extern u8 gBattleOutcome;

extern struct EventObject gEventObjects[];

extern u8 gUnknown_0819F818[];
extern u8 gUnknown_0819F840[];
extern u8 gUnknown_0819F878[];
extern u8 gUnknown_0819F887[];
extern u8 gUnknown_0819F8AE[];

extern u8 gUnknown_0819F80B[];
extern u8 gUnknown_081C6C02[];

// The first transition is used if the enemy pokemon are lower level than our pokemon.
// Otherwise, the second transition is used.
static const u8 gBattleTransitionTable_Wild[][2] =
{
    {B_TRANSITION_SLICE,               B_TRANSITION_WHITEFADE},     // Normal
    {B_TRANSITION_CLOCKWISE_BLACKFADE, B_TRANSITION_GRID_SQUARES},  // Cave
    {B_TRANSITION_BLUR,                B_TRANSITION_GRID_SQUARES},  // Cave with flash used
    {B_TRANSITION_WAVE,                B_TRANSITION_RIPPLE},        // Water
};
static const u8 gBattleTransitionTable_Trainer[][2] =
{
    {B_TRANSITION_POKEBALLS_TRAIL, B_TRANSITION_SHARDS},        // Normal
    {B_TRANSITION_SHUFFLE,         B_TRANSITION_BIG_POKEBALL},  // Cave
    {B_TRANSITION_BLUR,            B_TRANSITION_GRID_SQUARES},  // Cave with flash used
    {B_TRANSITION_SWIRL,           B_TRANSITION_RIPPLE},        // Water
};

enum
{
    TRAINER_PARAM_LOAD_VAL_8BIT,
    TRAINER_PARAM_LOAD_VAL_16BIT,
    TRAINER_PARAM_LOAD_VAL_32BIT,
    TRAINER_PARAM_CLEAR_VAL_8BIT,
    TRAINER_PARAM_CLEAR_VAL_16BIT,
    TRAINER_PARAM_CLEAR_VAL_32BIT,
    TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR,
};

struct TrainerBattleParameter
{
    void *varPtr;
    u8 ptrType;
};

static const struct TrainerBattleParameter gTrainerBattleSpecs_0[] =
{
    {&sTrainerBattleMode,          TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent,      TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerEventObjectLocalId,    TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerIntroSpeech,         TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerDefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,       TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,  TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBattleEndScript,     TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBattleScriptRetAddr, TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};
static const struct TrainerBattleParameter gTrainerBattleSpecs_1[] =
{
    {&sTrainerBattleMode,          TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent,      TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerEventObjectLocalId,    TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerIntroSpeech,         TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerDefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,       TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,  TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBattleEndScript,     TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerBattleScriptRetAddr, TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};
static const struct TrainerBattleParameter gTrainerBattleSpecs_2[] =
{
    {&sTrainerBattleMode,          TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent,      TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerEventObjectLocalId,    TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerIntroSpeech,         TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerDefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,       TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,  TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerBattleEndScript,     TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBattleScriptRetAddr, TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};
static const struct TrainerBattleParameter gTrainerBattleSpecs_3[] =
{
    {&sTrainerBattleMode,          TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent,      TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerEventObjectLocalId,    TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerIntroSpeech,         TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerDefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,       TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,  TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBattleEndScript,     TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBattleScriptRetAddr, TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};
static const struct TrainerBattleParameter gTrainerBattleSpecs_4[] =
{
    {&sTrainerBattleMode,          TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent,      TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerEventObjectLocalId,    TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerIntroSpeech,         TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerDefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,       TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,  TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerBattleEndScript,     TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerBattleScriptRetAddr, TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};

const struct TrainerEyeTrainer gTrainerEyeTrainers[] =
{
    {
        {TRAINER_ROSE_1, TRAINER_ROSE_2, TRAINER_ROSE_2, TRAINER_ROSE_2, TRAINER_ROSE_2},
        MAP_GROUP(ROUTE118),
        MAP_NUM(ROUTE118),
    },
    {
        {TRAINER_DUSTY_1, TRAINER_DUSTY_2, TRAINER_DUSTY_2, TRAINER_DUSTY_2, TRAINER_DUSTY_2},
        MAP_GROUP(ROUTE111),
        MAP_NUM(ROUTE111),
    },
    {
        {TRAINER_LOLA_1, TRAINER_LOLA_2, TRAINER_LOLA_2, TRAINER_LOLA_2, TRAINER_LOLA_2},
        MAP_GROUP(ROUTE109),
        MAP_NUM(ROUTE109),
    },
    {
        {TRAINER_RICKY_1, TRAINER_RICKY_2, TRAINER_RICKY_2, TRAINER_RICKY_2, TRAINER_RICKY_2},
        MAP_GROUP(ROUTE109),
        MAP_NUM(ROUTE109),
    },
    {
        {TRAINER_RITA_AND_SAM_1, TRAINER_RITA_AND_SAM_2, TRAINER_RITA_AND_SAM_2, TRAINER_RITA_AND_SAM_2, TRAINER_RITA_AND_SAM_2},
        MAP_GROUP(ROUTE124),
        MAP_NUM(ROUTE124),
    },
    {
        {TRAINER_BROOKE_1, TRAINER_BROOKE_2, TRAINER_BROOKE_2, TRAINER_BROOKE_2, TRAINER_BROOKE_2},
        MAP_GROUP(ROUTE111),
        MAP_NUM(ROUTE111),
    },
    {
        {TRAINER_WILTON_1, TRAINER_WILTON_2, TRAINER_WILTON_2, TRAINER_WILTON_2, TRAINER_WILTON_2},
        MAP_GROUP(ROUTE111),
        MAP_NUM(ROUTE111),
    },
    {
        {TRAINER_VALERIE_1, TRAINER_VALERIE_2, TRAINER_VALERIE_2, TRAINER_VALERIE_2, TRAINER_VALERIE_2},
        MAP_GROUP(MT_PYRE_6F),
        MAP_NUM(MT_PYRE_6F),
    },
    {
        {TRAINER_CINDY_1, TRAINER_CINDY_3, TRAINER_CINDY_3, TRAINER_CINDY_3, TRAINER_CINDY_3},
        MAP_GROUP(ROUTE104),
        MAP_NUM(ROUTE104),
    },
    {
        {TRAINER_JESSICA_1, TRAINER_JESSICA_2, TRAINER_JESSICA_2, TRAINER_JESSICA_2, TRAINER_JESSICA_2},
        MAP_GROUP(ROUTE121),
        MAP_NUM(ROUTE121),
    },
    {
        {TRAINER_WINSTON_1, TRAINER_WINSTON_2, TRAINER_WINSTON_2, TRAINER_WINSTON_2, TRAINER_WINSTON_2},
        MAP_GROUP(ROUTE104),
        MAP_NUM(ROUTE104),
    },
    {
        {TRAINER_STEVE_1, TRAINER_STEVE_2, TRAINER_STEVE_2, TRAINER_STEVE_2, TRAINER_STEVE_2},
        MAP_GROUP(ROUTE114),
        MAP_NUM(ROUTE114),
    },
    {
        {TRAINER_TONY_1, TRAINER_TONY_2, TRAINER_TONY_2, TRAINER_TONY_2, TRAINER_TONY_2},
        MAP_GROUP(ROUTE107),
        MAP_NUM(ROUTE107),
    },
    {
        {TRAINER_NOB_1, TRAINER_NOB_2, TRAINER_NOB_2, TRAINER_NOB_2, TRAINER_NOB_2},
        MAP_GROUP(ROUTE115),
        MAP_NUM(ROUTE115),
    },
    {
        {TRAINER_DALTON_1, TRAINER_DALTON_2, TRAINER_DALTON_2, TRAINER_DALTON_2, TRAINER_DALTON_2},
        MAP_GROUP(ROUTE118),
        MAP_NUM(ROUTE118),
    },
    {
        {TRAINER_BERNIE_1, TRAINER_BERNIE_2, TRAINER_BERNIE_2, TRAINER_BERNIE_2, TRAINER_BERNIE_2},
        MAP_GROUP(ROUTE114),
        MAP_NUM(ROUTE114),
    },
    {
        {TRAINER_ETHAN_1, TRAINER_ETHAN_2, TRAINER_ETHAN_2, TRAINER_ETHAN_2, TRAINER_ETHAN_2},
        MAP_GROUP(JAGGED_PASS),
        MAP_NUM(JAGGED_PASS),
    },
    {
        {TRAINER_JOHN_AND_JAY_1, TRAINER_JOHN_AND_JAY_2, TRAINER_JOHN_AND_JAY_2, TRAINER_JOHN_AND_JAY_2, TRAINER_JOHN_AND_JAY_2},
        MAP_GROUP(METEOR_FALLS_1F_2R),
        MAP_NUM(METEOR_FALLS_1F_2R),
    },
    {
        {TRAINER_BRANDON_1, TRAINER_BRANDON_2, TRAINER_BRANDON_2, TRAINER_BRANDON_2, TRAINER_BRANDON_2},
        MAP_GROUP(ROUTE120),
        MAP_NUM(ROUTE120),
    },
    {
        {TRAINER_CAMERON_1, TRAINER_CAMERON_2, TRAINER_CAMERON_2, TRAINER_CAMERON_2, TRAINER_CAMERON_2},
        MAP_GROUP(ROUTE123),
        MAP_NUM(ROUTE123),
    },
    {
        {TRAINER_JACKI_1, TRAINER_JACKI_2, TRAINER_JACKI_2, TRAINER_JACKI_2, TRAINER_JACKI_2},
        MAP_GROUP(ROUTE123),
        MAP_NUM(ROUTE123),
    },
    {
        {TRAINER_WALTER_1, TRAINER_WALTER_2, TRAINER_WALTER_2, TRAINER_WALTER_2, TRAINER_WALTER_2},
        MAP_GROUP(ROUTE121),
        MAP_NUM(ROUTE121),
    },
    {
        {TRAINER_KAREN_1, TRAINER_KAREN_2, TRAINER_KAREN_2, TRAINER_KAREN_2, TRAINER_KAREN_2},
        MAP_GROUP(ROUTE116),
        MAP_NUM(ROUTE116),
    },
    {
        {TRAINER_JERRY_1, TRAINER_JERRY_2, TRAINER_JERRY_2, TRAINER_JERRY_2, TRAINER_JERRY_2},
        MAP_GROUP(ROUTE116),
        MAP_NUM(ROUTE116),
    },
    {
        {TRAINER_ANNA_AND_MEG_1, TRAINER_ANNA_AND_MEG_2, TRAINER_ANNA_AND_MEG_2, TRAINER_ANNA_AND_MEG_2, TRAINER_ANNA_AND_MEG_2},
        MAP_GROUP(ROUTE117),
        MAP_NUM(ROUTE117),
    },
    {
        {TRAINER_ISABEL_1, TRAINER_ISABEL_2, TRAINER_ISABEL_2, TRAINER_ISABEL_2, TRAINER_ISABEL_2},
        MAP_GROUP(ROUTE110),
        MAP_NUM(ROUTE110),
    },
    {
        {TRAINER_MIGUEL_1, TRAINER_MIGUEL_2, TRAINER_MIGUEL_2, TRAINER_MIGUEL_2, TRAINER_MIGUEL_2},
        MAP_GROUP(ROUTE103),
        MAP_NUM(ROUTE103),
    },
    {
        {TRAINER_TIMOTHY_1, TRAINER_TIMOTHY_2, TRAINER_TIMOTHY_2, TRAINER_TIMOTHY_2, TRAINER_TIMOTHY_2},
        MAP_GROUP(ROUTE115),
        MAP_NUM(ROUTE115),
    },
    {
        {TRAINER_SHELBY_1, TRAINER_SHELBY_2, TRAINER_SHELBY_2, TRAINER_SHELBY_2, TRAINER_SHELBY_2},
        MAP_GROUP(MT_CHIMNEY),
        MAP_NUM(MT_CHIMNEY),
    },
    {
        {TRAINER_CALVIN_1, TRAINER_CALVIN_2, TRAINER_CALVIN_2, TRAINER_CALVIN_2, TRAINER_CALVIN_2},
        MAP_GROUP(ROUTE102),
        MAP_NUM(ROUTE102),
    },
    {
        {TRAINER_ELLIOT_1, TRAINER_ELLIOT_2, TRAINER_ELLIOT_2, TRAINER_ELLIOT_2, TRAINER_ELLIOT_2},
        MAP_GROUP(ROUTE106),
        MAP_NUM(ROUTE106),
    },
    {
        {TRAINER_ABIGAIL_1, TRAINER_ABIGAIL_2, TRAINER_ABIGAIL_2, TRAINER_ABIGAIL_2, TRAINER_ABIGAIL_2},
        MAP_GROUP(ROUTE110),
        MAP_NUM(ROUTE110),
    },
    {
        {TRAINER_BENJAMIN_1, TRAINER_BENJAMIN_2, TRAINER_BENJAMIN_2, TRAINER_BENJAMIN_2, TRAINER_BENJAMIN_2},
        MAP_GROUP(ROUTE110),
        MAP_NUM(ROUTE110),
    },
    {
        {TRAINER_ISAIAH_1, TRAINER_ISAIAH_2, TRAINER_ISAIAH_2, TRAINER_ISAIAH_2, TRAINER_ISAIAH_2},
        MAP_GROUP(ROUTE128),
        MAP_NUM(ROUTE128),
    },
    {
        {TRAINER_KATELYN_1, TRAINER_KATELYN_2, TRAINER_KATELYN_2, TRAINER_KATELYN_2, TRAINER_KATELYN_2},
        MAP_GROUP(ROUTE128),
        MAP_NUM(ROUTE128),
    },
    {
        {TRAINER_MARIA_1, TRAINER_MARIA_2, TRAINER_MARIA_2, TRAINER_MARIA_2, TRAINER_MARIA_2},
        MAP_GROUP(ROUTE117),
        MAP_NUM(ROUTE117),
    },
    {
        {TRAINER_DYLAN_1, TRAINER_DYLAN_2, TRAINER_DYLAN_2, TRAINER_DYLAN_2, TRAINER_DYLAN_2},
        MAP_GROUP(ROUTE117),
        MAP_NUM(ROUTE117),
    },
    {
        {TRAINER_NICOLAS_1, TRAINER_NICOLAS_2, TRAINER_NICOLAS_2, TRAINER_NICOLAS_2, TRAINER_NICOLAS_2},
        MAP_GROUP(METEOR_FALLS_1F_2R),
        MAP_NUM(METEOR_FALLS_1F_2R),
    },
    {
        {TRAINER_ROBERT_1, TRAINER_ROBERT_2, TRAINER_ROBERT_2, TRAINER_ROBERT_2, TRAINER_ROBERT_2},
        MAP_GROUP(ROUTE120),
        MAP_NUM(ROUTE120),
    },
    {
        {TRAINER_LAO_1, TRAINER_LAO_2, TRAINER_LAO_2, TRAINER_LAO_2, TRAINER_LAO_2},
        MAP_GROUP(ROUTE113),
        MAP_NUM(ROUTE113),
    },
    {
        {TRAINER_CYNDY_1, TRAINER_CYNDY_2, TRAINER_CYNDY_2, TRAINER_CYNDY_2, TRAINER_CYNDY_2},
        MAP_GROUP(ROUTE115),
        MAP_NUM(ROUTE115),
    },
    {
        {TRAINER_MADELINE_1, TRAINER_MADELINE_2, TRAINER_MADELINE_2, TRAINER_MADELINE_2, TRAINER_MADELINE_2},
        MAP_GROUP(ROUTE113),
        MAP_NUM(ROUTE113),
    },
    {
        {TRAINER_JENNY_1, TRAINER_JENNY_2, TRAINER_JENNY_2, TRAINER_JENNY_2, TRAINER_JENNY_2},
        MAP_GROUP(ROUTE124),
        MAP_NUM(ROUTE124),
    },
    {
        {TRAINER_DIANA_1, TRAINER_DIANA_2, TRAINER_DIANA_2, TRAINER_DIANA_2, TRAINER_DIANA_2},
        MAP_GROUP(JAGGED_PASS),
        MAP_NUM(JAGGED_PASS),
    },
    {
        {TRAINER_AMY_AND_LIV_1, TRAINER_AMY_AND_LIV_2, TRAINER_AMY_AND_LIV_2, TRAINER_AMY_AND_LIV_2, TRAINER_AMY_AND_LIV_2},
        MAP_GROUP(ROUTE103),
        MAP_NUM(ROUTE103),
    },
    {
        {TRAINER_ERNEST_1, TRAINER_ERNEST_2, TRAINER_ERNEST_2, TRAINER_ERNEST_2, TRAINER_ERNEST_2},
        MAP_GROUP(ROUTE125),
        MAP_NUM(ROUTE125),
    },
    {
        {TRAINER_EDWIN_1, TRAINER_EDWIN_2, TRAINER_EDWIN_2, TRAINER_EDWIN_2, TRAINER_EDWIN_2},
        MAP_GROUP(ROUTE110),
        MAP_NUM(ROUTE110),
    },
    {
        {TRAINER_LYDIA_1, TRAINER_LYDIA_2, TRAINER_LYDIA_2, TRAINER_LYDIA_2, TRAINER_LYDIA_2},
        MAP_GROUP(ROUTE117),
        MAP_NUM(ROUTE117),
    },
    {
        {TRAINER_ISAAC_1, TRAINER_ISAAC_2, TRAINER_ISAAC_2, TRAINER_ISAAC_2, TRAINER_ISAAC_2},
        MAP_GROUP(ROUTE117),
        MAP_NUM(ROUTE117),
    },
    {
        {TRAINER_CATHERINE_1, TRAINER_CATHERINE_2, TRAINER_CATHERINE_2, TRAINER_CATHERINE_2, TRAINER_CATHERINE_2},
        MAP_GROUP(ROUTE119),
        MAP_NUM(ROUTE119),
    },
    {
        {TRAINER_JACKSON_1, TRAINER_JACKSON_2, TRAINER_JACKSON_2, TRAINER_JACKSON_2, TRAINER_JACKSON_2},
        MAP_GROUP(ROUTE119),
        MAP_NUM(ROUTE119),
    },
    {
        {TRAINER_HALEY_1, TRAINER_HALEY_2, TRAINER_HALEY_2, TRAINER_HALEY_2, TRAINER_HALEY_2},
        MAP_GROUP(ROUTE104),
        MAP_NUM(ROUTE104),
    },
    {
        {TRAINER_JAMES_1, TRAINER_JAMES_2, TRAINER_JAMES_2, TRAINER_JAMES_2, TRAINER_JAMES_2},
        MAP_GROUP(PETALBURG_WOODS),
        MAP_NUM(PETALBURG_WOODS),
    },
    {
        {TRAINER_TRENT_1, TRAINER_TRENT_2, TRAINER_TRENT_2, TRAINER_TRENT_2, TRAINER_TRENT_2},
        MAP_GROUP(ROUTE112),
        MAP_NUM(ROUTE112),
    },
    {
        {TRAINER_LOIS_AND_HAL_1, TRAINER_LOIS_AND_HAL_2, TRAINER_LOIS_AND_HAL_2, TRAINER_LOIS_AND_HAL_2, TRAINER_LOIS_AND_HAL_2},
        MAP_GROUP(ABANDONED_SHIP_ROOMS2_1F),
        MAP_NUM(ABANDONED_SHIP_ROOMS2_1F),
    },
    {
        {TRAINER_WALLY_3, TRAINER_NONE, TRAINER_NONE, TRAINER_NONE, TRAINER_NONE},
        MAP_GROUP(VICTORY_ROAD_1F),
        MAP_NUM(VICTORY_ROAD_1F),
    },
};

static const u16 sBadgeFlags[] =
{
    FLAG_BADGE01_GET,
    FLAG_BADGE02_GET,
    FLAG_BADGE03_GET,
    FLAG_BADGE04_GET,
    FLAG_BADGE05_GET,
    FLAG_BADGE06_GET,
    FLAG_BADGE07_GET,
    FLAG_BADGE08_GET,
};

static void DoStandardWildBattle(void);
static void DoSafariBattle(void);
static void SetTrainerFlagsAfterTrainerEyeRematch(void);
static void CB2_EndWildBattle(void);
static void CB2_EndScriptedWildBattle(void);
static u8 GetWildBattleTransition(void);
static u8 GetTrainerBattleTransition(void);
static void CB2_GiveStarter(void);
static void CB2_StartFirstBattle(void);
static void CB2_EndFirstBattle(void);
static bool32 IsPlayerDefeated(u32 a1);

#define tState data[0]
#define tTransition data[1]

static void Task_BattleStart(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        if (!FldeffPoison_IsActive()) // is poison not active?
        {
            BattleTransition_StartOnField(tTransition);
            tState++; // go to case 1.
        }
        break;
    case 1:
        if (IsBattleTransitionDone() == TRUE)
        {
            SetMainCallback2(sub_800E7C4);
            RestartWildEncounterImmunitySteps();
            ClearPoisonStepCounter();
            DestroyTask(taskId);
        }
        break;
    }
}

static void CreateBattleStartTask(u8 transition, u16 song)
{
    u8 taskId = CreateTask(Task_BattleStart, 1);

    gTasks[taskId].tTransition = transition;
    current_map_music_set__default_for_battle(song);
}

#undef tState
#undef tTransition

void BattleSetup_StartWildBattle(void)
{
    if (GetSafariZoneFlag())
        DoSafariBattle();
    else
        DoStandardWildBattle();
}

static void DoStandardWildBattle(void)
{
    ScriptContext2_Enable();
    FreezeEventObjects();
    sub_80597F4();
    gMain.savedCallback = CB2_EndWildBattle;
    gBattleTypeFlags = 0;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
}

void BattleSetup_StartRoamerBattle(void)
{
    ScriptContext2_Enable();
    FreezeEventObjects();
    sub_80597F4();
    gMain.savedCallback = CB2_EndWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_ROAMER;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
}

static void DoSafariBattle(void)
{
    ScriptContext2_Enable();
    FreezeEventObjects();
    sub_80597F4();
    gMain.savedCallback = sub_80C824C;
    gBattleTypeFlags = BATTLE_TYPE_SAFARI;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
}

static void StartTheBattle(void)
{
    CreateBattleStartTask(GetTrainerBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_TRAINER_BATTLES);
}

//Initiates battle where Wally catches Ralts
void ScrSpecial_StartWallyTutorialBattle(void)
{
    CreateMaleMon(&gEnemyParty[0], SPECIES_RALTS, 5);
    ScriptContext2_Enable();
    gMain.savedCallback = c2_exit_to_overworld_1_continue_scripts_restart_music;
    gBattleTypeFlags = BATTLE_TYPE_WALLY_TUTORIAL;
    CreateBattleStartTask(B_TRANSITION_SLICE, 0);
}

void BattleSetup_StartScriptedWildBattle(void)
{
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = 0;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
}

void ScrSpecial_StartSouthernIslandBattle(void)
{
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_LEGENDARY;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
}

void ScrSpecial_StartRayquazaBattle(void)
{
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_LEGENDARY;
    CreateBattleStartTask(B_TRANSITION_BLUR, MUS_BATTLE34);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
}

void ScrSpecial_StartGroudonKyogreBattle(void)
{
    u16 species = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES);
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_LEGENDARY | BATTLE_TYPE_KYOGRE_GROUDON;
    if (species == SPECIES_GROUDON || species == SPECIES_HO_OH)
        CreateBattleStartTask(B_TRANSITION_SHARDS, MUS_BATTLE34); // GROUDON
    else if (species == SPECIES_KYOGRE || species == SPECIES_LUGIA)
        CreateBattleStartTask(B_TRANSITION_RIPPLE, MUS_BATTLE34); // KYOGRE
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
}

void ScrSpecial_StartRegiBattle(void)
{
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_LEGENDARY | BATTLE_TYPE_REGI;
    CreateBattleStartTask(B_TRANSITION_GRID_SQUARES, GetMUS_ForBattle());
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
}

static void CB2_EndWildBattle(void)
{
    CpuFill16(0, (void *)BG_PLTT, BG_PLTT_SIZE);
    ResetOamRange(0, 128);

    if (IsPlayerDefeated(gBattleOutcome) == TRUE)
    {
        SetMainCallback2(CB2_WhiteOut);
    }
    else
    {
        SetMainCallback2(CB2_ReturnToField);
        gFieldCallback = sub_8080E44;
    }
}

void CB2_EndScriptedWildBattle(void)
{
    CpuFill16(0, (void *)BG_PLTT, BG_PLTT_SIZE);
    ResetOamRange(0, 128);

    if (IsPlayerDefeated(gBattleOutcome) == TRUE)
        SetMainCallback2(CB2_WhiteOut);
    else
        SetMainCallback2(c2_exit_to_overworld_1_continue_scripts_restart_music);
}

s8 BattleSetup_GetTerrain(void)
{
    u16 tileBehavior;
    s16 x, y;

    PlayerGetDestCoords(&x, &y);
    tileBehavior = MapGridGetMetatileBehaviorAt(x, y);

    if (MetatileBehavior_IsTallGrass(tileBehavior))
        return BATTLE_TERRAIN_GRASS;
    if (MetatileBehavior_IsLongGrass(tileBehavior))
        return BATTLE_TERRAIN_LONG_GRASS;
    if (MetatileBehavior_IsSandOrDeepSand(tileBehavior))
        return BATTLE_TERRAIN_SAND;
    switch (gMapHeader.mapType)
    {
    case MAP_TYPE_TOWN:
    case MAP_TYPE_CITY:
    case MAP_TYPE_ROUTE:
        break;
    case MAP_TYPE_UNDERGROUND:
        if (MetatileBehavior_IsIndoorEncounter(tileBehavior))
            return BATTLE_TERRAIN_BUILDING;
        if (MetatileBehavior_IsSurfableWaterOrUnderwater(tileBehavior))
            return BATTLE_TERRAIN_POND;
        return BATTLE_TERRAIN_CAVE;
    case MAP_TYPE_INDOOR:
    case MAP_TYPE_SECRET_BASE:
        return BATTLE_TERRAIN_BUILDING;
    case MAP_TYPE_UNDERWATER:
        return BATTLE_TERRAIN_UNDERWATER;
    case MAP_TYPE_6:
        if (MetatileBehavior_IsSurfableWaterOrUnderwater(tileBehavior))
            return BATTLE_TERRAIN_WATER;
        return BATTLE_TERRAIN_PLAIN;
    }
    if (MetatileBehavior_IsOceanWater(tileBehavior))
        return BATTLE_TERRAIN_WATER;
    if (MetatileBehavior_IsSurfableWaterOrUnderwater(tileBehavior))
        return BATTLE_TERRAIN_POND;
    if (MetatileBehavior_IsMountainTop(tileBehavior))
        return BATTLE_TERRAIN_MOUNTAIN;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
    {
        if (MetatileBehavior_GetBridgeType(tileBehavior))
            return BATTLE_TERRAIN_POND;
        if (MetatileBehavior_IsBridge(tileBehavior) == TRUE)
            return BATTLE_TERRAIN_WATER;
    }
    if (gSaveBlock1.location.mapGroup == MAP_GROUP(ROUTE113) && gSaveBlock1.location.mapNum == MAP_NUM(ROUTE113))
        return BATTLE_TERRAIN_SAND;
    if (GetSav1Weather() == 8)
        return BATTLE_TERRAIN_SAND;
    return BATTLE_TERRAIN_PLAIN;
}

static s8 GetBattleTransitionTypeByMap(void)
{
    u16 tileBehavior;
    s16 x, y;

    PlayerGetDestCoords(&x, &y);
    tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
    if (Overworld_GetFlashLevel())
        return 2;
    if (!MetatileBehavior_IsSurfableWaterOrUnderwater(tileBehavior))
    {
        switch (gMapHeader.mapType)
        {
        case MAP_TYPE_UNDERGROUND:
            return 1;
        case MAP_TYPE_UNDERWATER:
            return 3;
        default:
            return 0;
        }
    }
    return 3;
}

static u16 GetSumOfPlayerPartyLevel(u8 numMons)
{
    u8 sum = 0;
    int i;

    for (i = 0; i < 6; i++)
    {
        u32 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);

        if (species != SPECIES_EGG && species != SPECIES_NONE && GetMonData(&gPlayerParty[i], MON_DATA_HP) != 0)
        {
            sum += GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
            numMons--;
            if (numMons == 0)
                break;
        }
    }
    return sum;
}

static u8 GetSumOfEnemyPartyLevel(u16 opponentId, u8 numMons)
{
    u8 i;
    u8 sum;
    u32 count = numMons;

    if (gTrainers[opponentId].partySize < count)
        count = gTrainers[opponentId].partySize;

    sum = 0;

    switch (gTrainers[opponentId].partyFlags)
    {
    case 0:
        {
            const struct TrainerMonNoItemDefaultMoves *party;
            party = gTrainers[opponentId].party.NoItemDefaultMoves;
            for (i = 0; i < count; i++)
                sum += party[i].level;
        }
        break;
    case F_TRAINER_PARTY_CUSTOM_MOVESET:
        {
            const struct TrainerMonNoItemCustomMoves *party;
            party = gTrainers[opponentId].party.NoItemCustomMoves;
            for (i = 0; i < count; i++)
                sum += party[i].level;
        }
        break;
    case F_TRAINER_PARTY_HELD_ITEM:
        {
            const struct TrainerMonItemDefaultMoves *party;
            party = gTrainers[opponentId].party.ItemDefaultMoves;
            for (i = 0; i < count; i++)
                sum += party[i].level;
        }
        break;
    case F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM:
        {
            const struct TrainerMonItemCustomMoves *party;
            party = gTrainers[opponentId].party.ItemCustomMoves;
            for (i = 0; i < count; i++)
                sum += party[i].level;
        }
	case F_TRAINER_PARTY_FULL_CONTROL:
		{
            const struct TrainerMonFullControl *party;
            party = gTrainers[opponentId].party.FullControl;
            for (i = 0; i < count; i++)
                sum += party[i].level;
		}
        break;
    }

    return sum;
}

static u8 GetWildBattleTransition(void)
{
    u8 transitionType = GetBattleTransitionTypeByMap();
    u8 enemyLevel = GetMonData(&gEnemyParty[0], MON_DATA_LEVEL);
    u8 playerLevel = GetSumOfPlayerPartyLevel(1);

    if (enemyLevel < playerLevel)
        return gBattleTransitionTable_Wild[transitionType][0];
    else
        return gBattleTransitionTable_Wild[transitionType][1];
}

static u8 GetTrainerBattleTransition(void)
{
    const struct Trainer *trainer;
    u8 minPartyCount;
    u8 transitionType;
    u8 enemyLevel;
    u8 playerLevel;

    if (gTrainerBattleOpponent == SECRET_BASE_OPPONENT)
        return B_TRANSITION_STEVEN;

    trainer = gTrainers;

    if (trainer[gTrainerBattleOpponent].trainerClass == TRAINER_CLASS_ELITE_FOUR)
    {
        if (gTrainerBattleOpponent == TRAINER_SIDNEY)
            return B_TRANSITION_SYDNEY;
        if (gTrainerBattleOpponent == TRAINER_PHOEBE)
            return B_TRANSITION_PHOEBE;
        if (gTrainerBattleOpponent == TRAINER_GLACIA)
            return B_TRANSITION_GLACIA;
        if (gTrainerBattleOpponent == TRAINER_DRAKE)
            return B_TRANSITION_DRAKE;
        return B_TRANSITION_STEVEN;
    }

    if (trainer[gTrainerBattleOpponent].trainerClass == TRAINER_CLASS_CHAMPION)
        return B_TRANSITION_STEVEN;

    if (trainer[gTrainerBattleOpponent].doubleBattle == TRUE)
        minPartyCount = 2; // double battles always at least have 2 pokemon.
    else
        minPartyCount = 1;

    transitionType = GetBattleTransitionTypeByMap();
    enemyLevel = GetSumOfEnemyPartyLevel(gTrainerBattleOpponent, minPartyCount);
    playerLevel = GetSumOfPlayerPartyLevel(minPartyCount);
    if (enemyLevel < playerLevel) // is wild mon level than the player's mon level?
        return gBattleTransitionTable_Trainer[transitionType][0];
    else
        return gBattleTransitionTable_Trainer[transitionType][1];
}

u8 BattleSetup_GetBattleTowerBattleTransition(void)
{
    u8 enemyLevel = GetMonData(&gEnemyParty[0], MON_DATA_LEVEL);
    u8 playerLevel = GetSumOfPlayerPartyLevel(1);

    if (enemyLevel < playerLevel)
        return B_TRANSITION_POKEBALLS_TRAIL;
    else
        return B_TRANSITION_BIG_POKEBALL;
}

void ScrSpecial_ChooseStarter(void)
{
    SetMainCallback2(CB2_ChooseStarter);
    gMain.savedCallback = CB2_GiveStarter;
}

static const u16 foreignStarters[][4] =
{
    { SPECIES_CHARMANDER, SPECIES_CYNDAQUIL, SPECIES_SQUIRTLE, SPECIES_TOTODILE },
    { SPECIES_BULBASAUR, SPECIES_CHIKORITA, SPECIES_SQUIRTLE, SPECIES_TOTODILE },
    { SPECIES_BULBASAUR, SPECIES_CHIKORITA, SPECIES_CHARMANDER, SPECIES_CYNDAQUIL },
};

static void CB2_GiveStarter(void)
{
    u16 starterPoke;
	u8 zero = 0;

    *GetVarPointer(VAR_STARTER_MON) = gSpecialVar_Result;
    starterPoke = GetStarterPokemon(gSpecialVar_Result);
    ScriptGiveMon(starterPoke, 5, 0, 0, 0, 0);
	SetMonData(&gPlayerParty[0], MON_DATA_HIDDEN_ABILITY, &zero);
    *GetVarPointer(VAR_SECOND_STARTER) = foreignStarters[gSpecialVar_Result][Random() % 4];
    ResetTasks();
    sub_80408BC();
    SetMainCallback2(CB2_StartFirstBattle);
    BattleTransition_Start(0);
}

static void CB2_StartFirstBattle(void)
{
    UpdatePaletteFade();
    RunTasks();

    if (IsBattleTransitionDone() == TRUE)
    {
        gBattleTypeFlags = BATTLE_TYPE_FIRST_BATTLE;
        gMain.savedCallback = CB2_EndFirstBattle;
        SetMainCallback2(sub_800E7C4);
        RestartWildEncounterImmunitySteps();
        ClearPoisonStepCounter();
        IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
        IncrementGameStat(GAME_STAT_WILD_BATTLES);
    }
}

static void CB2_EndFirstBattle(void)
{
    Overworld_ClearSavedMusic();
    SetMainCallback2(c2_exit_to_overworld_1_continue_scripts_restart_music);
}

// why not just use the macros? maybe its because they didnt want to uncast const every time?
static u32 TrainerBattleLoadArg32(const u8 *ptr)
{
    return T1_READ_32(ptr);
}

static u16 TrainerBattleLoadArg16(const u8 *ptr)
{
    return T1_READ_16(ptr);
}

static u8 TrainerBattleLoadArg8(const u8 *ptr)
{
    return T1_READ_8(ptr);
}

static u16 CurrentOpponentTrainerFlag(void)
{
    return TRAINER_FLAG_START + gTrainerBattleOpponent;
}

static bool32 IsPlayerDefeated(u32 battleOutcome)
{
    switch (battleOutcome)
    {
    case BATTLE_LOST:
    case BATTLE_DREW:
        return TRUE;
    case BATTLE_WON:
    case BATTLE_RAN:
    case BATTLE_PLAYER_TELEPORTED:
    case BATTLE_POKE_FLED:
    case BATTLE_CAUGHT:
        return FALSE;
    default:
        return FALSE;
    }
}

static void ResetTrainerOpponentIds(void)
{
    sTrainerBattleMode = 0;
    gTrainerBattleOpponent = 0;
    sTrainerEventObjectLocalId = 0;
    sTrainerIntroSpeech = 0;
    sTrainerDefeatSpeech = 0;
    sTrainerVictorySpeech = 0;
    sTrainerCannotBattleSpeech = 0;
    sTrainerBattleScriptRetAddr = 0;
    sTrainerBattleEndScript = 0;
}

static void TrainerBattleLoadArgs(const struct TrainerBattleParameter *specs, const u8 *data)
{
    while (1)
    {
        switch (specs->ptrType)
        {
        case TRAINER_PARAM_LOAD_VAL_8BIT:
            *(u8 *)specs->varPtr = TrainerBattleLoadArg8(data);
            data += 1;
            break;
        case TRAINER_PARAM_LOAD_VAL_16BIT:
            *(u16 *)specs->varPtr = TrainerBattleLoadArg16(data);
            data += 2;
            break;
        case TRAINER_PARAM_LOAD_VAL_32BIT:
            *(u32 *)specs->varPtr = TrainerBattleLoadArg32(data);
            data += 4;
            break;
        case TRAINER_PARAM_CLEAR_VAL_8BIT:
            *(u8 *)specs->varPtr = 0;
            break;
        case TRAINER_PARAM_CLEAR_VAL_16BIT:
            *(u16 *)specs->varPtr = 0;
            break;
        case TRAINER_PARAM_CLEAR_VAL_32BIT:
            *(u32 *)specs->varPtr = 0;
            break;
        case TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR:
            *(const u8 **)specs->varPtr = data;
            return;
        }
        specs++;
    }
}

static void SetMapVarsToTrainer(void)
{
    if (sTrainerEventObjectLocalId)
    {
        gSpecialVar_LastTalked = sTrainerEventObjectLocalId;
        gSelectedEventObject = GetEventObjectIdByLocalIdAndMap(sTrainerEventObjectLocalId, gSaveBlock1.location.mapNum, gSaveBlock1.location.mapGroup);
    }
}

u8 *BattleSetup_ConfigureTrainerBattle(const u8 *data)
{
    ResetTrainerOpponentIds();
    sTrainerBattleMode = TrainerBattleLoadArg8(data);

    switch (sTrainerBattleMode)
    {
    case 3:
        TrainerBattleLoadArgs(gTrainerBattleSpecs_3, data);
        return gUnknown_0819F878;
    case 4:
        TrainerBattleLoadArgs(gTrainerBattleSpecs_2, data);
        SetMapVarsToTrainer();
        return gUnknown_0819F840;
    case 1:
    case 2:
        TrainerBattleLoadArgs(gTrainerBattleSpecs_1, data);
        SetMapVarsToTrainer();
        return gUnknown_0819F818;
    case 6:
    case 8:
        TrainerBattleLoadArgs(gTrainerBattleSpecs_4, data);
        SetMapVarsToTrainer();
        return gUnknown_0819F840;
    case 7:
        TrainerBattleLoadArgs(gTrainerBattleSpecs_2, data);
        SetMapVarsToTrainer();
        gTrainerBattleOpponent = GetRematchTrainerId(gTrainerBattleOpponent);
        return gUnknown_0819F8AE;
    case 5:
        TrainerBattleLoadArgs(gTrainerBattleSpecs_0, data);
        SetMapVarsToTrainer();
        gTrainerBattleOpponent = GetRematchTrainerId(gTrainerBattleOpponent);
        return gUnknown_0819F887;
    default:
        TrainerBattleLoadArgs(gTrainerBattleSpecs_0, data);
        SetMapVarsToTrainer();
        return gUnknown_0819F818;
    }
}

void TrainerWantsBattle(u8 trainerEventObjId, const u8 *trainerScript)
{
    gSelectedEventObject = trainerEventObjId;
    gSpecialVar_LastTalked = gEventObjects[trainerEventObjId].localId;
    BattleSetup_ConfigureTrainerBattle(trainerScript + 1);
    ScriptContext1_SetupScript(gUnknown_0819F80B);
    ScriptContext2_Enable();
}

bool32 GetTrainerFlagFromScriptPointer(const u8 *data)
{
    u32 flag = TrainerBattleLoadArg16(data + 2);
    return FlagGet(TRAINER_FLAG_START + flag);
}

void sub_8082524(void)
{
    struct EventObject *eventObject = &gEventObjects[gSelectedEventObject];

    SetTrainerMovementType(eventObject, GetTrainerFacingDirectionMovementType(eventObject->facingDirection));
}

u8 ScrSpecial_GetTrainerBattleMode(void)
{
    return sTrainerBattleMode;
}

u8 ScrSpecial_HasTrainerBeenFought(void)
{
    return FlagGet(CurrentOpponentTrainerFlag());
}

void SetCurrentTrainerBattledFlag(void)
{
    FlagSet(CurrentOpponentTrainerFlag());
}

void unref_sub_8082590(void)
{
    FlagSet(CurrentOpponentTrainerFlag()); // duplicate function
}

u8 HasTrainerAlreadyBeenFought(u16 flag)
{
    return FlagGet(TRAINER_FLAG_START + flag);
}

void SetTrainerFlag(u16 flag)
{
    FlagSet(TRAINER_FLAG_START + flag);
}

void ClearTrainerFlag(u16 flag)
{
    FlagClear(TRAINER_FLAG_START + flag);
}

void BattleSetup_StartTrainerBattle(void)
{
    gBattleTypeFlags = BATTLE_TYPE_TRAINER;
    gMain.savedCallback = CB2_EndTrainerBattle;
    StartTheBattle();
    ScriptContext1_Stop();
}

void CB2_EndTrainerBattle(void)
{
    if (gTrainerBattleOpponent == SECRET_BASE_OPPONENT)
    {
        SetMainCallback2(c2_exit_to_overworld_1_continue_scripts_restart_music);
    }
    else if (IsPlayerDefeated(gBattleOutcome) == TRUE)
    {
        SetMainCallback2(CB2_WhiteOut);
    }
    else
    {
        SetMainCallback2(c2_exit_to_overworld_1_continue_scripts_restart_music);
        SetCurrentTrainerBattledFlag();
    }
}

void CB2_EndTrainerEyeRematchBattle(void)
{
    if (gTrainerBattleOpponent == SECRET_BASE_OPPONENT)
    {
        SetMainCallback2(c2_exit_to_overworld_1_continue_scripts_restart_music);
    }
    else if (IsPlayerDefeated(gBattleOutcome) == TRUE)
    {
        SetMainCallback2(CB2_WhiteOut);
    }
    else
    {
        SetMainCallback2(c2_exit_to_overworld_1_continue_scripts_restart_music);
        SetCurrentTrainerBattledFlag();
        SetTrainerFlagsAfterTrainerEyeRematch();
    }
}

void ScrSpecial_StartTrainerEyeRematch(void)
{
    gBattleTypeFlags = BATTLE_TYPE_TRAINER;
    gMain.savedCallback = CB2_EndTrainerEyeRematchBattle;
    StartTheBattle();
    ScriptContext1_Stop();
}

static const u8 *GetTrainerIntroSpeech(void);
static const u8 *GetTrainerNonBattlingSpeech(void);

void ScrSpecial_ShowTrainerIntroSpeech(void)
{
    ShowFieldMessage(GetTrainerIntroSpeech());
}

u8 *BattleSetup_GetScriptAddrAfterBattle(void)
{
    if (sTrainerBattleScriptRetAddr)
        return sTrainerBattleScriptRetAddr;
    else
        return gUnknown_081C6C02;
}

u8 *BattleSetup_GetTrainerPostBattleScript(void)
{
    if (sTrainerBattleEndScript)
        return sTrainerBattleEndScript;
    else
        return gUnknown_081C6C02;
}

void ScrSpecial_ShowTrainerNonBattlingSpeech(void)
{
    ShowFieldMessage(GetTrainerNonBattlingSpeech());
}

void PlayTrainerEncounterMusic(void)
{
    u16 music;

    if (sTrainerBattleMode != 1 && sTrainerBattleMode != 8)
    {
        switch (sub_803FC58(gTrainerBattleOpponent))
        {
        case TRAINER_ENCOUNTER_MUSIC_MALE:
            music = MUS_BOYEYE;
            break;
        case TRAINER_ENCOUNTER_MUSIC_FEMALE:
            music = MUS_GIRLEYE;
            break;
        case TRAINER_ENCOUNTER_MUSIC_GIRL:
            music = MUS_SYOUJOEYE;
            break;
        case TRAINER_ENCOUNTER_MUSIC_INTENSE:
            music = MUS_HAGESHII;
            break;
        case TRAINER_ENCOUNTER_MUSIC_COOL:
            music = MUS_KAKKOII;
            break;
        case TRAINER_ENCOUNTER_MUSIC_AQUA:
            music = MUS_AQA_0;
            break;
        case TRAINER_ENCOUNTER_MUSIC_MAGMA:
            music = MUS_MGM0;
            break;
        case TRAINER_ENCOUNTER_MUSIC_SWIMMER:
            music = MUS_SWIMEYE;
            break;
        case TRAINER_ENCOUNTER_MUSIC_TWINS:
            music = MUS_HUTAGO;
            break;
        case TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR:
            music = MUS_SITENNOU;
            break;
        case TRAINER_ENCOUNTER_MUSIC_HIKER:
            music = MUS_YAMA_EYE;
            break;
        case TRAINER_ENCOUNTER_MUSIC_INTERVIEWER:
            music = MUS_INTER_V;
            break;
        case TRAINER_ENCOUNTER_MUSIC_RICH:
            music = MUS_TEST;
            break;
        default:
            music = MUS_AYASII;
        }
        PlayNewMapMusic(music);
    }
}

//Returns an empty string if a null pointer was passed, otherwise returns str
static const u8 *SanitizeString(const u8 *str)
{
    if (str)
        return str;
    else
        return gOtherText_CancelWithTerminator;
}

static const u8 *GetTrainerIntroSpeech(void)
{
    return SanitizeString(sTrainerIntroSpeech);
}

u8 *GetTrainerLoseText(void)
{
    const u8 *str;

    if (gTrainerBattleOpponent == SECRET_BASE_OPPONENT)
        str = GetSecretBaseTrainerLoseText();
    else
        str = sTrainerDefeatSpeech;

    StringExpandPlaceholders(gStringVar4, SanitizeString(str));
    return gStringVar4;
}

const u8 *unref_sub_808286C(void)
{
    return SanitizeString(sTrainerVictorySpeech);
}

static const u8 *GetTrainerNonBattlingSpeech(void)
{
    return SanitizeString(sTrainerCannotBattleSpeech);
}

s32 FirstBattleTrainerIdToRematchTableId(const struct TrainerEyeTrainer *trainers, u16 opponentId)
{
    s32 i;

    for (i = 0; i < NUM_TRAINER_EYE_TRAINERS; i++)
    {
        if (trainers[i].opponentIDs[0] == opponentId)
            return i;
    }
    return -1;
}

s32 TrainerIdToRematchTableId(const struct TrainerEyeTrainer *trainers, u16 opponentId)
{
    s32 i;
    s32 j;

    for (i = 0; i < NUM_TRAINER_EYE_TRAINERS; i++)
    {
        for (j = 0; j < 5 && trainers[i].opponentIDs[j] != 0; j++)
        {
            if (trainers[i].opponentIDs[j] == opponentId)
                return i;
        }
    }
    return -1;
}

bool32 UpdateRandomTrainerEyeRematches(const struct TrainerEyeTrainer *trainers, u16 mapGroup, u16 mapNum)
{
    int i;
    bool32 ret = FALSE;

    for (i = 0; i < NUM_TRAINER_EYE_TRAINERS; i++)
    {
        if (trainers[i].mapGroup == mapGroup && trainers[i].mapNum == mapNum)
        {
            if (gSaveBlock1.trainerRematches[i] != 0)
            {
                // Trainer already wants rematch. Don't bother updating it
                ret = TRUE;
            }
            else if (HasTrainerAlreadyBeenFought(trainers[i].opponentIDs[0]) == TRUE
             && (Random() % 100) <= 30)  // 31% chance of getting a rematch
            {
                int rematches = 1;

                while (rematches < 5 && trainers[i].opponentIDs[rematches] != 0
                 && HasTrainerAlreadyBeenFought(trainers[i].opponentIDs[rematches]))
                    rematches++;
                gSaveBlock1.trainerRematches[i] = rematches;
                ret = TRUE;
            }
        }
    }
   return ret;
}

s32 DoesSomeoneWantRematchIn_(const struct TrainerEyeTrainer *trainers, u16 mapGroup, u16 mapNum)
{
    s32 i;

    for (i = 0; i < NUM_TRAINER_EYE_TRAINERS; i++)
    {
        if (trainers[i].mapGroup == mapGroup && trainers[i].mapNum == mapNum && gSaveBlock1.trainerRematches[i])
            return 1;
    }
    return 0;
}

s32 IsRematchTrainerIn_(const struct TrainerEyeTrainer *trainers, u16 mapGroup, u16 mapNum)
{
    s32 i;

    for (i = 0; i < NUM_TRAINER_EYE_TRAINERS; i++)
    {
        if (trainers[i].mapGroup == mapGroup && trainers[i].mapNum == mapNum)
            return 1;
    }
    return 0;
}

bool8 IsFirstTrainerIdReadyForRematch(const struct TrainerEyeTrainer *trainers, u16 opponentId)
{
    s32 trainerEyeIndex = FirstBattleTrainerIdToRematchTableId(trainers, opponentId);

    if (trainerEyeIndex != -1 && trainerEyeIndex < 100 && gSaveBlock1.trainerRematches[trainerEyeIndex])
        return TRUE;
    else
        return FALSE;
}

bool8 GetTrainerEyeRematchFlag(const struct TrainerEyeTrainer *trainers, u16 opponentId)
{
    s32 trainerEyeIndex = TrainerIdToRematchTableId(trainers, opponentId);

    if (trainerEyeIndex != -1 && trainerEyeIndex < 100 && gSaveBlock1.trainerRematches[trainerEyeIndex])
        return TRUE;
    else
        return FALSE;
}

u16 GetRematchTrainerIdFromTable(const struct TrainerEyeTrainer *trainers, u16 opponentId)
{
    int i;
    const struct TrainerEyeTrainer *trainer;
    s32 trainerEyeIndex = FirstBattleTrainerIdToRematchTableId(trainers, opponentId);

    if (trainerEyeIndex == -1)
        return 0;
    trainer = &trainers[trainerEyeIndex];
    for (i = 1; i < 5; i++)
    {
        if (!trainer->opponentIDs[i])
            return trainer->opponentIDs[i - 1];
        if (!HasTrainerAlreadyBeenFought(trainer->opponentIDs[i]))
            return trainer->opponentIDs[i];
    }
    return trainer->opponentIDs[4];
}

void ClearTrainerEyeRematchFlag(const struct TrainerEyeTrainer *trainers, u16 opponentId)
{
    s32 trainerEyeIndex = TrainerIdToRematchTableId(trainers, opponentId);

    if (trainerEyeIndex != -1)
        gSaveBlock1.trainerRematches[trainerEyeIndex] = 0;
}

bool8 WasSecondRematchWon(const struct TrainerEyeTrainer *trainers, u16 opponentId)
{
    s32 trainerEyeIndex = FirstBattleTrainerIdToRematchTableId(trainers, opponentId);

    if (trainerEyeIndex != -1 && HasTrainerAlreadyBeenFought(trainers[trainerEyeIndex].opponentIDs[1]))
        return TRUE;
    else
        return FALSE;
}

bool32 HasAtLeastFiveBadges(void)
{
    int badgeCount = 0;
    u32 i;

    for (i = 0; i < 8; i++)
    {
        if (FlagGet(sBadgeFlags[i]) == TRUE)
        {
            badgeCount++;
            if (badgeCount >= 5)
                return TRUE;
        }
    }
    return FALSE;
}

void IncrementRematchStepCounter(void)
{
    if (HasAtLeastFiveBadges())
    {
        if (gSaveBlock1.trainerRematchStepCounter >= TRAINER_REMATCH_STEPS)
            gSaveBlock1.trainerRematchStepCounter = TRAINER_REMATCH_STEPS;
        else
            gSaveBlock1.trainerRematchStepCounter++;
    }
}

bool32 IsRematchStepCounterMaxed(void)
{
    if (HasAtLeastFiveBadges() && gSaveBlock1.trainerRematchStepCounter >= TRAINER_REMATCH_STEPS)
        return TRUE;
    else
        return FALSE;
}

void TryUpdateRandomTrainerRematches(u16 mapGroup, u16 mapNum)
{
    if (IsRematchStepCounterMaxed() && UpdateRandomTrainerEyeRematches(gTrainerEyeTrainers, mapGroup, mapNum) == TRUE)
        gSaveBlock1.trainerRematchStepCounter = 0;
}

s32 DoesSomeoneWantRematchIn(u16 mapGroup, u16 mapNum)
{
    return DoesSomeoneWantRematchIn_(gTrainerEyeTrainers, mapGroup, mapNum);
}

s32 IsRematchTrainerIn(u16 mapGroup, u16 mapNum)
{
    return IsRematchTrainerIn_(gTrainerEyeTrainers, mapGroup, mapNum);
}

u16 GetRematchTrainerId(u16 opponentId)
{
    return GetRematchTrainerIdFromTable(gTrainerEyeTrainers, opponentId);
}

bool8 ShouldTryRematchBattle(void)
{
    if (IsFirstTrainerIdReadyForRematch(gTrainerEyeTrainers, gTrainerBattleOpponent))
        return 1;
    else
        return WasSecondRematchWon(gTrainerEyeTrainers, gTrainerBattleOpponent);
}

u8 ScrSpecial_GetTrainerEyeRematchFlag(void)
{
    return GetTrainerEyeRematchFlag(gTrainerEyeTrainers, gTrainerBattleOpponent);
}

void SetTrainerFlagsAfterTrainerEyeRematch(void)
{
    ClearTrainerEyeRematchFlag(gTrainerEyeTrainers, gTrainerBattleOpponent);
    SetCurrentTrainerBattledFlag();
}
