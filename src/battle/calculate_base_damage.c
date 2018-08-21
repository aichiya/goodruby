#include "global.h"
#include "constants/abilities.h"
#include "constants/battle_move_effects.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "battle.h"
#include "berry.h"
#include "data2.h"
#include "event_data.h"
#include "item.h"
#include "pokemon.h"
#include "ewram.h"

extern u16 gBattleTypeFlags;
extern struct BattlePokemon gBattleMons[4];
extern u16 gCurrentMove;
extern u8 gCritMultiplier;
extern u16 gBattleWeather;
extern struct BattleEnigmaBerry gEnigmaBerries[];
extern u16 gBattleMovePower;
extern u16 gTrainerBattleOpponent;

// Masks for getting PP Up count, also PP Max values
const u8 gPPUpReadMasks[] = {0x03, 0x0c, 0x30, 0xc0};

// Masks for setting PP Up count
const u8 gPPUpWriteMasks[] = {0xFC, 0xF3, 0xCF, 0x3F};

// Values added to PP Up count
const u8 gPPUpValues[] = {0x01, 0x04, 0x10, 0x40};

const u8 gStatStageRatios[][2] =
{
    {10, 40}, // -6
    {10, 35}, // -5
    {10, 30}, // -4
    {10, 25}, // -3
    {10, 20}, // -2
    {10, 15}, // -1
    {10, 10}, //  0
    {15, 10}, //  1
    {20, 10}, //  2
    {25, 10}, //  3
    {30, 10}, //  4
    {35, 10}, //  5
    {40, 10}  //  6
};

const u8 unknownGameFreakAbbrev_820825E[] = _("ゲーフリ");

const u8 gHoldEffectToType[][2] =
{
    {HOLD_EFFECT_BUG_POWER,      TYPE_BUG},
    {HOLD_EFFECT_STEEL_POWER,    TYPE_STEEL},
    {HOLD_EFFECT_GROUND_POWER,   TYPE_GROUND},
    {HOLD_EFFECT_ROCK_POWER,     TYPE_ROCK},
    {HOLD_EFFECT_GRASS_POWER,    TYPE_GRASS},
    {HOLD_EFFECT_DARK_POWER,     TYPE_DARK},
    {HOLD_EFFECT_FIGHTING_POWER, TYPE_FIGHTING},
    {HOLD_EFFECT_ELECTRIC_POWER, TYPE_ELECTRIC},
    {HOLD_EFFECT_WATER_POWER,    TYPE_WATER},
    {HOLD_EFFECT_FLYING_POWER,   TYPE_FLYING},
    {HOLD_EFFECT_POISON_POWER,   TYPE_POISON},
    {HOLD_EFFECT_ICE_POWER,      TYPE_ICE},
    {HOLD_EFFECT_GHOST_POWER,    TYPE_GHOST},
    {HOLD_EFFECT_PSYCHIC_POWER,  TYPE_PSYCHIC},
    {HOLD_EFFECT_FIRE_POWER,     TYPE_FIRE},
    {HOLD_EFFECT_DRAGON_POWER,   TYPE_DRAGON},
    {HOLD_EFFECT_NORMAL_POWER,   TYPE_NORMAL}
};

u8 GetBattlerSide(u8 bank);

#define APPLY_STAT_MOD(var, mon, stat, statMod)                                     \
{                                                                                   \
    (var) = (stat) * (gStatStageRatios)[statMod][0];                                \
    (var) /= (gStatStageRatios)[statMod][1];                                        \
}

s32 CalculateBaseDamage(struct BattlePokemon *attacker, struct BattlePokemon *defender, u32 move, u16 sideStatus, u16 powerOverride, u8 typeOverride, u8 bankAtk, u8 bankDef)
{
    u32 i;
    s32 damage = 0;
    s32 damageHelper;
    u8 type, moveClass;
    u16 attack, defense;
    u16 spAttack, spDefense;
    u8 attackMod, defenseMod;
    u8 defenderHoldEffect;
    u8 defenderHoldEffectParam;
    u8 attackerHoldEffect;
    u8 attackerHoldEffectParam;
	u8 defenderAbility;

    if (!powerOverride)
        gBattleMovePower = gBattleMoves[move].power;
    else
        gBattleMovePower = powerOverride;

    if (!typeOverride)
        type = gBattleMoves[move].type;
    else
        type = typeOverride & 0x3F;

    moveClass = gBattleMoves[move].moveClass;

    attack = attacker->attack;
    defense = defender->defense;
    spAttack = attacker->spAttack;
    spDefense = defender->spDefense;
	
	if (move == MOVE_FOUL_PLAY)
		attack = defender->attack;

    if (attacker->item == ITEM_ENIGMA_BERRY)
    {
        attackerHoldEffect = gEnigmaBerries[bankAtk].holdEffect;
        attackerHoldEffectParam = gEnigmaBerries[bankAtk].holdEffectParam;
    }
    else
    {
        attackerHoldEffect = ItemId_GetHoldEffect(attacker->item);
        attackerHoldEffectParam = ItemId_GetHoldEffectParam(attacker->item);
    }

    if (defender->item == ITEM_ENIGMA_BERRY)
    {
        defenderHoldEffect = gEnigmaBerries[bankDef].holdEffect;
        defenderHoldEffectParam = gEnigmaBerries[bankDef].holdEffectParam;
    }
    else
    {
        defenderHoldEffect = ItemId_GetHoldEffect(defender->item);
        defenderHoldEffectParam = ItemId_GetHoldEffectParam(defender->item);
    }
	
	defenderAbility = defender->ability;
	if (attacker->ability == ABILITY_MOLD_BREAKER)
		defenderAbility = 0;

    if (attacker->ability == ABILITY_HUGE_POWER || attacker->ability == ABILITY_PURE_POWER)
        attack *= 2;

    if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_EREADER_TRAINER)))
    {
        if ((gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            && gTrainerBattleOpponent != 1024
            && FlagGet(FLAG_BADGE01_GET)
            && !GetBattlerSide(bankAtk))
            attack = (110 * attack) / 100;
    }
    if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_EREADER_TRAINER)))
    {
        if ((gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            && gTrainerBattleOpponent != 1024
            && FlagGet(FLAG_BADGE05_GET)
            && !GetBattlerSide(bankDef))
            defense = (110 * defense) / 100;
    }
    if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_EREADER_TRAINER)))
    {
        if ((gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            && gTrainerBattleOpponent != 1024
            && FlagGet(FLAG_BADGE07_GET)
            && !GetBattlerSide(bankAtk))
            spAttack = (110 * spAttack) / 100;
    }
    if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_EREADER_TRAINER)))
    {
        if ((gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            && gTrainerBattleOpponent != 1024
            && FlagGet(FLAG_BADGE07_GET)
            && !GetBattlerSide(bankDef))
            spDefense = (110 * spDefense) / 100;
    }

    for (i = 0; i < 17; i++)
    {
        if (attackerHoldEffect == gHoldEffectToType[i][0]
            && type == gHoldEffectToType[i][1])
        {
            attack = (attack * (attackerHoldEffectParam + 100)) / 100;
            spAttack = (spAttack * (attackerHoldEffectParam + 100)) / 100;
            break;
        }
    }

    if (attackerHoldEffect == HOLD_EFFECT_CHOICE_BAND)
        attack = (150 * attack) / 100;
    if (attackerHoldEffect == HOLD_EFFECT_SOUL_DEW && !(gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER) && (attacker->species == SPECIES_LATIAS || attacker->species == SPECIES_LATIOS))
        spAttack = (150 * spAttack) / 100;
    if (defenderHoldEffect == HOLD_EFFECT_SOUL_DEW && !(gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER) && (defender->species == SPECIES_LATIAS || defender->species == SPECIES_LATIOS))
        spDefense = (150 * spDefense) / 100;
    if (attackerHoldEffect == HOLD_EFFECT_DEEP_SEA_TOOTH && attacker->species == SPECIES_CLAMPERL)
        spAttack *= 2;
    if (defenderHoldEffect == HOLD_EFFECT_DEEP_SEA_SCALE && defender->species == SPECIES_CLAMPERL)
        spDefense *= 2;
    if (attackerHoldEffect == HOLD_EFFECT_LIGHT_BALL && attacker->species == SPECIES_PIKACHU)
        spAttack *= 2;
    if (defenderHoldEffect == HOLD_EFFECT_METAL_POWDER && defender->species == SPECIES_DITTO)
        defense *= 2;
    if (attackerHoldEffect == HOLD_EFFECT_THICK_CLUB && (attacker->species == SPECIES_CUBONE || attacker->species == SPECIES_MAROWAK))
        attack *= 2;
    if (defenderAbility == ABILITY_THICK_FAT && (type == TYPE_FIRE || type == TYPE_ICE))
    {
        attack /= 2;
        spAttack /= 2;
    }
    if (attacker->ability == ABILITY_HUSTLE)
        attack = (150 * attack) / 100;
    if (attacker->ability == ABILITY_PLUS && AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, 0, ABILITY_MINUS, 0, 0))
        spAttack = (150 * spAttack) / 100;
    if (attacker->ability == ABILITY_MINUS && AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, 0, ABILITY_PLUS, 0, 0))
        spAttack = (150 * spAttack) / 100;
    if (attacker->ability == ABILITY_GUTS && attacker->status1)
        attack = (150 * attack) / 100;
    if (defenderAbility == ABILITY_MARVEL_SCALE && defender->status1)
        defense = (150 * defense) / 100;
    if (type == TYPE_ELECTRIC && AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, 0, 0, 0xFD, 0))
        gBattleMovePower /= 2;
    if (type == TYPE_FIRE && AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, 0, 0, 0xFE, 0))
        gBattleMovePower /= 2;
    if (type == TYPE_GRASS && attacker->ability == ABILITY_OVERGROW && attacker->hp <= (attacker->maxHP / 3))
        gBattleMovePower = (150 * gBattleMovePower) / 100;
    if (type == TYPE_FIRE && attacker->ability == ABILITY_BLAZE && attacker->hp <= (attacker->maxHP / 3))
        gBattleMovePower = (150 * gBattleMovePower) / 100;
    if (type == TYPE_WATER && attacker->ability == ABILITY_TORRENT && attacker->hp <= (attacker->maxHP / 3))
        gBattleMovePower = (150 * gBattleMovePower) / 100;
    if (type == TYPE_BUG && attacker->ability == ABILITY_SWARM && attacker->hp <= (attacker->maxHP / 3))
        gBattleMovePower = (150 * gBattleMovePower) / 100;
    if (gBattleMoves[gCurrentMove].effect == EFFECT_EXPLOSION)
        defense /= 2;

	if (gCurrentMove == MOVE_VENOSHOCK && defender->status1 & (STATUS_POISON | STATUS_TOXIC_POISON))
		spAttack *= 2;
	if (gCurrentMove == MOVE_BRINE && defender->hp *2 <= defender->maxHP)
		spAttack *= 2;
	if (gCurrentMove == MOVE_HEX && defender->status1)
		spAttack *= 2;
    
    if (moveClass == 0)
    {
        attack = attack;
        defense = defense;
        attackMod = attacker->statStages[STAT_STAGE_ATK];
        defenseMod = defender->statStages[STAT_STAGE_DEF];
		
		if (move == MOVE_FOUL_PLAY)
			attackMod = defender->statStages[STAT_STAGE_ATK];
        
        if ((sideStatus & SIDE_STATUS_REFLECT) && gCritMultiplier == 1)
        {
            if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE) && CountAliveMons(2) == 2)
                defense = (defense * 3) / 2;
            else
                defense *= 2;
        }
        
        if ((attacker->status1 & STATUS_BURN) && attacker->ability != ABILITY_GUTS && gCurrentMove != MOVE_FACADE)
            attack /= 2;
    }
    else if (moveClass == 1)
    {
        attack = spAttack;
        defense = spDefense;
        attackMod = attacker->statStages[STAT_STAGE_SPATK];
        defenseMod = defender->statStages[STAT_STAGE_SPDEF];
		
		if (move == MOVE_PSYSHOCK)
		{
			defense = defense;
			defenseMod = defender->statStages[STAT_STAGE_DEF];
		}
        
        if ((sideStatus & SIDE_STATUS_LIGHTSCREEN) && gCritMultiplier == 1)
        {
            if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE) && CountAliveMons(2) == 2)
                defense = (defense * 3) / 2;
            else
                defense *= 2;
        }
    }
	
	if (gCurrentMove == MOVE_CHIP_AWAY)
		defenseMod = 6;

    if (gCritMultiplier == 2)
    {
        if (attackMod > 6)
            APPLY_STAT_MOD(damage, attacker, attack, attackMod)
        else
            damage = attack;
    }
    else
        APPLY_STAT_MOD(damage, attacker, attack, attackMod)

    damage = damage * gBattleMovePower;
    damage *= (2 * attacker->level / 5 + 2);

    if (gCritMultiplier == 2)
    {
        if (defenseMod < 6)
            APPLY_STAT_MOD(damageHelper, defender, defense, defenseMod)
        else
            damageHelper = defense;
    }
    else
        APPLY_STAT_MOD(damageHelper, defender, defense, defenseMod)

    damage = damage / damageHelper;
    damage /= 50;
    
    // are effects of weather negated with cloud nine or air lock
    if (!AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, 0, ABILITY_CLOUD_NINE, 0, 0)
        && !AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, 0, ABILITY_AIR_LOCK, 0, 0))
    {
        if (gBattleWeather & WEATHER_RAIN_TEMPORARY)
        {
            switch (type)
            {
            case TYPE_FIRE:
                damage /= 2;
                break;
            case TYPE_WATER:
                damage = (15 * damage) / 10;
                break;
            }
        }

        // any weather except sun weakens solar beam
        if ((gBattleWeather & (WEATHER_RAIN_ANY | WEATHER_SANDSTORM_ANY | WEATHER_HAIL)) && gCurrentMove == MOVE_SOLAR_BEAM)
            damage /= 2;

        // sunny
        if (gBattleWeather & WEATHER_SUN_ANY)
        {
            switch (type)
            {
            case TYPE_FIRE:
                damage = (15 * damage) / 10;
                break;
            case TYPE_WATER:
                damage /= 2;
                break;
            }
			
			if (attacker->ability == ABILITY_SOLAR_POWER && moveClass == 1)
				damage = (15 * damage) / 10;
        }
        
        // sand
        if (gBattleWeather & WEATHER_SANDSTORM_ANY && moveClass == 1 && (defender->type1 == TYPE_ROCK || defender->type2 == TYPE_ROCK))
        {
            damage = (10 * damage) / 15;
        }
    }
    
    // flash fire triggered
    if ((eFlashFireArr.arr[bankAtk] & 1) && type == TYPE_FIRE)
        damage = (15 * damage) / 10;
	
	// me first bonus
	if (gBattleStruct->meFirstTracker)
		damage = (15 * damage) / 10;

    // spread move penalty
    if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE) && (gBattleMoves[move].target == 8 || gBattleMoves[move].target == 32) && CountAliveMons(2) == 2)
        damage = (3 * damage) / 4;

     // moves always do at least 1 damage.
    if (damage == 0)
        damage = 1;

    return damage + 2;
}
