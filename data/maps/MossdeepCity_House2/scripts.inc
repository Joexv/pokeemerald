.set LOCALID_WINGULL, 3

MossdeepCity_House2_MapScripts::
	.byte 0

// EA House Script
EA_Talk_Script::
// EA House Script with updated dialogue and flag setting
lock
faceplayer
goto_if_set FLAG_GOT_STARTER_FROM_EA EA_After_Flag
msgbox Text_EA_Intro, MSGBOX_NPC
waitmessage

// EA continues with more dialogue about the situation and the task
msgbox Text_EA_Details, MSGBOX_NPC
waitmessage

// Offer Pokémon team choices
msgbox Text_EA_ChooseTeam, MSGBOX_YESNO
goto_if_eq Choose_Team1
goto Choose_Team2

Choose_Team1::
	msgbox Text_Team1_Description, MSGBOX_DEFAULT
	waitmessage
	// Show Pokémon sprites for Team 1 if possible
	showmonpic SPECIES_RAICHU, 10, 3
	showmonpic SPECIES_NIDOKING, 12, 3
	showmonpic SPECIES_PILOSWINE, 14, 3
	msgbox Text_Team1_Confirm, MSGBOX_YESNO
	goto_if_eq Give_Team1
	goto Choose_Team2

Choose_Team2::
	msgbox Text_Team2_Description, MSGBOX_DEFAULT
	waitmessage
	// Show Pokémon sprites for Team 2 if possible
	showmonpic SPECIES_FERALIGATR, 10, 3
	showmonpic SPECIES_SWELLOW, 12, 3
	showmonpic SPECIES_BRELOOM, 14, 3
	msgbox Text_Team2_Confirm, MSGBOX_YESNO
	goto_if_eq Give_Team2
	goto Choose_Team3

Choose_Team3::
	msgbox Text_Team3_Description, MSGBOX_DEFAULT
	waitmessage
	// Show Pokémon sprites for Team 3 if possible
	showmonpic SPECIES_MAROWAK, 10, 3
	showmonpic SPECIES_ARCANINE, 12, 3
	showmonpic SPECIES_GENGAR, 14, 3
	msgbox Text_Team3_Confirm, MSGBOX_YESNO
	goto_if_eq Give_Team3
	goto End

// Team 1 selected
Give_Team1::
	givemon SPECIES_RAICHU, 50, ITEM_NONE
	givemon SPECIES_NIDOKING, 50, ITEM_NONE
	givemon SPECIES_PILOSWINE, 50, ITEM_NONE
	msgbox Text_TeamGiven, MSGBOX_DEFAULT
	waitmessage
	goto Give_Pokeballs

// Team 2 selected
Give_Team2::
	givemon SPECIES_FERALIGATR, 50, ITEM_NONE
	givemon SPECIES_SWELLOW, 50, ITEM_NONE
	givemon SPECIES_BRELOOM, 50, ITEM_NONE
	msgbox Text_TeamGiven, MSGBOX_DEFAULT
	waitmessage
	goto Give_Pokeballs

// Team 3 selected
Give_Team3::
	givemon SPECIES_MAROWAK, 50, ITEM_NONE
	givemon SPECIES_ARCANINE, 50, ITEM_NONE
	givemon SPECIES_GENGAR, 50, ITEM_NONE
	msgbox Text_TeamGiven, MSGBOX_DEFAULT
	waitmessage
	goto Give_Pokeballs

Give_Pokeballs::
	msgbox Text_PokeballsGiven, MSGBOX_DEFAULT
	waitmessage

	// Set flag to indicate the dialogue is now different
	setflag FLAG_GOT_STARTER_FROM_EA
	setvar VAR_MOSSDEEP_CITY_STATE 0x02
	goto End

End::
	release
	end

// After the player has their Pokémon and the flag is set, EA's new behavior:

EA_After_Flag::
	lock
	faceplayer
	msgbox Text_EA_AfterFlag, MSGBOX_DEFAULT
	waitmessage

	// Offer to heal Pokémon
	msgbox Text_EA_HealOffer, MSGBOX_YESNO
	goto_if_eq Heal_Pokemon

Heal_Pokemon::
	msgbox Text_EA_Healing, MSGBOX_DEFAULT
	special HealPlayerParty
	waitmessage
End_After::
	release
	end

Text_EA_Intro:
	.string "{COLOR BLUE}EA{COLOR DARK_GRAY}: You've arrived just\p"
	.string "in time... The war is escalating,\n"
	.string "and we must act quickly.$"

Text_EA_Details:
	.string "{COLOR BLUE}EA{COLOR DARK_GRAY}: The forces of {COLOR GREEN}TIAMET\n"
	.string "{COLOR DARK_GRAY}are wreaking havoc...\n"
	.string "The wild POKÉMON are her creations,\n"
	.string "born of chaos and destruction.\p"
	.string "These creatures cannot be tamed by\n"
	.string "normal means, but I have found a way.$"

Text_EA_ChooseTeam:
	.string "{COLOR BLUE}EA{COLOR DARK_GRAY}: I will grant you a team\n"
	.string "of POKÉMON tamed using my magic.\p"
	.string "Choose wisely... Will you take Team 1?$"

Text_Team1_Description:
	.string "{COLOR BLUE}EA{COLOR DARK_GRAY}: Team 1 includes\n"
	.string "{COLOR GREEN}RAICHU{COLOR DARK_GRAY}, {COLOR GREEN}NIDOKING{COLOR DARK_GRAY},\n"
	.string "and {COLOR GREEN}PILOSWINE{COLOR DARK_GRAY}.$"

Text_Team1_Confirm:
	.string "{COLOR BLUE}EA{COLOR DARK_GRAY}: Do you want this team?$"

Text_Team2_Description:
	.string "{COLOR BLUE}EA{COLOR DARK_GRAY}: Team 2 includes\n"
	.string "{COLOR GREEN}FERALIGATR{COLOR DARK_GRAY}, {COLOR GREEN}SWELLOW{COLOR DARK_GRAY},\n"
	.string "and {COLOR GREEN}BRELOOM{COLOR DARK_GRAY}.$"

Text_Team2_Confirm:
	.string "{COLOR BLUE}EA{COLOR DARK_GRAY}: Do you want this team?$"

Text_Team3_Description:
	.string "{COLOR BLUE}EA{COLOR DARK_GRAY}: Team 3 includes\n"
	.string "{COLOR GREEN}MAROWAK{COLOR DARK_GRAY}, {COLOR GREEN}ARCANINE{COLOR DARK_GRAY},\n"
	.string "and {COLOR GREEN}GENGAR{COLOR DARK_GRAY}.$"

Text_Team3_Confirm:
	.string "{COLOR BLUE}EA{COLOR DARK_GRAY}: Do you want this team?$"

Text_TeamGiven:
	.string "{COLOR BLUE}EA{COLOR DARK_GRAY}: Take care of them.\n"
	.string "They are your allies, granted to you.$"

Text_EA_AfterFlag:
	.string "The battle is long, but we're\p"
	.string "making progress.$"

Text_EA_HealOffer:
	.string "{COLOR BLUE}EA{COLOR DARK_GRAY}: Shall I heal your\n"
	.string "POKÉMON?$"

Text_EA_Healing:
	.string "Your POKÉMON are now fully healed.$"

Text_PokeballsGiven:
	.string "You should head north to {COLOR GREEN}URUK{COLOR DARK_GRAY}.\p"
	.string "One of {COLOR GREEN}TIAMET's{COLOR DARK_GRAY} generals is\n"
	.string "hiding there. Defeat them to weaken\p"
	.string "{COLOR GREEN}TIAMET's{COLOR DARK_GRAY} forces.$"
	