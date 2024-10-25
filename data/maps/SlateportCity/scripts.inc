.set LOCALID_FAT_MAN, 1
.set LOCALID_MAN_1, 2
.set LOCALID_RICH_BOY, 3
.set LOCALID_GRUNT_1, 5
.set LOCALID_COOK, 6
.set LOCALID_OLD_WOMAN, 7
.set LOCALID_GIRL, 8
.set LOCALID_TY, 9
.set LOCALID_GABBY, 10
.set LOCALID_CAPT_STERN, 11
.set LOCALID_GRUNT_2, 18
.set LOCALID_GRUNT_3, 19
.set LOCALID_GRUNT_4, 26
.set LOCALID_GRUNT_5, 27
.set LOCALID_GRUNT_6, 28
.set LOCALID_GRUNT_7, 29
.set LOCALID_GRUNT_8, 30
.set LOCALID_GRUNT_9, 31
.set LOCALID_GRUNT_11, 33
.set LOCALID_SCOTT, 35

@ Note: LOCALID_SLATEPORT_ENERGY_GURU is a local id for this map used elsewhere. It's defined in event_objects.h

SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_SLATEPORT_CITY
	return
	
@ Stall/Shopkeeper 1 - General Goods Vendor
SlateportCity_EventScript_Stallkeeper1::
	lock
	faceplayer
	msgbox SlateportCity_Text_Stallkeeper1, MSGBOX_DEFAULT
	release
	end

SlateportCity_Text_Stallkeeper1:
	.string "Welcome, traveler!\p"
	.string "We have everything you need for the road.\n"
	.string "Our priest has called down {COLOR RED}Ishtar’s{COLOR DARK_GRAY} blessings\n"
	.string "to protect {COLOR GREEN}Uruk{COLOR DARK_GRAY} in these troubled times.$"

@ Stall/Shopkeeper 2 - Trinket Seller (Non-priest focus)
SlateportCity_EventScript_Stallkeeper2::
	lock
	faceplayer
	msgbox SlateportCity_Text_Stallkeeper2, MSGBOX_DEFAULT
	release
	end

SlateportCity_Text_Stallkeeper2:
	.string "Trinkets, talismans, and charms for luck!\n"
	.string "{COLOR GREEN}Uruk{COLOR DARK_GRAY}'s been bustling lately with preparations.\p"
	.string "{COLOR BLUE}Marduk’s{COLOR DARK_GRAY} army is growing, and the tension is\n"
	.string "palpable - the gods must be planning something big.$"

@ Stall/Shopkeeper 3 - Weapon Merchant
SlateportCity_EventScript_Stallkeeper3::
	lock
	faceplayer
	msgbox SlateportCity_Text_Stallkeeper3, MSGBOX_DEFAULT
	release
	end

SlateportCity_Text_Stallkeeper3:
	.string "Warriors, gear up!\n"
	.string "{COLOR BLUE}Marduk{COLOR DARK_GRAY} gathers an army to defeat {COLOR RED}Tiamet{COLOR DARK_GRAY},\n"
	.string "and the priest is working tirelessly to\n"
	.string "support the cause. You’ll need fine weapons\n"
	.string "for the coming battle!$"

@ Shopper 1 - Enthusiastic Visitor (Priest’s absence)
SlateportCity_EventScript_Shopper1::
	lock
	faceplayer
	msgbox SlateportCity_Text_Shopper1, MSGBOX_DEFAULT
	release
	end

SlateportCity_Text_Shopper1:
	.string "I haven't seen the priest in days…\n"
	.string "He went into the {COLOR GREEN}temple{COLOR DARK_GRAY} with a strange\n"
	.string "visitor, and no one’s heard from him since.\p"
	.string "It’s got the city worried with {COLOR BLUE}Marduk’s{COLOR DARK_GRAY}\n"
	.string "army gathering.$"

@ Shopper 2 - Bargain Hunter (Non-priest focus)
SlateportCity_EventScript_Shopper2::
	lock
	faceplayer
	msgbox SlateportCity_Text_Shopper2, MSGBOX_DEFAULT
	release
	end

SlateportCity_Text_Shopper2:
	.string "The {COLOR GREEN}market{COLOR DARK_GRAY}'s lively with talk of {COLOR BLUE}Marduk{COLOR DARK_GRAY}\n"
	.string "assembling an army to fight {COLOR RED}Tiamet{COLOR DARK_GRAY}.\p"
	.string "I better stock up before supplies run\n"
	.string "low. With everything going on, you never\n"
	.string "know what might happen next.$"

@ Generic 1 - City Background (Non-priest focus)
SlateportCity_EventScript_Generic1::
	lock
	faceplayer
	msgbox SlateportCity_Text_Generic1, MSGBOX_DEFAULT
	release
	end

SlateportCity_Text_Generic1:
	.string "{COLOR GREEN}Uruk{COLOR DARK_GRAY}, the city of trade and strength!\p"
	.string "People come from all across the lands\n"
	.string "to barter in its grand {COLOR GREEN}markets{COLOR DARK_GRAY}.$"

@ Generic 2 - Old Town Gossip (Priest mention)
SlateportCity_EventScript_Generic2::
	lock
	faceplayer
	msgbox SlateportCity_Text_Generic2, MSGBOX_DEFAULT
	release
	end

SlateportCity_Text_Generic2:
	.string "I've seen {COLOR GREEN}Uruk{COLOR DARK_GRAY} grow since I was a child.\p"
	.string "The city owes much to the priest’s guidance,\n"
	.string "bringing both {COLOR RED}Ishtar's{COLOR DARK_GRAY} blessings and {COLOR BLUE}Marduk’s{COLOR DARK_GRAY} plans\n"
	.string "for the battle ahead.$"

SlateportCity_EventScript_Man1::
    lock
    faceplayer
    msgbox SlateportCity_Text_Generic2, MSGBOX_DEFAULT
    release
    end

SlateportCity_EventScript_NameRatersHouseSign::
    end
