@ no this is too stupid i'm overhauling it
@ type order: 
@ normal, fighting, flying, poison,   ground
@ rock,   bug,      ghost,  steel,    fairy
@ fire,   water,    grass,  electric, psychic
@ ice,    dragon,   dark,   roosting, typeless
@
@ 0 = ineffective
@ 1 = ineffective ; neutral if foresight or scrappy
@ 2 = ineffective ; neutral if miracle eye
@ 5 == NVE
@ 10 == neutral
@ 20 = SE

gTypeEffectiveness:: @ 81F9720

@ Normal
	.byte 10, 10, 10, 10, 10
	.byte  5, 10,  1,  5, 10
	.byte 10, 10, 10, 10, 10
	.byte 10, 10, 10, 10, 10

@ Fighting
	.byte 20, 10,  5,  5, 10
	.byte 20,  5,  1, 20,  5
	.byte 10, 10, 10, 10,  5
	.byte 20, 10, 20, 10, 10

@ Flying
	.byte 10, 20, 10, 10, 10
	.byte  5, 20, 10,  5, 10
	.byte 10, 10, 20,  5, 10
	.byte 10, 10, 10, 10, 10

@ Poison
	.byte 10, 10, 10,  5,  5
	.byte  5, 10,  5,  0, 20
	.byte 10, 10, 20, 10, 10
	.byte 10, 10, 10, 10, 10

@ Ground
	.byte 10, 10,  0, 20, 10
	.byte 20,  5, 10, 20, 10
	.byte 20, 10,  5, 20, 10
	.byte 10, 10, 10, 10, 10

@ Rock
	.byte 10,  5, 20, 10,  5
	.byte 10, 20, 10,  5, 10
	.byte 20, 10, 10, 10, 10
	.byte 20, 10, 10, 10, 10

@ Bug
	.byte 10,  5,  5,  5, 10
	.byte 10, 10,  5,  5,  5
	.byte  5, 10, 20, 10, 20
	.byte 10, 10, 20, 10, 10
	
@ normal, fighting, flying, poison,   ground
@ rock,   bug,      ghost,  steel,    fairy
@ fire,   water,    grass,  electric, psychic
@ ice,    dragon,   dark,   roosting, --

@ Ghost
	.byte  0, 10, 10, 10, 10
	.byte 10, 10, 20, 10, 10
	.byte 10, 10, 10, 10, 20
	.byte 10, 10,  5, 10, 10

@ Steel
	.byte 10, 10, 10, 10, 10
	.byte 20, 10, 10,  5, 20
	.byte  5,  5, 10,  5, 10
	.byte 20, 10, 10, 10, 10

@ Fairy
	.byte 10, 20, 10,  5, 10
	.byte 10, 10, 10,  5, 10
	.byte  5, 10, 10, 10, 10
	.byte 10, 20, 20, 10, 10

@ Fire
	.byte 10, 10, 10, 10, 10
	.byte  5, 20, 10, 20, 10
	.byte  5,  5, 20, 10, 10
	.byte 20,  5, 10, 10, 10

@ Water
	.byte 10, 10, 10, 10, 20
	.byte 20, 10, 10, 10, 10
	.byte 20,  5,  5, 10, 10
	.byte 10,  5, 10, 10, 10

@ Grass
	.byte 10, 10,  5,  5, 20
	.byte 20,  5, 10,  5, 10
	.byte  5, 20,  5, 10, 10
	.byte 10,  5, 10, 10, 10

@ Electric
	.byte 10, 10, 20, 10,  0
	.byte 10, 10, 10, 10, 10
	.byte 10, 20,  5,  5, 10
	.byte 10,  5, 10, 10, 10
	
@ normal, fighting, flying, poison,   ground
@ rock,   bug,      ghost,  steel,    fairy
@ fire,   water,    grass,  electric, psychic
@ ice,    dragon,   dark,   roosting, --

@ Psychic
	.byte 10, 20, 10, 20, 10
	.byte 10, 10, 10,  5, 10
	.byte 10, 10, 10, 10,  5
	.byte 10, 10,  2, 10, 10

@ Ice
	.byte 10, 10, 20, 10, 20
	.byte 10, 10, 10,  5, 10
	.byte  5,  5, 20, 10, 10
	.byte  5, 20, 10, 10, 10

@ Dragon
	.byte 10, 10, 10, 10, 10
	.byte 10, 10, 10,  5,  0
	.byte 10, 10, 10, 10, 10
	.byte 10, 20, 10, 10, 10

@ Dark
	.byte 10,  5, 10, 10, 10
	.byte 10, 10, 20, 10,  5
	.byte 10, 10, 10, 10, 20
	.byte 10, 10,  5, 10, 10

@ Roosting (flying ; shouldn't be used)
	.byte 10, 20, 10, 10, 10
	.byte  5, 20, 10,  5, 10
	.byte 10, 10, 10,  5, 10
	.byte 10, 10, 10, 10, 10

@ Typeless (burnt up ; also shouldn't be used)
	.byte 10, 10, 10, 10, 10
	.byte 10, 10, 10, 10, 10
	.byte 10, 10, 10, 10, 10
	.byte 10, 10, 10, 10, 10
	.byte 10, 10, 10, 10, 10


@ Old abomination
	.byte   TYPE_NORMAL,     TYPE_ROCK,  5
	.byte   TYPE_NORMAL,    TYPE_STEEL,  5
	.byte     TYPE_FIRE,     TYPE_FIRE,  5
	.byte     TYPE_FIRE,    TYPE_WATER,  5
	.byte     TYPE_FIRE,    TYPE_GRASS, 20
	.byte     TYPE_FIRE,      TYPE_ICE, 20
	.byte     TYPE_FIRE,      TYPE_BUG, 20
	.byte     TYPE_FIRE,     TYPE_ROCK,  5
	.byte     TYPE_FIRE,   TYPE_DRAGON,  5
	.byte     TYPE_FIRE,    TYPE_STEEL, 20
	.byte    TYPE_WATER,     TYPE_FIRE, 20
	.byte    TYPE_WATER,    TYPE_WATER,  5
	.byte    TYPE_WATER,    TYPE_GRASS,  5
	.byte    TYPE_WATER,   TYPE_GROUND, 20
	.byte    TYPE_WATER,     TYPE_ROCK, 20
	.byte    TYPE_WATER,   TYPE_DRAGON,  5
	.byte TYPE_ELECTRIC,    TYPE_WATER, 20
	.byte TYPE_ELECTRIC, TYPE_ELECTRIC,  5
	.byte TYPE_ELECTRIC,    TYPE_GRASS,  5
	.byte TYPE_ELECTRIC,   TYPE_GROUND,  0
	.byte TYPE_ELECTRIC,   TYPE_FLYING, 20
	.byte TYPE_ELECTRIC,   TYPE_DRAGON,  5
	.byte    TYPE_GRASS,     TYPE_FIRE,  5
	.byte    TYPE_GRASS,    TYPE_WATER, 20
	.byte    TYPE_GRASS,    TYPE_GRASS,  5
	.byte    TYPE_GRASS,   TYPE_POISON,  5
	.byte    TYPE_GRASS,   TYPE_GROUND, 20
	.byte    TYPE_GRASS,   TYPE_FLYING,  5
	.byte    TYPE_GRASS,      TYPE_BUG,  5
	.byte    TYPE_GRASS,     TYPE_ROCK, 20
	.byte    TYPE_GRASS,   TYPE_DRAGON,  5
	.byte    TYPE_GRASS,    TYPE_STEEL,  5
	.byte      TYPE_ICE,    TYPE_WATER,  5
	.byte      TYPE_ICE,    TYPE_GRASS, 20
	.byte      TYPE_ICE,      TYPE_ICE,  5
	.byte      TYPE_ICE,   TYPE_GROUND, 20
	.byte      TYPE_ICE,   TYPE_FLYING, 20
	.byte      TYPE_ICE,   TYPE_DRAGON, 20
	.byte      TYPE_ICE,    TYPE_STEEL,  5
	.byte      TYPE_ICE,     TYPE_FIRE,  5
	.byte TYPE_FIGHTING,   TYPE_NORMAL, 20
	.byte TYPE_FIGHTING,      TYPE_ICE, 20
	.byte TYPE_FIGHTING,   TYPE_POISON,  5
	.byte TYPE_FIGHTING,   TYPE_FLYING,  5
	.byte TYPE_FIGHTING,  TYPE_PSYCHIC,  5
	.byte TYPE_FIGHTING,      TYPE_BUG,  5
	.byte TYPE_FIGHTING,     TYPE_ROCK, 20
	.byte TYPE_FIGHTING,     TYPE_DARK, 20
	.byte TYPE_FIGHTING,    TYPE_STEEL, 20
	.byte TYPE_FIGHTING,    TYPE_FAIRY,  5
	.byte   TYPE_POISON,    TYPE_GRASS, 20
	.byte   TYPE_POISON,   TYPE_POISON,  5
	.byte   TYPE_POISON,   TYPE_GROUND,  5
	.byte   TYPE_POISON,     TYPE_ROCK,  5
	.byte   TYPE_POISON,    TYPE_GHOST,  5
	.byte   TYPE_POISON,    TYPE_STEEL,  0
	.byte   TYPE_POISON,    TYPE_FAIRY, 20
	.byte   TYPE_GROUND,     TYPE_FIRE, 20
	.byte   TYPE_GROUND, TYPE_ELECTRIC, 20
	.byte   TYPE_GROUND,    TYPE_GRASS,  5
	.byte   TYPE_GROUND,   TYPE_POISON, 20
	.byte   TYPE_GROUND,   TYPE_FLYING,  0
	.byte   TYPE_GROUND,      TYPE_BUG,  5
	.byte   TYPE_GROUND,     TYPE_ROCK, 20
	.byte   TYPE_GROUND,    TYPE_STEEL, 20
	.byte   TYPE_FLYING, TYPE_ELECTRIC,  5
	.byte   TYPE_FLYING,    TYPE_GRASS, 20
	.byte   TYPE_FLYING, TYPE_FIGHTING, 20
	.byte   TYPE_FLYING,      TYPE_BUG, 20
	.byte   TYPE_FLYING,     TYPE_ROCK,  5
	.byte   TYPE_FLYING,    TYPE_STEEL,  5
	.byte  TYPE_PSYCHIC, TYPE_FIGHTING, 20
	.byte  TYPE_PSYCHIC,   TYPE_POISON, 20
	.byte  TYPE_PSYCHIC,  TYPE_PSYCHIC,  5
	.byte  TYPE_PSYCHIC,     TYPE_DARK,  0
	.byte  TYPE_PSYCHIC,    TYPE_STEEL,  5
	.byte      TYPE_BUG,     TYPE_FIRE,  5
	.byte      TYPE_BUG,    TYPE_GRASS, 20
	.byte      TYPE_BUG, TYPE_FIGHTING,  5
	.byte      TYPE_BUG,   TYPE_POISON,  5
	.byte      TYPE_BUG,   TYPE_FLYING,  5
	.byte      TYPE_BUG,  TYPE_PSYCHIC, 20
	.byte      TYPE_BUG,    TYPE_GHOST,  5
	.byte      TYPE_BUG,     TYPE_DARK, 20
	.byte      TYPE_BUG,    TYPE_STEEL,  5
	.byte      TYPE_BUG,    TYPE_FAIRY,  5
	.byte     TYPE_ROCK,     TYPE_FIRE, 20
	.byte     TYPE_ROCK,      TYPE_ICE, 20
	.byte     TYPE_ROCK, TYPE_FIGHTING,  5
	.byte     TYPE_ROCK,   TYPE_GROUND,  5
	.byte     TYPE_ROCK,   TYPE_FLYING, 20
	.byte     TYPE_ROCK,      TYPE_BUG, 20
	.byte     TYPE_ROCK,    TYPE_STEEL,  5
	.byte    TYPE_GHOST,   TYPE_NORMAL,  0
	.byte    TYPE_GHOST,  TYPE_PSYCHIC, 20
	.byte    TYPE_GHOST,     TYPE_DARK,  5
	.byte    TYPE_GHOST,    TYPE_GHOST, 20
	.byte   TYPE_DRAGON,   TYPE_DRAGON, 20
	.byte   TYPE_DRAGON,    TYPE_STEEL,  5
	.byte   TYPE_DRAGON,    TYPE_FAIRY,  0
	.byte     TYPE_DARK, TYPE_FIGHTING,  5
	.byte     TYPE_DARK,  TYPE_PSYCHIC, 20
	.byte     TYPE_DARK,    TYPE_GHOST, 20
	.byte     TYPE_DARK,     TYPE_DARK,  5
	.byte     TYPE_DARK,    TYPE_FAIRY,  5
	.byte    TYPE_STEEL,     TYPE_FIRE,  5
	.byte    TYPE_STEEL,    TYPE_WATER,  5
	.byte    TYPE_STEEL, TYPE_ELECTRIC,  5
	.byte    TYPE_STEEL,      TYPE_ICE, 20
	.byte    TYPE_STEEL,     TYPE_ROCK, 20
	.byte    TYPE_STEEL,    TYPE_STEEL,  5
	.byte    TYPE_STEEL,    TYPE_FAIRY, 20
	.byte    TYPE_FAIRY,     TYPE_DARK, 20
	.byte    TYPE_FAIRY,   TYPE_DRAGON, 20
	.byte    TYPE_FAIRY, TYPE_FIGHTING, 20
	.byte    TYPE_FAIRY,     TYPE_FIRE,  5
	.byte    TYPE_FAIRY,   TYPE_POISON,  5
	.byte    TYPE_FAIRY,    TYPE_STEEL,  5
	.byte          0xFE,          0xFE,  0
	.byte   TYPE_NORMAL,    TYPE_GHOST,  0
	.byte TYPE_FIGHTING,    TYPE_GHOST,  0
	.byte          0xFF,          0xFF,  0
