	.include "include/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	@ unused
gOtherText_TopSpeed::
	.string "Top Speed$"

gMultiText_BerryBlenderMaxSpeedRecord:: @ 842C2E6
	.string "BERRY BLENDER\nMAXIMUM SPEED RECORD!$"

gMultiText_2P3P4P:: @ 842C30A
	.string "2 Players\n3 Players\n4 Players$"

gMultiText_Saving:: @ 842C328
	.string "SAVING...\nDON'T TURN OFF THE POWER.$"

gMultiText_LinkError:: @ 842C34C
	.string "{HIGHLIGHT TRANSPARENT}{COLOR WHITE2}Link error...\nCheck your Game Link cable connection,\nand turn the power off and on.$"

gSystemText_OptionMenu:: @ 842C3A6
	.string "{PALETTE 9}OPTION$"

gSystemText_TextSpeed:: @ 842C3B0
	.string "{PALETTE 9}TEXT SPEED$"

gSystemText_BattleScene:: @ 842C3BE
	.string "{PALETTE 9}BATTLE SCENE$"

gSystemText_BattleStyle:: @ 842C3CE
	.string "{PALETTE 9}BATTLE STYLE$"

gSystemText_Sound:: @ 842C3DE
	.string "{PALETTE 9}SOUND$"

gSystemText_Frame:: @ 842C3E7
	.string "{PALETTE 9}FRAME$"

gSystemText_Cancel:: @ 842C3F0
	.string "{PALETTE 9}CANCEL$"

gSystemText_ButtonMode:: @ 842C3FA
	.string "{PALETTE 9}BUTTON MODE$"

gSystemText_Font:: @ 842C3F0
	.string "{PALETTE 9}FONT$"

gSystemText_Slow:: @ 842C409
	.string "{PALETTE 15}Mid$"

gSystemText_Mid:: @ 842C411
	.string "{PALETTE 15}Fast$"

gSystemText_Fast:: @ 842C418
	.string "{PALETTE 15}Instant$"

gSystemText_On:: @ 842C420
	.string "{PALETTE 15}On$"

gSystemText_Off:: @ 842C426
	.string "{PALETTE 15}Off$"

gSystemText_Shift:: @ 842C42D
	.string "{PALETTE 15}Shift$"

gSystemText_Set:: @ 842C436
	.string "{PALETTE 15}Set$"

gSystemText_Mono:: @ 842C43D
	.string "{PALETTE 15}Mono$"

gSystemText_Stereo:: @ 842C445
	.string "{PALETTE 15}Stereo$"

gSystemText_Type:: @ 842C44F
	.string "{PALETTE 15}Type$"

gSystemText_Terminator:: @ 842C457
	.string "{PALETTE 8}$"

gSystemText_Normal:: @ 842C45B
	.string "{PALETTE 15}Normal$"

gSystemText_LR:: @ 842C465
	.string "{PALETTE 15}LR$"

gSystemText_LA:: @ 842C46B
	.string "{PALETTE 15}L=A$"
    
gSystemText_RS::
    .string "{PALETTE 15}RS$"
    
gSystemText_Emerald::
    .string "{PALETTE 15}Emerald$"
    
gSystemText_FRLG::
    .string "{PALETTE 15}FRLG$"

SystemText_Pokedex::
	.string "Pokédex$"
SystemText_Pokemon::
	.string "Pokémon$"
SystemText_BAG::
	.string "Bag$"
SystemText_Pokenav::
	.string "Pokénav$"
SystemText_Player::
	.string "{PLAYER}$"
SystemText_Save::
	.string "Save$"
SystemText_Option::
	.string "Option$"
SystemText_Exit::
	.string "Exit$"
SystemText_Retire:: @ safari zone?
	.string "Retire$"

gOtherText_SafariStock:: @ 842C4A9
	.string "Safari Balls\nStock: {STR_VAR_1}$"

gSystemText_LinkStandby:: @ 842C4C0
	.string "Link standby...\n... ... B Button: Cancel$"

gSystemText_LoadEventPressA:: @ 842C4E9
	.string "Press the A Button to load event.\n... ... B Button: Cancel$"

gSystemText_LoadingEvent:: @ 842C524
	.string "Loading event...$"

gSystemText_DontCutLink:: @ 842C535
	.string "Don't remove the Game Link cable.\nDon't turn off the power.$"

gSystemText_EventLoadSuccess:: @ 842C571
	.string "The event was safely loaded.$$"

gSystemText_LoadingError:: @ 842C58F
	.string "Loading error.\nEnding session.$$$$$$$$"

gOtherText_Hoenn:: @ 842C5B5
	.string "HOENN$"

gOtherText_OhABite:: @ 842C5BB
	.string "Oh! A bite!$"

gOtherText_PokeOnHook:: @ 842C5C7
	.string "A Pokémon's on the hook!{PAUSE_UNTIL_PRESS}$"

gOtherText_NotEvenANibble:: @ 842C5E2
	.string "Not even a nibble...{PAUSE_UNTIL_PRESS}$"

gOtherText_ItGotAway:: @ 842C5F9
	.string "It got away...{PAUSE_UNTIL_PRESS}$$"

gTradeText_WillBeSent:: @ 842C60B
	.string "{STR_VAR_2} will be sent to {STR_VAR_1}.$"

gTradeText_ByeBye:: @ 842C622
	.string "Bye-bye, {STR_VAR_2}!$"

gTradeText_SentOverPoke:: @ 842C62F
	.string "{STR_VAR_1} sent over {STR_VAR_3}.$"

gTradeText_TakeGoodCare:: @ 842C640
	.string "Take good care of {STR_VAR_3}!$"

TradeText_Cancel::
	.string "Cancel$"
TradeText_ChoosePoke::
	.string "Choose a Pokémon.$"
TradeText_Summary1::
	.string "Summary$"
TradeText_Trade1::
	.string "Trade$"
TradeText_CancelTradePrompt::
	.string "Cancel trade?$"
TradeText_PressBToExit::
	.string "Press the B Button to exit.$"
TradeText_Summary2::
	.string "Summary$"
TradeText_Trade2::
	.string "Trade$"
TradeText_LinkStandby::
	.string "{COLOR DARK_GREY}{HIGHLIGHT WHITE2}{SHADOW LIGHT_GREY}Link standby...\nPlease wait.$"
TradeText_TradeCancelled::
	.string "{COLOR DARK_GREY}{HIGHLIGHT WHITE2}{SHADOW LIGHT_GREY}The trade has\nbeen canceled.$"
TradeText_OnlyPoke::
	.string "{COLOR DARK_GREY}{HIGHLIGHT WHITE2}{SHADOW LIGHT_GREY}That's your only\nPokémon for battle.$"
TradeText_NonTradablePoke::
	.string "{COLOR DARK_GREY}{HIGHLIGHT WHITE2}{SHADOW LIGHT_GREY}Your friend can't\ntrade that one.$"
TradeText_WaitingForFriend::
	.string "{COLOR DARK_GREY}{HIGHLIGHT WHITE2}{SHADOW LIGHT_GREY}Waiting for your\nfriend to finish...$"
TradeText_WantToTrade::
	.string "{COLOR DARK_GREY}{HIGHLIGHT WHITE2}{SHADOW LIGHT_GREY}Your friend wants\nto trade Pokémon.$"
	.string "$"

gTradeText_TradeOkayPrompt:: @ 842C7B6
	.string "Is this trade okay?$"

gOtherText_Terminator2:: @ 842C7CA
	.string "$"

gOtherText_ControlAndMiscText:: @ 842C7CB
	.string "\n$"
	.string "/$"
	.string "Lv$"
	.string "---$"

gOtherText_FourQuestions:: @ 842C7D6
	.string "????$"

@ 842C7DB
	.include "data/text/easy_chat/group_name_strings.inc"

gOtherText_ThreeQuestions:: @ 842C890
	.string "???$"

gOtherText_From:: @ 842C894
	.string "From $"

gOtherText_MixingRecordsWithFriend:: @ 842C89A
	.string "Mixing records...$"

gOtherText_MixingComplete:: @ 842C8AC
	.string "Record mixing completed.\nThank you for waiting.$"

gOtherText_TrainersTrainerCard:: @ 842C8DC
	.string "'s Trainer Card$"

gOtherText_FirstHOF:: @ 842C8EC
	.string "FIRST HALL OF FAME$"

gOtherText_LinkCableBattles:: @ 842C8FF
	.string "LINK CABLE BATTLES  W/            L/$"

gOtherText_BattleTowerWinRecord:: @ 842C924
	.string "BATTLE TOWER W/{CLEAR_TO 0x72}&{CLEAR_TO 0x98}STRAIGHT$"

gOtherText_ContestRecord:: @ 842C943
	.string "CONTESTS W/FRIENDS W/$"

gOtherText_MixingRecord:: @ 842C959
	.string "{POKEBLOCK}S W/FRIENDS$"

gOtherText_TradeRecord:: @ 842C96A
	.string "POKéMON TRADES$"

gOtherText_Boy:: @ 842C979
	.string "Boy$"

gOtherText_Girl:: @ 842C97D
	.string "Girl$"
	.string "$"

gOtherText_Player:: @ 842C983
	.string "Player$"

gOtherText_Badges:: @ 842C98A
	.string "Badges$"
	.string "$"

gOtherText_Pokedex:: @ 842C992
	.string "Pokédex$"

gOtherText_PlayTime:: @ 842C99A
	.string "Play Time$"

gOtherText_SentToPC:: @ 842C9A4
	.string "{STR_VAR_1} was sent to\nthe PC.{PAUSE_UNTIL_PRESS}$"

OtherText_YourName::
	.string "Your Name?$"
OtherText_BoxName::
	.string "Box Name?$"
OtherText_PokeName::
	.string "{STR_VAR_1}'s nickname?$"

gOtherText_Marco:: @ 842C9E1
	.string "Marco$" @ polo

gOtherText_Coins:: @ 842C9E7
	.string "{STR_VAR_1} Coins$"

gOtherText_BattleResults:: @ 842C9F0
	.string "{PLAYER}'s Battle Results$"

gOtherText_WinRecord:: @ 842CA04
	.string "Total Record W/{STR_VAR_1} L/{STR_VAR_2} D/{STR_VAR_3}$"

gOtherText_WinLoseDraw:: @ 842CA20
	.string "WIN        LOSE        DRAW$"

gOtherText_SevenDashes:: @ 842CA3C
	.string "-------$"

gOtherText_FourDashes:: @ 842CA44
	.string "----$"

gOtherText_BattleTowerResults:: @ 842CA49
	.string "{PLAYER}'s Battle Tower Results$"

gOtherText_Lv50:: @ 842CA63
	.string "LV 50$"

gOtherText_Lv100:: @ 842CA69
	.string "LV 100$"

gOtherText_WinStreak:: @ 842CA70
	.string "{STR_VAR_1}W Streak$"

gOtherText_Current:: @ 842CA7B
	.string "Current$"

gOtherText_Record:: @ 842CA83
	.string "Record$"

gOtherText_Prev:: @ 842CA8A
	.string "Prev.$"

gOtherText_QuitGamePrompt:: @ 842CA90
	.string "Quit the game?$"

gOtherText_MaxCoins:: @ 842CA9F
	.string "You've got 9,999 Coins.$"

gOtherText_OutOfCoins:: @ 842CAB7
	.string "You've run out of Coins.\nGame over!$"

gOtherText_DontHaveThreeCoins:: @ 842CADB
	.string "You don't have three Coins.$"

gOtherText_ReelTime:: @ 842CAF7
	.string "REEL TIME\nHere's your chance to take\naim and nail marks!\nThe Reel Time continues for\nas often as the drawn number.\nIt all ends on a Big Bonus.$"

DaycareText_GetAlongVeryWell::
	.string "The two seem to get along very well.$"
DaycareText_GetAlong::
	.string "The two seem to get along.$"
DaycareText_DontLikeOther::
	.string "The two don't seem to like each other.$"
DaycareText_PlayOther::
	.string "The two prefer to play with other\nPokémon than each other.$"

gOtherText_NewLine2:: @ 842CC28
	.string "\n$"

gOtherText_CancelAndLv:: @ 842CC2A
	.string "Cancel$"
	.string "LV$"

gEggNickname:: @ 842CC34
	.string "Egg$"

gOtherText_HatchedFromEgg:: @ 842CC38
	.string "{COLOR WHITE2}{HIGHLIGHT TRANSPARENT}{SHADOW DARK_GREY}{STR_VAR_1} hatched from the Egg!$"

gOtherText_NickHatchPrompt:: @ 842CC5A
	.string "{COLOR WHITE2}{HIGHLIGHT TRANSPARENT}{SHADOW DARK_GREY}Would you like to nickname the newly\nhatched {STR_VAR_1}?$"

OtherText_Battle::
	.string "Battle$"
OtherText_Contest::
	.string "Contest$"
OtherText_Type::
	.string "Type/$"
OtherText_PP::
	.string "PP/$"
OtherText_Power::
	.string "Power$"
OtherText_Accuracy::
	.string "Accuracy$"
OtherText_Appeal::
	.string "Appeal$"
OtherText_Jam::
	.string "Jam$"

gOtherText_TeachWhichMove:: @ 842CCC7
	.string "Teach which move to {STR_VAR_1}?$"

gOtherText_TeachSpecificMove:: @ 842CCDF
	.string "Teach {STR_VAR_2}?$"

gOtherText_CantTeachEggMove::
    .string "No Pokémon in the party currently\nknows the move {STR_VAR_2}.$"

gOtherText_PokeLearnedMove:: @ 842CCE9
	.string "{STR_VAR_1} learned {STR_VAR_2}.$"

gOtherText_DeleteOlderMove:: @ 842CCF8
	.string "{STR_VAR_1} is trying to learn\n{STR_VAR_2}.\pBut {STR_VAR_1} can't learn more\nthan four moves.\pDelete an older move to make\nroom for {STR_VAR_2}?$"

gOtherText_StopLearningMove:: @ 842CD65
	.string "Stop learning {STR_VAR_2}?$"

gOtherText_ForgotMove123:: @ 842CD77
	.string "{PAUSE 32}1, {PAUSE 15}2 {PAUSE 15}...{PAUSE 15}...{PAUSE 15}...{PAUSE 15} {PLAY_SE 0x0038}Poof!\p$"

gOtherText_ForgotOrDidNotLearnMove:: @ 842CDA3
	.string "{STR_VAR_1} forgot {STR_VAR_3}.\pAnd...\p{STR_VAR_1} learned {STR_VAR_2}.$"
	.string "{STR_VAR_1} did not learn\n{STR_VAR_2}.$"

gOtherText_GiveUpTeachingMove:: @ 842CDDC
	.string "Give up trying to teach a new move\nto {STR_VAR_1}?$"

gOtherText_WhichMoveToForget:: @ 842CE06
	.string "Which move should be forgotten?\p$"

gSystemText_ClearAllSaveDataPrompt:: @ 842CE27
	.string "Clear all save data areas?$"

gSystemText_ClearingData:: @ 842CE42
	.string "Clearing data...\nPlease wait.$"

gContestText_AnnounceResults:: @ 842CE60
	.string "Announcing the results!$"

gContestText_PreliminaryResults:: @ 842CE78
	.string "The preliminary results!$"

gContestText_Round2Results:: @ 842CE91
	.string "Round 2 results!$"

gContestText_PokeWon:: @ 842CEA2
	.string "{STR_VAR_1}'s {STR_VAR_2} won!$"

gOtherText_LinkStandby:: @ 842CEAF
	.string "Link standby...$"

@ 842CEBF
	.include "data/text/landmarks.inc"

gOtherText_Terminator4:: @ 842D0E6
	.string "$"

gOtherText_Nature:: @ 842D0E7
	.string " nature, $"

gOtherText_Training::
	.string " training, $"

gOtherText_Comma:: @ 842D0F1
	.string ",$"

gOtherText_Met:: @ 842D0F3
	.string " (met).$"

gOtherText_Egg2:: @ 842D0FB
	.string " (Egg).$"

gOtherText_ObtainedInTrade:: @ 842D103
	.string "obtained in a trade.$"

gOtherText_FatefulEncounter:: @ 842D118
	.string "fateful encounter.$"

gOtherText_Met2:: @ 842D12B
	.string " (met).$"

gOtherText_EggDayCare:: @ 842D133
	.string "An odd Pokémon Egg found\nby the Day Care couple.$"

gOtherText_EggNicePlace:: @ 842D164
	.string "A peculiar Pokémon Egg\nobtained at the nice place.$"

gOtherText_EggObtainedInTrade:: @ 842D197
	.string "A peculiar Pokémon Egg\nobtained in a trade.$"

gOtherText_EggHotSprings:: @ 842D1C3
	.string "A Pokémon Egg obtained\nat the hot springs.$"

gOtherText_LinkStandby2:: @ 842D1EE
	.string "Link standby...$"

gOtherText_YesNoAndPlayer:: @ 842D1FE
	.string "{COLOR DARK_GREY}{HIGHLIGHT WHITE2}{SHADOW LIGHT_GREY}YES\nNO$"
	.string "{HIGHLIGHT TRANSPARENT}PLAYER$"
	.string "{HIGHLIGHT TRANSPARENT}$"

gOtherText_HoennDex:: @ 842D21C
	.string "HOENN$"

gOtherText_NationalDex:: @ 842D222
	.string "NATIONAL$"

gOtherText_DiplomaCertificationGameFreak:: @ 842D22B
	.string "{HIGHLIGHT TRANSPARENT}Player: {CLEAR 0x10}{COLOR RED}{PLAYER}\n\n{COLOR DARK_GREY}{STR_VAR_1} POKéDEX\nThis document certifies\nthat you have successfully\ncompleted your Pokédex.\n\n{CLEAR_TO 0x42}{COLOR RED}GAME FREAK$"
	.string "{COLOR RED}{HIGHLIGHT TRANSPARENT}GAME FREAK$"

gOtherText_PLink:: @ 842D2BC
	.string "{STR_VAR_1}P LINK$"

gOtherText_YesNoTerminating:: @ 842D2C5
	.string "YES\nNO$"
	.string "Terminating.$"

gOtherText_LinkNotFound:: @ 842D2D9
	.string "Link partner(s) not found.\nPlease try again.\p$"

gOtherText_BlenderChooseBerry:: @ 842D307
	.string "Starting up the Berry Blender.\pPlease select a Berry from your Bag\nto put in the Berry Blender.\p$"

gOtherText_PokeBlockMade:: @ 842D368
	.string " was made!$"

gOtherText_PressAToStart:: @ 842D373
	.string "Press the A Button to start.$"

gOtherText_PleaseWait:: @ 842D390
	.string "Please wait a while.$"

gOtherText_LinkStandby3:: @ 842D3A5
	.string "Link standby...$"

gOtherText_BlendAnotherBerryPrompt:: @ 842D3B5
	.string "Would you like to blend another Berry?$"

gOtherText_OutOfBerries:: @ 842D3DC
	.string "You've run out of Berries for\nblending in the Berry Blender.\p$"

gOtherText_CaseIsFull:: @ 842D41A
	.string "Your {POKEBLOCK} Case is full.\p$"

gOtherText_NoBerriesForBlend:: @ 842D434
	.string " has no Berries to put in\nthe Berry Blender.$"

gOtherText_OtherCaseIsFull:: @ 842D461
	.string "'s {POKEBLOCK} Case is full.\p$"

gOtherText_ResultsOfBlending:: @ 842D479
	.string "RESULTS OF BLENDING$"
	.string "BERRY USED$"

gOtherText_Berry:: @ 842D498
	.string " BERRY$"

gOtherText_RequiredTime:: @ 842D49F
	.string "REQUIRED TIME$"

gOtherText_Min:: @ 842D4AD
	.string "MIN.$"

gOtherText_Sec:: @ 842D4B2
	.string "SEC.$"

gOtherText_MaxSpeed:: @ 842D4B7
	.string "MAXIMUM SPEED$"

gOtherText_RPM:: @ 842D4C5
	.string "RPM$"
	.string ".$"

gOtherText_Ranking:: @ 842D4CB
	.string "RANKING$"

gOtherText_BlockLevelIs:: @ 842D4D3
	.string "The level is $"

gOtherText_BlockFeelIs:: @ 842D4E1
	.string ", and the feel is $"

gOtherText_Period:: @ 842D4F4
	.string ".$"

gOtherText_Day:: @ 842D4F6
	.string "DAY$"
	.string ":$"

gOtherText_OK:: @ 842D4FC
	.string "OK$"

gOtherText_CorrectTimePrompt:: @ 842D4FF
	.string "Is this the correct time?$"

gText_PkmnTransferredToPC::
    .string "{STR_VAR_2} was transferred to\n"
	.string "the Pokémon Storage System.$"
