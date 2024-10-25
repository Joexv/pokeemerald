.set LOCALID_FAMILIAR_GRUNT, 13

SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

@ Receptionist 1 - Check for Tiamet Soldiers
SlateportCity_EventScript_Receptionist1::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS, SlateportCity_EventScript_Receptionist1_Normal
	goto SlateportCity_EventScript_Receptionist1_Frightened
	end

@ Receptionist 1 - Frightened State (before the flag is set)
SlateportCity_EventScript_Receptionist1_Frightened::
	msgbox SlateportCity_Text_Receptionist1_Frightened, MSGBOX_DEFAULT
	release
	end

@ Receptionist 1 - Normal State (after the flag is set)
SlateportCity_EventScript_Receptionist1_Normal::
	msgbox SlateportCity_Text_Receptionist1_Normal, MSGBOX_DEFAULT
	release
	end

@ Receptionist 2 - Check for Tiamet Soldiers
SlateportCity_EventScript_Receptionist2::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS, SlateportCity_EventScript_Receptionist2_Priest
	goto SlateportCity_EventScript_Receptionist2_Frightened
	end

@ Receptionist 2 - Frightened State (before the flag is set)
SlateportCity_EventScript_Receptionist2_Frightened::
	msgbox SlateportCity_Text_Receptionist2_Frightened, MSGBOX_DEFAULT
	release
	end

@ Receptionist 2 - Priest Mention (after the flag is set)
SlateportCity_EventScript_Receptionist2_Priest::
	msgbox SlateportCity_Text_Receptionist2_Priest, MSGBOX_DEFAULT
	release
	end

@ Grunt 1 - Aggressive Dialog
SlateportCity_EventScript_Grunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_Grunt1, MSGBOX_DEFAULT
	release
	end

SlateportCity_Text_Grunt1:
	.string "You’re not welcome here.\p"
	.string "Get lost before you regret stepping\n"
	.string "into {COLOR GREEN}Ishtar's Temple{COLOR DARK_GRAY}, stranger!$"

@ Grunt 2 - Aggressive Dialog
SlateportCity_EventScript_Grunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_Grunt2, MSGBOX_DEFAULT
	release
	end

SlateportCity_Text_Grunt2:
	.string "The priest was foolish to resist {COLOR RED}Tiamet{COLOR DARK_GRAY}.\p"
	.string "You better not be as foolish.$"

@ Grunt 3 - Aggressive Dialog
SlateportCity_EventScript_Grunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_Grunt3, MSGBOX_DEFAULT
	release
	end

SlateportCity_Text_Grunt3:
	.string "Stay out of our way, or you’ll find\n"
	.string "yourself in serious trouble!$"

@ Grunt 4 - Aggressive Dialog
SlateportCity_EventScript_Grunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_Grunt4, MSGBOX_DEFAULT
	release
	end

SlateportCity_Text_Grunt4:
	.string "We serve {COLOR RED}Tiamet{COLOR DARK_GRAY} now.\p"
	.string "Nothing can stop her from taking this\n"
	.string "{COLOR GREEN}temple{COLOR DARK_GRAY}, not even {COLOR RED}Ishtar{COLOR DARK_GRAY}’s blessings!$"

@ Grunt 5 - Aggressive Dialog
SlateportCity_EventScript_Grunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_Grunt5, MSGBOX_DEFAULT
	release
	end

SlateportCity_Text_Grunt5:
	.string "Move along, or I’ll make you move.\n"
	.string "This place belongs to {COLOR RED}Tiamet{COLOR DARK_GRAY} now.$"

@ Grunt 6 - Aggressive Dialog
SlateportCity_EventScript_Grunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_Grunt6, MSGBOX_DEFAULT
	release
	end

SlateportCity_Text_Grunt6:
	.string "You think {COLOR RED}Ishtar{COLOR DARK_GRAY} can protect you?\n"
	.string "You’ll be the first to fall when {COLOR RED}Tiamet{COLOR DARK_GRAY}\n"
	.string "takes her throne.$"

@ Grunt 7 - Aggressive Dialog
SlateportCity_EventScript_Grunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_Grunt7, MSGBOX_DEFAULT
	release
	end

SlateportCity_Text_Grunt7:
	.string "This {COLOR GREEN}temple{COLOR DARK_GRAY} is ours now.\p"
	.string "No one can save you. Not {COLOR RED}Ishtar{COLOR DARK_GRAY},\n"
	.string "and certainly not this sad excuse for a priest.$"

@
SlateportCity_Text_Receptionist1_Frightened:
.string "I'm so scared... What will we do?$"

SlateportCity_Text_Receptionist1_Normal:
	.string "Welcome to {COLOR GREEN}Ishtar's Temple{COLOR DARK_GRAY}.\n"
	.string "We offer blessings and guidance to\n"
	.string "those in need. How can we assist you?$"

SlateportCity_Text_Receptionist2_Frightened:
	.string "Please, help us...\n"
	.string "The soldiers of {COLOR RED}Tiamet{COLOR DARK_GRAY} have forced their way in.\n"
	.string "We don’t know what will happen next...$"

SlateportCity_Text_Receptionist2_Priest:
	.string "The priest has been missing for days now...\n"
	.string "He went into the {COLOR GREEN}temple{COLOR DARK_GRAY} with a strange visitor,\n"
	.string "and no one’s seen him since.$"
	