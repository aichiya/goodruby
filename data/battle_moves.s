#include "constants/battle_constants.h"
#include "constants/battle_move_effects.h"
	.include "include/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gBattleMoves:: @ 81FB12C
@ NONE
	.byte EFFECT_HIT
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 0 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ POUND
	.byte EFFECT_HIT
	.byte 40 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 35 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ KARATE_CHOP
	.byte EFFECT_HIGH_CRITICAL
	.byte 50 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 25 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ DOUBLE_SLAP
	.byte EFFECT_MULTI_HIT
	.byte 15 @ power
	.byte TYPE_NORMAL
	.byte 85 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ COMET_PUNCH
	.byte EFFECT_MULTI_HIT
	.byte 18 @ power
	.byte TYPE_NORMAL
	.byte 85 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ MEGA_PUNCH
	.byte EFFECT_HIT
	.byte 80 @ power
	.byte TYPE_NORMAL
	.byte 85 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ PAY_DAY
	.byte EFFECT_PAY_DAY
	.byte 40 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ FIRE_PUNCH
	.byte EFFECT_BURN_HIT
	.byte 75 @ power
	.byte TYPE_FIRE
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ ICE_PUNCH
	.byte EFFECT_FREEZE_HIT
	.byte 75 @ power
	.byte TYPE_ICE
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ THUNDER_PUNCH
	.byte EFFECT_PARALYZE_HIT
	.byte 75 @ power
	.byte TYPE_ELECTRIC
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SCRATCH
	.byte EFFECT_HIT
	.byte 40 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 35 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ VICE_GRIP
	.byte EFFECT_HIT
	.byte 55 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ GUILLOTINE
	.byte EFFECT_OHKO
	.byte 1 @ power
	.byte TYPE_NORMAL
	.byte 30 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ RAZOR_WIND
	.byte EFFECT_RAZOR_WIND
	.byte 80 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ SWORDS_DANCE
	.byte EFFECT_ATTACK_UP_2
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ CUT
	.byte EFFECT_HIT
	.byte 50 @ power
	.byte TYPE_NORMAL
	.byte 95 @ accuracy
	.byte 30 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ GUST
	.byte EFFECT_GUST
	.byte 40 @ power
	.byte TYPE_FLYING
	.byte 100 @ accuracy
	.byte 35 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ WING_ATTACK
	.byte EFFECT_HIT
	.byte 60 @ power
	.byte TYPE_FLYING
	.byte 100 @ accuracy
	.byte 35 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ WHIRLWIND
	.byte EFFECT_ROAR
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte -6 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ FLY
	.byte EFFECT_FLY
	.byte 90 @ power
	.byte TYPE_FLYING
	.byte 95 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ BIND
	.byte EFFECT_TRAP
	.byte 15 @ power
	.byte TYPE_NORMAL
	.byte 85 @ accuracy
	.byte 20 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SLAM
	.byte EFFECT_HIT
	.byte 80 @ power
	.byte TYPE_NORMAL
	.byte 75 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ VINE_WHIP
	.byte EFFECT_HIT
	.byte 45 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 25 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ STOMP
	.byte EFFECT_FLINCH_HIT_2
	.byte 65 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 30 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ DOUBLE_KICK
	.byte EFFECT_DOUBLE_HIT
	.byte 30 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ MEGA_KICK
	.byte EFFECT_HIT
	.byte 120 @ power
	.byte TYPE_NORMAL
	.byte 75 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ JUMP_KICK
	.byte EFFECT_RECOIL_IF_MISS
	.byte 100 @ power
	.byte TYPE_FIGHTING
	.byte 95 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ ROLLING_KICK
	.byte EFFECT_FLINCH_HIT
	.byte 60 @ power
	.byte TYPE_FIGHTING
	.byte 85 @ accuracy
	.byte 15 @ PP
	.byte 30 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SAND_ATTACK
	.byte EFFECT_ACCURACY_DOWN
	.byte 0 @ power
	.byte TYPE_GROUND
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ HEADBUTT
	.byte EFFECT_FLINCH_HIT
	.byte 70 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 30 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ HORN_ATTACK
	.byte EFFECT_HIT
	.byte 65 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 25 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ FURY_ATTACK
	.byte EFFECT_MULTI_HIT
	.byte 15 @ power
	.byte TYPE_NORMAL
	.byte 85 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ HORN_DRILL
	.byte EFFECT_OHKO
	.byte 1 @ power
	.byte TYPE_NORMAL
	.byte 30 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ TACKLE
	.byte EFFECT_HIT
	.byte 40 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 35 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ BODY_SLAM
	.byte EFFECT_PARALYZE_HIT
	.byte 85 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 30 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ WRAP
	.byte EFFECT_TRAP
	.byte 15 @ power
	.byte TYPE_NORMAL
	.byte 90 @ accuracy
	.byte 20 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ TAKE_DOWN
	.byte EFFECT_RECOIL
	.byte 90 @ power
	.byte TYPE_NORMAL
	.byte 85 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ THRASH
	.byte EFFECT_RAMPAGE
	.byte 120 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_RANDOM
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ DOUBLE_EDGE
	.byte EFFECT_DOUBLE_EDGE
	.byte 120 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ TAIL_WHIP
	.byte EFFECT_DEFENSE_DOWN
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ POISON_STING
	.byte EFFECT_POISON_HIT
	.byte 15 @ power
	.byte TYPE_POISON
	.byte 100 @ accuracy
	.byte 35 @ PP
	.byte 30 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ TWINEEDLE
	.byte EFFECT_TWINEEDLE
	.byte 25 @ power
	.byte TYPE_BUG
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 20 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ PIN_MISSILE
	.byte EFFECT_MULTI_HIT
	.byte 25 @ power
	.byte TYPE_BUG
	.byte 95 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ LEER
	.byte EFFECT_DEFENSE_DOWN
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ BITE
	.byte EFFECT_FLINCH_HIT
	.byte 60 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 25 @ PP
	.byte 30 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT | F_BITING @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ GROWL
	.byte EFFECT_ATTACK_DOWN
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 40 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ ROAR
	.byte EFFECT_ROAR
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte -6 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ SING
	.byte EFFECT_SLEEP
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 55 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ SUPERSONIC
	.byte EFFECT_CONFUSE
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 55 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ SONIC_BOOM
	.byte EFFECT_SONICBOOM
	.byte 1 @ power
	.byte TYPE_NORMAL
	.byte 90 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ DISABLE
	.byte EFFECT_DISABLE
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ ACID
	.byte EFFECT_SPECIAL_DEFENSE_DOWN_HIT
	.byte 40 @ power
	.byte TYPE_POISON
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ EMBER
	.byte EFFECT_BURN_HIT
	.byte 40 @ power
	.byte TYPE_FIRE
	.byte 100 @ accuracy
	.byte 25 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ FLAMETHROWER
	.byte EFFECT_BURN_HIT
	.byte 90 @ power
	.byte TYPE_FIRE
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ MIST
	.byte EFFECT_MIST
	.byte 0 @ power
	.byte TYPE_ICE
	.byte 0 @ accuracy
	.byte 30 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ WATER_GUN
	.byte EFFECT_HIT
	.byte 40 @ power
	.byte TYPE_WATER
	.byte 100 @ accuracy
	.byte 25 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ HYDRO_PUMP
	.byte EFFECT_HIT
	.byte 110 @ power
	.byte TYPE_WATER
	.byte 80 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ SURF
	.byte EFFECT_HIT
	.byte 90 @ power
	.byte TYPE_WATER
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ ICE_BEAM
	.byte EFFECT_FREEZE_HIT
	.byte 90 @ power
	.byte TYPE_ICE
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ BLIZZARD
	.byte EFFECT_FREEZE_HIT
	.byte 110 @ power
	.byte TYPE_ICE
	.byte 70 @ accuracy
	.byte 5 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ PSYBEAM
	.byte EFFECT_CONFUSE_HIT
	.byte 65 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ BUBBLE_BEAM
	.byte EFFECT_SPEED_DOWN_HIT
	.byte 65 @ power
	.byte TYPE_WATER
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ AURORA_BEAM
	.byte EFFECT_ATTACK_DOWN_HIT
	.byte 65 @ power
	.byte TYPE_ICE
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ HYPER_BEAM
	.byte EFFECT_RECHARGE
	.byte 150 @ power
	.byte TYPE_NORMAL
	.byte 90 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ PECK
	.byte EFFECT_HIT
	.byte 35 @ power
	.byte TYPE_FLYING
	.byte 100 @ accuracy
	.byte 35 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ DRILL_PECK
	.byte EFFECT_HIT
	.byte 80 @ power
	.byte TYPE_FLYING
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SUBMISSION
	.byte EFFECT_RECOIL
	.byte 80 @ power
	.byte TYPE_FIGHTING
	.byte 80 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ LOW_KICK
	.byte EFFECT_LOW_KICK
	.byte 1 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ COUNTER
	.byte EFFECT_COUNTER
	.byte 1 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SPECIAL
	.byte -5 @ priority
	.byte F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SEISMIC_TOSS
	.byte EFFECT_LEVEL_DAMAGE
	.byte 1 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ STRENGTH
	.byte EFFECT_HIT
	.byte 80 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ ABSORB
	.byte EFFECT_ABSORB
	.byte 20 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 25 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ MEGA_DRAIN
	.byte EFFECT_ABSORB
	.byte 40 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ LEECH_SEED
	.byte EFFECT_LEECH_SEED
	.byte 0 @ power
	.byte TYPE_GRASS
	.byte 90 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ GROWTH
	.byte EFFECT_SPECIAL_ATTACK_UP
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ RAZOR_LEAF
	.byte EFFECT_HIGH_CRITICAL
	.byte 55 @ power
	.byte TYPE_GRASS
	.byte 95 @ accuracy
	.byte 25 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SOLAR_BEAM
	.byte EFFECT_SOLARBEAM
	.byte 120 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ POISON_POWDER
	.byte EFFECT_POISON
	.byte 0 @ power
	.byte TYPE_POISON
	.byte 75 @ accuracy
	.byte 35 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ STUN_SPORE
	.byte EFFECT_PARALYZE
	.byte 0 @ power
	.byte TYPE_GRASS
	.byte 75 @ accuracy
	.byte 30 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ SLEEP_POWDER
	.byte EFFECT_SLEEP
	.byte 0 @ power
	.byte TYPE_GRASS
	.byte 75 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ PETAL_DANCE
	.byte EFFECT_RAMPAGE
	.byte 120 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_RANDOM
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ STRING_SHOT
	.byte EFFECT_SPEED_DOWN
	.byte 0 @ power
	.byte TYPE_BUG
	.byte 95 @ accuracy
	.byte 40 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ DRAGON_RAGE
	.byte EFFECT_DRAGON_RAGE
	.byte 1 @ power
	.byte TYPE_DRAGON
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ FIRE_SPIN
	.byte EFFECT_TRAP
	.byte 35 @ power
	.byte TYPE_FIRE
	.byte 70 @ accuracy
	.byte 15 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ THUNDER_SHOCK
	.byte EFFECT_PARALYZE_HIT
	.byte 40 @ power
	.byte TYPE_ELECTRIC
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ THUNDERBOLT
	.byte EFFECT_PARALYZE_HIT
	.byte 90 @ power
	.byte TYPE_ELECTRIC
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ THUNDER_WAVE
	.byte EFFECT_PARALYZE
	.byte 0 @ power
	.byte TYPE_ELECTRIC
	.byte 90 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ THUNDER
	.byte EFFECT_THUNDER
	.byte 110 @ power
	.byte TYPE_ELECTRIC
	.byte 70 @ accuracy
	.byte 10 @ PP
	.byte 30 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ ROCK_THROW
	.byte EFFECT_HIT
	.byte 50 @ power
	.byte TYPE_ROCK
	.byte 90 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ EARTHQUAKE
	.byte EFFECT_EARTHQUAKE
	.byte 100 @ power
	.byte TYPE_GROUND
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_ALL_EXCEPT_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ FISSURE
	.byte EFFECT_OHKO
	.byte 1 @ power
	.byte TYPE_GROUND
	.byte 30 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ DIG
	.byte EFFECT_FLY
	.byte 80 @ power
	.byte TYPE_GROUND
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ TOXIC
	.byte EFFECT_TOXIC
	.byte 0 @ power
	.byte TYPE_POISON
	.byte 90 @ accuracy
	.byte 10 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ CONFUSION
	.byte EFFECT_CONFUSE_HIT
	.byte 50 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 25 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ PSYCHIC
	.byte EFFECT_SPECIAL_DEFENSE_DOWN_HIT
	.byte 90 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ HYPNOSIS
	.byte EFFECT_SLEEP
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 60 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ MEDITATE
	.byte EFFECT_ATTACK_UP
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 0 @ accuracy
	.byte 40 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ AGILITY
	.byte EFFECT_SPEED_UP_2
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 0 @ accuracy
	.byte 30 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ QUICK_ATTACK
	.byte EFFECT_QUICK_ATTACK
	.byte 40 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 1 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ RAGE
	.byte EFFECT_RAGE
	.byte 20 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ TELEPORT
	.byte EFFECT_TELEPORT
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ NIGHT_SHADE
	.byte EFFECT_LEVEL_DAMAGE
	.byte 1 @ power
	.byte TYPE_GHOST
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ MIMIC
	.byte EFFECT_MIMIC
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ SCREECH
	.byte EFFECT_DEFENSE_DOWN_2
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 85 @ accuracy
	.byte 40 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ DOUBLE_TEAM
	.byte EFFECT_EVASION_UP
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ RECOVER
	.byte EFFECT_RESTORE_HP
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ HARDEN
	.byte EFFECT_DEFENSE_UP
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 30 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ MINIMIZE
	.byte EFFECT_MINIMIZE
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ SMOKESCREEN
	.byte EFFECT_ACCURACY_DOWN
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ CONFUSE_RAY
	.byte EFFECT_CONFUSE
	.byte 0 @ power
	.byte TYPE_GHOST
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ WITHDRAW
	.byte EFFECT_DEFENSE_UP
	.byte 0 @ power
	.byte TYPE_WATER
	.byte 0 @ accuracy
	.byte 40 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ DEFENSE_CURL
	.byte EFFECT_DEFENSE_CURL
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 40 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ BARRIER
	.byte EFFECT_DEFENSE_UP_2
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ LIGHT_SCREEN
	.byte EFFECT_LIGHT_SCREEN
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 0 @ accuracy
	.byte 30 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ HAZE
	.byte EFFECT_HAZE
	.byte 0 @ power
	.byte TYPE_ICE
	.byte 0 @ accuracy
	.byte 30 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ REFLECT
	.byte EFFECT_REFLECT
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ FOCUS_ENERGY
	.byte EFFECT_FOCUS_ENERGY
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 30 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ BIDE
	.byte EFFECT_BIDE
	.byte 1 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 1 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ METRONOME
	.byte EFFECT_METRONOME
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SPECIAL
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ MIRROR_MOVE
	.byte EFFECT_MIRROR_MOVE
	.byte 0 @ power
	.byte TYPE_FLYING
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SPECIAL
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ SELF_DESTRUCT
	.byte EFFECT_EXPLOSION
	.byte 200 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_ALL_EXCEPT_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ EGG_BOMB
	.byte EFFECT_HIT
	.byte 100 @ power
	.byte TYPE_NORMAL
	.byte 75 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ LICK
	.byte EFFECT_PARALYZE_HIT
	.byte 30 @ power
	.byte TYPE_GHOST
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 30 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SMOG
	.byte EFFECT_POISON_HIT
	.byte 30 @ power
	.byte TYPE_POISON
	.byte 70 @ accuracy
	.byte 20 @ PP
	.byte 40 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ SLUDGE
	.byte EFFECT_POISON_HIT
	.byte 65 @ power
	.byte TYPE_POISON
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 30 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ BONE_CLUB
	.byte EFFECT_FLINCH_HIT
	.byte 65 @ power
	.byte TYPE_GROUND
	.byte 85 @ accuracy
	.byte 20 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ FIRE_BLAST
	.byte EFFECT_BURN_HIT
	.byte 110 @ power
	.byte TYPE_FIRE
	.byte 85 @ accuracy
	.byte 5 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ WATERFALL
	.byte EFFECT_FLINCH_HIT
	.byte 80 @ power
	.byte TYPE_WATER
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 20 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ CLAMP
	.byte EFFECT_TRAP
	.byte 35 @ power
	.byte TYPE_WATER
	.byte 85 @ accuracy
	.byte 15 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SWIFT
	.byte EFFECT_ALWAYS_HIT
	.byte 60 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ SKULL_BASH
	.byte EFFECT_SKULL_BASH
	.byte 130 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SPIKE_CANNON
	.byte EFFECT_MULTI_HIT
	.byte 20 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ CONSTRICT
	.byte EFFECT_SPEED_DOWN_HIT
	.byte 10 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 35 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ AMNESIA
	.byte EFFECT_SPECIAL_DEFENSE_UP_2
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ KINESIS
	.byte EFFECT_ACCURACY_DOWN
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 80 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ SOFT_BOILED
	.byte EFFECT_SOFTBOILED
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ HI_JUMP_KICK
	.byte EFFECT_RECOIL_IF_MISS
	.byte 130 @ power
	.byte TYPE_FIGHTING
	.byte 90 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ GLARE
	.byte EFFECT_PARALYZE
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ DREAM_EATER
	.byte EFFECT_DREAM_EATER
	.byte 100 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ POISON_GAS
	.byte EFFECT_POISON
	.byte 0 @ power
	.byte TYPE_POISON
	.byte 90 @ accuracy
	.byte 40 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ BARRAGE
	.byte EFFECT_MULTI_HIT
	.byte 15 @ power
	.byte TYPE_NORMAL
	.byte 85 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ LEECH_LIFE
	.byte EFFECT_ABSORB
	.byte 80 @ power
	.byte TYPE_BUG
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ LOVELY_KISS
	.byte EFFECT_SLEEP
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 75 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ SKY_ATTACK
	.byte EFFECT_SKY_ATTACK
	.byte 140 @ power
	.byte TYPE_FLYING
	.byte 90 @ accuracy
	.byte 5 @ PP
	.byte 30 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ TRANSFORM
	.byte EFFECT_TRANSFORM
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ BUBBLE
	.byte EFFECT_SPEED_DOWN_HIT
	.byte 40 @ power
	.byte TYPE_WATER
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ DIZZY_PUNCH
	.byte EFFECT_CONFUSE_HIT
	.byte 70 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 20 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SPORE
	.byte EFFECT_SLEEP
	.byte 0 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ FLASH
	.byte EFFECT_ACCURACY_DOWN
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ PSYWAVE
	.byte EFFECT_PSYWAVE
	.byte 1 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ SPLASH
	.byte EFFECT_SPLASH
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 40 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ ACID_ARMOR
	.byte EFFECT_DEFENSE_UP_2
	.byte 0 @ power
	.byte TYPE_POISON
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ CRABHAMMER
	.byte EFFECT_HIGH_CRITICAL
	.byte 100 @ power
	.byte TYPE_WATER
	.byte 90 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ EXPLOSION
	.byte EFFECT_EXPLOSION
	.byte 250 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_ALL_EXCEPT_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ FURY_SWIPES
	.byte EFFECT_MULTI_HIT
	.byte 18 @ power
	.byte TYPE_NORMAL
	.byte 80 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ BONEMERANG
	.byte EFFECT_DOUBLE_HIT
	.byte 50 @ power
	.byte TYPE_GROUND
	.byte 90 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ REST
	.byte EFFECT_REST
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ ROCK_SLIDE
	.byte EFFECT_FLINCH_HIT
	.byte 75 @ power
	.byte TYPE_ROCK
	.byte 90 @ accuracy
	.byte 10 @ PP
	.byte 30 @ secondary effect chance
	.byte TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ HYPER_FANG
	.byte EFFECT_FLINCH_HIT
	.byte 80 @ power
	.byte TYPE_NORMAL
	.byte 90 @ accuracy
	.byte 15 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT | F_BITING @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SHARPEN
	.byte EFFECT_ATTACK_UP
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 30 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ CONVERSION
	.byte EFFECT_CONVERSION
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 30 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ TRI_ATTACK
	.byte EFFECT_TRI_ATTACK
	.byte 80 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 20 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ SUPER_FANG
	.byte EFFECT_SUPER_FANG
	.byte 1 @ power
	.byte TYPE_NORMAL
	.byte 90 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SLASH
	.byte EFFECT_HIGH_CRITICAL
	.byte 70 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SUBSTITUTE
	.byte EFFECT_SUBSTITUTE
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ STRUGGLE
	.byte EFFECT_RECOIL
	.byte 50 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 1 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SKETCH
	.byte EFFECT_SKETCH
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 1 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ TRIPLE_KICK
	.byte EFFECT_TRIPLE_KICK
	.byte 10 @ power
	.byte TYPE_FIGHTING
	.byte 90 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ THIEF
	.byte EFFECT_THIEF
	.byte 60 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 25 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SPIDER_WEB
	.byte EFFECT_MEAN_LOOK
	.byte 0 @ power
	.byte TYPE_BUG
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ MIND_READER
	.byte EFFECT_LOCK_ON
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ NIGHTMARE
	.byte EFFECT_NIGHTMARE
	.byte 0 @ power
	.byte TYPE_GHOST
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ FLAME_WHEEL
	.byte EFFECT_THAW_HIT
	.byte 60 @ power
	.byte TYPE_FIRE
	.byte 100 @ accuracy
	.byte 25 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SNORE
	.byte EFFECT_SNORE
	.byte 50 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 30 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ CURSE
	.byte EFFECT_CURSE
	.byte 0 @ power
	.byte TYPE_FAIRY
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ FLAIL
	.byte EFFECT_FLAIL
	.byte 1 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ CONVERSION_2
	.byte EFFECT_CONVERSION_2
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ AEROBLAST
	.byte EFFECT_HIGH_CRITICAL
	.byte 100 @ power
	.byte TYPE_FLYING
	.byte 95 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ COTTON_SPORE
	.byte EFFECT_SPEED_DOWN_2
	.byte 0 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 40 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ REVERSAL
	.byte EFFECT_FLAIL
	.byte 1 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SPITE
	.byte EFFECT_SPITE
	.byte 0 @ power
	.byte TYPE_GHOST
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ POWDER_SNOW
	.byte EFFECT_FREEZE_HIT
	.byte 40 @ power
	.byte TYPE_ICE
	.byte 100 @ accuracy
	.byte 25 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ PROTECT
	.byte EFFECT_PROTECT
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 4 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ MACH_PUNCH
	.byte EFFECT_QUICK_ATTACK
	.byte 40 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 1 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SCARY_FACE
	.byte EFFECT_SPEED_DOWN_2
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ FAINT_ATTACK
	.byte EFFECT_ALWAYS_HIT
	.byte 60 @ power
	.byte TYPE_DARK
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SWEET_KISS
	.byte EFFECT_CONFUSE
	.byte 0 @ power
	.byte TYPE_FAIRY
	.byte 75 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ BELLY_DRUM
	.byte EFFECT_BELLY_DRUM
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ SLUDGE_BOMB
	.byte EFFECT_POISON_HIT
	.byte 90 @ power
	.byte TYPE_POISON
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 30 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ MUD_SLAP
	.byte EFFECT_ACCURACY_DOWN_HIT
	.byte 20 @ power
	.byte TYPE_GROUND
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ OCTAZOOKA
	.byte EFFECT_ACCURACY_DOWN_HIT
	.byte 65 @ power
	.byte TYPE_WATER
	.byte 85 @ accuracy
	.byte 10 @ PP
	.byte 50 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ SPIKES
	.byte EFFECT_SPIKES
	.byte 0 @ power
	.byte TYPE_GROUND
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_ENEMY_SIDE
	.byte 0 @ priority
	.byte F_AFFECTED_BY_MAGIC_COAT @ misc. flags
	.byte 0 
	.byte CLASS_STATUS
	.byte 0

@ ZAP_CANNON
	.byte EFFECT_PARALYZE_HIT
	.byte 120 @ power
	.byte TYPE_ELECTRIC
	.byte 50 @ accuracy
	.byte 5 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ FORESIGHT
	.byte EFFECT_FORESIGHT
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 40 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ DESTINY_BOND
	.byte EFFECT_DESTINY_BOND
	.byte 0 @ power
	.byte TYPE_GHOST
	.byte 0 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ PERISH_SONG
	.byte EFFECT_PERISH_SONG
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ ICY_WIND
	.byte EFFECT_SPEED_DOWN_HIT
	.byte 55 @ power
	.byte TYPE_ICE
	.byte 95 @ accuracy
	.byte 15 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ DETECT
	.byte EFFECT_PROTECT
	.byte 0 @ power
	.byte TYPE_FIGHTING
	.byte 0 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 4 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ BONE_RUSH
	.byte EFFECT_MULTI_HIT
	.byte 25 @ power
	.byte TYPE_GROUND
	.byte 90 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ LOCK_ON
	.byte EFFECT_LOCK_ON
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ OUTRAGE
	.byte EFFECT_RAMPAGE
	.byte 120 @ power
	.byte TYPE_DRAGON
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_RANDOM
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SANDSTORM
	.byte EFFECT_SANDSTORM
	.byte 0 @ power
	.byte TYPE_ROCK
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ GIGA_DRAIN
	.byte EFFECT_ABSORB
	.byte 75 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ ENDURE
	.byte EFFECT_ENDURE
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 4 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ CHARM
	.byte EFFECT_ATTACK_DOWN_2
	.byte 0 @ power
	.byte TYPE_FAIRY
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ ROLLOUT
	.byte EFFECT_ROLLOUT
	.byte 30 @ power
	.byte TYPE_ROCK
	.byte 90 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ FALSE_SWIPE
	.byte EFFECT_FALSE_SWIPE
	.byte 40 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 40 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SWAGGER
	.byte EFFECT_SWAGGER
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 85 @ accuracy
	.byte 15 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ MILK_DRINK
	.byte EFFECT_SOFTBOILED
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ SPARK
	.byte EFFECT_PARALYZE_HIT
	.byte 65 @ power
	.byte TYPE_ELECTRIC
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 30 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ FURY_CUTTER
	.byte EFFECT_FURY_CUTTER
	.byte 40 @ power
	.byte TYPE_BUG
	.byte 95 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ STEEL_WING
	.byte EFFECT_DEFENSE_UP_HIT
	.byte 70 @ power
	.byte TYPE_STEEL
	.byte 90 @ accuracy
	.byte 25 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ MEAN_LOOK
	.byte EFFECT_MEAN_LOOK
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ ATTRACT
	.byte EFFECT_ATTRACT
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ SLEEP_TALK
	.byte EFFECT_SLEEP_TALK
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SPECIAL
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ HEAL_BELL
	.byte EFFECT_HEAL_BELL
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ RETURN
	.byte EFFECT_RETURN
	.byte 1 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ PRESENT
	.byte EFFECT_PRESENT
	.byte 1 @ power
	.byte TYPE_NORMAL
	.byte 90 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ FRUSTRATION
	.byte EFFECT_FRUSTRATION
	.byte 1 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SAFEGUARD
	.byte EFFECT_SAFEGUARD
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 25 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ PAIN_SPLIT
	.byte EFFECT_PAIN_SPLIT
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ SACRED_FIRE
	.byte EFFECT_THAW_HIT
	.byte 100 @ power
	.byte TYPE_FIRE
	.byte 95 @ accuracy
	.byte 5 @ PP
	.byte 50 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ MAGNITUDE
	.byte EFFECT_MAGNITUDE
	.byte 1 @ power
	.byte TYPE_GROUND
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_ALL_EXCEPT_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ DYNAMIC_PUNCH
	.byte EFFECT_CONFUSE_HIT
	.byte 100 @ power
	.byte TYPE_FIGHTING
	.byte 50 @ accuracy
	.byte 5 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ MEGAHORN
	.byte EFFECT_HIT
	.byte 120 @ power
	.byte TYPE_BUG
	.byte 85 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ DRAGON_BREATH
	.byte EFFECT_PARALYZE_HIT
	.byte 60 @ power
	.byte TYPE_DRAGON
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 30 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ BATON_PASS
	.byte EFFECT_BATON_PASS
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 40 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ ENCORE
	.byte EFFECT_ENCORE
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ PURSUIT
	.byte EFFECT_PURSUIT
	.byte 40 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ RAPID_SPIN
	.byte EFFECT_RAPID_SPIN
	.byte 20 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 40 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SWEET_SCENT
	.byte EFFECT_EVASION_DOWN
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ IRON_TAIL
	.byte EFFECT_DEFENSE_DOWN_HIT
	.byte 100 @ power
	.byte TYPE_STEEL
	.byte 75 @ accuracy
	.byte 15 @ PP
	.byte 30 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ METAL_CLAW
	.byte EFFECT_ATTACK_UP_HIT
	.byte 50 @ power
	.byte TYPE_STEEL
	.byte 95 @ accuracy
	.byte 35 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ VITAL_THROW
	.byte EFFECT_VITAL_THROW
	.byte 70 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte -1 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ MORNING_SUN
	.byte EFFECT_MORNING_SUN
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ SYNTHESIS
	.byte EFFECT_SYNTHESIS
	.byte 0 @ power
	.byte TYPE_GRASS
	.byte 0 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ MOONLIGHT
	.byte EFFECT_MOONLIGHT
	.byte 0 @ power
	.byte TYPE_FAIRY
	.byte 0 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ HIDDEN_POWER
	.byte EFFECT_HIDDEN_POWER
	.byte 1 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ CROSS_CHOP
	.byte EFFECT_HIGH_CRITICAL
	.byte 100 @ power
	.byte TYPE_FIGHTING
	.byte 80 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ TWISTER
	.byte EFFECT_TWISTER
	.byte 40 @ power
	.byte TYPE_DRAGON
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 20 @ secondary effect chance
	.byte TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ RAIN_DANCE
	.byte EFFECT_RAIN_DANCE
	.byte 0 @ power
	.byte TYPE_WATER
	.byte 0 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ SUNNY_DAY
	.byte EFFECT_SUNNY_DAY
	.byte 0 @ power
	.byte TYPE_FIRE
	.byte 0 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ CRUNCH
	.byte EFFECT_DEFENSE_DOWN_HIT
	.byte 80 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 20 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT | F_BITING @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ MIRROR_COAT
	.byte EFFECT_MIRROR_COAT
	.byte 1 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SPECIAL
	.byte -5 @ priority
	.byte F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ PSYCH_UP
	.byte EFFECT_PSYCH_UP
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ EXTREME_SPEED
	.byte EFFECT_QUICK_ATTACK
	.byte 80 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 2 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ ANCIENT_POWER
	.byte EFFECT_ALL_STATS_UP_HIT
	.byte 60 @ power
	.byte TYPE_ROCK
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ SHADOW_BALL
	.byte EFFECT_SPECIAL_DEFENSE_DOWN_HIT
	.byte 80 @ power
	.byte TYPE_GHOST
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 20 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ FUTURE_SIGHT
	.byte EFFECT_FUTURE_SIGHT
	.byte 120 @ power
	.byte TYPE_PSYCHIC
	.byte 90 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ ROCK_SMASH
	.byte EFFECT_DEFENSE_DOWN_HIT
	.byte 40 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 50 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ WHIRLPOOL
	.byte EFFECT_TRAP
	.byte 35 @ power
	.byte TYPE_WATER
	.byte 85 @ accuracy
	.byte 15 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ BEAT_UP
	.byte EFFECT_BEAT_UP
	.byte 10 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ FAKE_OUT
	.byte EFFECT_FAKE_OUT
	.byte 40 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 3 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ UPROAR
	.byte EFFECT_UPROAR
	.byte 90 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_RANDOM
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ STOCKPILE
	.byte EFFECT_STOCKPILE
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ SPIT_UP
	.byte EFFECT_SPIT_UP
	.byte 100 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ SWALLOW
	.byte EFFECT_SWALLOW
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ HEAT_WAVE
	.byte EFFECT_BURN_HIT
	.byte 95 @ power
	.byte TYPE_FIRE
	.byte 90 @ accuracy
	.byte 10 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ HAIL
	.byte EFFECT_HAIL
	.byte 0 @ power
	.byte TYPE_ICE
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ TORMENT
	.byte EFFECT_TORMENT
	.byte 0 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ FLATTER
	.byte EFFECT_FLATTER
	.byte 0 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ WILL_O_WISP
	.byte EFFECT_WILL_O_WISP
	.byte 0 @ power
	.byte TYPE_FIRE
	.byte 85 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ MEMENTO
	.byte EFFECT_MEMENTO
	.byte 0 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ FACADE
	.byte EFFECT_FACADE
	.byte 70 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ FOCUS_PUNCH
	.byte EFFECT_FOCUS_PUNCH
	.byte 150 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte -3 @ priority
	.byte F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SMELLING_SALT
	.byte EFFECT_SMELLINGSALT
	.byte 70 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ FOLLOW_ME
	.byte EFFECT_FOLLOW_ME
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 2 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ NATURE_POWER
	.byte EFFECT_NATURE_POWER
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 95 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SPECIAL
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ CHARGE
	.byte EFFECT_CHARGE
	.byte 0 @ power
	.byte TYPE_ELECTRIC
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ TAUNT
	.byte EFFECT_TAUNT
	.byte 0 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_PROTECT | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ HELPING_HAND
	.byte EFFECT_HELPING_HAND
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 5 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ TRICK
	.byte EFFECT_TRICK
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ ROLE_PLAY
	.byte EFFECT_ROLE_PLAY
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ WISH
	.byte EFFECT_WISH
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ ASSIST
	.byte EFFECT_ASSIST
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SPECIAL
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ INGRAIN
	.byte EFFECT_INGRAIN
	.byte 0 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ SUPERPOWER
	.byte EFFECT_SUPERPOWER
	.byte 120 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ MAGIC_COAT
	.byte EFFECT_MAGIC_COAT
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SPECIAL
	.byte 4 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ RECYCLE
	.byte EFFECT_RECYCLE
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ REVENGE
	.byte EFFECT_REVENGE
	.byte 60 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte -4 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ BRICK_BREAK
	.byte EFFECT_BRICK_BREAK
	.byte 75 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ YAWN
	.byte EFFECT_YAWN
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ KNOCK_OFF
	.byte EFFECT_KNOCK_OFF
	.byte 65 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ ENDEAVOR
	.byte EFFECT_ENDEAVOR
	.byte 1 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ ERUPTION
	.byte EFFECT_ERUPTION
	.byte 150 @ power
	.byte TYPE_FIRE
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ SKILL_SWAP
	.byte EFFECT_SKILL_SWAP
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ IMPRISON
	.byte EFFECT_IMPRISON
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ REFRESH
	.byte EFFECT_REFRESH
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ GRUDGE
	.byte EFFECT_GRUDGE
	.byte 0 @ power
	.byte TYPE_GHOST
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ SNATCH
	.byte EFFECT_SNATCH
	.byte 0 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SPECIAL
	.byte 4 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ SECRET_POWER
	.byte EFFECT_SECRET_POWER
	.byte 70 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 30 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ DIVE
	.byte EFFECT_FLY
	.byte 80 @ power
	.byte TYPE_WATER
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ ARM_THRUST
	.byte EFFECT_MULTI_HIT
	.byte 15 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ CAMOUFLAGE
	.byte EFFECT_CAMOUFLAGE
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ TAIL_GLOW
	.byte EFFECT_SPECIAL_ATTACK_UP_2
	.byte 0 @ power
	.byte TYPE_BUG
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ LUSTER_PURGE
	.byte EFFECT_SPECIAL_DEFENSE_DOWN_HIT
	.byte 70 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 50 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ MIST_BALL
	.byte EFFECT_SPECIAL_ATTACK_DOWN_HIT
	.byte 70 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 50 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ FEATHER_DANCE
	.byte EFFECT_ATTACK_DOWN_2
	.byte 0 @ power
	.byte TYPE_FLYING
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ TEETER_DANCE
	.byte EFFECT_TEETER_DANCE
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_ALL_EXCEPT_USER
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ BLAZE_KICK
	.byte EFFECT_BLAZE_KICK
	.byte 85 @ power
	.byte TYPE_FIRE
	.byte 90 @ accuracy
	.byte 10 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ MUD_SPORT
	.byte EFFECT_MUD_SPORT
	.byte 0 @ power
	.byte TYPE_GROUND
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ ICE_BALL
	.byte EFFECT_ROLLOUT
	.byte 30 @ power
	.byte TYPE_ICE
	.byte 90 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ NEEDLE_ARM
	.byte EFFECT_FLINCH_HIT_2
	.byte 60 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 30 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SLACK_OFF
	.byte EFFECT_RESTORE_HP
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ HYPER_VOICE
	.byte EFFECT_HIT
	.byte 90 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ POISON_FANG
	.byte EFFECT_POISON_FANG
	.byte 50 @ power
	.byte TYPE_POISON
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 50 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT | F_BITING @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ CRUSH_CLAW
	.byte EFFECT_DEFENSE_DOWN_HIT
	.byte 75 @ power
	.byte TYPE_NORMAL
	.byte 95 @ accuracy
	.byte 10 @ PP
	.byte 50 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ BLAST_BURN
	.byte EFFECT_RECHARGE
	.byte 150 @ power
	.byte TYPE_FIRE
	.byte 90 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ HYDRO_CANNON
	.byte EFFECT_RECHARGE
	.byte 150 @ power
	.byte TYPE_WATER
	.byte 90 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ METEOR_MASH
	.byte EFFECT_ATTACK_UP_HIT
	.byte 90 @ power
	.byte TYPE_STEEL
	.byte 90 @ accuracy
	.byte 10 @ PP
	.byte 20 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ ASTONISH
	.byte EFFECT_FLINCH_HIT_2
	.byte 30 @ power
	.byte TYPE_GHOST
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 30 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ WEATHER_BALL
	.byte EFFECT_WEATHER_BALL
	.byte 50 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ AROMATHERAPY
	.byte EFFECT_HEAL_BELL
	.byte 0 @ power
	.byte TYPE_GRASS
	.byte 0 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ FAKE_TEARS
	.byte EFFECT_SPECIAL_DEFENSE_DOWN_2
	.byte 0 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ AIR_CUTTER
	.byte EFFECT_HIGH_CRITICAL
	.byte 60 @ power
	.byte TYPE_FLYING
	.byte 95 @ accuracy
	.byte 25 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ OVERHEAT
	.byte EFFECT_OVERHEAT
	.byte 130 @ power
	.byte TYPE_FIRE
	.byte 90 @ accuracy
	.byte 5 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ ODOR_SLEUTH
	.byte EFFECT_FORESIGHT
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 40 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ ROCK_TOMB
	.byte EFFECT_SPEED_DOWN_HIT
	.byte 60 @ power
	.byte TYPE_ROCK
	.byte 95 @ accuracy
	.byte 15 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SILVER_WIND
	.byte EFFECT_ALL_STATS_UP_HIT
	.byte 60 @ power
	.byte TYPE_BUG
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ METAL_SOUND
	.byte EFFECT_SPECIAL_DEFENSE_DOWN_2
	.byte 0 @ power
	.byte TYPE_STEEL
	.byte 85 @ accuracy
	.byte 40 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ GRASS_WHISTLE
	.byte EFFECT_SLEEP
	.byte 0 @ power
	.byte TYPE_GRASS
	.byte 55 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ TICKLE
	.byte EFFECT_TICKLE
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ COSMIC_POWER
	.byte EFFECT_COSMIC_POWER
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ WATER_SPOUT
	.byte EFFECT_ERUPTION
	.byte 150 @ power
	.byte TYPE_WATER
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ SIGNAL_BEAM
	.byte EFFECT_CONFUSE_HIT
	.byte 75 @ power
	.byte TYPE_BUG
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ SHADOW_PUNCH
	.byte EFFECT_ALWAYS_HIT
	.byte 60 @ power
	.byte TYPE_GHOST
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ EXTRASENSORY
	.byte EFFECT_FLINCH_HIT_2
	.byte 80 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ SKY_UPPERCUT
	.byte EFFECT_SKY_UPPERCUT
	.byte 85 @ power
	.byte TYPE_FIGHTING
	.byte 90 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SAND_TOMB
	.byte EFFECT_TRAP
	.byte 35 @ power
	.byte TYPE_GROUND
	.byte 85 @ accuracy
	.byte 15 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ SHEER_COLD
	.byte EFFECT_OHKO
	.byte 1 @ power
	.byte TYPE_ICE
	.byte 30 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ MUDDY_WATER
	.byte EFFECT_ACCURACY_DOWN_HIT
	.byte 90 @ power
	.byte TYPE_WATER
	.byte 85 @ accuracy
	.byte 10 @ PP
	.byte 30 @ secondary effect chance
	.byte TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ BULLET_SEED
	.byte EFFECT_MULTI_HIT
	.byte 25 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ AERIAL_ACE
	.byte EFFECT_ALWAYS_HIT
	.byte 60 @ power
	.byte TYPE_FLYING
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ ICICLE_SPEAR
	.byte EFFECT_MULTI_HIT
	.byte 25 @ power
	.byte TYPE_ICE
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ IRON_DEFENSE
	.byte EFFECT_DEFENSE_UP_2
	.byte 0 @ power
	.byte TYPE_STEEL
	.byte 0 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ BLOCK
	.byte EFFECT_MEAN_LOOK
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ HOWL
	.byte EFFECT_ATTACK_UP
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 40 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ DRAGON_CLAW
	.byte EFFECT_HIT
	.byte 80 @ power
	.byte TYPE_DRAGON
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ FRENZY_PLANT
	.byte EFFECT_RECHARGE
	.byte 150 @ power
	.byte TYPE_GRASS
	.byte 90 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ BULK_UP
	.byte EFFECT_BULK_UP
	.byte 0 @ power
	.byte TYPE_FIGHTING
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ BOUNCE
	.byte EFFECT_FLY
	.byte 85 @ power
	.byte TYPE_FLYING
	.byte 85 @ accuracy
	.byte 5 @ PP
	.byte 30 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ MUD_SHOT
	.byte EFFECT_SPEED_DOWN_HIT
	.byte 55 @ power
	.byte TYPE_GROUND
	.byte 95 @ accuracy
	.byte 15 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ POISON_TAIL
	.byte EFFECT_POISON_TAIL
	.byte 50 @ power
	.byte TYPE_POISON
	.byte 100 @ accuracy
	.byte 25 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ COVET
	.byte EFFECT_THIEF
	.byte 60 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 25 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ VOLT_TACKLE
	.byte EFFECT_DOUBLE_EDGE
	.byte 120 @ power
	.byte TYPE_ELECTRIC
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ MAGICAL_LEAF
	.byte EFFECT_ALWAYS_HIT
	.byte 60 @ power
	.byte TYPE_GRASS
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ WATER_SPORT
	.byte EFFECT_WATER_SPORT
	.byte 0 @ power
	.byte TYPE_WATER
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ CALM_MIND
	.byte EFFECT_CALM_MIND
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ LEAF_BLADE
	.byte EFFECT_HIGH_CRITICAL
	.byte 90 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ DRAGON_DANCE
	.byte EFFECT_DRAGON_DANCE
	.byte 0 @ power
	.byte TYPE_DRAGON
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_USER
	.byte 0 @ priority
	.byte F_AFFECTED_BY_SNATCH @ misc. flags
	.byte 0
	.byte CLASS_STATUS
	.byte 0

@ ROCK_BLAST
	.byte EFFECT_MULTI_HIT
	.byte 25 @ power
	.byte TYPE_ROCK
	.byte 90 @ accuracy
	.byte 10 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ SHOCK_WAVE
	.byte EFFECT_ALWAYS_HIT
	.byte 60 @ power
	.byte TYPE_ELECTRIC
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ WATER_PULSE
	.byte EFFECT_CONFUSE_HIT
	.byte 60 @ power
	.byte TYPE_WATER
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 20 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ DOOM_DESIRE
	.byte EFFECT_FUTURE_SIGHT
	.byte 140 @ power
	.byte TYPE_STEEL
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte 0 @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ PSYCHO_BOOST
	.byte EFFECT_OVERHEAT
	.byte 140 @ power
	.byte TYPE_PSYCHIC
	.byte 90 @ accuracy
	.byte 5 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ ENERGY_BALL
	.byte EFFECT_SPECIAL_DEFENSE_DOWN_HIT
	.byte 90 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 10 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ LEAF_STORM
	.byte EFFECT_OVERHEAT
	.byte 130 @ power
	.byte TYPE_GRASS
	.byte 90 @ accuracy
	.byte 5 @ PP
	.byte 100 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
	.byte 0
	.byte CLASS_SPECIAL
	.byte 0

@ DUAL_CHOP
	.byte EFFECT_DOUBLE_HIT
	.byte 40 @ power
	.byte TYPE_DRAGON
	.byte 90 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0

@ X_SCISSOR
	.byte EFFECT_HIT
	.byte 80 @ power
	.byte TYPE_BUG
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ secondary effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags
	.byte 0
	.byte CLASS_PHYSICAL
	.byte 0
