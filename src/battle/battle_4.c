#include "global.h"
#include "battle.h"
#include "battle_message.h"
#include "battle_string_ids.h"
#include "battle_script_commands.h"
#include "battle_util.h"
#include "constants/battle_move_effects.h"
#include "constants/moves.h"
#include "constants/abilities.h"
#include "constants/flags.h"
#include "item.h"
#include "constants/items.h"
#include "data2.h"
#include "event_data.h"
#include "constants/hold_effects.h"
#include "random.h"
#include "rom3.h"
#include "constants/species.h"
#include "pokemon.h"
#include "text.h"
#include "palette.h"
#include "main.h"
#include "constants/songs.h"
#include "sound.h"
#include "task.h"
#include "string.h"
#include "string_util.h"
#include "decompress.h"
#include "pokemon_summary_screen.h"
#include "naming_screen.h"
#include "ewram.h"
#include "util.h"

// TODO: put this into battle_controllers.h

#define RET_VALUE_LEVELLED_UP   11

enum
{
    CONTROLLER_GETMONDATA,
    CONTROLLER_GETRAWMONDATA,
    CONTROLLER_SETMONDATA,
    CONTROLLER_SETRAWMONDATA,
    CONTROLLER_LOADMONSPRITE,
    CONTROLLER_SWITCHINANIM,
    CONTROLLER_RETURNMONTOBALL,
    CONTROLLER_DRAWTRAINERPIC,
    CONTROLLER_TRAINERSLIDE,
    CONTROLLER_TRAINERSLIDEBACK,
    CONTROLLER_FAINTANIMATION,
    CONTROLLER_PALETTEFADE,
    CONTROLLER_SUCCESSBALLTHROWANIM,
    CONTROLLER_BALLTHROWANIM,
    CONTROLLER_PAUSE,
    CONTROLLER_MOVEANIMATION,
    CONTROLLER_PRINTSTRING,
    CONTROLLER_PRINTSTRINGPLAYERONLY,
    CONTROLLER_CHOOSEACTION,
    CONTROLLER_UNKNOWNYESNOBOX,
    CONTROLLER_CHOOSEMOVE,
    CONTROLLER_OPENBAG,
    CONTROLLER_CHOOSEPOKEMON,
    CONTROLLER_23,
    CONTROLLER_HEALTHBARUPDATE,
    CONTROLLER_EXPUPDATE,
    CONTROLLER_STATUSICONUPDATE,
    CONTROLLER_STATUSANIMATION,
    CONTROLLER_STATUSXOR,
    CONTROLLER_DATATRANSFER,
    CONTROLLER_DMA3TRANSFER,
    CONTROLLER_31,
    CONTROLLER_32,
    CONTROLLER_TWORETURNVALUES,
    CONTROLLER_CHOSENMONRETURNVALUE,
    CONTROLLER_ONERETURNVALUE,
    CONTROLLER_ONERETURNVALUE_DUPLICATE,
    CONTROLLER_37,
    CONTROLLER_38,
    CONTROLLER_39,
    CONTROLLER_40,
    CONTROLLER_HITANIMATION,
    CONTROLLER_42,
    CONTROLLER_EFFECTIVENESSSOUND,
    CONTROLLER_PLAYFANFAREORBGM,
    CONTROLLER_FAINTINGCRY,
    CONTROLLER_INTROSLIDE,
    CONTROLLER_INTROTRAINERBALLTHROW,
    CONTROLLER_DRAWPARTYSTATUSSUMMARY,
    CONTROLLER_49,
    CONTROLLER_50,
    CONTROLLER_SPRITEINVISIBILITY,
    CONTROLLER_BATTLEANIMATION,
    CONTROLLER_LINKSTANDBYMSG,
    CONTROLLER_RESETACTIONMOVESELECTION,
    CONTROLLER_55,
    /*new controllers should go here*/
    CONTROLLER_TERMINATOR_NOP,
    CONTROLLER_CMDS_COUNT
};


enum
{
    FLAVOR_SPICY, // 0
    FLAVOR_DRY, // 1
    FLAVOR_SWEET, // 2
    FLAVOR_BITTER, // 3
    FLAVOR_SOUR, // 4
};

//extern needed variables
extern u8 gUnknown_02023A14_50;
extern u8 gCritMultiplier;
extern s32 gBattleMoveDamage;
extern u32 gStatuses3[MAX_BATTLERS_COUNT];
extern u16 gBattleTypeFlags;
extern const struct BaseStats gBaseStats[];
extern struct BattleEnigmaBerry gEnigmaBerries[MAX_BATTLERS_COUNT];
extern struct BattlePokemon gBattleMons[MAX_BATTLERS_COUNT];
extern u8 gActiveBattler;
extern u32 gBattleExecBuffer;
extern u8 gBattlersCount;
extern u16 gBattlerPartyIndexes[MAX_BATTLERS_COUNT];
extern u8 gBanksByTurnOrder[MAX_BATTLERS_COUNT];
extern u8 gActionsByTurnOrder[MAX_BATTLERS_COUNT];
extern u16 gCurrentMove;
extern u8 gLastUsedAbility;
extern u16 gBattleWeather;
extern u8 gStringBank;
extern u8 gEffectBank;
extern u8 gAbsentBattlerFlags;
extern u8 gMultiHitCounter;
extern u16 gLastUsedMove[4];
extern u16 gLockedMoves[4];
extern u16 gChosenMovesByBanks[4];
extern u16 gSideAffecting[2];
extern u16 gPauseCounterBattle;
extern u16 gPaydayMoney;
extern u16 gRandomTurnNumber;
extern u8 gBattleOutcome;
extern u8 gBattleTerrain;
extern u16 gTrainerBattleOpponent;
extern u8 gBankAttacker;
extern u8 gBankTarget;
extern const u8* gBattlescriptCurrInstr;
extern u8 gCurrMovePos;
extern u8 gCurrentActionFuncId;
extern u32 gHitMarker;
extern u16 gMoveResultFlags;
extern u8 gBattleCommunication[];
extern u16 gLastLandedMoves[4];
extern u16 gLastHitByType[4];
extern u8 gStringBank;
extern u16 gDynamicBasePower;
extern const u8 gTypeEffectiveness[];
extern u16 gLastUsedItem;
extern u16 gBattleMovePower;
extern s32 gHpDealt;
extern s32 gTakenDmg[MAX_BATTLERS_COUNT];
extern u8 gTakenDmgBanks[MAX_BATTLERS_COUNT];
extern const u16 gMissStringIds[];
extern u8 gSentPokesToOpponent[2];
extern u8 gBank1;
extern u16 gExpShareExp;
extern u8 gBattleTextBuff1[];
extern u8 gBattleTextBuff2[];
extern u8 gBattleTextBuff3[];
extern u8 gLeveledUpInBattle;
extern void (*gBattleMainFunc)(void);
extern struct Window gUnknown_03004210;
extern const u8 BattleText_YesNo[];
extern u8 gPlayerPartyCount;
extern u16 gMoveToLearn; //move to learn
extern const u8 gTrainerMoney[];
extern u16 gRandomMove;
extern u8* gBattleScriptsForMoveEffects[];
extern u16 gChosenMove; //last used move in battle
extern u8 gBankInMenu;
extern u8 gActionForBanks[4];
extern u16 gUnknown_02024C2C[4]; //last used moves 2, used by sketch
extern u16 gUnknown_02024C4C[4]; //last used moves by banks, another one
extern u8 gCurrentTurnActionNumber;
extern u16 gTrappingMoves[];
extern const struct Item gItems[];
extern u16 gUnknown_02024C2C[4];
extern u8 gLastHitBy[4];

extern u8 BattleScript_MoveEffectSleep[];
extern u8 BattleScript_MoveEffectPoison[];
extern u8 BattleScript_MoveEffectBurn[];
extern u8 BattleScript_MoveEffectFreeze[];
extern u8 BattleScript_MoveEffectParalysis[];
extern u8 BattleScript_MoveEffectToxic[];
extern u8 BattleScript_MoveEffectConfusion[];
extern u8 BattleScript_MoveEffectUproar[];
extern u8 BattleScript_MoveEffectWrap[];
extern u8 BattleScript_MoveEffectPayDay[];
extern u8 BattleScript_MoveEffectRecoil33[];

//extern functions
u8 AtkCanceller_UnableToUseMove(void);
void PressurePPLose(u8 bank_atk, u8 bank_def, u16 move);
void CancelMultiTurnMoves(u8 bank);
void BattleScriptPush(const u8* BS_ptr);
void BattleScriptPushCursor(void);
void RecordAbilityBattle(u8 bank, u8 ability);
void RecordItemBattle(u8 bank, u8 holdEffect);
static bool8 IsTwoTurnsMove(u16 move);
static void TrySetDestinyBondToHappen(void);
static void CheckWonderGuardAndLevitate(void);
u8 GetBattlerPosition(u8 bank);
u8 GetBattlerSide(u8 bank);
u8 GetBattleBank(u8 bankValue);
s32 CalculateBaseDamage(struct BattlePokemon *attacker, struct BattlePokemon *defender, u32 move, u16 a4, u16 powerOverride, u8 typeOverride, u8 bank_atk, u8 bank_def);
static u8 AttacksThisTurn(u8 bank, u16 move); //Note: returns 1 if it's a charging turn, otherwise 2
void UndoEffectsAfterFainting(void);
void BattleStopLowHpSound(void);
void PlayBGM(u16 songID);
void MonGainEVs(struct Pokemon*, u16 defeatedSpecies);
extern u8 gBattleBufferB[4][0x200];
void HandleLowHpMusicChange(struct Pokemon*, u8 bank);
bool8 IsTradedMon(struct Pokemon*);
void BattleScriptPop(void);
void SwitchInClearSetData(void);
u8 GetSetPokedexFlag(u16 nationalNum, u8 caseID);
u16 SpeciesToNationalPokedexNum(u16 species);
u8 sub_803FC34(u8 bank);
u16 sub_803FBFC(u8 a);
u8 GetBattlerAtPosition(u8 ID);
void sub_8012258(u8);
//MonTryLearningNewMove teach poke a move
u16 GiveMoveToBattleMon(struct BattlePokemon *mon, u16 move);
void IncrementGameStat(u8 index);
u8 GetScaledHPFraction(s16 hp, s16 maxhp, u8 scale);
u16 GetPokedexHeightWeight(u16 national_num, u8 heightweight);
u8 MenuCursor_Create814A5C0(u8 a1, u16 a2, u8 a3, u16 a4, u8 a5);
void DestroyMenuCursor(void);
void sub_802BC6C(void);
u8 sub_809FA30(void);
bool32 IsHMMove2(u16 move);
void sub_802BBD4(u8 r0, u8 r1, u8 r2, u8 r3, u8 sp0);
void nullsub_6(void);
void ReshowBattleScreenAfterMenu(void);
void BattleMainCB2(void);
void AddMoney(u32* moneySaveblock, u32 to_give);
void RemoveMoney(u32* moneySaveblock, u32 to_take);
u8 CountAliveMons(u8 caseID);
void PokemonUseItemEffects(struct Pokemon*, u16 item, u8 partyID, u8 r3, u8 sp);
u8 CanRunFromBattle(void);
u8 GetMoveTarget(u16 move, u8 targetbyte); //get target of move
u8 CastformDataTypeChange(u8 bank);
u8 Overworld_GetMapTypeOfSaveblockLocation(void);
u8 CalculatePlayerPartyCount(void);
u16 Sqrt(u32 num);
u8 sub_809070C(u16 nationalNum, u32 TiD, u32 PiD); //task prepare poke dex display
void MenuCursor_SetPos814A880(u8 a1, u8 a2);
u8 CheckMoveLimitations(u8 bank, u8 unusable_moves, u8 flags);
bool8 IsLinkDoubleBattle(void);
void sub_8094B6C(u8 bank, u8 partyID, u8 r2);
s8 GetPokeFlavourRelation(u32 pid, u8 flavor);

//extern BattleScripts
extern u8 BattleScript_MoveEnd[];
extern u8 BattleScript_NoPPForMove[];
extern u8 BattleScript_NoTarget[];
extern u8 BattleScript_Protean[];
extern u8 BattleScript_MagicCoatBounce[];
extern u8 BattleScript_MagicBounceBounce[];
extern u8 BattleScript_TookAttack[];
extern u8 BattleScript_SnatchedMove[];
extern u8 BattleScript_Pausex20[];
extern u8 BattleScript_SubstituteFade[];
extern u8 BattleScript_HangedOnMsg[];
extern u8 BattleScript_HangedOnMsgDestroyItem[];
extern u8 BattleScript_OneHitKOMsg[];
extern u8 BattleScript_EnduredMsg[];
extern u8 BattleScript_SturdyMsg[];
extern u8 BattleScript_PSNPrevention[];
extern u8 BattleScript_BRNPrevention[];
extern u8 BattleScript_PRLZPrevention[];
extern u8 BattleScript_FlinchPrevention[];
extern u8 BattleScript_StatUp[];
extern u8 BattleScript_StatDown[];
extern u8 BattleScript_NoItemSteal[];
extern u8 BattleScript_ItemSteal[];
extern u8 BattleScript_RapidSpinAway[];
extern u8 BattleScript_TargetPRLZHeal[];
extern u8 BattleScript_KnockedOff[];
extern u8 BattleScript_LevelUp[];
extern u8 BattleScript_WrapFree[];
extern u8 BattleScript_LeechSeedFree[];
extern u8 BattleScript_SpikesFree[];
extern u8 BattleScript_ButItFailed[];
extern u8 BattleScript_ObliviousPreventsAttraction[];
extern u8 BattleScript_MistProtected[];
extern u8 BattleScript_AbilityNoStatLoss[];
extern u8 BattleScript_AbilityNoSpecificStatLoss[];
extern u8 BattleScript_TrainerBallBlock[];
extern u8 BattleScript_WallyBallThrow[];
extern u8 BattleScript_SuccessBallThrow[];
extern u8 BattleScript_ShakeBallThrow[];
extern u8 BattleScript_AllStatsUp[];
extern u8 BattleScript_AtkDefDown[];
extern u8 BattleScript_SAtkDown2[];
extern u8 BattleScript_RageIsBuilding[];
extern u8 BattleScript_DefrostedViaFireMove[];
extern u8 gUnknown_081D9B2D[];

extern u8 BattleScript_HazardsUser[]; //spikes1
extern u8 BattleScript_HazardsTarget[]; //spikes2
extern u8 BattleScript_HazardsgBank1[]; //spikes3
extern u8 BattleScript_HitFromCritCalc[]; //present dmg
extern u8 BattleScript_AlreadyAtFullHp[]; //present full hp
extern u8 BattleScript_PresentHealTarget[]; //present hp heal
extern u8 BattleScript_MoveMissedPause[];
extern u8 BattleScript_CastformChange[];
extern u8 BattleScript_DampStopsExplosion[];
extern u8 BattleScript_SuccessForceOut[]; //bs random switchout
extern u8 BattleScript_PrintPayDayMoneyString[]; //bs payday money give
extern u8 BattleScript_FaintAttacker[];
extern u8 BattleScript_FaintTarget[];
extern u8 BattleScript_DestinyBondTakesLife[];
extern u8 BattleScript_SelectingImprisionedMoveInPalace[];
extern u8 BattleScript_BugBiteEatBerry[];
extern u8 BattleScript_BugBiteGainHP[];
extern u8 BattleScript_BugBiteHealStatus[];
extern u8 BattleScript_BugBiteGainHPConfuse[];
extern u8 BattleScript_BugBiteRaiseStat[];
extern u8 BattleScript_BugBiteLansat[];
extern u8 BattleScript_BugBiteLeppa[];
extern u8 BattleScript_CaptivateFail[];
extern u8 BattleScript_CaptivateFailOblivious[];
extern u8 BattleScript_TargetSLPHeal[];
extern u8 BattleScript_AbsorbToxicSpikes[];
extern u8 BattleScript_IncinerateDestroyBerry[];
extern u8 BattleScript_LiftedProtect[];
extern u8 BattleScript_SpikyShieldRecoil[];
extern u8 BattleScript_FinishUTurn[];
extern u8 BattleScript_UseResistBerry[];
extern u8 BattleScript_DefiantProc[];
extern u8 BattleScript_CompetitiveProc[];
extern u8 BattleScript_FellStingerKills[];
extern u8 BattleScript_ForecastSun[];
extern u8 BattleScript_ForecastRain[];
extern u8 BattleScript_ForecastHail[];
extern u8 BattleScript_ExplosionLoop[];

extern const u8 gStatusConditionString_PoisonJpn[];
extern const u8 gStatusConditionString_SleepJpn[];
extern const u8 gStatusConditionString_ParalysisJpn[];
extern const u8 gStatusConditionString_BurnJpn[];
extern const u8 gStatusConditionString_IceJpn[];
extern const u8 gStatusConditionString_ConfusionJpn[];

// read via orr
#define BSScriptRead32(ptr) ((ptr)[0] | (ptr)[1] << 8 | (ptr)[2] << 16 | (ptr)[3] << 24)
#define BSScriptRead16(ptr) ((ptr)[0] | ((ptr)[1] << 8))
#define BSScriptReadPtr(ptr) ((void *)BSScriptRead32(ptr))

// read via add
#define BS2ScriptRead32(ptr) ((ptr)[0] + ((ptr)[1] << 8) + ((ptr)[2] << 16) + ((ptr)[3] << 24))
#define BS2ScriptRead16(ptr) ((ptr)[0] + ((ptr)[1] << 8))
#define BS2ScriptReadPtr(ptr) ((void *)BS2ScriptRead32(ptr))

#define TARGET_PROTECT_AFFECTED ((gProtectStructs[gBankTarget].protected && gBattleMoves[gCurrentMove].flags & F_AFFECTED_BY_PROTECT))

//array entries for battle communication
#define MOVE_EFFECT_BYTE    0x3
#define MULTISTRING_CHOOSER 0x5
#define MSG_DISPLAY         0x7

#define TARGET_SELECTED         0x0
#define TARGET_DEPENDS          0x1
#define TARGET_BOTH             0x8
#define TARGET_FOES_AND_ALLY    0x20
#define TARGET_OPPONENTS_FIELD  0x40

#define TYPE_FORESIGHT  0xFE
#define TYPE_ENDTABLE   0xFF

#define CMP_EQUAL               0x0
#define CMP_NOT_EQUAL           0x1
#define CMP_GREATER_THAN        0x2
#define CMP_LESS_THAN           0x3
#define CMP_COMMON_BITS         0x4
#define CMP_NO_COMMON_BITS      0x5

#define uBYTE0_16(value)(( (u8) (((u16)(value) & (0x000000FF)) >> 0x00)))
#define uBYTE1_16(value)(( (u8) (((u16)(value) & (0x0000FF00)) >> 0x08)))

#define uBYTE0_32(value)(( (u8) (((u32)(value) & (0x000000FF)) >> 0x00)))
#define uBYTE1_32(value)(( (u8) (((u32)(value) & (0x0000FF00)) >> 0x08)))
#define uBYTE2_32(value)(( (u8) (((u32)(value) & (0x00FF0000)) >> 0x10)))
#define uBYTE3_32(value)(( (u8) (((u32)(value) & (0xFF000000)) >> 0x18)))

#define sBYTE0_16(value)(( (u8) (((s16)(value) & (0x000000FF)) >> 0x00)))
#define sBYTE1_16(value)(( (u8) (((s16)(value) & (0x0000FF00)) >> 0x08)))

#define sBYTE0_32(value)(( (u8) (((s32)(value) & (0x000000FF)) >> 0x00)))
#define sBYTE1_32(value)(( (u8) (((s32)(value) & (0x0000FF00)) >> 0x08)))
#define sBYTE2_32(value)(( (u8) (((s32)(value) & (0x00FF0000)) >> 0x10)))
#define sBYTE3_32(value)(( (u8) (((s32)(value) & (0xFF000000)) >> 0x18)))

#define RecordAbilitySetField6(ability, fieldValue) \
(gLastUsedAbility = ability, gBattleCommunication[6] = fieldValue, RecordAbilityBattle(gBankTarget, ability))

#define TARGET_TURN_DAMAGED (((gSpecialStatuses[gBankTarget].moveturnLostHP_physical || gSpecialStatuses[gBankTarget].moveturnLostHP_special)))

#define HP_ON_SWITCHOUT (((u16*)(ewram_addr + 0x160BC)))

static void atk00_attackcanceler(void);
static void atk01_accuracycheck(void);
static void atk02_attackstring(void);
static void atk03_ppreduce(void);
static void atk04_critcalc(void);
static void atk05_damagecalc(void);
static void atk06_typecalc(void);
static void atk07_adjustnormaldamage(void);
static void atk08_adjustnormaldamage2(void);
static void atk09_attackanimation(void);
static void atk0A_waitanimation(void);
static void atk0B_healthbarupdate(void);
static void atk0C_datahpupdate(void);
static void atk0D_critmessage(void);
static void atk0E_effectivenesssound(void);
static void atk0F_resultmessage(void);
static void atk10_printstring(void);
static void atk11_printselectionstring(void);
static void atk12_waitmessage(void);
static void atk13_printfromtable(void);
static void atk14_printselectionstringfromtable(void);
static void atk15_seteffectwithchance(void);
static void atk16_seteffectprimary(void);
static void atk17_seteffectsecondary(void);
static void atk18_clearstatusfromeffect(void);
static void atk19_tryfaintmon(void);
static void atk1A_dofaintanimation(void);
static void atk1B_cleareffectsonfaint(void);
static void atk1C_jumpifstatus(void);
static void atk1D_jumpifstatus2(void);
static void atk1E_jumpifability(void);
static void atk1F_jumpifsideaffecting(void);
static void atk20_jumpifstat(void);
static void atk21_jumpifstatus3condition(void);
static void atk22_jumpiftype(void);
static void atk23_getexp(void);
static void atk24(void);
static void atk25_movevaluescleanup(void);
static void atk26_setmultihit(void);
static void atk27_decrementmultihit(void);
static void atk28_goto(void);
static void atk29_jumpifbyte(void);
static void atk2A_jumpifhalfword(void);
static void atk2B_jumpifword(void);
static void atk2C_jumpifarrayequal(void);
static void atk2D_jumpifarraynotequal(void);
static void atk2E_setbyte(void);
static void atk2F_addbyte(void);
static void atk30_subbyte(void);
static void atk31_copyarray(void);
static void atk32_copyarraywithindex(void);
static void atk33_orbyte(void);
static void atk34_orhalfword(void);
static void atk35_orword(void);
static void atk36_bicbyte(void);
static void atk37_bichalfword(void);
static void atk38_bicword(void);
static void atk39_pause(void);
static void atk3A_waitstate(void);
static void atk3B_healthbar_update(void);
static void atk3C_return(void);
static void atk3D_end(void);
static void atk3E_end2(void);
static void atk3F_end3(void);
static void atk40_jumpifaffectedbyprotect(void);
static void atk41_call(void);
static void atk42_jumpiftype2(void);
static void atk43_jumpifabilitypresent(void);
static void atk44_endselectionscript(void);
static void atk45_playanimation(void);
static void atk46_playanimation2(void);
static void atk47_setgraphicalstatchangevalues(void);
static void atk48_playstatchangeanimation(void);
static void atk49_moveend(void);
static void atk4A_typecalc2(void);
static void atk4B_returnatktoball(void);
static void atk4C_getswitchedmondata(void);
static void atk4D_switchindataupdate(void);
static void atk4E_switchinanim(void);
static void atk4F_jumpifcantswitch(void);
static void atk50_openpartyscreen(void);
static void atk51_switchhandleorder(void);
static void atk52_switchineffects(void);
static void atk53_trainerslidein(void);
static void atk54_playse(void);
static void atk55_fanfare(void);
static void atk56_playfaintcry(void);
static void atk57(void);
static void atk58_returntoball(void);
void atk59_handlelearnnewmove(void);
static void atk5A_yesnoboxlearnmove(void);
static void atk5B_yesnoboxstoplearningmove(void);
static void atk5C_hitanimation(void);
static void atk5D_getmoneyreward(void);
static void atk5E_8025A70(void);
static void atk5F_8025B24(void);
static void atk60_incrementgamestat(void);
static void atk61_drawpartystatussummary(void);
static void atk62_08025C6C(void);
static void atk63_jumptorandomattack(void);
static void atk64_statusanimation(void);
static void atk65_status2animation(void);
static void atk66_chosenstatusanimation(void);
static void atk67_yesnobox(void);
static void atk68_cancelallactions(void);
static void atk69_adjustsetdamage(void);
void atk6A_removeitem(void);
static void atk6B_atknameinbuff1(void);
static void atk6C_drawlvlupbox(void);
static void atk6D_resetsentmonsvalue(void);
static void atk6E_setatktoplayer0(void);
static void atk6F_makevisible(void);
static void atk70_recordlastability(void);
static void atk71_buffermovetolearn(void);
static void atk72_jumpifplayerran(void);
static void atk73_hpthresholds(void);
static void atk74_hpthresholds2(void);
static void atk75_useitemonopponent(void);
static void atk76_various(void);
static void atk77_setprotectlike(void);
static void atk78_faintifabilitynotdamp(void);
static void atk79_setatkhptozero(void);
static void atk7A_jumpifnexttargetvalid(void);
static void atk7B_tryhealhalfhealth(void);
static void atk7C_trymirrormove(void);
static void atk7D_setrain(void);
static void atk7E_setreflect(void);
static void atk7F_setseeded(void);
static void atk80_manipulatedamage(void);
static void atk81_trysetrest(void);
static void atk82_jumpifnotfirstturn(void);
static void atk83_nop(void);
static void atk84_jumpifcantmakeasleep(void);
static void atk85_stockpile(void);
static void atk86_stockpiletobasedamage(void);
static void atk87_stockpiletohpheal(void);
static void atk88_negativedamage(void);
static u8 ChangeStatBuffs(s8 statValue, u8 statId, u8 flags, const u8 *BS_ptr);
static void atk89_statbuffchange(void);
static void atk8A_normalisebuffs(void);
static void atk8B_setbide(void);
static void atk8C_confuseifrepeatingattackends(void);
static void atk8D_setmultihitcounter(void);
static void atk8E_initmultihitstring(void);
static void atk8F_forcerandomswitch(void);
static void atk90_tryconversiontypechange(void);
static void atk91_givepaydaymoney(void);
static void atk92_setlightscreen(void);
static void atk93_tryKO(void);
static void atk94_damagetohalftargethp(void);
static void atk95_setsandstorm(void);
static void atk96_weatherdamage(void);
static void atk97_tryinfatuating(void);
static void atk98_updatestatusicon(void);
static void atk99_setmist(void);
static void atk9A_setfocusenergy(void);
static void atk9B_transformdataexecution(void);
static void atk9C_setsubstitute(void);
static void atk9D_mimicattackcopy(void);
static void atk9E_metronome(void);
static void atk9F_dmgtolevel(void);
static void atkA0_psywavedamageeffect(void);
static void atkA1_counterdamagecalculator(void);
static void atkA2_mirrorcoatdamagecalculator(void);
static void atkA3_disablelastusedattack(void);
static void atkA4_trysetencore(void);
static void atkA5_painsplitdmgcalc(void);
static void atkA6_settypetorandomresistance(void);
static void atkA7_setalwayshitflag(void);
static void atkA8_copymovepermanently(void);
static void atkA9_trychoosesleeptalkmove(void);
static void atkAA_setdestinybond(void);
static void atkAB_trysetdestinybondtohappen(void);
static void atkAC_remaininghptopower(void);
static void atkAD_tryspiteppreduce(void);
static void atkAE_healpartystatus(void);
static void atkAF_cursetarget(void);
static void atkB0_trysetspikes(void);
static void atkB1_setforesight(void);
static void atkB2_trysetperishsong(void);
static void atkB3_rolloutdamagecalculation(void);
static void atkB4_jumpifconfusedandstatmaxed(void);
static void atkB5_furycuttercalc(void);
static void atkB6_happinesstodamagecalculation(void);
static void atkB7_presentdamagecalculation(void);
static void atkB8_setsafeguard(void);
static void atkB9_magnitudedamagecalculation(void);
static void atkBA_jumpifnopursuitswitchdmg(void);
static void atkBB_setsunny(void);
static void atkBC_maxattackhalvehp(void);
static void atkBD_copyfoestats(void);
static void atkBE_rapidspinfree(void);
static void atkBF_setdefensecurlbit(void);
static void atkC0_recoverbasedonsunlight(void);
static void atkC1_hiddenpowercalc(void);
static void atkC2_selectfirstvalidtarget(void);
static void atkC3_trysetfutureattack(void);
static void atkC4_trydobeatup(void);
static void atkC5_setsemiinvulnerablebit(void);
static void atkC6_clearsemiinvulnerablebit(void);
static void atkC7_setminimize(void);
static void atkC8_sethail(void);
static void atkC9_jumpifattackandspecialattackcannotfall(void);
static void atkCA_setforcedtarget(void);
static void atkCB_setcharge(void);
static void atkCC_callterrainattack(void);
static void atkCD_cureifburnedparalysedorpoisoned(void);
static void atkCE_settorment(void);
static void atkCF_jumpifnodamage(void);
static void atkD0_settaunt(void);
static void atkD1_trysethelpinghand(void);
static void atkD2_tryswapitems(void);
static void atkD3_trycopyability(void);
static void atkD4_trywish(void);
static void atkD5_trysetroots(void);
static void atkD6_doubledamagedealtifdamaged(void);
static void atkD7_setyawn(void);
static void atkD8_setdamagetohealthdifference(void);
static void atkD9_scaledamagebyhealthratio(void);
static void atkDA_tryswapabilities(void);
static void atkDB_tryimprision(void);
static void atkDC_trysetgrudge(void);
static void atkDD_weightdamagecalculation(void);
static void atkDE_asistattackselect(void);
static void atkDF_trysetmagiccoat(void);
static void atkE0_trysetsnatch(void);
static void atkE1_trygetintimidatetarget(void);
static void atkE2_switchoutabilities(void);
static void atkE3_jumpifhasnohp(void);
static void atkE4_getsecretpowereffect(void);
static void atkE5_pickup(void);
static void atkE6_docastformchangeanimation(void);
static void atkE7_trycastformdatachange(void);
static void atkE8_settypebasedhalvers(void);
static void atkE9_setweatherballtype(void);
static void atkEA_tryrecycleitem(void);
static void atkEB_settypetoterrain(void);
static void atkEC_pursuitrelated(void);
static void atkED_snatchsetbanks(void);
static void atkEE_removelightscreenreflect(void);
void atkEF_handleballthrow(void);
static void atkF0_givecaughtmon(void);
static void atkF1_trysetcaughtmondexflags(void);
static void atkF2_displaydexinfo(void);
static void atkF3_trygivecaughtmonnick(void);
static void atkF4_subattackerhpbydmg(void);
static void atkF5_removeattackerstatus1(void);
static void atkF6_finishaction(void);
static void atkF7_finishturn(void);
static void atkF8_special(void);

static void sp00_suckerpunch(void);
static void sp01_fling(void);
static void sp02_flingloseitem(void);
static void sp03_bugbite(void);
static void sp04_naturalgift(void);
static void sp05_defogreflect(void);
static void sp06_defoglightscreen(void);
static void sp07_defogsafeguard(void);
static void sp08_defogmist(void);
static void sp09_defogfoespikes(void);
static void sp0A_defogownspikes(void);
static void sp0B_roost(void);
static void sp0C_payback(void);
static void sp0D_tailwind(void);
static void sp0E_luckychant(void);
static void sp0F_storedpower(void);
static void sp10_captivate(void);
static void sp11_healingwish(void);
static void sp12_spikesaffect(void);
static void sp13_healingwishaffect(void);
static void sp14_setstickyweb(void);
static void sp15_webaffect(void);
static void sp16_defogfoeweb(void);
static void sp17_defogownweb(void);
static void sp18_worryseed(void);
static void sp19_punishment(void);
static void sp1A_echoedvoice(void);
static void sp1B_sleepremoval(void);
static void sp1C_heavyslam(void);
static void sp1D_aquaring(void);
static void sp1E_soak(void);
static void sp1F_setstealthrock(void);
static void sp20_rocksaffect(void);
static void sp21_defogfoerocks(void);
static void sp22_defogownrocks(void);
static void sp23_copycat(void);
static void sp24_settoxicspikes(void);
static void sp25_toxicspikesaffect(void);
static void sp26_wringout(void);
static void sp27_defogfoetoxicspikes(void);
static void sp28_defogowntoxicspikes(void);
static void sp29_reflecttype(void);
static void sp2A_metalburst(void);
static void sp2B_electroball(void);
static void sp2C_entrainmentfailcheck(void);
static void sp2D_trumpcard(void);
static void sp2E_entrainmentapply(void);
static void sp2F_incinerate(void);
static void sp30_clearsmog(void);
static void sp31_gyroball(void);
static void sp32_feint(void);
static void sp33_powertrick(void);
static void sp34_powersplit(void);
static void sp35_guardsplit(void);
static void sp36_bpasspowertrick(void);
static void sp37_spotlight(void);
static void sp38_acupressure(void);
static void sp39_frisk(void);
static void sp3A_mefirst(void);
static void sp3B_powerswap(void);
static void sp3C_guardswap(void);
static void sp3D_psychoshiftsleep(void);
static void sp3E_uturncheck(void);
static void sp3F_setauroraveil(void);
static void sp40_settrickroom(void);
static void sp41_checkdefiant(void);
static void sp42_checkdefiantwebs(void);
static void sp43_checkdefianttarget(void);
static void sp44_preparecatchexp(void);
static void sp45_fellstingercheck(void);
static void sp46_finalgambit(void);
static void sp47_burnup(void);
static void sp48_lastresort(void);
static void sp49_losemoney(void);
static void sp4A_round(void);
static void sp4B_jumpkickrecoil(void);
static void sp4C_checkexplosiontargetvalidity(void);
static void sp4D_endifnopowerherb(void);
static void sp4E_demonbook(void);
static void sp4F_forcewin(void);
static void sp50_usegun(void);
static void sp51_usexnihilo(void);
static void sp52_usemaxrevive(void);

void (* const gBattleScriptingCommandsTable[])(void) =
{
    atk00_attackcanceler,
    atk01_accuracycheck,
    atk02_attackstring,
    atk03_ppreduce,
    atk04_critcalc,
    atk05_damagecalc,
    atk06_typecalc,
    atk07_adjustnormaldamage,
    atk08_adjustnormaldamage2,
    atk09_attackanimation,
    atk0A_waitanimation,
    atk0B_healthbarupdate,
    atk0C_datahpupdate,
    atk0D_critmessage,
    atk0E_effectivenesssound,
    atk0F_resultmessage,
    atk10_printstring,
    atk11_printselectionstring,
    atk12_waitmessage,
    atk13_printfromtable,
    atk14_printselectionstringfromtable,
    atk15_seteffectwithchance,
    atk16_seteffectprimary,
    atk17_seteffectsecondary,
    atk18_clearstatusfromeffect,
    atk19_tryfaintmon,
    atk1A_dofaintanimation,
    atk1B_cleareffectsonfaint,
    atk1C_jumpifstatus,
    atk1D_jumpifstatus2,
    atk1E_jumpifability,
    atk1F_jumpifsideaffecting,
    atk20_jumpifstat,
    atk21_jumpifstatus3condition,
    atk22_jumpiftype,
    atk23_getexp,
    atk24,
    atk25_movevaluescleanup,
    atk26_setmultihit,
    atk27_decrementmultihit,
    atk28_goto,
    atk29_jumpifbyte,
    atk2A_jumpifhalfword,
    atk2B_jumpifword,
    atk2C_jumpifarrayequal,
    atk2D_jumpifarraynotequal,
    atk2E_setbyte,
    atk2F_addbyte,
    atk30_subbyte,
    atk31_copyarray,
    atk32_copyarraywithindex,
    atk33_orbyte,
    atk34_orhalfword,
    atk35_orword,
    atk36_bicbyte,
    atk37_bichalfword,
    atk38_bicword,
    atk39_pause,
    atk3A_waitstate,
    atk3B_healthbar_update,
    atk3C_return,
    atk3D_end,
    atk3E_end2,
    atk3F_end3,
    atk40_jumpifaffectedbyprotect,
    atk41_call,
    atk42_jumpiftype2,
    atk43_jumpifabilitypresent,
    atk44_endselectionscript,
    atk45_playanimation,
    atk46_playanimation2,
    atk47_setgraphicalstatchangevalues,
    atk48_playstatchangeanimation,
    atk49_moveend,
    atk4A_typecalc2,
    atk4B_returnatktoball,
    atk4C_getswitchedmondata,
    atk4D_switchindataupdate,
    atk4E_switchinanim,
    atk4F_jumpifcantswitch,
    atk50_openpartyscreen,
    atk51_switchhandleorder,
    atk52_switchineffects,
    atk53_trainerslidein,
    atk54_playse,
    atk55_fanfare,
    atk56_playfaintcry,
    atk57,
    atk58_returntoball,
    atk59_handlelearnnewmove,
    atk5A_yesnoboxlearnmove,
    atk5B_yesnoboxstoplearningmove,
    atk5C_hitanimation,
    atk5D_getmoneyreward,
    atk5E_8025A70,
    atk5F_8025B24,
    atk60_incrementgamestat,
    atk61_drawpartystatussummary,
    atk62_08025C6C,
    atk63_jumptorandomattack,
    atk64_statusanimation,
    atk65_status2animation,
    atk66_chosenstatusanimation,
    atk67_yesnobox,
    atk68_cancelallactions,
    atk69_adjustsetdamage,
    atk6A_removeitem,
    atk6B_atknameinbuff1,
    atk6C_drawlvlupbox,
    atk6D_resetsentmonsvalue,
    atk6E_setatktoplayer0,
    atk6F_makevisible,
    atk70_recordlastability,
    atk71_buffermovetolearn,
    atk72_jumpifplayerran,
    atk73_hpthresholds,
    atk74_hpthresholds2,
    atk75_useitemonopponent,
    atk76_various,
    atk77_setprotectlike,
    atk78_faintifabilitynotdamp,
    atk79_setatkhptozero,
    atk7A_jumpifnexttargetvalid,
    atk7B_tryhealhalfhealth,
    atk7C_trymirrormove,
    atk7D_setrain,
    atk7E_setreflect,
    atk7F_setseeded,
    atk80_manipulatedamage,
    atk81_trysetrest,
    atk82_jumpifnotfirstturn,
    atk83_nop,
    atk84_jumpifcantmakeasleep,
    atk85_stockpile,
    atk86_stockpiletobasedamage,
    atk87_stockpiletohpheal,
    atk88_negativedamage,
    atk89_statbuffchange,
    atk8A_normalisebuffs,
    atk8B_setbide,
    atk8C_confuseifrepeatingattackends,
    atk8D_setmultihitcounter,
    atk8E_initmultihitstring,
    atk8F_forcerandomswitch,
    atk90_tryconversiontypechange,
    atk91_givepaydaymoney,
    atk92_setlightscreen,
    atk93_tryKO,
    atk94_damagetohalftargethp,
    atk95_setsandstorm,
    atk96_weatherdamage,
    atk97_tryinfatuating,
    atk98_updatestatusicon,
    atk99_setmist,
    atk9A_setfocusenergy,
    atk9B_transformdataexecution,
    atk9C_setsubstitute,
    atk9D_mimicattackcopy,
    atk9E_metronome,
    atk9F_dmgtolevel,
    atkA0_psywavedamageeffect,
    atkA1_counterdamagecalculator,
    atkA2_mirrorcoatdamagecalculator,
    atkA3_disablelastusedattack,
    atkA4_trysetencore,
    atkA5_painsplitdmgcalc,
    atkA6_settypetorandomresistance,
    atkA7_setalwayshitflag,
    atkA8_copymovepermanently,
    atkA9_trychoosesleeptalkmove,
    atkAA_setdestinybond,
    atkAB_trysetdestinybondtohappen,
    atkAC_remaininghptopower,
    atkAD_tryspiteppreduce,
    atkAE_healpartystatus,
    atkAF_cursetarget,
    atkB0_trysetspikes,
    atkB1_setforesight,
    atkB2_trysetperishsong,
    atkB3_rolloutdamagecalculation,
    atkB4_jumpifconfusedandstatmaxed,
    atkB5_furycuttercalc,
    atkB6_happinesstodamagecalculation,
    atkB7_presentdamagecalculation,
    atkB8_setsafeguard,
    atkB9_magnitudedamagecalculation,
    atkBA_jumpifnopursuitswitchdmg,
    atkBB_setsunny,
    atkBC_maxattackhalvehp,
    atkBD_copyfoestats,
    atkBE_rapidspinfree,
    atkBF_setdefensecurlbit,
    atkC0_recoverbasedonsunlight,
    atkC1_hiddenpowercalc,
    atkC2_selectfirstvalidtarget,
    atkC3_trysetfutureattack,
    atkC4_trydobeatup,
    atkC5_setsemiinvulnerablebit,
    atkC6_clearsemiinvulnerablebit,
    atkC7_setminimize,
    atkC8_sethail,
    atkC9_jumpifattackandspecialattackcannotfall,
    atkCA_setforcedtarget,
    atkCB_setcharge,
    atkCC_callterrainattack,
    atkCD_cureifburnedparalysedorpoisoned,
    atkCE_settorment,
    atkCF_jumpifnodamage,
    atkD0_settaunt,
    atkD1_trysethelpinghand,
    atkD2_tryswapitems,
    atkD3_trycopyability,
    atkD4_trywish,
    atkD5_trysetroots,
    atkD6_doubledamagedealtifdamaged,
    atkD7_setyawn,
    atkD8_setdamagetohealthdifference,
    atkD9_scaledamagebyhealthratio,
    atkDA_tryswapabilities,
    atkDB_tryimprision,
    atkDC_trysetgrudge,
    atkDD_weightdamagecalculation,
    atkDE_asistattackselect,
    atkDF_trysetmagiccoat,
    atkE0_trysetsnatch,
    atkE1_trygetintimidatetarget,
    atkE2_switchoutabilities,
    atkE3_jumpifhasnohp,
    atkE4_getsecretpowereffect,
    atkE5_pickup,
    atkE6_docastformchangeanimation,
    atkE7_trycastformdatachange,
    atkE8_settypebasedhalvers,
    atkE9_setweatherballtype,
    atkEA_tryrecycleitem,
    atkEB_settypetoterrain,
    atkEC_pursuitrelated,
    atkED_snatchsetbanks,
    atkEE_removelightscreenreflect,
    atkEF_handleballthrow,
    atkF0_givecaughtmon,
    atkF1_trysetcaughtmondexflags,
    atkF2_displaydexinfo,
    atkF3_trygivecaughtmonnick,
    atkF4_subattackerhpbydmg,
    atkF5_removeattackerstatus1,
    atkF6_finishaction,
    atkF7_finishturn,
	atkF8_special,
};

struct StatFractions
{
    u8 dividend;
    u8 divisor;
};

static const struct StatFractions gAccuracyStageRatios[] =
{
    { 33, 100}, // -6
    { 36, 100}, // -5
    { 43, 100}, // -4
    { 50, 100}, // -3
    { 60, 100}, // -2
    { 75, 100}, // -1
    {  1,   1}, //  0
    {133, 100}, // +1
    {166, 100}, // +2
    {  2,   1}, // +3
    {233, 100}, // +4
    {133,  50}, // +5
    {  3,   1}, // +6
};

// The chance is 1/N for each stage.
static const u16 sCriticalHitChance[] = {24, 8, 2, 1, 1};

static const u32 sStatusFlagsForMoveEffects[] =
{
    0x00000000,
    STATUS_SLEEP,
    STATUS_POISON,
    STATUS_BURN,
    STATUS_FREEZE,
    STATUS_PARALYSIS,
    STATUS_TOXIC_POISON,
    STATUS2_CONFUSION,
    STATUS2_FLINCHED,
    0x00000000,
    STATUS2_UPROAR,
    0x00000000,
    STATUS2_MULTIPLETURNS,
    STATUS2_WRAPPED,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    STATUS2_RECHARGE,
    0x00000000,
    0x00000000,
    STATUS2_ESCAPE_PREVENTION,
    STATUS2_NIGHTMARE,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    STATUS2_LOCK_CONFUSE,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000
};

u8* const gMoveEffectBS_Ptrs[] =
{
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectPoison,
    BattleScript_MoveEffectBurn,
    BattleScript_MoveEffectFreeze,
    BattleScript_MoveEffectParalysis,
    BattleScript_MoveEffectToxic,
    BattleScript_MoveEffectConfusion,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectUproar,
    BattleScript_MoveEffectPayDay,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectWrap,
    BattleScript_MoveEffectRecoil33,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectSleep,
    BattleScript_MoveEffectRecoil33
};

const u8 sUnreferencedBitMask1[] = {0, 1, 3, 7, 0xF, 0x1F, 0x3F};

const u8 gLevelUpStatBoxStats[] =
{
    MON_DATA_MAX_HP, MON_DATA_SPATK, MON_DATA_ATK,
    MON_DATA_SPDEF, MON_DATA_DEF, MON_DATA_SPEED
};

static const u16 sProtectSuccessRates[] = {0xFFFF, 0x5555, 0x1C71, 0x097B, 0x0329, 0x10D, 0x0059};

#define MIMIC_FORBIDDEN_END             0xFFFE
#define METRONOME_FORBIDDEN_END         0xFFFF
#define ASSIST_FORBIDDEN_END            0xFFFF

static const u16 sMovesForbiddenToCopy[] =
{
     MOVE_METRONOME,
     MOVE_STRUGGLE,
     MOVE_SKETCH,
     MOVE_MIMIC,
     MIMIC_FORBIDDEN_END,
     MOVE_COUNTER,
     MOVE_MIRROR_COAT,
     MOVE_PROTECT,
     MOVE_DETECT,
     MOVE_ENDURE,
     MOVE_DESTINY_BOND,
     MOVE_SLEEP_TALK,
     MOVE_THIEF,
     MOVE_FOLLOW_ME,
     MOVE_SNATCH,
     MOVE_HELPING_HAND,
     MOVE_COVET,
     MOVE_TRICK,
     MOVE_FOCUS_PUNCH,
     MOVE_AURORA_VEIL,
     METRONOME_FORBIDDEN_END
};

static const u8 sFlailHpScaleToPowerTable[] = //reversal+flail HP thresholds to power
{
    1, 200,
    4, 150,
    9, 100,
    16, 80,
    32, 40,
    48, 20
};

static const u16 sNaturePowerMoves[] =
{
    MOVE_ENERGY_BALL, // grass
    MOVE_LEAF_STORM, // long grass
    MOVE_EARTH_POWER, // sand
    MOVE_HYDRO_PUMP, // underwater
    MOVE_BRINE, // sea water
    MOVE_MUD_BOMB, // pond
    MOVE_POWER_GEM, // rock
    MOVE_POWER_GEM, // cave
    MOVE_TRI_ATTACK, // plain, etc.
    MOVE_TRI_ATTACK,
};

static const u8 sTerrainToType[] =
{
    TYPE_GRASS, // tall grass
    TYPE_GRASS, // long grass
    TYPE_GROUND, // sand
    TYPE_WATER, // underwater
    TYPE_WATER, // water
    TYPE_WATER, // pond water
    TYPE_ROCK, // rock
    TYPE_ROCK, // cave
    TYPE_NORMAL, // building
    TYPE_NORMAL, // plain
};

static const u8 sBallCatchBonuses[] =
{
    20, 15, 10, 20 // Ultra, Great, Poke, Safari
};

// Note: only contains abilities bypassed by jumpifability
static const u8 sMoldBreakerAbilities[] =
{
	ABILITY_IMMUNITY,
	ABILITY_INSOMNIA,
	ABILITY_LIMBER,
	ABILITY_MAGMA_ARMOR, // redundant but may become relevant?
	ABILITY_OBLIVIOUS,
	ABILITY_OWN_TEMPO,
	ABILITY_SOUNDPROOF,
	ABILITY_SUCTION_CUPS,
	ABILITY_VITAL_SPIRIT,
	ABILITY_WATER_VEIL,
	0,
};

static const u16 sPickupItemsL10[] =
{
    ITEM_POTION, 25,
    ITEM_ANTIDOTE, 35,
	ITEM_SUPER_POTION, 45,
	ITEM_GREAT_BALL, 55,
	ITEM_REPEL, 65,
	ITEM_ESCAPE_ROPE, 75,
	ITEM_FULL_HEAL, 85,
	ITEM_HYPER_POTION, 90,
	ITEM_STICK, 95,
	ITEM_ULTRA_BALL, 98,
	ITEM_KINGS_ROCK, 99,
	ITEM_LEFTOVERS, 1,
};

static const u16 sPickupItemsL20[] =
{
    ITEM_ANTIDOTE, 25,
    ITEM_SUPER_POTION, 35,
	ITEM_GREAT_BALL, 45,
	ITEM_REPEL, 55,
	ITEM_ESCAPE_ROPE, 65,
	ITEM_FULL_HEAL, 75,
	ITEM_HYPER_POTION, 80,
	ITEM_STICK, 83,
	ITEM_ULTRA_BALL, 86,
	ITEM_KINGS_ROCK, 87,
	ITEM_LEFTOVERS, 88,
	ITEM_SUN_STONE, 91,
	ITEM_MOON_STONE, 94,
	ITEM_DRAGON_SCALE, 97,
	ITEM_REVIVE, 99,
	ITEM_BIG_MUSHROOM, 1,
};

static const u16 sPickupItemsL30[] =
{
    ITEM_SUPER_POTION, 25,
    ITEM_GREAT_BALL, 35,
	ITEM_REPEL, 45,
	ITEM_ESCAPE_ROPE, 55,
	ITEM_FULL_HEAL, 65,
	ITEM_HYPER_POTION, 70,
	ITEM_ULTRA_BALL, 75,
	ITEM_KINGS_ROCK, 76,
	ITEM_LEFTOVERS, 77,
	ITEM_SUN_STONE, 82,
	ITEM_MOON_STONE, 87,
	ITEM_DRAGON_SCALE, 90,
	ITEM_REVIVE, 92,
	ITEM_BIG_MUSHROOM, 95,
	ITEM_RARE_CANDY, 98,
	ITEM_BIG_PEARL, 99,
	ITEM_FULL_RESTORE, 1,
};

static const u16 sPickupItemsL40[] =
{
    ITEM_GREAT_BALL, 25,
    ITEM_REPEL, 35,
	ITEM_ESCAPE_ROPE, 45,
	ITEM_FULL_HEAL, 55,
	ITEM_HYPER_POTION, 65,
	ITEM_ULTRA_BALL, 70,
	ITEM_KINGS_ROCK, 71,
	ITEM_LEFTOVERS, 72,
	ITEM_SUN_STONE, 77,
	ITEM_MOON_STONE, 82,
	ITEM_DRAGON_SCALE, 85,
	ITEM_REVIVE, 90,
	ITEM_RARE_CANDY, 93,
	ITEM_BIG_PEARL, 97,
	ITEM_FULL_RESTORE, 98,
	ITEM_NUGGET, 99,
	ITEM_ETHER, 91,
};

static const u16 sPickupItemsL50[] =
{
    ITEM_REPEL, 20,
    ITEM_ESCAPE_ROPE, 30,
	ITEM_FULL_HEAL, 40,
	ITEM_HYPER_POTION, 50,
	ITEM_ULTRA_BALL, 60,
	ITEM_KINGS_ROCK, 61,
	ITEM_LEFTOVERS, 62,
	ITEM_SUN_STONE, 72,
	ITEM_MOON_STONE, 82,
	ITEM_DRAGON_SCALE, 85,
	ITEM_REVIVE, 90,
	ITEM_RARE_CANDY, 93,
	ITEM_FULL_RESTORE, 95,
	ITEM_NUGGET, 99,
	ITEM_ETHER, 91,
};

static const u16 sPickupItemsL60[] =
{
    ITEM_ESCAPE_ROPE, 20,
    ITEM_FULL_HEAL, 30,
	ITEM_HYPER_POTION, 40,
	ITEM_ULTRA_BALL, 50,
	ITEM_KINGS_ROCK, 51,
	ITEM_LEFTOVERS, 52,
	ITEM_SUN_STONE, 62,
	ITEM_MOON_STONE, 72,
	ITEM_DRAGON_SCALE, 75,
	ITEM_REVIVE, 82,
	ITEM_RARE_CANDY, 90,
	ITEM_FULL_RESTORE, 93,
	ITEM_NUGGET, 98,
	ITEM_ETHER, 99,
	ITEM_HEART_SCALE, 1,
};

static const u16 sPickupItemsL70[] =
{
    ITEM_FULL_HEAL, 20,
    ITEM_HYPER_POTION, 30,
	ITEM_ULTRA_BALL, 40,
	ITEM_KINGS_ROCK, 41,
	ITEM_LEFTOVERS, 42,
	ITEM_SUN_STONE, 52,
	ITEM_MOON_STONE, 62,
	ITEM_DRAGON_SCALE, 65,
	ITEM_REVIVE, 75,
	ITEM_RARE_CANDY, 83,
	ITEM_FULL_RESTORE, 88,
	ITEM_NUGGET, 93,
	ITEM_HEART_SCALE, 97,
	ITEM_ELIXIR, 1,
};

static const u16 sPickupItemsL80[] =
{
    ITEM_HYPER_POTION, 20,
    ITEM_ULTRA_BALL, 30,
	ITEM_KINGS_ROCK, 31,
	ITEM_LEFTOVERS, 32,
	ITEM_SUN_STONE, 42,
	ITEM_MOON_STONE, 52,
	ITEM_DRAGON_SCALE, 55,
	ITEM_REVIVE, 65,
	ITEM_RARE_CANDY, 73,
	ITEM_FULL_RESTORE, 78,
	ITEM_NUGGET, 83,
	ITEM_HEART_SCALE, 93,
	ITEM_ELIXIR, 98,
	ITEM_MAX_REVIVE, 1,
};

static const u16 sPickupItemsL90[] =
{
    ITEM_ULTRA_BALL, 20,
	ITEM_KINGS_ROCK, 21,
	ITEM_LEFTOVERS, 22,
	ITEM_SUN_STONE, 32,
	ITEM_MOON_STONE, 42,
	ITEM_DRAGON_SCALE, 45,
	ITEM_REVIVE, 55,
	ITEM_RARE_CANDY, 63,
	ITEM_FULL_RESTORE, 73,
	ITEM_NUGGET, 78,
	ITEM_HEART_SCALE, 88,
	ITEM_MAX_REVIVE, 98,
	ITEM_PP_UP, 99,
	ITEM_MAX_ELIXIR, 1,
};

static const u16 sPickupItemsL100[] =
{
	ITEM_KINGS_ROCK, 1,
	ITEM_LEFTOVERS, 2,
	ITEM_SUN_STONE, 12,
	ITEM_MOON_STONE, 22,
	ITEM_DRAGON_SCALE, 25,
	ITEM_REVIVE, 45,
	ITEM_RARE_CANDY, 53,
	ITEM_FULL_RESTORE, 68,
	ITEM_NUGGET, 73,
	ITEM_HEART_SCALE, 83,
	ITEM_MAX_REVIVE, 93,
	ITEM_PP_UP, 97,
	ITEM_MAX_ELIXIR, 1,
};

static const u16* sPickupTables[] =
{
	sPickupItemsL10,
	sPickupItemsL20,
	sPickupItemsL30,
	sPickupItemsL40,
	sPickupItemsL50,
	sPickupItemsL60,
	sPickupItemsL70,
	sPickupItemsL80,
	sPickupItemsL90,
	sPickupItemsL100,
};

static const u32 sExperienceScalingFactors[] = 
{
	0,
    0,
    1,
    3,
    8,
    13,
    22,
    32,
    45,
    60,
    79,
    100,
    124,
    152,
    183,
    217,
    256,
    297,
    343,
    393,
    447,
    505,
    567,
    634,
    705,
    781,
    861,
    946,
    1037,
    1132,
    1232,
    1337,
    1448,
    1563,
    1685,
    1811,
    1944,
    2081,
    2225,
    2374,
    2529,
    2690,
    2858,
    3031,
    3210,
    3396,
    3587,
    3786,
    3990,
    4201,
    4419,
    4643,
    4874,
    5112,
    5357,
    5608,
    5866,
    6132,
    6404,
    6684,
    6971,
    7265,
    7566,
    7875,
    8192,
    8515,
    8847,
    9186,
    9532,
    9886,
    10249,
    10619,
    10996,
    11382,
    11776,
    12178,
    12588,
    13006,
    13433,
    13867,
    14310,
    14762,
    15222,
    15690,
    16167,
    16652,
    17146,
    17649,
    18161,
    18681,
    19210,
    19748,
    20295,
    20851,
    21417,
    21991,
    22574,
    23166,
    23768,
    24379,
    25000,
    25629,
    26268,
    26917,
    27575,
    28243,
    28920,
    29607,
    30303,
    31010,
    31726,
    32452,
    33188,
    33934,
    34689,
    35455,
    36231,
    37017,
    37813,
    38619,
    39436,
    40262,
    41099,
    41947,
    42804,
    43673,
    44551,
    45441,
    46340,
    47251,
    48172,
    49104,
    50046,
    50999,
    51963,
    52938,
    53924,
    54921,
    55929,
    56947,
    57977,
    59018,
    60070,
    61133,
    62208,
    63293,
    64390,
    65498,
    66618,
    67749,
    68891,
    70045,
    71211,
    72388,
    73576,
    74777,
    75989,
    77212,
    78448,
    79695,
    80954,
    82225,
    83507,
    84802,
    86109,
    87427,
    88758,
    90101,
    91456,
    92823,
    94202,
    95593,
    96997,
    98413,
    99841,
    101282,
    102735,
    104201,
    105679,
    107169,
    108672,
    110188,
    111716,
    113257,
    114811,
    116377,
    117956,
    119548,
    121153,
    122770,
    124401,
    126044,
    127700,
    129369,
    131052,
    132747,
    134456,
    136177,
    137912,
    139660,
    141421,
    143195,
    144983,
    146784,
    148598,
    150426,
    152267,
    154122,
    155990,
    157872,
    159767,
};

static const u16 sPlayerMoneyLossConstants[] =
{
    8,
    16,
    24,
    36,
    48,
    64,
    80,
    100,
    120,
};

static void atk00_attackcanceler(void)
{
    s32 i;

    if (gBattleOutcome != 0)
    {
        gCurrentActionFuncId = ACTION_FINISHED;
        return;
    }
    if (gBattleMons[gBankAttacker].hp == 0 && !(gHitMarker & HITMARKER_NO_ATTACKSTRING))
    {
        gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
        gBattlescriptCurrInstr = BattleScript_MoveEnd;
        return;
    }
    if (AtkCanceller_UnableToUseMove())
        return;
    if (gBattleMons[gBankAttacker].ability != ABILITY_MOLD_BREAKER && AbilityBattleEffects(ABILITYEFFECT_MOVES_BLOCK, gBankTarget, 0, 0, 0))
        return;
    if (!gBattleMons[gBankAttacker].pp[gCurrMovePos] && gCurrentMove != MOVE_STRUGGLE && !(gHitMarker & 0x800200)
     && !(gBattleMons[gBankAttacker].status2 & STATUS2_MULTIPLETURNS))
    {
        gBattlescriptCurrInstr = BattleScript_NoPPForMove;
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        return;
    }
    if (gBattleMons[gBankTarget].hp == 0 && gCurrentMove != MOVE_EXPLOSION && gCurrentMove != MOVE_SELF_DESTRUCT)
    {
        gBattlescriptCurrInstr = BattleScript_NoTarget;
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        return;
    }
	
	if (gBattleMons[gBankAttacker].ability == ABILITY_PRANKSTER && gBattleMoves[gCurrentMove].moveClass == CLASS_STATUS)
		gWishFutureKnock.pranksterBoosted = 1;

    gHitMarker &= ~(HITMARKER_x800000);

    if (!(gHitMarker & HITMARKER_OBEYS) && !(gBattleMons[gBankAttacker].status2 & STATUS2_MULTIPLETURNS))
    {
        i = IsMonDisobedient(); // why use the 'i' variable...?
        switch (i)
        {
        case 0:
            break;
        case 2:
            gHitMarker |= HITMARKER_OBEYS;
            return;
        default:
            gMoveResultFlags |= MOVE_RESULT_MISSED;
            return;
        }
    }

    gHitMarker |= HITMARKER_OBEYS;
    
    if (gBattleMons[gBankAttacker].ability == ABILITY_FORECAST)
    {
        u8 moveType = gBattleMoves[gCurrentMove].type;
        
        if ((moveType == TYPE_FIRE || gCurrentMove == MOVE_SOLAR_BEAM || gCurrentMove == MOVE_SYNTHESIS
            || gCurrentMove == MOVE_MOONLIGHT || gCurrentMove == MOVE_MORNING_SUN || gCurrentMove == MOVE_GROWTH)
            && !(gBattleWeather & WEATHER_SUN_ANY))
        {
            // set sun
			BattleScriptPushCursor();
			gBattlescriptCurrInstr = BattleScript_ForecastSun;
            gBattleStruct->scriptingActive = gBankAttacker;
			return;
        }
        else if ((moveType == TYPE_WATER || gCurrentMove == MOVE_THUNDER || gCurrentMove == MOVE_HURRICANE)
                && !(gBattleWeather & WEATHER_RAIN_ANY))
        {
            // set rain
			BattleScriptPushCursor();
			gBattlescriptCurrInstr = BattleScript_ForecastRain;
            gBattleStruct->scriptingActive = gBankAttacker;
            return;
        }
        else if ((moveType == TYPE_ICE) && !(gBattleWeather & WEATHER_HAIL))
        {
            // set hail
			BattleScriptPushCursor();
			gBattlescriptCurrInstr = BattleScript_ForecastHail;
            gBattleStruct->scriptingActive = gBankAttacker;
            return;
        }
    }

    if (gProtectStructs[gBankTarget].bounceMove && !(gWishFutureKnock.reflected) && gBattleMoves[gCurrentMove].flags & F_AFFECTED_BY_MAGIC_COAT)
    {
        PressurePPLose(gBankAttacker, gBankTarget, MOVE_MAGIC_COAT);
        gProtectStructs[gBankTarget].bounceMove = 0;
		gWishFutureKnock.reflected = 1;
		gWishFutureKnock.pranksterBoosted = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_MagicCoatBounce;
        return;
    }
	if (gBattleMons[gBankTarget].ability == ABILITY_MAGIC_BOUNCE && !(gWishFutureKnock.reflected) && gBattleMoves[gCurrentMove].flags & F_AFFECTED_BY_MAGIC_COAT)
	{
		gWishFutureKnock.reflected = 1;
		gWishFutureKnock.pranksterBoosted = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_MagicBounceBounce;
        return;
	}

    for (i = 0; i < gBattlersCount; i++)
    {
        if ((gProtectStructs[gBanksByTurnOrder[i]].stealMove) && gBattleMoves[gCurrentMove].flags & F_AFFECTED_BY_SNATCH)
        {
            PressurePPLose(gBankAttacker, gBanksByTurnOrder[i], MOVE_SNATCH);
            gProtectStructs[gBanksByTurnOrder[i]].stealMove = 0;
            gBattleStruct->scriptingActive = gBanksByTurnOrder[i];
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_SnatchedMove;
            return;
        }
    }
	
	if (gBattleMons[gBankAttacker].ability == ABILITY_INFILTRATOR)
	{
		gHitMarker |= HITMARKER_IGNORE_SUBSTITUTE;
	}

    if (gSpecialStatuses[gBankTarget].lightningRodRedirected)
    {
        gSpecialStatuses[gBankTarget].lightningRodRedirected = 0;
        gLastUsedAbility = gBattleMons[gBankTarget].ability;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_TookAttack;
        RecordAbilityBattle(gBankTarget, gLastUsedAbility);
    }
    else if (TARGET_PROTECT_AFFECTED
     && (gCurrentMove != MOVE_CURSE || (gBattleMons[gBankAttacker].type1 == TYPE_GHOST || gBattleMons[gBankAttacker].type2 == TYPE_GHOST))
     && ((!IsTwoTurnsMove(gCurrentMove) || (gBattleMons[gBankAttacker].status2 & STATUS2_MULTIPLETURNS))))
    {
        CancelMultiTurnMoves(gBankAttacker);
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gLastLandedMoves[gBankTarget] = 0;
        gLastHitByType[gBankTarget] = 0;
        gBattleCommunication[6] = 1;
        gBattlescriptCurrInstr++;
    }
    else
    {
        gBattlescriptCurrInstr++;
    }
}

static void JumpIfMoveFailed(u8 adder, u16 move)
{
    const u8 *BS_ptr = gBattlescriptCurrInstr + adder;
    if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
    {
        gLastLandedMoves[gBankTarget] = 0;
        gLastHitByType[gBankTarget] = 0;
        BS_ptr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        TrySetDestinyBondToHappen();
		if (gBattleMons[gBankAttacker].ability != ABILITY_MOLD_BREAKER)
			if (AbilityBattleEffects(ABILITYEFFECT_ABSORBING, gBankTarget, 0, 0, move))
				return;
    }
    gBattlescriptCurrInstr = BS_ptr;
}

static void atk40_jumpifaffectedbyprotect(void)
{
    if (TARGET_PROTECT_AFFECTED)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        JumpIfMoveFailed(5, 0);
        gBattleCommunication[6] = 1;
    }
    else
    {
        gBattlescriptCurrInstr += 5;
    }
}

static bool8 JumpIfMoveAffectedByProtect(u16 move)
{
    bool8 affected = FALSE;
    if (TARGET_PROTECT_AFFECTED)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        JumpIfMoveFailed(7, move);
        gBattleCommunication[6] = 1;
        affected = TRUE;
    }
    return affected;
}

static bool8 AccuracyCalcHelper(u16 move)
{
    if (gStatuses3[gBankTarget] & STATUS3_ALWAYS_HITS && gDisableStructs[gBankTarget].bankWithSureHit == gBankAttacker)
    {
        JumpIfMoveFailed(7, move);
        return TRUE;
    }
	
	if (gBattleMons[gBankAttacker].ability == ABILITY_NO_GUARD || gBattleMons[gBankTarget].ability == ABILITY_NO_GUARD)
	{
        JumpIfMoveFailed(7, move);
        return TRUE;
	}
	
	if (move == MOVE_TOXIC && (gBattleMons[gBankAttacker].type1 == TYPE_POISON || gBattleMons[gBankAttacker].type2 == TYPE_POISON))
	{
        JumpIfMoveFailed(7, move);
        return TRUE;
	}

    if (!(gHitMarker & HITMARKER_IGNORE_ON_AIR) && gStatuses3[gBankTarget] & STATUS3_ON_AIR)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    gHitMarker &= ~HITMARKER_IGNORE_ON_AIR;

    if (!(gHitMarker & HITMARKER_IGNORE_UNDERGROUND) && gStatuses3[gBankTarget] & STATUS3_UNDERGROUND)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    gHitMarker &= ~HITMARKER_IGNORE_UNDERGROUND;

    if (!(gHitMarker & HITMARKER_IGNORE_UNDERWATER) && gStatuses3[gBankTarget] & STATUS3_UNDERWATER)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    gHitMarker &= ~HITMARKER_IGNORE_UNDERWATER;
	
	if (gStatuses3[gBankTarget] & STATUS3_IN_SHADOWS)
	{
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        JumpIfMoveFailed(7, move);
        return TRUE;
	}

    if ((WEATHER_HAS_EFFECT && (gBattleWeather & WEATHER_RAIN_ANY) && (gBattleMoves[move].effect == EFFECT_THUNDER || gBattleMoves[move].effect == EFFECT_HURRICANE))
	 || (WEATHER_HAS_EFFECT && (gBattleWeather & WEATHER_HAIL) && (move == MOVE_BLIZZARD))
     || (gBattleMoves[move].accuracy == 0))
    {
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    return FALSE;
}

static void atk01_accuracycheck(void)
{
    u16 move = T2_READ_16(gBattlescriptCurrInstr + 5);

	if (gWishFutureKnock.pranksterBoosted && (gBattleMons[gBankTarget].type1 == TYPE_DARK || gBattleMons[gBankTarget].type2 == TYPE_DARK))
	{
		gMoveResultFlags |= MOVE_RESULT_DOESNT_AFFECT_FOE;
		gProtectStructs[gBankAttacker].notEffective = 1;
        JumpIfMoveFailed(7, move);
	}
	else if (gBattleMons[gBankTarget].ability == ABILITY_TELEPATHY && gBattleMoves[gCurrentMove].moveClass != CLASS_STATUS && GetBattlerSide(gBankAttacker) == GetBattlerSide(gBankTarget))
	{
		gMoveResultFlags |= MOVE_RESULT_MISSED;
		gProtectStructs[gBankAttacker].notEffective = 1;
        JumpIfMoveFailed(7, move);
	}
    else if (move == 0xFFFE || move == 0xFFFF)
    {
        if (gStatuses3[gBankTarget] & STATUS3_ALWAYS_HITS && move == 0xFFFF && gDisableStructs[gBankTarget].bankWithSureHit == gBankAttacker)
            gBattlescriptCurrInstr += 7;
        else if (gStatuses3[gBankTarget] & (STATUS3_ON_AIR | STATUS3_UNDERGROUND | STATUS3_UNDERWATER))
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
        else if (!JumpIfMoveAffectedByProtect(0))
            gBattlescriptCurrInstr += 7;
    }
    else
    {
        u8 type, moveAcc, holdEffect, quality, targetAbility, accMod, evaMod;
        s8 buff;
        u16 calc;

        if (move == 0)
            move = gCurrentMove;
		
		targetAbility = gBattleMons[gBankTarget].ability;
		if (gBattleMons[gBankAttacker].ability == ABILITY_MOLD_BREAKER)
			targetAbility = 0;

        GET_MOVE_TYPE(move, type);

        if (JumpIfMoveAffectedByProtect(move))
            return;
        if (AccuracyCalcHelper(move))
            return;
		
		accMod = gBattleMons[gBankAttacker].statStages[STAT_STAGE_ACC];
		evaMod = gBattleMons[gBankTarget].statStages[STAT_STAGE_EVASION];
		
		// Chip Away and attacker Unaware ignore all evasion changes.
		if (gCurrentMove == MOVE_CHIP_AWAY || gCurrentMove == MOVE_SACRED_SWORD || gBattleMons[gBankAttacker].ability == ABILITY_UNAWARE)
			evaMod = 6;
		
		// Foresight, Miracle Eye, and Keen Eye ignore positive evasion changes.
		if (evaMod > 6 && (gBattleMons[gBankTarget].status2 & STATUS2_FORESIGHT
		  || gStatuses3[gBankTarget] & STATUS3_MIRACLE_EYE
		  || gBattleMons[gBankAttacker].ability == ABILITY_KEEN_EYE))
		{
			evaMod = 6;
		}
		
		// Opposing Unaware makes us ignore all accuracy changes.
		if (targetAbility == ABILITY_UNAWARE)
			accMod = 6;
		
		buff = accMod + 6 - evaMod;

        if (buff < 0)
            buff = 0;
        if (buff > 0xC)
            buff = 0xC;

        moveAcc = gBattleMoves[move].accuracy;
        // check Thunder on sunny weather
        if (WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SUN_ANY && (gBattleMoves[move].effect == EFFECT_THUNDER || gBattleMoves[move].effect == EFFECT_HURRICANE))
            moveAcc = 50;
		
		if (gBattleMoves[move].moveClass == CLASS_STATUS && targetAbility == ABILITY_WONDER_SKIN)
			moveAcc = 50;

        calc = gAccuracyStageRatios[buff].dividend * moveAcc;
        calc /= gAccuracyStageRatios[buff].divisor;
		

        if (gBattleMons[gBankAttacker].ability == ABILITY_COMPOUND_EYES)
            calc = (calc * 130) / 100; // 1.3 compound eyes boost
        if (WEATHER_HAS_EFFECT && targetAbility == ABILITY_SAND_VEIL && gBattleWeather & WEATHER_SANDSTORM_ANY)
            calc = (calc * 80) / 100; // 0.8 sand veil loss;
        if (WEATHER_HAS_EFFECT && targetAbility == ABILITY_SNOW_CLOAK && gBattleWeather & WEATHER_HAIL)
            calc = (calc * 80) / 100; // 0.8 snow cloak loss
        if (gBattleMons[gBankAttacker].ability == ABILITY_HUSTLE && gBattleMoves[move].moveClass == CLASS_PHYSICAL)
            calc = (calc * 80) / 100; // 1.2 hustle loss;
		if (targetAbility == ABILITY_TANGLED_FEET && gBattleMons[gBankTarget].status2 & STATUS2_CONFUSION)
			calc = (calc * 50) / 100; // 0.5 tangled feet loss

        if (gBattleMons[gBankTarget].item == ITEM_ENIGMA_BERRY)
        {
            holdEffect = gEnigmaBerries[gBankTarget].holdEffect;
            quality = gEnigmaBerries[gBankTarget].holdEffectParam;
        }
        else
        {
            holdEffect = ItemId_GetHoldEffect(gBattleMons[gBankTarget].item);
            quality = ItemId_GetHoldEffectParam(gBattleMons[gBankTarget].item);
        }

        gStringBank = gBankTarget;

        if (holdEffect == HOLD_EFFECT_EVASION_UP)
            calc = (calc * (100 - quality)) / 100;

        // final calculation
        if ((Random() % 100 + 1) > calc)
        {
            gMoveResultFlags |= MOVE_RESULT_MISSED;
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE &&
                (gBattleMoves[move].target == 0x8 || gBattleMoves[move].target == 0x20))
                gBattleCommunication[6] = 2;
            else
                gBattleCommunication[6] = 0;
            CheckWonderGuardAndLevitate();
        }
        JumpIfMoveFailed(7, move);
    }
}

static void atk02_attackstring(void)
{
    if (gBattleExecBuffer)
         return;

	if (gBattleMons[gBankAttacker].ability == ABILITY_PROTEAN)
	{
		u8 moveType = gBattleMoves[gCurrentMove].type;
		if (gBattleStruct->dynamicMoveType & 0x3F)
			moveType = gBattleStruct->dynamicMoveType & 0x3F;
		
		if (gBattleMons[gBankAttacker].type1 != moveType || gBattleMons[gBankAttacker].type2 != moveType)
		{
			gBattleMons[gBankAttacker].type1 = moveType;
			gBattleMons[gBankAttacker].type2 = moveType;
			
			gBattleTextBuff1[0] = 0xFD;
			gBattleTextBuff1[1] = 3;
			gBattleTextBuff1[2] = moveType;
			gBattleTextBuff1[3] = 0xFF;
			
			BattleScriptPushCursor();
			gBattlescriptCurrInstr = BattleScript_Protean;
			return;
		}
	}

    if (!(gHitMarker & (HITMARKER_NO_ATTACKSTRING | HITMARKER_ATTACKSTRING_PRINTED)))
    {
        PrepareStringBattle(4, gBankAttacker);
        gHitMarker |= HITMARKER_ATTACKSTRING_PRINTED;
    }
	if (gCurrentMove != MOVE_COPYCAT)
		gBattleStruct->copycatTracker = gCurrentMove;

    gBattlescriptCurrInstr++;
    gBattleCommunication[MSG_DISPLAY] = 0;
}

static void atk03_ppreduce(void)
{
    s32 ppToDeduct = 1;

    if (gBattleExecBuffer)
        return;

    if (!gSpecialStatuses[gBankAttacker].flag20)
    {
        switch (gBattleMoves[gCurrentMove].target)
        {
        case TARGET_FOES_AND_ALLY:
            ppToDeduct += AbilityBattleEffects(ABILITYEFFECT_COUNT_ON_FIELD, gBankAttacker, ABILITY_PRESSURE, 0, 0);
            break;
        case TARGET_BOTH:
        case TARGET_OPPONENTS_FIELD:
            ppToDeduct += AbilityBattleEffects(ABILITYEFFECT_COUNT_OTHER_SIZE, gBankAttacker, ABILITY_PRESSURE, 0, 0);
            break;
        default:
            if (gBankAttacker != gBankTarget && gBattleMons[gBankTarget].ability == ABILITY_PRESSURE)
                ppToDeduct++;
            break;
        }
    }

    if (!(gHitMarker & (HITMARKER_NO_PPDEDUCT | HITMARKER_NO_ATTACKSTRING)) && gBattleMons[gBankAttacker].pp[gCurrMovePos])
    {
        gProtectStructs[gBankAttacker].notFirstStrike = 1;
		gBattleMons[gBankAttacker].usedMoves |= (0x1 << gCurrMovePos);

        if (gBattleMons[gBankAttacker].pp[gCurrMovePos] > ppToDeduct)
            gBattleMons[gBankAttacker].pp[gCurrMovePos] -= ppToDeduct;
        else
            gBattleMons[gBankAttacker].pp[gCurrMovePos] = 0;

        if (!(gBattleMons[gBankAttacker].status2 & STATUS2_TRANSFORMED)
            && !((gDisableStructs[gBankAttacker].unk18_b) & gBitTable[gCurrMovePos]))
        {
            gActiveBattler = gBankAttacker;
            EmitSetMonData(0, REQUEST_PPMOVE1_BATTLE + gCurrMovePos, 0, 1, &gBattleMons[gBankAttacker].pp[gCurrMovePos]);
            MarkBufferBankForExecution(gBankAttacker);
        }
    }

    gHitMarker &= ~(HITMARKER_NO_PPDEDUCT);
    gBattlescriptCurrInstr++;
}

static void atk04_critcalc(void)
{
    u8 holdEffect, targetAbility;
    u16 item, critChance;

    item = gBattleMons[gBankAttacker].item;
	
	targetAbility = gBattleMons[gBankTarget].ability;
	if (gBattleMons[gBankAttacker].ability == ABILITY_MOLD_BREAKER)
		targetAbility = 0;

    if (item == ITEM_ENIGMA_BERRY)
        holdEffect = gEnigmaBerries[gBankAttacker].holdEffect;
    else
        holdEffect = ItemId_GetHoldEffect(item);

    gStringBank = gBankAttacker;

    critChance = 0;
    
    if (gBattleMons[gBankAttacker].status2 & STATUS2_FOCUS_ENERGY)
        critChance += 2;
    if (gBattleMoves[gCurrentMove].flags & F_CRITTY)
        critChance++;
    if (gBattleMons[gBankAttacker].ability == ABILITY_SUPER_LUCK)
        critChance++;
    if (holdEffect == HOLD_EFFECT_SCOPE_LENS)
        critChance++;
    if (holdEffect == HOLD_EFFECT_LUCKY_PUNCH && gBattleMons[gBankAttacker].species == SPECIES_CHANSEY)
        critChance += 2;
    if (holdEffect == HOLD_EFFECT_STICK && gBattleMons[gBankAttacker].species == SPECIES_FARFETCHD)
        critChance += 2;
	
	if (gCurrentMove == MOVE_STORM_THROW || gCurrentMove == MOVE_FROST_BREATH)
		critChance = 4;

    if (gBattleMons[gBankAttacker].ability == ABILITY_MERCILESS && (gBattleMons[gBankTarget].status1 & (STATUS_POISON | STATUS_TOXIC_POISON)))
        critChance = 4;

    if (critChance > 4)
        critChance = 4;

    if ((targetAbility != ABILITY_BATTLE_ARMOR && targetAbility != ABILITY_SHELL_ARMOR)
     && !(gStatuses3[gBankAttacker] & STATUS3_CANT_SCORE_A_CRIT)
     && !(gBattleTypeFlags & (BATTLE_TYPE_WALLY_TUTORIAL | BATTLE_TYPE_FIRST_BATTLE))
	 && !(gSideTimers[GetBattlerSide(gBankTarget)].luckyChantTimer)
     && !(Random() % sCriticalHitChance[critChance]))
        gCritMultiplier = 2;
    else
        gCritMultiplier = 1;

    gBattlescriptCurrInstr++;
}

static void atk05_damagecalc(void)
{
    u16 side_hword = gSideAffecting[GetBattlerPosition(gBankTarget) & 1];
    gBattleMoveDamage = CalculateBaseDamage(&gBattleMons[gBankAttacker], &gBattleMons[gBankTarget], gCurrentMove,
                                            side_hword, gDynamicBasePower,
                                            gBattleStruct->dynamicMoveType, gBankAttacker, gBankTarget);
    gBattleMoveDamage = gBattleMoveDamage * gBattleStruct->dmgMultiplier;
	
	if (gCritMultiplier > 1)
	{
		gBattleMoveDamage += (gBattleMoveDamage / 2);
		if (gBattleMons[gBankAttacker].ability == ABILITY_SNIPER)
			gBattleMoveDamage += (gBattleMoveDamage / 2);
	}

    if (gStatuses3[gBankAttacker] & STATUS3_CHARGED_UP && gBattleMoves[gCurrentMove].type == TYPE_ELECTRIC)
        gBattleMoveDamage *= 2;
    if (gProtectStructs[gBankAttacker].helpingHand)
        gBattleMoveDamage = gBattleMoveDamage * 15 / 10;

    gBattlescriptCurrInstr++;
}

void AI_CalcDmg(u8 BankAtk, u8 BankDef)
{
    u16 side_hword = gSideAffecting[GetBattlerPosition(BankDef) & 1];
    gBattleMoveDamage = CalculateBaseDamage(&gBattleMons[BankAtk], &gBattleMons[BankDef], gCurrentMove,
                                            side_hword, gDynamicBasePower,
                                            gBattleStruct->dynamicMoveType, BankAtk, BankDef);
    gDynamicBasePower = 0;
    gBattleMoveDamage = gBattleMoveDamage * gBattleStruct->dmgMultiplier;

	if (gCritMultiplier > 1)
	{
		gBattleMoveDamage += (gBattleMoveDamage / 2);
		if (gBattleMons[BankAtk].ability == ABILITY_SNIPER)
			gBattleMoveDamage += (gBattleMoveDamage / 2);
	}
    if (gStatuses3[BankAtk] & STATUS3_CHARGED_UP && gBattleMoves[gCurrentMove].type == TYPE_ELECTRIC)
        gBattleMoveDamage *= 2;
    if (gProtectStructs[BankAtk].helpingHand)
        gBattleMoveDamage = gBattleMoveDamage * 15 / 10;
}

static void ModulateDmgByType(u8 multiplier)
{
    switch (multiplier)
    {
    case 0: //no effect
        gMoveResultFlags |= MOVE_RESULT_DOESNT_AFFECT_FOE;
        gMoveResultFlags &= ~MOVE_RESULT_NOT_VERY_EFFECTIVE;
        gMoveResultFlags &= ~MOVE_RESULT_SUPER_EFFECTIVE;
        break;
	case 1: // no effect unless foresight
		if (gBattleMons[gBankTarget].status2 & STATUS2_FORESIGHT || gBattleMons[gBankAttacker].ability == ABILITY_SCRAPPY)
		{
			multiplier = 10;
			break;
		}
        gMoveResultFlags |= MOVE_RESULT_DOESNT_AFFECT_FOE;
        gMoveResultFlags &= ~MOVE_RESULT_NOT_VERY_EFFECTIVE;
        gMoveResultFlags &= ~MOVE_RESULT_SUPER_EFFECTIVE;
		multiplier = 0;
        break;
	case 2: // no effect unless miracle eye
		if (gStatuses3[gBankTarget] & STATUS3_MIRACLE_EYE)
		{
			multiplier = 10;
			break;
		}
        gMoveResultFlags |= MOVE_RESULT_DOESNT_AFFECT_FOE;
        gMoveResultFlags &= ~MOVE_RESULT_NOT_VERY_EFFECTIVE;
        gMoveResultFlags &= ~MOVE_RESULT_SUPER_EFFECTIVE;
		multiplier = 0;
        break;
    case 5: //not very effecting
        if (gBattleMoves[gCurrentMove].power && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
        {
            if (gMoveResultFlags & MOVE_RESULT_SUPER_EFFECTIVE)
                gMoveResultFlags &= ~MOVE_RESULT_SUPER_EFFECTIVE;
            else
                gMoveResultFlags |= MOVE_RESULT_NOT_VERY_EFFECTIVE;
        }
        break;
    case 20: //super effective
        if (gBattleMoves[gCurrentMove].power && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
        {
            if (gMoveResultFlags & MOVE_RESULT_NOT_VERY_EFFECTIVE)
                gMoveResultFlags &= ~MOVE_RESULT_NOT_VERY_EFFECTIVE;
            else
                gMoveResultFlags |= MOVE_RESULT_SUPER_EFFECTIVE;
        }
        break;
    }
    gBattleMoveDamage = gBattleMoveDamage * multiplier / 10;
    if (gBattleMoveDamage == 0 && multiplier != 0)
        gBattleMoveDamage = 1;

}

static void atk06_typecalc(void)
{
    u8 move_type, defenderAbility;
    u16 def_item;
	
	defenderAbility = gBattleMons[gBankTarget].ability;
	if (gBattleMons[gBankAttacker].ability == ABILITY_MOLD_BREAKER)
		defenderAbility = 0;
	
	if (gCurrentMove == MOVE_SYNCHRONOISE)
	{
		if (!(gBattleMons[gBankAttacker].type1 == gBattleMons[gBankTarget].type1
		   || gBattleMons[gBankAttacker].type1 == gBattleMons[gBankTarget].type2
		   || gBattleMons[gBankAttacker].type2 == gBattleMons[gBankTarget].type1
		   || gBattleMons[gBankAttacker].type2 == gBattleMons[gBankTarget].type2))
		{
			gBattleMoveDamage = 0;
			gMoveResultFlags |= MOVE_RESULT_DOESNT_AFFECT_FOE;
            gProtectStructs[gBankAttacker].notEffective = 1;
			gBattlescriptCurrInstr++;
			return;
		}
	}
    if (gCurrentMove != MOVE_STRUGGLE)
    {
        if (gBattleStruct->dynamicMoveType)
            move_type = gBattleStruct->dynamicMoveType & 0x3F;
        else
            move_type = gBattleMoves[gCurrentMove].type;

        if (gBattleMons[gBankAttacker].ability == ABILITY_PIXILATE && move_type == TYPE_NORMAL)
            move_type = TYPE_FAIRY;

        //check stab
        if (gBattleMons[gBankAttacker].type1 == move_type || gBattleMons[gBankAttacker].type2 == move_type)
        {
			if (gBattleMons[gBankAttacker].ability == ABILITY_ADAPTABILITY)
				gBattleMoveDamage = gBattleMoveDamage * 20;
			else
				gBattleMoveDamage = gBattleMoveDamage * 15;
            gBattleMoveDamage = gBattleMoveDamage / 10;
        }

        if (defenderAbility == ABILITY_LEVITATE && move_type == TYPE_GROUND)
        {
            gLastUsedAbility = gBattleMons[gBankTarget].ability;
            gMoveResultFlags |= (MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE);
            gLastLandedMoves[gBankTarget] = 0;
            gLastHitByType[gBankTarget] = 0;
            gBattleCommunication[6] = move_type;
            RecordAbilityBattle(gBankTarget, gLastUsedAbility);
        }
		else if (gCurrentMove == MOVE_FREEZE_DRY)
		{
			if (gBattleMons[gBankTarget].type1 == TYPE_WATER)
				ModulateDmgByType(20);
			else
				ModulateDmgByType(gTypeEffectiveness[move_type * 20 + gBattleMons[gBankTarget].type1]);
			if (gBattleMons[gBankTarget].type1 != gBattleMons[gBankTarget].type2)
			{
				if (gBattleMons[gBankTarget].type2 == TYPE_WATER)
					ModulateDmgByType(20);
				else
					ModulateDmgByType(gTypeEffectiveness[move_type * 20 + gBattleMons[gBankTarget].type2]);
			}
		}
        else
        {
			ModulateDmgByType(gTypeEffectiveness[move_type * 20 + gBattleMons[gBankTarget].type1]);
			if (gBattleMons[gBankTarget].type1 != gBattleMons[gBankTarget].type2)
				ModulateDmgByType(gTypeEffectiveness[move_type * 20 + gBattleMons[gBankTarget].type2]);
        }

        if (defenderAbility == ABILITY_WONDER_GUARD && AttacksThisTurn(gBankAttacker, gCurrentMove) == 2
         && (!(gMoveResultFlags & MOVE_RESULT_SUPER_EFFECTIVE) || ((gMoveResultFlags & (MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE)) == (MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE)))
         && gBattleMoves[gCurrentMove].power)
        {
            gLastUsedAbility = ABILITY_WONDER_GUARD;
            gMoveResultFlags |= MOVE_RESULT_MISSED;
            gLastLandedMoves[gBankTarget] = 0;
            gLastHitByType[gBankTarget] = 0;
            gBattleCommunication[6] = 3;
            RecordAbilityBattle(gBankTarget, gLastUsedAbility);
        }
        if (gMoveResultFlags & MOVE_RESULT_DOESNT_AFFECT_FOE)
            gProtectStructs[gBankAttacker].notEffective = 1;
		
		if (gMoveResultFlags & MOVE_RESULT_NOT_VERY_EFFECTIVE && gBattleMons[gBankAttacker].ability == ABILITY_TINTED_LENS)
			gBattleMoveDamage *= 2;
		
		if (gMoveResultFlags & MOVE_RESULT_SUPER_EFFECTIVE && (gBattleMons[gBankTarget].ability == ABILITY_SOLID_ROCK || gBattleMons[gBankTarget].ability == ABILITY_FILTER))
			gBattleMoveDamage = gBattleMoveDamage * 3 / 4;

        // Resist berries.
        // This is a bit of hack, but we assume the Natural Gift type == resisted type.
        // This is true for all canon resist berries.
        // Also we're ignoring enigma berries because lol.
        def_item = gBattleMons[gBankTarget].item;
        if (((gMoveResultFlags & MOVE_RESULT_SUPER_EFFECTIVE) || move_type == TYPE_NORMAL) &&
            ItemId_GetHoldEffect(def_item) == HOLD_EFFECT_RESIST_BERRY &&
            ItemId_GetNatGiftType(def_item) == move_type &&
            gBattleMoveDamage > 0 &&
            (!(gBattleMons[gBankTarget].status2 & STATUS2_SUBSTITUTE) || gHitMarker & HITMARKER_IGNORE_SUBSTITUTE) &&
            !AbilityBattleEffects(ABILITYEFFECT_CHECK_OTHER_SIDE, gBankTarget, ABILITY_UNNERVE, 0, 0))
        {
            gBattleMoveDamage /= 2;
            gWishFutureKnock.berryEatenPokes[GetBattlerSide(gBankTarget)] |= gBitTable[gBattlerPartyIndexes[gBankTarget]];
            
            gBattlescriptCurrInstr++;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_UseResistBerry;
			gLastUsedItem = gBattleMons[gBankTarget].item;
        }
        else
        {
            gBattlescriptCurrInstr++;
        }
    }
    else
    {
        gBattlescriptCurrInstr++;
    }
}
static void CheckWonderGuardAndLevitate(void)
{
    u8 flags = 0;
    u8 typemu = 0;
    u8 move_type;

    if (gCurrentMove == MOVE_STRUGGLE || !gBattleMoves[gCurrentMove].power)
        return;
	if (gBattleMons[gBankAttacker].ability == ABILITY_MOLD_BREAKER)
		return;

    if (gBattleStruct->dynamicMoveType)
        move_type = gBattleStruct->dynamicMoveType & 0x3F;
    else
        move_type = gBattleMoves[gCurrentMove].type;

    if (gBattleMons[gBankTarget].ability == ABILITY_LEVITATE && move_type == TYPE_GROUND)
    {
        RecordAbilitySetField6(ABILITY_LEVITATE, move_type);
        return;
    }
	
	typemu = gTypeEffectiveness[move_type * 20  + gBattleMons[gBankTarget].type1];
	if (typemu == 1 && !(gBattleMons[gBankTarget].status2 & STATUS2_FORESIGHT || gBattleMons[gBankAttacker].ability == ABILITY_SCRAPPY))
		typemu = 0;
	else if (typemu == 2 && !(gStatuses3[gBankTarget] & STATUS3_MIRACLE_EYE))
		typemu = 0;
	if (gCurrentMove == MOVE_FREEZE_DRY && gBattleMons[gBankTarget].type1 == TYPE_WATER)
		typemu = 20;
	if (typemu == 0)
	{
		gMoveResultFlags |= MOVE_RESULT_DOESNT_AFFECT_FOE;
		gProtectStructs[gBankAttacker].notEffective = 1;
	}
	else if (typemu == 5)
		flags |= 2;
	else if (typemu == 20)
		flags |= 1;
	
	typemu = gTypeEffectiveness[move_type * 20  + gBattleMons[gBankTarget].type2];
	if (typemu == 1 && !(gBattleMons[gBankTarget].status2 & STATUS2_FORESIGHT || gBattleMons[gBankAttacker].ability == ABILITY_SCRAPPY))
		typemu = 0;
	else if (typemu == 2 && !(gStatuses3[gBankTarget] & STATUS3_MIRACLE_EYE))
		typemu = 0;
	if (gCurrentMove == MOVE_FREEZE_DRY && gBattleMons[gBankTarget].type2 == TYPE_WATER)
		typemu = 20;
	if (typemu == 0)
	{
		gMoveResultFlags |= MOVE_RESULT_DOESNT_AFFECT_FOE;
		gProtectStructs[gBankAttacker].notEffective = 1;
	}
	else if (typemu == 5)
		flags |= 2;
	else if (typemu == 20)
		flags |= 1;

    if (gBattleMons[gBankTarget].ability == ABILITY_WONDER_GUARD && AttacksThisTurn(gBankAttacker, gCurrentMove) == 2)
    {
        if (((flags & 2) || !(flags & 1)) && gBattleMoves[gCurrentMove].power)
        {
            RecordAbilitySetField6(ABILITY_WONDER_GUARD, 3);
        }
    }
}

static void ModulateDmgByType2(u8 multiplier, u16 move, u8* flags) //a literal copy of the ModulateDmgbyType1 with different args...
{
    switch (multiplier)
    {
    case 0: //no effect
        *flags |= MOVE_RESULT_DOESNT_AFFECT_FOE;
        *flags &= ~MOVE_RESULT_NOT_VERY_EFFECTIVE;
        *flags &= ~MOVE_RESULT_SUPER_EFFECTIVE;
        break;
	case 1: //no effect unless foresight on target
		if (gBattleMons[gBankTarget].status2 & STATUS2_FORESIGHT || gBattleMons[gBankAttacker].ability == ABILITY_SCRAPPY)
		{
			multiplier = 10;
			break;
		}
        *flags |= MOVE_RESULT_DOESNT_AFFECT_FOE;
        *flags &= ~MOVE_RESULT_NOT_VERY_EFFECTIVE;
        *flags &= ~MOVE_RESULT_SUPER_EFFECTIVE;
		multiplier = 0;
        break;
	case 2: //no effect unless miracle eye on target
		if (gStatuses3[gBankTarget] & STATUS3_MIRACLE_EYE)
		{
			multiplier = 10;
			break;
		}
        *flags |= MOVE_RESULT_DOESNT_AFFECT_FOE;
        *flags &= ~MOVE_RESULT_NOT_VERY_EFFECTIVE;
        *flags &= ~MOVE_RESULT_SUPER_EFFECTIVE;
		multiplier = 0;
        break;
    case 5: //not very effecting
        if (gBattleMoves[move].power && !(*flags & MOVE_RESULT_NO_EFFECT))
        {
            if (*flags & MOVE_RESULT_SUPER_EFFECTIVE)
                *flags &= ~MOVE_RESULT_SUPER_EFFECTIVE;
            else
                *flags |= MOVE_RESULT_NOT_VERY_EFFECTIVE;
        }
        break;
    case 20: //super effective
        if (gBattleMoves[move].power && !(*flags & MOVE_RESULT_NO_EFFECT))
        {
            if (*flags & MOVE_RESULT_NOT_VERY_EFFECTIVE)
                *flags &= ~MOVE_RESULT_NOT_VERY_EFFECTIVE;
            else
                *flags |= MOVE_RESULT_SUPER_EFFECTIVE;
        }
        break;
    }
	
    gBattleMoveDamage = gBattleMoveDamage * multiplier / 10;
    if (gBattleMoveDamage == 0 && multiplier != 0)
        gBattleMoveDamage = 1;
}

u8 TypeCalc(u16 move, u8 bank_atk, u8 bank_def)
{
    u8 flags = 0;
    u8 move_type;
	u8 defenderAbility;

    if (move == MOVE_STRUGGLE)
        return 0;

    move_type = gBattleMoves[move].type;

    if (gBattleMons[bank_atk].ability == ABILITY_PIXILATE && move_type == TYPE_NORMAL)
        move_type = TYPE_FAIRY;

    //check stab
    if (gBattleMons[bank_atk].type1 == move_type || gBattleMons[bank_atk].type2 == move_type)
    {
		if (gBattleMons[bank_atk].ability == ABILITY_ADAPTABILITY)
			gBattleMoveDamage = gBattleMoveDamage * 20;
		else
			gBattleMoveDamage = gBattleMoveDamage * 15;
        gBattleMoveDamage = gBattleMoveDamage / 10;
    }
	
	defenderAbility = gBattleMons[bank_def].ability;
	if (gBattleMons[bank_atk].ability == ABILITY_MOLD_BREAKER)
		defenderAbility = 0;

    if (defenderAbility == ABILITY_LEVITATE && move_type == TYPE_GROUND)
    {
        flags |= (MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE);
    }
    else
    {
		if (move == MOVE_FREEZE_DRY && gBattleMons[bank_def].type1 == TYPE_WATER)
			ModulateDmgByType2(20, move, &flags);
		else
			ModulateDmgByType2(gTypeEffectiveness[move_type * 20 + gBattleMons[bank_def].type1], move, &flags);
		if (gBattleMons[bank_def].type1 != gBattleMons[bank_def].type2)
		{
			if (move == MOVE_FREEZE_DRY && gBattleMons[bank_def].type2 == TYPE_WATER)
				ModulateDmgByType2(20, move, &flags);
			else
				ModulateDmgByType2(gTypeEffectiveness[move_type * 20 + gBattleMons[bank_def].type2], move, &flags);
		}
    }

    if (defenderAbility == ABILITY_WONDER_GUARD && !(flags & MOVE_RESULT_MISSED) &&
        AttacksThisTurn(bank_atk, move) == 2 &&
        (!(flags & MOVE_RESULT_SUPER_EFFECTIVE) || ((flags & (MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE)) == (MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE))) &&
        gBattleMoves[move].power)
    {
        flags |= MOVE_RESULT_MISSED;
    }
	
	if (flags & MOVE_RESULT_NOT_VERY_EFFECTIVE && gBattleMons[bank_atk].ability == ABILITY_TINTED_LENS)
		gBattleMoveDamage *= 2;
	
	if (flags & MOVE_RESULT_SUPER_EFFECTIVE && (defenderAbility == ABILITY_SOLID_ROCK || defenderAbility == ABILITY_FILTER))
		gBattleMoveDamage = gBattleMoveDamage * 3 / 4;
	
    return flags;
}

u8 AI_TypeCalc(u16 move, u16 species, u8 ability)
{
    u8 flags = 0;
    u8 type1 = gBaseStats[species].type1, type2 = gBaseStats[species].type2, move_type;

    if (move == MOVE_STRUGGLE)
        return 0;

    move_type = gBattleMoves[move].type;

    if (ability == ABILITY_LEVITATE && move_type == TYPE_GROUND)
        flags = MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE;
    else
    {
		if (move == MOVE_FREEZE_DRY && type1 == TYPE_WATER)
			ModulateDmgByType2(20, move, &flags);
		else
			ModulateDmgByType2(gTypeEffectiveness[move_type * 20 + type1], move, &flags);
		if (type1 != type2)
		{
		if (move == MOVE_FREEZE_DRY && type2 == TYPE_WATER)
			ModulateDmgByType2(20, move, &flags);
		else
			ModulateDmgByType2(gTypeEffectiveness[move_type * 20 + type2], move, &flags);
		}
    }
    if (ability == ABILITY_WONDER_GUARD
     && (!(flags & MOVE_RESULT_SUPER_EFFECTIVE) || ((flags & (MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE)) == (MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE)))
     && gBattleMoves[move].power)
        flags |= MOVE_RESULT_DOESNT_AFFECT_FOE;
    return flags;
}

// Multiplies the damage by a random factor between 85% to 100% inclusive
static inline void ApplyRandomDmgMultiplier(void)
{
    u16 rand = Random();
    u16 randPercent = 100 - (rand % 16);

    if (gBattleMoveDamage != 0)
    {
        gBattleMoveDamage *= randPercent;
        gBattleMoveDamage /= 100;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
    }
}

void Unused_ApplyRandomDmgMultiplier(void)
{
    ApplyRandomDmgMultiplier();
}

static void atk07_adjustnormaldamage(void)
{
    u8 hold_effect, quality;
    ApplyRandomDmgMultiplier();
    if (gBattleMons[gBankTarget].item == ITEM_ENIGMA_BERRY)
    {
        hold_effect = gEnigmaBerries[gBankTarget].holdEffect, quality = gEnigmaBerries[gBankTarget].holdEffectParam;
    }
    else
    {
        hold_effect = ItemId_GetHoldEffect(gBattleMons[gBankTarget].item);
        quality = ItemId_GetHoldEffectParam(gBattleMons[gBankTarget].item);
    }

    gStringBank = gBankTarget;

    if (hold_effect == HOLD_EFFECT_FOCUS_BAND && (Random() % 100) < quality)
    {
        RecordItemBattle(gBankTarget, hold_effect);
        gSpecialStatuses[gBankTarget].focusBanded = 1;
    }
    if (!(gBattleMons[gBankTarget].status2 & STATUS2_SUBSTITUTE) && gBattleMons[gBankTarget].hp <= gBattleMoveDamage)
    {
		if (gBattleMoves[gCurrentMove].effect == EFFECT_FALSE_SWIPE)
		{
			gBattleMoveDamage = gBattleMons[gBankTarget].hp - 1;
		}
		else if (gProtectStructs[gBankTarget].endured)
		{
			gBattleMoveDamage = gBattleMons[gBankTarget].hp - 1;
			gMoveResultFlags |= MOVE_RESULT_FOE_ENDURED;
		}
		else if (gBattleMons[gBankTarget].ability == ABILITY_STURDY && gBattleMons[gBankTarget].hp == gBattleMons[gBankTarget].maxHP &&
		         gBattleMons[gBankAttacker].ability != ABILITY_MOLD_BREAKER)
		{
			gBattleMoveDamage = gBattleMons[gBankTarget].hp - 1;
			gMoveResultFlags |= MOVE_RESULT_STURDY;
		}
        else if (hold_effect == HOLD_EFFECT_FOCUS_SASH && gBattleMons[gBankTarget].hp == gBattleMons[gBankTarget].maxHP)
        {
			gBattleMoveDamage = gBattleMons[gBankTarget].hp - 1;
			gMoveResultFlags |= MOVE_RESULT_FOE_HUNG_ON;
			gLastUsedItem = gBattleMons[gBankTarget].item;
        }
		else if (gSpecialStatuses[gBankTarget].focusBanded)
		{
			gBattleMoveDamage = gBattleMons[gBankTarget].hp - 1;
			gMoveResultFlags |= MOVE_RESULT_FOE_HUNG_ON;
			gLastUsedItem = gBattleMons[gBankTarget].item;
		}
	}
    
	gBattlescriptCurrInstr++;
}

static void atk08_adjustnormaldamage2(void) //literally the same as 0x7 except it doesn't check for false swipe move effect...
{
    u8 hold_effect, quality;
    ApplyRandomDmgMultiplier();
    if (gBattleMons[gBankTarget].item == ITEM_ENIGMA_BERRY)
    {
        hold_effect = gEnigmaBerries[gBankTarget].holdEffect, quality = gEnigmaBerries[gBankTarget].holdEffectParam;
    }
    else
    {
        hold_effect = ItemId_GetHoldEffect(gBattleMons[gBankTarget].item);
        quality = ItemId_GetHoldEffectParam(gBattleMons[gBankTarget].item);
    }

    gStringBank = gBankTarget;

    if (hold_effect == HOLD_EFFECT_FOCUS_BAND && (Random() % 100) < quality)
    {
        RecordItemBattle(gBankTarget, hold_effect);
        gSpecialStatuses[gBankTarget].focusBanded = 1;
    }
    if (gBattleMons[gBankTarget].status2 & STATUS2_SUBSTITUTE)
        goto END;
    if (!gProtectStructs[gBankTarget].endured
     && !gSpecialStatuses[gBankTarget].focusBanded)
        goto END;

    if (gBattleMons[gBankTarget].hp > gBattleMoveDamage)
        goto END;

    gBattleMoveDamage = gBattleMons[gBankTarget].hp - 1;

    if (gProtectStructs[gBankTarget].endured)
    {
        gMoveResultFlags |= MOVE_RESULT_FOE_ENDURED;
        goto END;
    }
    if (gSpecialStatuses[gBankTarget].focusBanded)
    {
        gMoveResultFlags |= MOVE_RESULT_FOE_HUNG_ON;
        gLastUsedItem = gBattleMons[gBankTarget].item;
    }

    END:
        gBattlescriptCurrInstr++;
}

static void atk09_attackanimation(void)
{
    if (gBattleExecBuffer)
        return;

    if ((gHitMarker & HITMARKER_NO_ANIMATIONS) && (gCurrentMove != MOVE_TRANSFORM && gCurrentMove != MOVE_SUBSTITUTE))
    {
        BattleScriptPush(gBattlescriptCurrInstr + 1);
        gBattlescriptCurrInstr = BattleScript_Pausex20;
        gBattleStruct->animTurn += 1;
        gBattleStruct->animTargetsHit += 1;
    }
    else
    {
        if ((gBattleMoves[gCurrentMove].target & TARGET_BOTH || gBattleMoves[gCurrentMove].target & TARGET_FOES_AND_ALLY || gBattleMoves[gCurrentMove].target & TARGET_DEPENDS) && gBattleStruct->animTargetsHit)
        {
            gBattlescriptCurrInstr++;
            return;
        }
        if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
        {
            gActiveBattler = gBankAttacker;

            EmitMoveAnimation(0, gCurrentMove, gBattleStruct->animTurn, gBattleMovePower, gBattleMoveDamage, gBattleMons[gBankAttacker].friendship, &gDisableStructs[gBankAttacker]);
            gBattleStruct->animTurn += 1;
            gBattleStruct->animTargetsHit += 1;
            MarkBufferBankForExecution(gBankAttacker);
            gBattlescriptCurrInstr++;
        }
        else
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_Pausex20;
        }
    }
}

static void atk0A_waitanimation(void)
{
    if (gBattleExecBuffer == 0)
        gBattlescriptCurrInstr++;
}

static void atk0B_healthbarupdate(void)
{
    if (gBattleExecBuffer)
        return;

    if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
    {
        gActiveBattler = GetBattleBank(gBattlescriptCurrInstr[1]);

        if (gBattleMons[gActiveBattler].status2 & STATUS2_SUBSTITUTE && gDisableStructs[gActiveBattler].substituteHP && !(gHitMarker & HITMARKER_IGNORE_SUBSTITUTE))
        {
            PrepareStringBattle(0x80, gActiveBattler);
        }
        else
        {
            // Emerald
            /*
            s16 healthValue;

            s32 currDmg = gBattleMoveDamage;
            s32 maxPossibleDmgValue = 10000; // not present in R/S, ensures that huge damage values don't change sign

            if (currDmg <= maxPossibleDmgValue)
                healthValue = currDmg;
            else
                healthValue = maxPossibleDmgValue;

            EmitHealthBarUpdate(0, healthValue);
            */

            EmitHealthBarUpdate(0, gBattleMoveDamage);
            MarkBufferBankForExecution(gActiveBattler);

            if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER && gBattleMoveDamage > 0)
                gBattleResults.unk5_0 = 1;
        }
    }

    gBattlescriptCurrInstr += 2;
}

static void atk0C_datahpupdate(void)
{
    u32 moveType;
	u8 moveClass;

    if (gBattleExecBuffer)
        return;

    if (gBattleStruct->dynamicMoveType == 0)
        moveType = gBattleMoves[gCurrentMove].type;
    else if (!(gBattleStruct->dynamicMoveType & 0x40))
        moveType = gBattleStruct->dynamicMoveType & 0x3F;
    else
        moveType = gBattleMoves[gCurrentMove].type;
	moveClass = gBattleMoves[gCurrentMove].moveClass;

    if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
    {
        gActiveBattler = GetBattleBank(gBattlescriptCurrInstr[1]);
        
        if (gBattleMons[gActiveBattler].status2 & STATUS2_SUBSTITUTE && gDisableStructs[gActiveBattler].substituteHP && !(gHitMarker & HITMARKER_IGNORE_SUBSTITUTE))
        {
            gProtectStructs[gBankAttacker].dealtDmg = 1;
            if (gDisableStructs[gActiveBattler].substituteHP >= gBattleMoveDamage)
            {
                if (gSpecialStatuses[gActiveBattler].moveturnLostHP == 0)
                    gSpecialStatuses[gActiveBattler].moveturnLostHP = gBattleMoveDamage;
                gDisableStructs[gActiveBattler].substituteHP -= gBattleMoveDamage;
                gHpDealt = gBattleMoveDamage;
            }
            else
            {
                if (gSpecialStatuses[gActiveBattler].moveturnLostHP == 0)
                    gSpecialStatuses[gActiveBattler].moveturnLostHP = gDisableStructs[gActiveBattler].substituteHP;
                gHpDealt = gDisableStructs[gActiveBattler].substituteHP;
                gDisableStructs[gActiveBattler].substituteHP = 0;
            }
            // check substitute fading
            if (gDisableStructs[gActiveBattler].substituteHP == 0)
            {
                gBattlescriptCurrInstr += 2;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_SubstituteFade;
                return;
            }
        }
        else
        {
            gHitMarker &= ~(HITMARKER_IGNORE_SUBSTITUTE);
            if (gBattleMoveDamage < 0) // hp goes up
            {
                gBattleMons[gActiveBattler].hp -= gBattleMoveDamage;
                if (gBattleMons[gActiveBattler].hp > gBattleMons[gActiveBattler].maxHP)
                    gBattleMons[gActiveBattler].hp = gBattleMons[gActiveBattler].maxHP;

            }
            else // hp goes down
            {
                if (gHitMarker & HITMARKER_x20)
                {
                    gHitMarker &= ~(HITMARKER_x20);
                }
                else
                {
                    gTakenDmg[gActiveBattler] += gBattleMoveDamage;
                    if (gBattlescriptCurrInstr[1] == BS_GET_TARGET)
                        gTakenDmgBanks[gActiveBattler] = gBankAttacker;
                    else
                        gTakenDmgBanks[gActiveBattler] = gBankTarget;
                }

                if (gBattleMons[gActiveBattler].hp > gBattleMoveDamage)
                {
                    gBattleMons[gActiveBattler].hp -= gBattleMoveDamage;
                    gHpDealt = gBattleMoveDamage;
                }
                else
                {
                    gHpDealt = gBattleMons[gActiveBattler].hp;
                    gBattleMons[gActiveBattler].hp = 0;
                }

                if (!gSpecialStatuses[gActiveBattler].moveturnLostHP && !(gHitMarker & HITMARKER_x100000))
                    gSpecialStatuses[gActiveBattler].moveturnLostHP = gHpDealt;

                if (moveClass == 0 && !(gHitMarker & HITMARKER_x100000) && gCurrentMove != MOVE_PAIN_SPLIT)
                {
                    gProtectStructs[gActiveBattler].physicalDmg = gHpDealt;
                    gSpecialStatuses[gActiveBattler].moveturnLostHP_physical = gHpDealt;
                    if (gBattlescriptCurrInstr[1] == BS_GET_TARGET)
                    {
                        gProtectStructs[gActiveBattler].classLastHit = CLASS_PHYSICAL;
                        gProtectStructs[gActiveBattler].physicalBank = gBankAttacker;
                        gSpecialStatuses[gActiveBattler].moveturnPhysicalBank = gBankAttacker;
                        gProtectStructs[gBankAttacker].dealtDmg = 1;
                    }
                    else
                    {
                        gProtectStructs[gActiveBattler].classLastHit = CLASS_PHYSICAL;
                        gProtectStructs[gActiveBattler].physicalBank = gBankTarget;
                        gSpecialStatuses[gActiveBattler].moveturnPhysicalBank = gBankTarget;
                    }
                }
                else if (moveClass == 1 && !(gHitMarker & HITMARKER_x100000))
                {
                    gProtectStructs[gActiveBattler].specialDmg = gHpDealt;
                    gSpecialStatuses[gActiveBattler].moveturnLostHP_special = gHpDealt;
                    if (gBattlescriptCurrInstr[1] == BS_GET_TARGET)
                    {
                        gProtectStructs[gActiveBattler].classLastHit = CLASS_SPECIAL;
                        gProtectStructs[gActiveBattler].specialBank = gBankAttacker;
                        gSpecialStatuses[gActiveBattler].moveturnSpecialBank = gBankAttacker;
                        gProtectStructs[gBankAttacker].dealtDmg = 1;
                    }
                    else
                    {
                        gProtectStructs[gActiveBattler].classLastHit = CLASS_SPECIAL;
                        gProtectStructs[gActiveBattler].specialBank = gBankTarget;
                        gSpecialStatuses[gActiveBattler].moveturnSpecialBank = gBankTarget;
                    }
                }
            }
            gHitMarker &= ~(HITMARKER_x100000);
            EmitSetMonData(0, REQUEST_HP_BATTLE, 0, 2, &gBattleMons[gActiveBattler].hp);
            MarkBufferBankForExecution(gActiveBattler);
        }
    }
    else
    {
        gActiveBattler = GetBattleBank(gBattlescriptCurrInstr[1]);
        if (gSpecialStatuses[gActiveBattler].moveturnLostHP == 0)
            gSpecialStatuses[gActiveBattler].moveturnLostHP = 0xFFFF;
    }
    gBattlescriptCurrInstr += 2;
}

static void atk0D_critmessage(void)
{
    if (gBattleExecBuffer == 0)
    {
        if (gCritMultiplier == 2 && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
        {
            PrepareStringBattle(0xD9, gBankAttacker);
            gBattleCommunication[MSG_DISPLAY] = 1;
        }
        gBattlescriptCurrInstr++;
    }
}

static void atk0E_effectivenesssound(void)
{
    if (gBattleExecBuffer)
        return;

    gActiveBattler = gBankTarget;
    if (!(gMoveResultFlags & MOVE_RESULT_MISSED))
    {
        u8 flag = ~MOVE_RESULT_MISSED;
        switch (gMoveResultFlags & flag)
        {
        case MOVE_RESULT_SUPER_EFFECTIVE:
            EmitEffectivenessSound(0, 14);
            MarkBufferBankForExecution(gActiveBattler);
            break;
        case MOVE_RESULT_NOT_VERY_EFFECTIVE:
            EmitEffectivenessSound(0, 12);
            MarkBufferBankForExecution(gActiveBattler);
            break;
        case MOVE_RESULT_DOESNT_AFFECT_FOE:
        case MOVE_RESULT_FAILED:
            break;
        case MOVE_RESULT_FOE_ENDURED:
        case MOVE_RESULT_ONE_HIT_KO:
        case MOVE_RESULT_FOE_HUNG_ON:
        default:
            if (gMoveResultFlags & MOVE_RESULT_SUPER_EFFECTIVE)
            {
                EmitEffectivenessSound(0, 14);
                MarkBufferBankForExecution(gActiveBattler);
            }
            else if (gMoveResultFlags & MOVE_RESULT_NOT_VERY_EFFECTIVE)
            {
                EmitEffectivenessSound(0, 12);
                MarkBufferBankForExecution(gActiveBattler);
            }
            else if (!(gMoveResultFlags & (MOVE_RESULT_DOESNT_AFFECT_FOE | MOVE_RESULT_FAILED)))
            {
                EmitEffectivenessSound(0, 13);
                MarkBufferBankForExecution(gActiveBattler);
            }
            break;
        }
    }
    gBattlescriptCurrInstr++;
}

static void atk0F_resultmessage(void)
{
    u32 stringId = 0;

    if (gBattleExecBuffer)
        return;

    if (gMoveResultFlags & MOVE_RESULT_MISSED && (!(gMoveResultFlags & MOVE_RESULT_DOESNT_AFFECT_FOE) || gBattleCommunication[6] > 2))
    {
        stringId = gMissStringIds[gBattleCommunication[6]];
        gBattleCommunication[MSG_DISPLAY] = 1;
		
		if (gProtectStructs[gBankTarget].spikyShield && gBattleMoves[gCurrentMove].flags & F_MAKES_CONTACT && gBattleCommunication[6] == 1)
		{
			//mess 'em up
			gBattleMoveDamage = gBattleMons[gBankAttacker].hp / 8;
			if (gBattleMoveDamage < 1)
				gBattleMoveDamage = 1;
			gBattlescriptCurrInstr++;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_SpikyShieldRecoil;
			return;
		}
    }
    else
    {
        gBattleCommunication[MSG_DISPLAY] = 1;
        switch (gMoveResultFlags & ~(MOVE_RESULT_MISSED))
        {
        case MOVE_RESULT_SUPER_EFFECTIVE:
            stringId = STRINGID_SUPEREFFECTIVE;
            break;
        case MOVE_RESULT_NOT_VERY_EFFECTIVE:
            stringId = STRINGID_NOTVERYEFFECTIVE;
            break;
        case MOVE_RESULT_ONE_HIT_KO:
            stringId = STRINGID_ONEHITKO;
            break;
        case MOVE_RESULT_FOE_ENDURED:
            stringId = STRINGID_PKMNENDUREDHIT;
            break;
		case MOVE_RESULT_STURDY:
			stringId = 384; // hack alert
			break;
        case MOVE_RESULT_FAILED:
            stringId = STRINGID_BUTITFAILED;
            break;
        case MOVE_RESULT_DOESNT_AFFECT_FOE:
            stringId = STRINGID_ITDOESNTAFFECT;
            break;
        case MOVE_RESULT_FOE_HUNG_ON:
            gLastUsedItem = gBattleMons[gBankTarget].item;
            gStringBank = gBankTarget;
            gMoveResultFlags &= ~(MOVE_RESULT_FOE_ENDURED | MOVE_RESULT_FOE_HUNG_ON);
            BattleScriptPushCursor();
            if (ItemId_GetHoldEffect(gLastUsedItem) == HOLD_EFFECT_FOCUS_SASH)
                gBattlescriptCurrInstr = BattleScript_HangedOnMsgDestroyItem;
            else
                gBattlescriptCurrInstr = BattleScript_HangedOnMsg;
            return;
        default:
            if (gMoveResultFlags & MOVE_RESULT_DOESNT_AFFECT_FOE)
            {
                stringId = STRINGID_ITDOESNTAFFECT;
            }
            else if (gMoveResultFlags & MOVE_RESULT_ONE_HIT_KO)
            {
                gMoveResultFlags &= ~(MOVE_RESULT_ONE_HIT_KO);
                gMoveResultFlags &= ~(MOVE_RESULT_SUPER_EFFECTIVE);
                gMoveResultFlags &= ~(MOVE_RESULT_NOT_VERY_EFFECTIVE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_OneHitKOMsg;
                return;
            }
            else if (gMoveResultFlags & MOVE_RESULT_FOE_ENDURED)
            {
                gMoveResultFlags &= ~(MOVE_RESULT_FOE_ENDURED | MOVE_RESULT_FOE_HUNG_ON | MOVE_RESULT_STURDY);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_EnduredMsg;
                return;
            }
			else if (gMoveResultFlags & MOVE_RESULT_STURDY)
			{
                gMoveResultFlags &= ~(MOVE_RESULT_FOE_ENDURED | MOVE_RESULT_FOE_HUNG_ON | MOVE_RESULT_STURDY);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_SturdyMsg;
                return;
			}
            else if (gMoveResultFlags & MOVE_RESULT_FOE_HUNG_ON)
            {
                gLastUsedItem = gBattleMons[gBankTarget].item;
                gStringBank = gBankTarget;
                gMoveResultFlags &= ~(MOVE_RESULT_FOE_ENDURED | MOVE_RESULT_FOE_HUNG_ON | MOVE_RESULT_STURDY);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_HangedOnMsg;
                return;
            }
            else if (gMoveResultFlags & MOVE_RESULT_FAILED)
            {
                stringId = STRINGID_BUTITFAILED;
            }
            else
            {
                gBattleCommunication[MSG_DISPLAY] = 0;
            }
        }
    }

    if (stringId)
        PrepareStringBattle(stringId, gBankAttacker);

    gBattlescriptCurrInstr++;
}

static void atk10_printstring(void)
{
    if (gBattleExecBuffer == 0)
    {
        u16 var = T2_READ_16(gBattlescriptCurrInstr + 1);
        PrepareStringBattle(var, gBankAttacker);
        gBattlescriptCurrInstr += 3;
        gBattleCommunication[MSG_DISPLAY] = 1;
    }
}

static void atk11_printselectionstring(void)
{
    gActiveBattler = gBankAttacker;
    EmitPrintStringPlayerOnly(0, T2_READ_16(gBattlescriptCurrInstr + 1));
    MarkBufferBankForExecution(gActiveBattler);
    gBattlescriptCurrInstr += 3;
    gBattleCommunication[MSG_DISPLAY] = 1;
}

static void atk12_waitmessage(void)
{
    if (gBattleExecBuffer == 0)
    {
        if (!gBattleCommunication[MSG_DISPLAY])
        {
            gBattlescriptCurrInstr += 3;
        }
        else
        {
            u16 to_wait = T2_READ_16(gBattlescriptCurrInstr + 1);
            if (++gPauseCounterBattle >= to_wait)
            {
                gPauseCounterBattle = 0;
                gBattlescriptCurrInstr += 3;
                gBattleCommunication[MSG_DISPLAY] = 0;
            }
        }
    }
}

static void atk13_printfromtable(void)
{
    if (gBattleExecBuffer == 0)
    {
        u16 *ptr = (u16 *)T1_READ_PTR(gBattlescriptCurrInstr + 1);
        ptr += gBattleCommunication[MULTISTRING_CHOOSER];
        PrepareStringBattle(*(u16*)ptr, gBankAttacker);
        gBattlescriptCurrInstr += 5;
        gBattleCommunication[MSG_DISPLAY] = 1;
    }
}

static void atk14_printselectionstringfromtable(void)
{
    if (gBattleExecBuffer == 0)
    {
        u16 *ptr = (u16 *)T1_READ_PTR(gBattlescriptCurrInstr + 1); // FIXME
        ptr += gBattleCommunication[MULTISTRING_CHOOSER];
        gActiveBattler = gBankAttacker;
        EmitPrintStringPlayerOnly(0, *(u16*)ptr);
        MarkBufferBankForExecution(gActiveBattler);
        gBattlescriptCurrInstr += 5;
        gBattleCommunication[MSG_DISPLAY] = 1;
    }
}

u8 BankGetTurnOrder(u8 bank)
{
    int i;
    for (i = 0; i < gBattlersCount; i++)
    {
        if (gBanksByTurnOrder[i] == bank)
            break;
    }
    return i;
}

//Someone please decompile this monstrosity below...
void SetMoveEffect(bool8 primary, u8 certainArg)
{
    #define EffectAffectsUser 0x40
    register u8 certain asm("r5") = certainArg;
    register bool32 StatusChanged asm("r10") = 0;
	register int AffectsUser asm("r6") = 0; //0x40 otherwise
    bool32 NoSunCanFreeze = 1;

    if (gBattleCommunication[MOVE_EFFECT_BYTE] & EffectAffectsUser)
    {
        gEffectBank = gBankAttacker; //bank that effects get applied on
        gBattleCommunication[MOVE_EFFECT_BYTE] &= ~(EffectAffectsUser);
        AffectsUser = EffectAffectsUser;
        gBattleStruct->scriptingActive = gBankTarget; //theoretically the attacker
    }
    else
    {
        gEffectBank = gBankTarget;
        gBattleStruct->scriptingActive = gBankAttacker;
    }

    if (gBattleMons[gEffectBank].ability == ABILITY_SHIELD_DUST && !(gHitMarker & HITMARKER_IGNORE_SAFEGUARD) &&
        !primary && gBattleCommunication[MOVE_EFFECT_BYTE] <= 9)
        {gBattlescriptCurrInstr++; return;}

    if (gSideAffecting[GetBattlerPosition(gEffectBank) & 1] & SIDE_STATUS_SAFEGUARD && !(gHitMarker & HITMARKER_IGNORE_SAFEGUARD) &&
        !primary && gBattleCommunication[MOVE_EFFECT_BYTE] <= 7)
        {gBattlescriptCurrInstr++; return;}
	
	if (gBattleMons[gBankAttacker].ability == ABILITY_SHEER_FORCE && (gBattleMoves[gCurrentMove].flags & F_SHEER_FORCE) && gBattleCommunication[MOVE_EFFECT_BYTE] != 0x26)
	{
		gBattlescriptCurrInstr++; return;
	}

    //make sure at least ONE HP except payday and thief
    if (gBattleMons[gEffectBank].hp == 0 && gBattleCommunication[MOVE_EFFECT_BYTE] != 0xB && gBattleCommunication[MOVE_EFFECT_BYTE] != 0x1F)
        {gBattlescriptCurrInstr++; return;}

    if (gBattleMons[gEffectBank].status2 & STATUS2_SUBSTITUTE && AffectsUser != EffectAffectsUser && gBattleMons[gBankAttacker].ability != ABILITY_INFILTRATOR)
        {gBattlescriptCurrInstr++; return;}

    if (gBattleCommunication[MOVE_EFFECT_BYTE] <= 6) //status change
    {
        switch (sStatusFlagsForMoveEffects[gBattleCommunication[MOVE_EFFECT_BYTE]])
        {
        case STATUS_SLEEP:
            //check active uproar
            if (gBattleMons[gEffectBank].ability != ABILITY_SOUNDPROOF)
            {
                for (gActiveBattler = 0; gActiveBattler < gBattlersCount && !(gBattleMons[gActiveBattler].status2 & STATUS2_UPROAR); gActiveBattler++) {}
            }
            else
                gActiveBattler = gBattlersCount;
            if (gBattleMons[gEffectBank].status1) {break;}
            if (gActiveBattler != gBattlersCount) {break;} //nice way of checking uproar...
            if (gBattleMons[gEffectBank].ability == ABILITY_VITAL_SPIRIT) {break;}
            if (gBattleMons[gEffectBank].ability == ABILITY_INSOMNIA) {break;}

            CancelMultiTurnMoves(gEffectBank);
            StatusChanged = 1;
            break;
        case STATUS_POISON:
            if (gBattleMons[gEffectBank].ability == ABILITY_IMMUNITY && (primary == 1 || certain == 0x80))
            {
                gLastUsedAbility = ABILITY_IMMUNITY;
                RecordAbilityBattle(gEffectBank, ABILITY_IMMUNITY);
                BattleScriptPush(gBattlescriptCurrInstr + 1);
            //_0801E664:
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;
                if (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                    gHitMarker &= ~(HITMARKER_IGNORE_SAFEGUARD);
                    return;
                }
                else
                    {gBattleCommunication[MULTISTRING_CHOOSER] = 0; return;}
            }
            if ((gBattleMons[gEffectBank].type1 == TYPE_POISON || gBattleMons[gEffectBank].type2 == TYPE_POISON || gBattleMons[gEffectBank].type1 == TYPE_STEEL || gBattleMons[gEffectBank].type2 == TYPE_STEEL)
                && !(gHitMarker & HITMARKER_IGNORE_SAFEGUARD) && (primary == 1 || certain == 0x80))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;
                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
                return;
            }
            if (gBattleMons[gEffectBank].type1 == TYPE_POISON) {break;}
            if (gBattleMons[gEffectBank].type2 == TYPE_POISON) {break;}
            if (gBattleMons[gEffectBank].type1 == TYPE_STEEL) {break;}
            if (gBattleMons[gEffectBank].type2 == TYPE_STEEL) {break;}
            if (gBattleMons[gEffectBank].status1) {break;}
            if (gBattleMons[gEffectBank].ability == ABILITY_IMMUNITY) {break;}

            StatusChanged = 1;
            break;
        case STATUS_BURN:
            if (gBattleMons[gEffectBank].ability == ABILITY_WATER_VEIL && (primary == 1 || certain == 0x80))
            {
                gLastUsedAbility = ABILITY_WATER_VEIL;
                RecordAbilityBattle(gEffectBank, ABILITY_WATER_VEIL);
                BattleScriptPush(gBattlescriptCurrInstr + 1);
            //_0801E664:
                gBattlescriptCurrInstr = BattleScript_BRNPrevention;
                if (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                    gHitMarker &= ~(HITMARKER_IGNORE_SAFEGUARD);
                    return;
                }
                else
                    {gBattleCommunication[MULTISTRING_CHOOSER] = 0; return;}
            }
            if ((gBattleMons[gEffectBank].type1 == TYPE_FIRE || gBattleMons[gEffectBank].type2 == TYPE_FIRE)
                && (gHitMarker & HITMARKER_IGNORE_SAFEGUARD) && (primary == 1 || certain == 0x80))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_BRNPrevention;
                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
                return;
            }
            if (gBattleMons[gEffectBank].type1 == TYPE_FIRE) {break;}
            if (gBattleMons[gEffectBank].type2 == TYPE_FIRE) {break;}
            if (gBattleMons[gEffectBank].ability == ABILITY_WATER_VEIL) {break;}
            if (gBattleMons[gEffectBank].status1 != 0) {break;}
            StatusChanged = 1;
            break;
        case STATUS_FREEZE:
            if (WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SUN_ANY) {NoSunCanFreeze = 0;}
            if (gBattleMons[gEffectBank].type1 == TYPE_ICE) {break;}
            if (gBattleMons[gEffectBank].type2 == TYPE_ICE) {break;}
            if (gBattleMons[gEffectBank].status1) {break;}
            if (NoSunCanFreeze == 0) {break;}
            if (gBattleMons[gEffectBank].ability == ABILITY_MAGMA_ARMOR) {break;}

            CancelMultiTurnMoves(gEffectBank);
            StatusChanged = 1;
            break;
        case STATUS_PARALYSIS:
            if (gBattleMons[gEffectBank].ability == ABILITY_LIMBER)
            {
                if ((primary == 1 || certain == 0x80))
                {
                    gLastUsedAbility = ABILITY_LIMBER;
                    RecordAbilityBattle(gEffectBank, ABILITY_LIMBER);
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                //_0801E664:
                    gBattlescriptCurrInstr = BattleScript_PRLZPrevention;
                    if (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                        gHitMarker &= ~(HITMARKER_IGNORE_SAFEGUARD);
                        return;
                    }
                    else
                        {gBattleCommunication[MULTISTRING_CHOOSER] = 0; return;}
                }
                else {break;}
            }
            if (gBattleMons[gEffectBank].status1) {break;}
			if (gBattleMons[gEffectBank].type1 == TYPE_ELECTRIC || gBattleMons[gEffectBank].type2 == TYPE_ELECTRIC) {break;}
            StatusChanged = 1;
            break;
        case STATUS_TOXIC_POISON:
            if (gBattleMons[gEffectBank].ability == ABILITY_IMMUNITY && (primary == 1 || certain == 0x80))
            {
                gLastUsedAbility = ABILITY_IMMUNITY;
                RecordAbilityBattle(gEffectBank, ABILITY_IMMUNITY);
                BattleScriptPush(gBattlescriptCurrInstr + 1);
            //_0801E664:
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;
                if (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                    gHitMarker &= ~(HITMARKER_IGNORE_SAFEGUARD);
                    return;
                }
                else
                    {gBattleCommunication[MULTISTRING_CHOOSER] = 0; return;}
            }
            if ((gBattleMons[gEffectBank].type1 == TYPE_POISON || gBattleMons[gEffectBank].type2 == TYPE_POISON || gBattleMons[gEffectBank].type1 == TYPE_STEEL || gBattleMons[gEffectBank].type2 == TYPE_STEEL)
                && !(gHitMarker & HITMARKER_IGNORE_SAFEGUARD) && (primary == 1 || certain == 0x80))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;
                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
                return;
            }
            if (gBattleMons[gEffectBank].status1) {break;}
            if (gBattleMons[gEffectBank].type1 != TYPE_POISON &&
                gBattleMons[gEffectBank].type2 != TYPE_POISON &&
                gBattleMons[gEffectBank].type1 != TYPE_STEEL &&
                gBattleMons[gEffectBank].type2 != TYPE_STEEL)
            {
                if (gBattleMons[gEffectBank].ability == ABILITY_IMMUNITY) {break;}
                gBattleMons[gEffectBank].status1 &= ~(0x9); //This gets (correctly) optimized out...
                StatusChanged = 1;
                break;
            }
            else
                gMoveResultFlags |= MOVE_RESULT_DOESNT_AFFECT_FOE;
            break;
        }
        if (StatusChanged == 1)
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            if (sStatusFlagsForMoveEffects[gBattleCommunication[MOVE_EFFECT_BYTE]] == STATUS_SLEEP)
                gBattleMons[gEffectBank].status1 |= ((Random() % 3) + 2);
            else
                gBattleMons[gEffectBank].status1 |= sStatusFlagsForMoveEffects[gBattleCommunication[MOVE_EFFECT_BYTE]];
            gBattlescriptCurrInstr = gMoveEffectBS_Ptrs[gBattleCommunication[MOVE_EFFECT_BYTE]];
            gActiveBattler = gEffectBank;
            EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gEffectBank].status1);
            MarkBufferBankForExecution(gActiveBattler);
            if (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                gHitMarker &= ~(HITMARKER_IGNORE_SAFEGUARD);
            }
            else
                gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            if (gBattleCommunication[MOVE_EFFECT_BYTE] == 2 || gBattleCommunication[MOVE_EFFECT_BYTE] == 6 || gBattleCommunication[MOVE_EFFECT_BYTE] == 5 || gBattleCommunication[MOVE_EFFECT_BYTE] == 3)
            {
                gBattleStruct->synchroniseEffect = gBattleCommunication[MOVE_EFFECT_BYTE];
                gHitMarker |= HITMARKER_SYNCHRONISE_EFFECT;
            }
            return;
        }
        else if (StatusChanged == 0)
        {
            gBattleCommunication[MOVE_EFFECT_BYTE] = 0;
            gBattlescriptCurrInstr++; return;
        }
    }
    else
    {
        if (gBattleMons[gEffectBank].status2 & sStatusFlagsForMoveEffects[gBattleCommunication[MOVE_EFFECT_BYTE]])
        {
            gBattlescriptCurrInstr++;
            return;
        }
        switch (gBattleCommunication[MOVE_EFFECT_BYTE])
        {
        case 7: //confusion
            if (gBattleMons[gEffectBank].ability == ABILITY_OWN_TEMPO)
                {gBattlescriptCurrInstr++; return;}
            if (gBattleMons[gEffectBank].status2 & STATUS2_CONFUSION)
                {gBattlescriptCurrInstr++; return;}
            gBattleMons[gEffectBank].status2 |= (((Random()) % 0x4)) + 2;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = gMoveEffectBS_Ptrs[gBattleCommunication[MOVE_EFFECT_BYTE]];
            break;
        case 8: //flinch
            if (gBattleMons[gEffectBank].ability == ABILITY_INNER_FOCUS)
            {
                if (primary == 1 || certain == 0x80)
                {
                    gLastUsedAbility = ABILITY_INNER_FOCUS;
                    RecordAbilityBattle(gEffectBank, ABILITY_INNER_FOCUS);
                    gBattlescriptCurrInstr = BattleScript_FlinchPrevention;
                    return;
                }
                else
                    {gBattlescriptCurrInstr++; return;}
            }
            else
            {
                if (BankGetTurnOrder(gEffectBank) > gCurrentTurnActionNumber)
                    gBattleMons[gEffectBank].status2 |= sStatusFlagsForMoveEffects[gBattleCommunication[MOVE_EFFECT_BYTE]];
                gBattlescriptCurrInstr++; return;
            }
            break;
        case 10: //uproar
            if (gBattleMons[gEffectBank].status2 & STATUS2_UPROAR)
                {gBattlescriptCurrInstr++; return;}
            gBattleMons[gEffectBank].status2 |= STATUS2_MULTIPLETURNS;
            gLockedMoves[gEffectBank] = gCurrentMove;
            gBattleMons[gEffectBank].status2 |= ((Random() & 3) + 2) << 4;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = gMoveEffectBS_Ptrs[gBattleCommunication[MOVE_EFFECT_BYTE]];
            break;
        case 11: //pay day
            if (!(GetBattlerPosition(gBankAttacker) & 1))
            {
                u16 PayDay = gPaydayMoney;
                gPaydayMoney += (gBattleMons[gBankAttacker].level * 5);
                if (PayDay > gPaydayMoney)
                    gPaydayMoney = 0xFFFF;
            }
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = gMoveEffectBS_Ptrs[gBattleCommunication[MOVE_EFFECT_BYTE]];
            break;
        case 9: //tri attack
            if (gBattleMons[gEffectBank].status1)
                {gBattlescriptCurrInstr++; return;}
            gBattleCommunication[MOVE_EFFECT_BYTE] = Random() % 3 + 3;
            SetMoveEffect(0, 0);
            break;
        case 12: //charging move
            gBattleMons[gEffectBank].status2 |= STATUS2_MULTIPLETURNS;
            gLockedMoves[gEffectBank] = gCurrentMove;
            gProtectStructs[gEffectBank].chargingTurn = 1;
            gBattlescriptCurrInstr++;
            break;
        case 13: //wrap
            if (gBattleMons[gEffectBank].status2 & STATUS2_WRAPPED)
                {gBattlescriptCurrInstr++; return;}
            gBattleMons[gEffectBank].status2 |= ((Random() & 3) + 2) << 0xD;
            gBattleStruct->wrappedMove[gEffectBank*2] = (u8)gCurrentMove;
            (1 + gBattleStruct->wrappedMove)[gEffectBank*2] = gCurrentMove >> 8; //don't ask.
            gBattleStruct->wrappedBy[gEffectBank] = gBankAttacker;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = gMoveEffectBS_Ptrs[gBattleCommunication[MOVE_EFFECT_BYTE]];
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            while (gBattleCommunication[MULTISTRING_CHOOSER] <= 5
             && gCurrentMove != gTrappingMoves[gBattleCommunication[MULTISTRING_CHOOSER]])
                gBattleCommunication[MULTISTRING_CHOOSER]++;
            break;
        case 14: //25% recoil
            if (gCurrentMove == MOVE_STRUGGLE)
                gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP / 4;
            else
                gBattleMoveDamage = (gHpDealt) / 4;
            if (gBattleMoveDamage == 0)
                gBattleMoveDamage = 1;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = gMoveEffectBS_Ptrs[gBattleCommunication[MOVE_EFFECT_BYTE]];
            break;
        case 15 ... 21: //stat + 1
            if (ChangeStatBuffs(0x10, gBattleCommunication[MOVE_EFFECT_BYTE] + 0xF2, AffectsUser, 0)) {gBattlescriptCurrInstr++;}
            else
            {
                gBattleStruct->animArg1 = gBattleCommunication[MOVE_EFFECT_BYTE] & 0x3F; //TODO: the arg ptr is wrong by one
                gBattleStruct->animArg2 = 0;
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_StatUp;
            }
            break;
        case 22 ... 28: //stat - 1
            if (ChangeStatBuffs(~(0x6f), gBattleCommunication[MOVE_EFFECT_BYTE] + 0xEB, AffectsUser, 0)) {gBattlescriptCurrInstr++;} //TODO: negation doesnt work correctly
            else
            {
                gBattleStruct->animArg1 = gBattleCommunication[MOVE_EFFECT_BYTE] & 0x3F;
                gBattleStruct->animArg2 = 0;
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_StatDown;
            }
            break;
        case 39 ... 45: //stat + 2
            if (ChangeStatBuffs(0x20, gBattleCommunication[MOVE_EFFECT_BYTE] + 0xDA, AffectsUser, 0)) {gBattlescriptCurrInstr++;}
            else
            {
                gBattleStruct->animArg1 = gBattleCommunication[MOVE_EFFECT_BYTE] & 0x3F;
                gBattleStruct->animArg2 = 0;
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_StatUp;
            }
            break;
        case 46 ... 52: //stat - 2
            if (ChangeStatBuffs(~(0x5f), gBattleCommunication[MOVE_EFFECT_BYTE] + 0xD3, AffectsUser, 0)) {gBattlescriptCurrInstr++;}
            else
            {
                gBattleStruct->animArg1 = gBattleCommunication[MOVE_EFFECT_BYTE] & 0x3F;
                gBattleStruct->animArg2 = 0;
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_StatDown;
            }
            break;
        case 29: //recharge
            gBattleMons[gEffectBank].status2 |= STATUS2_RECHARGE;
            gDisableStructs[gEffectBank].rechargeCounter = 2;
            gLockedMoves[gEffectBank] = gCurrentMove;
            gBattlescriptCurrInstr++;
            break;
        case 30: //rage
            gBattleMons[gBankAttacker].status2 |= STATUS2_RAGE;
            gBattlescriptCurrInstr++;
            break;
        case 31: //item steal
            {
                u8 side = GetBattlerSide(gBankAttacker);
                if (GetBattlerSide(gBankAttacker) == 1 && !(gBattleTypeFlags & (BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_LINK)) && gTrainerBattleOpponent != 0x400)
                        {gBattlescriptCurrInstr++; return;}
                else if (!(gBattleTypeFlags & (BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_LINK)) && gTrainerBattleOpponent != 0x400 && (gWishFutureKnock.knockedOffPokes[side] & gBitTable[gBattlerPartyIndexes[gBankAttacker]]))
                        {gBattlescriptCurrInstr++; return;}
                else if (gBattleMons[gBankTarget].item && gBattleMons[gBankTarget].ability == ABILITY_STICKY_HOLD)
                {
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_NoItemSteal;
                    gLastUsedAbility = gBattleMons[gBankTarget].ability;
                    RecordAbilityBattle(gBankTarget, gLastUsedAbility);
                    return;
                }
                else if (gBattleMons[gBankAttacker].item)
                    {gBattlescriptCurrInstr++; return;}
                else if (gBattleMons[gBankTarget].item == ITEM_ENIGMA_BERRY)
                    {gBattlescriptCurrInstr++; return;}
                else if (gBattleMons[gBankTarget].item == 0)
                    {gBattlescriptCurrInstr++; return;}
				else
				{
					gLastUsedItem = gBattleMons[gBankTarget].item;
					gBattleStruct->usedHeldItems[gBankAttacker] = gLastUsedItem;
					gBattleMons[gBankTarget].item = 0;

					gActiveBattler = gBankAttacker;
					EmitSetMonData(0, REQUEST_HELDITEM_BATTLE, 0, 2, &gLastUsedItem);
					MarkBufferBankForExecution(gBankAttacker);

					gActiveBattler = gBankTarget;
					EmitSetMonData(0, REQUEST_HELDITEM_BATTLE, 0, 2, &gBattleMons[gBankTarget].item);
					MarkBufferBankForExecution(gBankTarget);

					BattleScriptPush(gBattlescriptCurrInstr + 1);
					gBattlescriptCurrInstr = BattleScript_ItemSteal;

					gBattleStruct->choicedMove[gBankTarget] = 0;
				}
            }
            break;
        case 32: //escape prevention
            gBattleMons[gBankTarget].status2 |= STATUS2_ESCAPE_PREVENTION;
            gDisableStructs[gBankTarget].bankPreventingEscape = gBankAttacker;
            gBattlescriptCurrInstr++;
            break;
        case 33: //nightmare
            gBattleMons[gBankTarget].status2 |= STATUS2_NIGHTMARE;
            gBattlescriptCurrInstr++;
            break;
        case 34: //ancientpower
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_AllStatsUp;
            return;
        case 35: //break free rapidspin
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_RapidSpinAway;
            return;
        case 36: //paralysis removal
            if (gBattleMons[gBankTarget].status1 & STATUS_PARALYSIS)
            {
                gBattleMons[gBankTarget].status1 &= ~(STATUS_PARALYSIS);
                gActiveBattler = gBankTarget;
                EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gBankTarget].status1);
                MarkBufferBankForExecution(gActiveBattler);
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_TargetPRLZHeal;
            }
            else
                {gBattlescriptCurrInstr++; return;}
            break;
        case 37: //superpower
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_AtkDefDown;
            return;
        case 38: //33% recoil
            gBattleMoveDamage = gHpDealt / 3;
            if (gBattleMoveDamage == 0)
                gBattleMoveDamage = 1;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = gMoveEffectBS_Ptrs[gBattleCommunication[MOVE_EFFECT_BYTE]];
            break;
        case 53: //thrash
            if (!(gBattleMons[gEffectBank].status2 & STATUS2_LOCK_CONFUSE))
            {
                gBattleMons[gEffectBank].status2 |= STATUS2_MULTIPLETURNS;
                gLockedMoves[gEffectBank] = gCurrentMove;
                gBattleMons[gEffectBank].status2 |= (((Random() & 1) + 2) << 0xA);
            }
            else
                {gBattlescriptCurrInstr++; return;}
            break;
        case 54: //knock off
            if (gBattleMons[gEffectBank].ability == ABILITY_STICKY_HOLD)
            {
                if (gBattleMons[gEffectBank].item == 0)
                    {gBattlescriptCurrInstr++; return;}
                gLastUsedAbility = ABILITY_STICKY_HOLD;
                gBattlescriptCurrInstr = BattleScript_NoItemSteal;
                RecordAbilityBattle(gEffectBank, ABILITY_STICKY_HOLD);
                return;
            }
            if (gBattleMons[gEffectBank].item == 0)
                    {gBattlescriptCurrInstr++; return;}
            else
            {
                u8 side = GetBattlerSide(gEffectBank);
                gLastUsedItem = gBattleMons[gEffectBank].item;
                gBattleMons[gEffectBank].item = 0;
                gWishFutureKnock.knockedOffPokes[side] |= gBitTable[gBattlerPartyIndexes[gEffectBank]];
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_KnockedOff;

				gBattleStruct->choicedMove[gEffectBank] = 0;
            }
            break;
        case 59: //overheat
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_SAtkDown2;
            return;
        }
    }
}

static void atk15_seteffectwithchance(void)
{
    u32 PercentChance;

    if (gBattleMons[gBankAttacker].ability == ABILITY_SERENE_GRACE)
        PercentChance = gBattleMoves[gCurrentMove].secondaryEffectChance * 2;
    else
        PercentChance = gBattleMoves[gCurrentMove].secondaryEffectChance;

    if (DEBUG && (gUnknown_02023A14_50 & 4)
     && !(gBattleCommunication[MOVE_EFFECT_BYTE] & 0x80) && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
    {
        SetMoveEffect(0, 0);
    }
    else if ((gBattleCommunication[MOVE_EFFECT_BYTE] & 0x80) && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
    {
        gBattleCommunication[MOVE_EFFECT_BYTE] &= 0x7F;
        SetMoveEffect(0, 0x80);
    }
    else if (Random() % 100 <= PercentChance && gBattleCommunication[MOVE_EFFECT_BYTE] != 0 && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
    {
        if (PercentChance >= 100)
            SetMoveEffect(0, 0x80);
        else
            SetMoveEffect(0, 0);
    }
    else
    {
        gBattlescriptCurrInstr++;
    }

    gBattleCommunication[MOVE_EFFECT_BYTE] = 0;
    gBattleStruct->unk16112 = 0;
}

static void atk16_seteffectprimary(void)
{
    SetMoveEffect(1, 0);
}

static void atk17_seteffectsecondary(void)
{
    SetMoveEffect(0, 0);
}

static void atk18_clearstatusfromeffect(void)
{
    gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
    if (gBattleCommunication[MOVE_EFFECT_BYTE] <= 6)
        gBattleMons[gActiveBattler].status1 &= (~sStatusFlagsForMoveEffects[gBattleCommunication[MOVE_EFFECT_BYTE]]);
    else
        gBattleMons[gActiveBattler].status2 &= (~sStatusFlagsForMoveEffects[gBattleCommunication[MOVE_EFFECT_BYTE]]);

    gBattleCommunication[MOVE_EFFECT_BYTE] = 0;
    gBattlescriptCurrInstr += 2;
    gBattleStruct->unk16112 = 0;
}

static void atk19_tryfaintmon(void)
{
    u8 *r4;

    if (gBattlescriptCurrInstr[2] != 0)
    {
        gActiveBattler = GetBattleBank(gBattlescriptCurrInstr[1]);
        if (gHitMarker & HITMARKER_FAINTED(gActiveBattler))
        {
            r4 = T1_READ_PTR(gBattlescriptCurrInstr + 3);

            BattleScriptPop();
            gBattlescriptCurrInstr = r4;
            gSideAffecting[GetBattlerSide(gActiveBattler)] &= ~SIDE_STATUS_SPIKES_DAMAGED;
        }
        else
        {
            gBattlescriptCurrInstr += 7;
        }
    }
    else
    {
        u8 bank;

        if (gBattlescriptCurrInstr[1] == 1)
        {
            gActiveBattler = gBankAttacker;
            bank = gBankTarget;
            r4 = BattleScript_FaintAttacker;
        }
        else
        {
            gActiveBattler = gBankTarget;
            bank = gBankAttacker;
            r4 = BattleScript_FaintTarget;
        }
        if (!(gAbsentBattlerFlags & gBitTable[gActiveBattler])
         && gBattleMons[gActiveBattler].hp == 0)
        {
            ewram160ACarr2(0, bank) = 0;
            ewram160ACarr2(1, bank) = 0;
            ewram16100arr2(0, bank) = 0;
            ewram16100arr2(1, bank) = 0;
            ewram16100arr2(2, bank) = 0;
            ewram16100arr2(3, bank) = 0;

            gHitMarker |= HITMARKER_FAINTED(gActiveBattler);
            BattleScriptPush(gBattlescriptCurrInstr + 7);
            gBattlescriptCurrInstr = r4;
            if (GetBattlerSide(gActiveBattler) == 0)
            {
                gHitMarker |= HITMARKER_x400000;
                if (gBattleResults.playerFaintCounter < 0xFF)
                    gBattleResults.playerFaintCounter++;
                if (gBattleMons[bank].level > gBattleMons[gActiveBattler].level)
                {
                    if (gBattleMons[bank].level - gBattleMons[gActiveBattler].level > 29)
                        AdjustFriendship(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], FRIENDSHIP_EVENT_FAINT_LARGE);
                    else
                        AdjustFriendship(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], FRIENDSHIP_EVENT_FAINT_SMALL);
                }
            }
            else
            {
                if (gBattleResults.opponentFaintCounter < 0xFF)
                    gBattleResults.opponentFaintCounter++;
                gBattleResults.lastOpponentSpecies = gBattleMons[gActiveBattler].species;
            }
            if ((gHitMarker & HITMARKER_DESTINYBOND) && gBattleMons[gBankAttacker].hp != 0)
            {
                BattleScriptPush(gBattlescriptCurrInstr);
                gBattleMoveDamage = gBattleMons[bank].hp;
                gBattlescriptCurrInstr = BattleScript_DestinyBondTakesLife;
            }
            if ((gStatuses3[gBankTarget] & STATUS3_GRUDGE)
             && !(gHitMarker & HITMARKER_GRUDGE)
             && GetBattlerSide(gBankAttacker) != GetBattlerSide(gBankTarget)
             && gBattleMons[gBankAttacker].hp != 0
             && gCurrentMove != MOVE_STRUGGLE)
            {
                u8 moveIndex = ewram1608Carr(gBankAttacker);

                gBattleMons[gBankAttacker].pp[moveIndex] = 0;
                BattleScriptPush(gBattlescriptCurrInstr);
                gBattlescriptCurrInstr = BattleScript_SelectingImprisionedMoveInPalace;
                gActiveBattler = gBankAttacker;
                EmitSetMonData(0, moveIndex + 9, 0, 1, &gBattleMons[gActiveBattler].pp[moveIndex]);
                MarkBufferBankForExecution(gActiveBattler);

                gBattleTextBuff1[0] = 0xFD;
                gBattleTextBuff1[1] = 2;
                gBattleTextBuff1[2] = gBattleMons[gBankAttacker].moves[moveIndex];
                gBattleTextBuff1[3] = gBattleMons[gBankAttacker].moves[moveIndex] >> 8;
                gBattleTextBuff1[4] = EOS;
            }
        }
        else
        {
            gBattlescriptCurrInstr += 7;
        }
    }
}

static void atk1A_dofaintanimation(void)
{
    if (gBattleExecBuffer == 0)
    {
        gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
        Emitcmd10(0);
        MarkBufferBankForExecution(gActiveBattler);
        gBattlescriptCurrInstr += 2;
    }
}

static void atk1B_cleareffectsonfaint(void)
{
    //Clears things like attraction or trapping to other banks
    if (gBattleExecBuffer == 0)
    {
        gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
        gBattleMons[gActiveBattler].status1 = 0;
        EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 0x4, &gBattleMons[gActiveBattler].status1);
        MarkBufferBankForExecution(gActiveBattler);
        UndoEffectsAfterFainting();
        gBattlescriptCurrInstr += 2;
    }
}

static void atk1C_jumpifstatus(void)
{
    u8 bank = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
    u32 flags = T2_READ_32(gBattlescriptCurrInstr + 2);
    void* jump_loc = T2_READ_PTR(gBattlescriptCurrInstr + 6);
    if (gBattleMons[bank].status1 & flags && gBattleMons[bank].hp)
        gBattlescriptCurrInstr = jump_loc;
    else
        gBattlescriptCurrInstr += 10;
}

static void atk1D_jumpifstatus2(void)
{
    u8 bank = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
    u32 flags = T2_READ_32(gBattlescriptCurrInstr + 2);
    void* jump_loc = T2_READ_PTR(gBattlescriptCurrInstr + 6);
	if (gBattleMons[gBankAttacker].ability == ABILITY_INFILTRATOR && (flags == STATUS2_SUBSTITUTE) && gBankAttacker != bank)
		gBattlescriptCurrInstr += 10;
    else if (gBattleMons[bank].status2 & flags && gBattleMons[bank].hp)
        gBattlescriptCurrInstr = jump_loc;
    else
        gBattlescriptCurrInstr += 10;
}

static void atk1E_jumpifability(void)
{
    u8 bank;
    u8 ability = T2_READ_8(gBattlescriptCurrInstr + 2);
    void* jump_loc = T2_READ_PTR(gBattlescriptCurrInstr + 3);
	
	if (gBattleMons[gBankAttacker].ability == ABILITY_MOLD_BREAKER)
	{
		u8 i = 0;
		while (sMoldBreakerAbilities[i])
		{
			if (sMoldBreakerAbilities[i] == ability)
			{
				gBattlescriptCurrInstr += 7;
				return;
			}
			i++;
		}
	}
	
    if (T2_READ_8(gBattlescriptCurrInstr + 1) == 8)
    {
        bank = AbilityBattleEffects(ABILITYEFFECT_CHECK_BANK_SIDE, gBankAttacker, ability, 0, 0);
        if (bank)
        {
            gLastUsedAbility = ability;
            gBattlescriptCurrInstr = jump_loc;
            RecordAbilityBattle(bank -1, gLastUsedAbility);
            ewram160F8 = bank - 1;
        }
        else
            gBattlescriptCurrInstr += 7;
    }
    else if (T2_READ_8(gBattlescriptCurrInstr + 1) == 9)
    {
        bank = AbilityBattleEffects(ABILITYEFFECT_CHECK_OTHER_SIDE, gBankAttacker, ability, 0, 0);
        if (bank)
        {
            gLastUsedAbility = ability;
            gBattlescriptCurrInstr = jump_loc;
            RecordAbilityBattle(bank - 1, gLastUsedAbility);
            ewram160F8 = bank - 1;
        }
        else
            gBattlescriptCurrInstr += 7;
    }
    else
    {
        bank = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
        if (gBattleMons[bank].ability == ability)
        {
            gLastUsedAbility = ability;
            gBattlescriptCurrInstr = jump_loc;
            RecordAbilityBattle(bank, gLastUsedAbility);
            ewram160F8 = bank;
        }
        else
            gBattlescriptCurrInstr += 7;
    }
}

static void atk1F_jumpifsideaffecting(void)
{
    u8 side;
    u16 flags;
    void* jump_loc;
    if (T2_READ_8(gBattlescriptCurrInstr + 1) == 1)
        side = GetBattlerPosition(gBankAttacker) & 1;
    else
        side = GetBattlerPosition(gBankTarget) & 1;

    flags = T2_READ_16(gBattlescriptCurrInstr + 2);
    jump_loc = T2_READ_PTR(gBattlescriptCurrInstr + 4);
	
	if (gBattleMons[gBankAttacker].ability == ABILITY_INFILTRATOR && flags == SIDE_STATUS_SAFEGUARD)
		gBattlescriptCurrInstr += 8;
    else if (gSideAffecting[side] & flags)
        gBattlescriptCurrInstr = jump_loc;
    else
        gBattlescriptCurrInstr += 8;
}

static void atk20_jumpifstat(void)
{
    u8 ret = 0;
    u8 bank = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
    u8 value = gBattleMons[bank].statStages[T2_READ_8(gBattlescriptCurrInstr + 3)];
    u8 contrary = gBattleMons[bank].ability == ABILITY_CONTRARY;
    u8 comparison = T2_READ_8(gBattlescriptCurrInstr + 2);
    
    if (contrary)
    {
        if (value == 0)
            value = 12;
        else if (value == 12)
            value = 0;
        
        if (comparison == CMP_GREATER_THAN)
            comparison = CMP_LESS_THAN;
        else if (comparison == CMP_LESS_THAN)
            comparison = CMP_GREATER_THAN;
    }
    
    switch (comparison)
    {
    case CMP_EQUAL:
        if (value == T2_READ_8(gBattlescriptCurrInstr + 4))
            ret++;
        break;
    case CMP_NOT_EQUAL:
        if (value != T2_READ_8(gBattlescriptCurrInstr + 4))
            ret++;
        break;
    case CMP_GREATER_THAN:
        if (value > T2_READ_8(gBattlescriptCurrInstr + 4))
            ret++;
        break;
    case CMP_LESS_THAN:
        if (value < T2_READ_8(gBattlescriptCurrInstr + 4))
            ret++;
        break;
    case CMP_COMMON_BITS:
        if (value & T2_READ_8(gBattlescriptCurrInstr + 4))
            ret++;
        break;
    case CMP_NO_COMMON_BITS:
        if (!(value & T2_READ_8(gBattlescriptCurrInstr + 4)))
            ret++;
        break;
    }
    if (ret)
        gBattlescriptCurrInstr = T2_READ_PTR(gBattlescriptCurrInstr + 5);
    else
        gBattlescriptCurrInstr += 9;
}

static void atk21_jumpifstatus3condition(void)
{
    u32 flags;
    void* jump_loc;

    gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
    flags = T2_READ_32(gBattlescriptCurrInstr + 2);
    jump_loc = T2_READ_PTR(gBattlescriptCurrInstr + 7);
    if (T2_READ_8(gBattlescriptCurrInstr + 6))
    {
        if ((gStatuses3[gActiveBattler] & flags) != 0)
            gBattlescriptCurrInstr += 11;
        else
            gBattlescriptCurrInstr = jump_loc;
    }
    else
    {
        if ((gStatuses3[gActiveBattler] & flags) != 0)
            gBattlescriptCurrInstr = jump_loc;
        else
            gBattlescriptCurrInstr += 11;
    }
}

static void atk22_jumpiftype(void) //u8 bank, u8 type, *ptr
{
    u8 bank = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
    u8 type = T2_READ_8(gBattlescriptCurrInstr + 2);
    void* jump_loc = T2_READ_PTR(gBattlescriptCurrInstr + 3);

    if (gBattleMons[bank].type1 == type || gBattleMons[bank].type2 == type)
        gBattlescriptCurrInstr = jump_loc;
    else
        gBattlescriptCurrInstr += 7;
}

static void atk23_getexp(void)
{
    u16 item;
    s32 i; // also used as stringId
    u8 holdEffect;
    s32 sentIn;

    s32 viaExpShare = 0;
    u16* exp = &gBattleStruct->exp;

    gBank1 = GetBattleBank(gBattlescriptCurrInstr[1]);
    sentIn = gSentPokesToOpponent[(gBank1 & 2) >> 1];

    switch (gBattleStruct->getexpStateTracker)
    {
    case 0: // check if should receive exp at all
        if (GetBattlerSide(gBank1) != B_SIDE_OPPONENT || (gBattleTypeFlags &
             (BATTLE_TYPE_LINK
              | BATTLE_TYPE_SAFARI
              | BATTLE_TYPE_BATTLE_TOWER
              | BATTLE_TYPE_EREADER_TRAINER)))
        {
            gBattleStruct->getexpStateTracker = 6; // goto last case
        }
        else
        {
            gBattleStruct->getexpStateTracker++;
            gBattleStruct->unk16113 |= gBitTable[gBattlerPartyIndexes[gBank1]];
        }
        break;
    case 1: // calculate experience points to redistribute
        {
            u16 calculatedExp;
            s32 viaSentIn;

            for (viaSentIn = 0, i = 0; i < 6; i++)
            {
                if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) == SPECIES_NONE || GetMonData(&gPlayerParty[i], MON_DATA_HP) == 0)
                    continue;
                if (gBitTable[i] & sentIn)
                    viaSentIn++;

                item = GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM);

                if (item == ITEM_ENIGMA_BERRY)
                    holdEffect = gSaveBlock1.enigmaBerry.holdEffect;
                else
                    holdEffect = ItemId_GetHoldEffect(item);

                if (holdEffect == HOLD_EFFECT_EXP_SHARE)
                    viaExpShare++;
            }

            calculatedExp = gBaseStats[gBattleMons[gBank1].species].expYield * gBattleMons[gBank1].level / 5;

            if (viaExpShare) // at least one mon is getting exp via exp share
            {
                *exp = calculatedExp / 2 / viaSentIn;
                if (*exp == 0)
                    *exp = 1;

                gExpShareExp = calculatedExp / 2 / viaExpShare;
                if (gExpShareExp == 0)
                    gExpShareExp = 1;
            }
            else
            {
                *exp = calculatedExp / viaSentIn;
                if (*exp == 0)
                    *exp = 1;
                gExpShareExp = 0;
            }

            gBattleStruct->getexpStateTracker++;
            gBattleStruct->expGetterID = 0;
            gBattleStruct->sentInPokes = sentIn;
        }
        // fall through
    case 2: // set exp value to the poke in expgetter_id and print message
        if (gBattleExecBuffer == 0)
        {
            item = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_HELD_ITEM);

            if (item == ITEM_ENIGMA_BERRY)
                holdEffect = gSaveBlock1.enigmaBerry.holdEffect;
            else
                holdEffect = ItemId_GetHoldEffect(item);

            if (holdEffect != HOLD_EFFECT_EXP_SHARE && !(gBattleStruct->sentInPokes & 1))
            {
                gBattleStruct->sentInPokes >>= 1;
                gBattleStruct->getexpStateTracker = 5;
                gBattleMoveDamage = 0; // used for exp
            }
            else if (GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_LEVEL) == 100)
            {
                gBattleStruct->sentInPokes >>= 1;
                gBattleStruct->getexpStateTracker = 5;
                gBattleMoveDamage = 0; // used for exp
            }
            else
            {
                // music change in wild battle after fainting a poke
                if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER) && gBattleMons[0].hp && !gBattleStruct->wildVictorySong)
                {
                    BattleStopLowHpSound();
                    PlayBGM(0x161);
                    gBattleStruct->wildVictorySong++;
                }

                if (GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_HP))
                {
                    u8 enemyLevel = gBattleMons[gBank1].level;
                    u8 playerLevel = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_LEVEL);
                    if (gBattleStruct->sentInPokes & 1)
                        gBattleMoveDamage = *exp;
                    else
                        gBattleMoveDamage = 0;

                    if (holdEffect == HOLD_EFFECT_EXP_SHARE)
                        gBattleMoveDamage += gExpShareExp;
					
					gBattleMoveDamage *= sExperienceScalingFactors[(enemyLevel * 2) + 10];
					gBattleMoveDamage /= sExperienceScalingFactors[(enemyLevel + playerLevel) + 10];
					
                    if (enemyLevel > (playerLevel + 5))
                    {
                        gBattleMoveDamage *= 5 + (enemyLevel - playerLevel);
                        gBattleMoveDamage /= 10;
                    }
                    
                    if (holdEffect == HOLD_EFFECT_LUCKY_EGG)
                        gBattleMoveDamage = (gBattleMoveDamage * 150) / 100;

                    if (IsTradedMon(&gPlayerParty[gBattleStruct->expGetterID]))
                    {
                        gBattleMoveDamage = (gBattleMoveDamage * 110) / 100; // nerfed from vanilla
                        i = 0x14A;
                    }
                    else
                    {
                        i = 0x149;
                    }
					
					if (gBattleMoveDamage < 1)
						gBattleMoveDamage = 1;

                    // get exp getter bank
                    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                    {
                        if (!(gBattlerPartyIndexes[2] != gBattleStruct->expGetterID) && !(gAbsentBattlerFlags & gBitTable[2]))
                            gBattleStruct->expGetterBank = 2;
                        else
                        {
                            if (!(gAbsentBattlerFlags & gBitTable[0]))
                                gBattleStruct->expGetterBank = 0;
                            else
                                gBattleStruct->expGetterBank = 2;
                        }
                    }
                    else
                        gBattleStruct->expGetterBank = 0;

                    PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, gBattleStruct->expGetterBank, gBattleStruct->expGetterID)

					// buffer 'gained' or 'gained a boosted'
					PREPARE_STRING_BUFFER(gBattleTextBuff2, i)

                    PREPARE_WORD_NUMBER_BUFFER(gBattleTextBuff3, 5, gBattleMoveDamage)

                    PrepareStringBattle(STRINGID_PKMNGAINEDEXP, gBattleStruct->expGetterBank);
                    MonGainEVs(&gPlayerParty[gBattleStruct->expGetterID], gBattleMons[gBank1].species);
                }
                gBattleStruct->sentInPokes >>= 1;
                gBattleStruct->getexpStateTracker++;
            }
        }
        break;
    case 3: // Set stats and give exp
        if (gBattleExecBuffer == 0)
        {
            gBattleBufferB[gBattleStruct->expGetterBank][0] = 0;
            if (GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_HP) && GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_LEVEL) != 100)
            {
                gBattleResources_statsBeforeLvlUp->hp = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_MAX_HP);
                gBattleResources_statsBeforeLvlUp->atk = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_ATK);
                gBattleResources_statsBeforeLvlUp->def = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_DEF);
                gBattleResources_statsBeforeLvlUp->spd = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_SPEED);
                gBattleResources_statsBeforeLvlUp->spAtk = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_SPATK);
                gBattleResources_statsBeforeLvlUp->spDef = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_SPDEF);
                
                gActiveBattler = gBattleStruct->expGetterBank;

                EmitExpBarUpdate(0, gBattleStruct->expGetterID, gBattleMoveDamage);
                MarkBufferBankForExecution(gActiveBattler);
            }
            gBattleStruct->getexpStateTracker++;
        }
        break;
    case 4: // lvl up if necessary
        if (gBattleExecBuffer == 0)
        {
            gActiveBattler = gBattleStruct->expGetterBank;
            if (gBattleBufferB[gActiveBattler][0] == CONTROLLER_TWORETURNVALUES
             && gBattleBufferB[gActiveBattler][1] == RET_VALUE_LEVELLED_UP)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && gBattlerPartyIndexes[gActiveBattler] == gBattleStruct->expGetterID)
                    HandleLowHpMusicChange(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], gActiveBattler);

                PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, gActiveBattler, gBattleStruct->expGetterID)

                PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff2, 3, GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_LEVEL))

                BattleScriptPushCursor();
                gLeveledUpInBattle |= gBitTable[gBattleStruct->expGetterID];
                gBattlescriptCurrInstr = BattleScript_LevelUp;
                gBattleMoveDamage = (gBattleBufferB[gActiveBattler][2] | (gBattleBufferB[gActiveBattler][3] << 8) |
									(gBattleBufferB[gActiveBattler][4] << 16) | (gBattleBufferB[gActiveBattler][5] << 24));
                AdjustFriendship(&gPlayerParty[gBattleStruct->expGetterID], FRIENDSHIP_EVENT_GROW_LEVEL);

                // update battle mon structure after level up
                if (gBattlerPartyIndexes[0] == gBattleStruct->expGetterID && gBattleMons[0].hp)
                {
                    gBattleMons[0].level = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_LEVEL);
                    gBattleMons[0].hp = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_HP);
                    gBattleMons[0].maxHP = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_MAX_HP);
                    gBattleMons[0].attack = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_ATK);
                    gBattleMons[0].defense = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_DEF);
                    // Why is this duplicated?
                    gBattleMons[0].speed = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_SPEED);
                    gBattleMons[0].speed = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_SPEED);
                    gBattleMons[0].spAttack = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_SPATK);
                    gBattleMons[0].spDefense = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_SPDEF);
                }
                // What is else if?
                if (gBattlerPartyIndexes[2] == gBattleStruct->expGetterID && gBattleMons[2].hp && (gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
                {
                    gBattleMons[2].level = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_LEVEL);
                    gBattleMons[2].hp = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_HP);
                    gBattleMons[2].maxHP = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_MAX_HP);
                    gBattleMons[2].attack = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_ATK);
                    gBattleMons[2].defense = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_DEF);
                    // Duplicated again, but this time there's no Sp Defense
                    gBattleMons[2].speed = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_SPEED);
                    gBattleMons[2].speed = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_SPEED);
                    gBattleMons[2].spAttack = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_SPATK);
                }
            }
            else
            {
                gBattleMoveDamage = 0;
            }
            gBattleStruct->getexpStateTracker = 5;
        }
        break;
    case 5: // looper increment
        if (gBattleMoveDamage) // there is exp to give, goto case 3 that gives exp
            gBattleStruct->getexpStateTracker = 3;
        else
        {
            gBattleStruct->expGetterID++;
            if (gBattleStruct->expGetterID <= 5)
                gBattleStruct->getexpStateTracker = 2; // loop again
            else
                gBattleStruct->getexpStateTracker = 6; // we're done
        }
        break;
    case 6: // increment instruction
        if (gBattleExecBuffer == 0)
        {
            // not sure why gf clears the item and ability here
            gBattleMons[gBank1].item = 0;
            gBattleMons[gBank1].ability = 0;
            gBattlescriptCurrInstr += 2;
        }
        break;
    }
}

#ifdef NONMATCHING
static void atk24(void)
{
    u16 HP_count = 0;
    int i;
    if (gBattleExecBuffer) {return;}

    for (i = 0; i < 6; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
            HP_count += GetMonData(&gPlayerParty[i], MON_DATA_HP);
    }

    if (HP_count == 0)
        gBattleOutcome |= BATTLE_LOST;

    for (HP_count = 0, i = 0; i < 6; i++)
    {
        if (GetMonData(&gEnemyParty[i], MON_DATA_SPECIES) && !GetMonData(&gEnemyParty[i], MON_DATA_IS_EGG))
            HP_count += GetMonData(&gEnemyParty[i], MON_DATA_HP);
    }

    if (!HP_count)
        gBattleOutcome |= BATTLE_WON;

    if (!gBattleOutcome && (gBattleTypeFlags & BATTLE_TYPE_LINK))
    {
        register int found1 asm("r2");
        register int found2 asm("r4");

        //I can't for the love of god decompile that part

        for (found1 = 0, i = 0; i < gBattlersCount; i += 2)
        {
            if ((gHitMarker & HITMARKER_UNK(i)) && !gSpecialStatuses[i].flag40)
                found1++;
        }

        for (found2 = 0, i = 1; i < gBattlersCount; i += 2)
        {
            if ((gHitMarker & HITMARKER_UNK(i)) && !gSpecialStatuses[i].flag40)
                found2++;
        }

        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            if (found2 + found1 > 1)
                gBattlescriptCurrInstr = T2_READ_PTR(gBattlescriptCurrInstr + 1);
            else
                gBattlescriptCurrInstr += 5;
        }
        else
        {
            if (found2 != 0 && found1 != 0)
                gBattlescriptCurrInstr = T2_READ_PTR(gBattlescriptCurrInstr + 1);
            else
                gBattlescriptCurrInstr += 5;
        }
    }
    else
        gBattlescriptCurrInstr += 5;

}
#else
NAKED
static void atk24(void)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r8\n\
    push {r7}\n\
    movs r6, 0\n\
    ldr r0, _08020AF0 @ =gBattleExecBuffer\n\
    ldr r0, [r0]\n\
    cmp r0, 0\n\
    beq _080209C6\n\
    b _08020B46\n\
_080209C6:\n\
    movs r5, 0\n\
_080209C8:\n\
    movs r0, 0x64\n\
    adds r1, r5, 0\n\
    muls r1, r0\n\
    ldr r0, _08020AF4 @ =gPlayerParty\n\
    adds r4, r1, r0\n\
    adds r0, r4, 0\n\
    movs r1, 0xB\n\
    bl GetMonData\n\
    cmp r0, 0\n\
    beq _080209F8\n\
    adds r0, r4, 0\n\
    movs r1, 0x2D\n\
    bl GetMonData\n\
    cmp r0, 0\n\
    bne _080209F8\n\
    adds r0, r4, 0\n\
    movs r1, 0x39\n\
    bl GetMonData\n\
    adds r0, r6, r0\n\
    lsls r0, 16\n\
    lsrs r6, r0, 16\n\
_080209F8:\n\
    adds r5, 0x1\n\
    cmp r5, 0x5\n\
    ble _080209C8\n\
    cmp r6, 0\n\
    bne _08020A0C\n\
    ldr r0, _08020AF8 @ =gBattleOutcome\n\
    ldrb r1, [r0]\n\
    movs r2, 0x2\n\
    orrs r1, r2\n\
    strb r1, [r0]\n\
_08020A0C:\n\
    movs r6, 0\n\
    movs r5, 0\n\
_08020A10:\n\
    movs r0, 0x64\n\
    adds r1, r5, 0\n\
    muls r1, r0\n\
    ldr r0, _08020AFC @ =gEnemyParty\n\
    adds r4, r1, r0\n\
    adds r0, r4, 0\n\
    movs r1, 0xB\n\
    bl GetMonData\n\
    cmp r0, 0\n\
    beq _08020A40\n\
    adds r0, r4, 0\n\
    movs r1, 0x2D\n\
    bl GetMonData\n\
    cmp r0, 0\n\
    bne _08020A40\n\
    adds r0, r4, 0\n\
    movs r1, 0x39\n\
    bl GetMonData\n\
    adds r0, r6, r0\n\
    lsls r0, 16\n\
    lsrs r6, r0, 16\n\
_08020A40:\n\
    adds r5, 0x1\n\
    cmp r5, 0x5\n\
    ble _08020A10\n\
    ldr r2, _08020AF8 @ =gBattleOutcome\n\
    cmp r6, 0\n\
    bne _08020A54\n\
    ldrb r0, [r2]\n\
    movs r1, 0x1\n\
    orrs r0, r1\n\
    strb r0, [r2]\n\
_08020A54:\n\
    ldrb r0, [r2]\n\
    cmp r0, 0\n\
    bne _08020B3E\n\
    ldr r2, _08020B00 @ =gBattleTypeFlags\n\
    ldrh r1, [r2]\n\
    movs r0, 0x2\n\
    ands r0, r1\n\
    mov r8, r2\n\
    cmp r0, 0\n\
    beq _08020B3E\n\
    movs r2, 0\n\
    movs r5, 0\n\
    ldr r0, _08020B04 @ =gBattlersCount\n\
    ldrb r3, [r0]\n\
    mov r12, r0\n\
    ldr r7, _08020B08 @ =gBattlescriptCurrInstr\n\
    cmp r2, r3\n\
    bge _08020AA0\n\
    ldr r0, _08020B0C @ =gHitMarker\n\
    movs r1, 0x80\n\
    lsls r1, 21\n\
    ldr r6, [r0]\n\
    adds r4, r3, 0\n\
    ldr r3, _08020B10 @ =gSpecialStatuses\n\
_08020A84:\n\
    adds r0, r1, 0\n\
    lsls r0, r5\n\
    ands r0, r6\n\
    cmp r0, 0\n\
    beq _08020A98\n\
    ldrb r0, [r3]\n\
    lsls r0, 25\n\
    cmp r0, 0\n\
    blt _08020A98\n\
    adds r2, 0x1\n\
_08020A98:\n\
    adds r3, 0x28\n\
    adds r5, 0x2\n\
    cmp r5, r4\n\
    blt _08020A84\n\
_08020AA0:\n\
    movs r4, 0\n\
    movs r5, 0x1\n\
    mov r0, r12\n\
    ldrb r3, [r0]\n\
    cmp r5, r3\n\
    bge _08020ADA\n\
    ldr r0, _08020B0C @ =gHitMarker\n\
    movs r1, 0x80\n\
    lsls r1, 21\n\
    mov r12, r1\n\
    ldr r1, [r0]\n\
    ldr r0, _08020B10 @ =gSpecialStatuses\n\
    adds r6, r3, 0\n\
    adds r3, r0, 0\n\
    adds r3, 0x14\n\
_08020ABE:\n\
    mov r0, r12\n\
    lsls r0, r5\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _08020AD2\n\
    ldrb r0, [r3]\n\
    lsls r0, 25\n\
    cmp r0, 0\n\
    blt _08020AD2\n\
    adds r4, 0x1\n\
_08020AD2:\n\
    adds r3, 0x28\n\
    adds r5, 0x2\n\
    cmp r5, r6\n\
    blt _08020ABE\n\
_08020ADA:\n\
    mov r0, r8\n\
    ldrh r1, [r0]\n\
    movs r0, 0x40\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _08020B14\n\
    adds r0, r4, r2\n\
    cmp r0, 0x1\n\
    bgt _08020B1C\n\
    b _08020B36\n\
    .align 2, 0\n\
_08020AF0: .4byte gBattleExecBuffer\n\
_08020AF4: .4byte gPlayerParty\n\
_08020AF8: .4byte gBattleOutcome\n\
_08020AFC: .4byte gEnemyParty\n\
_08020B00: .4byte gBattleTypeFlags\n\
_08020B04: .4byte gBattlersCount\n\
_08020B08: .4byte gBattlescriptCurrInstr\n\
_08020B0C: .4byte gHitMarker\n\
_08020B10: .4byte gSpecialStatuses\n\
_08020B14:\n\
    cmp r4, 0\n\
    beq _08020B36\n\
    cmp r2, 0\n\
    beq _08020B36\n\
_08020B1C:\n\
    ldr r2, [r7]\n\
    ldrb r1, [r2, 0x1]\n\
    ldrb r0, [r2, 0x2]\n\
    lsls r0, 8\n\
    adds r1, r0\n\
    ldrb r0, [r2, 0x3]\n\
    lsls r0, 16\n\
    adds r1, r0\n\
    ldrb r0, [r2, 0x4]\n\
    lsls r0, 24\n\
    adds r1, r0\n\
    str r1, [r7]\n\
    b _08020B46\n\
_08020B36:\n\
    ldr r0, [r7]\n\
    adds r0, 0x5\n\
    str r0, [r7]\n\
    b _08020B46\n\
_08020B3E:\n\
    ldr r1, _08020B50 @ =gBattlescriptCurrInstr\n\
    ldr r0, [r1]\n\
    adds r0, 0x5\n\
    str r0, [r1]\n\
_08020B46:\n\
    pop {r3}\n\
    mov r8, r3\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .align 2, 0\n\
_08020B50: .4byte gBattlescriptCurrInstr\n\
        .syntax divided\n");
}
#endif

static void MoveValuesCleanUp(void)
{
    gMoveResultFlags = 0;
    gBattleStruct->dmgMultiplier = 1;
    gCritMultiplier = 1;
    gBattleCommunication[MOVE_EFFECT_BYTE] = 0;
    gBattleCommunication[6] = 0;
    gHitMarker &= ~(HITMARKER_DESTINYBOND);
    gHitMarker &= ~(HITMARKER_SYNCHRONISE_EFFECT);
}

static void atk25_movevaluescleanup(void)
{
    MoveValuesCleanUp();
    gBattlescriptCurrInstr += 1;
}

static void atk26_setmultihit(void)
{
    gMultiHitCounter = T2_READ_8(gBattlescriptCurrInstr + 1);
    gBattlescriptCurrInstr += 2;
}

static void atk27_decrementmultihit(void)
{
    if (--gMultiHitCounter == 0)
        gBattlescriptCurrInstr += 5;
    else
        gBattlescriptCurrInstr = T2_READ_PTR(gBattlescriptCurrInstr + 1);
}

static void atk28_goto(void)
{
    gBattlescriptCurrInstr = T2_READ_PTR(gBattlescriptCurrInstr + 1);
}

static void atk29_jumpifbyte(void)
{
    u8 caseID = T2_READ_8(gBattlescriptCurrInstr + 1);
    u8* ptr = T2_READ_PTR(gBattlescriptCurrInstr + 2);
    u8 value = T2_READ_8(gBattlescriptCurrInstr + 6);
    u8* jump_loc = T2_READ_PTR(gBattlescriptCurrInstr + 7);
    gBattlescriptCurrInstr += 11;
    switch (caseID)
    {
    case CMP_EQUAL:
        if (*ptr == value)
            gBattlescriptCurrInstr = jump_loc;
        break;
    case CMP_NOT_EQUAL:
        if (*ptr != value)
            gBattlescriptCurrInstr = jump_loc;
        break;
    case CMP_GREATER_THAN:
        if (*ptr > value)
            gBattlescriptCurrInstr = jump_loc;
        break;
    case CMP_LESS_THAN:
        if (*ptr < value)
            gBattlescriptCurrInstr = jump_loc;
        break;
    case CMP_COMMON_BITS:
        if (*ptr & value)
            gBattlescriptCurrInstr = jump_loc;
        break;
    case CMP_NO_COMMON_BITS:
        if (!(*ptr & value))
            gBattlescriptCurrInstr = jump_loc;
        break;
    }
}

static void atk2A_jumpifhalfword(void)
{
    u8 caseID = T2_READ_8(gBattlescriptCurrInstr + 1);
    u16* ptr = T2_READ_PTR(gBattlescriptCurrInstr + 2);
    u16 value = T2_READ_16(gBattlescriptCurrInstr + 6);
    u8* jump_loc = T2_READ_PTR(gBattlescriptCurrInstr + 8);
    gBattlescriptCurrInstr += 12;
    switch (caseID)
    {
    case CMP_EQUAL:
        if (*ptr == value)
            gBattlescriptCurrInstr = jump_loc;
        break;
    case CMP_NOT_EQUAL:
        if (*ptr != value)
            gBattlescriptCurrInstr = jump_loc;
        break;
    case CMP_GREATER_THAN:
        if (*ptr > value)
            gBattlescriptCurrInstr = jump_loc;
        break;
    case CMP_LESS_THAN:
        if (*ptr < value)
            gBattlescriptCurrInstr = jump_loc;
        break;
    case CMP_COMMON_BITS:
        if (*ptr & value)
            gBattlescriptCurrInstr = jump_loc;
        break;
    case CMP_NO_COMMON_BITS:
        if (!(*ptr & value))
            gBattlescriptCurrInstr = jump_loc;
        break;
    }
}

// Strange that there's an instance of T1_READ_32 in what seems to be a T2 function. see global.h for the distinction.
static void atk2B_jumpifword(void)
{
    u8 caseID = T2_READ_8(gBattlescriptCurrInstr + 1);
    u32* ptr = T2_READ_PTR(gBattlescriptCurrInstr + 2);
    u32 value = T1_READ_32(gBattlescriptCurrInstr + 6);
    u8* jump_loc = T2_READ_PTR(gBattlescriptCurrInstr + 10);
    gBattlescriptCurrInstr += 14;
    switch (caseID)
    {
    case CMP_EQUAL:
        if (*ptr == value)
            gBattlescriptCurrInstr = jump_loc;
        break;
    case CMP_NOT_EQUAL:
        if (*ptr != value)
            gBattlescriptCurrInstr = jump_loc;
        break;
    case CMP_GREATER_THAN:
        if (*ptr > value)
            gBattlescriptCurrInstr = jump_loc;
        break;
    case CMP_LESS_THAN:
        if (*ptr < value)
            gBattlescriptCurrInstr = jump_loc;
        break;
    case CMP_COMMON_BITS:
        if (*ptr & value)
            gBattlescriptCurrInstr = jump_loc;
        break;
    case CMP_NO_COMMON_BITS:
        if (!(*ptr & value))
            gBattlescriptCurrInstr = jump_loc;
        break;
    }
}

static void atk2C_jumpifarrayequal(void)
{
    //Mem1, Mem2, Size, Jump Loc
    u8* mem1 = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    u8* mem2 = T2_READ_PTR(gBattlescriptCurrInstr + 5);
    u32 size = T2_READ_8(gBattlescriptCurrInstr + 9);
    u8* jump_loc = T2_READ_PTR(gBattlescriptCurrInstr + 10);

    u8 i;
    for (i = 0; i < size; i++)
    {
        if (*mem1 != *mem2)
        {
            gBattlescriptCurrInstr += 14;
            break;
        }
        mem1++, mem2++;
    }

    if (i == size)
        gBattlescriptCurrInstr = jump_loc;
}

static void atk2D_jumpifarraynotequal(void)
{
    //Mem1, Mem2, Size, Jump Loc
    u8 equal_bytes = 0;
    u8* mem1 = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    u8* mem2 = T2_READ_PTR(gBattlescriptCurrInstr + 5);
    u32 size = T2_READ_8(gBattlescriptCurrInstr + 9);
    u8* jump_loc = T2_READ_PTR(gBattlescriptCurrInstr + 10);

    u8 i;
    for (i = 0; i < size; i++)
    {
        if (*mem1 == *mem2)
        {
            equal_bytes++;
        }
        mem1++, mem2++;
    }

    if (equal_bytes != size)
        gBattlescriptCurrInstr = jump_loc;
    else
        gBattlescriptCurrInstr += 14;
}

static void atk2E_setbyte(void)
{
    u8* mem = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    *mem = T2_READ_8(gBattlescriptCurrInstr + 5);
    gBattlescriptCurrInstr += 6;
}

static void atk2F_addbyte(void)
{
    u8* mem = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    *mem += T2_READ_8(gBattlescriptCurrInstr + 5);
    gBattlescriptCurrInstr += 6;
}

static void atk30_subbyte(void)
{
    u8* mem = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    *mem -= T2_READ_8(gBattlescriptCurrInstr + 5);
    gBattlescriptCurrInstr += 6;
}

static void atk31_copyarray(void)
{
    u8* mem1 = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    u8* mem2 = T2_READ_PTR(gBattlescriptCurrInstr + 5);
    s32 size = T2_READ_8(gBattlescriptCurrInstr + 9);

    s32 i;
    for (i = 0; i < size; i++)
    {
        mem1[i] = mem2[i];
    }

    gBattlescriptCurrInstr += 10;
}

static void atk32_copyarraywithindex(void)
{
    u8* mem1 = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    u8* mem2 = T2_READ_PTR(gBattlescriptCurrInstr + 5);
    u8* index = T2_READ_PTR(gBattlescriptCurrInstr + 9);
    s32 size = T2_READ_8(gBattlescriptCurrInstr + 13);

    s32 i;
    for (i = 0; i < size; i++)
    {
        mem1[i] = mem2[i + *index];
    }

    gBattlescriptCurrInstr += 14;
}

static void atk33_orbyte(void)
{
    u8* mem = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    *mem |= T2_READ_8(gBattlescriptCurrInstr + 5);
    gBattlescriptCurrInstr += 6;
}

static void atk34_orhalfword(void)
{
    u16* mem = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    u16 val = T2_READ_16(gBattlescriptCurrInstr + 5);

    *mem |= val;
    gBattlescriptCurrInstr += 7;
}

static void atk35_orword(void)
{
    u32* mem = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    u32 val = T2_READ_32(gBattlescriptCurrInstr + 5);

    *mem |= val;
    gBattlescriptCurrInstr += 9;
}

static void atk36_bicbyte(void)
{
    u8* mem = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    *mem &= ~(T2_READ_8(gBattlescriptCurrInstr + 5));
    gBattlescriptCurrInstr += 6;
}

static void atk37_bichalfword(void)
{
    u16* mem = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    u16 val = T2_READ_16(gBattlescriptCurrInstr + 5);

    *mem &= ~val;
    gBattlescriptCurrInstr += 7;
}

static void atk38_bicword(void)
{
    u32* mem = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    u32 val = T2_READ_32(gBattlescriptCurrInstr + 5);

    *mem &= ~val;
    gBattlescriptCurrInstr += 9;
}

static void atk39_pause(void)
{
    if (gBattleExecBuffer == 0)
    {
        u16 value = T2_READ_16(gBattlescriptCurrInstr + 1);
        if (++gPauseCounterBattle >= value)
        {
            gPauseCounterBattle = 0;
            gBattlescriptCurrInstr += 3;
        }
    }
}

static void atk3A_waitstate(void)
{
    if (gBattleExecBuffer == 0)
        gBattlescriptCurrInstr++;
}

static void atk3B_healthbar_update(void)
{
    if (!T2_READ_8(gBattlescriptCurrInstr + 1))
        gActiveBattler = gBankTarget;
    else
        gActiveBattler = gBankAttacker;

    EmitHealthBarUpdate(0, gBattleMoveDamage);
    MarkBufferBankForExecution(gActiveBattler);
    gBattlescriptCurrInstr += 2;
}

static void atk3C_return(void)
{
    BattleScriptPop();
}

static void atk3D_end(void)
{
	gBattleStruct->meFirstTracker = 0;
    gMoveResultFlags = 0;
    gActiveBattler = 0;
    gCurrentActionFuncId = 0xB;
}

static void atk3E_end2(void)
{
    //not much difference between this and 3D. It's more apparent in Emerald
    gActiveBattler = 0;
    gCurrentActionFuncId = 0xB;
}

static void atk3F_end3(void) //pops the main function stack
{
    BattleScriptPop();
    if (B_FUNCTION_STACK->size)
        B_FUNCTION_STACK->size--;
    gBattleMainFunc = B_FUNCTION_STACK->ptr[B_FUNCTION_STACK->size];
}

static void atk41_call(void)
{
    BattleScriptPush(gBattlescriptCurrInstr + 5);
    gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
}

static void atk42_jumpiftype2(void) //u8 bank, u8 type, *ptr
{
    u8 bank = GetBattleBank(T1_READ_8(gBattlescriptCurrInstr + 1));

    if (T1_READ_8(gBattlescriptCurrInstr + 2) == gBattleMons[bank].type1 || T1_READ_8(gBattlescriptCurrInstr + 2) == gBattleMons[bank].type2)
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
    else
        gBattlescriptCurrInstr += 7;
}

static void atk43_jumpifabilitypresent(void)
{
    if (AbilityBattleEffects(ABILITYEFFECT_CHECK_ON_FIELD, 0, T2_READ_8(gBattlescriptCurrInstr + 1), 0, 0))
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 2);
    else
        gBattlescriptCurrInstr += 6;
}

static void atk44_endselectionscript(void)
{
    ewram16060(gBankAttacker) = 1;
}

static void atk45_playanimation(void)
{
    const u16* argumentPtr;

    gActiveBattler = GetBattleBank(gBattlescriptCurrInstr[1]);
    argumentPtr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 3);
    
    
    if (gBattlescriptCurrInstr[2] == B_ANIM_STATS_CHANGE &&
        gBattleMons[gActiveBattler].ability == ABILITY_CONTRARY)
    {
        switch (gBattleStruct->animArg1)
        {
            case 0xF ... 0x15: gBattleStruct->animArg1 += 7; break;
            case 0x16 ... 0x1C: gBattleStruct->animArg1 -= 7; break;
            case 0x27 ... 0x2D: gBattleStruct->animArg1 += 7; break;
            case 0x2E ... 0x34: gBattleStruct->animArg1 -= 7; break;
            
            case 0x37 ... 0x38: gBattleStruct->animArg1 += 2; break;
            case 0x39 ... 0x3A: gBattleStruct->animArg1 -= 2; break;
        }
    }

    if (gBattlescriptCurrInstr[2] == B_ANIM_STATS_CHANGE
        || gBattlescriptCurrInstr[2] == B_ANIM_SNATCH_MOVE
        || gBattlescriptCurrInstr[2] == B_ANIM_SUBSTITUTE_FADE)
    {
        EmitBattleAnimation(0, gBattlescriptCurrInstr[2], *argumentPtr);
        MarkBufferBankForExecution(gActiveBattler);
        gBattlescriptCurrInstr += 7;
    }
    else if (gHitMarker & HITMARKER_NO_ANIMATIONS)
    {
        BattleScriptPush(gBattlescriptCurrInstr + 7);
        gBattlescriptCurrInstr = BattleScript_Pausex20;
    }
    else if (gBattlescriptCurrInstr[2] == B_ANIM_RAIN_CONTINUES
             || gBattlescriptCurrInstr[2] == B_ANIM_SUN_CONTINUES
             || gBattlescriptCurrInstr[2] == B_ANIM_SANDSTORM_CONTINUES
             || gBattlescriptCurrInstr[2] == B_ANIM_HAIL_CONTINUES)
    {
        EmitBattleAnimation(0, gBattlescriptCurrInstr[2], *argumentPtr);
        MarkBufferBankForExecution(gActiveBattler);
        gBattlescriptCurrInstr += 7;
    }
    else if (gStatuses3[gActiveBattler] & STATUS3_SEMI_INVULNERABLE)
    {
        gBattlescriptCurrInstr += 7;
    }
    else
    {
        EmitBattleAnimation(0, gBattlescriptCurrInstr[2], *argumentPtr);
        MarkBufferBankForExecution(gActiveBattler);
        gBattlescriptCurrInstr += 7;
    }
}

static void atk46_playanimation2(void) // animation Id is stored in the first pointer
{
    const u16* argumentPtr;
    const u8* animationIdPtr;

    gActiveBattler = GetBattleBank(gBattlescriptCurrInstr[1]);
    animationIdPtr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 2);
    argumentPtr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 6);

    if (*animationIdPtr == B_ANIM_STATS_CHANGE
        || *animationIdPtr == B_ANIM_SNATCH_MOVE
        || *animationIdPtr == B_ANIM_SUBSTITUTE_FADE)
    {
        EmitBattleAnimation(0, *animationIdPtr, *argumentPtr);
        MarkBufferBankForExecution(gActiveBattler);
        gBattlescriptCurrInstr += 10;
    }
    else if (gHitMarker & HITMARKER_NO_ANIMATIONS)
    {
        gBattlescriptCurrInstr += 10;
    }
    else if (*animationIdPtr == B_ANIM_RAIN_CONTINUES
             || *animationIdPtr == B_ANIM_SUN_CONTINUES
             || *animationIdPtr == B_ANIM_SANDSTORM_CONTINUES
             || *animationIdPtr == B_ANIM_HAIL_CONTINUES)
    {
        EmitBattleAnimation(0, *animationIdPtr, *argumentPtr);
        MarkBufferBankForExecution(gActiveBattler);
        gBattlescriptCurrInstr += 10;
    }
    else if (gStatuses3[gActiveBattler] & STATUS3_SEMI_INVULNERABLE)
    {
        gBattlescriptCurrInstr += 10;
    }
    else
    {
        EmitBattleAnimation(0, *animationIdPtr, *argumentPtr);
        MarkBufferBankForExecution(gActiveBattler);
        gBattlescriptCurrInstr += 10;
    }
}

static void atk47_setgraphicalstatchangevalues(void)
{
    u8 to_add = 0;
    switch (gBattleStruct->statChanger & 0xF0)
    {
    case 0x10: //+1
        to_add = 0xF;
        break;
    case 0x20: //+2
	case 0x30: //+3
        to_add = 0x27;
        break;
    case 0x90: //-1
        to_add = 0x16;
        break;
    case 0xA0: //-2
        to_add = 0x2E;
        break;
    }
    gBattleStruct->animArg1 = (gBattleStruct->statChanger & 0xF) + to_add - 1;
    gBattleStruct->animArg2 = 0;
    gBattlescriptCurrInstr++;
}

static void atk48_playstatchangeanimation(void)
{
    int curr_stat = 0;
    u16 stat_animID = 0;
    int changeable_stats = 0;
    u32 stats_to_check;
    u8 arg3;

    gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
    stats_to_check = T2_READ_8(gBattlescriptCurrInstr + 2);
    arg3 = T2_READ_8(gBattlescriptCurrInstr + 3);
    
    if (gBattleMons[gActiveBattler].ability == ABILITY_CONTRARY)
        arg3 ^= 0x1;
    
    if (arg3 & 1)
    {
        u16 r1 = 0x15;
        if (arg3 & 0x2)
            r1 = 0x2D;
        while (stats_to_check != 0)
        {
            if (stats_to_check & 1)
            {
                if (!(arg3 & 0x8))
                {
                    u8 ability = gBattleMons[gActiveBattler].ability;
                    if (!gSideTimers[GetBattlerPosition(gActiveBattler) & 1].mistTimer)
                    {
                        if (ability != ABILITY_CLEAR_BODY && ability != ABILITY_WHITE_SMOKE &&
                           !(ability == ABILITY_KEEN_EYE && curr_stat == 6) && !(ability == ABILITY_HYPER_CUTTER && curr_stat == 1) &&
                           !(ability == ABILITY_BIG_PECKS && curr_stat == 2))
                        {
                            if (gBattleMons[gActiveBattler].statStages[curr_stat] > 0)
                            {
                                stat_animID = r1 + curr_stat;
                                changeable_stats++;
                            }
                        }
                    }
                }
                else if (gBattleMons[gActiveBattler].statStages[curr_stat] > 0)
                {
                    stat_animID = r1 + curr_stat;
                    changeable_stats++;
                }
            }

            stats_to_check >>= 1;
            curr_stat++;
        }
        if (changeable_stats > 1)
        {
            if (arg3 & 2)
                stat_animID = 0x3A;
            else
                stat_animID = 0x39;
        }
    }
    else
    {
        u16 r1 = 0xE;
        if (arg3 & 0x2)
            r1 = 0x26;
        while (stats_to_check != 0)
        {
            if (stats_to_check & 1)
            {
                if (gBattleMons[gActiveBattler].statStages[curr_stat] < 0xC)
                {
                    stat_animID = r1 + curr_stat;
                    changeable_stats++;
                }
            }

            stats_to_check >>= 1;
            curr_stat++;
        }
        if (changeable_stats > 1)
        {
            if (arg3 & 2)
                stat_animID = 0x38;
            else
                stat_animID = 0x37;
        }
    }
    
    if ((arg3 & 4) && changeable_stats <= 1)
    {
        gBattlescriptCurrInstr += 4;
    }
    else if (changeable_stats != 0 && !(gBattleStruct->unk160DC))
    {
        EmitBattleAnimation(0, 1, stat_animID);
        MarkBufferBankForExecution(gActiveBattler);
        if ((arg3 & 4) && changeable_stats > 1)
            gBattleStruct->unk160DC = 1;
        gBattlescriptCurrInstr += 4;
    }
    else
    {
        gBattlescriptCurrInstr += 4;
    }
}


#define ATK49_LAST_CASE 20

static void atk49_moveend(void)
{
    int i;
    u8 abort = 0;
    int effect = 0;
    u16 last_move = 0, *choiced_move_atk;
    int arg1, arg2, hold_effect_atk, move_type;
    if (gChosenMove != 0xFFFF)
        last_move = gChosenMove;

    arg1 = T2_READ_8(gBattlescriptCurrInstr + 1);
    arg2 = T2_READ_8(gBattlescriptCurrInstr + 2);
    if (gBattleMons[gBankAttacker].item == ITEM_ENIGMA_BERRY)
        hold_effect_atk = gEnigmaBerries[gBankAttacker].holdEffect;
    else
        hold_effect_atk = ItemId_GetHoldEffect(gBattleMons[gBankAttacker].item);

    choiced_move_atk = &((u16*)(gSharedMem + 0x160E8))[gBankAttacker];
    if (gBattleStruct->dynamicMoveType)
        move_type = gBattleStruct->dynamicMoveType & 0x3F;
    else
        move_type = gBattleMoves[gCurrentMove].type;

    do
    {
        switch (gBattleStruct->cmd49StateTracker)
        {
        case 0: //rage check
            if (gBattleMons[gBankTarget].status2 & STATUS2_RAGE
                && gBattleMons[gBankTarget].hp && gBankAttacker != gBankTarget
                && GetBattlerSide(gBankAttacker) != GetBattlerSide(gBankTarget)
                && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) && TARGET_TURN_DAMAGED
                && gBattleMoves[gCurrentMove].power && gBattleMons[gBankTarget].statStages[STAT_STAGE_ATK] <= 0xB)
            {
                gBattleMons[gBankTarget].statStages[STAT_STAGE_ATK]++;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_RageIsBuilding;
                effect = 1;
            }
            gBattleStruct->cmd49StateTracker++;
            break;
        case 1: //defrosting check
            if (gBattleMons[gBankTarget].status1 & STATUS_FREEZE
                && gBattleMons[gBankTarget].hp && gBankAttacker != gBankTarget
                && gSpecialStatuses[gBankTarget].moveturnLostHP
                && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) && move_type == TYPE_FIRE)
            {
                gBattleMons[gBankTarget].status1 &= ~(STATUS_FREEZE);
                gActiveBattler = gBankTarget;
                EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gBankTarget].status1);
                MarkBufferBankForExecution(gActiveBattler);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_DefrostedViaFireMove;
                effect = 1;
            }
            gBattleStruct->cmd49StateTracker++;
            break;
		case 2: //attack rider abilities
            if (AbilityBattleEffects(ABILITYEFFECT_RIDER, gBankAttacker, 0, 0, 0))
                effect = 1;
            gBattleStruct->cmd49StateTracker++;
            break;
        case 3: //target synchronize
            if (AbilityBattleEffects(ABILITYEFFECT_SYNCHRONIZE, gBankTarget, 0, 0, 0))
                effect = 1;
            gBattleStruct->cmd49StateTracker++;
            break;
        case 4: //defender contact abilities
            if (AbilityBattleEffects(ABILITYEFFECT_CONTACT, gBankTarget, 0, 0, 0))
                effect = 1;
            gBattleStruct->cmd49StateTracker++;
            break;
        case 5: //status immunities
            if (AbilityBattleEffects(ABILITYEFFECT_IMMUNITY, 0, 0, 0, 0))
                effect = 1; //it loops through 4 banks, so we increment after its done with all banks
            else
                gBattleStruct->cmd49StateTracker++;
            break;
        case 6: //attacker synchronize
            if (AbilityBattleEffects(ABILITYEFFECT_ATK_SYNCHRONIZE, gBankAttacker, 0, 0, 0))
                effect = 1;
            gBattleStruct->cmd49StateTracker++;
            break;
        case 7: //update choice band move
            if (gHitMarker & HITMARKER_OBEYS && hold_effect_atk == HOLD_EFFECT_CHOICE_BAND
                && gChosenMove != MOVE_STRUGGLE && (*choiced_move_atk == 0 || *choiced_move_atk == 0xFFFF)
                && gChosenMove != MOVE_BATON_PASS && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
            {
                *choiced_move_atk = gChosenMove;
                for (i = 0; i < 4 && gBattleMons[gBankAttacker].moves[i] != *choiced_move_atk; i++){}
                if (i == 4)
                    *choiced_move_atk = 0;
            }
            gBattleStruct->cmd49StateTracker++;
            break;
        case 8: //changed held items
            for (i = 0; i < gBattlersCount; i++)
            {
				u16* changedItem = &gBattleStruct->changedItems[i];
				if (*changedItem)
				{
					gBattleMons[i].item = *changedItem;
				}
            }
            gBattleStruct->cmd49StateTracker++;
            break;
        case 9: //make sprite invisible
            if (gStatuses3[gBankAttacker] & (STATUS3_SEMI_INVULNERABLE)
                && !(gHitMarker & HITMARKER_NO_ANIMATIONS))
            {
                gActiveBattler = gBankAttacker;
                EmitSpriteInvisibility(0, 1);
                MarkBufferBankForExecution(gActiveBattler);
            }
            gBattleStruct->cmd49StateTracker++;
            break;
        case 10: //semi-invlurneable attacker make visible
            if ((gMoveResultFlags & MOVE_RESULT_NO_EFFECT) || !(gStatuses3[gBankAttacker] & (STATUS3_SEMI_INVULNERABLE))
                || WasUnableToUseMove(gBankAttacker))
                {
                    gActiveBattler = gBankAttacker;
                    EmitSpriteInvisibility(0, 0);
                    MarkBufferBankForExecution(gActiveBattler);
                    gStatuses3[gActiveBattler] &= ~(STATUS3_SEMI_INVULNERABLE);
                    gSpecialStatuses[gBankAttacker].restoredBankSprite = 1;
                }
            gBattleStruct->cmd49StateTracker++;
            break;
        case 11: //semi-invulnerable target make visible
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) || !(gStatuses3[gBankTarget] & (STATUS3_SEMI_INVULNERABLE))
                || WasUnableToUseMove(gBankTarget))
                {
                    gActiveBattler = gBankTarget;
                    EmitSpriteInvisibility(0, 0);
                    MarkBufferBankForExecution(gActiveBattler);
                    gStatuses3[gActiveBattler] &= ~(STATUS3_SEMI_INVULNERABLE);
                    gSpecialStatuses[gBankTarget].restoredBankSprite = 1;
                }
            gBattleStruct->cmd49StateTracker++;
            break;
        case 12: // item effects for all battlers
			if (ItemBattleEffects(3, 0, FALSE))
				effect = TRUE;
			else
				gBattleStruct->cmd49StateTracker++;
			break;
		case 13: // king's rock, shell bell
			if (ItemBattleEffects(4, 0, FALSE))
				effect = TRUE;
			else
				gBattleStruct->cmd49StateTracker++;
			break;
		case 14: // update substitute
			for (i = 0; i < gBattlersCount; i++)
			{
				if (gDisableStructs[i].substituteHP == 0)
					gBattleMons[i].status2 &= ~(STATUS2_SUBSTITUTE);
			}
			gBattleStruct->cmd49StateTracker++;
			break;
		case 15: // weird
			if (gHitMarker & HITMARKER_PURSUIT_TRAP)
			{
				gActiveBattler = gBankAttacker;
				gBankAttacker = gBankTarget;
				gBankTarget = gActiveBattler;
				gHitMarker &= ~(HITMARKER_PURSUIT_TRAP);
			}
			if (gHitMarker & HITMARKER_ATTACKSTRING_PRINTED)
			{
				gUnknown_02024C2C[gBankAttacker] = gChosenMove;
			}
			if (!(gAbsentBattlerFlags & gBitTable[gBankAttacker])
				&& !(gBattleStruct->unk160A6 & gBitTable[gBankAttacker])
				&& gBattleMoves[last_move].effect != EFFECT_BATON_PASS)
			{
				if (gHitMarker & HITMARKER_OBEYS)
				{
					gLastUsedMove[gBankAttacker] = gChosenMove;
					gUnknown_02024C4C[gBankAttacker] = gCurrentMove;
				}
				else
				{
					gLastUsedMove[gBankAttacker] = 0xFFFF;
					gUnknown_02024C4C[gBankAttacker] = 0xFFFF;
				}
				
				if (!(gHitMarker & HITMARKER_FAINTED(gBankTarget)))
					gLastHitBy[gBankTarget] = gBankAttacker;
				
				if (gHitMarker & HITMARKER_OBEYS && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
				{
					if (gChosenMove == 0xFFFF)
					{
						gLastLandedMoves[gBankTarget] = gChosenMove;
					}
					else
					{
						gLastLandedMoves[gBankTarget] = gCurrentMove;
						GET_MOVE_TYPE(gCurrentMove, gLastHitByType[gBankTarget]);
					}
				}
				else
				{
					gLastLandedMoves[gBankTarget] = 0xFFFF;
				}
			}
			gBattleStruct->cmd49StateTracker++;
			break;
		case 16: // mirror move
			if (!(gAbsentBattlerFlags & gBitTable[gBankAttacker]) && !(gBattleStruct->unk160A6 & gBitTable[gBankAttacker])
				&& gBattleMoves[last_move].flags & F_MIRROR_MOVE_COMPATIBLE && gHitMarker & HITMARKER_OBEYS
				&& gBankAttacker != gBankTarget &&  !(gHitMarker & HITMARKER_FAINTED(gBankTarget))
				&& !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
			{
				u8 target, attacker;
				
				*(gBattleStruct->mirrorMoves + gBankTarget * 2 + 0) = gChosenMove;
				*(gBattleStruct->mirrorMoves + gBankTarget * 2 + 1) = gChosenMove >> 8;
				
				target = gBankTarget;
				attacker = gBankAttacker;
				*((attacker >> 1 << 1) + target * 4 + (u8*)(gBattleStruct->mirrorMoveArrays) + 0) = gChosenMove;
				*((attacker >> 1 << 1) + target * 4 + (u8*)(gBattleStruct->mirrorMoveArrays) + 1) = gChosenMove >> 8;
			}
			gBattleStruct->cmd49StateTracker++;
			break;
		case 17: // loop back around for spread moves, maybe
			if (!(gHitMarker & HITMARKER_UNABLE_TO_USE_MOVE) && gBattleTypeFlags & BATTLE_TYPE_DOUBLE
			&& !gProtectStructs[gBankAttacker].chargingTurn && gBattleMoves[gCurrentMove].target == TARGET_BOTH_ENEMIES
			&& !(gHitMarker & HITMARKER_NO_ATTACKSTRING))
			{
				u8 battlerId = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gBankTarget)));
				if (gBattleMons[battlerId].hp != 0)
				{
					gBankTarget = battlerId;
					gHitMarker |= HITMARKER_NO_ATTACKSTRING;
					gBattleStruct->cmd49StateTracker = 0;
					MoveValuesCleanUp();
					BattleScriptPush(gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect]);
					gBattlescriptCurrInstr = gUnknown_081D9B2D;
					return;
				}
				else
				{
					gHitMarker |= HITMARKER_NO_ATTACKSTRING;
				}
			}
			gBattleStruct->cmd49StateTracker++;
			break;
        case 18: // life orb
			if (ItemBattleEffects(5, 0, FALSE))
				effect = TRUE;
			gBattleStruct->cmd49StateTracker++;
			break;
		case 19:
			gWishFutureKnock.reflected = 0;
			gWishFutureKnock.pranksterBoosted = 0;
			gBattleStruct->cmd49StateTracker++;
			break;
		case ATK49_LAST_CASE:
			break;
		}
		
		if (arg1 == 1 && effect == FALSE)
			gBattleStruct->cmd49StateTracker = ATK49_LAST_CASE;
		if (arg1 == 2 && arg2 == gBattleStruct->cmd49StateTracker)
			abort = 1; //gBattleStruct->cmd49StateTracker = ATK49_LAST_CASE;

    } while (gBattleStruct->cmd49StateTracker != ATK49_LAST_CASE && effect == FALSE && !abort);
	
	if ((gBattleStruct->cmd49StateTracker == ATK49_LAST_CASE && effect == FALSE) || abort)
		gBattlescriptCurrInstr += 3;
}

static void atk4A_typecalc2(void)
{
    u8 flags = 0;
    u8 typemu = 0;
    u8 move_type = gBattleMoves[gCurrentMove].type;
	u8 defenderAbility;
	
	defenderAbility = gBattleMons[gBankTarget].ability;
	if (gBattleMons[gBankAttacker].ability == ABILITY_MOLD_BREAKER)
		defenderAbility = 0;

    if (defenderAbility == ABILITY_LEVITATE && move_type == TYPE_GROUND)
    {
        gLastUsedAbility = gBattleMons[gBankTarget].ability;
        gMoveResultFlags |= (MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE);
        gLastLandedMoves[gBankTarget] = 0;
        gBattleCommunication[6] = move_type;
        RecordAbilityBattle(gBankTarget, gLastUsedAbility);
    }
    else
    {
		typemu = gTypeEffectiveness[move_type * 20 + gBattleMons[gBankTarget].type1];
		if (typemu == 1 && !(gBattleMons[gBankTarget].status2 & STATUS2_FORESIGHT || gBattleMons[gBankAttacker].ability == ABILITY_SCRAPPY))
			typemu = 0;
		else if (typemu == 2 && !(gStatuses3[gBankTarget] & STATUS3_MIRACLE_EYE))
			typemu = 0;
		if (gCurrentMove == MOVE_FREEZE_DRY && gBattleMons[gBankTarget].type1 == TYPE_WATER)
			typemu = 20;
		
		if (typemu == 0)
            gMoveResultFlags |= MOVE_RESULT_DOESNT_AFFECT_FOE;
		else if (typemu == 5)
			gMoveResultFlags |= MOVE_RESULT_NOT_VERY_EFFECTIVE;
		else if (typemu == 20)
			gMoveResultFlags |= MOVE_RESULT_SUPER_EFFECTIVE;
		typemu = gTypeEffectiveness[move_type * 20 + gBattleMons[gBankTarget].type2];
		
		if (typemu == 1 && !(gBattleMons[gBankTarget].status2 & STATUS2_FORESIGHT || gBattleMons[gBankAttacker].ability == ABILITY_SCRAPPY))
			typemu = 0;
		else if (typemu == 2 && !(gStatuses3[gBankTarget] & STATUS3_MIRACLE_EYE))
			typemu = 0;
		if (gCurrentMove == MOVE_FREEZE_DRY && gBattleMons[gBankTarget].type2 == TYPE_WATER)
			typemu = 20;
		
		if (typemu == 0)
            gMoveResultFlags |= MOVE_RESULT_DOESNT_AFFECT_FOE;
		else if (typemu == 5)
			gMoveResultFlags |= MOVE_RESULT_NOT_VERY_EFFECTIVE;
		else if (typemu == 20)
			gMoveResultFlags |= MOVE_RESULT_SUPER_EFFECTIVE;
    }

    if (defenderAbility == ABILITY_WONDER_GUARD && !(flags & MOVE_RESULT_NO_EFFECT) && AttacksThisTurn(gBankAttacker, gCurrentMove) == 2 &&
        (!(flags & MOVE_RESULT_SUPER_EFFECTIVE) || ((flags & (MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE)) == (MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE))) &&
        gBattleMoves[gCurrentMove].power)
    {
        gLastUsedAbility = ABILITY_WONDER_GUARD;
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gLastLandedMoves[gBankTarget] = 0;
        gBattleCommunication[6] = 3;
        RecordAbilityBattle(gBankTarget, gLastUsedAbility);
    }
    if (gMoveResultFlags & MOVE_RESULT_DOESNT_AFFECT_FOE)
        gProtectStructs[gBankAttacker].notEffective = 1;

    gBattlescriptCurrInstr++;
}

static void atk4B_returnatktoball(void)
{
    gActiveBattler = gBankAttacker;
    if (!(gHitMarker & HITMARKER_FAINTED(gActiveBattler)))
    {
        EmitReturnPokeToBall(0, 0);
        MarkBufferBankForExecution(gActiveBattler);
    }
    gBattlescriptCurrInstr++;
}

static void atk4C_getswitchedmondata(void)
{
    if (gBattleExecBuffer)
        return;

    gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));

    gBattlerPartyIndexes[gActiveBattler] = ewram16068arr(gActiveBattler);

    EmitGetAttributes(0, 0, gBitTable[gBattlerPartyIndexes[gActiveBattler]]);
    MarkBufferBankForExecution(gActiveBattler);
    gBattlescriptCurrInstr += 2;
}

static void atk4D_switchindataupdate(void)
{
    struct BattlePokemon oldData;
    s32 i;
    u8 *monData;

    if (gBattleExecBuffer)
        return;

    gActiveBattler = GetBattleBank(gBattlescriptCurrInstr[1]);
    oldData = gBattleMons[gActiveBattler];
    monData = (u8*)(&gBattleMons[gActiveBattler]);

    for (i = 0; i < sizeof(struct BattlePokemon); i++)
    {
        monData[i] = gBattleBufferB[gActiveBattler][4 + i];
    }

    // check knocked off item
    i = GetBattlerSide(gActiveBattler);
    if (gWishFutureKnock.knockedOffPokes[i] & gBitTable[gBattlerPartyIndexes[gActiveBattler]])
    {
        gBattleMons[gActiveBattler].item = 0;
    }

    if (gBattleMoves[gCurrentMove].effect == EFFECT_BATON_PASS)
    {
        for (i = 0; i < 8; i++)
        {
            gBattleMons[gActiveBattler].statStages[i] = oldData.statStages[i];
        }
        gBattleMons[gActiveBattler].status2 = oldData.status2;
    }

    SwitchInClearSetData();

    gBattleStruct->scriptingActive = gActiveBattler;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gActiveBattler, gBattlerPartyIndexes[gActiveBattler]);

    gBattlescriptCurrInstr += 2;
}

static void atk4E_switchinanim(void)
{
    if (gBattleExecBuffer)
        return;

    gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
    if (GetBattlerSide(gActiveBattler) == 1 && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_BATTLE_TOWER)))
    {
        GetSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[gActiveBattler].species), 2);
    }
    gAbsentBattlerFlags &= ~(gBitTable[gActiveBattler]);
    EmitSendOutPoke(0, gBattlerPartyIndexes[gActiveBattler], T2_READ_8(gBattlescriptCurrInstr + 2));
    MarkBufferBankForExecution(gActiveBattler);
    gBattlescriptCurrInstr += 3;
}

static void atk4F_jumpifcantswitch(void)
{
    int val, to_cmp;
    register struct Pokemon *party;
    u8 r7;
    //0x80 byte is used as a way of telling the function whether to not check status2/status3
    gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1) & 0x7F);
    if (!(T2_READ_8(gBattlescriptCurrInstr + 1) & 0x80)
        && ((gBattleMons[gActiveBattler].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION))
            || (gStatuses3[gActiveBattler] & STATUS3_ROOTED)))
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 2);
        return;
    }
    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if (GetBattlerSide(gActiveBattler) == 1)
            party = gEnemyParty;
        else
            party = gPlayerParty;
        val = 0;
        if (sub_803FBFC(sub_803FC34(gActiveBattler)) == 1)
            val = 3;
        for (to_cmp = val + 3; val < to_cmp; val++)
        {
            if (GetMonData(&party[val], MON_DATA_SPECIES) != SPECIES_NONE
             && !GetMonData(&party[val], MON_DATA_IS_EGG)
             && GetMonData(&party[val], MON_DATA_HP) != 0
             && gBattlerPartyIndexes[gActiveBattler] != val)
                break;
        }
        if (val == to_cmp)
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 2);
        else
            gBattlescriptCurrInstr += 6;
    }
    else
    {
        if (GetBattlerSide(gActiveBattler) == 1)
        {
            r7 = GetBattlerAtPosition(1);
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                to_cmp = GetBattlerAtPosition(3);
            else
                to_cmp = r7;
            party = gEnemyParty;
        }
        else
        {
            r7 = GetBattlerAtPosition(0);
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                to_cmp = GetBattlerAtPosition(2);
            else
                to_cmp = r7;
            party = gPlayerParty;
        }
        for (val = 0; val < 6; val++)
        {
            if (GetMonData(&party[val], MON_DATA_HP) != 0
             && GetMonData(&party[val], MON_DATA_SPECIES) != SPECIES_NONE
             && !GetMonData(&party[val], MON_DATA_IS_EGG)
             && val != gBattlerPartyIndexes[r7] && val != gBattlerPartyIndexes[to_cmp])
                break;
        }
        if (val == 6)
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 2);
        else
            gBattlescriptCurrInstr += 6;
    }
}

void sub_8022A3C(u8 unkown)
{
    BATTLE_PARTY_ID(gActiveBattler) = gBattlerPartyIndexes[gActiveBattler];
    EmitChoosePokemon(0, 1, unkown, 0, gBattleStruct->unk1606C[gActiveBattler]);
    MarkBufferBankForExecution(gActiveBattler);
}

/*
static void atk50_openpartyscreen(void)
{
    int i = 0;
    int r9 = 0;
    u8* fail_loc = T1_READ_PTR(gBattlescriptCurrInstr + 2);

    if (T2_READ_8(gBattlescriptCurrInstr + 1) == 5)
    {
        if ((gBattleTypeFlags & (BATTLE_TYPE_DOUBLE | BATTLE_TYPE_MULTI)) != BATTLE_TYPE_DOUBLE)
        {
            for (gActiveBattler = i; gActiveBattler < gBattlersCount; gActiveBattler++)
            {
                if (!(gHitMarker & HITMARKER_FAINTED(gActiveBattler)))
                {
                    EmitLinkStandbyMsg(0, 2);
                    MarkBufferBankForExecution(gActiveBattler);
                }
                else if (sub_8018018(gActiveBattler, 6, 6) == 0
                         && !gSpecialStatuses[gActiveBattler].flag40)
                {
                    sub_8022A3C(6);
                    gSpecialStatuses[gActiveBattler].flag40 = 1;
                }
                else
                {
                    gAbsentBattlerFlags |= gBitTable[gActiveBattler];
                    gHitMarker &= (~HITMARKER_FAINTED(gActiveBattler));
                    EmitLinkStandbyMsg(0, 2);
                    MarkBufferBankForExecution(gActiveBattler);
                }
            }
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        {
            if (!(gHitMarker >> 0x1C & gBitTable[0]))
            {

            }
            else if (sub_8018018(gActiveBattler, 6, 6) == 0
                     && !gSpecialStatuses[gActiveBattler].flag40)
            {

            }
            else
            {

            }
        }
    }
}
*/

NAKED
static void atk50_openpartyscreen(void)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r9\n\
    mov r6, r8\n\
    push {r6,r7}\n\
    sub sp, 0x4\n\
    movs r7, 0\n\
    movs r0, 0\n\
    mov r9, r0\n\
    ldr r6, _08022B44 @ =gBattlescriptCurrInstr\n\
    ldr r1, [r6]\n\
    ldrb r2, [r1, 0x2]\n\
    ldrb r0, [r1, 0x3]\n\
    lsls r0, 8\n\
    orrs r2, r0\n\
    ldrb r0, [r1, 0x4]\n\
    lsls r0, 16\n\
    orrs r2, r0\n\
    ldrb r0, [r1, 0x5]\n\
    lsls r0, 24\n\
    orrs r2, r0\n\
    mov r8, r2\n\
    ldrb r2, [r1, 0x1]\n\
    adds r0, r2, 0\n\
    mov r12, r6\n\
    cmp r0, 0x5\n\
    beq _08022ACE\n\
    b _08022F74\n\
_08022ACE:\n\
    ldr r0, _08022B48 @ =gBattleTypeFlags\n\
    ldrh r0, [r0]\n\
    movs r1, 0x41\n\
    ands r1, r0\n\
    cmp r1, 0x1\n\
    beq _08022BBC\n\
    ldr r1, _08022B4C @ =gActiveBattler\n\
    strb r7, [r1]\n\
    ldr r0, _08022B50 @ =gBattlersCount\n\
    ldrb r0, [r0]\n\
    cmp r7, r0\n\
    bcc _08022AE8\n\
    b _08022F62\n\
_08022AE8:\n\
    ldr r7, _08022B54 @ =gHitMarker\n\
    ldr r6, _08022B58 @ =gBitTable\n\
    adds r4, r1, 0\n\
    ldr r0, _08022B5C @ =gAbsentBattlerFlags\n\
    mov r8, r0\n\
_08022AF2:\n\
    ldrb r2, [r4]\n\
    lsls r0, r2, 2\n\
    adds r0, r6\n\
    ldr r1, [r0]\n\
    lsls r1, 28\n\
    ldr r0, [r7]\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _08022B94\n\
    adds r0, r2, 0\n\
    movs r1, 0x6\n\
    movs r2, 0x6\n\
    bl sub_8018018\n\
    lsls r0, 24\n\
    cmp r0, 0\n\
    beq _08022B60\n\
    ldrb r0, [r4]\n\
    lsls r0, 2\n\
    adds r0, r6\n\
    ldr r0, [r0]\n\
    mov r2, r8\n\
    ldrb r1, [r2]\n\
    orrs r0, r1\n\
    strb r0, [r2]\n\
    ldrb r0, [r4]\n\
    lsls r0, 2\n\
    adds r0, r6\n\
    ldr r1, [r0]\n\
    lsls r1, 28\n\
    ldr r0, [r7]\n\
    bics r0, r1\n\
    str r0, [r7]\n\
    movs r0, 0\n\
    movs r1, 0x2\n\
    bl EmitLinkStandbyMsg\n\
    ldrb r0, [r4]\n\
    bl MarkBufferBankForExecution\n\
    b _08022BA2\n\
    .align 2, 0\n\
_08022B44: .4byte gBattlescriptCurrInstr\n\
_08022B48: .4byte gBattleTypeFlags\n\
_08022B4C: .4byte gActiveBattler\n\
_08022B50: .4byte gBattlersCount\n\
_08022B54: .4byte gHitMarker\n\
_08022B58: .4byte gBitTable\n\
_08022B5C: .4byte gAbsentBattlerFlags\n\
_08022B60:\n\
    ldr r5, _08022B90 @ =gSpecialStatuses\n\
    ldrb r0, [r4]\n\
    lsls r1, r0, 2\n\
    adds r1, r0\n\
    lsls r1, 2\n\
    adds r1, r5\n\
    ldrb r0, [r1]\n\
    lsls r0, 25\n\
    cmp r0, 0\n\
    blt _08022BA2\n\
    movs r0, 0x6\n\
    bl sub_8022A3C\n\
    ldrb r1, [r4]\n\
    lsls r0, r1, 2\n\
    adds r0, r1\n\
    lsls r0, 2\n\
    adds r0, r5\n\
    ldrb r1, [r0]\n\
    movs r2, 0x40\n\
    orrs r1, r2\n\
    strb r1, [r0]\n\
    b _08022BA2\n\
    .align 2, 0\n\
_08022B90: .4byte gSpecialStatuses\n\
_08022B94:\n\
    movs r0, 0\n\
    movs r1, 0x2\n\
    bl EmitLinkStandbyMsg\n\
    ldrb r0, [r4]\n\
    bl MarkBufferBankForExecution\n\
_08022BA2:\n\
    ldrb r0, [r4]\n\
    adds r0, 0x1\n\
    strb r0, [r4]\n\
    ldr r1, _08022BB8 @ =gBattlersCount\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    ldrb r1, [r1]\n\
    cmp r0, r1\n\
    bcc _08022AF2\n\
    b _08022F62\n\
    .align 2, 0\n\
_08022BB8: .4byte gBattlersCount\n\
_08022BBC:\n\
    ands r1, r0\n\
    cmp r1, 0\n\
    bne _08022BC4\n\
    b _08022F62\n\
_08022BC4:\n\
    ldr r0, _08022C1C @ =gHitMarker\n\
    mov r8, r0\n\
    ldr r0, [r0]\n\
    lsrs r5, r0, 28\n\
    ldr r6, _08022C20 @ =gBitTable\n\
    ldr r0, [r6]\n\
    ands r0, r5\n\
    cmp r0, 0\n\
    beq _08022C7E\n\
    ldr r4, _08022C24 @ =gActiveBattler\n\
    strb r7, [r4]\n\
    movs r0, 0\n\
    movs r1, 0x6\n\
    movs r2, 0x6\n\
    bl sub_8018018\n\
    lsls r0, 24\n\
    cmp r0, 0\n\
    beq _08022C2C\n\
    ldr r2, _08022C28 @ =gAbsentBattlerFlags\n\
    ldrb r0, [r4]\n\
    lsls r0, 2\n\
    adds r0, r6\n\
    ldr r0, [r0]\n\
    ldrb r1, [r2]\n\
    orrs r0, r1\n\
    strb r0, [r2]\n\
    ldrb r0, [r4]\n\
    lsls r0, 2\n\
    adds r0, r6\n\
    ldr r1, [r0]\n\
    lsls r1, 28\n\
    mov r2, r8\n\
    ldr r0, [r2]\n\
    bics r0, r1\n\
    str r0, [r2]\n\
    movs r0, 0\n\
    bl Emitcmd42\n\
    ldrb r0, [r4]\n\
    bl MarkBufferBankForExecution\n\
    b _08022C7E\n\
    .align 2, 0\n\
_08022C1C: .4byte gHitMarker\n\
_08022C20: .4byte gBitTable\n\
_08022C24: .4byte gActiveBattler\n\
_08022C28: .4byte gAbsentBattlerFlags\n\
_08022C2C:\n\
    ldr r6, _08022C60 @ =gSpecialStatuses\n\
    ldrb r0, [r4]\n\
    lsls r1, r0, 2\n\
    adds r1, r0\n\
    lsls r1, 2\n\
    adds r1, r6\n\
    ldrb r0, [r1]\n\
    lsls r0, 25\n\
    cmp r0, 0\n\
    blt _08022C6C\n\
    ldr r0, _08022C64 @ =gSharedMem\n\
    ldr r1, _08022C68 @ =0x0001606a\n\
    adds r0, r1\n\
    ldrb r0, [r0]\n\
    bl sub_8022A3C\n\
    ldrb r1, [r4]\n\
    lsls r0, r1, 2\n\
    adds r0, r1\n\
    lsls r0, 2\n\
    adds r0, r6\n\
    ldrb r1, [r0]\n\
    movs r2, 0x40\n\
    orrs r1, r2\n\
    strb r1, [r0]\n\
    b _08022C7E\n\
    .align 2, 0\n\
_08022C60: .4byte gSpecialStatuses\n\
_08022C64: .4byte gSharedMem\n\
_08022C68: .4byte 0x0001606a\n\
_08022C6C:\n\
    movs r0, 0\n\
    movs r1, 0x2\n\
    bl EmitLinkStandbyMsg\n\
    ldrb r0, [r4]\n\
    bl MarkBufferBankForExecution\n\
    movs r2, 0x1\n\
    mov r9, r2\n\
_08022C7E:\n\
    ldr r6, _08022CD8 @ =gBitTable\n\
    ldr r0, [r6, 0x8]\n\
    ands r0, r5\n\
    cmp r0, 0\n\
    beq _08022D40\n\
    ldr r0, [r6]\n\
    ands r0, r5\n\
    cmp r0, 0\n\
    bne _08022D40\n\
    ldr r4, _08022CDC @ =gActiveBattler\n\
    movs r0, 0x2\n\
    strb r0, [r4]\n\
    movs r0, 0x2\n\
    movs r1, 0x6\n\
    movs r2, 0x6\n\
    bl sub_8018018\n\
    lsls r0, 24\n\
    cmp r0, 0\n\
    beq _08022CE8\n\
    ldr r2, _08022CE0 @ =gAbsentBattlerFlags\n\
    ldrb r0, [r4]\n\
    lsls r0, 2\n\
    adds r0, r6\n\
    ldr r0, [r0]\n\
    ldrb r1, [r2]\n\
    orrs r0, r1\n\
    strb r0, [r2]\n\
    ldr r2, _08022CE4 @ =gHitMarker\n\
    ldrb r0, [r4]\n\
    lsls r0, 2\n\
    adds r0, r6\n\
    ldr r1, [r0]\n\
    lsls r1, 28\n\
    ldr r0, [r2]\n\
    bics r0, r1\n\
    str r0, [r2]\n\
    movs r0, 0\n\
    bl Emitcmd42\n\
    ldrb r0, [r4]\n\
    bl MarkBufferBankForExecution\n\
    b _08022D40\n\
    .align 2, 0\n\
_08022CD8: .4byte gBitTable\n\
_08022CDC: .4byte gActiveBattler\n\
_08022CE0: .4byte gAbsentBattlerFlags\n\
_08022CE4: .4byte gHitMarker\n\
_08022CE8:\n\
    ldr r6, _08022D1C @ =gSpecialStatuses\n\
    ldrb r0, [r4]\n\
    lsls r1, r0, 2\n\
    adds r1, r0\n\
    lsls r1, 2\n\
    adds r1, r6\n\
    ldrb r0, [r1]\n\
    lsls r0, 25\n\
    cmp r0, 0\n\
    blt _08022D28\n\
    ldr r0, _08022D20 @ =gSharedMem\n\
    ldr r1, _08022D24 @ =0x00016068\n\
    adds r0, r1\n\
    ldrb r0, [r0]\n\
    bl sub_8022A3C\n\
    ldrb r1, [r4]\n\
    lsls r0, r1, 2\n\
    adds r0, r1\n\
    lsls r0, 2\n\
    adds r0, r6\n\
    ldrb r1, [r0]\n\
    movs r2, 0x40\n\
    orrs r1, r2\n\
    strb r1, [r0]\n\
    b _08022D40\n\
    .align 2, 0\n\
_08022D1C: .4byte gSpecialStatuses\n\
_08022D20: .4byte gSharedMem\n\
_08022D24: .4byte 0x00016068\n\
_08022D28:\n\
    movs r0, 0x1\n\
    mov r2, r9\n\
    ands r0, r2\n\
    cmp r0, 0\n\
    bne _08022D40\n\
    movs r0, 0\n\
    movs r1, 0x2\n\
    bl EmitLinkStandbyMsg\n\
    ldrb r0, [r4]\n\
    bl MarkBufferBankForExecution\n\
_08022D40:\n\
    ldr r6, _08022D90 @ =gBitTable\n\
    ldr r0, [r6, 0x4]\n\
    ands r0, r5\n\
    cmp r0, 0\n\
    beq _08022DF6\n\
    ldr r4, _08022D94 @ =gActiveBattler\n\
    movs r0, 0x1\n\
    strb r0, [r4]\n\
    movs r0, 0x1\n\
    movs r1, 0x6\n\
    movs r2, 0x6\n\
    bl sub_8018018\n\
    lsls r0, 24\n\
    cmp r0, 0\n\
    beq _08022DA0\n\
    ldr r2, _08022D98 @ =gAbsentBattlerFlags\n\
    ldrb r0, [r4]\n\
    lsls r0, 2\n\
    adds r0, r6\n\
    ldr r0, [r0]\n\
    ldrb r1, [r2]\n\
    orrs r0, r1\n\
    strb r0, [r2]\n\
    ldr r2, _08022D9C @ =gHitMarker\n\
    ldrb r0, [r4]\n\
    lsls r0, 2\n\
    adds r0, r6\n\
    ldr r1, [r0]\n\
    lsls r1, 28\n\
    ldr r0, [r2]\n\
    bics r0, r1\n\
    str r0, [r2]\n\
    movs r0, 0\n\
    bl Emitcmd42\n\
    ldrb r0, [r4]\n\
    bl MarkBufferBankForExecution\n\
    b _08022DF6\n\
    .align 2, 0\n\
_08022D90: .4byte gBitTable\n\
_08022D94: .4byte gActiveBattler\n\
_08022D98: .4byte gAbsentBattlerFlags\n\
_08022D9C: .4byte gHitMarker\n\
_08022DA0:\n\
    ldr r6, _08022DD4 @ =gSpecialStatuses\n\
    ldrb r0, [r4]\n\
    lsls r1, r0, 2\n\
    adds r1, r0\n\
    lsls r1, 2\n\
    adds r1, r6\n\
    ldrb r0, [r1]\n\
    lsls r0, 25\n\
    cmp r0, 0\n\
    blt _08022DE0\n\
    ldr r0, _08022DD8 @ =gSharedMem\n\
    ldr r1, _08022DDC @ =0x0001606b\n\
    adds r0, r1\n\
    ldrb r0, [r0]\n\
    bl sub_8022A3C\n\
    ldrb r1, [r4]\n\
    lsls r0, r1, 2\n\
    adds r0, r1\n\
    lsls r0, 2\n\
    adds r0, r6\n\
    ldrb r1, [r0]\n\
    movs r2, 0x40\n\
    orrs r1, r2\n\
    strb r1, [r0]\n\
    b _08022DF6\n\
    .align 2, 0\n\
_08022DD4: .4byte gSpecialStatuses\n\
_08022DD8: .4byte gSharedMem\n\
_08022DDC: .4byte 0x0001606b\n\
_08022DE0:\n\
    movs r0, 0\n\
    movs r1, 0x2\n\
    bl EmitLinkStandbyMsg\n\
    ldrb r0, [r4]\n\
    bl MarkBufferBankForExecution\n\
    movs r0, 0x2\n\
    mov r2, r9\n\
    orrs r2, r0\n\
    mov r9, r2\n\
_08022DF6:\n\
    ldr r6, _08022E50 @ =gBitTable\n\
    ldr r0, [r6, 0xC]\n\
    ands r0, r5\n\
    cmp r0, 0\n\
    beq _08022EB8\n\
    ldr r0, [r6, 0x4]\n\
    ands r0, r5\n\
    cmp r0, 0\n\
    bne _08022EB8\n\
    ldr r4, _08022E54 @ =gActiveBattler\n\
    movs r0, 0x3\n\
    strb r0, [r4]\n\
    movs r0, 0x3\n\
    movs r1, 0x6\n\
    movs r2, 0x6\n\
    bl sub_8018018\n\
    lsls r0, 24\n\
    cmp r0, 0\n\
    beq _08022E60\n\
    ldr r2, _08022E58 @ =gAbsentBattlerFlags\n\
    ldrb r0, [r4]\n\
    lsls r0, 2\n\
    adds r0, r6\n\
    ldr r0, [r0]\n\
    ldrb r1, [r2]\n\
    orrs r0, r1\n\
    strb r0, [r2]\n\
    ldr r2, _08022E5C @ =gHitMarker\n\
    ldrb r0, [r4]\n\
    lsls r0, 2\n\
    adds r0, r6\n\
    ldr r1, [r0]\n\
    lsls r1, 28\n\
    ldr r0, [r2]\n\
    bics r0, r1\n\
    str r0, [r2]\n\
    movs r0, 0\n\
    bl Emitcmd42\n\
    ldrb r0, [r4]\n\
    bl MarkBufferBankForExecution\n\
    b _08022EB8\n\
    .align 2, 0\n\
_08022E50: .4byte gBitTable\n\
_08022E54: .4byte gActiveBattler\n\
_08022E58: .4byte gAbsentBattlerFlags\n\
_08022E5C: .4byte gHitMarker\n\
_08022E60:\n\
    ldr r6, _08022E94 @ =gSpecialStatuses\n\
    ldrb r0, [r4]\n\
    lsls r1, r0, 2\n\
    adds r1, r0\n\
    lsls r1, 2\n\
    adds r1, r6\n\
    ldrb r0, [r1]\n\
    lsls r0, 25\n\
    cmp r0, 0\n\
    blt _08022EA0\n\
    ldr r0, _08022E98 @ =gSharedMem\n\
    ldr r1, _08022E9C @ =0x00016069\n\
    adds r0, r1\n\
    ldrb r0, [r0]\n\
    bl sub_8022A3C\n\
    ldrb r1, [r4]\n\
    lsls r0, r1, 2\n\
    adds r0, r1\n\
    lsls r0, 2\n\
    adds r0, r6\n\
    ldrb r1, [r0]\n\
    movs r2, 0x40\n\
    orrs r1, r2\n\
    strb r1, [r0]\n\
    b _08022EB8\n\
    .align 2, 0\n\
_08022E94: .4byte gSpecialStatuses\n\
_08022E98: .4byte gSharedMem\n\
_08022E9C: .4byte 0x00016069\n\
_08022EA0:\n\
    movs r0, 0x2\n\
    mov r2, r9\n\
    ands r2, r0\n\
    cmp r2, 0\n\
    bne _08022EB8\n\
    movs r0, 0\n\
    movs r1, 0x2\n\
    bl EmitLinkStandbyMsg\n\
    ldrb r0, [r4]\n\
    bl MarkBufferBankForExecution\n\
_08022EB8:\n\
    ldr r1, _08022EE8 @ =gSpecialStatuses\n\
    ldrb r0, [r1]\n\
    lsls r0, 25\n\
    cmp r0, 0\n\
    blt _08022F0C\n\
    adds r0, r1, 0\n\
    adds r0, 0x28\n\
    ldrb r0, [r0]\n\
    lsls r0, 25\n\
    cmp r0, 0\n\
    blt _08022F0C\n\
    cmp r5, 0\n\
    beq _08022F0C\n\
    ldr r0, _08022EEC @ =gAbsentBattlerFlags\n\
    ldrb r1, [r0]\n\
    ldr r0, _08022EF0 @ =gBitTable\n\
    ldr r0, [r0]\n\
    ands r1, r0\n\
    cmp r1, 0\n\
    beq _08022EF8\n\
    ldr r1, _08022EF4 @ =gActiveBattler\n\
    movs r0, 0x2\n\
    strb r0, [r1]\n\
    b _08022EFC\n\
    .align 2, 0\n\
_08022EE8: .4byte gSpecialStatuses\n\
_08022EEC: .4byte gAbsentBattlerFlags\n\
_08022EF0: .4byte gBitTable\n\
_08022EF4: .4byte gActiveBattler\n\
_08022EF8:\n\
    ldr r0, _08022F3C @ =gActiveBattler\n\
    strb r1, [r0]\n\
_08022EFC:\n\
    movs r0, 0\n\
    movs r1, 0x2\n\
    bl EmitLinkStandbyMsg\n\
    ldr r0, _08022F3C @ =gActiveBattler\n\
    ldrb r0, [r0]\n\
    bl MarkBufferBankForExecution\n\
_08022F0C:\n\
    ldr r1, _08022F40 @ =gSpecialStatuses\n\
    ldrb r0, [r1, 0x14]\n\
    lsls r0, 25\n\
    cmp r0, 0\n\
    blt _08022F62\n\
    adds r0, r1, 0\n\
    adds r0, 0x3C\n\
    ldrb r0, [r0]\n\
    lsls r0, 25\n\
    cmp r0, 0\n\
    blt _08022F62\n\
    cmp r5, 0\n\
    beq _08022F62\n\
    ldr r0, _08022F44 @ =gAbsentBattlerFlags\n\
    ldrb r0, [r0]\n\
    ldr r1, _08022F48 @ =gBitTable\n\
    ldr r1, [r1, 0x4]\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _08022F4C\n\
    ldr r1, _08022F3C @ =gActiveBattler\n\
    movs r0, 0x3\n\
    b _08022F50\n\
    .align 2, 0\n\
_08022F3C: .4byte gActiveBattler\n\
_08022F40: .4byte gSpecialStatuses\n\
_08022F44: .4byte gAbsentBattlerFlags\n\
_08022F48: .4byte gBitTable\n\
_08022F4C:\n\
    ldr r1, _08022F6C @ =gActiveBattler\n\
    movs r0, 0x1\n\
_08022F50:\n\
    strb r0, [r1]\n\
    movs r0, 0\n\
    movs r1, 0x2\n\
    bl EmitLinkStandbyMsg\n\
    ldr r0, _08022F6C @ =gActiveBattler\n\
    ldrb r0, [r0]\n\
    bl MarkBufferBankForExecution\n\
_08022F62:\n\
    ldr r1, _08022F70 @ =gBattlescriptCurrInstr\n\
    ldr r0, [r1]\n\
    adds r0, 0x6\n\
    str r0, [r1]\n\
    b _08023302\n\
    .align 2, 0\n\
_08022F6C: .4byte gActiveBattler\n\
_08022F70: .4byte gBattlescriptCurrInstr\n\
_08022F74:\n\
    cmp r0, 0x6\n\
    beq _08022F7A\n\
    b _08023170\n\
_08022F7A:\n\
    ldr r0, _08022FF0 @ =gBattleTypeFlags\n\
    ldrh r2, [r0]\n\
    movs r0, 0x40\n\
    ands r0, r2\n\
    cmp r0, 0\n\
    beq _08022F88\n\
    b _0802310C\n\
_08022F88:\n\
    movs r0, 0x1\n\
    ands r0, r2\n\
    cmp r0, 0\n\
    bne _08022F92\n\
    b _0802310C\n\
_08022F92:\n\
    ldr r7, _08022FF4 @ =gHitMarker\n\
    ldr r0, [r7]\n\
    lsrs r5, r0, 28\n\
    ldr r4, _08022FF8 @ =gBitTable\n\
    ldr r0, [r4, 0x8]\n\
    ands r0, r5\n\
    cmp r0, 0\n\
    beq _0802303A\n\
    ldr r0, [r4]\n\
    ands r0, r5\n\
    cmp r0, 0\n\
    beq _0802303A\n\
    ldr r6, _08022FFC @ =gActiveBattler\n\
    movs r0, 0x2\n\
    strb r0, [r6]\n\
    ldr r0, _08023000 @ =gBattleBufferB\n\
    ldrb r1, [r0, 0x1]\n\
    movs r0, 0x2\n\
    movs r2, 0x6\n\
    bl sub_8018018\n\
    lsls r0, 24\n\
    cmp r0, 0\n\
    beq _08023008\n\
    ldr r2, _08023004 @ =gAbsentBattlerFlags\n\
    ldrb r0, [r6]\n\
    lsls r0, 2\n\
    adds r0, r4\n\
    ldr r0, [r0]\n\
    ldrb r1, [r2]\n\
    orrs r0, r1\n\
    strb r0, [r2]\n\
    ldrb r0, [r6]\n\
    lsls r0, 2\n\
    adds r0, r4\n\
    ldr r1, [r0]\n\
    lsls r1, 28\n\
    ldr r0, [r7]\n\
    bics r0, r1\n\
    str r0, [r7]\n\
    movs r0, 0\n\
    bl Emitcmd42\n\
    ldrb r0, [r6]\n\
    bl MarkBufferBankForExecution\n\
    b _0802303A\n\
    .align 2, 0\n\
_08022FF0: .4byte gBattleTypeFlags\n\
_08022FF4: .4byte gHitMarker\n\
_08022FF8: .4byte gBitTable\n\
_08022FFC: .4byte gActiveBattler\n\
_08023000: .4byte gBattleBufferB\n\
_08023004: .4byte gAbsentBattlerFlags\n\
_08023008:\n\
    ldr r4, _08023098 @ =gSpecialStatuses\n\
    ldrb r0, [r6]\n\
    lsls r1, r0, 2\n\
    adds r1, r0\n\
    lsls r1, 2\n\
    adds r1, r4\n\
    ldrb r0, [r1]\n\
    lsls r0, 25\n\
    cmp r0, 0\n\
    blt _0802303A\n\
    ldr r0, _0802309C @ =gSharedMem\n\
    ldr r1, _080230A0 @ =0x00016068\n\
    adds r0, r1\n\
    ldrb r0, [r0]\n\
    bl sub_8022A3C\n\
    ldrb r1, [r6]\n\
    lsls r0, r1, 2\n\
    adds r0, r1\n\
    lsls r0, 2\n\
    adds r0, r4\n\
    ldrb r1, [r0]\n\
    movs r2, 0x40\n\
    orrs r1, r2\n\
    strb r1, [r0]\n\
_0802303A:\n\
    ldr r4, _080230A4 @ =gBitTable\n\
    ldr r0, [r4, 0xC]\n\
    ands r0, r5\n\
    cmp r0, 0\n\
    beq _080230EE\n\
    ldr r0, [r4, 0x4]\n\
    ands r5, r0\n\
    cmp r5, 0\n\
    beq _080230EE\n\
    ldr r5, _080230A8 @ =gActiveBattler\n\
    movs r0, 0x3\n\
    strb r0, [r5]\n\
    ldr r0, _080230AC @ =gBattleBufferB\n\
    ldr r2, _080230B0 @ =0x00000201\n\
    adds r0, r2\n\
    ldrb r1, [r0]\n\
    movs r0, 0x3\n\
    movs r2, 0x6\n\
    bl sub_8018018\n\
    lsls r0, 24\n\
    cmp r0, 0\n\
    beq _080230BC\n\
    ldr r2, _080230B4 @ =gAbsentBattlerFlags\n\
    ldrb r0, [r5]\n\
    lsls r0, 2\n\
    adds r0, r4\n\
    ldr r0, [r0]\n\
    ldrb r1, [r2]\n\
    orrs r0, r1\n\
    strb r0, [r2]\n\
    ldr r2, _080230B8 @ =gHitMarker\n\
    ldrb r0, [r5]\n\
    lsls r0, 2\n\
    adds r0, r4\n\
    ldr r1, [r0]\n\
    lsls r1, 28\n\
    ldr r0, [r2]\n\
    bics r0, r1\n\
    str r0, [r2]\n\
    movs r0, 0\n\
    bl Emitcmd42\n\
    ldrb r0, [r5]\n\
    bl MarkBufferBankForExecution\n\
    b _080230EE\n\
    .align 2, 0\n\
_08023098: .4byte gSpecialStatuses\n\
_0802309C: .4byte gSharedMem\n\
_080230A0: .4byte 0x00016068\n\
_080230A4: .4byte gBitTable\n\
_080230A8: .4byte gActiveBattler\n\
_080230AC: .4byte gBattleBufferB\n\
_080230B0: .4byte 0x00000201\n\
_080230B4: .4byte gAbsentBattlerFlags\n\
_080230B8: .4byte gHitMarker\n\
_080230BC:\n\
    ldr r4, _080230FC @ =gSpecialStatuses\n\
    ldrb r0, [r5]\n\
    lsls r1, r0, 2\n\
    adds r1, r0\n\
    lsls r1, 2\n\
    adds r1, r4\n\
    ldrb r0, [r1]\n\
    lsls r0, 25\n\
    cmp r0, 0\n\
    blt _080230EE\n\
    ldr r0, _08023100 @ =gSharedMem\n\
    ldr r1, _08023104 @ =0x00016069\n\
    adds r0, r1\n\
    ldrb r0, [r0]\n\
    bl sub_8022A3C\n\
    ldrb r1, [r5]\n\
    lsls r0, r1, 2\n\
    adds r0, r1\n\
    lsls r0, 2\n\
    adds r0, r4\n\
    ldrb r1, [r0]\n\
    movs r2, 0x40\n\
    orrs r1, r2\n\
    strb r1, [r0]\n\
_080230EE:\n\
    ldr r1, _08023108 @ =gBattlescriptCurrInstr\n\
    ldr r0, [r1]\n\
    adds r0, 0x6\n\
    str r0, [r1]\n\
    mov r12, r1\n\
    b _08023110\n\
    .align 2, 0\n\
_080230FC: .4byte gSpecialStatuses\n\
_08023100: .4byte gSharedMem\n\
_08023104: .4byte 0x00016069\n\
_08023108: .4byte gBattlescriptCurrInstr\n\
_0802310C:\n\
    adds r0, r1, 0x6\n\
    str r0, [r6]\n\
_08023110:\n\
    ldr r0, _08023160 @ =gHitMarker\n\
    ldr r0, [r0]\n\
    lsrs r5, r0, 28\n\
    ldr r1, _08023164 @ =gBank1\n\
    movs r0, 0\n\
    strb r0, [r1]\n\
    ldr r4, _08023168 @ =gBitTable\n\
    ldr r2, [r4]\n\
    ands r2, r5\n\
    ldr r6, _0802316C @ =gBattlersCount\n\
    cmp r2, 0\n\
    bne _0802314C\n\
    adds r7, r6, 0\n\
    ldrb r0, [r6]\n\
    cmp r2, r0\n\
    bcs _0802314C\n\
    adds r3, r1, 0\n\
_08023132:\n\
    ldrb r0, [r3]\n\
    adds r0, 0x1\n\
    strb r0, [r3]\n\
    ldrb r2, [r3]\n\
    lsls r0, r2, 2\n\
    adds r0, r4\n\
    ldr r0, [r0]\n\
    ands r0, r5\n\
    cmp r0, 0\n\
    bne _0802314C\n\
    ldrb r0, [r7]\n\
    cmp r2, r0\n\
    bcc _08023132\n\
_0802314C:\n\
    ldrb r0, [r1]\n\
    ldrb r6, [r6]\n\
    cmp r0, r6\n\
    beq _08023156\n\
    b _08023302\n\
_08023156:\n\
    mov r1, r8\n\
    mov r2, r12\n\
    str r1, [r2]\n\
    b _08023302\n\
    .align 2, 0\n\
_08023160: .4byte gHitMarker\n\
_08023164: .4byte gBank1\n\
_08023168: .4byte gBitTable\n\
_0802316C: .4byte gBattlersCount\n\
_08023170:\n\
    movs r0, 0x80\n\
    ands r0, r2\n\
    movs r5, 0x1\n\
    cmp r0, 0\n\
    beq _0802317C\n\
    movs r5, 0\n\
_0802317C:\n\
    movs r0, 0x7F\n\
    ands r0, r2\n\
    bl GetBattleBank\n\
    lsls r0, 24\n\
    lsrs r7, r0, 24\n\
    ldr r1, _080231A4 @ =gSpecialStatuses\n\
    lsls r0, r7, 2\n\
    adds r0, r7\n\
    lsls r0, 2\n\
    adds r0, r1\n\
    ldrb r0, [r0]\n\
    lsls r0, 25\n\
    cmp r0, 0\n\
    bge _080231A8\n\
    ldr r0, [r6]\n\
    adds r0, 0x6\n\
    str r0, [r6]\n\
    b _08023302\n\
    .align 2, 0\n\
_080231A4: .4byte gSpecialStatuses\n\
_080231A8:\n\
    adds r0, r7, 0\n\
    movs r1, 0x6\n\
    movs r2, 0x6\n\
    bl sub_8018018\n\
    lsls r0, 24\n\
    cmp r0, 0\n\
    beq _080231F8\n\
    ldr r2, _080231E8 @ =gActiveBattler\n\
    strb r7, [r2]\n\
    ldr r3, _080231EC @ =gAbsentBattlerFlags\n\
    ldr r4, _080231F0 @ =gBitTable\n\
    ldrb r0, [r2]\n\
    lsls r0, 2\n\
    adds r0, r4\n\
    ldr r0, [r0]\n\
    ldrb r1, [r3]\n\
    orrs r0, r1\n\
    strb r0, [r3]\n\
    ldr r3, _080231F4 @ =gHitMarker\n\
    ldrb r0, [r2]\n\
    lsls r0, 2\n\
    adds r0, r4\n\
    ldr r1, [r0]\n\
    lsls r1, 28\n\
    ldr r0, [r3]\n\
    bics r0, r1\n\
    str r0, [r3]\n\
    mov r0, r8\n\
    str r0, [r6]\n\
    b _08023302\n\
    .align 2, 0\n\
_080231E8: .4byte gActiveBattler\n\
_080231EC: .4byte gAbsentBattlerFlags\n\
_080231F0: .4byte gBitTable\n\
_080231F4: .4byte gHitMarker\n\
_080231F8:\n\
    ldr r4, _080232A0 @ =gActiveBattler\n\
    strb r7, [r4]\n\
    ldr r3, _080232A4 @ =gSharedMem\n\
    ldrb r0, [r4]\n\
    ldr r2, _080232A8 @ =0x00016064\n\
    adds r1, r0, r2\n\
    adds r1, r3\n\
    ldr r2, _080232AC @ =gBattlerPartyIndexes\n\
    lsls r0, 1\n\
    adds r0, r2\n\
    ldrh r0, [r0]\n\
    strb r0, [r1]\n\
    ldrb r1, [r4]\n\
    movs r0, 0x2\n\
    eors r0, r1\n\
    ldr r1, _080232B0 @ =0x00016068\n\
    adds r0, r1\n\
    adds r0, r3\n\
    ldrb r2, [r0]\n\
    ldrb r1, [r4]\n\
    lsls r0, r1, 1\n\
    adds r0, r1\n\
    ldr r1, _080232B4 @ =0x0001606c\n\
    adds r3, r1\n\
    adds r0, r3\n\
    str r0, [sp]\n\
    movs r0, 0\n\
    adds r1, r5, 0\n\
    movs r3, 0\n\
    bl EmitChoosePokemon\n\
    ldrb r0, [r4]\n\
    bl MarkBufferBankForExecution\n\
    ldr r0, [r6]\n\
    adds r0, 0x6\n\
    str r0, [r6]\n\
    ldrb r0, [r4]\n\
    bl GetBattlerPosition\n\
    lsls r0, 24\n\
    cmp r0, 0\n\
    bne _0802325A\n\
    ldr r1, _080232B8 @ =gBattleResults\n\
    ldrb r0, [r1, 0x2]\n\
    cmp r0, 0xFE\n\
    bhi _0802325A\n\
    adds r0, 0x1\n\
    strb r0, [r1, 0x2]\n\
_0802325A:\n\
    ldr r0, _080232BC @ =gBattleTypeFlags\n\
    ldrh r1, [r0]\n\
    movs r0, 0x40\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _080232C4\n\
    ldr r1, _080232A0 @ =gActiveBattler\n\
    movs r0, 0\n\
    strb r0, [r1]\n\
    ldr r0, _080232C0 @ =gBattlersCount\n\
    ldrb r0, [r0]\n\
    cmp r0, 0\n\
    beq _08023302\n\
    adds r4, r1, 0\n\
_08023276:\n\
    ldrb r0, [r4]\n\
    cmp r0, r7\n\
    beq _0802328A\n\
    movs r0, 0\n\
    movs r1, 0x2\n\
    bl EmitLinkStandbyMsg\n\
    ldrb r0, [r4]\n\
    bl MarkBufferBankForExecution\n\
_0802328A:\n\
    ldrb r0, [r4]\n\
    adds r0, 0x1\n\
    strb r0, [r4]\n\
    ldr r1, _080232C0 @ =gBattlersCount\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    ldrb r1, [r1]\n\
    cmp r0, r1\n\
    bcc _08023276\n\
    b _08023302\n\
    .align 2, 0\n\
_080232A0: .4byte gActiveBattler\n\
_080232A4: .4byte gSharedMem\n\
_080232A8: .4byte 0x00016064\n\
_080232AC: .4byte gBattlerPartyIndexes\n\
_080232B0: .4byte 0x00016068\n\
_080232B4: .4byte 0x0001606c\n\
_080232B8: .4byte gBattleResults\n\
_080232BC: .4byte gBattleTypeFlags\n\
_080232C0: .4byte gBattlersCount\n\
_080232C4:\n\
    adds r0, r7, 0\n\
    bl GetBattlerPosition\n\
    movs r1, 0x1\n\
    eors r0, r1\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    bl GetBattlerAtPosition\n\
    ldr r4, _08023310 @ =gActiveBattler\n\
    strb r0, [r4]\n\
    ldr r0, _08023314 @ =gAbsentBattlerFlags\n\
    ldrb r1, [r0]\n\
    ldr r2, _08023318 @ =gBitTable\n\
    ldrb r3, [r4]\n\
    lsls r0, r3, 2\n\
    adds r0, r2\n\
    ldr r0, [r0]\n\
    ands r1, r0\n\
    cmp r1, 0\n\
    beq _080232F4\n\
    movs r0, 0x2\n\
    eors r3, r0\n\
    strb r3, [r4]\n\
_080232F4:\n\
    movs r0, 0\n\
    movs r1, 0x2\n\
    bl EmitLinkStandbyMsg\n\
    ldrb r0, [r4]\n\
    bl MarkBufferBankForExecution\n\
_08023302:\n\
    add sp, 0x4\n\
    pop {r3,r4}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .align 2, 0\n\
_08023310: .4byte gActiveBattler\n\
_08023314: .4byte gAbsentBattlerFlags\n\
_08023318: .4byte gBitTable\n\
        .syntax divided");
}

static void atk51_switchhandleorder(void)
{
    int i;
    if (gBattleExecBuffer)
        return;

    gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
    switch (T2_READ_8(gBattlescriptCurrInstr + 2))
    {
    case 0:
        for (i = 0; i < gBattlersCount; i++)
        {
            if (gBattleBufferB[i][0] == 0x22)
                ewram16068arr(i) = gBattleBufferB[i][1];
        }
        break;
    case 1:
        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            sub_8012258(gActiveBattler);
        break;
    case 2:
        gBattleCommunication[0] = gBattleBufferB[gActiveBattler][1];
        ewram16068arr(gActiveBattler) = gBattleBufferB[gActiveBattler][1];
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            ewram1606Carr(0, gActiveBattler) &= 0xF;
            ewram1606Carr(0, gActiveBattler) |= (gBattleBufferB[gActiveBattler][2] & 0xF0);
            ewram1606Carr(1, gActiveBattler) = gBattleBufferB[gActiveBattler][3];
            ewram1606Carr(0, (gActiveBattler ^ 2)) &= (0xF0);
            ewram1606Carr(0, (gActiveBattler ^ 2)) |= (gBattleBufferB[gActiveBattler][2] & 0xF0) >> 4;
            ewram1606Carr(2, (gActiveBattler ^ 2)) = gBattleBufferB[gActiveBattler][3];
        }
        else
            sub_8012258(gActiveBattler);

        gBattleTextBuff1[0] = 0xFD;
        gBattleTextBuff1[1] = 6;
        gBattleTextBuff1[2] = gBattleMons[gBankAttacker].species;
        gBattleTextBuff1[3] = gBattleMons[gBankAttacker].species >> 8;
        gBattleTextBuff1[4] = 0xFF;

        gBattleTextBuff2[0] = 0xFD;
        gBattleTextBuff2[1] = 7;
        gBattleTextBuff2[2] = gActiveBattler;
        gBattleTextBuff2[3] = gBattleBufferB[gActiveBattler][1];
        gBattleTextBuff2[4] = 0xFF;
        break;
    }
    gBattlescriptCurrInstr += 3;
}

static void atk52_switchineffects(void)
{
    int i;

    gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
    sub_80157C4(gActiveBattler);
    gHitMarker &= ~(HITMARKER_FAINTED(gActiveBattler));
    gSpecialStatuses[gActiveBattler].flag40 = 0;

    if (!(gSideAffecting[GetBattlerSide(gActiveBattler)] & SIDE_STATUS_SPIKES_DAMAGED))
    {
        gSideAffecting[GetBattlerSide(gActiveBattler)] |= SIDE_STATUS_SPIKES_DAMAGED;

        gBattleStruct->scriptingActive = gActiveBattler;
        BattleScriptPushCursor();

        if (T2_READ_8(gBattlescriptCurrInstr + 1) == 0)
            gBattlescriptCurrInstr = BattleScript_HazardsTarget;
        else if (T2_READ_8(gBattlescriptCurrInstr + 1) == 1)
            gBattlescriptCurrInstr = BattleScript_HazardsUser;
        else
            gBattlescriptCurrInstr = BattleScript_HazardsgBank1;
    }
    else
    {
        if (gBattleMons[gActiveBattler].ability == ABILITY_TRUANT)
        {
            gDisableStructs[gActiveBattler].truantCounter = 1;
        }

        if (AbilityBattleEffects(ABILITYEFFECT_ON_SWITCHIN, gActiveBattler, 0, 0, 0) == 0 && ItemBattleEffects(0, gActiveBattler, 0) == 0)
        {
            gSideAffecting[GetBattlerSide(gActiveBattler)] &= ~(SIDE_STATUS_SPIKES_DAMAGED);

            for (i = 0; i < gBattlersCount; i++)
            {
                if (gBanksByTurnOrder[i] == gActiveBattler)
                    gActionsByTurnOrder[i] = 0xC;
            }

            for (i = 0; i < gBattlersCount; i++)
            {
                *(HP_ON_SWITCHOUT + GetBattlerSide(i)) = gBattleMons[i].hp;
            }

            if (T2_READ_8(gBattlescriptCurrInstr + 1) == 5)
            {
                u32 hitmark = gHitMarker >> 0x1C;
                gBank1++;
                while (1)
                {
                    if (hitmark & gBitTable[gBank1] && !(gAbsentBattlerFlags & gBitTable[gBank1]))
                        break;
                    if (gBank1 >= gBattlersCount)
                        break;
                    gBank1++;
                }
            }
            gBattlescriptCurrInstr += 2;
        }
    }
}

static void atk53_trainerslidein(void)
{
    if (!T2_READ_8(gBattlescriptCurrInstr + 1))
        gActiveBattler = GetBattlerAtPosition(0);
    else
        gActiveBattler = GetBattlerAtPosition(1);

    EmitTrainerSlide(0);
    MarkBufferBankForExecution(gActiveBattler);
    gBattlescriptCurrInstr += 2;
}

static void atk54_playse(void)
{
    gActiveBattler = gBankAttacker;
    EmitEffectivenessSound(0, T2_READ_16(gBattlescriptCurrInstr + 1));
    MarkBufferBankForExecution(gActiveBattler);
    gBattlescriptCurrInstr += 3;
}

static void atk55_fanfare(void)
{
    gActiveBattler = gBankAttacker;
    Emitcmd44(0, T2_READ_16(gBattlescriptCurrInstr + 1));
    MarkBufferBankForExecution(gActiveBattler);
    gBattlescriptCurrInstr += 3;
}

static void atk56_playfaintcry(void)
{
    gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
    EmitFaintingCry(0);
    MarkBufferBankForExecution(gActiveBattler);
    gBattlescriptCurrInstr += 2;
}

static void atk57(void)
{
    gActiveBattler = GetBattlerAtPosition(0);
    Emitcmd55(0, gBattleOutcome);
    MarkBufferBankForExecution(gActiveBattler);
    gBattlescriptCurrInstr += 1;
}

static void atk58_returntoball(void)
{
    gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
    EmitReturnPokeToBall(0, 1);
    MarkBufferBankForExecution(gActiveBattler);
    gBattlescriptCurrInstr += 2;
}

void atk59_handlelearnnewmove(void)
{
    u8* loc1 = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    u8* loc2 = T1_READ_PTR(gBattlescriptCurrInstr + 5);

    u16 ret = MonTryLearningNewMove(&gPlayerParty[gBattleStruct->expGetterID], T2_READ_8(gBattlescriptCurrInstr + 9));
    while (ret == 0xFFFE)
        ret = MonTryLearningNewMove(&gPlayerParty[gBattleStruct->expGetterID], 0);

    if (ret == 0)
    {
        gBattlescriptCurrInstr = loc2;
    }
    else if (ret == 0xFFFF)
    {
        gBattlescriptCurrInstr += 10;
    }
    else
    {
        gActiveBattler = GetBattlerAtPosition(0);
        if (gBattlerPartyIndexes[gActiveBattler] == gBattleStruct->expGetterID && !(gBattleMons[gActiveBattler].status2 & STATUS2_TRANSFORMED))
            GiveMoveToBattleMon(&gBattleMons[gActiveBattler], ret);
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE) //what is else if
        {
            gActiveBattler = GetBattlerAtPosition(2);
            if (gBattlerPartyIndexes[gActiveBattler] == gBattleStruct->expGetterID && !(gBattleMons[gActiveBattler].status2 & STATUS2_TRANSFORMED))
                GiveMoveToBattleMon(&gBattleMons[gActiveBattler], ret);
        }
        gBattlescriptCurrInstr = loc1;
    }
}

void sub_8023A80(void)
{
    sub_802BBD4(0x18, 8, 0x1D, 0xD, 0);
    Text_InitWindow(&gUnknown_03004210, BattleText_YesNo, 0x100, 0x19, 0x9);
    Text_PrintWindow8002F44(&gUnknown_03004210);
    MenuCursor_Create814A5C0(0, 0xFFFF, 0xC, 0x2D9F, 0x20);
}

void sub_8023AD8(void)
{
    sub_802BBD4(0x18, 8, 0x1D, 0xD, 1);
    DestroyMenuCursor();
}

static void atk5A_yesnoboxlearnmove(void)
{
    gActiveBattler = 0;
    switch (gBattleStruct->atk5A_StateTracker)
    {
    case 0:
        sub_8023A80();
        gBattleStruct->atk5A_StateTracker++;
        gBattleCommunication[1] = 0;
        sub_802BC6C();
        break;
    case 1:
        if (gMain.newKeys & DPAD_UP && gBattleCommunication[1] != 0)
        {
            PlaySE(SE_SELECT);
            nullsub_6();
            gBattleCommunication[1] = 0;
            sub_802BC6C();
        }
        if (gMain.newKeys & DPAD_DOWN && gBattleCommunication[1] == 0)
        {
            PlaySE(SE_SELECT);
            nullsub_6();
            gBattleCommunication[1] = 1;
            sub_802BC6C();
        }
        if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            if (gBattleCommunication[1] == 0)
            {
                sub_8023AD8();
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB(0, 0, 0));
                gBattleStruct->atk5A_StateTracker++;
                return;
            }
            goto state_tracker_4;
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
          state_tracker_4:
            gBattleStruct->atk5A_StateTracker = 4;
        }
        break;
    case 2:
        if (!gPaletteFade.active)
        {
            ShowSelectMovePokemonSummaryScreen(gPlayerParty, gBattleStruct->expGetterID, gPlayerPartyCount - 1, ReshowBattleScreenAfterMenu, gMoveToLearn);
            gBattleStruct->atk5A_StateTracker++;
        }
        break;
    case 3:
        if (!gPaletteFade.active && gMain.callback2 == BattleMainCB2)
        {
            u8 move_pos = sub_809FA30();
            if (move_pos == 4)
            {
                gBattleStruct->atk5A_StateTracker = 4;
            }
            else
            {
                u16 move = GetMonData(&gPlayerParty[gBattleStruct->expGetterID], MON_DATA_MOVE1 + move_pos);
                if (IsHMMove2(move))
                {
                    PrepareStringBattle(0x13F, gActiveBattler);
                    gBattleStruct->atk5A_StateTracker = 5;
                }
                else
                {
                    u8 *ptr;

                    gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
                    ptr = gBattleTextBuff2;
                    {
                        ptr[0] = 0xFD;
                        ptr[1] = 2;
                        ptr[2] = move;
                        ptr[3] = ((move & 0xFF00) >> 8);
                        ptr += 4;
                    }
                    ptr[0] = 0xFF;
                    RemoveMonPPBonus(&gPlayerParty[gBattleStruct->expGetterID], move_pos);
                    SetMonMoveSlot(&gPlayerParty[gBattleStruct->expGetterID], gMoveToLearn, move_pos);
                    if (gBattlerPartyIndexes[0] == gBattleStruct->expGetterID && !(gBattleMons[0].status2 & STATUS2_TRANSFORMED)
                        && !(gDisableStructs[0].unk18_b & gBitTable[move_pos]))
                    {
                        RemoveBattleMonPPBonus(&gBattleMons[0], move_pos);
                        SetBattleMonMoveSlot(&gBattleMons[0], gMoveToLearn, move_pos);
                    }
                    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && gBattlerPartyIndexes[2] == gBattleStruct->expGetterID && !(gBattleMons[2].status2 & STATUS2_TRANSFORMED)
                        && !(gDisableStructs[2].unk18_b & gBitTable[move_pos]))
                    {
                        RemoveBattleMonPPBonus(&gBattleMons[2], move_pos);
                        SetBattleMonMoveSlot(&gBattleMons[2], gMoveToLearn, move_pos);
                    }
                }
            }
        }
        break;
    case 4:
        sub_8023AD8();
        gBattlescriptCurrInstr += 5;
        break;
    case 5:
        if (gBattleExecBuffer == 0)
        {
            gBattleStruct->atk5A_StateTracker = 2;
        }
        break;
    }
}

static void atk5B_yesnoboxstoplearningmove(void)
{
    switch (gBattleStruct->atk5A_StateTracker)
    {
    case 0:
        sub_8023A80();
        gBattleStruct->atk5A_StateTracker++;
        gBattleCommunication[1] = 0;
        sub_802BC6C();
        break;
    case 1:
        if (gMain.newKeys & DPAD_UP && gBattleCommunication[1] != 0)
        {
            PlaySE(SE_SELECT);
            nullsub_6();
            gBattleCommunication[1] = 0;
            sub_802BC6C();
        }
        if (gMain.newKeys & DPAD_DOWN && gBattleCommunication[1] == 0)
        {
            PlaySE(SE_SELECT);
            nullsub_6();
            gBattleCommunication[1] = 1;
            sub_802BC6C();
        }
        if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            if (gBattleCommunication[1] != 0)
                gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
            else
                gBattlescriptCurrInstr += 5;
            sub_8023AD8();
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
            sub_8023AD8();
        }
    }
}

static void atk5C_hitanimation(void)
{
    gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
    if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
        gBattlescriptCurrInstr += 2;
    else if (!(gHitMarker & HITMARKER_IGNORE_SUBSTITUTE) || !(gBattleMons[gActiveBattler].status2 & STATUS2_SUBSTITUTE) || gDisableStructs[gActiveBattler].substituteHP == 0)
    {
        EmitHitAnimation(0);
        MarkBufferBankForExecution(gActiveBattler);
        gBattlescriptCurrInstr += 2;
    }
    else
        gBattlescriptCurrInstr += 2;
}

#define MONEY_UNKNOWN ((*(u8*)(ewram_addr + 0x17000 + 0x94)))

static void atk5D_getmoneyreward(void)
{
    int i = 0;
    u8 r5 = 0;
    u32 money_to_give;
    if (gTrainerBattleOpponent == 0x400)
    {
        money_to_give = 2 * gBattleStruct->moneyMultiplier * MONEY_UNKNOWN;
    }
    else
    {
        switch(gTrainers[gTrainerBattleOpponent].partyFlags)
        {
        case 0:
            {
                const struct TrainerMonNoItemDefaultMoves *data = gTrainers[gTrainerBattleOpponent].party.NoItemDefaultMoves;
                r5 = data[gTrainers[gTrainerBattleOpponent].partySize - 1].level;
            }
            break;
        case 2:
            {
                const struct TrainerMonItemDefaultMoves *data = gTrainers[gTrainerBattleOpponent].party.ItemDefaultMoves;
                r5 = data[gTrainers[gTrainerBattleOpponent].partySize - 1].level;
            }
            break;
        case 1:
        case 3:
            {
                const struct TrainerMonItemCustomMoves *data = gTrainers[gTrainerBattleOpponent].party.ItemCustomMoves;
                r5 = data[gTrainers[gTrainerBattleOpponent].partySize - 1].level;
            }
            break;
		case 4:
			{
                const struct TrainerMonFullControl *data = gTrainers[gTrainerBattleOpponent].party.FullControl;
                r5 = data[gTrainers[gTrainerBattleOpponent].partySize - 1].level;
			}
            break;
        }
        for (; gTrainerMoney[i * 4] != 0xFF && gTrainerMoney[i * 4] != gTrainers[gTrainerBattleOpponent].trainerClass ; i++) {}

        money_to_give = (r5 << 2) * gBattleStruct->moneyMultiplier;
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            money_to_give = 2 * gTrainerMoney[i * 4 + 1] * money_to_give;
        else
            money_to_give = 1 * gTrainerMoney[i * 4 + 1] * money_to_give;
    }

    AddMoney(&gSaveBlock1.money, money_to_give);
    gBattleTextBuff1[0] = 0xFD;
    gBattleTextBuff1[1] = 1;
    gBattleTextBuff1[2] = 4;
    gBattleTextBuff1[3] = 5;
    gBattleTextBuff1[4] = (u8)(money_to_give);
    gBattleTextBuff1[5] = (u8)(money_to_give >> 8);
    gBattleTextBuff1[6] = (u8)(money_to_give >> 16);
    gBattleTextBuff1[7] = (u8)(money_to_give >> 24);
    gBattleTextBuff1[8] = 0xFF;

    gBattlescriptCurrInstr += 1;
}

/*
static u32 GetTrainerMoneyToGive(u16 trainerId)
{
    u32 i = 0;
    u32 lastMonLevel = 0;
    u32 moneyReward = 0;

    if (trainerId == SECRET_BASE_OPPONENT)
    {
        moneyReward = 20 * eSecretBaseRecord->partyLevels[0] * gBattleStruct->moneyMultiplier;
    }
    else
    {
        switch (gTrainers[trainerId].partyFlags)
        {
        case 0:
            {
                const struct TrainerMonNoItemDefaultMoves *party = gTrainers[trainerId].party.NoItemDefaultMoves;
                lastMonLevel = party[gTrainers[trainerId].partySize - 1].lvl;
            }
            break;
        case F_TRAINER_PARTY_CUSTOM_MOVESET:
            {
                const struct TrainerMonNoItemCustomMoves *party = gTrainers[trainerId].party.NoItemCustomMoves;
                lastMonLevel = party[gTrainers[trainerId].partySize - 1].lvl;
            }
            break;
        case F_TRAINER_PARTY_HELD_ITEM:
            {
                const struct TrainerMonItemDefaultMoves *party = gTrainers[trainerId].party.ItemDefaultMoves;
                lastMonLevel = party[gTrainers[trainerId].partySize - 1].lvl;
            }
            break;
        case F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM:
            {
                const struct TrainerMonItemCustomMoves *party = gTrainers[trainerId].party.ItemCustomMoves;
                lastMonLevel = party[gTrainers[trainerId].partySize - 1].lvl;
            }
            break;
        }

        for (; gTrainerMoneyTable[i].classId != 0xFF; i++)
        {
            if (gTrainerMoneyTable[i].classId == gTrainers[trainerId].trainerClass)
                break;
        }

        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            moneyReward = 4 * lastMonLevel * gBattleStruct->moneyMultiplier * 2 * gTrainerMoneyTable[i].value;
        else
            moneyReward = 4 * lastMonLevel * gBattleStruct->moneyMultiplier * gTrainerMoneyTable[i].value;
    }

    return moneyReward;
}

static void atk5D_getmoneyreward(void)
{
    u32 moneyReward = GetTrainerMoneyToGive(gTrainerBattleOpponent_A);
    if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
        moneyReward += GetTrainerMoneyToGive(gTrainerBattleOpponent_B);

    AddMoney(&gSaveBlock1Ptr->money, moneyReward);

    PREPARE_WORD_NUMBER_BUFFER(gBattleTextBuff1, 5, moneyReward)

    gBattlescriptCurrInstr++;
}
*/

static void atk5E_8025A70(void)
{
    gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
    switch (gBattleCommunication[0])
    {
    case 0:
        EmitGetAttributes(0, REQUEST_ALL_BATTLE, 0);
        MarkBufferBankForExecution(gActiveBattler);
        gBattleCommunication[0]++;
        break;
    case 1:
         if (gBattleExecBuffer == 0)
         {
            int i;
            struct BattlePokemon* bufferPoke = (struct BattlePokemon*) &gBattleBufferB[gActiveBattler][4];
            for (i = 0; i < 4; i++)
            {
                gBattleMons[gActiveBattler].moves[i] = bufferPoke->moves[i];
                gBattleMons[gActiveBattler].pp[i] = bufferPoke->pp[i];
            }
            gBattlescriptCurrInstr += 2;
         }
         break;
    }
}

static void atk5F_8025B24(void)
{
    gActiveBattler = gBankAttacker;
    gBankAttacker = gBankTarget;
    gBankTarget = gActiveBattler;
    //what is xor...
    if (gHitMarker & HITMARKER_PURSUIT_TRAP)
        gHitMarker &= ~(HITMARKER_PURSUIT_TRAP);
    else
        gHitMarker |= HITMARKER_PURSUIT_TRAP;
    gBattlescriptCurrInstr++;
}

static void atk60_incrementgamestat(void)
{
    if (GetBattlerSide(gBankAttacker) == 0)
    {
        IncrementGameStat(T2_READ_8(gBattlescriptCurrInstr + 1));
    }
    gBattlescriptCurrInstr += 2;
}

static void atk61_drawpartystatussummary(void)
{
    int i;
    struct Pokemon* party;
    struct HpAndStatus hpStatus[6];
    if (gBattleExecBuffer)
        return;

    gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
    if (GetBattlerSide(gActiveBattler) == 0)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = 0; i < 6; i++)
    {
        if (GetMonData(&party[i], MON_DATA_SPECIES2) == 0 || GetMonData(&party[i], MON_DATA_SPECIES2) == SPECIES_EGG)
        {
            hpStatus[i].hp = 0xFFFF;
            hpStatus[i].status = 0;
        }
        else
        {
            hpStatus[i].hp = GetMonData(&party[i], MON_DATA_HP);
            hpStatus[i].status = GetMonData(&party[i], MON_DATA_STATUS);
        }
    }
    EmitDrawPartyStatusSummary(0, hpStatus, 1);
    MarkBufferBankForExecution(gActiveBattler);
    gBattlescriptCurrInstr += 2;
}

static void atk62_08025C6C(void)
{
    gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
    Emitcmd49(0);
    MarkBufferBankForExecution(gActiveBattler);
    gBattlescriptCurrInstr += 2;
}

static void atk63_jumptorandomattack(void)
{
    if (T2_READ_8(gBattlescriptCurrInstr + 1))
        gCurrentMove = gRandomMove;
    else
        gChosenMove = gCurrentMove = gRandomMove;
    gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
}

static void atk64_statusanimation(void)
{
    if (gBattleExecBuffer == 0)
    {
        gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
        if (!(gStatuses3[gActiveBattler] & STATUS3_SEMI_INVULNERABLE) && gDisableStructs[gActiveBattler].substituteHP == 0 && !(gHitMarker & HITMARKER_NO_ANIMATIONS))
        {
            EmitStatusAnimation(0, 0, gBattleMons[gActiveBattler].status1);
            MarkBufferBankForExecution(gActiveBattler);
        }
        gBattlescriptCurrInstr += 2;
    }
}

static void atk65_status2animation(void)
{
    if (gBattleExecBuffer == 0)
    {
        u32 possible_to_anim;
        gActiveBattler = GetBattleBank(T1_READ_8(gBattlescriptCurrInstr + 1));
        possible_to_anim = T1_READ_32(gBattlescriptCurrInstr + 2);
        if (!(gStatuses3[gActiveBattler] & STATUS3_SEMI_INVULNERABLE) && gDisableStructs[gActiveBattler].substituteHP == 0 && !(gHitMarker & HITMARKER_NO_ANIMATIONS))
        {
            EmitStatusAnimation(0, 1, gBattleMons[gActiveBattler].status2 & possible_to_anim);
            MarkBufferBankForExecution(gActiveBattler);
        }
        gBattlescriptCurrInstr += 6;
    }
}

static void atk66_chosenstatusanimation(void)
{
    if (gBattleExecBuffer == 0)
    {
        u32 status;
        gActiveBattler = GetBattleBank(T1_READ_8(gBattlescriptCurrInstr + 1));
        status = T1_READ_32(gBattlescriptCurrInstr + 3);
        if (!(gStatuses3[gActiveBattler] & STATUS3_SEMI_INVULNERABLE) && gDisableStructs[gActiveBattler].substituteHP == 0 && !(gHitMarker & HITMARKER_NO_ANIMATIONS))
        {
            EmitStatusAnimation(0, T1_READ_8(gBattlescriptCurrInstr + 2), status);
            MarkBufferBankForExecution(gActiveBattler);
        }
        gBattlescriptCurrInstr += 7;
    }
}

static void atk67_yesnobox(void)
{
    switch (gBattleCommunication[0])
    {
    case 0:
        sub_8023A80();
        gBattleCommunication[0]++;
        gBattleCommunication[1] = 0;
        sub_802BC6C();
        break;
    case 1:
        if (gMain.newKeys & DPAD_UP && gBattleCommunication[1] != 0)
        {
            PlaySE(SE_SELECT);
            nullsub_6();
            gBattleCommunication[1] = 0;
            sub_802BC6C();
        }
        if (gMain.newKeys & DPAD_DOWN && gBattleCommunication[1] == 0)
        {
            PlaySE(SE_SELECT);
            nullsub_6();
            gBattleCommunication[1] = 1;
            sub_802BC6C();
        }
        if (gMain.newKeys & B_BUTTON)
        {
            gBattleCommunication[1] = 1;
            PlaySE(SE_SELECT);
            sub_8023AD8();
            gBattlescriptCurrInstr++;
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            sub_8023AD8();
            gBattlescriptCurrInstr++;
        }
        break;
    }
}

static void atk68_cancelallactions(void)
{
    int i;
    for (i = 0; i < gBattlersCount; i++)
    {
        gActionsByTurnOrder[i] = 0xC;
    }
    gBattlescriptCurrInstr++;
}

static void atk69_adjustsetdamage(void) //literally a copy of atk07 except theres no rand dmg modifier...
{
    u8 hold_effect, quality;
    if (gBattleMons[gBankTarget].item == ITEM_ENIGMA_BERRY)
        hold_effect = gEnigmaBerries[gBankTarget].holdEffect, quality = gEnigmaBerries[gBankTarget].holdEffectParam;
    else
    {
        hold_effect = ItemId_GetHoldEffect(gBattleMons[gBankTarget].item);
        quality = ItemId_GetHoldEffectParam(gBattleMons[gBankTarget].item);
    }

    gStringBank = gBankTarget;

    if (hold_effect == HOLD_EFFECT_FOCUS_BAND && (Random() % 100) < quality)
    {
        RecordItemBattle(gBankTarget, hold_effect);
        gSpecialStatuses[gBankTarget].focusBanded = 1;
    }
    if (gBattleMons[gBankTarget].status2 & STATUS2_SUBSTITUTE)
        goto END;
    if (gBattleMoves[gCurrentMove].effect != EFFECT_FALSE_SWIPE && !gProtectStructs[gBankTarget].endured
     && !gSpecialStatuses[gBankTarget].focusBanded)
        goto END;
    if (gBattleMons[gBankTarget].hp > gBattleMoveDamage)
        goto END;

    gBattleMoveDamage = gBattleMons[gBankTarget].hp - 1;

    if (gProtectStructs[gBankTarget].endured)
    {
        gMoveResultFlags |= MOVE_RESULT_FOE_ENDURED;
        goto END;
    }
    if (gSpecialStatuses[gBankTarget].focusBanded)
    {
        gMoveResultFlags |= MOVE_RESULT_FOE_HUNG_ON;
        gLastUsedItem = gBattleMons[gBankTarget].item;
    }

    END:
        gBattlescriptCurrInstr++;
}

void atk6A_removeitem(void)
{
    gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
    USED_HELD_ITEMS(gActiveBattler) = gBattleMons[gActiveBattler].item;

    gBattleMons[gActiveBattler].item = 0;
	gBattleMons[gActiveBattler].itemRemoved = 1;
    EmitSetMonData(0, REQUEST_HELDITEM_BATTLE, 0, 2, &gBattleMons[gActiveBattler].item);
    MarkBufferBankForExecution(gActiveBattler);
    gBattlescriptCurrInstr += 2;
}

static void atk6B_atknameinbuff1(void)
{
    gBattleTextBuff1[0] = 0xFD;
    gBattleTextBuff1[1] = 7;
    gBattleTextBuff1[2] = gBankAttacker;
    gBattleTextBuff1[3] = gBattlerPartyIndexes[gBankAttacker];
    gBattleTextBuff1[4] = 0xFF;
    gBattlescriptCurrInstr++;
}

#ifdef NONMATCHING
static void atk6C_drawlvlupbox(void)
{
    u8 r1 = 0;
    u8 r7 = 0;
    switch (gBattleStruct->atk6C_statetracker)
    {
    case 0:
        sub_802BBD4(0xB, 0, 0x1D, 0x7, r1);
        StringCopy(gStringVar4, BattleText_Format2);

    }
}

#else
NAKED
static void atk6C_drawlvlupbox(void)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x4\n\
    movs r1, 0\n\
    movs r7, 0\n\
    ldr r0, _08024928 @ =gSharedMem\n\
    mov r10, r0\n\
    ldr r4, _0802492C @ =0x0001609c\n\
    add r4, r10\n\
    ldrb r0, [r4]\n\
    cmp r0, 0x1\n\
    bne _0802491C\n\
    b _08024AF4\n\
_0802491C:\n\
    cmp r0, 0x1\n\
    bgt _08024930\n\
    cmp r0, 0\n\
    beq _0802493E\n\
    b _08024C38\n\
    .align 2, 0\n\
_08024928: .4byte gSharedMem\n\
_0802492C: .4byte 0x0001609c\n\
_08024930:\n\
    cmp r0, 0x2\n\
    bne _08024936\n\
    b _08024C04\n\
_08024936:\n\
    cmp r0, 0x3\n\
    bne _0802493C\n\
    b _08024C30\n\
_0802493C:\n\
    b _08024C38\n\
_0802493E:\n\
    str r1, [sp]\n\
    movs r0, 0xB\n\
    movs r1, 0\n\
    movs r2, 0x1D\n\
    movs r3, 0x7\n\
    bl sub_802BBD4\n\
    ldr r0, _0802499C @ =gStringVar4\n\
    ldr r1, _080249A0 @ =BattleText_Format2\n\
    bl StringCopy\n\
    adds r5, r0, 0\n\
    movs r1, 0\n\
    mov r8, r1\n\
_0802495A:\n\
    movs r2, 0\n\
    mov r9, r2\n\
    ldr r0, _080249A4 @ =gUnknown_0840165C\n\
    mov r1, r8\n\
    lsls r4, r1, 2\n\
    adds r0, r4, r0\n\
    ldr r1, [r0]\n\
    adds r0, r5, 0\n\
    bl StringAppend\n\
    adds r5, r0, 0\n\
    ldr r0, _080249A8 @ =gSharedMem\n\
    ldr r2, _080249AC @ =0x00016018\n\
    adds r0, r2\n\
    ldrb r1, [r0]\n\
    movs r0, 0x64\n\
    muls r0, r1\n\
    ldr r1, _080249B0 @ =gPlayerParty\n\
    adds r0, r1\n\
    ldr r1, _080249B4 @ =gLevelUpStatBoxStats\n\
    add r1, r8\n\
    ldrb r1, [r1]\n\
    bl GetMonData\n\
    lsls r0, 16\n\
    lsrs r1, r0, 16\n\
    mov r0, r8\n\
    cmp r0, 0x5\n\
    bhi _08024A1A\n\
    ldr r0, _080249B8 @ =_080249BC\n\
    adds r0, r4, r0\n\
    ldr r0, [r0]\n\
    mov pc, r0\n\
    .align 2, 0\n\
_0802499C: .4byte gStringVar4\n\
_080249A0: .4byte BattleText_Format2\n\
_080249A4: .4byte gUnknown_0840165C\n\
_080249A8: .4byte gSharedMem\n\
_080249AC: .4byte 0x00016018\n\
_080249B0: .4byte gPlayerParty\n\
_080249B4: .4byte gLevelUpStatBoxStats\n\
_080249B8: .4byte _080249BC\n\
    .align 2, 0\n\
_080249BC:\n\
    .4byte _080249D4\n\
    .4byte _080249E0\n\
    .4byte _080249EC\n\
    .4byte _080249F8\n\
    .4byte _08024A04\n\
    .4byte _08024A10\n\
_080249D4:\n\
    ldr r0, _080249DC @ =gSharedMem + 0x17180\n\
    ldrh r0, [r0]\n\
    b _08024A14\n\
    .align 2, 0\n\
_080249DC: .4byte gSharedMem + 0x17180\n\
_080249E0:\n\
    ldr r0, _080249E8 @ =gSharedMem + 0x17180\n\
    ldrh r0, [r0, 0x8]\n\
    b _08024A14\n\
    .align 2, 0\n\
_080249E8: .4byte gSharedMem + 0x17180\n\
_080249EC:\n\
    ldr r0, _080249F4 @ =gSharedMem + 0x17180\n\
    ldrh r0, [r0, 0x2]\n\
    b _08024A14\n\
    .align 2, 0\n\
_080249F4: .4byte gSharedMem + 0x17180\n\
_080249F8:\n\
    ldr r0, _08024A00 @ =gSharedMem + 0x17180\n\
    ldrh r0, [r0, 0xA]\n\
    b _08024A14\n\
    .align 2, 0\n\
_08024A00: .4byte gSharedMem + 0x17180\n\
_08024A04:\n\
    ldr r0, _08024A0C @ =gSharedMem + 0x17180\n\
    ldrh r0, [r0, 0x4]\n\
    b _08024A14\n\
    .align 2, 0\n\
_08024A0C: .4byte gSharedMem + 0x17180\n\
_08024A10:\n\
    ldr r0, _08024A54 @ =gSharedMem + 0x17180\n\
    ldrh r0, [r0, 0x6]\n\
_08024A14:\n\
    subs r0, r1, r0\n\
    lsls r0, 16\n\
    lsrs r7, r0, 16\n\
_08024A1A:\n\
    lsls r0, r7, 16\n\
    asrs r0, 16\n\
    cmp r0, 0\n\
    bge _08024A2C\n\
    negs r0, r0\n\
    lsls r0, 16\n\
    lsrs r7, r0, 16\n\
    movs r1, 0x1\n\
    add r9, r1\n\
_08024A2C:\n\
    movs r0, 0xFC\n\
    strb r0, [r5]\n\
    movs r0, 0x13\n\
    strb r0, [r5, 0x1]\n\
    movs r1, 0x1\n\
    mov r2, r8\n\
    ands r1, r2\n\
    lsls r0, r1, 3\n\
    adds r0, r1\n\
    adds r0, 0x5\n\
    lsls r0, 3\n\
    adds r0, 0x6\n\
    strb r0, [r5, 0x2]\n\
    adds r5, 0x3\n\
    mov r0, r9\n\
    cmp r0, 0\n\
    beq _08024A5C\n\
    ldr r1, _08024A58 @ =BattleText_Dash\n\
    b _08024A5E\n\
    .align 2, 0\n\
_08024A54: .4byte gSharedMem + 0x17180\n\
_08024A58: .4byte BattleText_Dash\n\
_08024A5C:\n\
    ldr r1, _08024AA4 @ =BattleText_Plus\n\
_08024A5E:\n\
    adds r0, r5, 0\n\
    bl StringCopy\n\
    adds r5, r0, 0\n\
    movs r6, 0xFC\n\
    strb r6, [r5]\n\
    movs r4, 0x14\n\
    strb r4, [r5, 0x1]\n\
    movs r0, 0x6\n\
    strb r0, [r5, 0x2]\n\
    adds r5, 0x3\n\
    lsls r1, r7, 16\n\
    asrs r1, 16\n\
    adds r0, r5, 0\n\
    movs r2, 0x1\n\
    movs r3, 0x2\n\
    bl ConvertIntToDecimalStringN\n\
    adds r5, r0, 0\n\
    strb r6, [r5]\n\
    strb r4, [r5, 0x1]\n\
    movs r0, 0\n\
    strb r0, [r5, 0x2]\n\
    adds r5, 0x3\n\
    movs r0, 0x1\n\
    mov r1, r8\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _08024AA8\n\
    movs r0, 0xFE\n\
    strb r0, [r5]\n\
    movs r0, 0xFF\n\
    strb r0, [r5, 0x1]\n\
    adds r5, 0x1\n\
    b _08024AB8\n\
    .align 2, 0\n\
_08024AA4: .4byte BattleText_Plus\n\
_08024AA8:\n\
    strb r6, [r5]\n\
    movs r0, 0x11\n\
    strb r0, [r5, 0x1]\n\
    movs r0, 0x8\n\
    strb r0, [r5, 0x2]\n\
    adds r5, 0x3\n\
    movs r0, 0xFF\n\
    strb r0, [r5]\n\
_08024AB8:\n\
    movs r2, 0x1\n\
    add r8, r2\n\
    mov r0, r8\n\
    cmp r0, 0x5\n\
    bgt _08024AC4\n\
    b _0802495A\n\
_08024AC4:\n\
    ldr r4, _08024AE4 @ =gUnknown_03004210\n\
    ldr r1, _08024AE8 @ =gStringVar4\n\
    adds r2, 0xFF\n\
    movs r0, 0x1\n\
    str r0, [sp]\n\
    adds r0, r4, 0\n\
    movs r3, 0xC\n\
    bl Text_InitWindow\n\
    adds r0, r4, 0\n\
    bl Text_PrintWindow8002F44\n\
    ldr r1, _08024AEC @ =gSharedMem\n\
    ldr r2, _08024AF0 @ =0x0001609c\n\
    adds r1, r2\n\
    b _08024BEA\n\
    .align 2, 0\n\
_08024AE4: .4byte gUnknown_03004210\n\
_08024AE8: .4byte gStringVar4\n\
_08024AEC: .4byte gSharedMem\n\
_08024AF0: .4byte 0x0001609c\n\
_08024AF4:\n\
    ldr r0, _08024B94 @ =gMain\n\
    ldrh r0, [r0, 0x2E]\n\
    cmp r0, 0\n\
    bne _08024AFE\n\
    b _08024C38\n\
_08024AFE:\n\
    movs r0, 0x5\n\
    bl PlaySE\n\
    ldr r0, _08024B98 @ =gStringVar4\n\
    ldr r1, _08024B9C @ =BattleText_Format2\n\
    bl StringCopy\n\
    adds r5, r0, 0\n\
    movs r0, 0\n\
    mov r8, r0\n\
    mov r9, r0\n\
    movs r6, 0xFC\n\
    movs r7, 0x14\n\
    ldr r1, _08024BA0 @ =0x00016018\n\
    add r10, r1\n\
_08024B1C:\n\
    ldr r1, _08024BA4 @ =gUnknown_0840165C\n\
    mov r2, r8\n\
    lsls r0, r2, 2\n\
    adds r0, r1\n\
    ldr r1, [r0]\n\
    adds r0, r5, 0\n\
    bl StringAppend\n\
    adds r5, r0, 0\n\
    mov r0, r10\n\
    ldrb r1, [r0]\n\
    movs r0, 0x64\n\
    muls r0, r1\n\
    ldr r1, _08024BA8 @ =gPlayerParty\n\
    adds r0, r1\n\
    ldr r1, _08024BAC @ =gLevelUpStatBoxStats\n\
    add r1, r8\n\
    ldrb r1, [r1]\n\
    bl GetMonData\n\
    adds r1, r0, 0\n\
    strb r6, [r5]\n\
    movs r0, 0x13\n\
    strb r0, [r5, 0x1]\n\
    movs r4, 0x1\n\
    mov r2, r8\n\
    ands r4, r2\n\
    lsls r0, r4, 3\n\
    adds r0, r4\n\
    adds r0, 0x5\n\
    lsls r0, 3\n\
    adds r0, 0x6\n\
    strb r0, [r5, 0x2]\n\
    adds r5, 0x3\n\
    strb r6, [r5]\n\
    strb r7, [r5, 0x1]\n\
    movs r0, 0x6\n\
    strb r0, [r5, 0x2]\n\
    adds r5, 0x3\n\
    lsls r1, 16\n\
    asrs r1, 16\n\
    adds r0, r5, 0\n\
    movs r2, 0x1\n\
    movs r3, 0x3\n\
    bl ConvertIntToDecimalStringN\n\
    adds r5, r0, 0\n\
    strb r6, [r5]\n\
    strb r7, [r5, 0x1]\n\
    mov r0, r9\n\
    strb r0, [r5, 0x2]\n\
    adds r5, 0x3\n\
    cmp r4, 0\n\
    beq _08024BB0\n\
    movs r0, 0xFE\n\
    strb r0, [r5]\n\
    movs r0, 0xFF\n\
    strb r0, [r5, 0x1]\n\
    adds r5, 0x1\n\
    b _08024BC0\n\
    .align 2, 0\n\
_08024B94: .4byte gMain\n\
_08024B98: .4byte gStringVar4\n\
_08024B9C: .4byte BattleText_Format2\n\
_08024BA0: .4byte 0x00016018\n\
_08024BA4: .4byte gUnknown_0840165C\n\
_08024BA8: .4byte gPlayerParty\n\
_08024BAC: .4byte gLevelUpStatBoxStats\n\
_08024BB0:\n\
    strb r6, [r5]\n\
    movs r0, 0x11\n\
    strb r0, [r5, 0x1]\n\
    movs r0, 0x8\n\
    strb r0, [r5, 0x2]\n\
    adds r5, 0x3\n\
    movs r0, 0xFF\n\
    strb r0, [r5]\n\
_08024BC0:\n\
    movs r1, 0x1\n\
    add r8, r1\n\
    mov r2, r8\n\
    cmp r2, 0x5\n\
    ble _08024B1C\n\
    ldr r4, _08024BF4 @ =gUnknown_03004210\n\
    ldr r1, _08024BF8 @ =gStringVar4\n\
    movs r2, 0x80\n\
    lsls r2, 1\n\
    movs r0, 0x1\n\
    str r0, [sp]\n\
    adds r0, r4, 0\n\
    movs r3, 0xC\n\
    bl Text_InitWindow\n\
    adds r0, r4, 0\n\
    bl Text_PrintWindow8002F44\n\
    ldr r1, _08024BFC @ =gSharedMem\n\
    ldr r0, _08024C00 @ =0x0001609c\n\
    adds r1, r0\n\
_08024BEA:\n\
    ldrb r0, [r1]\n\
    adds r0, 0x1\n\
    strb r0, [r1]\n\
    b _08024C38\n\
    .align 2, 0\n\
_08024BF4: .4byte gUnknown_03004210\n\
_08024BF8: .4byte gStringVar4\n\
_08024BFC: .4byte gSharedMem\n\
_08024C00: .4byte 0x0001609c\n\
_08024C04:\n\
    ldr r0, _08024C2C @ =gMain\n\
    ldrh r0, [r0, 0x2E]\n\
    cmp r0, 0\n\
    beq _08024C38\n\
    movs r0, 0x5\n\
    bl PlaySE\n\
    movs r0, 0x1\n\
    str r0, [sp]\n\
    movs r0, 0xB\n\
    movs r1, 0\n\
    movs r2, 0x1D\n\
    movs r3, 0x7\n\
    bl sub_802BBD4\n\
    ldrb r0, [r4]\n\
    adds r0, 0x1\n\
    strb r0, [r4]\n\
    b _08024C38\n\
    .align 2, 0\n\
_08024C2C: .4byte gMain\n\
_08024C30:\n\
    ldr r1, _08024C48 @ =gBattlescriptCurrInstr\n\
    ldr r0, [r1]\n\
    adds r0, 0x1\n\
    str r0, [r1]\n\
_08024C38:\n\
    add sp, 0x4\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .align 2, 0\n\
_08024C48: .4byte gBattlescriptCurrInstr\n\
        .syntax divided");
}

#endif

static void atk6D_resetsentmonsvalue(void)
{
    ResetSentPokesToOpponentValue();
    gBattlescriptCurrInstr++;
}

static void atk6E_setatktoplayer0(void)
{
    gBankAttacker = GetBattlerAtPosition(0);
    gBattlescriptCurrInstr++;
}

static void atk6F_makevisible(void)
{
    gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
    EmitSpriteInvisibility(0, 0);
    MarkBufferBankForExecution(gActiveBattler);
    gBattlescriptCurrInstr += 2;
}

static void atk70_recordlastability(void)
{
    gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
    RecordAbilityBattle(gActiveBattler, gLastUsedAbility);
    gBattlescriptCurrInstr += 1; //buggy, should be += 2, one byte for command, one byte for argument...
}

void sub_8024CEC(void)
{
    gBattleTextBuff2[0] = 0xFD;
    gBattleTextBuff2[1] = 2;
    gBattleTextBuff2[2] = (gMoveToLearn);
    gBattleTextBuff2[3] = uBYTE1_16(gMoveToLearn);
    gBattleTextBuff2[4] = 0xFF;
}

static void atk71_buffermovetolearn(void)
{
    sub_8024CEC();
    gBattlescriptCurrInstr++;
}

static void atk72_jumpifplayerran(void)
{
    if (TryRunFromBattle(gBank1))
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    else
        gBattlescriptCurrInstr += 5;
}

static void atk73_hpthresholds(void)
{
    u8 opposing_bank;
    s32 result;
    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
    {
        gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
        opposing_bank = gActiveBattler ^ 1;

        result = gBattleMons[opposing_bank].hp * 100 / gBattleMons[opposing_bank].maxHP;
        if (result == 0)
            result = 1;

        if (result >= 70 || !gBattleMons[opposing_bank].hp)
            gBattleStruct->hpScale = 0;
        else if (result >= 40)
            gBattleStruct->hpScale = 1;
        else if (result >= 10)
            gBattleStruct->hpScale = 2;
        else
            gBattleStruct->hpScale = 3;
    }

    gBattlescriptCurrInstr += 2;
}

static void atk74_hpthresholds2(void)
{
    u8 opposing_bank;
    u8 hp_switchout;
    s32 result;
    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
    {
        gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
        opposing_bank = gActiveBattler ^ 1;
        hp_switchout = ewram160BCarr(GetBattlerSide(opposing_bank)); //gBattleStruct->HP_OnSwitchout[GetBattlerSide(opposing_bank)];
        result = (hp_switchout - gBattleMons[opposing_bank].hp) * 100 / hp_switchout;

        if (gBattleMons[opposing_bank].hp >= hp_switchout)
            gBattleStruct->hpScale = 0;
        else if (result <= 29)
            gBattleStruct->hpScale = 1;
        else if (result <= 69)
            gBattleStruct->hpScale = 2;
        else
            gBattleStruct->hpScale = 3;
    }

    gBattlescriptCurrInstr += 2;
}

static void atk75_useitemonopponent(void)
{
    gBankInMenu = gBankAttacker;
    PokemonUseItemEffects(&gEnemyParty[gBattlerPartyIndexes[gBankAttacker]], gLastUsedItem, gBattlerPartyIndexes[gBankAttacker], 0, 1);
    gBattlescriptCurrInstr += 1;
}

static void atk76_various(void)
{
    gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
    switch (T2_READ_8(gBattlescriptCurrInstr + 2))
    {
    case 0:
        CancelMultiTurnMoves(gActiveBattler);
        break;
    case 1:
        {
            u8 side;
            gBankAttacker = gBankTarget;
            side = GetBattlerSide(gBankAttacker) ^ 1;
            if (gSideTimers[side].followmeTimer && gBattleMons[gSideTimers[side].followmeTarget].hp)
                gBankTarget = gSideTimers[side].followmeTarget;
            else
                gBankTarget = gActiveBattler;
        }
        break;
    case 2:
        gBattleCommunication[0] = CanRunFromBattle();
        break;
    case 3:
        gBankTarget = GetMoveTarget(gCurrentMove, 0);
        break;
    case 4:
        if (gHitMarker & HITMARKER_FAINTED(gActiveBattler))
            gBattleCommunication[0] = 1;
        else
            gBattleCommunication[0] = 0;
        break;
    case 5:
        gSpecialStatuses[gActiveBattler].intimidatedPoke = 0;
        gSpecialStatuses[gActiveBattler].traced = 0;
        break;
    case 6:
        {
            int i;
            u16* choiced_move;
            if (gBattlerPartyIndexes[0] == gBattleStruct->expGetterID)
                goto ACTIVE_0;
            if (gBattlerPartyIndexes[2] != gBattleStruct->expGetterID)
                break;
            if (gBattlerPartyIndexes[0] == gBattlerPartyIndexes[2])
            {
                ACTIVE_0:
                    gActiveBattler = 0;
            }
            else
                gActiveBattler = 2;

            choiced_move = CHOICED_MOVE(gActiveBattler);
            for (i = 0; i < 4; i++)
            {
                if (gBattleMons[gActiveBattler].moves[i] == *choiced_move)
                    break;
            }
            if (i == 4)
                *choiced_move = 0;
        }
        break;
    }

    gBattlescriptCurrInstr += 3;
}

static void atk77_setprotectlike(void) //protect and endure
{
    bool8 not_last_turn = 1;
    u16 last_move = gUnknown_02024C4C[gBankAttacker];
	u16 protectRate;

    if (last_move != MOVE_PROTECT && last_move != MOVE_DETECT && last_move != MOVE_ENDURE && last_move != MOVE_SPIKY_SHIELD)
        gDisableStructs[gBankAttacker].protectUses = 0;
    if (gCurrentTurnActionNumber == (gBattlersCount - 1))
        not_last_turn = 0;
	
	if (gDisableStructs[gBankAttacker].protectUses > 6)
		protectRate = sProtectSuccessRates[6];
	else
		protectRate = sProtectSuccessRates[gDisableStructs[gBankAttacker].protectUses];

    if (protectRate >= Random() && not_last_turn)
    {
        if (gBattleMoves[gCurrentMove].effect == EFFECT_PROTECT)
        {
            gProtectStructs[gBankAttacker].protected = 1;
			gProtectStructs[gBankAttacker].spikyShield = 0;
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;
			if (gCurrentMove == MOVE_SPIKY_SHIELD)
			{
				gProtectStructs[gBankAttacker].spikyShield = 1;
			}
        }
        else if (gBattleMoves[gCurrentMove].effect == EFFECT_ENDURE)
        {
            gProtectStructs[gBankAttacker].endured = 1;
            gBattleCommunication[MULTISTRING_CHOOSER] = 1;
        }
        gDisableStructs[gBankAttacker].protectUses++;
    }
    else
    {
        gDisableStructs[gBankAttacker].protectUses = 0;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
        gMoveResultFlags |= MOVE_RESULT_MISSED;
    }

    gBattlescriptCurrInstr++;
}

static void atk78_faintifabilitynotdamp(void)
{
    if (gBattleExecBuffer)
        return;

	if (gBattleMons[gBankAttacker].ability == ABILITY_MOLD_BREAKER)
		gBankTarget = gBattlersCount;
	else
	{
		for (gBankTarget = 0; gBankTarget < gBattlersCount; gBankTarget++)
		{
			if (gBattleMons[gBankTarget].ability == ABILITY_DAMP)
				break;
		}
	}

    if (gBankTarget == gBattlersCount)
    {
        gActiveBattler = gBankAttacker;
        gBattleMoveDamage = gBattleMons[gActiveBattler].hp;
        EmitHealthBarUpdate(0, 0x7FFF);
        MarkBufferBankForExecution(gActiveBattler);
        gBattlescriptCurrInstr++;

        for (gBankTarget = 0; gBankTarget < gBattlersCount; gBankTarget++)
        {
            if (gBankTarget == gBankAttacker)
                continue;
            if (!(gAbsentBattlerFlags & gBitTable[gBankTarget]))
                break;
        }
    }
    else
    {
        gLastUsedAbility = ABILITY_DAMP;
        RecordAbilityBattle(gBankTarget, gBattleMons[gBankTarget].ability);
        gBattlescriptCurrInstr = BattleScript_DampStopsExplosion;
    }
}

static void atk79_setatkhptozero(void)
{
    if (gBattleExecBuffer)
        return;

    gActiveBattler = gBankAttacker;
    gBattleMons[gActiveBattler].hp = 0;
    EmitSetMonData(0, REQUEST_HP_BATTLE, 0, 2, &gBattleMons[gActiveBattler].hp);
    MarkBufferBankForExecution(gActiveBattler);

    gBattlescriptCurrInstr++;
}

static void atk7A_jumpifnexttargetvalid(void) //used by intimidate to loop through all targets
{
    u8* jump_loc = T1_READ_PTR(gBattlescriptCurrInstr + 1);

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        for (gBankTarget++; ; gBankTarget++)
        {
            if (gBankTarget == gBankAttacker)
                continue;
            if (!(gAbsentBattlerFlags & gBitTable[gBankTarget]))
                break;
        }

        if (gBankTarget >= gBattlersCount)
            gBattlescriptCurrInstr += 5;
        else
            gBattlescriptCurrInstr = jump_loc;
    }
    else
        gBattlescriptCurrInstr += 5;
}

static void atk7B_tryhealhalfhealth(void)
{
    u8* fail_loc = T1_READ_PTR(gBattlescriptCurrInstr + 1);

    if (T2_READ_8(gBattlescriptCurrInstr + 5) == 1)
        gBankTarget = gBankAttacker;

    gBattleMoveDamage = gBattleMons[gBankTarget].maxHP / 2;
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;
    gBattleMoveDamage *= -1;

    if (gBattleMons[gBankTarget].hp == gBattleMons[gBankTarget].maxHP)
        gBattlescriptCurrInstr = fail_loc;
    else
        gBattlescriptCurrInstr += 6;
}

static void atk7C_trymirrormove(void)
{
    u16 r7 = ewram160ACarr2(0, gBankAttacker) | (ewram160ACarr2(1, gBankAttacker) << 8);
    u16 r6 = ewram16100arr2(0, gBankAttacker) | (ewram16100arr2(1, gBankAttacker) << 8);
    u16 r5 = ewram16100arr2(2, gBankAttacker) | (ewram16100arr2(3, gBankAttacker) << 8);

    if (r7 != 0 && r7 != 0xFFFF)
    {
        gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
        gCurrentMove = r7;
        gBankTarget = GetMoveTarget(gCurrentMove, 0);
        gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
    }
    else if (r6 != 0 && r5 != 0 && r6 != 0xFFFF && r5 != 0xFFFF)
    {
        gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
        if (Random() & 1)
            gCurrentMove = r6;
        else
            gCurrentMove = r5;
        gBankTarget = GetMoveTarget(gCurrentMove, 0);
        gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
    }
    else if (r6 != 0 && r6 != 0xFFFF)
    {
        gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
        gCurrentMove = r6;
        gBankTarget = GetMoveTarget(gCurrentMove, 0);
        gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
    }
    else if (r5 != 0 && r5 != 0xFFFF)
    {
        gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
        gCurrentMove = r5;
        gBankTarget = GetMoveTarget(gCurrentMove, 0);
        gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
    }
    else
    {
        gSpecialStatuses[gBankAttacker].flag20 = 1;
        gBattlescriptCurrInstr++;
    }
}

static void atk7D_setrain(void)
{
    if (gBattleWeather & WEATHER_RAIN_ANY)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
    }
    else
    {
        gBattleWeather = WEATHER_RAIN_TEMPORARY;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
        gWishFutureKnock.weatherDuration = 5;
    }
    gBattlescriptCurrInstr++;
}

static void atk7E_setreflect(void)
{
    if (gSideAffecting[GetBattlerPosition(gBankAttacker) & 1] & SIDE_STATUS_REFLECT)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    else
    {
        gSideAffecting[GetBattlerPosition(gBankAttacker) & 1] |= SIDE_STATUS_REFLECT;
        gSideTimers[GetBattlerPosition(gBankAttacker) & 1].reflectTimer = 5;
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && CountAliveMons(1) == 2)
            gBattleCommunication[MULTISTRING_CHOOSER] = 2;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    gBattlescriptCurrInstr++;
}

static void atk7F_setseeded(void)
{
    if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT || gStatuses3[gBankTarget] & STATUS3_LEECHSEED)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    else if (gBattleMons[gBankTarget].type1 == TYPE_GRASS || gBattleMons[gBankTarget].type2 == TYPE_GRASS)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
    }
    else
    {
        gStatuses3[gBankTarget] |= gBankAttacker;
        gStatuses3[gBankTarget] |= STATUS3_LEECHSEED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }

    gBattlescriptCurrInstr++;
}

static void atk80_manipulatedamage(void)
{
    switch (T2_READ_8(gBattlescriptCurrInstr + 1))
    {
    case 0:
        gBattleMoveDamage *= -1;
        break;
    case 1:
        gBattleMoveDamage /= 2;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        if ((gBattleMons[gBankTarget].maxHP / 2) < gBattleMoveDamage)
            gBattleMoveDamage = gBattleMons[gBankTarget].maxHP / 2;
        break;
    case 2:
        gBattleMoveDamage *= 2;
        break;
    }

    gBattlescriptCurrInstr += 2;
}

static void atk81_trysetrest(void)
{
    u8* fail_loc = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    gActiveBattler = gBankTarget = gBankAttacker;
    gBattleMoveDamage = gBattleMons[gBankTarget].maxHP * (-1);
    if (gBattleMons[gBankTarget].hp == gBattleMons[gBankTarget].maxHP)
        gBattlescriptCurrInstr = fail_loc;
    else
    {
        if (gBattleMons[gBankTarget].status1 & ((u8)(~STATUS_SLEEP)))
            gBattleCommunication[MULTISTRING_CHOOSER] = 1;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;

        gBattleMons[gBankTarget].status1 = 3;
        EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
        MarkBufferBankForExecution(gActiveBattler);
        gBattlescriptCurrInstr += 5;
    }
}

static void atk82_jumpifnotfirstturn(void)
{
    u8* jump_loc = T1_READ_PTR(gBattlescriptCurrInstr + 1);

    if (gDisableStructs[gBankAttacker].isFirstTurn)
        gBattlescriptCurrInstr += 5;
    else
        gBattlescriptCurrInstr = jump_loc;
}

static void atk83_nop(void)
{
    gBattlescriptCurrInstr++;
}

bool8 UproarWakeUpCheck(u8 bank)
{
    int i;
    for (i = 0; i < gBattlersCount; i++)
    {
        if (!(gBattleMons[i].status2 & STATUS2_UPROAR) || gBattleMons[bank].ability == ABILITY_SOUNDPROOF) //wtf gamefreak, you should check this only once, not every time in a loop...
            continue;
        gBattleStruct->scriptingActive = i;
        if (gBankTarget == 0xFF)
            gBankTarget = i;
        else if (gBankTarget == i)
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = 1;
        break;
    }
    if (i == gBattlersCount)
        return 0;
    else
        return 1;
}

static void atk84_jumpifcantmakeasleep(void)
{
    u8* jump_loc = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    if (UproarWakeUpCheck(gBankTarget))
        gBattlescriptCurrInstr = jump_loc;
    else if (gBattleMons[gBankTarget].ability == ABILITY_INSOMNIA || gBattleMons[gBankTarget].ability == ABILITY_VITAL_SPIRIT)
    {
        gLastUsedAbility = gBattleMons[gBankTarget].ability;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
        gBattlescriptCurrInstr = jump_loc;
        RecordAbilityBattle(gBankTarget, gLastUsedAbility);
    }
    else
    {
        gBattlescriptCurrInstr += 5;
    }
}

static void atk85_stockpile(void)
{
    if (gDisableStructs[gBankAttacker].stockpileCounter == 3)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    else
    {
        gDisableStructs[gBankAttacker].stockpileCounter++;
        gBattleTextBuff1[0] = 0xFD;
        gBattleTextBuff1[1] = 1;
        gBattleTextBuff1[2] = 1;
        gBattleTextBuff1[3] = 1;
        gBattleTextBuff1[4] = gDisableStructs[gBankAttacker].stockpileCounter;
        gBattleTextBuff1[5] = 0xFF;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    gBattlescriptCurrInstr++;
}

static void atk86_stockpiletobasedamage(void)
{
    u8* jump_loc = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    if (gDisableStructs[gBankAttacker].stockpileCounter == 0)
    {
        gBattlescriptCurrInstr = jump_loc;
    }
    else
    {
        if (gBattleCommunication[6] != 1)
        {
            gBattleMoveDamage = CalculateBaseDamage(&gBattleMons[gBankAttacker], &gBattleMons[gBankTarget], gCurrentMove,
                                                    gSideAffecting[GetBattlerPosition(gBankTarget) & 1], 0,
                                                    0, gBankAttacker, gBankTarget)
                                * gDisableStructs[gBankAttacker].stockpileCounter;
            gBattleStruct->animTurn = gDisableStructs[gBankAttacker].stockpileCounter;

            if (gProtectStructs[gBankAttacker].helpingHand)
                gBattleMoveDamage = gBattleMoveDamage * 15 / 10;
        }
        gDisableStructs[gBankAttacker].stockpileCounter = 0;
        gBattlescriptCurrInstr += 5;
    }
}

static void atk87_stockpiletohpheal(void)
{
    u8* jump_loc = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    if (gDisableStructs[gBankAttacker].stockpileCounter == 0)
    {
        gBattlescriptCurrInstr = jump_loc;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    else if (gBattleMons[gBankAttacker].maxHP == gBattleMons[gBankAttacker].hp)
    {
        gDisableStructs[gBankAttacker].stockpileCounter = 0;
        gBattlescriptCurrInstr = jump_loc;
        gBankTarget = gBankAttacker;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    else
    {
        gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP / (1 << (3 - gDisableStructs[gBankAttacker].stockpileCounter));
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMoveDamage *= -1;
        gBattleStruct->animTurn = gDisableStructs[gBankAttacker].stockpileCounter;
        gDisableStructs[gBankAttacker].stockpileCounter = 0;
        gBattlescriptCurrInstr += 5;
        gBankTarget = gBankAttacker;
    }
}

static void atk88_negativedamage(void)
{
	if (gCurrentMove == MOVE_DRAIN_KISS)
		gBattleMoveDamage = -(gHpDealt * 3 / 4);
	else
		gBattleMoveDamage = -(gHpDealt / 2);
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = -1;
    gBattlescriptCurrInstr++;
}

static u8 ChangeStatBuffs(s8 statValue, u8 statId, u8 flags, const u8 *BS_ptr)
{
    bool8 certain = FALSE;
    bool8 notProtectAffected = FALSE;
    u32 index;
    bool8 contrary;

    if (flags & MOVE_EFFECT_AFFECTS_USER)
        gActiveBattler = gBankAttacker;
    else
        gActiveBattler = gBankTarget;

    flags &= ~(MOVE_EFFECT_AFFECTS_USER);

    if (flags & MOVE_EFFECT_CERTAIN)
        certain++;
    flags &= ~(MOVE_EFFECT_CERTAIN);

    if (flags & STAT_CHANGE_NOT_PROTECT_AFFECTED)
        notProtectAffected++;
    flags &= ~(STAT_CHANGE_NOT_PROTECT_AFFECTED);

    PREPARE_STAT_BUFFER(gBattleTextBuff1, statId)
    
    contrary = gBattleMons[gActiveBattler].ability == ABILITY_CONTRARY;

    if ((!contrary && ((statValue << 0x18) < 0)) || 
        ( contrary && ((statValue << 0x18) >= 0))) // stat decrease
    {
        if (gSideTimers[GET_BATTLER_SIDE(gActiveBattler)].mistTimer
            && !certain && gCurrentMove != MOVE_CURSE)
        {
            if (flags == STAT_CHANGE_BS_PTR)
            {
                if (gSpecialStatuses[gActiveBattler].statLowered)
                {
                    gBattlescriptCurrInstr = BS_ptr;
                }
                else
                {
                    BattleScriptPush(BS_ptr);
                    gBattleStruct->scriptingActive = gActiveBattler;
                    gBattlescriptCurrInstr = BattleScript_MistProtected;
                    gSpecialStatuses[gActiveBattler].statLowered = 1;
                }
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if (gCurrentMove != MOVE_CURSE
                 && notProtectAffected != TRUE && JumpIfMoveAffectedByProtect(0))
        {
            gBattlescriptCurrInstr = BattleScript_ButItFailed;
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if ((gBattleMons[gActiveBattler].ability == ABILITY_CLEAR_BODY
                  || gBattleMons[gActiveBattler].ability == ABILITY_WHITE_SMOKE)
                 && !certain && gCurrentMove != MOVE_CURSE)
        {
            if (flags == STAT_CHANGE_BS_PTR)
            {
                if (gSpecialStatuses[gActiveBattler].statLowered)
                {
                    gBattlescriptCurrInstr = BS_ptr;
                }
                else
                {
                    BattleScriptPush(BS_ptr);
                    gBattleStruct->scriptingActive = gActiveBattler;
                    gBattlescriptCurrInstr = BattleScript_AbilityNoStatLoss;
                    gLastUsedAbility = gBattleMons[gActiveBattler].ability;
                    RecordAbilityBattle(gActiveBattler, gLastUsedAbility);
                    gSpecialStatuses[gActiveBattler].statLowered = 1;
                }
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if (gBattleMons[gActiveBattler].ability == ABILITY_KEEN_EYE
                 && !certain && statId == STAT_STAGE_ACC)
        {
            if (flags == STAT_CHANGE_BS_PTR)
            {
                BattleScriptPush(BS_ptr);
                gBattleStruct->scriptingActive = gActiveBattler;
                gBattlescriptCurrInstr = BattleScript_AbilityNoSpecificStatLoss;
                gLastUsedAbility = gBattleMons[gActiveBattler].ability;
                RecordAbilityBattle(gActiveBattler, gLastUsedAbility);
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if (gBattleMons[gActiveBattler].ability == ABILITY_HYPER_CUTTER
                 && !certain && statId == STAT_STAGE_ATK)
        {
            if (flags == STAT_CHANGE_BS_PTR)
            {
                BattleScriptPush(BS_ptr);
                gBattleStruct->scriptingActive = gActiveBattler;
                gBattlescriptCurrInstr = BattleScript_AbilityNoSpecificStatLoss;
                gLastUsedAbility = gBattleMons[gActiveBattler].ability;
                RecordAbilityBattle(gActiveBattler, gLastUsedAbility);
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
		else if (gBattleMons[gActiveBattler].ability == ABILITY_BIG_PECKS
		          && !certain && statId == STAT_STAGE_DEF)
		{
            if (flags == STAT_CHANGE_BS_PTR)
            {
                BattleScriptPush(BS_ptr);
                gBattleStruct->scriptingActive = gActiveBattler;
                gBattlescriptCurrInstr = BattleScript_AbilityNoSpecificStatLoss;
                gLastUsedAbility = gBattleMons[gActiveBattler].ability;
                RecordAbilityBattle(gActiveBattler, gLastUsedAbility);
            }
            return STAT_CHANGE_DIDNT_WORK;
		}
        else if (gBattleMons[gActiveBattler].ability == ABILITY_SHIELD_DUST && flags == 0)
        {
            return STAT_CHANGE_DIDNT_WORK;
        }
        else // try to decrease
        {
            statValue = -GET_STAT_BUFF_VALUE(statValue);
            gBattleTextBuff2[0] = B_BUFF_PLACEHOLDER_BEGIN;
            index = 1;
            if (statValue == -2)
            {
                gBattleTextBuff2[1] = B_BUFF_STRING;
                gBattleTextBuff2[2] = STRINGID_STATHARSHLY;
                gBattleTextBuff2[3] = STRINGID_STATHARSHLY >> 8;
                index = 4;
            }
            gBattleTextBuff2[index] = B_BUFF_STRING;
            index++;
            gBattleTextBuff2[index] = STRINGID_STATFELL;
            index++;
            gBattleTextBuff2[index] = STRINGID_STATFELL >> 8;
            index++;
            gBattleTextBuff2[index] = B_BUFF_EOS;

            if (gBattleMons[gActiveBattler].statStages[statId] == 0)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
                gBattleTextBuff2[0] = B_BUFF_PLACEHOLDER_BEGIN;
                gBattleTextBuff2[1] = B_BUFF_STRING;
                gBattleTextBuff2[2] = (u8)439; // STRINGID_LOWER
                gBattleTextBuff2[3] = 439 >> 8;
                gBattleTextBuff2[4] = B_BUFF_EOS;
            }
            else
                gBattleCommunication[MULTISTRING_CHOOSER] = (gBankTarget == gActiveBattler);

        }
    }
    else // stat increase
    {
        statValue = GET_STAT_BUFF_VALUE(statValue);
        gBattleTextBuff2[0] = B_BUFF_PLACEHOLDER_BEGIN;
        index = 1;
        if (statValue == 2)
        {
            gBattleTextBuff2[1] = B_BUFF_STRING;
            gBattleTextBuff2[2] = STRINGID_STATSHARPLY;
            gBattleTextBuff2[3] = STRINGID_STATSHARPLY >> 8;
            index = 4;
        }
		else if (statValue == 3)
		{
            gBattleTextBuff2[1] = B_BUFF_STRING;
            gBattleTextBuff2[2] = (u8)398; // STRINGID_DRASTICALLY
            gBattleTextBuff2[3] = 398 >> 8;
            index = 4;
		}
        gBattleTextBuff2[index] = B_BUFF_STRING;
        index++;
        gBattleTextBuff2[index] = STRINGID_STATROSE;
        index++;
        gBattleTextBuff2[index] = STRINGID_STATROSE >> 8;
        index++;
        gBattleTextBuff2[index] = B_BUFF_EOS;

        if (gBattleMons[gActiveBattler].statStages[statId] == 0xC)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = 2;
            gBattleTextBuff2[0] = B_BUFF_PLACEHOLDER_BEGIN;
            gBattleTextBuff2[1] = B_BUFF_STRING;
            gBattleTextBuff2[2] = (u8)438; // STRING_ID_HIGHER
            gBattleTextBuff2[3] = 438 >> 8;
            gBattleTextBuff2[4] = B_BUFF_EOS;
        }
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = (gBankTarget == gActiveBattler);
    }

    gBattleMons[gActiveBattler].statStages[statId] += statValue;
    if (gBattleMons[gActiveBattler].statStages[statId] < 0)
        gBattleMons[gActiveBattler].statStages[statId] = 0;
    if (gBattleMons[gActiveBattler].statStages[statId] > 0xC)
        gBattleMons[gActiveBattler].statStages[statId] = 0xC;

    if (gBattleCommunication[MULTISTRING_CHOOSER] == 2 && flags & STAT_CHANGE_BS_PTR)
        gMoveResultFlags |= MOVE_RESULT_MISSED;

    if (gBattleCommunication[MULTISTRING_CHOOSER] == 2 && !(flags & STAT_CHANGE_BS_PTR))
        return STAT_CHANGE_DIDNT_WORK;

    return STAT_CHANGE_WORKED;
}

static void atk89_statbuffchange(void)
{
    u8* jump_loc = T1_READ_PTR(gBattlescriptCurrInstr + 2);
    if (ChangeStatBuffs(gBattleStruct->statChanger & 0xF0, gBattleStruct->statChanger & 0xF, T2_READ_8(gBattlescriptCurrInstr + 1), jump_loc) == 0)
        gBattlescriptCurrInstr += 6;
}

static void atk8A_normalisebuffs(void) //haze
{
    int i, j;
    for (i = 0; i < gBattlersCount; i++)
    {
        for (j = 0; j < 8; j++)
        {
            gBattleMons[i].statStages[j] = 6;
        }
    }
    gBattlescriptCurrInstr++;
}

static void atk8B_setbide(void)
{
    gBattleMons[gBankAttacker].status2 |= STATUS2_MULTIPLETURNS;
    gLockedMoves[gBankAttacker] = gCurrentMove;
    gTakenDmg[gBankAttacker] = 0;
    gBattleMons[gBankAttacker].status2 |= (STATUS2_BIDE - 0x100); //2 turns
    gBattlescriptCurrInstr++;
}

static void atk8C_confuseifrepeatingattackends(void)
{
    if (!(gBattleMons[gBankAttacker].status2 & STATUS2_LOCK_CONFUSE))
        gBattleCommunication[MOVE_EFFECT_BYTE] = 0x75;
    gBattlescriptCurrInstr++;
}

static void atk8D_setmultihitcounter(void)
{
    if (T2_READ_8(gBattlescriptCurrInstr + 1))
        gMultiHitCounter = T2_READ_8(gBattlescriptCurrInstr + 1);
    else
    {
        gMultiHitCounter = Random() % 6;
        if (gMultiHitCounter < 2)
            gMultiHitCounter += 2;
    }
    gBattlescriptCurrInstr += 2;
}

static void atk8E_initmultihitstring(void)
{
    ewram160E0(0) = 0xFD;
    ewram160E0(1) = 1;
    ewram160E0(2) = 1;
    ewram160E0(3) = 1;
    ewram160E0(4) = 0;
    ewram160E0(5) = 0xFF;
    gBattlescriptCurrInstr++;
}

static bool8 sub_80264C0(void)
{
    if (gBattleMons[gBankAttacker].level >= gBattleMons[gBankTarget].level)
    {
        ewram16064arr(gBankTarget) = gBattlerPartyIndexes[gBankTarget];
    }
    else
    {
        if (gBattleMons[gBankAttacker].level < gBattleMons[gBankTarget].level)
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
            return 0;
        }
        ewram16064arr(gBankTarget) = gBattlerPartyIndexes[gBankTarget];
    }
    gBattlescriptCurrInstr = BattleScript_SuccessForceOut;
    return 1;
}

static void atk8F_forcerandomswitch(void)
{
	if (gBattleMons[gBankTarget].hp == 0)
	{
		gBattlescriptCurrInstr += 5;
	}
    else if ((gBattleTypeFlags & BATTLE_TYPE_TRAINER))
    {
        u8 i;
        struct Pokemon* party;
        u8 valid;
        u8 val;
        if (!GetBattlerSide(gBankTarget))
            party = gPlayerParty;
        else
            party = gEnemyParty;

        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            valid = 0;
            val = 0;
            if (sub_803FBFC(sub_803FC34(gBankTarget)) == 1)
                val = 3;
            for (i = val; i < val + 3; i++)
            {
                if (GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE
                 && !GetMonData(&party[i], MON_DATA_IS_EGG)
                 && GetMonData(&party[i], MON_DATA_HP) != 0)
                    valid++;
            }
        }
        else
        {
            valid = 0;
            for (i = 0; i < 6; i++)
            {
                if (GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE
                 && !GetMonData(&party[i], MON_DATA_IS_EGG)
                 && GetMonData(&party[i], MON_DATA_HP) != 0)
                    valid++;
            }
        }

        if ((valid < 2 && (gBattleTypeFlags & (BATTLE_TYPE_DOUBLE | BATTLE_TYPE_MULTI)) != BATTLE_TYPE_DOUBLE)
         || (valid < 3 && (gBattleTypeFlags & BATTLE_TYPE_DOUBLE) && !(gBattleTypeFlags & BATTLE_TYPE_MULTI)))
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
        }
        else //if (sub_80264C0())
        {
			ewram16064arr(gBankTarget) = gBattlerPartyIndexes[gBankTarget];
			gBattlescriptCurrInstr = BattleScript_SuccessForceOut;
#define MON_CAN_BATTLE(mon) (((GetMonData(mon, MON_DATA_SPECIES) && GetMonData(mon, MON_DATA_IS_EGG) != 1 && GetMonData(mon, MON_DATA_HP))))
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                do
                {
                    val = Random() % 3;
                    if (sub_803FBFC(sub_803FC34(gBankTarget)) == 1)
                        i = val + 3;
                    else
                        i = val;
                } while (i == gBattlerPartyIndexes[gBankTarget] || i == gBattlerPartyIndexes[gBankTarget ^ 2] || !MON_CAN_BATTLE(&party[i]));
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                {
                    do
                    {
                        i = Random() % 6;
                    } while (i == gBattlerPartyIndexes[gBankTarget] || i == gBattlerPartyIndexes[gBankTarget ^ 2] || !MON_CAN_BATTLE(&party[i]));
                }
                else
                {
                    do
                    {
                        i = Random() % 6;
                    } while (i == gBattlerPartyIndexes[gBankTarget] || !MON_CAN_BATTLE(&party[i]));
                }
            }
            ewram16068arr(gBankTarget) = i;
            if (!IsLinkDoubleBattle())
                sub_8012258(gBankTarget);
            sub_8094B6C(gBankTarget, i, 0);
            sub_8094B6C(gBankTarget ^ 2, i, 1);
#undef MON_CAN_BATTLE
        }
    }
    else
    {
        sub_80264C0();
    }
}

static void atk90_tryconversiontypechange(void)
{
    //randomly changes user's type to one of its moves' type
    u8 valid_moves = 0;
    u8 checked_move;
    u8 move_type;
    while (valid_moves < 4)
    {
        if (gBattleMons[gBankAttacker].moves[valid_moves] == 0)
            break;
        valid_moves++;
    }

    for (checked_move = 0; checked_move < valid_moves; checked_move++)
    {
        move_type = gBattleMoves[gBattleMons[gBankAttacker].moves[checked_move]].type;
        if (move_type != gBattleMons[gBankAttacker].type1 && move_type != gBattleMons[gBankAttacker].type2)
            break;
    }

    if (checked_move == valid_moves)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        do
        {

            while ((checked_move = Random() & 3) >= valid_moves);

            move_type = gBattleMoves[gBattleMons[gBankAttacker].moves[checked_move]].type;
        } while (move_type == gBattleMons[gBankAttacker].type1 || move_type == gBattleMons[gBankAttacker].type2);

        gBattleMons[gBankAttacker].type1 = move_type;
        gBattleMons[gBankAttacker].type2 = move_type;

        gBattleTextBuff1[0] = 0xFD;
        gBattleTextBuff1[1] = 3;
        gBattleTextBuff1[2] = move_type;
        gBattleTextBuff1[3] = 0xFF;

        gBattlescriptCurrInstr += 5;
    }
}

static void atk91_givepaydaymoney(void)
{
    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK) && gPaydayMoney)
    {
        AddMoney(&gSaveBlock1.money, gPaydayMoney * gBattleStruct->moneyMultiplier);
        gBattleTextBuff1[0] = 0xFD;
        gBattleTextBuff1[1] = 1;
        gBattleTextBuff1[2] = 2;
        gBattleTextBuff1[3] = 5;
        gBattleTextBuff1[4] = gPaydayMoney;
        gBattleTextBuff1[5] = uBYTE1_16(gPaydayMoney);
        gBattleTextBuff1[6] = 0xFF;
        BattleScriptPush(gBattlescriptCurrInstr + 1);
        gBattlescriptCurrInstr = BattleScript_PrintPayDayMoneyString;
    }
    else
        gBattlescriptCurrInstr++;
}

static void atk92_setlightscreen(void)
{
    if (gSideAffecting[GetBattlerPosition(gBankAttacker) & 1] & SIDE_STATUS_LIGHTSCREEN)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    else
    {
        gSideAffecting[GetBattlerPosition(gBankAttacker) & 1] |= SIDE_STATUS_LIGHTSCREEN;
        gSideTimers[GetBattlerPosition(gBankAttacker) & 1].lightscreenTimer = 5;
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && CountAliveMons(1) == 2)
            gBattleCommunication[MULTISTRING_CHOOSER] = 4;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = 3;
    }
    gBattlescriptCurrInstr++;
}

#ifdef NOTMATCHING
static void atk93_tryKO(void)
{
   if (gBattleMons[gBankTarget].item == ITEM_ENIGMA_BERRY)
        hold_effect = gEnigmaBerries[gBankTarget].holdEffect, quality = gEnigmaBerries[gBankTarget].holdEffectParam;
    else
    {
        hold_effect = ItemId_GetHoldEffect(gBattleMons[gBankTarget].item);
        quality = ItemId_GetHoldEffectParam(gBattleMons[gBankTarget].item);
    }

    gStringBank = gBankTarget;

    if (hold_effect == HOLD_EFFECT_FOCUS_BAND && (Random() % 100) < quality)
    {
        RecordItemBattle(gBankTarget, hold_effect);
        gSpecialStatuses[gBankTarget].focusBanded = 1;
    }

    if (gBattleMons[gBankTarget].ability == ABILITY_STURDY)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gLastUsedAbility = ABILITY_STURDY;
        gBattlescriptCurrInstr = x;
        RecordAbilityBattle(gBankTarget, ABILITY_STURDY);
        return;
    }

    if (!(gStatuses3[gBankTarget] & STATUS3_ALWAYS_HITS))
    {
        u16 to_cmp = gBattleMons[gBankAttacker].level - gBattleMons[gBankTarget].level + gBattleMoves[gCurrentMove].accuracy;
        if (Random() % 0x64 + 1 < to_cmp || gBattleMons[gBankAttacker].level < gBattleMons[gBankTarget].level)
        {
            goto MOVE_RESULT_MISSED_LABEL;
        }
    }
    else
    {
        if (gDisableStructs[gBankTarget].bankWithSureHit != gBankAttacker || gBattleMons[gBankAttacker].level < gBattleMons[gBankTarget].level)
        {

        }
    }

MOVE_RESULT_MISSED_LABEL:
    gBattleTypeFlags |= MOVE_RESULT_MISSED;
    if (gBattleMons[gBankAttacker].level < gBattleMons[gBankTarget].level)
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    else
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
}

#else
__attribute((naked))
static void atk93_tryKO(void)
{
    asm(".syntax unified\n\
        push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    ldr r7, _08026BA8 @ =gBattleMons\n\
    ldr r6, _08026BAC @ =gBankTarget\n\
    ldrb r2, [r6]\n\
    movs r5, 0x58\n\
    adds r0, r2, 0\n\
    muls r0, r5\n\
    adds r1, r0, r7\n\
    ldrh r0, [r1, 0x2E]\n\
    cmp r0, 0xAF\n\
    bne _08026BB4\n\
    ldr r1, _08026BB0 @ =gEnigmaBerries\n\
    lsls r0, r2, 3\n\
    subs r0, r2\n\
    lsls r0, 2\n\
    adds r0, r1\n\
    ldrb r4, [r0, 0x7]\n\
    ldrb r6, [r0, 0x1A]\n\
    b _08026BCE\n\
    .align 2, 0\n\
_08026BA8: .4byte gBattleMons\n\
_08026BAC: .4byte gBankTarget\n\
_08026BB0: .4byte gEnigmaBerries\n\
_08026BB4:\n\
    ldrh r0, [r1, 0x2E]\n\
    bl ItemId_GetHoldEffect\n\
    lsls r0, 24\n\
    lsrs r4, r0, 24\n\
    ldrb r0, [r6]\n\
    muls r0, r5\n\
    adds r0, r7\n\
    ldrh r0, [r0, 0x2E]\n\
    bl ItemId_GetHoldEffectParam\n\
    lsls r0, 24\n\
    lsrs r6, r0, 24\n\
_08026BCE:\n\
    ldr r1, _08026C4C @ =gStringBank\n\
    ldr r5, _08026C50 @ =gBankTarget\n\
    ldrb r0, [r5]\n\
    strb r0, [r1]\n\
    cmp r4, 0x27\n\
    bne _08026C0C\n\
    bl Random\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    movs r1, 0x64\n\
    bl __umodsi3\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    cmp r0, r6\n\
    bcs _08026C0C\n\
    ldrb r0, [r5]\n\
    movs r1, 0x27\n\
    bl RecordItemBattle\n\
    ldr r2, _08026C54 @ =gSpecialStatuses\n\
    ldrb r1, [r5]\n\
    lsls r0, r1, 2\n\
    adds r0, r1\n\
    lsls r0, 2\n\
    adds r0, r2\n\
    ldrb r1, [r0]\n\
    movs r2, 0x80\n\
    orrs r1, r2\n\
    strb r1, [r0]\n\
_08026C0C:\n\
    ldr r0, _08026C58 @ =gBattleMons\n\
    mov r8, r0\n\
    ldr r1, _08026C50 @ =gBankTarget\n\
    ldrb r2, [r1]\n\
    movs r6, 0x58\n\
    adds r0, r2, 0\n\
    muls r0, r6\n\
    mov r3, r8\n\
    adds r5, r0, r3\n\
    adds r0, r5, 0\n\
    adds r0, 0x20\n\
    ldrb r3, [r0]\n\
    mov r10, r8\n\
    cmp r3, 0x5\n\
    bne _08026C6C\n\
    ldr r2, _08026C5C @ =gMoveResultFlags\n\
    ldrb r0, [r2]\n\
    movs r1, 0x1\n\
    orrs r0, r1\n\
    strb r0, [r2]\n\
    ldr r0, _08026C60 @ =gLastUsedAbility\n\
    strb r3, [r0]\n\
    ldr r1, _08026C64 @ =gBattlescriptCurrInstr\n\
    ldr r0, _08026C68 @ =BattleScript_SturdyPreventsOHKO\n\
    str r0, [r1]\n\
    ldr r1, _08026C50 @ =gBankTarget\n\
    ldrb r0, [r1]\n\
    movs r1, 0x5\n\
    bl RecordAbilityBattle\n\
    b _08026E40\n\
    .align 2, 0\n\
_08026C4C: .4byte gStringBank\n\
_08026C50: .4byte gBankTarget\n\
_08026C54: .4byte gSpecialStatuses\n\
_08026C58: .4byte gBattleMons\n\
_08026C5C: .4byte gMoveResultFlags\n\
_08026C60: .4byte gLastUsedAbility\n\
_08026C64: .4byte gBattlescriptCurrInstr\n\
_08026C68: .4byte BattleScript_SturdyPreventsOHKO\n\
_08026C6C:\n\
    ldr r1, _08026CE0 @ =gStatuses3\n\
    lsls r0, r2, 2\n\
    adds r0, r1\n\
    ldr r0, [r0]\n\
    movs r1, 0x18\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    bne _08026CF4\n\
    ldr r1, _08026CE4 @ =gBattleMoves\n\
    ldr r0, _08026CE8 @ =gCurrentMove\n\
    ldrh r0, [r0]\n\
    lsls r2, r0, 1\n\
    adds r2, r0\n\
    lsls r2, 2\n\
    adds r2, r1\n\
    ldr r7, _08026CEC @ =gBankAttacker\n\
    ldrb r0, [r7]\n\
    muls r0, r6\n\
    add r0, r10\n\
    adds r0, 0x2A\n\
    ldrb r0, [r0]\n\
    adds r1, r5, 0\n\
    adds r1, 0x2A\n\
    ldrb r1, [r1]\n\
    subs r0, r1\n\
    ldrb r2, [r2, 0x3]\n\
    adds r0, r2\n\
    lsls r0, 16\n\
    lsrs r4, r0, 16\n\
    bl Random\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    movs r1, 0x64\n\
    bl __umodsi3\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    adds r0, 0x1\n\
    cmp r0, r4\n\
    bge _08026CDC\n\
    ldrb r0, [r7]\n\
    adds r1, r0, 0\n\
    muls r1, r6\n\
    add r1, r10\n\
    adds r1, 0x2A\n\
    ldr r2, _08026CF0 @ =gBankTarget\n\
    ldrb r0, [r2]\n\
    muls r0, r6\n\
    add r0, r10\n\
    adds r0, 0x2A\n\
    ldrb r1, [r1]\n\
    movs r4, 0x1\n\
    ldrb r0, [r0]\n\
    cmp r1, r0\n\
    bcs _08026D20\n\
_08026CDC:\n\
    mov r10, r8\n\
    b _08026DE0\n\
    .align 2, 0\n\
_08026CE0: .4byte gStatuses3\n\
_08026CE4: .4byte gBattleMoves\n\
_08026CE8: .4byte gCurrentMove\n\
_08026CEC: .4byte gBankAttacker\n\
_08026CF0: .4byte gBankTarget\n\
_08026CF4:\n\
    ldr r0, _08026D4C @ =gDisableStructs\n\
    lsls r1, r2, 3\n\
    subs r1, r2\n\
    lsls r1, 2\n\
    adds r1, r0\n\
    ldr r2, _08026D50 @ =gBankAttacker\n\
    ldrb r0, [r1, 0x15]\n\
    movs r4, 0\n\
    ldrb r3, [r2]\n\
    cmp r0, r3\n\
    bne _08026D20\n\
    ldrb r0, [r2]\n\
    muls r0, r6\n\
    add r0, r10\n\
    adds r0, 0x2A\n\
    adds r1, r5, 0\n\
    adds r1, 0x2A\n\
    ldrb r0, [r0]\n\
    ldrb r1, [r1]\n\
    cmp r0, r1\n\
    bcc _08026D20\n\
    movs r4, 0x1\n\
_08026D20:\n\
    cmp r4, 0\n\
    beq _08026DE0\n\
    ldr r0, _08026D54 @ =gProtectStructs\n\
    ldr r1, _08026D58 @ =gBankTarget\n\
    ldrb r2, [r1]\n\
    lsls r1, r2, 4\n\
    adds r1, r0\n\
    ldrb r0, [r1]\n\
    lsls r0, 30\n\
    cmp r0, 0\n\
    bge _08026D64\n\
    ldr r1, _08026D5C @ =gBattleMoveDamage\n\
    movs r0, 0x58\n\
    muls r0, r2\n\
    add r0, r10\n\
    ldrh r0, [r0, 0x28]\n\
    subs r0, 0x1\n\
    str r0, [r1]\n\
    ldr r2, _08026D60 @ =gMoveResultFlags\n\
    ldrb r0, [r2]\n\
    movs r1, 0x40\n\
    b _08026DC6\n\
    .align 2, 0\n\
_08026D4C: .4byte gDisableStructs\n\
_08026D50: .4byte gBankAttacker\n\
_08026D54: .4byte gProtectStructs\n\
_08026D58: .4byte gBankTarget\n\
_08026D5C: .4byte gBattleMoveDamage\n\
_08026D60: .4byte gMoveResultFlags\n\
_08026D64:\n\
    ldr r0, _08026DA0 @ =gSpecialStatuses\n\
    lsls r1, r2, 2\n\
    adds r1, r2\n\
    lsls r1, 2\n\
    adds r1, r0\n\
    ldrb r0, [r1]\n\
    lsrs r0, 7\n\
    cmp r0, 0\n\
    beq _08026DB4\n\
    ldr r1, _08026DA4 @ =gBattleMoveDamage\n\
    movs r3, 0x58\n\
    adds r0, r2, 0\n\
    muls r0, r3\n\
    add r0, r10\n\
    ldrh r0, [r0, 0x28]\n\
    subs r0, 0x1\n\
    str r0, [r1]\n\
    ldr r2, _08026DA8 @ =gMoveResultFlags\n\
    ldrb r0, [r2]\n\
    movs r1, 0x80\n\
    orrs r0, r1\n\
    strb r0, [r2]\n\
    ldr r1, _08026DAC @ =gLastUsedItem\n\
    ldr r2, _08026DB0 @ =gBankTarget\n\
    ldrb r0, [r2]\n\
    muls r0, r3\n\
    add r0, r10\n\
    ldrh r0, [r0, 0x2E]\n\
    strh r0, [r1]\n\
    b _08026DCA\n\
    .align 2, 0\n\
_08026DA0: .4byte gSpecialStatuses\n\
_08026DA4: .4byte gBattleMoveDamage\n\
_08026DA8: .4byte gMoveResultFlags\n\
_08026DAC: .4byte gLastUsedItem\n\
_08026DB0: .4byte gBankTarget\n\
_08026DB4:\n\
    ldr r1, _08026DD4 @ =gBattleMoveDamage\n\
    movs r0, 0x58\n\
    muls r0, r2\n\
    add r0, r10\n\
    ldrh r0, [r0, 0x28]\n\
    str r0, [r1]\n\
    ldr r2, _08026DD8 @ =gMoveResultFlags\n\
    ldrb r0, [r2]\n\
    movs r1, 0x10\n\
_08026DC6:\n\
    orrs r0, r1\n\
    strb r0, [r2]\n\
_08026DCA:\n\
    ldr r1, _08026DDC @ =gBattlescriptCurrInstr\n\
    ldr r0, [r1]\n\
    adds r0, 0x5\n\
    str r0, [r1]\n\
    b _08026E40\n\
    .align 2, 0\n\
_08026DD4: .4byte gBattleMoveDamage\n\
_08026DD8: .4byte gMoveResultFlags\n\
_08026DDC: .4byte gBattlescriptCurrInstr\n\
_08026DE0:\n\
    ldr r2, _08026E10 @ =gMoveResultFlags\n\
    ldrb r0, [r2]\n\
    movs r1, 0x1\n\
    orrs r0, r1\n\
    strb r0, [r2]\n\
    ldr r0, _08026E14 @ =gBankAttacker\n\
    ldrb r0, [r0]\n\
    movs r2, 0x58\n\
    adds r1, r0, 0\n\
    muls r1, r2\n\
    add r1, r10\n\
    adds r1, 0x2A\n\
    ldr r3, _08026E18 @ =gBankTarget\n\
    ldrb r0, [r3]\n\
    muls r0, r2\n\
    add r0, r10\n\
    adds r0, 0x2A\n\
    ldrb r1, [r1]\n\
    ldrb r0, [r0]\n\
    cmp r1, r0\n\
    bcc _08026E20\n\
    ldr r1, _08026E1C @ =gBattleCommunication\n\
    movs r0, 0\n\
    b _08026E24\n\
    .align 2, 0\n\
_08026E10: .4byte gMoveResultFlags\n\
_08026E14: .4byte gBankAttacker\n\
_08026E18: .4byte gBankTarget\n\
_08026E1C: .4byte gBattleCommunication\n\
_08026E20:\n\
    ldr r1, _08026E50 @ =gBattleCommunication\n\
    movs r0, 0x1\n\
_08026E24:\n\
    strb r0, [r1, 0x5]\n\
    ldr r3, _08026E54 @ =gBattlescriptCurrInstr\n\
    ldr r2, [r3]\n\
    ldrb r1, [r2, 0x1]\n\
    ldrb r0, [r2, 0x2]\n\
    lsls r0, 8\n\
    orrs r1, r0\n\
    ldrb r0, [r2, 0x3]\n\
    lsls r0, 16\n\
    orrs r1, r0\n\
    ldrb r0, [r2, 0x4]\n\
    lsls r0, 24\n\
    orrs r1, r0\n\
    str r1, [r3]\n\
_08026E40:\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .align 2, 0\n\
_08026E50: .4byte gBattleCommunication\n\
_08026E54: .4byte gBattlescriptCurrInstr\n\
        .syntax divided");
}
#endif // NOTMATCHING

static void atk94_damagetohalftargethp(void) //super fang
{
    gBattleMoveDamage = gBattleMons[gBankTarget].hp / 2;
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;
    gBattlescriptCurrInstr++;
}

static void atk95_setsandstorm(void)
{
    if (gBattleWeather & WEATHER_SANDSTORM_ANY)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
    }
    else
    {
        gBattleWeather = WEATHER_SANDSTORM_TEMPORARY;
        gBattleCommunication[MULTISTRING_CHOOSER] = 3;
        gWishFutureKnock.weatherDuration = 5;
    }
    gBattlescriptCurrInstr++;
}

static void atk96_weatherdamage(void)
{
    gBattleMoveDamage = 0;
    if (WEATHER_HAS_EFFECT)
    {
        if (gBattleWeather & WEATHER_SANDSTORM_ANY)
        {
            if (gBattleMons[gBankAttacker].type1 != TYPE_ROCK && gBattleMons[gBankAttacker].type1 != TYPE_STEEL && gBattleMons[gBankAttacker].type1 != TYPE_GROUND
             && gBattleMons[gBankAttacker].type2 != TYPE_ROCK && gBattleMons[gBankAttacker].type2 != TYPE_STEEL && gBattleMons[gBankAttacker].type2 != TYPE_GROUND
			 && gBattleMons[gBankAttacker].ability != ABILITY_SAND_RUSH && gBattleMons[gBankAttacker].ability != ABILITY_MAGIC_GUARD
			 && gBattleMons[gBankAttacker].ability != ABILITY_SAND_FORCE && gBattleMons[gBankAttacker].ability != ABILITY_OVERCOAT
             && gBattleMons[gBankAttacker].ability != ABILITY_SAND_STREAM
             && gBattleMons[gBankAttacker].ability != ABILITY_SAND_VEIL && !(gStatuses3[gBankAttacker] & STATUS3_UNDERGROUND) && !(gStatuses3[gBankAttacker] & STATUS3_UNDERWATER))
            {
                gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP / 16;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
            }
            else
            {
                gBattleMoveDamage = 0;
            }
        }
        if (gBattleWeather & WEATHER_HAIL)
        {
            if (gBattleMons[gBankAttacker].type1 != TYPE_ICE && gBattleMons[gBankAttacker].type2 != TYPE_ICE && gBattleMons[gBankAttacker].ability != ABILITY_ICE_BODY &&
			    gBattleMons[gBankAttacker].ability != ABILITY_MAGIC_GUARD && gBattleMons[gBankAttacker].ability != ABILITY_OVERCOAT &&
				gBattleMons[gBankAttacker].ability != ABILITY_SNOW_CLOAK && gBattleMons[gBankAttacker].ability != ABILITY_SNOW_WARNING &&
			    !(gStatuses3[gBankAttacker] & STATUS3_UNDERGROUND) && !(gStatuses3[gBankAttacker] & STATUS3_UNDERWATER))
            {
                gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP / 16;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
            }
            else
            {
                gBattleMoveDamage = 0;
            }
        }
		if (gBattleWeather & WEATHER_SUN_ANY)
		{
			if (gBattleMons[gBankAttacker].ability == ABILITY_SOLAR_POWER || gBattleMons[gBankAttacker].ability == ABILITY_DRY_SKIN)
			{
				gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP / 8;
				if (gBattleMoveDamage == 0)
					gBattleMoveDamage = 1;
			}
		}
    }
    else
        gBattleMoveDamage = 0;

    if (gAbsentBattlerFlags & gBitTable[gBankAttacker] || gBattleMons[gBankAttacker].hp == 0)
        gBattleMoveDamage = 0;

    gBattlescriptCurrInstr++;
}

static void atk97_tryinfatuating(void)
{
    struct Pokemon *attacker, *target;
    u16 atk_species, def_species;
    u32 atk_pid, def_pid;
    if (!GetBattlerSide(gBankAttacker))
        attacker = &gPlayerParty[gBattlerPartyIndexes[gBankAttacker]];
    else
        attacker = &gEnemyParty[gBattlerPartyIndexes[gBankAttacker]];

    if (!GetBattlerSide(gBankTarget))
        target = &gPlayerParty[gBattlerPartyIndexes[gBankTarget]];
    else
        target = &gEnemyParty[gBattlerPartyIndexes[gBankTarget]];

    atk_species = GetMonData(attacker, MON_DATA_SPECIES);
    atk_pid = GetMonData(attacker, MON_DATA_PERSONALITY);

    def_species = GetMonData(target, MON_DATA_SPECIES);
    def_pid = GetMonData(target, MON_DATA_PERSONALITY);

    if (gBattleMons[gBankTarget].ability == ABILITY_OBLIVIOUS)
    {
        gBattlescriptCurrInstr = BattleScript_ObliviousPreventsAttraction;
        gLastUsedAbility = ABILITY_OBLIVIOUS;
        RecordAbilityBattle(gBankTarget, ABILITY_OBLIVIOUS);
    }
    else
    {
        if (GetGenderFromSpeciesAndPersonality(atk_species, atk_pid) == GetGenderFromSpeciesAndPersonality(def_species, def_pid)
            || gStatuses3[gBankTarget] & STATUS3_SEMI_INVULNERABLE || gBattleMons[gBankTarget].status2 & STATUS2_INFATUATION || GetGenderFromSpeciesAndPersonality(atk_species, atk_pid) == 0xFF
            || GetGenderFromSpeciesAndPersonality(def_species, def_pid) == 0xFF)
            {
                gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
            }
        else
        {
            gBattleMons[gBankTarget].status2 |=  (gBitTable[gBankAttacker] << 16);
            gBattlescriptCurrInstr += 5;
        }
    }
}

static void atk98_updatestatusicon(void)
{
    if (gBattleExecBuffer)
        return;

    if (T2_READ_8(gBattlescriptCurrInstr + 1) != 4)
    {
        gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
        EmitStatusIconUpdate(0, gBattleMons[gActiveBattler].status1, gBattleMons[gActiveBattler].status2);
        MarkBufferBankForExecution(gActiveBattler);
        gBattlescriptCurrInstr += 2;
    }
    else
    {
        gActiveBattler = gBankAttacker;
        if (!(gAbsentBattlerFlags & gBitTable[gActiveBattler]))
        {
            EmitStatusIconUpdate(0, gBattleMons[gActiveBattler].status1, gBattleMons[gActiveBattler].status2);
            MarkBufferBankForExecution(gActiveBattler);
        }
        if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        {
            gActiveBattler = GetBattlerAtPosition(GetBattlerPosition(gBankAttacker) ^ 2);
            if (!(gAbsentBattlerFlags & gBitTable[gActiveBattler]))
            {
                EmitStatusIconUpdate(0, gBattleMons[gActiveBattler].status1, gBattleMons[gActiveBattler].status2);
                MarkBufferBankForExecution(gActiveBattler);
            }
        }
        gBattlescriptCurrInstr += 2;
    }
}

static void atk99_setmist(void)
{
    if (gSideTimers[GetBattlerPosition(gBankAttacker) & 1].mistTimer)
    {
        gMoveResultFlags |= MOVE_RESULT_FAILED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    else
    {
        gSideTimers[GetBattlerPosition(gBankAttacker) & 1].mistTimer = 5;
        gSideAffecting[GetBattlerPosition(gBankAttacker) & 1] |= SIDE_STATUS_MIST;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    gBattlescriptCurrInstr++;
}

static void atk9A_setfocusenergy(void)
{
    if (gBattleMons[gBankAttacker].status2 & STATUS2_FOCUS_ENERGY)
    {
        gMoveResultFlags |= MOVE_RESULT_FAILED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    else
    {
        gBattleMons[gBankAttacker].status2 |= STATUS2_FOCUS_ENERGY;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    gBattlescriptCurrInstr++;
}

static void atk9B_transformdataexecution(void)
{
    gChosenMove = 0xFFFF;
    gBattlescriptCurrInstr++;
    if (gBattleMons[gBankTarget].status2 & STATUS2_TRANSFORMED || gStatuses3[gBankTarget] & STATUS3_SEMI_INVULNERABLE)
    {
        gMoveResultFlags |= MOVE_RESULT_FAILED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    else
    {
        u32 i; s32 j;
        u8 *atk_data, *def_data;
        gBattleMons[gBankAttacker].status2 |= STATUS2_TRANSFORMED;
        gDisableStructs[gBankAttacker].disabledMove = 0;
        gDisableStructs[gBankAttacker].disableTimer1 = 0;
        gDisableStructs[gBankAttacker].transformedMonPersonality = gBattleMons[gBankTarget].personality;
        gDisableStructs[gBankAttacker].unk18_b = 0;

        gBattleTextBuff1[0] = 0xFD;
        gBattleTextBuff1[1] = 6;
        gBattleTextBuff1[2] = (gBattleMons[gBankTarget].species);
        gBattleTextBuff1[3] = uBYTE1_16(gBattleMons[gBankTarget].species);
        gBattleTextBuff1[4] = 0xFF;

        atk_data = (u8*)(&gBattleMons[gBankAttacker]);
        def_data = (u8*)(&gBattleMons[gBankTarget]);

        for (i = 0; i < 0x24; i++)
            atk_data[i] = def_data[i];

        for (j = 0; j < 4; j++)
        {
            if (gBattleMoves[gBattleMons[gBankAttacker].moves[j]].pp < 5)
                gBattleMons[gBankAttacker].pp[j] = gBattleMoves[gBattleMons[gBankAttacker].moves[j]].pp;
            else
                gBattleMons[gBankAttacker].pp[j] = 5;
        }

        gActiveBattler = gBankAttacker;
        EmitResetActionMoveSelection(0, 2);
        MarkBufferBankForExecution(gActiveBattler);
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
}

static void atk9C_setsubstitute(void)
{
    u32 hp = gBattleMons[gBankAttacker].maxHP / 4;
    if (gBattleMons[gBankAttacker].maxHP / 4 == 0)
        hp = 1;
    if (gBattleMons[gBankAttacker].hp <= hp)
    {
        gBattleMoveDamage = 0;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    else
    {
        gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP / 4;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMons[gBankAttacker].status2 |= STATUS2_SUBSTITUTE;
        gBattleMons[gBankAttacker].status2 &= ~(STATUS2_WRAPPED);
        gDisableStructs[gBankAttacker].substituteHP = gBattleMoveDamage;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
        gHitMarker |= HITMARKER_IGNORE_SUBSTITUTE;
    }
    gBattlescriptCurrInstr++;
}

static bool8 IsMoveUncopyable(u16 move)
{
    int i;
    for (i = 0; sMovesForbiddenToCopy[i] != 0xFFFE && sMovesForbiddenToCopy[i] != move; i++) {}
    return (sMovesForbiddenToCopy[i] != 0xFFFE);
}

static void atk9D_mimicattackcopy(void)
{
    gChosenMove = 0xFFFF;
    if (IsMoveUncopyable(gLastUsedMove[gBankTarget]) || gBattleMons[gBankAttacker].status2 & STATUS2_TRANSFORMED
        || gLastUsedMove[gBankTarget] == 0 || gLastUsedMove[gBankTarget] == 0xFFFF)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        int i;
        for (i = 0; i < 4; i++)
        {
            if (gBattleMons[gBankAttacker].moves[i] == gLastUsedMove[gBankTarget])
                break;
        }
        if (i == 4)
        {
            gBattleMons[gBankAttacker].moves[gCurrMovePos] = gLastUsedMove[gBankTarget];
            if (gBattleMoves[gLastUsedMove[gBankTarget]].pp < 5)
                gBattleMons[gBankAttacker].pp[gCurrMovePos] = gBattleMoves[gLastUsedMove[gBankTarget]].pp;
            else
                gBattleMons[gBankAttacker].pp[gCurrMovePos] = 5;

            gBattleTextBuff1[0] = 0xFD;
            gBattleTextBuff1[1] = 2;
            gBattleTextBuff1[2] = gLastUsedMove[gBankTarget];
            gBattleTextBuff1[3] = uBYTE1_16(gLastUsedMove[gBankTarget]);
            gBattleTextBuff1[4] = 0xFF;

            gDisableStructs[gBankAttacker].unk18_b |= gBitTable[gCurrMovePos];
            gBattlescriptCurrInstr += 5;
        }
        else
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

#if DEBUG
NAKED
static void atk9E_metronome(void)
{
    asm("\
	push	{r4, r5, r6, r7, lr}\n\
	mov	r7, r8\n\
	push	{r7}\n\
	ldr	r6, ._3076      @ gBankAttacker\n\
	ldrb	r2, [r6]\n\
	lsl	r1, r2, #0x1\n\
	ldr	r0, ._3076 + 4  @ \n\
	add	r3, r1, r0\n\
	ldr	r5, ._3076 + 8  @ \n\
	mov	r4, #0x58\n\
	add	r0, r2, #0\n\
	mul	r0, r0, r4\n\
	add	r1, r0, r5\n\
	ldrh	r0, [r1, #0xe]\n\
	cmp	r0, #0\n\
	bne	._3071	@cond_branch\n\
	ldrh	r2, [r1, #0x10]\n\
	cmp	r2, #0\n\
	beq	._3071	@cond_branch\n\
	ldrh	r0, [r1, #0x12]\n\
	cmp	r0, #0\n\
	beq	._3071	@cond_branch\n\
	ldrh	r0, [r3]\n\
	cmp	r0, #0\n\
	bne	._3072	@cond_branch\n\
	strh	r2, [r3]\n\
._3072:\n\
	ldr	r1, ._3076 + 12 @ \n\
	ldrh	r0, [r3]\n\
	strh	r0, [r1]\n\
	ldrb	r0, [r6]\n\
	mul	r0, r0, r4\n\
	add	r0, r0, r5\n\
	ldrh	r5, [r0, #0x10]\n\
	ldrh	r2, [r0, #0x12]\n\
	add	r7, r1, #0\n\
	cmp	r5, r2\n\
	bcs	._3073	@cond_branch\n\
	ldrh	r0, [r3]\n\
	cmp	r0, r2\n\
	beq	._3074	@cond_branch\n\
	add	r0, r0, #0x1\n\
	b	._3079\n\
._3077:\n\
	.align	2, 0\n\
._3076:\n\
	.word	gBankAttacker\n\
	.word	+0x20160b4\n\
	.word	gBattleMons\n\
	.word	gCurrentMove\n\
._3073:\n\
	ldrh	r4, [r3]\n\
	add	r1, r4, #0\n\
	mov	r0, #0xb1\n\
	lsl	r0, r0, #0x1\n\
	cmp	r1, r0\n\
	bne	._3078	@cond_branch\n\
	mov	r0, #0x1\n\
	b	._3079\n\
._3078:\n\
	cmp	r1, r2\n\
	bne	._3080	@cond_branch\n\
._3074:\n\
	strh	r5, [r3]\n\
	b	._3081\n\
._3080:\n\
	add	r0, r4, #1\n\
._3079:\n\
	strh	r0, [r3]\n\
._3081:\n\
	ldr	r4, ._3083      @ gHitMarker\n\
	ldr	r2, [r4]\n\
	ldr	r0, ._3083 + 4  @ 0xfffffbff\n\
	and	r2, r2, r0\n\
	str	r2, [r4]\n\
	ldr	r6, ._3083 + 8  @ gBattlescriptCurrInstr\n\
	ldr	r5, ._3083 + 12 @ gBattleScriptsForMoveEffects\n\
	ldr	r3, ._3083 + 16 @ gBattleMoves\n\
	ldrh	r1, [r7]\n\
	lsl	r0, r1, #0x1\n\
	add	r0, r0, r1\n\
	lsl	r0, r0, #0x2\n\
	add	r0, r0, r3\n\
	ldrb	r0, [r0]\n\
	lsl	r0, r0, #0x2\n\
	add	r0, r0, r5\n\
	ldr	r0, [r0]\n\
	str	r0, [r6]\n\
	mov	r0, #0x80\n\
	lsl	r0, r0, #0x4\n\
	orr	r2, r2, r0\n\
	str	r2, [r4]\n\
	ldrh	r0, [r7]\n\
	b	._3082\n\
._3084:\n\
	.align	2, 0\n\
._3083:\n\
	.word	gHitMarker\n\
	.word	0xfffffbff\n\
	.word	gBattlescriptCurrInstr\n\
	.word	gBattleScriptsForMoveEffects\n\
	.word	gBattleMoves\n\
._3071:\n\
	ldr	r7, ._3090      @ gCurrentMove\n\
	mov	r6, #0xb1\n\
	lsl	r6, r6, #0x1\n\
	ldr	r5, ._3090 + 4  @ sMovesForbiddenToCopy\n\
	ldr	r0, ._3090 + 8  @ gBattlescriptCurrInstr\n\
	mov	r8, r0\n\
._3089:\n\
	bl	Random\n\
	ldr	r2, ._3090 + 12 @ 0x1ff\n\
	add	r1, r2, #0\n\
	and	r0, r0, r1\n\
	add	r0, r0, #0x1\n\
	strh	r0, [r7]\n\
	cmp	r0, r6\n\
	bhi	._3089	@cond_branch\n\
	mov	r0, #0x3\n\
._3086:\n\
	sub	r0, r0, #0x1\n\
	cmp	r0, #0\n\
	bge	._3086	@cond_branch\n\
	ldr	r4, ._3090      @ gCurrentMove\n\
	ldrh	r2, [r4]\n\
	ldr	r3, ._3090 + 16 @ 0xffff\n\
	sub	r0, r5, #2\n\
._3088:\n\
	add	r0, r0, #0x2\n\
	ldrh	r1, [r0]\n\
	cmp	r1, r2\n\
	beq	._3087	@cond_branch\n\
	cmp	r1, r3\n\
	bne	._3088	@cond_branch\n\
._3087:\n\
	ldr	r0, ._3090 + 16 @ 0xffff\n\
	cmp	r1, r0\n\
	bne	._3089	@cond_branch\n\
	ldr	r2, ._3090 + 20 @ gHitMarker\n\
	ldr	r0, [r2]\n\
	ldr	r1, ._3090 + 24 @ 0xfffffbff\n\
	and	r0, r0, r1\n\
	str	r0, [r2]\n\
	ldr	r3, ._3090 + 28 @ gBattleScriptsForMoveEffects\n\
	ldr	r2, ._3090 + 32 @ gBattleMoves\n\
	ldrh	r1, [r4]\n\
	lsl	r0, r1, #0x1\n\
	add	r0, r0, r1\n\
	lsl	r0, r0, #0x2\n\
	add	r0, r0, r2\n\
	ldrb	r0, [r0]\n\
	lsl	r0, r0, #0x2\n\
	add	r0, r0, r3\n\
	ldr	r0, [r0]\n\
	mov	r1, r8\n\
	str	r0, [r1]\n\
	ldrh	r0, [r4]\n\
._3082:\n\
	mov	r1, #0x0\n\
	bl	GetMoveTarget\n\
	ldr	r1, ._3090 + 36 @ gBankTarget\n\
	strb	r0, [r1]\n\
	pop	{r3}\n\
	mov	r8, r3\n\
	pop	{r4, r5, r6, r7}\n\
	pop	{r0}\n\
	bx	r0\n\
._3091:\n\
	.align	2, 0\n\
._3090:\n\
	.word	gCurrentMove\n\
	.word	sMovesForbiddenToCopy\n\
	.word	gBattlescriptCurrInstr\n\
	.word	0x1ff\n\
	.word	0xffff\n\
	.word	gHitMarker\n\
	.word	0xfffffbff\n\
	.word	gBattleScriptsForMoveEffects\n\
	.word	gBattleMoves\n\
	.word	gBankTarget");
}
#else
#ifdef NONMATCHING
static void atk9E_metronome(void)
{
    // sMovesForbiddenToCopy
    int i;
    do
    {
        while ((gCurrentMove = (Random() & 0x1FF) + 1) > 0x162);
        for (i = 0; sMovesForbiddenToCopy[i] != gCurrentMove && sMovesForbiddenToCopy[i] != 0xFFFF; i++);
    } while (sMovesForbiddenToCopy[i] != 0xFFFF);

    gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
    gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
    gBankTarget = GetMoveTarget(gCurrentMove, 0);
}

#else
NAKED
static void atk9E_metronome(void)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r8\n\
    push {r7}\n\
    ldr r7, _08027938 @ =gCurrentMove\n\
    movs r6, 0xB1\n\
    lsls r6, 1\n\
    ldr r5, _0802793C @ =sMovesForbiddenToCopy\n\
    ldr r0, _08027940 @ =gBattlescriptCurrInstr\n\
    mov r8, r0\n\
_080278CA:\n\
    bl Random\n\
    ldr r2, _08027944 @ =0x000001ff\n\
    adds r1, r2, 0\n\
    ands r0, r1\n\
    adds r0, 0x1\n\
    strh r0, [r7]\n\
    cmp r0, r6\n\
    bhi _080278CA\n\
    movs r0, 0x3\n\
_080278DE:\n\
    subs r0, 0x1\n\
    cmp r0, 0\n\
    bge _080278DE\n\
    ldr r4, _08027938 @ =gCurrentMove\n\
    ldrh r2, [r4]\n\
    ldr r3, _08027948 @ =0x0000ffff\n\
    subs r0, r5, 0x2\n\
_080278EC:\n\
    adds r0, 0x2\n\
    ldrh r1, [r0]\n\
    cmp r1, r2\n\
    beq _080278F8\n\
    cmp r1, r3\n\
    bne _080278EC\n\
_080278F8:\n\
    ldr r0, _08027948 @ =0x0000ffff\n\
    cmp r1, r0\n\
    bne _080278CA\n\
    ldr r2, _0802794C @ =gHitMarker\n\
    ldr r0, [r2]\n\
    ldr r1, _08027950 @ =0xfffffbff\n\
    ands r0, r1\n\
    str r0, [r2]\n\
    ldr r3, _08027954 @ =gBattleScriptsForMoveEffects\n\
    ldr r2, _08027958 @ =gBattleMoves\n\
    ldrh r1, [r4]\n\
    lsls r0, r1, 1\n\
    adds r0, r1\n\
    lsls r0, 2\n\
    adds r0, r2\n\
    ldrb r0, [r0]\n\
    lsls r0, 2\n\
    adds r0, r3\n\
    ldr r0, [r0]\n\
    mov r1, r8\n\
    str r0, [r1]\n\
    ldrh r0, [r4]\n\
    movs r1, 0\n\
    bl GetMoveTarget\n\
    ldr r1, _0802795C @ =gBankTarget\n\
    strb r0, [r1]\n\
    pop {r3}\n\
    mov r8, r3\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .align 2, 0\n\
_08027938: .4byte gCurrentMove\n\
_0802793C: .4byte sMovesForbiddenToCopy\n\
_08027940: .4byte gBattlescriptCurrInstr\n\
_08027944: .4byte 0x000001ff\n\
_08027948: .4byte 0x0000ffff\n\
_0802794C: .4byte gHitMarker\n\
_08027950: .4byte 0xfffffbff\n\
_08027954: .4byte gBattleScriptsForMoveEffects\n\
_08027958: .4byte gBattleMoves\n\
_0802795C: .4byte gBankTarget\n\
        .syntax divided");
}
#endif // NONMATCHING
#endif

static void atk9F_dmgtolevel(void)
{
    gBattleMoveDamage = gBattleMons[gBankAttacker].level;
    gBattlescriptCurrInstr++;
}

static void atkA0_psywavedamageeffect(void)
{
    s32 rand_dmg;
    while ((rand_dmg = (Random() & 0xF)) > 0xA);
    rand_dmg *= 10;
    gBattleMoveDamage = gBattleMons[gBankAttacker].level * (rand_dmg + 50) / 100;
    gBattlescriptCurrInstr++;
}

static void atkA1_counterdamagecalculator(void)
{
    u8 atk_side = GetBattlerSide(gBankAttacker);
    u8 def_side = GetBattlerSide(gProtectStructs[gBankAttacker].physicalBank);
    if (gProtectStructs[gBankAttacker].physicalDmg && atk_side != def_side && gBattleMons[gProtectStructs[gBankAttacker].physicalBank].hp)
    {
        gBattleMoveDamage = gProtectStructs[gBankAttacker].physicalDmg * 2;
        if (gSideTimers[def_side].followmeTimer && gBattleMons[gSideTimers[def_side].followmeTarget].hp)
            gBankTarget = gSideTimers[def_side].followmeTarget;
        else
            gBankTarget = gProtectStructs[gBankAttacker].physicalBank;
        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gSpecialStatuses[gBankAttacker].flag20 = 1;
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkA2_mirrorcoatdamagecalculator(void) //a copy of atkA1 with the physical -> special field changes
{
    u8 atk_side = GetBattlerSide(gBankAttacker);
    u8 def_side = GetBattlerSide(gProtectStructs[gBankAttacker].specialBank);
    if (gProtectStructs[gBankAttacker].specialDmg && atk_side != def_side && gBattleMons[gProtectStructs[gBankAttacker].specialBank].hp)
    {
        gBattleMoveDamage = gProtectStructs[gBankAttacker].specialDmg * 2;
        if (gSideTimers[def_side].followmeTimer && gBattleMons[gSideTimers[def_side].followmeTarget].hp)
            gBankTarget = gSideTimers[def_side].followmeTarget;
        else
            gBankTarget = gProtectStructs[gBankAttacker].specialBank;
        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gSpecialStatuses[gBankAttacker].flag20 = 1;
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkA3_disablelastusedattack(void)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (gBattleMons[gBankTarget].moves[i] == gLastUsedMove[gBankTarget])
            break;
    }
    if (gDisableStructs[gBankTarget].disabledMove == 0 && i != 4 && gBattleMons[gBankTarget].pp[i] != 0)
    {
        gBattleTextBuff1[0] = 0xFD;
        gBattleTextBuff1[1] = 2;
        gBattleTextBuff1[2] = gBattleMons[gBankTarget].moves[i];
        gBattleTextBuff1[3] = uBYTE1_16(gBattleMons[gBankTarget].moves[i]);
        gBattleTextBuff1[4] = 0xFF;

        gDisableStructs[gBankTarget].disabledMove = gBattleMons[gBankTarget].moves[i];
        gDisableStructs[gBankTarget].disableTimer1 = 4;
        gDisableStructs[gBankTarget].disableTimer2 = gDisableStructs[gBankTarget].disableTimer1; //that's interesting
        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkA4_trysetencore(void)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (gBattleMons[gBankTarget].moves[i] == gLastUsedMove[gBankTarget])
            break;
    }
    if (gLastUsedMove[gBankTarget] == MOVE_STRUGGLE || gLastUsedMove[gBankTarget] == MOVE_ENCORE || gLastUsedMove[gBankTarget] == MOVE_MIRROR_MOVE)
        i = 4;
    if (gDisableStructs[gBankTarget].encoredMove == 0 && i != 4 && gBattleMons[gBankTarget].pp[i] != 0)
    {
        gDisableStructs[gBankTarget].encoredMove = gBattleMons[gBankTarget].moves[i];
        gDisableStructs[gBankTarget].encoredMovePos = i;
        gDisableStructs[gBankTarget].encoreTimer1 = 3;
        gDisableStructs[gBankTarget].encoreTimer2 = gDisableStructs[gBankTarget].encoreTimer1;
        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkA5_painsplitdmgcalc(void)
{
    if (!(gBattleMons[gBankTarget].status2 & STATUS2_SUBSTITUTE))
    {
        s32 hp_diff = (gBattleMons[gBankAttacker].hp + gBattleMons[gBankTarget].hp) / 2;
        s32 to_store = gBattleMoveDamage = gBattleMons[gBankTarget].hp - hp_diff;
        gBattleStruct->unk16014 = sBYTE0_32(to_store);
        gBattleStruct->unk16015 = sBYTE1_32(to_store);
        gBattleStruct->unk16016 = sBYTE2_32(to_store);
        gBattleStruct->unk16017 = sBYTE3_32(to_store);

        gBattleMoveDamage = gBattleMons[gBankAttacker].hp - hp_diff;
        gSpecialStatuses[gBankTarget].moveturnLostHP = 0xFFFF;

        gBattlescriptCurrInstr += 5;
    }
    else
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
}

#ifdef NONMATCHING
static void atkA6_settypetorandomresistance(void)
{
    if (gLastLandedMoves[gBankAttacker] == 0 || gLastLandedMoves[gBankAttacker] == 0xFFFF || (IsTwoTurnsMove(gLastLandedMoves[gBankAttacker]) && !gProtectStructs[gBankAttacker].physicalDmg && !gProtectStructs[gBankAttacker].specialDmg))
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    else
    {
        int type = 0, rands = 0;
        do
        {
            while (((type = (Random() & 0x7F)) > 0x70));
            type *= 3;
            if (gTypeEffectiveness[type] == gLastHitByType[gBankAttacker] && gTypeEffectiveness[type + 2] <= 5 && gBattleMons[gBankAttacker].type1 != gTypeEffectiveness[type + 1] && gBattleMons[gBankAttacker].type2 != gTypeEffectiveness[type + 1])
            {
                gBattleMons[gBankAttacker].type1 = type;
                gBattleMons[gBankAttacker].type2 = type;
                gBattleTextBuff1[0] = 0xFD;
                gBattleTextBuff1[1] = 3;
                gBattleTextBuff1[2] = type;
                gBattleTextBuff1[3] = 0xFF;
                gBattlescriptCurrInstr += 5;
                return;
            }
            rands++;
        } while (rands <= 999);

        type = 0, rands = 0;
        do
        {
            if (gTypeEffectiveness[type] == 0xFE || gTypeEffectiveness[type] != 0xFF)
            {
                if (gTypeEffectiveness[type] == gLastHitByType[gBankAttacker] && gTypeEffectiveness[type + 2] <= 5 && gBattleMons[gBankAttacker].type1 != gTypeEffectiveness[type + 1] && gBattleMons[gBankAttacker].type2 != gTypeEffectiveness[type + 1])
                {
                    gBattleMons[gBankAttacker].type1 = gTypeEffectiveness[rands + 1];
                    gBattleMons[gBankAttacker].type2 = gTypeEffectiveness[rands + 1];
                    gBattleTextBuff1[0] = 0xFD;
                    gBattleTextBuff1[1] = 3;
                    gBattleTextBuff1[2] = gTypeEffectiveness[rands + 1];
                    gBattleTextBuff1[3] = 0xFF;
                    gBattlescriptCurrInstr += 5;
                    return;
                }
            }
            type += 3, rands += 3;
        } while (rands < 336);

        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

#else
NAKED
static void atkA6_settypetorandomresistance(void)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    ldr r1, _08027FA8 @ =gLastLandedMoves\n\
    ldr r4, _08027FAC @ =gBankAttacker\n\
    ldrb r0, [r4]\n\
    lsls r0, 1\n\
    adds r2, r0, r1\n\
    ldrh r1, [r2]\n\
    cmp r1, 0\n\
    beq _08027F8C\n\
    ldr r0, _08027FB0 @ =0x0000ffff\n\
    cmp r1, r0\n\
    beq _08027F8C\n\
    ldrh r0, [r2]\n\
    bl IsTwoTurnsMove\n\
    lsls r0, 24\n\
    cmp r0, 0\n\
    beq _08028024\n\
    ldr r2, _08027FB4 @ =gProtectStructs\n\
    ldrb r0, [r4]\n\
    lsls r1, r0, 4\n\
    adds r0, r2, 0x4\n\
    adds r0, r1, r0\n\
    ldr r0, [r0]\n\
    cmp r0, 0\n\
    bne _08028024\n\
    adds r0, r2, 0\n\
    adds r0, 0x8\n\
    adds r0, r1, r0\n\
    ldr r0, [r0]\n\
    cmp r0, 0\n\
    bne _08028024\n\
_08027F8C:\n\
    ldr r3, _08027FB8 @ =gBattlescriptCurrInstr\n\
    ldr r2, [r3]\n\
    ldrb r1, [r2, 0x1]\n\
    ldrb r0, [r2, 0x2]\n\
    lsls r0, 8\n\
    orrs r1, r0\n\
    ldrb r0, [r2, 0x3]\n\
    lsls r0, 16\n\
    orrs r1, r0\n\
    ldrb r0, [r2, 0x4]\n\
    lsls r0, 24\n\
    orrs r1, r0\n\
    str r1, [r3]\n\
    b _08028110\n\
    .align 2, 0\n\
_08027FA8: .4byte gLastLandedMoves\n\
_08027FAC: .4byte gBankAttacker\n\
_08027FB0: .4byte 0x0000ffff\n\
_08027FB4: .4byte gProtectStructs\n\
_08027FB8: .4byte gBattlescriptCurrInstr\n\
_08027FBC:\n\
    mov r0, r12\n\
    strb r5, [r0]\n\
    mov r1, r10\n\
    ldrb r0, [r1]\n\
    muls r0, r2\n\
    adds r0, r7\n\
    adds r0, 0x22\n\
    strb r5, [r0]\n\
    ldr r1, _08027FE0 @ =gBattleTextBuff1\n\
    movs r0, 0xFD\n\
    strb r0, [r1]\n\
    movs r0, 0x3\n\
    strb r0, [r1, 0x1]\n\
    strb r5, [r1, 0x2]\n\
    movs r0, 0xFF\n\
    strb r0, [r1, 0x3]\n\
    ldr r1, _08027FE4 @ =gBattlescriptCurrInstr\n\
    b _08028012\n\
    .align 2, 0\n\
_08027FE0: .4byte gBattleTextBuff1\n\
_08027FE4: .4byte gBattlescriptCurrInstr\n\
_08027FE8:\n\
    mov r0, r8\n\
    adds r0, 0x1\n\
    adds r0, r3\n\
    ldrb r2, [r0]\n\
    strb r2, [r4]\n\
    mov r4, r10\n\
    ldrb r0, [r4]\n\
    muls r0, r6\n\
    ldr r7, _0802801C @ =gBattleMons\n\
    adds r0, r7\n\
    adds r0, 0x22\n\
    strb r2, [r0]\n\
    ldr r1, _08028020 @ =gBattleTextBuff1\n\
    movs r0, 0xFD\n\
    strb r0, [r1]\n\
    movs r0, 0x3\n\
    strb r0, [r1, 0x1]\n\
    strb r2, [r1, 0x2]\n\
    movs r0, 0xFF\n\
    strb r0, [r1, 0x3]\n\
    mov r1, r12\n\
_08028012:\n\
    ldr r0, [r1]\n\
    adds r0, 0x5\n\
    str r0, [r1]\n\
    b _08028110\n\
    .align 2, 0\n\
_0802801C: .4byte gBattleMons\n\
_08028020: .4byte gBattleTextBuff1\n\
_08028024:\n\
    movs r4, 0\n\
    mov r8, r4\n\
    movs r7, 0x7F\n\
    mov r9, r7\n\
_0802802C:\n\
    bl Random\n\
    mov r4, r9\n\
    ands r4, r0\n\
    cmp r4, 0x70\n\
    bhi _0802802C\n\
    lsls r0, r4, 1\n\
    adds r4, r0, r4\n\
    ldr r6, _08028120 @ =gTypeEffectiveness\n\
    adds r3, r4, r6\n\
    ldr r1, _08028124 @ =gLastHitByType\n\
    ldr r2, _08028128 @ =gBankAttacker\n\
    ldrb r5, [r2]\n\
    lsls r0, r5, 1\n\
    adds r0, r1\n\
    ldrb r1, [r3]\n\
    mov r10, r2\n\
    ldrh r0, [r0]\n\
    cmp r1, r0\n\
    bne _08028088\n\
    adds r0, r4, 0x2\n\
    adds r0, r6\n\
    ldrb r0, [r0]\n\
    cmp r0, 0x5\n\
    bhi _08028088\n\
    ldr r7, _0802812C @ =gBattleMons\n\
    movs r2, 0x58\n\
    adds r0, r5, 0\n\
    muls r0, r2\n\
    adds r3, r0, r7\n\
    movs r0, 0x21\n\
    adds r0, r3\n\
    mov r12, r0\n\
    adds r0, r4, 0x1\n\
    adds r0, r6\n\
    ldrb r5, [r0]\n\
    mov r1, r12\n\
    ldrb r0, [r1]\n\
    adds r1, r5, 0\n\
    cmp r0, r1\n\
    beq _08028088\n\
    adds r0, r3, 0\n\
    adds r0, 0x22\n\
    ldrb r0, [r0]\n\
    cmp r0, r1\n\
    bne _08027FBC\n\
_08028088:\n\
    movs r7, 0x1\n\
    add r8, r7\n\
    ldr r0, _08028130 @ =0x000003e7\n\
    cmp r8, r0\n\
    ble _0802802C\n\
    movs r0, 0\n\
    mov r8, r0\n\
    ldr r1, _08028134 @ =gBattlescriptCurrInstr\n\
    mov r12, r1\n\
    ldr r3, _08028120 @ =gTypeEffectiveness\n\
    adds r0, r4, 0x1\n\
    adds r0, r3\n\
    mov r9, r0\n\
    adds r5, r3, 0\n\
_080280A4:\n\
    ldrb r1, [r5]\n\
    cmp r1, 0xFF\n\
    bgt _080280AE\n\
    cmp r1, 0xFE\n\
    bge _080280E8\n\
_080280AE:\n\
    mov r4, r10\n\
    ldrb r2, [r4]\n\
    lsls r0, r2, 1\n\
    ldr r7, _08028124 @ =gLastHitByType\n\
    adds r0, r7\n\
    ldrh r0, [r0]\n\
    cmp r1, r0\n\
    bne _080280E8\n\
    ldrb r0, [r5, 0x2]\n\
    cmp r0, 0x5\n\
    bhi _080280E8\n\
    movs r6, 0x58\n\
    adds r0, r2, 0\n\
    muls r0, r6\n\
    ldr r1, _0802812C @ =gBattleMons\n\
    adds r2, r0, r1\n\
    adds r4, r2, 0\n\
    adds r4, 0x21\n\
    ldrb r0, [r4]\n\
    mov r7, r9\n\
    ldrb r1, [r7]\n\
    cmp r0, r1\n\
    beq _080280E8\n\
    adds r0, r2, 0\n\
    adds r0, 0x22\n\
    ldrb r0, [r0]\n\
    cmp r0, r1\n\
    beq _080280E8\n\
    b _08027FE8\n\
_080280E8:\n\
    adds r5, 0x3\n\
    movs r0, 0x3\n\
    add r8, r0\n\
    ldr r0, _08028138 @ =0x0000014f\n\
    cmp r8, r0\n\
    bls _080280A4\n\
    mov r1, r12\n\
    ldr r2, [r1]\n\
    ldrb r1, [r2, 0x1]\n\
    ldrb r0, [r2, 0x2]\n\
    lsls r0, 8\n\
    orrs r1, r0\n\
    ldrb r0, [r2, 0x3]\n\
    lsls r0, 16\n\
    orrs r1, r0\n\
    ldrb r0, [r2, 0x4]\n\
    lsls r0, 24\n\
    orrs r1, r0\n\
    mov r4, r12\n\
    str r1, [r4]\n\
_08028110:\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .align 2, 0\n\
_08028120: .4byte gTypeEffectiveness\n\
_08028124: .4byte gLastHitByType\n\
_08028128: .4byte gBankAttacker\n\
_0802812C: .4byte gBattleMons\n\
_08028130: .4byte 0x000003e7\n\
_08028134: .4byte gBattlescriptCurrInstr\n\
_08028138: .4byte 0x0000014f\n\
        .syntax divided");
}
#endif // NONMATCHING

static void atkA7_setalwayshitflag(void)
{
    gStatuses3[gBankTarget] &= ~(STATUS3_ALWAYS_HITS);
    gStatuses3[gBankTarget] |= 0x10;
    gDisableStructs[gBankTarget].bankWithSureHit = gBankAttacker;
    gBattlescriptCurrInstr++;
}

struct move_pp
{
    u16 move[4];
    u8 pp[4];
    u8 ppBonuses;
};

static void atkA8_copymovepermanently(void)
{
    gChosenMove = 0xFFFF;
    if (!(gBattleMons[gBankAttacker].status2 & STATUS2_TRANSFORMED) && gUnknown_02024C2C[gBankTarget] != MOVE_STRUGGLE && gUnknown_02024C2C[gBankTarget] != 0 && gUnknown_02024C2C[gBankTarget] != 0xFFFF && gUnknown_02024C2C[gBankTarget] != MOVE_SKETCH)
    {
        int i;
        for (i = 0; i < 4; i++)
        {
            if (gBattleMons[gBankAttacker].moves[i] == MOVE_SKETCH)
                continue;
            if (gBattleMons[gBankAttacker].moves[i] == gUnknown_02024C2C[gBankTarget])
                break;
        }
        if (i != 4) //sketch fail
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
        else //sketch worked
        {
            struct move_pp moves_data;
            gBattleMons[gBankAttacker].moves[gCurrMovePos] = gUnknown_02024C2C[gBankTarget];
            gBattleMons[gBankAttacker].pp[gCurrMovePos] = gBattleMoves[gUnknown_02024C2C[gBankTarget]].pp;
            gActiveBattler = gBankAttacker;
            for (i = 0; i < 4; i++)
            {
                moves_data.move[i] = gBattleMons[gBankAttacker].moves[i];
                moves_data.pp[i] = gBattleMons[gBankAttacker].pp[i];
            }
            moves_data.ppBonuses = gBattleMons[gBankAttacker].ppBonuses;
            EmitSetMonData(0, REQUEST_MOVES_PP_BATTLE, 0, sizeof(struct move_pp), &moves_data);
            MarkBufferBankForExecution(gActiveBattler);
            gBattleTextBuff1[0] = 0xFD;
            gBattleTextBuff1[1] = 2;
            gBattleTextBuff1[2] = gUnknown_02024C2C[gBankTarget];
            gBattleTextBuff1[3] = gUnknown_02024C2C[gBankTarget] >> 8;
            gBattleTextBuff1[4] = 0xFF;
            gBattlescriptCurrInstr += 5;
        }
    }
    else //sketch fail
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
}

static bool8 IsTwoTurnsMove(u16 move)
{
    u8 effect = gBattleMoves[move].effect;
    if (effect == EFFECT_SKULL_BASH || effect == EFFECT_RAZOR_WIND || effect == EFFECT_SKY_ATTACK || effect == EFFECT_SOLARBEAM || effect == EFFECT_FLY || effect == EFFECT_BIDE)
        return 1;
    else
        return 0;
}

static bool8 IsMoveUnchoosable(u16 move)
{
    if (move == 0 || move == MOVE_SLEEP_TALK || move == MOVE_ASSIST || move == MOVE_MIRROR_MOVE || move == MOVE_METRONOME)
        return 1;
    else
        return 0;
}

static u8 AttacksThisTurn(u8 bank, u16 move) //Note: returns 1 if it's a charging turn, otherwise 2
{
    //first argument is unused
    u8 effect;
    if (gBattleMoves[move].effect == EFFECT_SOLARBEAM && (gBattleWeather & WEATHER_SUN_ANY))
        return 2;
    effect = gBattleMoves[move].effect;
    if (effect == EFFECT_SKULL_BASH || effect == EFFECT_RAZOR_WIND || effect == EFFECT_SKY_ATTACK || effect == EFFECT_SOLARBEAM || effect == EFFECT_FLY || effect == EFFECT_BIDE)
    {
        if ((gHitMarker & HITMARKER_x8000000))
            return 1;
    }
    return 2;
}

static void atkA9_trychoosesleeptalkmove(void)
{
    u8 unusable_moves = 0;
    int i;

    for (i = 0; i < 4; i++)
    {
        if (IsMoveUnchoosable(gBattleMons[gBankAttacker].moves[i]) || gBattleMons[gBankAttacker].moves[i] == MOVE_FOCUS_PUNCH
            || gBattleMons[gBankAttacker].moves[i] == MOVE_UPROAR || IsTwoTurnsMove(gBattleMons[gBankAttacker].moves[i]))
                unusable_moves |= gBitTable[i];
    }
    unusable_moves = CheckMoveLimitations(gBankAttacker, unusable_moves, 0xFD);
    if (unusable_moves == 0xF) //all 4 moves cannot be chosen
        gBattlescriptCurrInstr += 5;
    else //at least one move can be chosen
    {
        u32 random_pos;
        do
        {
            random_pos = Random() & 3;
        } while ((gBitTable[random_pos] & unusable_moves));

        gRandomMove = gBattleMons[gBankAttacker].moves[random_pos];
        gCurrMovePos = random_pos;
        gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
        gBankTarget = GetMoveTarget(gRandomMove, 0);
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkAA_setdestinybond(void)
{
    gBattleMons[gBankAttacker].status2 |= STATUS2_DESTINY_BOND;
    gBattlescriptCurrInstr++;
}

static void TrySetDestinyBondToHappen(void)
{
    u8 atk_side = GetBattlerSide(gBankAttacker);
    u8 def_side = GetBattlerSide(gBankTarget);
    if (gBattleMons[gBankTarget].status2 & STATUS2_DESTINY_BOND && atk_side != def_side && !(gHitMarker & HITMARKER_GRUDGE))
        gHitMarker |= HITMARKER_DESTINYBOND;
}

static void atkAB_trysetdestinybondtohappen(void)
{
    TrySetDestinyBondToHappen();
    gBattlescriptCurrInstr++;
}

static void atkAC_remaininghptopower(void)
{
    s32 hp_fraction = GetScaledHPFraction(gBattleMons[gBankAttacker].hp, gBattleMons[gBankAttacker].maxHP, 48);
    int i;
    for (i = 0; i < 12; i += 2)
    {
        if (hp_fraction <= sFlailHpScaleToPowerTable[i])
            break;
    }
    gDynamicBasePower = sFlailHpScaleToPowerTable[i + 1];
    gBattlescriptCurrInstr++;
}

static void atkAD_tryspiteppreduce(void)
{
    if (gLastUsedMove[gBankTarget] != 0 && gLastUsedMove[gBankTarget] != 0xFFFF && !(gStatuses3[gBankTarget] & STATUS3_SEMI_INVULNERABLE))
    {
        int i;
        for (i = 0; i < 4; i++)
        {
            if (gLastUsedMove[gBankTarget] == gBattleMons[gBankTarget].moves[i])
                break;
        }
        if (i != 4 && gBattleMons[gBankTarget].pp[i] > 0)
        {
            s32 lost_pp = 4;
            if (gBattleMons[gBankTarget].pp[i] < lost_pp)
                lost_pp = gBattleMons[gBankTarget].pp[i];

            gBattleTextBuff1[0] = 0xFD;
            gBattleTextBuff1[1] = 2;
            gBattleTextBuff1[2] = gLastUsedMove[gBankTarget];
            gBattleTextBuff1[3] = gLastUsedMove[gBankTarget] >> 8;
            gBattleTextBuff1[4] = 0xFF;
            ConvertIntToDecimalStringN(gBattleTextBuff2, lost_pp, 0, 1);
            gBattleTextBuff2[0] = 0xFD;
            gBattleTextBuff2[1] = 1;
            gBattleTextBuff2[2] = 1;
            gBattleTextBuff2[3] = 1;
            gBattleTextBuff2[4] = lost_pp;
            gBattleTextBuff2[5] = 0xFF;

            gBattleMons[gBankTarget].pp[i] -= lost_pp;
            gActiveBattler = gBankTarget;
            if (!(gDisableStructs[gActiveBattler].unk18_b & gBitTable[i])
                && !(gBattleMons[gActiveBattler].status2 & STATUS2_TRANSFORMED))
            {
                EmitSetMonData(0, REQUEST_PPMOVE1_BATTLE + i, 0, 1, &gBattleMons[gActiveBattler].pp[i]);
                MarkBufferBankForExecution(gActiveBattler);
            }
            gBattlescriptCurrInstr += 5;
            if (gBattleMons[gBankTarget].pp[i] == 0)
                CancelMultiTurnMoves(gBankTarget);
            return;
        }
    }
    gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
}

static void atkAE_healpartystatus(void)
{
    register u32 zero2 asm("r4") = 0;
    u32 zero = zero2;
    u8 to_heal = 0;
    if (gCurrentMove == MOVE_HEAL_BELL)
    {
        struct Pokemon* party;
        int i;

        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
        if (GetBattlerSide(gBankAttacker) == 0)
            party = gPlayerParty;
        else
            party = gEnemyParty;

        if (gBattleMons[gBankAttacker].ability != ABILITY_SOUNDPROOF)
        {
            gBattleMons[gBankAttacker].status1 = 0;
        }
        else
        {
            RecordAbilityBattle(gBankAttacker, gBattleMons[gBankAttacker].ability);
            gBattleCommunication[MULTISTRING_CHOOSER] |= 1;
        }

        gActiveBattler = gBattleStruct->scriptingActive = GetBattlerAtPosition(GetBattlerPosition(gBankAttacker) ^ 2);
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && !(gAbsentBattlerFlags & gBitTable[gActiveBattler]))
        {
            if (gBattleMons[gActiveBattler].ability != ABILITY_SOUNDPROOF)
            {
                gBattleMons[gActiveBattler].status1 = 0;
            }
            else
            {
                RecordAbilityBattle(gActiveBattler, gBattleMons[gActiveBattler].ability);
                gBattleCommunication[MULTISTRING_CHOOSER] |= 2;
            }
        }

        for (i = 0; i < 6; i++)
        {
            u16 species = GetMonData(&party[i], MON_DATA_SPECIES2);
            if (species != 0 && species != SPECIES_EGG)
            {
				u8 ability;
                if (gBattlerPartyIndexes[gBankAttacker] == i)
                    ability = gBattleMons[gBankAttacker].ability;
                else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && gBattlerPartyIndexes[gActiveBattler] == i && !(gAbsentBattlerFlags & gBitTable[gActiveBattler]))
                    ability = gBattleMons[gActiveBattler].ability;
                else
                    ability = GetMonAbility(&party[i]);
                if (ability != ABILITY_SOUNDPROOF)
                    to_heal |= (1 << i);
            }
        }
    }
    else //Aromatherapy
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = 4;
        to_heal = 0x3F;
        gBattleMons[gBankAttacker].status1 = zero2;

        gActiveBattler = GetBattlerAtPosition(GetBattlerPosition(gBankAttacker) ^ 2);
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && !(gAbsentBattlerFlags & gBitTable[gActiveBattler]))
            gBattleMons[gActiveBattler].status1 = 0;

    }
    //missing check?
    gActiveBattler = gBankAttacker;
    EmitSetMonData(0, REQUEST_STATUS_BATTLE, to_heal, 4, &zero);
    MarkBufferBankForExecution(gActiveBattler);

    gBattlescriptCurrInstr++;
}

static void atkAF_cursetarget(void)
{
    if (gBattleMons[gBankTarget].status2 & STATUS2_CURSED || gStatuses3[gBankTarget] & STATUS3_SEMI_INVULNERABLE)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gBattleMons[gBankTarget].status2 |= STATUS2_CURSED;
        gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP / 2;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkB0_trysetspikes(void)
{
    u8 side = GetBattlerSide(gBankAttacker) ^ 1;
    if ((gSideTimers[side].spikesAmount & HAZARD_SPIKES) == 3)
    {
        gSpecialStatuses[gBankAttacker].flag20 = 1;
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gSideAffecting[side] |= SIDE_STATUS_SPIKES;
        gSideTimers[side].spikesAmount++;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkB1_setforesight(void)
{
	if (gCurrentMove == MOVE_MIRACLE_EYE)
		gStatuses3[gBankTarget] |= STATUS3_MIRACLE_EYE;
	else
		gBattleMons[gBankTarget].status2 |= STATUS2_FORESIGHT;
    gBattlescriptCurrInstr++;
}

static void atkB2_trysetperishsong(void)
{
    int not_affected_pokes = 0, i;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (gStatuses3[i] & STATUS3_PERISH_SONG || gBattleMons[i].ability == ABILITY_SOUNDPROOF)
            not_affected_pokes++;
        else
        {
            gStatuses3[i] |= STATUS3_PERISH_SONG;
            gDisableStructs[i].perishSongTimer1 = 3;
            gDisableStructs[i].perishSongTimer2 = 3;
        }
    }

    PressurePPLoseOnUsingPerishSong(gBankAttacker);
    if (not_affected_pokes == gBattlersCount)
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    else
        gBattlescriptCurrInstr += 5;
}

static void atkB3_rolloutdamagecalculation(void)
{
    if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
    {
        CancelMultiTurnMoves(gBankAttacker);
        gBattlescriptCurrInstr = BattleScript_MoveMissedPause;
    }
    else
    {
        int i;
        if (!(gBattleMons[gBankAttacker].status2 & STATUS2_MULTIPLETURNS)) //first hit
        {
            gDisableStructs[gBankAttacker].rolloutTimer1 = 5;
            gDisableStructs[gBankAttacker].rolloutTimer2 = 5;
            gBattleMons[gBankAttacker].status2 |= STATUS2_MULTIPLETURNS;
            gLockedMoves[gBankAttacker] = gCurrentMove;
        }
        if (--gDisableStructs[gBankAttacker].rolloutTimer1 == 0)
            gBattleMons[gBankAttacker].status2 &= ~(STATUS2_MULTIPLETURNS);

        gDynamicBasePower = gBattleMoves[gCurrentMove].power;
        for (i = 1; i < (5 - gDisableStructs[gBankAttacker].rolloutTimer1); i++)
            gDynamicBasePower *= 2;

        if (gBattleMons[gBankAttacker].status2 & STATUS2_DEFENSE_CURL)
            gDynamicBasePower *= 2;

        gBattlescriptCurrInstr++;
    }
}

static void atkB4_jumpifconfusedandstatmaxed(void)
{
    if (gBattleMons[gBankTarget].status2 & STATUS2_CONFUSION && gBattleMons[gBankTarget].statStages[T2_READ_8(gBattlescriptCurrInstr + 1)] == 0xC)
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 2);
    else
        gBattlescriptCurrInstr += 6;
}

static void atkB5_furycuttercalc(void)
{
    if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
    {
        gDisableStructs[gBankAttacker].furyCutterCounter = 0;
        gBattlescriptCurrInstr = BattleScript_MoveMissedPause;
    }
    else
    {
        int i;

        if (gDisableStructs[gBankAttacker].furyCutterCounter != 5)
            gDisableStructs[gBankAttacker].furyCutterCounter++;

        gDynamicBasePower = gBattleMoves[gCurrentMove].power;
        for (i = 1; i < gDisableStructs[gBankAttacker].furyCutterCounter; i++)
            gDynamicBasePower *= 2;

        gBattlescriptCurrInstr++;
    }
}

static void atkB6_happinesstodamagecalculation(void)
{
    if (gBattleMoves[gCurrentMove].effect == EFFECT_RETURN)
        gDynamicBasePower = 10 * (gBattleMons[gBankAttacker].friendship) / 25;
    else //EFFECT_FRUSTRATION
        gDynamicBasePower = 10 * (255 - gBattleMons[gBankAttacker].friendship) / 25;
    gBattlescriptCurrInstr++;
}

static void atkB7_presentdamagecalculation(void)
{
    s32 rand = Random() & 0xFF;
    if (rand < 102)
        gDynamicBasePower = 40;
    else if (rand < 178)
        gDynamicBasePower = 80;
    else if (rand < 204)
        gDynamicBasePower = 120;
    else
    {
        gBattleMoveDamage = gBattleMons[gBankTarget].maxHP / 4;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMoveDamage *= -1;
    }
    if (rand < 204)
        gBattlescriptCurrInstr = BattleScript_HitFromCritCalc;
    else if (gBattleMons[gBankTarget].maxHP == gBattleMons[gBankTarget].hp)
        gBattlescriptCurrInstr = BattleScript_AlreadyAtFullHp;
    else
    {
        //gMoveResultFlags &= ~(MOVE_RESULT_DOESNT_AFFECT_FOE); only in Emerald
        gBattlescriptCurrInstr = BattleScript_PresentHealTarget;
    }
}

static void atkB8_setsafeguard(void)
{
    if (gSideAffecting[GetBattlerPosition(gBankAttacker) & 1] & SIDE_STATUS_SAFEGUARD)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    else
    {
        gSideAffecting[GetBattlerPosition(gBankAttacker) & 1] |= SIDE_STATUS_SAFEGUARD;
        gSideTimers[GetBattlerPosition(gBankAttacker) & 1].safeguardTimer = 5;
        gBattleCommunication[MULTISTRING_CHOOSER] = 5;
    }
    gBattlescriptCurrInstr++;
}

static void atkB9_magnitudedamagecalculation(void)
{
    s32 magnitude = Random() % 100;
    if (magnitude < 5)
    {
        gDynamicBasePower = 10;
        magnitude = 4;
    }
    else if (magnitude < 15)
    {
        gDynamicBasePower = 30;
        magnitude = 5;
    }
    else if (magnitude < 35)
    {
        gDynamicBasePower = 50;
        magnitude = 6;
    }
    else if (magnitude < 65)
    {
        gDynamicBasePower = 70;
        magnitude = 7;
    }
    else if (magnitude < 85)
    {
        gDynamicBasePower = 90;
        magnitude = 8;
    }
    else if (magnitude < 95)
    {
        gDynamicBasePower = 110;
        magnitude = 9;
    }
    else
    {
        gDynamicBasePower = 150;
        magnitude = 10;
    }

    gBattleTextBuff1[0] = 0xFD;
    gBattleTextBuff1[1] = 1;
    gBattleTextBuff1[2] = 1;
    gBattleTextBuff1[3] = 2;
    gBattleTextBuff1[4] = magnitude;
    gBattleTextBuff1[5] = 0xFF;

    for (gBankTarget = 0; gBankTarget < gBattlersCount; gBankTarget++)
    {
        if (gBankTarget == gBankAttacker)
            continue;
        if (!(gAbsentBattlerFlags & gBitTable[gBankTarget])) //a valid target was found
            break;
    }
    gBattlescriptCurrInstr++;
}

static void atkBA_jumpifnopursuitswitchdmg(void)
{
    if (gMultiHitCounter == 1)
    {
        if (GetBattlerSide(gBankAttacker) == 0)
            gBankTarget = GetBattlerAtPosition(1);
        else
            gBankTarget = GetBattlerAtPosition(0);
    }
    else
    {
        if (GetBattlerSide(gBankAttacker) == 0)
            gBankTarget = GetBattlerAtPosition(3);
        else
            gBankTarget = GetBattlerAtPosition(2);
    }

    if (gActionForBanks[gBankTarget] == 0 && gBankAttacker == ewram16010arr(gBankTarget) && !(gBattleMons[gBankTarget].status1 & (STATUS_SLEEP | STATUS_FREEZE))
        && gBattleMons[gBankAttacker].hp && !gDisableStructs[gBankTarget].truantCounter && gChosenMovesByBanks[gBankTarget] == MOVE_PURSUIT)
    {
        int i;
        for (i = 0; i < gBattlersCount; i++)
        {
            if (gBanksByTurnOrder[i] == gBankTarget)
                gActionsByTurnOrder[i] = 11;
        }
        gCurrentMove = MOVE_PURSUIT;
        gBattlescriptCurrInstr += 5;
        gBattleStruct->animTurn = 1;
        gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
    }
    else
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
}

static void atkBB_setsunny(void)
{
    if (gBattleWeather & WEATHER_SUN_ANY)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
    }
    else
    {
        gBattleWeather = WEATHER_SUN_TEMPORARY;
        gBattleCommunication[MULTISTRING_CHOOSER] = 4;
        gWishFutureKnock.weatherDuration = 5;
    }
    gBattlescriptCurrInstr++;
}

static void atkBC_maxattackhalvehp(void) //belly drum
{
    u32 half_hp = gBattleMons[gBankAttacker].maxHP / 2;
    if (!(gBattleMons[gBankAttacker].maxHP / 2))
        half_hp = 1;

    if (gBattleMons[gBankAttacker].statStages[STAT_STAGE_ATK] < 12 && gBattleMons[gBankAttacker].hp > half_hp)
    {
        gBattleMons[gBankAttacker].statStages[STAT_STAGE_ATK] = 12;
        gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP / 2;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkBD_copyfoestats(void) //psych up
{
    int i;
    for (i = 0; i < 8; i++)
    {
        gBattleMons[gBankAttacker].statStages[i] = gBattleMons[gBankTarget].statStages[i];
    }
    gBattlescriptCurrInstr += 5; //why not 1? possible unused fail possibility?
}

static void atkBE_rapidspinfree(void) //rapid spin
{
    if (gBattleMons[gBankAttacker].status2 & STATUS2_WRAPPED)
    {
        gBattleMons[gBankAttacker].status2 &= ~(STATUS2_WRAPPED);
        gBankTarget = ewram16020arr(gBankAttacker);
        gBattleTextBuff1[0] = 0xFD;
        gBattleTextBuff1[1] = 2;
        gBattleTextBuff1[2] = ewram16004arr(0, gBankAttacker);
        gBattleTextBuff1[3] = ewram16004arr(1, gBankAttacker);
        gBattleTextBuff1[4] = 0xFF;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_WrapFree;
    }
    else if (gStatuses3[gBankAttacker] & STATUS3_LEECHSEED)
    {
        gStatuses3[gBankAttacker] &= ~(STATUS3_LEECHSEED);
        gStatuses3[gBankAttacker] &= ~(STATUS3_LEECHSEED_BANK);
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_LeechSeedFree;
    }
    else if (gSideTimers[GetBattlerSide(gBankAttacker)].spikesAmount & HAZARD_SPIKES)
    {
        gSideTimers[GetBattlerSide(gBankAttacker)].spikesAmount &= ~(HAZARD_SPIKES);
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_SpikesFree;
		gBattleTextBuff1[0] = 0xFD;
		gBattleTextBuff1[1] = 2;
		gBattleTextBuff1[2] = MOVE_SPIKES;
		gBattleTextBuff1[3] = MOVE_SPIKES >> 8;
		gBattleTextBuff1[4] = EOS;
    }
    else if (gSideTimers[GetBattlerSide(gBankAttacker)].spikesAmount & HAZARD_STEALTH_ROCK)
    {
        gSideTimers[GetBattlerSide(gBankAttacker)].spikesAmount &= ~(HAZARD_STEALTH_ROCK);
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_SpikesFree;
		gBattleTextBuff1[0] = 0xFD;
		gBattleTextBuff1[1] = 2;
		gBattleTextBuff1[2] = (u8)MOVE_STEALTH_ROCK;
		gBattleTextBuff1[3] = MOVE_STEALTH_ROCK >> 8;
		gBattleTextBuff1[4] = EOS;
    }
    else if (gSideTimers[GetBattlerSide(gBankAttacker)].spikesAmount & HAZARD_TOXIC_SPIKES_ANY)
    {
        gSideTimers[GetBattlerSide(gBankAttacker)].spikesAmount &= ~(HAZARD_TOXIC_SPIKES_ANY);
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_SpikesFree;
		gBattleTextBuff1[0] = 0xFD;
		gBattleTextBuff1[1] = 2;
		gBattleTextBuff1[2] = (u8)MOVE_TOXIC_SPIKES;
		gBattleTextBuff1[3] = MOVE_TOXIC_SPIKES >> 8;
		gBattleTextBuff1[4] = EOS;
    }
    else if (gSideTimers[GetBattlerSide(gBankAttacker)].spikesAmount & HAZARD_STICKY_WEB)
    {
        gSideTimers[GetBattlerSide(gBankAttacker)].spikesAmount &= ~(HAZARD_STICKY_WEB);
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_SpikesFree;
		gBattleTextBuff1[0] = 0xFD;
		gBattleTextBuff1[1] = 2;
		gBattleTextBuff1[2] = (u8)MOVE_STICKY_WEB;
		gBattleTextBuff1[3] = MOVE_STICKY_WEB >> 8;
		gBattleTextBuff1[4] = EOS;
    }
    else
        gBattlescriptCurrInstr++;
}

static void atkBF_setdefensecurlbit(void)
{
    gBattleMons[gBankAttacker].status2 |= STATUS2_DEFENSE_CURL;
    gBattlescriptCurrInstr++;
}

static void atkC0_recoverbasedonsunlight(void)
{
    gBankTarget = gBankAttacker;
    if (gBattleMons[gBankAttacker].hp != gBattleMons[gBankAttacker].maxHP)
    {
        if (!gBattleWeather || !WEATHER_HAS_EFFECT)
            gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP / 2;
        else if (gBattleWeather & WEATHER_SUN_ANY)
            gBattleMoveDamage = 20 * gBattleMons[gBankAttacker].maxHP / 30;
        else //not sunny weather
            gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP / 4;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMoveDamage *= -1;
        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkC1_hiddenpowercalc(void)
{
	u8 type = ((gBattleMons[gBankAttacker].hpIV & 1)) |
	          ((gBattleMons[gBankAttacker].attackIV & 1) << 1) |
	          ((gBattleMons[gBankAttacker].defenseIV & 1) << 2) |
	          ((gBattleMons[gBankAttacker].speedIV & 1) << 3) |
	          ((gBattleMons[gBankAttacker].spAttackIV & 1) << 4) |
	          ((gBattleMons[gBankAttacker].spDefenseIV & 1) << 5);

	gBattleStruct->dynamicMoveType = ((type * 15) / 63) + 1;
	if (gBattleStruct->dynamicMoveType >= TYPE_FAIRY)
		gBattleStruct->dynamicMoveType++;

	gBattleStruct->dynamicMoveType |= 0xC0;

	gBattlescriptCurrInstr++;
}

static void atkC2_selectfirstvalidtarget(void)
{
    for (gBankTarget = 0; gBankTarget < gBattlersCount; gBankTarget++)
    {
        if (gBankTarget == gBankAttacker)
            continue;
        if (!(gAbsentBattlerFlags & gBitTable[gBankTarget]))
            break;
    }
    gBattlescriptCurrInstr++;
}

static void atkC3_trysetfutureattack(void)
{
    if (gWishFutureKnock.futureSightCounter[gBankTarget] != 0)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
		if (gCurrentMove == MOVE_FUTURE_SIGHT)
			gWishFutureKnock.futureSightMove[gBankTarget] = 0;
		else // Doom Desire
			gWishFutureKnock.futureSightMove[gBankTarget] = 1;
        gWishFutureKnock.futureSightAttacker[gBankTarget] = gBankAttacker;
        gWishFutureKnock.futureSightCounter[gBankTarget] = 3;
        gWishFutureKnock.futureSightDmg[gBankTarget] = CalculateBaseDamage(&gBattleMons[gBankAttacker], &gBattleMons[gBankTarget], gCurrentMove,
                                                    gSideAffecting[GetBattlerPosition(gBankTarget) & 1], 0,
                                                    0, gBankAttacker, gBankTarget);

        if (gProtectStructs[gBankAttacker].helpingHand)
            gWishFutureKnock.futureSightDmg[gBankTarget] = gWishFutureKnock.futureSightDmg[gBankTarget] * 15 / 10;

        if (gCurrentMove == MOVE_DOOM_DESIRE)
            gBattleCommunication[MULTISTRING_CHOOSER] = 1;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;

        gBattlescriptCurrInstr += 5;
    }
}

#ifdef NONMATCHING
static void atkC4_trydobeatup(void)
{
    register struct Pokemon* party asm("r7");
    if (GetBattlerSide(gBankAttacker) == 0)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    if (gBattleMons[gBankTarget].hp == 0)
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    else
    {
        while (gBattleCommunication[0] < 6)
        {
            if (GetMonData(&party[gBattleCommunication[0]], MON_DATA_HP) && GetMonData(&party[gBattleCommunication[0]], MON_DATA_SPECIES2)
                && GetMonData(&party[gBattleCommunication[0]], MON_DATA_SPECIES2) != SPECIES_EGG && !GetMonData(&party[gBattleCommunication[0]], MON_DATA_STATUS))
                    break;
            gBattleCommunication[0]++;
        }
        if (gBattleCommunication[0] < 6)
        {
            gBattleTextBuff1[0] = 0xFD;
            gBattleTextBuff1[1] = 4;
            gBattleTextBuff1[2] = gBankAttacker;
            gBattleTextBuff1[3] = gBattleCommunication[0];
            gBattleTextBuff1[4] = 0xFF;
            gBattlescriptCurrInstr += 9;

            gBattleMoveDamage = gBaseStats[GetMonData(&party[gBattleCommunication[0]], MON_DATA_SPECIES)].baseAttack;
            gBattleMoveDamage *= gBattleMoves[gCurrentMove].power;
            gBattleMoveDamage *= (GetMonData(&party[gBattleCommunication[0]], MON_DATA_LEVEL) * 2 / 5 + 2);
            gBattleMoveDamage /= gBaseStats[gBattleMons[gBankTarget].species].baseDefense;
            gBattleMoveDamage = (gBattleMoveDamage / 50) + 2;
            if (gProtectStructs[gBankAttacker].helpingHand)
                gBattleMoveDamage = gBattleMoveDamage * 15 / 10;

            gBattleCommunication[0]++;
        }
        else if (gBattleCommunication[0] != 0)
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
        else
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 5);
    }
}
#else
NAKED
static void atkC4_trydobeatup(void)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r9\n\
    mov r6, r8\n\
    push {r6,r7}\n\
    ldr r0, _08029A8C @ =gBankAttacker\n\
    ldrb r0, [r0]\n\
    bl GetBattlerSide\n\
    lsls r0, 24\n\
    ldr r7, _08029A90 @ =gEnemyParty\n\
    cmp r0, 0\n\
    bne _08029A62\n\
    ldr r7, _08029A94 @ =gPlayerParty\n\
_08029A62:\n\
    ldr r2, _08029A98 @ =gBattleMons\n\
    ldr r0, _08029A9C @ =gBankTarget\n\
    ldrb r1, [r0]\n\
    movs r0, 0x58\n\
    muls r0, r1\n\
    adds r0, r2\n\
    ldrh r0, [r0, 0x28]\n\
    cmp r0, 0\n\
    bne _08029AA4\n\
    ldr r3, _08029AA0 @ =gBattlescriptCurrInstr\n\
    ldr r2, [r3]\n\
    ldrb r1, [r2, 0x1]\n\
    ldrb r0, [r2, 0x2]\n\
    lsls r0, 8\n\
    orrs r1, r0\n\
    ldrb r0, [r2, 0x3]\n\
    lsls r0, 16\n\
    orrs r1, r0\n\
    ldrb r0, [r2, 0x4]\n\
    b _08029C40\n\
    .align 2, 0\n\
_08029A8C: .4byte gBankAttacker\n\
_08029A90: .4byte gEnemyParty\n\
_08029A94: .4byte gPlayerParty\n\
_08029A98: .4byte gBattleMons\n\
_08029A9C: .4byte gBankTarget\n\
_08029AA0: .4byte gBattlescriptCurrInstr\n\
_08029AA4:\n\
    ldr r6, _08029BE0 @ =gBattleCommunication\n\
    ldrb r0, [r6]\n\
    mov r8, r0\n\
    cmp r0, 0x5\n\
    bls _08029AB0\n\
    b _08029C0C\n\
_08029AB0:\n\
    adds r4, r6, 0\n\
    movs r5, 0x64\n\
_08029AB4:\n\
    ldrb r0, [r4]\n\
    muls r0, r5\n\
    adds r0, r7, r0\n\
    movs r1, 0x39\n\
    bl GetMonData\n\
    cmp r0, 0\n\
    beq _08029AF8\n\
    ldrb r0, [r6]\n\
    muls r0, r5\n\
    adds r0, r7, r0\n\
    movs r1, 0x41\n\
    bl GetMonData\n\
    cmp r0, 0\n\
    beq _08029AF8\n\
    ldrb r0, [r4]\n\
    muls r0, r5\n\
    adds r0, r7, r0\n\
    movs r1, 0x41\n\
    bl GetMonData\n\
    movs r1, 0xCE\n\
    lsls r1, 1\n\
    cmp r0, r1\n\
    beq _08029AF8\n\
    ldrb r0, [r4]\n\
    muls r0, r5\n\
    adds r0, r7, r0\n\
    movs r1, 0x37\n\
    bl GetMonData\n\
    cmp r0, 0\n\
    beq _08029B08\n\
_08029AF8:\n\
    ldrb r0, [r4]\n\
    adds r0, 0x1\n\
    strb r0, [r4]\n\
    adds r6, r4, 0\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    cmp r0, 0x5\n\
    bls _08029AB4\n\
_08029B08:\n\
    ldr r1, _08029BE0 @ =gBattleCommunication\n\
    mov r9, r1\n\
    ldrb r2, [r1]\n\
    cmp r2, 0x5\n\
    bhi _08029C0C\n\
    ldr r1, _08029BE4 @ =gBattleTextBuff1\n\
    movs r0, 0xFD\n\
    strb r0, [r1]\n\
    movs r0, 0x4\n\
    strb r0, [r1, 0x1]\n\
    ldr r6, _08029BE8 @ =gBankAttacker\n\
    ldrb r0, [r6]\n\
    strb r0, [r1, 0x2]\n\
    strb r2, [r1, 0x3]\n\
    movs r0, 0xFF\n\
    strb r0, [r1, 0x4]\n\
    ldr r1, _08029BEC @ =gBattlescriptCurrInstr\n\
    ldr r0, [r1]\n\
    adds r0, 0x9\n\
    str r0, [r1]\n\
    ldr r2, _08029BF0 @ =gBattleMoveDamage\n\
    mov r8, r2\n\
    ldr r5, _08029BF4 @ =gBaseStats\n\
    mov r1, r9\n\
    ldrb r0, [r1]\n\
    movs r4, 0x64\n\
    muls r0, r4\n\
    adds r0, r7, r0\n\
    movs r1, 0xB\n\
    bl GetMonData\n\
    lsls r1, r0, 3\n\
    subs r1, r0\n\
    lsls r1, 2\n\
    adds r1, r5\n\
    ldrb r3, [r1, 0x1]\n\
    mov r2, r8\n\
    str r3, [r2]\n\
    ldr r2, _08029BF8 @ =gBattleMoves\n\
    ldr r0, _08029BFC @ =gCurrentMove\n\
    ldrh r1, [r0]\n\
    lsls r0, r1, 1\n\
    adds r0, r1\n\
    lsls r0, 2\n\
    adds r0, r2\n\
    ldrb r0, [r0, 0x1]\n\
    muls r0, r3\n\
    mov r1, r8\n\
    str r0, [r1]\n\
    mov r2, r9\n\
    ldrb r0, [r2]\n\
    muls r0, r4\n\
    adds r0, r7, r0\n\
    movs r1, 0x38\n\
    bl GetMonData\n\
    lsls r0, 1\n\
    movs r1, 0x5\n\
    bl __udivsi3\n\
    adds r0, 0x2\n\
    mov r2, r8\n\
    ldr r1, [r2]\n\
    muls r0, r1\n\
    str r0, [r2]\n\
    ldr r3, _08029C00 @ =gBattleMons\n\
    ldr r1, _08029C04 @ =gBankTarget\n\
    ldrb r2, [r1]\n\
    movs r1, 0x58\n\
    muls r1, r2\n\
    adds r1, r3\n\
    ldrh r2, [r1]\n\
    lsls r1, r2, 3\n\
    subs r1, r2\n\
    lsls r1, 2\n\
    adds r1, r5\n\
    ldrb r1, [r1, 0x2]\n\
    bl __divsi3\n\
    mov r1, r8\n\
    str r0, [r1]\n\
    movs r1, 0x32\n\
    bl __divsi3\n\
    adds r2, r0, 0x2\n\
    mov r0, r8\n\
    str r2, [r0]\n\
    ldr r1, _08029C08 @ =gProtectStructs\n\
    ldrb r0, [r6]\n\
    lsls r0, 4\n\
    adds r0, r1\n\
    ldrb r0, [r0]\n\
    lsls r0, 28\n\
    cmp r0, 0\n\
    bge _08029BD4\n\
    lsls r0, r2, 4\n\
    subs r0, r2\n\
    movs r1, 0xA\n\
    bl __divsi3\n\
    mov r1, r8\n\
    str r0, [r1]\n\
_08029BD4:\n\
    mov r2, r9\n\
    ldrb r0, [r2]\n\
    adds r0, 0x1\n\
    strb r0, [r2]\n\
    b _08029C46\n\
    .align 2, 0\n\
_08029BE0: .4byte gBattleCommunication\n\
_08029BE4: .4byte gBattleTextBuff1\n\
_08029BE8: .4byte gBankAttacker\n\
_08029BEC: .4byte gBattlescriptCurrInstr\n\
_08029BF0: .4byte gBattleMoveDamage\n\
_08029BF4: .4byte gBaseStats\n\
_08029BF8: .4byte gBattleMoves\n\
_08029BFC: .4byte gCurrentMove\n\
_08029C00: .4byte gBattleMons\n\
_08029C04: .4byte gBankTarget\n\
_08029C08: .4byte gProtectStructs\n\
_08029C0C:\n\
    mov r0, r8\n\
    cmp r0, 0\n\
    beq _08029C2C\n\
    ldr r3, _08029C28 @ =gBattlescriptCurrInstr\n\
    ldr r2, [r3]\n\
    ldrb r1, [r2, 0x1]\n\
    ldrb r0, [r2, 0x2]\n\
    lsls r0, 8\n\
    orrs r1, r0\n\
    ldrb r0, [r2, 0x3]\n\
    lsls r0, 16\n\
    orrs r1, r0\n\
    ldrb r0, [r2, 0x4]\n\
    b _08029C40\n\
    .align 2, 0\n\
_08029C28: .4byte gBattlescriptCurrInstr\n\
_08029C2C:\n\
    ldr r3, _08029C54 @ =gBattlescriptCurrInstr\n\
    ldr r2, [r3]\n\
    ldrb r1, [r2, 0x5]\n\
    ldrb r0, [r2, 0x6]\n\
    lsls r0, 8\n\
    orrs r1, r0\n\
    ldrb r0, [r2, 0x7]\n\
    lsls r0, 16\n\
    orrs r1, r0\n\
    ldrb r0, [r2, 0x8]\n\
_08029C40:\n\
    lsls r0, 24\n\
    orrs r1, r0\n\
    str r1, [r3]\n\
_08029C46:\n\
    pop {r3,r4}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .align 2, 0\n\
_08029C54: .4byte gBattlescriptCurrInstr\n\
        .syntax divided");
}
#endif // NONMATCHING

static void atkC5_setsemiinvulnerablebit(void)
{
    switch (gCurrentMove)
    {
    case MOVE_FLY:
    case MOVE_BOUNCE:
        gStatuses3[gBankAttacker] |= STATUS3_ON_AIR;
        break;
    case MOVE_DIG:
        gStatuses3[gBankAttacker] |= STATUS3_UNDERGROUND;
        break;
    case MOVE_DIVE:
        gStatuses3[gBankAttacker] |= STATUS3_UNDERWATER;
        break;
	case MOVE_PHANTOM_FORCE:
        gStatuses3[gBankAttacker] |= STATUS3_IN_SHADOWS;
        break;
    }
    gBattlescriptCurrInstr++;
}

static void atkC6_clearsemiinvulnerablebit(void)
{
    switch (gCurrentMove)
    {
    case MOVE_FLY:
    case MOVE_BOUNCE:
        gStatuses3[gBankAttacker] &= ~STATUS3_ON_AIR;
        break;
    case MOVE_DIG:
        gStatuses3[gBankAttacker] &= ~STATUS3_UNDERGROUND;
        break;
    case MOVE_DIVE:
        gStatuses3[gBankAttacker] &= ~STATUS3_UNDERWATER;
        break;
	case MOVE_PHANTOM_FORCE:
        gStatuses3[gBankAttacker] &= ~STATUS3_IN_SHADOWS;
        break;
    }
    gBattlescriptCurrInstr++;
}

static void atkC7_setminimize(void)
{
    if (gHitMarker & HITMARKER_OBEYS)
        gStatuses3[gBankAttacker] |= STATUS3_MINIMIZED;
    gBattlescriptCurrInstr++;
}

static void atkC8_sethail(void)
{
    if (gBattleWeather & WEATHER_HAIL)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
    }
    else
    {
        gBattleWeather = WEATHER_HAIL;
        gBattleCommunication[MULTISTRING_CHOOSER] = 5;
        gWishFutureKnock.weatherDuration = 5;
    }
    gBattlescriptCurrInstr++;
}

static void atkC9_jumpifattackandspecialattackcannotfall(void) //memento
{
    if (gBattleMons[gBankTarget].statStages[STAT_STAGE_ATK] == 0
        && gBattleMons[gBankTarget].statStages[STAT_STAGE_SPATK] == 0
        && gBattleCommunication[6] != 1)
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    else
    {
        gActiveBattler = gBankAttacker;
        gBattleMoveDamage = gBattleMons[gActiveBattler].hp;
        EmitHealthBarUpdate(0, 0x7FFF);
        MarkBufferBankForExecution(gActiveBattler);
        gBattlescriptCurrInstr += 5;
    }
}

static void atkCA_setforcedtarget(void) //follow me
{
    gSideTimers[GetBattlerSide(gBankAttacker)].followmeTimer = 1;
    gSideTimers[GetBattlerSide(gBankAttacker)].followmeTarget = gBankAttacker;
    gBattlescriptCurrInstr++;
}

static void atkCB_setcharge(void)
{
    gStatuses3[gBankAttacker] |= STATUS3_CHARGED_UP;
    gDisableStructs[gBankAttacker].chargeTimer1 = 2;
    gDisableStructs[gBankAttacker].chargeTimer2 = 2;
    gBattlescriptCurrInstr++;
}

static void atkCC_callterrainattack(void) //nature power
{
    gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
    gCurrentMove = sNaturePowerMoves[gBattleTerrain];
    gBankTarget = GetMoveTarget(gCurrentMove, 0);
    BattleScriptPush(gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect]);
    gBattlescriptCurrInstr++;
}

static void atkCD_cureifburnedparalysedorpoisoned(void) //refresh
{
    if (gBattleMons[gBankAttacker].status1 & (STATUS_POISON | STATUS_BURN | STATUS_PARALYSIS | STATUS_TOXIC_POISON))
    {
        gBattleMons[gBankAttacker].status1 = 0;
        gBattlescriptCurrInstr += 5;
        gActiveBattler = gBankAttacker;
        EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
        MarkBufferBankForExecution(gActiveBattler);
    }
    else
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
}

static void atkCE_settorment(void)
{
    if (gBattleMons[gBankTarget].status2 & STATUS2_TORMENT)
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    else
    {
        gBattleMons[gBankTarget].status2 |= STATUS2_TORMENT;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkCF_jumpifnodamage(void)
{
    if (gProtectStructs[gBankAttacker].physicalDmg || gProtectStructs[gBankAttacker].specialDmg)
        gBattlescriptCurrInstr += 5;
    else
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
}

static void atkD0_settaunt(void)
{
    if (gDisableStructs[gBankTarget].tauntTimer1 == 0)
    {
        gDisableStructs[gBankTarget].tauntTimer1 = 2;
        gDisableStructs[gBankTarget].tauntTimer2 = 2;
        gBattlescriptCurrInstr += 5;
    }
    else
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
}

static void atkD1_trysethelpinghand(void)
{
    gBankTarget = GetBattlerAtPosition(GetBattlerPosition(gBankAttacker) ^ 2);
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && !(gAbsentBattlerFlags & gBitTable[gBankTarget])
        && !gProtectStructs[gBankAttacker].helpingHand && !gProtectStructs[gBankTarget].helpingHand)
    {
        gProtectStructs[gBankTarget].helpingHand = 1;
        gBattlescriptCurrInstr += 5;
    }
    else
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
}

#ifdef NONMATCHING
static void atkD2_tryswapitems(void)
{
    if ((GetBattlerSide(gBankAttacker) != 1 || gBattleTypeFlags & (BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_LINK | BATTLE_TYPE_EREADER_TRAINER) || gTrainerBattleOpponent == 0x400))
    {
        u8 side = GetBattlerSide(gBankAttacker);
        if (gBattleTypeFlags)
    }

    gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
}

#else
NAKED
static void atkD2_tryswapitems(void)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x4\n\
    ldr r0, _0802A30C @ =gBankAttacker\n\
    ldrb r0, [r0]\n\
    bl GetBattlerSide\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    cmp r0, 0x1\n\
    bne _0802A24C\n\
    ldr r0, _0802A310 @ =gBattleTypeFlags\n\
    ldrh r1, [r0]\n\
    ldr r0, _0802A314 @ =0x00000902\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    bne _0802A24C\n\
    ldr r0, _0802A318 @ =gTrainerBattleOpponent\n\
    ldrh r1, [r0]\n\
    movs r0, 0x80\n\
    lsls r0, 3\n\
    cmp r1, r0\n\
    bne _0802A2EE\n\
_0802A24C:\n\
    ldr r4, _0802A30C @ =gBankAttacker\n\
    ldrb r0, [r4]\n\
    bl GetBattlerSide\n\
    lsls r0, 24\n\
    lsrs r2, r0, 24\n\
    ldr r0, _0802A310 @ =gBattleTypeFlags\n\
    ldrh r1, [r0]\n\
    ldr r0, _0802A314 @ =0x00000902\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    bne _0802A290\n\
    ldr r0, _0802A318 @ =gTrainerBattleOpponent\n\
    ldrh r1, [r0]\n\
    movs r0, 0x80\n\
    lsls r0, 3\n\
    cmp r1, r0\n\
    beq _0802A290\n\
    ldr r0, _0802A31C @ =gWishFutureKnock\n\
    adds r0, 0x29\n\
    adds r0, r2, r0\n\
    ldrb r1, [r0]\n\
    ldr r3, _0802A320 @ =gBitTable\n\
    ldr r2, _0802A324 @ =gBattlerPartyIndexes\n\
    ldrb r0, [r4]\n\
    lsls r0, 1\n\
    adds r0, r2\n\
    ldrh r0, [r0]\n\
    lsls r0, 2\n\
    adds r0, r3\n\
    ldr r0, [r0]\n\
    ands r1, r0\n\
    cmp r1, 0\n\
    bne _0802A2EE\n\
_0802A290:\n\
    ldr r0, _0802A328 @ =gBattleMons\n\
    mov r9, r0\n\
    ldr r1, _0802A30C @ =gBankAttacker\n\
    ldrb r4, [r1]\n\
    movs r2, 0x58\n\
    mov r8, r2\n\
    mov r0, r8\n\
    muls r0, r4\n\
    mov r3, r9\n\
    adds r5, r0, r3\n\
    ldrh r3, [r5, 0x2E]\n\
    adds r1, r3, 0\n\
    cmp r1, 0\n\
    bne _0802A2BE\n\
    ldr r0, _0802A32C @ =gBankTarget\n\
    ldrb r0, [r0]\n\
    mov r2, r8\n\
    muls r2, r0\n\
    adds r0, r2, 0\n\
    add r0, r9\n\
    ldrh r0, [r0, 0x2E]\n\
    cmp r0, 0\n\
    beq _0802A2EE\n\
_0802A2BE:\n\
    cmp r1, 0xAF\n\
    beq _0802A2EE\n\
    ldr r7, _0802A32C @ =gBankTarget\n\
    ldrb r0, [r7]\n\
    mov r1, r8\n\
    muls r1, r0\n\
    adds r0, r1, 0\n\
    mov r1, r9\n\
    adds r2, r0, r1\n\
    ldrh r1, [r2, 0x2E]\n\
    cmp r1, 0xAF\n\
    beq _0802A2EE\n\
    adds r0, r3, 0\n\
    subs r0, 0x79\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    cmp r0, 0xB\n\
    bls _0802A2EE\n\
    adds r0, r1, 0\n\
    subs r0, 0x79\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    cmp r0, 0xB\n\
    bhi _0802A334\n\
_0802A2EE:\n\
    ldr r3, _0802A330 @ =gBattlescriptCurrInstr\n\
    ldr r2, [r3]\n\
    ldrb r1, [r2, 0x1]\n\
    ldrb r0, [r2, 0x2]\n\
    lsls r0, 8\n\
    orrs r1, r0\n\
    ldrb r0, [r2, 0x3]\n\
    lsls r0, 16\n\
    orrs r1, r0\n\
    ldrb r0, [r2, 0x4]\n\
    lsls r0, 24\n\
    orrs r1, r0\n\
    str r1, [r3]\n\
    b _0802A49A\n\
    .align 2, 0\n\
_0802A30C: .4byte gBankAttacker\n\
_0802A310: .4byte gBattleTypeFlags\n\
_0802A314: .4byte 0x00000902\n\
_0802A318: .4byte gTrainerBattleOpponent\n\
_0802A31C: .4byte gWishFutureKnock\n\
_0802A320: .4byte gBitTable\n\
_0802A324: .4byte gBattlerPartyIndexes\n\
_0802A328: .4byte gBattleMons\n\
_0802A32C: .4byte gBankTarget\n\
_0802A330: .4byte gBattlescriptCurrInstr\n\
_0802A334:\n\
    adds r0, r2, 0\n\
    adds r0, 0x20\n\
    ldrb r0, [r0]\n\
    cmp r0, 0x3C\n\
    bne _0802A36C\n\
    ldr r1, _0802A360 @ =gBattlescriptCurrInstr\n\
    ldr r0, _0802A364 @ =BattleScript_NoItemSteal\n\
    str r0, [r1]\n\
    ldr r1, _0802A368 @ =gLastUsedAbility\n\
    ldrb r0, [r7]\n\
    mov r2, r8\n\
    muls r2, r0\n\
    adds r0, r2, 0\n\
    add r0, r9\n\
    adds r0, 0x20\n\
    ldrb r0, [r0]\n\
    strb r0, [r1]\n\
    ldrb r0, [r7]\n\
    ldrb r1, [r1]\n\
    bl RecordAbilityBattle\n\
    b _0802A49A\n\
    .align 2, 0\n\
_0802A360: .4byte gBattlescriptCurrInstr\n\
_0802A364: .4byte BattleScript_NoItemSteal\n\
_0802A368: .4byte gLastUsedAbility\n\
_0802A36C:\n\
    lsls r0, r4, 1\n\
    ldr r4, _0802A458 @ =gSharedMem + 0x160F0\n\
    adds r6, r0, r4\n\
    ldrh r5, [r5, 0x2E]\n\
    mov r10, r5\n\
    strh r1, [r6]\n\
    ldr r3, _0802A45C @ =gBankAttacker\n\
    ldrb r0, [r3]\n\
    mov r1, r8\n\
    muls r1, r0\n\
    adds r0, r1, 0\n\
    add r0, r9\n\
    movs r1, 0\n\
    strh r1, [r0, 0x2E]\n\
    ldrb r0, [r7]\n\
    mov r2, r8\n\
    muls r2, r0\n\
    adds r0, r2, 0\n\
    add r0, r9\n\
    mov r3, r10\n\
    strh r3, [r0, 0x2E]\n\
    ldr r5, _0802A460 @ =gActiveBattler\n\
    ldr r1, _0802A45C @ =gBankAttacker\n\
    ldrb r0, [r1]\n\
    strb r0, [r5]\n\
    str r6, [sp]\n\
    movs r0, 0\n\
    movs r1, 0x2\n\
    movs r2, 0\n\
    movs r3, 0x2\n\
    bl EmitSetMonData\n\
    ldr r2, _0802A45C @ =gBankAttacker\n\
    ldrb r0, [r2]\n\
    bl MarkBufferBankForExecution\n\
    ldrb r0, [r7]\n\
    strb r0, [r5]\n\
    ldrb r0, [r7]\n\
    mov r3, r8\n\
    muls r3, r0\n\
    adds r0, r3, 0\n\
    mov r1, r9\n\
    adds r1, 0x2E\n\
    adds r0, r1\n\
    str r0, [sp]\n\
    movs r0, 0\n\
    movs r1, 0x2\n\
    movs r2, 0\n\
    movs r3, 0x2\n\
    bl EmitSetMonData\n\
    ldrb r0, [r7]\n\
    bl MarkBufferBankForExecution\n\
    ldr r0, _0802A464 @ =0xfffe9f10\n\
    adds r4, r0\n\
    ldrb r0, [r7]\n\
    lsls r0, 1\n\
    ldr r2, _0802A468 @ =0x000160e8\n\
    adds r0, r2\n\
    adds r0, r4\n\
    movs r1, 0\n\
    strb r1, [r0]\n\
    ldrb r0, [r7]\n\
    lsls r0, 1\n\
    ldr r1, _0802A46C @ =0x000160e9\n\
    adds r0, r1\n\
    adds r0, r4\n\
    movs r3, 0\n\
    strb r3, [r0]\n\
    ldr r3, _0802A45C @ =gBankAttacker\n\
    ldrb r0, [r3]\n\
    lsls r0, 1\n\
    adds r0, r2\n\
    adds r0, r4\n\
    movs r2, 0\n\
    strb r2, [r0]\n\
    ldrb r0, [r3]\n\
    lsls r0, 1\n\
    adds r0, r1\n\
    adds r0, r4\n\
    strb r2, [r0]\n\
    ldr r1, _0802A470 @ =gBattlescriptCurrInstr\n\
    ldr r0, [r1]\n\
    adds r0, 0x5\n\
    str r0, [r1]\n\
    ldr r1, _0802A474 @ =gBattleTextBuff1\n\
    movs r3, 0xFD\n\
    strb r3, [r1]\n\
    movs r2, 0xA\n\
    strb r2, [r1, 0x1]\n\
    ldrh r0, [r6]\n\
    strb r0, [r1, 0x2]\n\
    ldrh r0, [r6]\n\
    lsrs r0, 8\n\
    strb r0, [r1, 0x3]\n\
    movs r0, 0xFF\n\
    strb r0, [r1, 0x4]\n\
    ldr r1, _0802A478 @ =gBattleTextBuff2\n\
    strb r3, [r1]\n\
    strb r2, [r1, 0x1]\n\
    mov r3, r10\n\
    strb r3, [r1, 0x2]\n\
    mov r2, r10\n\
    lsrs r0, r2, 8\n\
    strb r0, [r1, 0x3]\n\
    movs r0, 0x1\n\
    negs r0, r0\n\
    strb r0, [r1, 0x4]\n\
    cmp r2, 0\n\
    beq _0802A480\n\
    ldrh r0, [r6]\n\
    cmp r0, 0\n\
    beq _0802A494\n\
    ldr r1, _0802A47C @ =gBattleCommunication\n\
    movs r0, 0x2\n\
    b _0802A498\n\
    .align 2, 0\n\
_0802A458: .4byte gSharedMem + 0x160F0\n\
_0802A45C: .4byte gBankAttacker\n\
_0802A460: .4byte gActiveBattler\n\
_0802A464: .4byte 0xfffe9f10\n\
_0802A468: .4byte 0x000160e8\n\
_0802A46C: .4byte 0x000160e9\n\
_0802A470: .4byte gBattlescriptCurrInstr\n\
_0802A474: .4byte gBattleTextBuff1\n\
_0802A478: .4byte gBattleTextBuff2\n\
_0802A47C: .4byte gBattleCommunication\n\
_0802A480:\n\
    ldrh r0, [r6]\n\
    cmp r0, 0\n\
    beq _0802A494\n\
    ldr r0, _0802A490 @ =gBattleCommunication\n\
    movs r3, 0\n\
    strb r3, [r0, 0x5]\n\
    b _0802A49A\n\
    .align 2, 0\n\
_0802A490: .4byte gBattleCommunication\n\
_0802A494:\n\
    ldr r1, _0802A4AC @ =gBattleCommunication\n\
    movs r0, 0x1\n\
_0802A498:\n\
    strb r0, [r1, 0x5]\n\
_0802A49A:\n\
    add sp, 0x4\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .align 2, 0\n\
_0802A4AC: .4byte gBattleCommunication\n\
        .syntax divided");
}
#endif // NONMATCHING

static void atkD3_trycopyability(void) //role play
{
    if (gBattleMons[gBankTarget].ability != 0 && gBattleMons[gBankTarget].ability != ABILITY_WONDER_GUARD)
    {
        gBattleMons[gBankAttacker].ability = gBattleMons[gBankTarget].ability;
        gLastUsedAbility = gBattleMons[gBankTarget].ability;
        gBattlescriptCurrInstr += 5;
    }
    else
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
}

static void atkD4_trywish(void)
{
    switch (T2_READ_8(gBattlescriptCurrInstr + 1))
    {
    case 0: //use wish
        if (gWishFutureKnock.wishCounter[gBankAttacker] == 0)
        {
            gWishFutureKnock.wishCounter[gBankAttacker] = 2;
            gWishFutureKnock.wishUserID[gBankAttacker] = gBattlerPartyIndexes[gBankAttacker];
            gBattlescriptCurrInstr += 6;
        }
        else
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 2);
        break;
    case 1: //heal effect
        gBattleTextBuff1[0] = 0xFD;
        gBattleTextBuff1[1] = 4;
        gBattleTextBuff1[2] = gBankTarget;
        gBattleTextBuff1[3] = gWishFutureKnock.wishUserID[gBankTarget];
        gBattleTextBuff1[4] = 0xFF;
        gBattleMoveDamage = gBattleMons[gBankTarget].maxHP / 2;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMoveDamage *= -1;
        if (gBattleMons[gBankTarget].hp == gBattleMons[gBankTarget].maxHP)
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 2);
        else
            gBattlescriptCurrInstr += 6;
        break;
    }
}

static void atkD5_trysetroots(void) //ingrain
{
    if (gStatuses3[gBankAttacker] & STATUS3_ROOTED)
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    else
    {
        gStatuses3[gBankAttacker] |= STATUS3_ROOTED;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkD6_doubledamagedealtifdamaged(void)
{
    if ((gProtectStructs[gBankAttacker].physicalDmg && gProtectStructs[gBankAttacker].physicalBank == gBankTarget)
        || (gProtectStructs[gBankAttacker].specialDmg && gProtectStructs[gBankAttacker].specialBank == gBankTarget))
            gBattleStruct->dmgMultiplier = 2;
    gBattlescriptCurrInstr++;
}

static void atkD7_setyawn(void)
{
    if (gStatuses3[gBankTarget] & STATUS3_YAWN || (u8) gBattleMons[gBankTarget].status1)
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    else
    {
        gStatuses3[gBankTarget] |= 0x1000;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkD8_setdamagetohealthdifference(void)
{
    if (gBattleMons[gBankTarget].hp <= gBattleMons[gBankAttacker].hp)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gBattleMoveDamage = gBattleMons[gBankTarget].hp - gBattleMons[gBankAttacker].hp;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkD9_scaledamagebyhealthratio(void)
{
    if (gDynamicBasePower == 0)
    {
        u8 power = gBattleMoves[gCurrentMove].power;
        gDynamicBasePower = gBattleMons[gBankAttacker].hp * power / gBattleMons[gBankAttacker].maxHP;
        if (gDynamicBasePower == 0)
            gDynamicBasePower = 1;
    }
    gBattlescriptCurrInstr++;
}

static void atkDA_tryswapabilities(void)
{
    if ((gBattleMons[gBankAttacker].ability == 0 && gBattleMons[gBankTarget].ability == 0)
     || gBattleMons[gBankAttacker].ability == ABILITY_WONDER_GUARD || gBattleMons[gBankTarget].ability == ABILITY_WONDER_GUARD
     || gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    else
    {
        u8 atk_ability = gBattleMons[gBankAttacker].ability;
        gBattleMons[gBankAttacker].ability = gBattleMons[gBankTarget].ability;
        gBattleMons[gBankTarget].ability = atk_ability;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkDB_tryimprision(void)
{
    u8 r8 = 0;
    if ((gStatuses3[gBankAttacker] & STATUS3_IMPRISIONED))
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        u8 bank;
        PressurePPLoseOnUsingImprision(gBankAttacker);
        for (bank = 0; bank < gBattlersCount; bank++)
        {
            if (r8 != GetBattlerSide(bank))
            {
                int j;
                for (j = 0; j < 4; j++)
                {
                    int k;
                    for (k = 0; k < 4; k++)
                    {
                        if (gBattleMons[gBankAttacker].moves[j] == gBattleMons[bank].moves[k] && gBattleMons[gBankAttacker].moves[j])
                            break;
                    }
                    if (k != 4)
                        break;
                }
                if (j != 4)
                {
                    gStatuses3[gBankAttacker] |= STATUS3_IMPRISIONED;
                    gBattlescriptCurrInstr += 5;
                    break;
                }
            }
        }
        if (bank == gBattlersCount)
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkDC_trysetgrudge(void)
{
    if (gStatuses3[gBankAttacker] & STATUS3_GRUDGE)
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    else
    {
        gStatuses3[gBankAttacker] |= STATUS3_GRUDGE;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkDD_weightdamagecalculation(void)
{
    // Now unused.
    gBattlescriptCurrInstr++;
}

#ifdef NONMATCHING
static void atkDE_asistattackselect(void)
{
    u32 chooseable_moves_no = 0;
    struct Pokemon* party;
    int i, j;
    u16* chooseable_moves;
    if (GetBattlerPosition(gBankAttacker) & 1)
        party = gEnemyParty;
    else
        party = gPlayerParty;

    for (i = 0; i < 6; i++)
    {
        if (i == gBattlerPartyIndexes[gBankAttacker])
            break;
        if (!GetMonData(&party[i], MON_DATA_SPECIES2) || GetMonData(&party[i], MON_DATA_SPECIES2) == SPECIES_EGG)
            break;
        chooseable_moves = &gBattleStruct->assistMove[chooseable_moves_no];
        for (j = 0; j < 4; j++)
        {
            int k;
            u16 move = GetMonData(&party[i], MON_DATA_MOVE1 + i);
            if (IsMoveUnchoosable(move))
                break;
            //sMovesForbiddenToCopy[k]
            for (k = 0; ;k++)
            {
                if (sMovesForbiddenToCopy[k] == 0xFFFF)
                {
                    if (move)
                    {
                        *chooseable_moves = move;
                        chooseable_moves++;
                        chooseable_moves_no++;
                    }
                    break;
                }
                if (sMovesForbiddenToCopy[k] == move)
                    break;
            }
        }
    }
    if (chooseable_moves_no)
    {
        gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
        gRandomMove = gBattleStruct->assistMove[Random() % chooseable_moves_no];
        gBankTarget = GetMoveTarget(gRandomMove, 0);
        gBattlescriptCurrInstr += 5;
    }
    else
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
}

#else
NAKED
static void atkDE_asistattackselect(void)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x8\n\
    movs r0, 0\n\
    mov r10, r0\n\
    ldr r0, _0802AB9C @ =gBankAttacker\n\
    ldrb r0, [r0]\n\
    bl GetBattlerPosition\n\
    movs r1, 0x1\n\
    ands r1, r0\n\
    ldr r0, _0802ABA0 @ =gPlayerParty\n\
    str r0, [sp]\n\
    cmp r1, 0\n\
    beq _0802AAAC\n\
    ldr r1, _0802ABA4 @ =gEnemyParty\n\
    str r1, [sp]\n\
_0802AAAC:\n\
    movs r2, 0\n\
_0802AAAE:\n\
    ldr r1, _0802ABA8 @ =gBattlerPartyIndexes\n\
    ldr r0, _0802AB9C @ =gBankAttacker\n\
    ldrb r0, [r0]\n\
    lsls r0, 1\n\
    adds r0, r1\n\
    adds r1, r2, 0x1\n\
    str r1, [sp, 0x4]\n\
    ldrh r0, [r0]\n\
    cmp r2, r0\n\
    beq _0802AB54\n\
    movs r0, 0x64\n\
    adds r6, r2, 0\n\
    muls r6, r0\n\
    ldr r0, [sp]\n\
    adds r4, r0, r6\n\
    adds r0, r4, 0\n\
    movs r1, 0x41\n\
    bl GetMonData\n\
    cmp r0, 0\n\
    beq _0802AB54\n\
    adds r0, r4, 0\n\
    movs r1, 0x41\n\
    bl GetMonData\n\
    movs r1, 0xCE\n\
    lsls r1, 1\n\
    cmp r0, r1\n\
    beq _0802AB54\n\
    movs r5, 0\n\
    ldr r1, _0802ABAC @ =0x0000ffff\n\
    mov r8, r1\n\
    mov r9, r6\n\
    mov r1, r10\n\
    lsls r0, r1, 1\n\
    ldr r1, _0802ABB0 @ =gSharedMem + 0x16024\n\
    adds r6, r0, r1\n\
_0802AAF8:\n\
    movs r7, 0\n\
    adds r1, r5, 0\n\
    adds r1, 0xD\n\
    ldr r0, [sp]\n\
    add r0, r9\n\
    bl GetMonData\n\
    lsls r0, 16\n\
    lsrs r4, r0, 16\n\
    adds r0, r4, 0\n\
    bl IsMoveUnchoosable\n\
    lsls r0, 24\n\
    adds r1, r5, 0x1\n\
    cmp r0, 0\n\
    bne _0802AB4E\n\
    ldr r0, _0802ABB4 @ =sMovesForbiddenToCopy\n\
    ldrh r2, [r0]\n\
    adds r3, r0, 0\n\
    cmp r2, r8\n\
    beq _0802AB42\n\
    cmp r4, r2\n\
    beq _0802AB38\n\
    ldr r5, _0802ABAC @ =0x0000ffff\n\
    adds r2, r3, 0\n\
_0802AB2A:\n\
    adds r2, 0x2\n\
    adds r7, 0x1\n\
    ldrh r0, [r2]\n\
    cmp r0, r5\n\
    beq _0802AB42\n\
    cmp r4, r0\n\
    bne _0802AB2A\n\
_0802AB38:\n\
    lsls r0, r7, 1\n\
    adds r0, r3\n\
    ldrh r0, [r0]\n\
    cmp r0, r8\n\
    bne _0802AB4E\n\
_0802AB42:\n\
    cmp r4, 0\n\
    beq _0802AB4E\n\
    strh r4, [r6]\n\
    adds r6, 0x2\n\
    movs r0, 0x1\n\
    add r10, r0\n\
_0802AB4E:\n\
    adds r5, r1, 0\n\
    cmp r5, 0x3\n\
    ble _0802AAF8\n\
_0802AB54:\n\
    ldr r2, [sp, 0x4]\n\
    cmp r2, 0x5\n\
    ble _0802AAAE\n\
    mov r1, r10\n\
    cmp r1, 0\n\
    beq _0802ABCC\n\
    ldr r2, _0802ABB8 @ =gHitMarker\n\
    ldr r0, [r2]\n\
    ldr r1, _0802ABBC @ =0xfffffbff\n\
    ands r0, r1\n\
    str r0, [r2]\n\
    ldr r4, _0802ABC0 @ =gRandomMove\n\
    bl Random\n\
    movs r1, 0xFF\n\
    ands r1, r0\n\
    mov r0, r10\n\
    muls r0, r1\n\
    asrs r0, 8\n\
    lsls r0, 1\n\
    ldr r1, _0802ABB0 @ =gSharedMem + 0x16024\n\
    adds r0, r1\n\
    ldrh r0, [r0]\n\
    strh r0, [r4]\n\
    ldrh r0, [r4]\n\
    movs r1, 0\n\
    bl GetMoveTarget\n\
    ldr r1, _0802ABC4 @ =gBankTarget\n\
    strb r0, [r1]\n\
    ldr r1, _0802ABC8 @ =gBattlescriptCurrInstr\n\
    ldr r0, [r1]\n\
    adds r0, 0x5\n\
    str r0, [r1]\n\
    b _0802ABE6\n\
    .align 2, 0\n\
_0802AB9C: .4byte gBankAttacker\n\
_0802ABA0: .4byte gPlayerParty\n\
_0802ABA4: .4byte gEnemyParty\n\
_0802ABA8: .4byte gBattlerPartyIndexes\n\
_0802ABAC: .4byte 0x0000ffff\n\
_0802ABB0: .4byte gSharedMem + 0x16024\n\
_0802ABB4: .4byte sMovesForbiddenToCopy\n\
_0802ABB8: .4byte gHitMarker\n\
_0802ABBC: .4byte 0xfffffbff\n\
_0802ABC0: .4byte gRandomMove\n\
_0802ABC4: .4byte gBankTarget\n\
_0802ABC8: .4byte gBattlescriptCurrInstr\n\
_0802ABCC:\n\
    ldr r3, _0802ABF8 @ =gBattlescriptCurrInstr\n\
    ldr r2, [r3]\n\
    ldrb r1, [r2, 0x1]\n\
    ldrb r0, [r2, 0x2]\n\
    lsls r0, 8\n\
    orrs r1, r0\n\
    ldrb r0, [r2, 0x3]\n\
    lsls r0, 16\n\
    orrs r1, r0\n\
    ldrb r0, [r2, 0x4]\n\
    lsls r0, 24\n\
    orrs r1, r0\n\
    str r1, [r3]\n\
_0802ABE6:\n\
    add sp, 0x8\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .align 2, 0\n\
_0802ABF8: .4byte gBattlescriptCurrInstr\n\
        .syntax divided");
}

#endif // NONMATCHING

static void atkDF_trysetmagiccoat(void)
{
    gBankTarget = gBankAttacker;
    gSpecialStatuses[gBankAttacker].flag20 = 1;
    if (gCurrentTurnActionNumber == gBattlersCount - 1) //last turn
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    else
    {
        gProtectStructs[gBankAttacker].bounceMove = 1;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkE0_trysetsnatch(void)
{
    gSpecialStatuses[gBankAttacker].flag20 = 1;
    if (gCurrentTurnActionNumber == gBattlersCount - 1) //last turn
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    else
    {
        gProtectStructs[gBankAttacker].stealMove = 1;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkE1_trygetintimidatetarget(void)
{
    u8 side;

    gBattleStruct->scriptingActive = ewram160DD;
    side = GetBattlerSide(gBattleStruct->scriptingActive);
    gBattleTextBuff1[0] = 0xFD;
    gBattleTextBuff1[1] = 9;
    gBattleTextBuff1[2] = gBattleMons[gBattleStruct->scriptingActive].ability;
    gBattleTextBuff1[3] = 0xFF;

    for (;gBankTarget < gBattlersCount; gBankTarget++)
    {
        if (GetBattlerSide(gBankTarget) == side)
            continue;
        if (!(gAbsentBattlerFlags & gBitTable[gBankTarget]))
            break;
    }

    if (gBankTarget >= gBattlersCount)
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    else
        gBattlescriptCurrInstr += 5;
}

static void atkE2_switchoutabilities(void)
{
    gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
    switch (gBattleMons[gActiveBattler].ability)
    {
    case ABILITY_NATURAL_CURE:
        gBattleMons[gActiveBattler].status1 = 0;
        EmitSetMonData(0, REQUEST_STATUS_BATTLE, gBitTable[ewram16064arr(gActiveBattler)], 4, &gBattleMons[gActiveBattler].status1);
        MarkBufferBankForExecution(gActiveBattler);
        break;
	case ABILITY_REGENERATOR:
        gBattleMons[gActiveBattler].hp += gBattleMons[gActiveBattler].maxHP / 3;
        if (gBattleMons[gActiveBattler].hp > gBattleMons[gActiveBattler].maxHP)
            gBattleMons[gActiveBattler].hp = gBattleMons[gActiveBattler].maxHP;
        EmitSetMonData(0, REQUEST_HP_BATTLE, 0, 2, &gBattleMons[gActiveBattler].hp);
        MarkBufferBankForExecution(gActiveBattler);
        break;
    }
    gBattlescriptCurrInstr += 2;
}

static void atkE3_jumpifhasnohp(void)
{
    gActiveBattler = GetBattleBank(T2_READ_8(gBattlescriptCurrInstr + 1));
    if (gBattleMons[gActiveBattler].hp == 0)
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 2);
    else
        gBattlescriptCurrInstr += 6;
}

static void atkE4_getsecretpowereffect(void)
{
    switch (gBattleTerrain)
    {
    case BATTLE_TERRAIN_GRASS:
        gBattleCommunication[MOVE_EFFECT_BYTE] = 2;
        break;
    case BATTLE_TERRAIN_LONG_GRASS:
        gBattleCommunication[MOVE_EFFECT_BYTE] = 1;
        break;
    case BATTLE_TERRAIN_SAND:
        gBattleCommunication[MOVE_EFFECT_BYTE] = 27;
        break;
    case BATTLE_TERRAIN_UNDERWATER:
        gBattleCommunication[MOVE_EFFECT_BYTE] = 23;
        break;
    case BATTLE_TERRAIN_WATER:
        gBattleCommunication[MOVE_EFFECT_BYTE] = 22;
        break;
    case BATTLE_TERRAIN_POND:
        gBattleCommunication[MOVE_EFFECT_BYTE] = 24;
        break;
    case BATTLE_TERRAIN_MOUNTAIN:
        gBattleCommunication[MOVE_EFFECT_BYTE] = 7;
        break;
    case BATTLE_TERRAIN_CAVE:
        gBattleCommunication[MOVE_EFFECT_BYTE] = 8;
        break;
    default:
        gBattleCommunication[MOVE_EFFECT_BYTE] = 5;
        break;
    }
    gBattlescriptCurrInstr++;
}

static void atkE5_pickup(void)
{
    int i;
    for (i = 0; i < 6; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);
        u16 held_item = GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM);
		u8 level = (GetMonData(&gPlayerParty[i], MON_DATA_LEVEL) - 1) / 10;
        u8 ability = GetMonAbility(&gPlayerParty[i]);

        if (ability == ABILITY_PICKUP && species != 0 && species != SPECIES_EGG && held_item == 0 && (Random() % 10) == 0)
        {
            s32 chance = Random() % 100;
            s32 j;
            for (j = 0; j < 18; j += 2)
            {
                if (sPickupTables[level][j + 1] > chance)
                    break;
            }
            SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, (const void*) &((sPickupTables[level])[j]));
        }
        else if (ability == ABILITY_HONEY_GATHER && species != 0 && species != SPECIES_EGG && held_item == 0)
        {
            u16 item = ITEM_HONEY;
            u8 chance = 5 * ((level+9)/10);
            if (Random() % 100 < chance)
            {
                SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &item);
            }
        }
    }
    gBattlescriptCurrInstr++;
}

static void atkE6_docastformchangeanimation(void)
{
    gActiveBattler = gBattleStruct->scriptingActive;
    if (gBattleMons[gActiveBattler].status2 & STATUS2_SUBSTITUTE)
        gBattleStruct->castformToChangeInto |= 0x80;
    EmitBattleAnimation(0, B_ANIM_CASTFORM_CHANGE, gBattleStruct->castformToChangeInto);
    MarkBufferBankForExecution(gActiveBattler);
    gBattlescriptCurrInstr++;
}

static void atkE7_trycastformdatachange(void)
{
    u8 form;
    gBattlescriptCurrInstr++;
    form = CastformDataTypeChange(gBattleStruct->scriptingActive);
    if (form)
    {
        BattleScriptPushCursorAndCallback(BattleScript_CastformChange);
        gBattleStruct->castformToChangeInto = form - 1;
    }
}

static void atkE8_settypebasedhalvers(void) //water/mud sport
{
    bool8 worked = FALSE;
    if (gBattleMoves[gCurrentMove].effect == EFFECT_MUD_SPORT)
    {
        if (!(gStatuses3[gBankAttacker] & STATUS3_MUDSPORT))
        {
            gStatuses3[gBankAttacker] |= STATUS3_MUDSPORT;
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            worked = TRUE;
        }
    }
    else //water sport
    {
        if (!(gStatuses3[gBankAttacker] & STATUS3_WATERSPORT))
        {
            gStatuses3[gBankAttacker] |= STATUS3_WATERSPORT;
            gBattleCommunication[MULTISTRING_CHOOSER] = 1;
            worked = TRUE;
        }
    }
    if (worked)
        gBattlescriptCurrInstr += 5;
    else
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
}

static void atkE9_setweatherballtype(void)
{
    if (WEATHER_HAS_EFFECT)
    {
        if ((u8)(gBattleWeather))
            gBattleStruct->dmgMultiplier = 2;
        if (gBattleWeather & WEATHER_RAIN_ANY)
            gBattleStruct->dynamicMoveType = TYPE_WATER | 0x80;
        else if (gBattleWeather & WEATHER_SANDSTORM_ANY)
            gBattleStruct->dynamicMoveType = TYPE_ROCK | 0x80;
        else if (gBattleWeather & WEATHER_SUN_ANY)
            gBattleStruct->dynamicMoveType = TYPE_FIRE | 0x80;
        else if (gBattleWeather & WEATHER_HAIL)
            gBattleStruct->dynamicMoveType = TYPE_ICE | 0x80;
        else
            gBattleStruct->dynamicMoveType = TYPE_NORMAL | 0x80;
    }
    gBattlescriptCurrInstr++;
}

static void atkEA_tryrecycleitem(void)
{
    u16* used_item;
    gActiveBattler = gBankAttacker;
    used_item = USED_HELD_ITEM(gActiveBattler);
    if (*used_item && gBattleMons[gActiveBattler].item == 0)
    {
        gLastUsedItem = *used_item;
        *used_item = 0;
        gBattleMons[gActiveBattler].item = gLastUsedItem;
        EmitSetMonData(0, REQUEST_HELDITEM_BATTLE, 0, 2, &gBattleMons[gActiveBattler].item);
        MarkBufferBankForExecution(gActiveBattler);
        gBattlescriptCurrInstr += 5;
    }
    else
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
}

static void atkEB_settypetoterrain(void)
{
    if (gBattleMons[gBankAttacker].type1 != sTerrainToType[gBattleTerrain] && gBattleMons[gBankAttacker].type2 != sTerrainToType[gBattleTerrain])
    {
        gBattleMons[gBankAttacker].type1 = sTerrainToType[gBattleTerrain];
        gBattleMons[gBankAttacker].type2 = sTerrainToType[gBattleTerrain];
        gBattleTextBuff1[0] = 0xFD;
        gBattleTextBuff1[1] = 3;
        gBattleTextBuff1[2] = sTerrainToType[gBattleTerrain];
        gBattleTextBuff1[3] = 0xFF;
        gBattlescriptCurrInstr += 5;
    }
    else
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
}

static void atkEC_pursuitrelated(void)
{
    gActiveBattler = GetBattlerAtPosition(GetBattlerPosition(gBankAttacker) ^ 2);
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && !(gAbsentBattlerFlags & gBitTable[gActiveBattler]) && gActionForBanks[gActiveBattler] == 0 && gChosenMovesByBanks[gActiveBattler] == MOVE_PURSUIT)
    {
        gActionsByTurnOrder[gActiveBattler] = 11;
        gCurrentMove = MOVE_PURSUIT;
        gBattlescriptCurrInstr += 5;
        gBattleStruct->animTurn = 1;
        gBattleStruct->unk160A7 = gBankAttacker;
        gBankAttacker = gActiveBattler;
    }
    else
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
}

static void atkED_snatchsetbanks(void)
{
    gEffectBank = gBankAttacker;
    if (gBankAttacker == gBankTarget)
        gBankAttacker = gBankTarget = gBattleStruct->scriptingActive;
    else
        gBankTarget = gBattleStruct->scriptingActive;
    gBattleStruct->scriptingActive = gEffectBank;
    gBattlescriptCurrInstr++;
}

static void atkEE_removelightscreenreflect(void) //brick break
{
    u8 side = GetBattlerSide(gBankTarget);
    if (gSideTimers[side].reflectTimer || gSideTimers[side].lightscreenTimer)
    {
        gSideAffecting[side] &= ~(SIDE_STATUS_REFLECT);
        gSideAffecting[side] &= ~(SIDE_STATUS_LIGHTSCREEN);
        gSideTimers[side].reflectTimer = 0;
        gSideTimers[side].lightscreenTimer = 0;
        gBattleStruct->animTurn = 1;
        gBattleStruct->animTargetsHit = 1;
    }
    else
    {
        gBattleStruct->animTurn = 0;
        gBattleStruct->animTargetsHit = 0;
    }
    gBattlescriptCurrInstr++;
}

static const u16 sMoonBallMons[] = 
{
    SPECIES_NIDORAN_F,
    SPECIES_NIDORINA,
    SPECIES_NIDOQUEEN,
    SPECIES_NIDORAN_M,
    SPECIES_NIDORINO,
    SPECIES_NIDOKING,
    SPECIES_CLEFFA,
    SPECIES_CLEFAIRY,
    SPECIES_CLEFABLE,
    SPECIES_IGGLYBUFF,
    SPECIES_JIGGLYPUFF,
    SPECIES_WIGGLYTUFF,
    SPECIES_SKITTY,
    SPECIES_DELCATTY,
    0,
};

void atkEF_handleballthrow(void)
{
    u8 ball_multiplier = 0;
    u8 index = 0;
    struct Pokemon *attacker, *target;
    u16 atk_species, def_species, target_wt;
    u32 atk_pid, def_pid;
    if (gBattleExecBuffer)
        return;

    gActiveBattler = gBankAttacker;
    gBankTarget = gBankAttacker ^ 1;
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        EmitBallThrow(0, 5);
        MarkBufferBankForExecution(gActiveBattler);
        gBattlescriptCurrInstr = BattleScript_TrainerBallBlock;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
    {
        EmitBallThrow(0, 4);
        MarkBufferBankForExecution(gActiveBattler);
        gBattlescriptCurrInstr = BattleScript_WallyBallThrow;
    }
    else
    {
        u32 odds;
        u8 catch_rate;
        if (gLastUsedItem == ITEM_SAFARI_BALL)
            catch_rate = gBattleStruct->unk16089 * 1275 / 100; //correct the name to safariFleeRate
        else
            catch_rate = gBaseStats[gBattleMons[gBankTarget].species].catchRate;
        if (gLastUsedItem > 5)
        {
            switch (gLastUsedItem)
            {
            case ITEM_NET_BALL:
                if (gBattleMons[gBankTarget].type1 == TYPE_WATER || gBattleMons[gBankTarget].type2 == TYPE_WATER || gBattleMons[gBankTarget].type1 == TYPE_BUG || gBattleMons[gBankTarget].type2 == TYPE_BUG)
                    ball_multiplier = 30;
                else
                    ball_multiplier = 10;
                break;
            case ITEM_DIVE_BALL:
                if (Overworld_GetMapTypeOfSaveblockLocation() == 5)
                    ball_multiplier = 35;
                else
                    ball_multiplier = 10;
                break;
            case ITEM_NEST_BALL:
                if (gBattleMons[gBankTarget].level <= 39)
                {
                    ball_multiplier = 40 - gBattleMons[gBankTarget].level;
                    if (ball_multiplier <= 9)
                        ball_multiplier = 10;
                }
                else
                    ball_multiplier = 10;
                break;
            case ITEM_REPEAT_BALL:
                if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[gBankTarget].species), 1))
                    ball_multiplier = 30;
                else
                    ball_multiplier = 10;
                break;
            case ITEM_TIMER_BALL:
                ball_multiplier = gBattleResults.battleTurnCounter + 10;
                if (ball_multiplier > 40)
                    ball_multiplier = 40;
                break;
            case ITEM_LUXURY_BALL:
            case ITEM_PREMIER_BALL:
            case ITEM_FRIEND_BALL:
            case ITEM_HEAL_BALL:
            case ITEM_CHERISH_BALL:
                ball_multiplier = 10;
                break;
            case ITEM_LEVEL_BALL:
                if (gBattleMons[gBankTarget].level >= gBattleMons[gActiveBattler].level)
                    ball_multiplier = 10;
                else if (gBattleMons[gBankTarget].level * 2 > gBattleMons[gActiveBattler].level)
                    ball_multiplier = 20;
                else if (gBattleMons[gBankTarget].level * 4 > gBattleMons[gActiveBattler].level)
                    ball_multiplier = 40;
                else
                    ball_multiplier = 80;
                break;
            case ITEM_LURE_BALL:
                if (gBattleTypeFlags & BATTLE_TYPE_FISH)
                    ball_multiplier = 30;
                else
                    ball_multiplier = 10;
                break;
            case ITEM_MOON_BALL:
                ball_multiplier = 10;
                while (sMoonBallMons[index])
                {
                    if (sMoonBallMons[index] == gBattleMons[gBankTarget].species)
                    {
                        ball_multiplier = 40;
                        break;
                    }
                    index++;
                }
                break;
            case ITEM_LOVE_BALL:
                if (!GetBattlerSide(gBankAttacker))
                    attacker = &gPlayerParty[gBattlerPartyIndexes[gBankAttacker]];
                else
                    attacker = &gEnemyParty[gBattlerPartyIndexes[gBankAttacker]];

                if (!GetBattlerSide(gBankTarget))
                    target = &gPlayerParty[gBattlerPartyIndexes[gBankTarget]];
                else
                    target = &gEnemyParty[gBattlerPartyIndexes[gBankTarget]];

                atk_species = GetMonData(attacker, MON_DATA_SPECIES);
                atk_pid = GetMonData(attacker, MON_DATA_PERSONALITY);

                def_species = GetMonData(target, MON_DATA_SPECIES);
                def_pid = GetMonData(target, MON_DATA_PERSONALITY);

                if (gBattleMons[gBankTarget].species == gBattleMons[gActiveBattler].species &&
                    GetGenderFromSpeciesAndPersonality(atk_species, atk_pid) != GetGenderFromSpeciesAndPersonality(def_species, def_pid) &&
                    GetGenderFromSpeciesAndPersonality(atk_species, atk_pid) == 0xFF &&
                    GetGenderFromSpeciesAndPersonality(def_species, def_pid) == 0xFF)
                    ball_multiplier = 80;
                else
                    ball_multiplier = 10;
                break;
            case ITEM_HEAVY_BALL:
                target_wt = GetPokedexHeightWeight(SpeciesToNationalPokedexNum(gBattleMons[gBankTarget].species), 1);
                if (target_wt < 1000)
                {
                    if (catch_rate <= 20)
                        catch_rate = 1;
                    else
                        catch_rate -= 20;
                }
                else if (target_wt < 2000)
                    ; // do nothing
                else if (target_wt < 3000)
                {
                    if (catch_rate > 235)
                        catch_rate = 255;
                    else
                        catch_rate += 20;
                }
                else
                {
                    if (catch_rate > 225)
                        catch_rate = 255;
                    else
                        catch_rate += 30;
                }
                ball_multiplier = 10;
                break;
            case ITEM_FAST_BALL:
                if (gBaseStats[gBattleMons[gBankTarget].species].baseSpeed >= 100)
                    ball_multiplier = 40;
                else
                    ball_multiplier = 10;
                break;
            case ITEM_QUICK_BALL:
                if (gBattleResults.battleTurnCounter)
                    ball_multiplier = 10;
                else
                    ball_multiplier = 50;
                break;
            case ITEM_DUSK_BALL:
                if (Overworld_GetMapTypeOfSaveblockLocation() == 4)
                    ball_multiplier = 35;
                else
                    ball_multiplier = 10;
                break;
            case ITEM_AQUA_BALL:
                if (WEATHER_HAS_EFFECT && (gBattleWeather & WEATHER_RAIN_ANY))
                    ball_multiplier = 30;
                else
                    ball_multiplier = 7;
                break;
            case ITEM_MAGMA_BALL:
                if (WEATHER_HAS_EFFECT && (gBattleWeather & WEATHER_SUN_ANY))
                    ball_multiplier = 30;
                else
                    ball_multiplier = 7;
                break;
                
            }
        }
        else
            ball_multiplier = sBallCatchBonuses[gLastUsedItem - 2];

        odds = (catch_rate * ball_multiplier / 10) * (gBattleMons[gBankTarget].maxHP * 3 - gBattleMons[gBankTarget].hp * 2) / (3 * gBattleMons[gBankTarget].maxHP);
        if (gBattleMons[gBankTarget].status1 & (STATUS_SLEEP | STATUS_FREEZE))
            odds *= 2;
        if (gBattleMons[gBankTarget].status1 & (STATUS_POISON | STATUS_BURN | STATUS_PARALYSIS | STATUS_TOXIC_POISON ))
            odds = (odds * 15) / 10;

        if (gLastUsedItem != ITEM_SAFARI_BALL)
        {
            if (gLastUsedItem == ITEM_MASTER_BALL)
            {
                gBattleResults.unk5_1 = 1;
            }
            else
            {
                if (gBattleResults.usedBalls[gLastUsedItem - ITEM_ULTRA_BALL] < 0xFF)
                    gBattleResults.usedBalls[gLastUsedItem - ITEM_ULTRA_BALL]++;
            }
        }
        if (odds > 254) //poke caught
        {
            EmitBallThrow(0, 4);
            MarkBufferBankForExecution(gActiveBattler);
            gBattlescriptCurrInstr = BattleScript_SuccessBallThrow;
            SetMonData(&gEnemyParty[gBattlerPartyIndexes[gBankTarget]], MON_DATA_POKEBALL, (const void*) &gLastUsedItem);
            if (CalculatePlayerPartyCount() == 6)
                gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            else
                gBattleCommunication[MULTISTRING_CHOOSER] = 1;
        }
        else //poke may be caught, calculate shakes
        {
            u8 shakes;
            odds = Sqrt(Sqrt(16711680 / odds));
            odds = 1048560 / odds;
            for (shakes = 0; shakes < 4 && Random() < odds; shakes++) {}
            if (gLastUsedItem == ITEM_MASTER_BALL)
                shakes = 4; //why calculate the shakes before that check?
            EmitBallThrow(0, shakes);
            MarkBufferBankForExecution(gActiveBattler);
            if (shakes == 4) //poke caught, copy of the code above
            {
                gBattlescriptCurrInstr = BattleScript_SuccessBallThrow;
                SetMonData(&gEnemyParty[gBattlerPartyIndexes[gBankTarget]], MON_DATA_POKEBALL, (const void*) &gLastUsedItem);
                if (CalculatePlayerPartyCount() == 6)
                    gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                else
                    gBattleCommunication[MULTISTRING_CHOOSER] = 1;
            }
            else //rip
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = shakes;
                gBattlescriptCurrInstr = BattleScript_ShakeBallThrow;
            }
        }
    }
}

static void atkF0_givecaughtmon(void)
{
    u8 i;
    u16 maxHP;
    u8 ppBonuses;
    u8 arg[4];
    struct Pokemon* mon;

    mon = &gEnemyParty[gBattlerPartyIndexes[gBankAttacker ^ 1]];
    if (GetMonData(mon, MON_DATA_POKEBALL) == ITEM_HEAL_BALL)
    {
        // should really make a heal-one-mon function instead of cribbing like this, o well
        maxHP = GetMonData(mon, MON_DATA_MAX_HP);
        arg[0] = maxHP;
        arg[1] = maxHP >> 8;
        SetMonData(mon, MON_DATA_HP, arg);
        ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);

        // restore PP.
        for(i = 0; i < 4; i++)
        {
            arg[0] = CalculatePPWithBonus(GetMonData(mon, MON_DATA_MOVE1 + i), ppBonuses, i);
            SetMonData(mon, MON_DATA_PP1 + i, arg);
        }

        arg[0] = 0;
        arg[1] = 0;
        arg[2] = 0;
        arg[3] = 0;
        SetMonData(mon, MON_DATA_STATUS, arg);
    }
    else if (GetMonData(mon, MON_DATA_POKEBALL) == ITEM_FRIEND_BALL)
    {
        arg[0] = 200;
        SetMonData(mon, MON_DATA_FRIENDSHIP, arg);
    }
    GiveMonToPlayer(&gEnemyParty[gBattlerPartyIndexes[gBankAttacker ^ 1]]);
    gBattleResults.caughtPoke = gBattleMons[gBankAttacker ^ 1].species;
    GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBankAttacker ^ 1]], MON_DATA_NICKNAME, gBattleResults.caughtNick);
    gBattlescriptCurrInstr++;
}

static void atkF1_trysetcaughtmondexflags(void)
{
    if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[gBankTarget].species), 1))
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    else
    {
        GetSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[gBankTarget].species), 3);
        if (gBattleMons[gBankTarget].species == SPECIES_UNOWN)
            gSaveBlock2.pokedex.unownPersonality = gBattleMons[gBankTarget].personality;
        if (gBattleMons[gBankTarget].species == SPECIES_SPINDA) //else if
            gSaveBlock2.pokedex.spindaPersonality = gBattleMons[gBankTarget].personality;
        gBattlescriptCurrInstr += 5;
    }
}

extern const u32 gBattleTerrainTiles_Building[];
extern const u32 gBattleTerrainTilemap_Building[];
extern const u32 gBattleTerrainPalette_BattleTower[];

static void atkF2_displaydexinfo(void)
{
    switch (gBattleCommunication[0])
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB(0, 0, 0));
        gBattleCommunication[0]++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            gBattleCommunication[1] = sub_809070C(SpeciesToNationalPokedexNum(gBattleMons[gBankTarget].species), gBattleMons[gBankTarget].otId, gBattleMons[gBankTarget].personality);
            gBattleCommunication[0]++;
        }
        break;
    case 2:
        if (!gPaletteFade.active && gMain.callback2 == BattleMainCB2 && !gTasks[gBattleCommunication[1]].isActive)
        {
            LZDecompressVram(gBattleTerrainTiles_Building, (void*)(0x06008000));
            LZDecompressVram(gBattleTerrainTilemap_Building, (void*)(0x0600d000));
            LoadCompressedPalette(gBattleTerrainPalette_BattleTower, 0x20, 0x60);
            REG_BG3CNT = 0x5a0b;
            gBattle_BG3_X = 0x100;
            BeginNormalPaletteFade(0xFFFC, 0, 16, 0, RGB(0, 0, 0));
            gBattleCommunication[0]++;
        }
        break;
    case 3:
        if (!gPaletteFade.active)
            gBattlescriptCurrInstr++;
        break;
    }
}

NAKED
void sub_802BBD4(u8 r0, u8 r1, u8 r2, u8 r3, u8 sp0)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    ldr r4, [sp, 0x20]\n\
    lsls r0, 24\n\
    lsrs r6, r0, 24\n\
    lsls r1, 24\n\
    lsrs r1, 24\n\
    mov r12, r1\n\
    lsls r2, 24\n\
    lsrs r5, r2, 24\n\
    lsls r3, 24\n\
    lsrs r7, r3, 24\n\
    lsls r4, 24\n\
    lsrs r4, 24\n\
    mov r8, r4\n\
    mov r2, r12\n\
    cmp r2, r7\n\
    bgt _0802BC5A\n\
    lsls r1, r6, 1\n\
    ldr r0, _0802BC20 @ =0x0600c000\n\
    adds r1, r0\n\
    mov r9, r1\n\
_0802BC06:\n\
    adds r1, r6, 0\n\
    adds r0, r2, 0x1\n\
    mov r10, r0\n\
    cmp r1, r5\n\
    bgt _0802BC54\n\
    lsls r0, r2, 6\n\
    mov r4, r9\n\
    adds r3, r4, r0\n\
_0802BC16:\n\
    cmp r2, r12\n\
    bne _0802BC28\n\
    ldr r0, _0802BC24 @ =0x00001022\n\
    b _0802BC36\n\
    .align 2, 0\n\
_0802BC20: .4byte 0x0600c000\n\
_0802BC24: .4byte 0x00001022\n\
_0802BC28:\n\
    cmp r2, r7\n\
    bne _0802BC34\n\
    ldr r0, _0802BC30 @ =0x00001028\n\
    b _0802BC36\n\
    .align 2, 0\n\
_0802BC30: .4byte 0x00001028\n\
_0802BC34:\n\
    ldr r0, _0802BC68 @ =0x00001025\n\
_0802BC36:\n\
    cmp r1, r6\n\
    beq _0802BC42\n\
    adds r0, 0x1\n\
    cmp r1, r5\n\
    bne _0802BC42\n\
    adds r0, 0x1\n\
_0802BC42:\n\
    mov r4, r8\n\
    cmp r4, 0\n\
    beq _0802BC4A\n\
    movs r0, 0\n\
_0802BC4A:\n\
    strh r0, [r3]\n\
    adds r3, 0x2\n\
    adds r1, 0x1\n\
    cmp r1, r5\n\
    ble _0802BC16\n\
_0802BC54:\n\
    mov r2, r10\n\
    cmp r2, r7\n\
    ble _0802BC06\n\
_0802BC5A:\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .align 2, 0\n\
_0802BC68: .4byte 0x00001025\n\
        .syntax divided");
}

void sub_802BC6C(void)
{
    MenuCursor_SetPos814A880(0xC8, ((gBattleCommunication[1] << 28) + 1207959552) >> 24); //what could that be?
}

void nullsub_6(void)
{
    return;
}

static void atkF3_trygivecaughtmonnick(void)
{
    switch (gBattleCommunication[0])
    {
    case 0:
        sub_8023A80();
        gBattleCommunication[0]++;
        gBattleCommunication[1] = 0;
        sub_802BC6C();
        break;
    case 1:
        if (gMain.newKeys & DPAD_UP && gBattleCommunication[1] != 0)
        {
            PlaySE(SE_SELECT);
            nullsub_6();
            gBattleCommunication[1] = 0;
            sub_802BC6C();
        }
        if (gMain.newKeys & DPAD_DOWN && gBattleCommunication[1] == 0)
        {
            PlaySE(SE_SELECT);
            nullsub_6();
            gBattleCommunication[1] = 1;
            sub_802BC6C();
        }
        if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            if (gBattleCommunication[1] == 0)
            {
                gBattleCommunication[0]++;
                BeginFastPaletteFade(3);
            }
            else
                gBattleCommunication[0] = 4;
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            gBattleCommunication[0] = 4;
        }
        break;
    case 2:
        if (!gPaletteFade.active)
        {
            GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBankAttacker ^ 1]], MON_DATA_NICKNAME, gBattleStruct->caughtNick);
            DoNamingScreen(2, gBattleStruct->caughtNick, GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBankAttacker ^ 1]], MON_DATA_SPECIES), GetMonGender(&gEnemyParty[gBattlerPartyIndexes[gBankAttacker ^ 1]]), GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBankAttacker ^ 1]], MON_DATA_PERSONALITY, 0), BattleMainCB2);
            gBattleCommunication[0]++;
        }
        break;
    case 3:
        if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active )
        {
            SetMonData(&gEnemyParty[gBattlerPartyIndexes[gBankAttacker ^ 1]], MON_DATA_NICKNAME, gBattleStruct->caughtNick);
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
        }
        break;
    case 4:
        if (CalculatePlayerPartyCount() == 6)
            gBattlescriptCurrInstr += 5;
        else
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
        break;
    }
}

static void atkF4_subattackerhpbydmg(void)
{
    gBattleMons[gBankAttacker].hp -= gBattleMoveDamage;
    gBattlescriptCurrInstr++;
}

static void atkF5_removeattackerstatus1(void)
{
    gBattleMons[gBankAttacker].status1 = 0;
    gBattlescriptCurrInstr++;
}

static void atkF6_finishaction(void)
{
    gCurrentActionFuncId = 0xC;
}

static void atkF7_finishturn(void)
{
    gCurrentActionFuncId = 0xC;
    gCurrentTurnActionNumber = gBattlersCount;
}


void (* const gBattleScriptingSpecialTable[])(void) =
{
	sp00_suckerpunch,
	sp01_fling,
	sp02_flingloseitem,
	sp03_bugbite,
	sp04_naturalgift,
	sp05_defogreflect,
	sp06_defoglightscreen,
	sp07_defogsafeguard,
	sp08_defogmist,
	sp09_defogfoespikes,
	sp0A_defogownspikes,
	sp0B_roost,
	sp0C_payback,
	sp0D_tailwind,
	sp0E_luckychant,
	sp0F_storedpower,
	sp10_captivate,
	sp11_healingwish,
	sp12_spikesaffect,
	sp13_healingwishaffect,
	sp14_setstickyweb,
	sp15_webaffect,
	sp16_defogfoeweb,
	sp17_defogownweb,
	sp18_worryseed,
	sp19_punishment,
	sp1A_echoedvoice,
	sp1B_sleepremoval,
	sp1C_heavyslam,
	sp1D_aquaring,
	sp1E_soak,
	sp1F_setstealthrock,
	sp20_rocksaffect,
	sp21_defogfoerocks,
	sp22_defogownrocks,
	sp23_copycat,
	sp24_settoxicspikes,
	sp25_toxicspikesaffect,
	sp26_wringout,
	sp27_defogfoetoxicspikes,
	sp28_defogowntoxicspikes,
	sp29_reflecttype,
	sp2A_metalburst,
	sp2B_electroball,
	sp2C_entrainmentfailcheck,
	sp2D_trumpcard,
	sp2E_entrainmentapply,
	sp2F_incinerate,
	sp30_clearsmog,
	sp31_gyroball,
	sp32_feint,
	sp33_powertrick,
	sp34_powersplit,
	sp35_guardsplit,
	sp36_bpasspowertrick,
	sp37_spotlight,
	sp38_acupressure,
	sp39_frisk,
	sp3A_mefirst,
	sp3B_powerswap,
	sp3C_guardswap,
	sp3D_psychoshiftsleep,
	sp3E_uturncheck,
    sp3F_setauroraveil,
    sp40_settrickroom,
    sp41_checkdefiant,
    sp42_checkdefiantwebs,
    sp43_checkdefianttarget,
    sp44_preparecatchexp,
	sp45_fellstingercheck,
	sp46_finalgambit,
	sp47_burnup,
	sp48_lastresort,
    sp49_losemoney,
    sp4A_round,
    sp4B_jumpkickrecoil,
    sp4C_checkexplosiontargetvalidity,
    sp4D_endifnopowerherb,
    sp4E_demonbook,
    sp4F_forcewin,
    sp50_usegun,
    sp51_usexnihilo,
    sp52_usemaxrevive,
};


static void atkF8_special(void)
{
    u8 index = gBattlescriptCurrInstr[1];
    gBattlescriptCurrInstr += 2;
    gBattleScriptingSpecialTable[index]();
}

static void sp00_suckerpunch(void)
{
	u8 i = 0;
	u8 success = 1;
	
	// Sucker Punch only works if:
	// The target is using a move
	// The move the target is using is not status
	// The attacker goes before the target
	
	if (gActionsByTurnOrder[gBankTarget] != ACTION_USE_MOVE)
		success = 0;
	else if (!(gProtectStructs[gBankTarget].onlyStruggle) && 
			gBattleMoves[gBattleMons[gBankTarget].moves[ewram1608Carr(gBankTarget)]].moveClass == 2)
		success = 0;
	else
	{
		for (i = 0; i < 4; i++)
		{
			if (gBanksByTurnOrder[i] == gBankAttacker)
				break;
			if (gBanksByTurnOrder[i] == gBankTarget)
			{
				success = 0;
				break;
			}
		}
	}
	
	if (!success)
		gBattlescriptCurrInstr = BattleScript_ButItFailed;
}

static void sp01_fling(void)
{
	u16 itemthrown = gBattleMons[gBankAttacker].item;
	u8 failed = 0;
	
	if (gWishFutureKnock.knockedOffPokes[gBankAttacker])
		failed = 1;
	else
	{
		gLastUsedItem = itemthrown;
		gDynamicBasePower = ItemId_GetFlingPower(itemthrown);
		if (gDynamicBasePower == 0)
			failed = 1;
	}
	
	if (failed)
	{
		gBattlescriptCurrInstr = BattleScript_ButItFailed;
	}
}

static void sp02_flingloseitem(void)
{
	u16 itemthrown = gBattleMons[gBankAttacker].item;
	u8 i;
	
	if (itemthrown == ITEM_LIGHT_BALL) //paralyze
		gBattleCommunication[MOVE_EFFECT_BYTE] = 0x85;
	else if (itemthrown == ITEM_POISON_BARB)
		gBattleCommunication[MOVE_EFFECT_BYTE] = 0x82;
	else if (itemthrown == ITEM_KINGS_ROCK)
		gBattleCommunication[MOVE_EFFECT_BYTE] = 0x88;
	else if (itemthrown == ITEM_LIECHI_BERRY)
		gBattleCommunication[MOVE_EFFECT_BYTE] = 0x8F;
	else if (itemthrown == ITEM_GANLON_BERRY)
		gBattleCommunication[MOVE_EFFECT_BYTE] = 0x90;
	else if (itemthrown == ITEM_SALAC_BERRY)
		gBattleCommunication[MOVE_EFFECT_BYTE] = 0x91;
	else if (itemthrown == ITEM_PETAYA_BERRY)
		gBattleCommunication[MOVE_EFFECT_BYTE] = 0x92;
	else if (itemthrown == ITEM_APICOT_BERRY)
		gBattleCommunication[MOVE_EFFECT_BYTE] = 0x93;
	else if (itemthrown == ITEM_STARF_BERRY)
	{
		for (i = 0; i < 5; i++)
		{
			if (gBattleMons[gBankTarget].statStages[STAT_STAGE_ATK + i] < 0xC)
				break;
		}
		if (i != 5)
		{
            do
			{
				i = Random() % 5;
            } while (gBattleMons[gBankTarget].statStages[STAT_STAGE_ATK + i] == 0xC);
			gBattleCommunication[MOVE_EFFECT_BYTE] = 0xA7 + i;
		}
	}
	// TODO:
	// mental herb: cures mental state
	// white herb: raises negative stat mods to +0
	// cheri, chesto, pecha, rawst, aspear, persim, lum: cures status
	// leppa: restores 10 PP to a move
	// oran: restores 10 HP
	// sitrus: restores 30 HP
	// figy+clones: restores 50%, may confuse
	// lansat: raises crit rate
	
	
}

static void _bugBiteFigy(u8 flavor)
{
	gBattleTextBuff1[0] = 0xFD;
	gBattleTextBuff1[1] = 8;
	gBattleTextBuff1[2] = flavor;
	gBattleTextBuff1[3] = EOS;
	gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP / 2;
	if (gBattleMoveDamage == 0)
		gBattleMoveDamage = 1;
	if (gBattleMons[gBankAttacker].hp + gBattleMoveDamage > gBattleMons[gBankAttacker].maxHP)
		gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP - gBattleMons[gBankAttacker].hp;
	gBattleMoveDamage *= -1;
	if (GetPokeFlavourRelation(gBattleMons[gBankAttacker].personality, flavor) < 0)
		gBattlescriptCurrInstr = BattleScript_BugBiteGainHPConfuse;
	else
		gBattlescriptCurrInstr = BattleScript_BugBiteGainHP;
}

static void sp03_bugbite(void)
{
	//asasdfghasgfh;efjwi
	u16 itemstolen = gBattleMons[gBankTarget].item;
	u8 i;
	struct Pokemon* poke;
	u8 changedPP, ppBonuses, maxPP;
	u16 move;
	
	if (ItemId_GetPocket(itemstolen) == 0x4) //evil magic number: POCKET_BERRIES
	{
		gLastUsedItem = itemstolen;
		gWishFutureKnock.berryEatenPokes[GetBattlerSide(gBankAttacker)] |= gBitTable[gBattlerPartyIndexes[gBankAttacker]];
		
		switch (itemstolen)
		{
			case ITEM_ORAN_BERRY: 
				gBattleMoveDamage = 10;
				if (gBattleMons[gBankAttacker].hp + gBattleMoveDamage > gBattleMons[gBankAttacker].maxHP)
					gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP - gBattleMons[gBankAttacker].hp;
				gBattleMoveDamage *= -1;
				gBattlescriptCurrInstr = BattleScript_BugBiteGainHP;
				break;
			case ITEM_SITRUS_BERRY:
				gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP / 4;
				if (gBattleMons[gBankAttacker].hp + gBattleMoveDamage > gBattleMons[gBankAttacker].maxHP)
					gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP - gBattleMons[gBankAttacker].hp;
				gBattleMoveDamage *= -1;
				gBattlescriptCurrInstr = BattleScript_BugBiteGainHP;
				break;
			case ITEM_CHERI_BERRY:
				if (gBattleMons[gBankAttacker].status1 & STATUS_PARALYSIS)
				{
					gBattleMons[gBankAttacker].status1 = 0;
					EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
					gBattlescriptCurrInstr = BattleScript_BugBiteHealStatus;
				}
				else
				{
					gBattlescriptCurrInstr = BattleScript_BugBiteEatBerry;
				}
				break;
			case ITEM_PECHA_BERRY:
				if (gBattleMons[gBankAttacker].status1 & (STATUS_PSN_ANY))
				{
					gBattleMons[gBankAttacker].status1 = 0;
					EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
					gBattlescriptCurrInstr = BattleScript_BugBiteHealStatus;
				}
				else
				{
					gBattlescriptCurrInstr = BattleScript_BugBiteEatBerry;
				}
				break;
			case ITEM_RAWST_BERRY:
				if (gBattleMons[gBankAttacker].status1 & (STATUS_BURN))
				{
					gBattleMons[gBankAttacker].status1 = 0;
					EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
					gBattlescriptCurrInstr = BattleScript_BugBiteHealStatus;
				}
				else
				{
					gBattlescriptCurrInstr = BattleScript_BugBiteEatBerry;
				}
				break;
			case ITEM_CHESTO_BERRY:
				if (gBattleMons[gBankAttacker].status1 & (STATUS_SLEEP))
				{
					gBattleMons[gBankAttacker].status1 = 0;
                    gBattleMons[gBankAttacker].status2 &= ~(STATUS2_NIGHTMARE);
					EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
					gBattlescriptCurrInstr = BattleScript_BugBiteHealStatus;
				}
				else
				{
					gBattlescriptCurrInstr = BattleScript_BugBiteEatBerry;
				}
				break;
			case ITEM_PERSIM_BERRY:
				if (gBattleMons[gBankAttacker].status2 & (STATUS2_CONFUSION))
				{
                    gBattleMons[gBankAttacker].status2 &= ~(STATUS2_CONFUSION);
					EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
					gBattlescriptCurrInstr = BattleScript_BugBiteHealStatus;
				}
				else
				{
					gBattlescriptCurrInstr = BattleScript_BugBiteEatBerry;
				}
			case ITEM_LUM_BERRY:
				if (gBattleMons[gBankAttacker].status1 || (gBattleMons[gBankAttacker].status2) & STATUS2_CONFUSION)
				{
					gBattleMons[gBankAttacker].status1 = 0;
                    gBattleMons[gBankAttacker].status2 &= ~(STATUS2_CONFUSION);
                    gBattleMons[gBankAttacker].status2 &= ~(STATUS2_NIGHTMARE);
					EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
					gBattlescriptCurrInstr = BattleScript_BugBiteHealStatus;
				}
				else
				{
					gBattlescriptCurrInstr = BattleScript_BugBiteEatBerry;
				}
				break;
			case ITEM_FIGY_BERRY:
				_bugBiteFigy(FLAVOR_SPICY);
				break;
			case ITEM_WIKI_BERRY:
				_bugBiteFigy(FLAVOR_DRY);
				break;
			case ITEM_MAGO_BERRY:
				_bugBiteFigy(FLAVOR_SWEET);
				break;
			case ITEM_AGUAV_BERRY:
				_bugBiteFigy(FLAVOR_BITTER);
				break;
			case ITEM_IAPAPA_BERRY:
				_bugBiteFigy(FLAVOR_SOUR);
				break;
			case ITEM_LIECHI_BERRY:
				gBattleCommunication[MOVE_EFFECT_BYTE] = 0xCF;
				gBattlescriptCurrInstr = BattleScript_BugBiteRaiseStat;
				break;
			case ITEM_GANLON_BERRY:
				gBattleCommunication[MOVE_EFFECT_BYTE] = 0xD0;
				gBattlescriptCurrInstr = BattleScript_BugBiteRaiseStat;
				break;
			case ITEM_SALAC_BERRY:
				gBattleCommunication[MOVE_EFFECT_BYTE] = 0xD1;
				gBattlescriptCurrInstr = BattleScript_BugBiteRaiseStat;
				break;
			case ITEM_PETAYA_BERRY:
				gBattleCommunication[MOVE_EFFECT_BYTE] = 0xD2;
				gBattlescriptCurrInstr = BattleScript_BugBiteRaiseStat;
				break;
			case ITEM_APICOT_BERRY:
				gBattleCommunication[MOVE_EFFECT_BYTE] = 0xD3;
				gBattlescriptCurrInstr = BattleScript_BugBiteRaiseStat;
				break;
			case ITEM_STARF_BERRY:
				for (i = 0; i < 5; i++)
				{
					if (gBattleMons[gBankAttacker].statStages[STAT_STAGE_ATK + i] < 0xC)
						break;
				}
				if (i != 5)
				{
					do
					{
						i = Random() % 5;
					} while (gBattleMons[gBankAttacker].statStages[STAT_STAGE_ATK + i] == 0xC);
					gBattleCommunication[MOVE_EFFECT_BYTE] = 0xE7 + i;
					gBattlescriptCurrInstr = BattleScript_BugBiteRaiseStat;
				}
				else
				{
					gBattlescriptCurrInstr = BattleScript_BugBiteEatBerry;
				}
				break;
			case ITEM_LANSAT_BERRY:
				gBattlescriptCurrInstr = BattleScript_BugBiteLansat;
				break;
			case ITEM_LEPPA_BERRY:
				if (GetBattlerSide(gBankAttacker) == 0)
					poke = &gPlayerParty[gBattlerPartyIndexes[gBankAttacker]];
				else
					poke = &gEnemyParty[gBattlerPartyIndexes[gBankAttacker]];
				for (i = 0; i < 4; i++)
				{
					move = GetMonData(poke, MON_DATA_MOVE1 + i);
					changedPP = GetMonData(poke, MON_DATA_PP1 + i);
					ppBonuses = GetMonData(poke, MON_DATA_PP_BONUSES);
					maxPP = CalculatePPWithBonus(move, ppBonuses, i);
					if (move && changedPP == 0)
						break;
				}
				if (i == 4)
				{
					for (i = 0; i < 4; i++)
					{
						move = GetMonData(poke, MON_DATA_MOVE1 + i);
						changedPP = GetMonData(poke, MON_DATA_PP1 + i);
						ppBonuses = GetMonData(poke, MON_DATA_PP_BONUSES);
						maxPP = CalculatePPWithBonus(move, ppBonuses, i);
						if (move && changedPP != maxPP)
							break;
					}
				}
				if (i != 4)
				{
					if (changedPP + 10 > maxPP)
						changedPP = maxPP;
					else
						changedPP = changedPP + 10;
					gBattleTextBuff1[0] = 0xFD;
					gBattleTextBuff1[1] = 2;
					gBattleTextBuff1[2] = move;
					gBattleTextBuff1[3] = move >> 8;
					gBattleTextBuff1[4] = 0xFF;
					EmitSetMonData(0, i + REQUEST_PPMOVE1_BATTLE, 0, 1, &changedPP);
					MarkBufferBankForExecution(gActiveBattler);
					gBattlescriptCurrInstr = BattleScript_BugBiteLeppa;
				}
			default:
				gBattlescriptCurrInstr = BattleScript_BugBiteEatBerry;
				break;
		}
	}
}

static void sp04_naturalgift(void)
{
	u16 itemthrown = gBattleMons[gBankAttacker].item;
	u8 failed = 0;
	
	if (gWishFutureKnock.knockedOffPokes[gBankAttacker])
		failed = 1;
	else
	{
		gLastUsedItem = itemthrown;
		gBattleStruct->dynamicMoveType = ItemId_GetNatGiftType(itemthrown);
		gDynamicBasePower = ItemId_GetNatGiftPower(itemthrown);
		if (gDynamicBasePower == 0)
			failed = 1;
	}
	
	if (failed)
	{
		gBattlescriptCurrInstr = BattleScript_ButItFailed;
	}
}

static void sp05_defogreflect(void)
{
    u8 side = GetBattlerSide(gBankTarget);
    if (gSideTimers[side].reflectTimer)
    {
        gSideAffecting[side] &= ~(SIDE_STATUS_REFLECT);
        gSideTimers[side].reflectTimer = 0;
		gBattleTextBuff1[0] = 0xFD;
		gBattleTextBuff1[1] = 2;
		gBattleTextBuff1[2] = MOVE_REFLECT;
		gBattleTextBuff1[3] = MOVE_REFLECT >> 8;
		gBattleTextBuff1[4] = EOS;
    }
	else
	{
		gBattlescriptCurrInstr += 6;
	}
}

static void sp06_defoglightscreen(void)
{
    u8 side = GetBattlerSide(gBankTarget);
    if (gSideTimers[side].lightscreenTimer)
    {
        gSideAffecting[side] &= ~(SIDE_STATUS_LIGHTSCREEN);
        gSideTimers[side].lightscreenTimer = 0;
		gBattleTextBuff1[0] = 0xFD;
		gBattleTextBuff1[1] = 2;
		gBattleTextBuff1[2] = MOVE_LIGHT_SCREEN;
		gBattleTextBuff1[3] = MOVE_LIGHT_SCREEN >> 8;
		gBattleTextBuff1[4] = EOS;
    }
	else
	{
		gBattlescriptCurrInstr += 6;
	}
}

static void sp07_defogsafeguard(void)
{
    u8 side = GetBattlerSide(gBankTarget);
    if (gSideTimers[side].safeguardTimer)
    {
        gSideAffecting[side] &= ~(SIDE_STATUS_SAFEGUARD);
        gSideTimers[side].safeguardTimer = 0;
		gBattleTextBuff1[0] = 0xFD;
		gBattleTextBuff1[1] = 2;
		gBattleTextBuff1[2] = MOVE_SAFEGUARD;
		gBattleTextBuff1[3] = MOVE_SAFEGUARD >> 8;
		gBattleTextBuff1[4] = EOS;
    }
	else
	{
		gBattlescriptCurrInstr += 6;
	}
}

static void sp08_defogmist(void)
{
    u8 side = GetBattlerSide(gBankTarget);
    if (gSideTimers[side].mistTimer)
    {
        gSideAffecting[side] &= ~(SIDE_STATUS_MIST);
        gSideTimers[side].mistTimer = 0;
		gBattleTextBuff1[0] = 0xFD;
		gBattleTextBuff1[1] = 2;
		gBattleTextBuff1[2] = MOVE_MIST;
		gBattleTextBuff1[3] = MOVE_MIST >> 8;
		gBattleTextBuff1[4] = EOS;
    }
	else
	{
		gBattlescriptCurrInstr += 6;
	}
}

static void sp09_defogfoespikes(void)
{
    u8 side = GetBattlerSide(gBankTarget);
    if (gSideTimers[side].spikesAmount & HAZARD_SPIKES)
    {
        gSideTimers[side].spikesAmount &= ~(HAZARD_SPIKES);
		gBattleTextBuff1[0] = 0xFD;
		gBattleTextBuff1[1] = 2;
		gBattleTextBuff1[2] = MOVE_SPIKES;
		gBattleTextBuff1[3] = MOVE_SPIKES >> 8;
		gBattleTextBuff1[4] = EOS;
    }
	else
	{
		gBattlescriptCurrInstr += 6;
	}
}

static void sp0A_defogownspikes(void)
{
    u8 side = GetBattlerSide(gBankAttacker);
    if (gSideTimers[side].spikesAmount & HAZARD_SPIKES)
    {
        gSideTimers[side].spikesAmount &= ~(HAZARD_SPIKES);
		gBattleTextBuff1[0] = 0xFD;
		gBattleTextBuff1[1] = 2;
		gBattleTextBuff1[2] = MOVE_SPIKES;
		gBattleTextBuff1[3] = MOVE_SPIKES >> 8;
		gBattleTextBuff1[4] = EOS;
    }
	else
	{
		gBattlescriptCurrInstr += 6;
	}
}

static void sp0B_roost(void)
{
	if (gBattleMons[gBankAttacker].type1 == TYPE_FLYING)
		gBattleMons[gBankAttacker].type1 = TYPE_ROOSTING;
	if (gBattleMons[gBankAttacker].type2 == TYPE_FLYING)
		gBattleMons[gBankAttacker].type2 = TYPE_ROOSTING;
}

static void sp0C_payback(void)
{
	u8 i;
	// Payback's power doubles if:
	// The target has already acted
	// The target is not switching
	
	
	gBattleStruct->animTurn = 0;
	
	if (gActionForBanks[gBankTarget] == ACTION_USE_MOVE)
	{
		for (i = 0; i < 4; i++)
		{
			if (gBanksByTurnOrder[i] == gBankAttacker)
				break;
			if (gBanksByTurnOrder[i] == gBankTarget)
			{
				// Double base power instead of using the multiplier due to Technician.
				gDynamicBasePower = 100;
				gBattleStruct->animTurn = 1;
				break;
			}
		}
	}
}

static void sp0D_tailwind(void)
{
    u8 side = GetBattlerSide(gBankAttacker);
    if (gSideTimers[side].tailwindTimer > 0)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    else
    {
        gSideTimers[side].tailwindTimer = 4;
        gBattleCommunication[MULTISTRING_CHOOSER] = 7;
    }
}

static void sp0E_luckychant(void)
{
    u8 side = GetBattlerSide(gBankAttacker);
    if (gSideTimers[side].luckyChantTimer > 0)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    else
    {
        gSideTimers[side].luckyChantTimer = 5;
        gBattleCommunication[MULTISTRING_CHOOSER] = 6;
    }
}

static void sp0F_storedpower(void)
{
	u16 power = 20;
	
	if (gBattleMons[gBankAttacker].statStages[STAT_STAGE_ATK] > 6)
		power += (gBattleMons[gBankAttacker].statStages[STAT_STAGE_ATK] - 6) * 20;
	if (gBattleMons[gBankAttacker].statStages[STAT_STAGE_DEF] > 6)
		power += (gBattleMons[gBankAttacker].statStages[STAT_STAGE_DEF] - 6) * 20;
	if (gBattleMons[gBankAttacker].statStages[STAT_STAGE_SPEED] > 6)
		power += (gBattleMons[gBankAttacker].statStages[STAT_STAGE_SPEED] - 6) * 20;
	if (gBattleMons[gBankAttacker].statStages[STAT_STAGE_SPATK] > 6)
		power += (gBattleMons[gBankAttacker].statStages[STAT_STAGE_SPATK] - 6) * 20;
	if (gBattleMons[gBankAttacker].statStages[STAT_STAGE_SPDEF] > 6)
		power += (gBattleMons[gBankAttacker].statStages[STAT_STAGE_SPDEF] - 6) * 20;
	if (gBattleMons[gBankAttacker].statStages[STAT_STAGE_ACC] > 6)
		power += (gBattleMons[gBankAttacker].statStages[STAT_STAGE_ACC] - 6) * 20;
	if (gBattleMons[gBankAttacker].statStages[STAT_STAGE_EVASION] > 6)
		power += (gBattleMons[gBankAttacker].statStages[STAT_STAGE_EVASION] - 6) * 20;
	
	gDynamicBasePower = power;
}

static void sp10_captivate(void)
{
    struct Pokemon *attacker, *target;
    u16 atk_species, def_species;
    u32 atk_pid, def_pid;
    if (!GetBattlerSide(gBankAttacker))
        attacker = &gPlayerParty[gBattlerPartyIndexes[gBankAttacker]];
    else
        attacker = &gEnemyParty[gBattlerPartyIndexes[gBankAttacker]];

    if (!GetBattlerSide(gBankTarget))
        target = &gPlayerParty[gBattlerPartyIndexes[gBankTarget]];
    else
        target = &gEnemyParty[gBattlerPartyIndexes[gBankTarget]];

    atk_species = GetMonData(attacker, MON_DATA_SPECIES);
    atk_pid = GetMonData(attacker, MON_DATA_PERSONALITY);

    def_species = GetMonData(target, MON_DATA_SPECIES);
    def_pid = GetMonData(target, MON_DATA_PERSONALITY);

    if (gBattleMons[gBankTarget].ability == ABILITY_OBLIVIOUS)
    {
        gBattlescriptCurrInstr = BattleScript_CaptivateFailOblivious;
        gLastUsedAbility = ABILITY_OBLIVIOUS;
        RecordAbilityBattle(gBankTarget, ABILITY_OBLIVIOUS);
    }
    else
    {
        if (GetGenderFromSpeciesAndPersonality(atk_species, atk_pid) == GetGenderFromSpeciesAndPersonality(def_species, def_pid)
            || gStatuses3[gBankTarget] & STATUS3_SEMI_INVULNERABLE || GetGenderFromSpeciesAndPersonality(atk_species, atk_pid) == 0xFF
            || GetGenderFromSpeciesAndPersonality(def_species, def_pid) == 0xFF)
            {
                gBattlescriptCurrInstr = BattleScript_CaptivateFail;
            }
    }
}

static void sp11_healingwish(void)
{
	gActiveBattler = gBankAttacker;
	gBattleMoveDamage = gBattleMons[gActiveBattler].hp;
	EmitHealthBarUpdate(0, 0x7FFF);
	MarkBufferBankForExecution(gActiveBattler);
	gSideTimers[GetBattlerSide(gActiveBattler)].spikesAmount |= HAZARD_HEALING_WISH;
}

static void sp12_spikesaffect(void)
{
	u8 spikes;
	gActiveBattler = gBattleStruct->scriptingActive;
	spikes = gSideTimers[GetBattlerSide(gActiveBattler)].spikesAmount & HAZARD_SPIKES; // 0x3
	if (spikes == 0 || gBattleMons[gActiveBattler].type1 == TYPE_FLYING || gBattleMons[gActiveBattler].type2 == TYPE_FLYING
        || gBattleMons[gActiveBattler].ability == ABILITY_LEVITATE || gBattleMons[gActiveBattler].ability == ABILITY_MAGIC_GUARD)
	{
		gBattlescriptCurrInstr += 5;
	}
	else
	{
		gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / (10 - (2 * spikes));
	}
}

static void sp13_healingwishaffect(void)
{
	u8 wish;
	gActiveBattler = gBattleStruct->scriptingActive;
	wish = gSideTimers[GetBattlerSide(gActiveBattler)].spikesAmount & HAZARD_HEALING_WISH;
	if (!wish)
	{
		gBattlescriptCurrInstr += 5;
	}
	else
	{
		gSideTimers[GetBattlerSide(gActiveBattler)].spikesAmount &= ~HAZARD_HEALING_WISH;
		gBattleMoveDamage = gBattleMons[gBankTarget].maxHP * (-1);
		gBattleMons[gBankTarget].status1 = 0;
		
        EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
		MarkBufferBankForExecution(gActiveBattler);
	}
}

static void sp14_setstickyweb(void)
{
    u8 side = GetBattlerSide(gBankAttacker) ^ 1;
    if ((gSideTimers[side].spikesAmount & HAZARD_STICKY_WEB) != 0)
    {
        gSpecialStatuses[gBankAttacker].flag20 = 1;
    }
    else
    {
        gSideTimers[side].spikesAmount |= HAZARD_STICKY_WEB;
        gBattlescriptCurrInstr += 5;
    }
}

static void sp15_webaffect(void)
{
	u8 web;
	gActiveBattler = gBattleStruct->scriptingActive;
	web = gSideTimers[GetBattlerSide(gActiveBattler)].spikesAmount & HAZARD_STICKY_WEB;
	if (web == 0 || gBattleMons[gActiveBattler].type1 == TYPE_FLYING || gBattleMons[gActiveBattler].type2 == TYPE_FLYING || gBattleMons[gActiveBattler].ability == ABILITY_LEVITATE)
	{
		gBattlescriptCurrInstr += 5;
	}
	else
	{
	}
}

static void sp16_defogfoeweb(void)
{
    u8 side = GetBattlerSide(gBankTarget);
    if (gSideTimers[side].spikesAmount & HAZARD_STICKY_WEB)
    {
        gSideTimers[side].spikesAmount &= ~(HAZARD_STICKY_WEB);
		gBattleTextBuff1[0] = 0xFD;
		gBattleTextBuff1[1] = 2;
		gBattleTextBuff1[2] = (u8)MOVE_STICKY_WEB;
		gBattleTextBuff1[3] = MOVE_STICKY_WEB >> 8;
		gBattleTextBuff1[4] = EOS;
    }
	else
	{
		gBattlescriptCurrInstr += 6;
	}
}

static void sp17_defogownweb(void)
{
    u8 side = GetBattlerSide(gBankAttacker);
    if (gSideTimers[side].spikesAmount & HAZARD_STICKY_WEB)
    {
        gSideTimers[side].spikesAmount &= ~(HAZARD_STICKY_WEB);
		gBattleTextBuff1[0] = 0xFD;
		gBattleTextBuff1[1] = 2;
		gBattleTextBuff1[2] = (u8)MOVE_STICKY_WEB;
		gBattleTextBuff1[3] = MOVE_STICKY_WEB >> 8;
		gBattleTextBuff1[4] = EOS;
    }
	else
	{
		gBattlescriptCurrInstr += 6;
	}
}

static void sp18_worryseed(void)
{
    //Set target's ability to Insomnia.
    //Don't worry about fail-checking, script accounts for that.
   
    gBattleMons[gBankTarget].ability = ABILITY_INSOMNIA;
}

static void sp19_punishment(void)
{
	// dead code now
	u16 power = 20;
	
	if (gBattleMons[gBankTarget].statStages[STAT_STAGE_ATK] > 6)
		power += (gBattleMons[gBankTarget].statStages[STAT_STAGE_ATK] - 6) * 20;
	if (gBattleMons[gBankTarget].statStages[STAT_STAGE_DEF] > 6)
		power += (gBattleMons[gBankTarget].statStages[STAT_STAGE_DEF] - 6) * 20;
	if (gBattleMons[gBankTarget].statStages[STAT_STAGE_SPEED] > 6)
		power += (gBattleMons[gBankTarget].statStages[STAT_STAGE_SPEED] - 6) * 20;
	if (gBattleMons[gBankTarget].statStages[STAT_STAGE_SPATK] > 6)
		power += (gBattleMons[gBankTarget].statStages[STAT_STAGE_SPATK] - 6) * 20;
	if (gBattleMons[gBankTarget].statStages[STAT_STAGE_SPDEF] > 6)
		power += (gBattleMons[gBankTarget].statStages[STAT_STAGE_SPDEF] - 6) * 20;
	if (gBattleMons[gBankTarget].statStages[STAT_STAGE_ACC] > 6)
		power += (gBattleMons[gBankTarget].statStages[STAT_STAGE_ACC] - 6) * 20;
	if (gBattleMons[gBankTarget].statStages[STAT_STAGE_EVASION] > 6)
		power += (gBattleMons[gBankTarget].statStages[STAT_STAGE_EVASION] - 6) * 20;
	
	if (power > 200)
		power = 200;
	
	gDynamicBasePower = power;
}

static void sp1A_echoedvoice(void)
{
	gBattleStruct->echoedVoiceMarker = 1;
	gDynamicBasePower = 40 + (40 * gBattleStruct->echoedVoiceCounter);
	gBattleStruct->animTurn = gBattleStruct->echoedVoiceCounter;
}

static void sp1B_sleepremoval(void)
{
    if (gBattleMons[gBankTarget].status1 & STATUS_SLEEP)
    {
        gBattleMons[gBankTarget].status1 &= ~(STATUS_SLEEP);
        gActiveBattler = gBankTarget;
        EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gBankTarget].status1);
        MarkBufferBankForExecution(gActiveBattler);
        BattleScriptPush(gBattlescriptCurrInstr);
        gBattlescriptCurrInstr = BattleScript_TargetSLPHeal;
    }
}

static void sp1C_heavyslam(void)
{

}

static void sp1D_aquaring(void)
{
	gStatuses3[gBankAttacker] |= STATUS3_AQUA_RING;
}

static void sp1E_soak(void)
{
	if (gBattleMons[gBankTarget].type1 == TYPE_WATER && gBattleMons[gBankTarget].type2 == TYPE_WATER)
	{
		// don't jump 5 so we goto butitfailed
	}
	else
	{
		gBattleMons[gBankTarget].type1 = TYPE_WATER;
		gBattleMons[gBankTarget].type2 = TYPE_WATER;
		gBattlescriptCurrInstr += 5;
	}
}

static void sp1F_setstealthrock(void)
{
    u8 side = GetBattlerSide(gBankAttacker) ^ 1;
    if ((gSideTimers[side].spikesAmount & HAZARD_STEALTH_ROCK) != 0)
    {
        gSpecialStatuses[gBankAttacker].flag20 = 1;
    }
    else
    {
        gSideTimers[side].spikesAmount |= HAZARD_STEALTH_ROCK;
        gBattlescriptCurrInstr += 5;
    }
}

static void sp20_rocksaffect(void)
{
	u8 spikes;
	u8 damagerate;
	gActiveBattler = gBattleStruct->scriptingActive;
	spikes = gSideTimers[GetBattlerSide(gActiveBattler)].spikesAmount & HAZARD_STEALTH_ROCK;
	if (spikes == 0 || gBattleMons[gActiveBattler].ability == ABILITY_MAGIC_GUARD)
	{
		gBattlescriptCurrInstr += 5;
	}
	else
	{
		damagerate = 4;
		damagerate = damagerate * gTypeEffectiveness[20 * TYPE_ROCK + gBattleMons[gActiveBattler].type1] / 10;
		if (gBattleMons[gActiveBattler].type1 != gBattleMons[gActiveBattler].type2)
			damagerate = damagerate * gTypeEffectiveness[20 * TYPE_ROCK + gBattleMons[gActiveBattler].type2] / 10;
		gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP * damagerate / 32;
	}
}

static void sp21_defogfoerocks(void)
{
    u8 side = GetBattlerSide(gBankTarget);
    if (gSideTimers[side].spikesAmount & HAZARD_STEALTH_ROCK)
    {
        gSideTimers[side].spikesAmount &= ~(HAZARD_STEALTH_ROCK);
		gBattleTextBuff1[0] = 0xFD;
		gBattleTextBuff1[1] = 2;
		gBattleTextBuff1[2] = (u8)MOVE_STEALTH_ROCK;
		gBattleTextBuff1[3] = MOVE_STEALTH_ROCK >> 8;
		gBattleTextBuff1[4] = EOS;
    }
	else
	{
		gBattlescriptCurrInstr += 6;
	}
}

static void sp22_defogownrocks(void)
{
    u8 side = GetBattlerSide(gBankAttacker);
    if (gSideTimers[side].spikesAmount & HAZARD_STEALTH_ROCK)
    {
        gSideTimers[side].spikesAmount &= ~(HAZARD_STEALTH_ROCK);
		gBattleTextBuff1[0] = 0xFD;
		gBattleTextBuff1[1] = 2;
		gBattleTextBuff1[2] = (u8)MOVE_STEALTH_ROCK;
		gBattleTextBuff1[3] = MOVE_STEALTH_ROCK >> 8;
		gBattleTextBuff1[4] = EOS;
    }
	else
	{
		gBattlescriptCurrInstr += 6;
	}
}

static const u16 sMovesForbiddenToCopycat[] =
{
	 MOVE_ASSIST,
	 // baneful bunker
	 // bestow
	 // chatter
	 // circle throw
	 MOVE_COPYCAT,
	 MOVE_COUNTER,
	 MOVE_COVET,
	 MOVE_DESTINY_BOND,
	 MOVE_DETECT,
	 MOVE_DRAGON_TAIL,
	 MOVE_ENDURE,
	 MOVE_FEINT,
	 MOVE_FOCUS_PUNCH,
	 MOVE_FOLLOW_ME,
	 MOVE_HELPING_HAND,
	 MOVE_ME_FIRST,
	 MOVE_METRONOME,
	 MOVE_MIMIC,
	 MOVE_MIRROR_COAT,
	 MOVE_MIRROR_MOVE,
	 MOVE_NATURE_POWER,
	 MOVE_PROTECT,
	 // rage powder
	 MOVE_ROAR,
	 MOVE_SKETCH,
	 MOVE_SLEEP_TALK,
	 MOVE_SNATCH,
	 MOVE_STRUGGLE,
	 MOVE_SWITCHEROO,
	 MOVE_THIEF,
	 MOVE_TRANSFORM,
	 MOVE_TRICK,
	 MOVE_WHIRLWIND,
	 0,
};

static void sp23_copycat(void)
{
	u8 i = 0;
	while (sMovesForbiddenToCopycat[i])
	{
		if (gBattleStruct->copycatTracker == sMovesForbiddenToCopycat[i])
			return;
		else
			i++;
	}
	if (gBattleStruct->copycatTracker != 0)
	{
        gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
        gCurrentMove = gBattleStruct->copycatTracker;
        gBankTarget = GetMoveTarget(gCurrentMove, 0);
        gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
	}
	// else current instruction stays the same and move fails
}

static void sp24_settoxicspikes(void)
{
	//t-spikes occupies 0x18
    u8 side = GetBattlerSide(gBankAttacker) ^ 1;
    if ((gSideTimers[side].spikesAmount & HAZARD_TOXIC_SPIKES2) != 0)
    {
        gSpecialStatuses[gBankAttacker].flag20 = 1;
    }
    else if ((gSideTimers[side].spikesAmount & HAZARD_TOXIC_SPIKES) != 0)
	{
        gSideTimers[side].spikesAmount |= HAZARD_TOXIC_SPIKES2;
        gBattlescriptCurrInstr += 5;
	}
    else
    {
        gSideTimers[side].spikesAmount |= HAZARD_TOXIC_SPIKES;
        gBattlescriptCurrInstr += 5;
    }
}

static void sp25_toxicspikesaffect(void)
{
	u8 spikes;
	gActiveBattler = gBattleStruct->scriptingActive;
	spikes = gSideTimers[GetBattlerSide(gActiveBattler)].spikesAmount;
    gBattlescriptCurrInstr += 8;
	
	if (!(spikes & HAZARD_TOXIC_SPIKES))
	{
		// no t-spikes
	}
	else if (gBattleMons[gActiveBattler].type1 == TYPE_FLYING || gBattleMons[gActiveBattler].type2 == TYPE_FLYING || gBattleMons[gActiveBattler].ability == ABILITY_LEVITATE)
	{
		// floated over t-spikes
	}
	else if (gBattleMons[gActiveBattler].type1 == TYPE_POISON || gBattleMons[gActiveBattler].type2 == TYPE_POISON)
	{
		// absorbed t-spikes
		gSideTimers[GetBattlerSide(gActiveBattler)].spikesAmount &= ~(HAZARD_TOXIC_SPIKES | HAZARD_TOXIC_SPIKES2);
		
        BattleScriptPushCursor();
		gBattlescriptCurrInstr = BattleScript_AbsorbToxicSpikes;
		
	}
	else if (gBattleMons[gActiveBattler].type1 == TYPE_STEEL || gBattleMons[gActiveBattler].type2 == TYPE_STEEL
	 || gBattleMons[gActiveBattler].ability == ABILITY_IMMUNITY || gBattleMons[gActiveBattler].status1
	 || gSideAffecting[gActiveBattler] & SIDE_STATUS_SAFEGUARD)
	{
		// can't be poisoned
	}
	else if (spikes & HAZARD_TOXIC_SPIKES2)
	{
		gBattleMons[gActiveBattler].status1 = STATUS_TOXIC_POISON;
        EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
        MarkBufferBankForExecution(gActiveBattler);
		
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr - 4);
	}
	else if (spikes & HAZARD_TOXIC_SPIKES)
	{
		gBattleMons[gActiveBattler].status1 = STATUS_POISON;
        EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
        MarkBufferBankForExecution(gActiveBattler);
		
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr - 8);
	}
}

static void sp26_wringout(void)
{
	gDynamicBasePower = 120 * gBattleMons[gBankTarget].hp / gBattleMons[gBankTarget].maxHP;
	if (gDynamicBasePower == 0)
		gDynamicBasePower = 1;
}


static void sp27_defogfoetoxicspikes(void)
{
    u8 side = GetBattlerSide(gBankTarget);
    if (gSideTimers[side].spikesAmount & HAZARD_TOXIC_SPIKES_ANY)
    {
        gSideTimers[side].spikesAmount &= ~(HAZARD_TOXIC_SPIKES_ANY);
		gBattleTextBuff1[0] = 0xFD;
		gBattleTextBuff1[1] = 2;
		gBattleTextBuff1[2] = (u8)MOVE_TOXIC_SPIKES;
		gBattleTextBuff1[3] = MOVE_TOXIC_SPIKES >> 8;
		gBattleTextBuff1[4] = EOS;
    }
	else
	{
		gBattlescriptCurrInstr += 6;
	}
}

static void sp28_defogowntoxicspikes(void)
{
    u8 side = GetBattlerSide(gBankAttacker);
    if (gSideTimers[side].spikesAmount & HAZARD_TOXIC_SPIKES_ANY)
    {
        gSideTimers[side].spikesAmount &= ~(HAZARD_TOXIC_SPIKES_ANY);
		gBattleTextBuff1[0] = 0xFD;
		gBattleTextBuff1[1] = 2;
		gBattleTextBuff1[2] = (u8)MOVE_TOXIC_SPIKES;
		gBattleTextBuff1[3] = MOVE_TOXIC_SPIKES >> 8;
		gBattleTextBuff1[4] = EOS;
    }
	else
	{
		gBattlescriptCurrInstr += 6;
	}
}

static void sp29_reflecttype(void)
{
	gBattleMons[gBankAttacker].type1 = gBattleMons[gBankTarget].type1;
	gBattleMons[gBankAttacker].type2 = gBattleMons[gBankTarget].type2;
	if (gBattleMons[gBankAttacker].type1 == TYPE_ROOSTING)
		gBattleMons[gBankAttacker].type1 = TYPE_FLYING;
	if (gBattleMons[gBankAttacker].type2 == TYPE_ROOSTING)
		gBattleMons[gBankAttacker].type2 = TYPE_FLYING;
}

static void sp2A_metalburst(void)
{
    u8 atk_side = GetBattlerSide(gBankAttacker);
    u8 def_side = GetBattlerSide(gProtectStructs[gBankAttacker].specialBank);
	if (gProtectStructs[gBankAttacker].classLastHit == CLASS_PHYSICAL)
	{
		def_side = GetBattlerSide(gProtectStructs[gBankAttacker].physicalBank);
		if (gProtectStructs[gBankAttacker].physicalDmg && atk_side != def_side && gBattleMons[gProtectStructs[gBankAttacker].physicalBank].hp)
		{
			gBattleMoveDamage = gProtectStructs[gBankAttacker].physicalDmg * 3 / 2;
			if (gSideTimers[def_side].followmeTimer && gBattleMons[gSideTimers[def_side].followmeTarget].hp)
				gBankTarget = gSideTimers[def_side].followmeTarget;
			else
				gBankTarget = gProtectStructs[gBankAttacker].physicalBank;
			gBattlescriptCurrInstr += 5;
		}
		else
		{
			gSpecialStatuses[gBankAttacker].flag20 = 1;
		}
	}
	else
	{
		if (gProtectStructs[gBankAttacker].specialDmg && atk_side != def_side && gBattleMons[gProtectStructs[gBankAttacker].specialBank].hp)
		{
			gBattleMoveDamage = gProtectStructs[gBankAttacker].specialDmg * 3 / 2;
			if (gSideTimers[def_side].followmeTimer && gBattleMons[gSideTimers[def_side].followmeTarget].hp)
				gBankTarget = gSideTimers[def_side].followmeTarget;
			else
				gBankTarget = gProtectStructs[gBankAttacker].specialBank;
			gBattlescriptCurrInstr += 5;
		}
		else
		{
			gSpecialStatuses[gBankAttacker].flag20 = 1;
		}
	}

}

static void sp2B_electroball(void)
{
    // Now dead code.
	u16 attackerspeed = GetModifiedSpeed(gBankAttacker);
	u16 targetspeed = GetModifiedSpeed(gBankTarget);
	
	if (targetspeed > attackerspeed)
	{
		gDynamicBasePower = 40;
	}
	else if (targetspeed*2 > attackerspeed)
	{
		gDynamicBasePower = 60;
	}
	else if (targetspeed*3 > attackerspeed)
	{
		gDynamicBasePower = 80;
	}
	else if (targetspeed*4 > attackerspeed)
	{
		gDynamicBasePower = 120;
	}
	else
	{
		gDynamicBasePower = 150;
	}
}

static void sp2C_entrainmentfailcheck(void)
{
	if (gBattleMons[gBankTarget].ability == ABILITY_TRUANT ||
		gBattleMons[gBankAttacker].ability == ABILITY_TRACE ||
		gBattleMons[gBankAttacker].ability == ABILITY_FORECAST ||
		gBattleMons[gBankTarget].ability == gBattleMons[gBankAttacker].ability)
	{
		gBattlescriptCurrInstr = BattleScript_ButItFailed;
		return;
	}
}

static void sp2D_trumpcard(void)
{
	switch (gBattleMons[gBankAttacker].pp[gCurrMovePos])
	{
		case 0: gDynamicBasePower = 200; gBattleStruct->animTurn = 4; break;
		case 1: gDynamicBasePower = 80; gBattleStruct->animTurn = 3; break;
		case 2: gDynamicBasePower = 60; gBattleStruct->animTurn = 2; break;
		case 3: gDynamicBasePower = 50; gBattleStruct->animTurn = 1; break;
		default: gDynamicBasePower = 40; gBattleStruct->animTurn = 0; break;
	}
}

static void sp2E_entrainmentapply(void)
{
    gBattleMons[gBankTarget].ability = gBattleMons[gBankAttacker].ability;
}

static void sp2F_incinerate(void)
{
	u16 itemstolen = gBattleMons[gBankTarget].item;
	
	if (ItemId_GetPocket(itemstolen) == 0x4) //evil magic number: POCKET_BERRIES
	{
		gLastUsedItem = itemstolen;
		gBattlescriptCurrInstr = BattleScript_IncinerateDestroyBerry;
	}
}

static void sp30_clearsmog(void)
{
	gBattleMons[gBankTarget].statStages[STAT_STAGE_ATK] = 6;
	gBattleMons[gBankTarget].statStages[STAT_STAGE_DEF] = 6;
	gBattleMons[gBankTarget].statStages[STAT_STAGE_SPEED] = 6;
	gBattleMons[gBankTarget].statStages[STAT_STAGE_SPATK] = 6;
	gBattleMons[gBankTarget].statStages[STAT_STAGE_SPDEF] = 6;
	gBattleMons[gBankTarget].statStages[STAT_STAGE_ACC] = 6;
	gBattleMons[gBankTarget].statStages[STAT_STAGE_EVASION] = 6;
}

static void sp31_gyroball(void)
{
	// unused code now
	u16 attackerspeed = GetModifiedSpeed(gBankAttacker);
	u16 targetspeed = GetModifiedSpeed(gBankTarget);
	u32 power = targetspeed * 25 / attackerspeed;
	if (power > 150)
		power = 150;
	if (power < 1)
		power = 1;
	
	gDynamicBasePower = power;
}

static void sp32_feint(void)
{
	if (gProtectStructs[gBankTarget].protected)
    {
		gProtectStructs[gBankTarget].protected = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_LiftedProtect;
	}
}

static void sp33_powertrick(void)
{
	u16 buffer = gBattleMons[gBankAttacker].attack;
	gBattleMons[gBankAttacker].attack = gBattleMons[gBankAttacker].defense;
	gBattleMons[gBankAttacker].defense = buffer;
	gStatuses3[gBankAttacker] ^= STATUS3_POWER_TRICK;
}

static void sp34_powersplit(void)
{
	u16 value = (gBattleMons[gBankAttacker].attack + gBattleMons[gBankTarget].attack) / 2;
	gBattleMons[gBankAttacker].attack = value;
	gBattleMons[gBankTarget].attack = value;
	value = (gBattleMons[gBankAttacker].spAttack + gBattleMons[gBankTarget].spAttack) / 2;
	gBattleMons[gBankAttacker].spAttack = value;
	gBattleMons[gBankTarget].spAttack = value;
}

static void sp35_guardsplit(void)
{
	u16 value = (gBattleMons[gBankAttacker].defense + gBattleMons[gBankTarget].defense) / 2;
	gBattleMons[gBankAttacker].defense = value;
	gBattleMons[gBankTarget].defense = value;
	value = (gBattleMons[gBankAttacker].spDefense + gBattleMons[gBankTarget].spDefense) / 2;
	gBattleMons[gBankAttacker].spDefense = value;
	gBattleMons[gBankTarget].spDefense = value;
}

static void sp36_bpasspowertrick(void)
{
	// For some reason, Power Trick can be baton passed...
	if (gStatuses3[gBankAttacker] & STATUS3_POWER_TRICK)
	{
		u16 buffer = gBattleMons[gBankAttacker].attack;
		gBattleMons[gBankAttacker].attack = gBattleMons[gBankAttacker].defense;
		gBattleMons[gBankAttacker].defense = buffer;
	}
}

static void sp37_spotlight(void)
{
    gSideTimers[GetBattlerSide(gBankTarget)].followmeTimer = 1;
    gSideTimers[GetBattlerSide(gBankTarget)].followmeTarget = gBankTarget;
}

static void sp38_acupressure(void)
{
	while (1)
	{
		u8 value = Random() % 7;
		switch (value)
		{
			case 0: 
				if (gBattleMons[gBankAttacker].statStages[STAT_STAGE_ATK] < 12)
				{
					gBattleStruct->statChanger = 33;
					return;
				}
				break;
			case 1: 
				if (gBattleMons[gBankAttacker].statStages[STAT_STAGE_DEF] < 12)
				{
					gBattleStruct->statChanger = 34;
					return;
				}
				break;
			case 2: 
				if (gBattleMons[gBankAttacker].statStages[STAT_STAGE_SPEED] < 12)
				{
					gBattleStruct->statChanger = 35;
					return;
				}
				break;
			case 3: 
				if (gBattleMons[gBankAttacker].statStages[STAT_STAGE_SPATK] < 12)
				{
					gBattleStruct->statChanger = 36;
					return;
				}
				break;
			case 4: 
				if (gBattleMons[gBankAttacker].statStages[STAT_STAGE_SPDEF] < 12)
				{
					gBattleStruct->statChanger = 37;
					return;
				}
				break;
			case 5: 
				if (gBattleMons[gBankAttacker].statStages[STAT_STAGE_ACC] < 12)
				{
					gBattleStruct->statChanger = 38;
					return;
				}
				break;
			case 6: 
				if (gBattleMons[gBankAttacker].statStages[STAT_STAGE_EVASION] < 12)
				{
					gBattleStruct->statChanger = 39;
					return;
				}
				break;
		}
	}
}

static void sp39_frisk(void)
{
	gLastUsedItem = gBattleMons[gBankTarget].item;
	if (gLastUsedItem == 0)
	{
		gBattlescriptCurrInstr += 6;
	}
}


static const u16 sMovesForbiddenToMeFirst[] =
{
	// beak blast
	// chatter
	MOVE_COUNTER,
	MOVE_COVET,
	MOVE_FOCUS_PUNCH,
	MOVE_METAL_BURST,
	MOVE_MIRROR_COAT,
	// shell trap
	MOVE_STRUGGLE,
	MOVE_THIEF,
	0,
};

static void sp3A_mefirst(void)
{
	// If target has moved, fail
	// If target is trying to use a status move, fail
	// If target is trying to use a non-copiable move, fail
	// Mimic target's move
	u8 failure = 0;
	u8 i = 0;
	u16 move = 0;
	
	if (gActionsByTurnOrder[gBankTarget] != ACTION_USE_MOVE)
		failure = 1;
	if (gProtectStructs[gBankTarget].onlyStruggle)
	{
		move = MOVE_STRUGGLE;
		failure = 1;
	}
	else
	{
		move = gBattleMons[gBankTarget].moves[ewram1608Carr(gBankTarget)];
	}
	
	if (gBattleMoves[move].moveClass == 2)
		failure = 1;
	else
	{
		while (sMovesForbiddenToMeFirst[i] && !failure)
		{
			if (sMovesForbiddenToMeFirst[i] == move)
			{
				failure = 1;
			}
			i++;
		}
	}
	
	for (i = 0; i < 4 && !failure; i++)
	{
		if (gBanksByTurnOrder[i] == gBankAttacker)
			break;
		if (gBanksByTurnOrder[i] == gBankTarget)
		{
			failure = 1;
			break;
		}
	}
	
	if (failure)
	{
		// failure to execute means we fall through in the battle script
		// so, do nothing here
	}
	else
	{
		gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
        gCurrentMove = move;
        gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
		gBattleStruct->meFirstTracker = 1;
	}
}

static void sp3B_powerswap(void)
{
	u16 buffer = gBattleMons[gBankAttacker].statStages[STAT_STAGE_ATK];
	gBattleMons[gBankAttacker].statStages[STAT_STAGE_ATK] = gBattleMons[gBankTarget].statStages[STAT_STAGE_ATK];
	gBattleMons[gBankTarget].statStages[STAT_STAGE_ATK] = buffer;
	
	buffer = gBattleMons[gBankAttacker].statStages[STAT_STAGE_SPATK];
	gBattleMons[gBankAttacker].statStages[STAT_STAGE_SPATK] = gBattleMons[gBankTarget].statStages[STAT_STAGE_SPATK];
	gBattleMons[gBankTarget].statStages[STAT_STAGE_SPATK] = buffer;
}

static void sp3C_guardswap(void)
{
	u16 buffer = gBattleMons[gBankAttacker].statStages[STAT_STAGE_DEF];
	gBattleMons[gBankAttacker].statStages[STAT_STAGE_DEF] = gBattleMons[gBankTarget].statStages[STAT_STAGE_DEF];
	gBattleMons[gBankTarget].statStages[STAT_STAGE_DEF] = buffer;
	
	buffer = gBattleMons[gBankAttacker].statStages[STAT_STAGE_SPDEF];
	gBattleMons[gBankAttacker].statStages[STAT_STAGE_SPDEF] = gBattleMons[gBankTarget].statStages[STAT_STAGE_SPDEF];
	gBattleMons[gBankTarget].statStages[STAT_STAGE_SPDEF] = buffer;
}

static void sp3D_psychoshiftsleep(void)
{
    gBattleMons[gBankAttacker].status1 &= ~(STATUS_SLEEP);
    gActiveBattler = gBankAttacker;
    EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gBankAttacker].status1);
    MarkBufferBankForExecution(gBankAttacker);
}

static void sp3E_uturncheck(void)
{
    u16 HP_count = 0;
	u8 i;
	
	if (gBattleMons[gBankAttacker].hp == 0)
	{
		gBattlescriptCurrInstr = BattleScript_FinishUTurn;
		return;
	}
	
    for (i = 0; i < 6; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
            HP_count += GetMonData(&gPlayerParty[i], MON_DATA_HP);
    }
    if (HP_count == 0)
	{
		gBattlescriptCurrInstr = BattleScript_FinishUTurn;
		return;
	}
	for (HP_count = 0, i = 0; i < 6; i++)
	{
		if (GetMonData(&gEnemyParty[i], MON_DATA_SPECIES) && !GetMonData(&gEnemyParty[i], MON_DATA_IS_EGG))
			HP_count += GetMonData(&gEnemyParty[i], MON_DATA_HP);
	}
	if (!HP_count)
		gBattlescriptCurrInstr = BattleScript_FinishUTurn;
}

static void sp3F_setauroraveil(void)
{
    if (gSideAffecting[GetBattlerPosition(gBankAttacker) & 1] & SIDE_STATUS_AURORA_VEIL)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    else
    {
        gSideAffecting[GetBattlerPosition(gBankAttacker) & 1] |= SIDE_STATUS_AURORA_VEIL;
        //gSideTimers[GetBattlerPosition(gBankAttacker) & 1].auroraVeilTimer = 5;
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && CountAliveMons(1) == 2)
            gBattleCommunication[MULTISTRING_CHOOSER] = 9;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = 8;
    }
}

static void sp40_settrickroom(void)
{
    if (gWishFutureKnock.trickRoomDuration == 0)
    {
        gWishFutureKnock.trickRoomDuration = 5;
        gBattleCommunication[MULTISTRING_CHOOSER] = 6;
    }
    else
    {
        gWishFutureKnock.trickRoomDuration = 0;
        gBattleCommunication[MULTISTRING_CHOOSER] = 7;
    }
}

static void sp41_checkdefiant(void)
{
    if (GetBattlerSide(gEffectBank) != GetBattlerSide(gBankAttacker))
    {
        if (gBattleMons[gEffectBank].ability == ABILITY_DEFIANT &&
            gBattleMons[gEffectBank].statStages[STAT_STAGE_ATK] != 13)
        {
            gBattleMons[gEffectBank].statStages[STAT_STAGE_ATK]++;
            if (gBattleMons[gEffectBank].statStages[STAT_STAGE_ATK] != 13)
                gBattleMons[gEffectBank].statStages[STAT_STAGE_ATK]++;
			BattleScriptPushCursor();
			gBattlescriptCurrInstr = BattleScript_DefiantProc;
            PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_STAGE_ATK);
        }
        else if (gBattleMons[gEffectBank].ability == ABILITY_COMPETITIVE &&
            gBattleMons[gEffectBank].statStages[STAT_STAGE_SPATK] != 13)
        {
            gBattleMons[gEffectBank].statStages[STAT_STAGE_SPATK]++;
            if (gBattleMons[gEffectBank].statStages[STAT_STAGE_SPATK] != 13)
                gBattleMons[gEffectBank].statStages[STAT_STAGE_SPATK]++;
			BattleScriptPushCursor();
			gBattlescriptCurrInstr = BattleScript_CompetitiveProc;
            PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_STAGE_SPATK);
        }
    }
}

static void sp42_checkdefiantwebs(void)
{
    if (gBattleMons[gEffectBank].ability == ABILITY_DEFIANT &&
        gBattleMons[gEffectBank].statStages[STAT_STAGE_ATK] != 13)
    {
        gBattleMons[gEffectBank].statStages[STAT_STAGE_ATK]++;
        if (gBattleMons[gEffectBank].statStages[STAT_STAGE_ATK] != 13)
            gBattleMons[gEffectBank].statStages[STAT_STAGE_ATK]++;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_DefiantProc;
        PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_STAGE_ATK);
    }
    else if (gBattleMons[gEffectBank].ability == ABILITY_COMPETITIVE &&
        gBattleMons[gEffectBank].statStages[STAT_STAGE_SPATK] != 13)
    {
        gBattleMons[gEffectBank].statStages[STAT_STAGE_SPATK]++;
        if (gBattleMons[gEffectBank].statStages[STAT_STAGE_SPATK] != 13)
            gBattleMons[gEffectBank].statStages[STAT_STAGE_SPATK]++;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_CompetitiveProc;
        PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_STAGE_SPATK);
    }
}

static void sp43_checkdefianttarget(void)
{
    gEffectBank = gBankTarget;

    if (gBattleMons[gEffectBank].ability == ABILITY_DEFIANT &&
        gBattleMons[gEffectBank].statStages[STAT_STAGE_ATK] != 13)
    {
        gBattleMons[gEffectBank].statStages[STAT_STAGE_ATK]++;
        if (gBattleMons[gEffectBank].statStages[STAT_STAGE_ATK] != 13)
            gBattleMons[gEffectBank].statStages[STAT_STAGE_ATK]++;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_DefiantProc;
        PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_STAGE_ATK);
    }
    else if (gBattleMons[gEffectBank].ability == ABILITY_COMPETITIVE &&
        gBattleMons[gEffectBank].statStages[STAT_STAGE_SPATK] != 13)
    {
        gBattleMons[gEffectBank].statStages[STAT_STAGE_SPATK]++;
        if (gBattleMons[gEffectBank].statStages[STAT_STAGE_SPATK] != 13)
            gBattleMons[gEffectBank].statStages[STAT_STAGE_SPATK]++;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_CompetitiveProc;
        PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_STAGE_SPATK);
    }
}

static void sp44_preparecatchexp(void)
{
    gBattleStruct->wildVictorySong++;
    gActiveBattler = 1;
    EmitSpriteInvisibility(0, 1);
    MarkBufferBankForExecution(gActiveBattler);
}

static void sp45_fellstingercheck(void)
{
	if(gBattleMons[gBankTarget].hp == 0)
		gBattlescriptCurrInstr = BattleScript_FellStingerKills;
}

static void sp46_finalgambit(void)
{
    if (gBattleExecBuffer)
        return;
	gActiveBattler = gBankAttacker;
    gBattleMoveDamage = gBattleMons[gActiveBattler].hp;
    EmitHealthBarUpdate(0, 0x7FFF);
    MarkBufferBankForExecution(gActiveBattler);
}

static void sp47_burnup(void)
{
	if (gBattleMons[gBankAttacker].type1 == TYPE_FIRE)
		gBattleMons[gBankAttacker].type1 = TYPE_TYPELESS;
	if (gBattleMons[gBankAttacker].type2 == TYPE_FIRE)
		gBattleMons[gBankAttacker].type2 = TYPE_TYPELESS;
}

static void sp48_lastresort(void)
{
	// Last Resort can be used if:
	// - User knows Last Resort
	// - User knows a move that is not Last Resort or an empty slot
	// And if, for every move the user knows:
	// - The move is Last Resort or --
	// - Or, the move has previously been used
	
	u8 hasLastResort = 0;
	u8 hasRealMove = 0;
	u8 hasUnusedMove = 0;
	u8 i = 0;
	
	for (i = 0; i < 4 && !hasUnusedMove; i++)
	{
		u16 move = gBattleMons[gBankAttacker].moves[i];
		
		if (move == MOVE_LAST_RESORT)
			hasLastResort = 1;
		else if (move != 0)
		{
			if (gBattleMons[gBankAttacker].usedMoves & (0x1 << i))
			{
				hasRealMove = 1;
			}
			else
			{
				hasUnusedMove = 1;
			}
		}
	}
	
	if (hasUnusedMove || !hasLastResort || !hasRealMove)
	{
		// failure
		gBattlescriptCurrInstr = BattleScript_ButItFailed;
	}
}

static void sp49_losemoney(void)
{
    // Take away some money and buffer the amount taken as a string.
    u16 highestLevel = 0;
    u8 badgeCount = 0;
    u32 moneyLoss;
    u8 i;
    
    for (i = 0; i < 6; i++)
    {
        u8 level = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL, 0);
        if (level > highestLevel)
            highestLevel = level;
    }
    for (i = 0; i < 8; i++)
    {
        if (FlagGet(FLAG_BADGE01_GET + i))
            badgeCount++;
    }
    
    moneyLoss = highestLevel * sPlayerMoneyLossConstants[badgeCount];
    
    if (moneyLoss > gSaveBlock1.money)
        moneyLoss = gSaveBlock1.money;

    RemoveMoney(&gSaveBlock1.money, moneyLoss);
    gBattleTextBuff1[0] = 0xFD;
    gBattleTextBuff1[1] = 1;
    gBattleTextBuff1[2] = 4;
    gBattleTextBuff1[3] = 5;
    gBattleTextBuff1[4] = (u8)(moneyLoss);
    gBattleTextBuff1[5] = (u8)(moneyLoss >> 8);
    gBattleTextBuff1[6] = (u8)(moneyLoss >> 16);
    gBattleTextBuff1[7] = (u8)(moneyLoss >> 24);
    gBattleTextBuff1[8] = 0xFF;
 
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    else
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
}

static void sp4A_round(void)
{
    u8 roundUsers[4] = {0, 0, 0, 0};
    u8 i;
    
    gBattleStruct->roundMarker = 1;
    
    for (i = 0; i < gBattlersCount; i++)
    {
        u8 bank = gBanksByTurnOrder[i];
        
        if (gActionsByTurnOrder[bank] != ACTION_USE_MOVE)
            continue;
        else if (!(gProtectStructs[bank].onlyStruggle) && 
			gBattleMons[bank].moves[ewram1608Carr(bank)] == MOVE_ROUND)
            roundUsers[i] = 1;
    }

    // Attacking mon is always a round user, but may not have selected round
    roundUsers[gCurrentTurnActionNumber] = 1;
    
    // Trawl list of actors.
    // Every time we find someone who is using Round, move them ahead of everyone who isn't.
    for (i = gCurrentTurnActionNumber+1; i < gBattlersCount; i++)
    {
        while (roundUsers[i] && !roundUsers[i-1])
        {
            SwapTurnOrder(i, i-1);
            roundUsers[i] = 0;
            roundUsers[i-1] = 1;
            i--;
        }
    }
}

static void sp4B_jumpkickrecoil(void)
{
    gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP / 2;
}

static void sp4C_checkexplosiontargetvalidity(void)
{
    // For explosion and self-destruct
    if (gBattleMons[gBankTarget].hp == 0)
        gBattlescriptCurrInstr = BattleScript_ExplosionLoop;
    
}

static void sp4D_endifnopowerherb(void)
{
    u8 holdEffect = ItemId_GetHoldEffect(gBattleMons[gBankAttacker].item);
    if (holdEffect != HOLD_EFFECT_POWER_HERB)
        gBattlescriptCurrInstr = BattleScript_MoveEnd;
}

// The order of this is assumed to be the same as the types
static const u16 demonbookmoves[] = {
    MOVE_TRI_ATTACK,
    MOVE_AURA_SPHERE,
    MOVE_AIR_SLASH,
    MOVE_SLUDGE_BOMB,
    MOVE_EARTH_POWER,
    MOVE_POWER_GEM,
    MOVE_BUG_BUZZ,
    MOVE_SHADOW_BALL,
    MOVE_FLASH_CANNON,
    MOVE_MOONBLAST,
    MOVE_FLAMETHROWER,
    MOVE_SURF,
    MOVE_ENERGY_BALL,
    MOVE_THUNDERBOLT,
    MOVE_PSYCHIC,
    MOVE_ICE_BEAM,
    MOVE_DRAGON_PULSE,
    MOVE_DARK_PULSE,
    0x00,
};

static void sp4E_demonbook(void)
{
    u8 i = 0;
    u16 moveUsed = 0;
    u16 highestDamage = 0;
    s32 baseDamage[18];
    u16 side_hword = gSideAffecting[GetBattlerPosition(gBankTarget) & 1];
    
    // Okay:
    // If foe is behind a sub, blow them away if possible
    if ((gBattleMons[gBankTarget].status2 & STATUS2_SUBSTITUTE) &&
        gBattleMons[gBankTarget].ability != ABILITY_SUCTION_CUPS &&
        gBattleMons[gBankTarget].ability != ABILITY_MAGIC_BOUNCE)
    {
        moveUsed = MOVE_WHIRLWIND;
        gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
        gCurrentMove = moveUsed;
        gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
        return;
    }
    
    // Use applicable OHKO if we locked on
    // (Levitate Froslass is the only way to block all of them, which is impossible but whatever)
    if (gStatuses3[gBankTarget] & STATUS3_ALWAYS_HITS && 
        gDisableStructs[gBankTarget].bankWithSureHit == gBankAttacker && 
        gBattleMons[gBankTarget].ability != ABILITY_STURDY) {
        if (gBattleMons[gBankTarget].type1 != TYPE_ICE && gBattleMons[gBankTarget].type2 != TYPE_ICE)
            moveUsed = MOVE_SHEER_COLD;
        else if (gBattleMons[gBankTarget].type1 != TYPE_GHOST && gBattleMons[gBankTarget].type2 != TYPE_GHOST)
            moveUsed = MOVE_GUILLOTINE;
        else if (gBattleMons[gBankTarget].ability != ABILITY_LEVITATE)
            moveUsed = MOVE_FISSURE;
        
        if (moveUsed != 0) {
            gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
            gCurrentMove = moveUsed;
            gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
            return;
        }
    }
    
    // Run through all of them and determine which is strongest
    for (i = 0; i < 18; i++) {
        gCurrentMove = demonbookmoves[i];
        gBattleMoveDamage = CalculateBaseDamage(&gBattleMons[gBankAttacker], &gBattleMons[gBankTarget],
                                                gCurrentMove, side_hword, 0, 0, gBankAttacker, gBankTarget);
        AI_TypeCalc(gCurrentMove, gBattleMons[gBankTarget].species, gBattleMons[gBankTarget].ability);
        baseDamage[i] = gBattleMoveDamage;
    }
    
    // Check foe's immunities
    if (gBattleMons[gBankTarget].ability == ABILITY_VOLT_ABSORB ||
        gBattleMons[gBankTarget].ability == ABILITY_MOTOR_DRIVE)
        baseDamage[TYPE_ELECTRIC] = 0;
        
    if (gBattleMons[gBankTarget].ability == ABILITY_WATER_ABSORB ||
        gBattleMons[gBankTarget].ability == ABILITY_DRY_SKIN ||
        gBattleMons[gBankTarget].ability == ABILITY_STORM_DRAIN)
        baseDamage[TYPE_WATER] = 0;
    
    if (gBattleMons[gBankTarget].ability == ABILITY_FLASH_FIRE)
        baseDamage[TYPE_FIRE] = 0;
    
    if (gBattleMons[gBankTarget].ability == ABILITY_SAP_SIPPER)
        baseDamage[TYPE_GRASS] = 0;
    
    if (gBattleMons[gBankTarget].ability == ABILITY_LEVITATE)
        baseDamage[TYPE_GROUND] = 0;
    
    // we can mostly ignore wonder guard since type effectiveness should push up a super-effective move

    // Pick the move with the highest damage
    for (i = 0; i < 18; i++) {
        if (baseDamage[i] > highestDamage) {
            highestDamage = baseDamage[i];
            moveUsed = demonbookmoves[i];
        }
    }
    
    // we somehow didn't find a move?
    if (moveUsed == 0)
        moveUsed = demonbookmoves[Random() % 18];
    
    gBattleMoveDamage = 0;
    gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
    gCurrentMove = moveUsed;
    gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
}

static void sp4F_forcewin(void)
{
    u32 zero = 0;
    u8 i = 0;
    gBattleMons[0].hp = 0;
    for (i = 0; i < 6; i++)
        SetMonData(&gPlayerParty[i], MON_DATA_HP, &zero);
}

static void sp50_usegun(void)
{
    gBankTarget = 0;
    gBattleMoveDamage = gBattleMons[gBankTarget].hp;
    gHitMarker = HITMARKER_IGNORE_SUBSTITUTE;
    gMoveResultFlags = MOVE_RESULT_SUPER_EFFECTIVE;
}

static void sp51_usexnihilo(void)
{
    gBankTarget = 0;
    gBattleMons[0].statStages[STAT_STAGE_ATK] = 0;
    gBattleMons[0].statStages[STAT_STAGE_DEF] = 0;
    gBattleMons[0].statStages[STAT_STAGE_SPATK] = 0;
    gBattleMons[0].statStages[STAT_STAGE_SPATK] = 0;
    gBattleMons[0].statStages[STAT_STAGE_SPEED] = 0;
    gBattleMons[0].statStages[STAT_STAGE_ACC] = 0;
    gBattleMons[0].statStages[STAT_STAGE_EVASION] = 0;
}

static void sp52_usemaxrevive(void)
{
    // pick a random fainted mon in the party to revive
    u32 hp = 0;
    u8 bitMask = 0;
    u8 numFainted = 0;
    u8 target = 0;
    u8 i = 0;
    u16 species = 0;
    
    for (i = 0; i < 6; i++)
    {
        if (GetMonData(&gEnemyParty[i], MON_DATA_HP) == 0)
        {
            bitMask |= (1 << i);
            numFainted++;
        }
    }
    
    if (numFainted == 0) // impossible??
        return;
    
    target = Random() % numFainted;
    
    for (i = 0; i < 6; i++)
    {
        if (bitMask & 0x1)
        {
            if (target == 0)
                break;
            else
                target--;
        }
        
        bitMask = bitMask >> 1;
    }
    
    target = i;
    hp = GetMonData(&gEnemyParty[target], MON_DATA_MAX_HP);
    SetMonData(&gEnemyParty[target], MON_DATA_HP, &hp);
    
    species = GetMonData(&gEnemyParty[target], MON_DATA_SPECIES);
    
    gBattleTextBuff1[0] = 0xFD;
    gBattleTextBuff1[1] = 6;
    gBattleTextBuff1[2] = (species);
    gBattleTextBuff1[3] = uBYTE1_16(species);
    gBattleTextBuff1[4] = 0xFF;
    
}
