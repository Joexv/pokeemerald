.set LOCALID_WINGULL, 3

MossdeepCity_House2_MapScripts::
	.byte 0

// EA House Script
EA_Talk_Script::
// EA House Script with updated dialogue and flag setting
lock
faceplayer
msgbox Text_EA_Intro, MSGBOX_NPC
waitmessage

// EA continues with more dialogue about the situation and the task
msgbox Text_EA_Details, MSGBOX_NPC
waitmessage

// Offer Pokémon team choices
msgbox Text_EA_ChooseTeam, MSGBOX_YESNO
goto_if_eq Choose_Team1
goto Choose_Team2

Choose_Team1:
	msgbox Text_Team1_Description, MSGBOX_DEFAULT
	waitmessage
	// Show Pokémon sprites for Team 1 if possible
	showmonpic SPECIES_, 10, 3
	showmonpic SPECIES_NIDORAN_F, 12, 3
	showmonpic SPECIES_SWINUB, 14, 3
	msgbox Text_Team1_Confirm, MSGBOX_YESNO
	goto_if_eq Give_Team1
	goto Choose_Team2

Choose_Team2:
	msgbox Text_Team2_Description, MSGBOX_DEFAULT
	waitmessage
	// Show Pokémon sprites for Team 2 if possible
	showmonpic SPECIES_FERALIGATR, 10, 3
	showmonpic SPECIES_SWELLOW, 12, 3
	showmonpic SPECIES_BRELOOM, 14, 3
	msgbox Text_Team2_Confirm, MSGBOX_YESNO
	goto_if_eq Give_Team2
	goto Choose_Team3

Choose_Team3:
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
Give_Team1:
	givemon SPECIES_RAICHU, 50, ITEM_NONE
	givemon SPECIES_NIDOKING, 50, ITEM_NONE
	givemon SPECIES_PILOSWINE, 50, ITEM_NONE
	msgbox Text_TeamGiven, MSGBOX_DEFAULT
	waitmessage
	goto Give_Pokeballs

// Team 2 selected
Give_Team2:
	givemon SPECIES_FERALIGATR, 50, ITEM_NONE
	givemon SPECIES_SWELLOW, 50, ITEM_NONE
	givemon SPECIES_BRELOOM, 50, ITEM_NONE
	msgbox Text_TeamGiven, MSGBOX_DEFAULT
	waitmessage
	goto Give_Pokeballs

// Team 3 selected
Give_Team3:
	givemon SPECIES_MAROWAK, 50, ITEM_NONE
	givemon SPECIES_ARCANINE, 50, ITEM_NONE
	givemon SPECIES_GENGAR, 50, ITEM_NONE
	msgbox Text_TeamGiven, MSGBOX_DEFAULT
	waitmessage
	goto Give_Pokeballs

Give_Pokeballs:
	// Give the player 5 Pokéballs after giving Pokémon
	giveitem ITEM_POKE_BALL, 5
	msgbox Text_PokeballsGiven, MSGBOX_DEFAULT
	waitmessage

	// Set flag to indicate the dialogue is now different
	setflag FLAG_GOT_STARTER_FROM_EA
	goto End

End:
	release
	end

// After the player has their Pokémon and the flag is set, EA's new behavior:

EA_After_Flag:
	lock
	faceplayer
	msgbox Text_EA_AfterFlag, MSGBOX_DEFAULT
	waitmessage

	// Offer to heal Pokémon
	msgbox Text_EA_HealOffer, MSGBOX_YESNO
	goto_if_eq Heal_Pokemon
	goto Check_Pokeballs

Heal_Pokemon:
	msgbox Text_EA_Healing, MSGBOX_DEFAULT
	special healparty
	waitmessage
	goto Check_Pokeballs

Check_Pokeballs:
	// Check if the player has no Pokéballs and give them 10 if necessary
	checkitem ITEM_POKE_BALL, 1
	compare VAR_RESULT, 0
	goto_if_eq Give_10_Pokeballs
	goto End_After

Give_10_Pokeballs:
	giveitem ITEM_POKE_BALL, 10
	msgbox Text_PokeballsGivenAgain, MSGBOX_DEFAULT
	waitmessage

End_After:
	release
	end

// Text Definitions
Text_EA_Intro:
	.string "{COLOR RED}EA{COLOR DARK_GRAY}: You've arrived just in time...\p"
	.string "The war is escalating, and we must act quickly.$"

Text_EA_Details:
	.string "{COLOR RED}EA{COLOR DARK_GRAY}: The forces of {COLOR GREEN}TIAMET{COLOR DARK_GRAY} are wreaking havoc...\n"
	.string "The wild POKÉMON you see are her creations, born of chaos and destruction.\p"
	.string "These creatures cannot be tamed by normal means, but I have devised a way to control them.\p"
	.string "Using my magic, I have created special spheres, {COLOR GREEN}POKÉBALLS{COLOR DARK_GRAY}, that can trap the monsters.\p"
	.string "Within these balls, the POKÉMON are imbued with my power, allowing them to obey you.$"

Text_EA_ChooseTeam:
	.string "{COLOR RED}EA{COLOR DARK_GRAY}: I will grant you a team of POKÉMON that I have tamed using my magic.\n"
	.string "These will be your allies in this war. Choose wisely... Will you take the first team?$"

Text_Team1_Description:
	.string "{COLOR RED}EA{COLOR DARK_GRAY}: Team 1 includes {COLOR GREEN}RAICHU{COLOR DARK_GRAY},\n"
	.string "{COLOR GREEN}NIDOKING{COLOR DARK_GRAY}, and {COLOR GREEN}PILOSWINE{COLOR DARK_GRAY}.$"

Text_Team1_Confirm:
	.string "{COLOR RED}EA{COLOR DARK_GRAY}: Do you want this team?$"

Text_Team2_Description:
	.string "{COLOR RED}EA{COLOR DARK_GRAY}: Team 2 includes {COLOR GREEN}FERALIGATR{COLOR DARK_GRAY},\n"
	.string "{COLOR GREEN}SWELLOW{COLOR DARK_GRAY}, and {COLOR GREEN}BRELOOM{COLOR DARK_GRAY}.$"

Text_Team2_Confirm:
	.string "{COLOR RED}EA{COLOR DARK_GRAY}: Do you want this team?$"

Text_Team3_Description:
	.string "{COLOR RED}EA{COLOR DARK_GRAY}: Team 3 includes {COLOR GREEN}MAROWAK{COLOR DARK_GRAY},\n"
	.string "{COLOR GREEN}ARCANINE{COLOR DARK_GRAY}, and {COLOR GREEN}GENGAR{COLOR DARK_GRAY}.$"

Text_Team3_Confirm:
	.string "{COLOR RED}EA{COLOR DARK_GRAY}: Do you want this team?$"

Text_TeamGiven:
	.string "{COLOR RED}EA{COLOR DARK_GRAY}: Take care of them.\n"
	.string "They are your allies, granted to you through my magic.$"

Text_PokeballsGiven:
	.string "{COLOR RED}EA{COLOR DARK_GRAY}: Here, take these {COLOR GREEN}POKÉBALLS{COLOR DARK_GRAY}.\n"
	.string "With them, you can capture any wild POKÉMON that Tiamet sends against us.$"

Text_EA_AfterFlag:
	.string "{COLOR RED}EA{COLOR DARK_GRAY}: How are you doing?\n"
	.string "The battle is long, but we are making progress.$"

Text_EA_HealOffer:
	.string "{COLOR RED}EA{COLOR DARK_GRAY}: Would you like me to heal your POKÉMON?$"

Text_EA_Healing:
	.string "{COLOR RED}EA{COLOR DARK_GRAY}: Your POKÉMON are now fully healed.$"

Text_PokeballsGivenAgain:
	.string "{COLOR RED}EA{COLOR DARK_GRAY}: It looks like you're out of {COLOR GREEN}POKÉBALLS{COLOR DARK_GRAY}.\n"
	.string "Here, take these to keep going.$"