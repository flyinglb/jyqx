// globals.h
// this file will be automatically included by the driver

#ifndef __SENSIBLE_MODIFIERS__
#define nosave  static
#define protect static
#endif

#include <ansi.h>

#define CONVERT_D	        "/adm/daemons/convertd.c"
#define F_ENCODING              "/feature/encoding.c"
#define PRIVATE_ROOM	        "/inherit/private_room.c"
#define RECORDABLE_ROOM	        "/inherit/recordable_room.c"
#define CHATTING_ROOM         "/inherit/room/chattingroom.c"
#define ROOM_D		        "/adm/daemons/roomd.c"	
#define PAWN		        "/feature/pawn"
#define F_BANKER		"/feature/banker"
#define QUEST_OB		"/feature/quest_list"
#define EXPLIST		        "/clone/quest/explist"
#define WAIMAO_D	        "/adm/daemons/waimaod"
#define EVENT_D                "/adm/daemons/eventd"
//for TOPTEN
#define TOPTEN_RICH 	        "/topten/rich.txt"
#define TOPTEN_PKER	        "/topten/pker.txt"
#define TOPTEN_EXP	        "/topten/exp.txt"
#define TOPTEN_SHEN1	        "/topten/shen1.txt"
#define TOPTEN_SHEN2	        "/topten/shen2.txt"
#define TOPTEN_NEILI	        "/topten/neili.txt"
#define TOPTEN_PER1		"/topten/per1.txt"
#define TOPTEN_PER2		"/topten/per2.txt"
#define TOPTEN_AGE		"/topten/age.txt"
#define RICH_B 		        "��ӹȺ����TOP TENʮ�������а�"
#define PKER_B 		        "��ӹȺ����TOP TENʮ��ɱ�˿����а�"
#define EXP_B  		        "��ӹȺ����TOP TENʮ��EXP�������а�"
#define SHEN1_B 		"��ӹȺ����TOP TENʮ���������а�"
#define SHEN2_B 		"��ӹȺ����TOP TENʮ��ħͷ���а�"
#define NEILI_B		        "��ӹȺ����TOP TENʮ�������������а�"
#define PER1_B		        "��ӹȺ����TOP TENʮ��˧�����а�"
#define PER2_B		        "��ӹȺ����TOP TENʮ���������а�"
#define AGE_B		        "��ӹȺ����TOP TENʮ����������а�"
#define TOPTEN_D		"/adm/daemons/toptend"
#define WHO_D                   "/adm/daemons/whod"

// Important directories
#define INC_DIR		        "/include/"
#define COMMAND_DIR	        "/cmds/"
#define CONFIG_DIR	        "/adm/etc/"
#define DATA_DIR		"/data/"
#define HELP_DIR		"/doc/help/"
#define LOG_DIR		        "/log/"

// Daemons
#define ALIAS_D		        "/adm/daemons/aliasd"
#define BAN_D		        "/adm/daemons/band"
#define CHANNEL_D		"/adm/daemons/channeld"
#define CHAR_D		        "/adm/daemons/chard"
#define CHINESE_D		"/adm/daemons/chinesed"
#define COMBAT_D		"/adm/daemons/combatd"
#define COMMAND_D		"/adm/daemons/commandd"
#define EMOTE_D		        "/adm/daemons/emoted"
#define FINGER_D		"/adm/daemons/fingerd"
#define FTP_D		        "/adm/daemons/ftpd"
#define INQUIRY_D		"/adm/daemons/inquiryd"
#define LOGIN_D		        "/adm/daemons/logind"
#define MONEY_D		        "/adm/daemons/moneyd"
#define NATURE_D		"/adm/daemons/natured"
#define PIG_D		        "/adm/daemons/pigd"
#define PROFILE_D		"/adm/daemons/profiled"
#define RANK_D		        "/adm/daemons/rankd"
#define SECURITY_D	        "/adm/daemons/securityd"
#define UPDATE_D		"/adm/daemons/updated"
#define VIRTUAL_D		"/adm/daemons/virtuald"
#define WEAPON_D		"/adm/daemons/weapond"
#define DNS_D                   "/adm/daemons/network/dns_master"
#define STATUS_D                "/adm/daemons/statusd"
#define LANGUAGE_D              "/adm/daemons/languaged"
#define CRON_D			"/adm/daemons/cron"
#define TASK_D			"/adm/daemons/questd"


// End of appendence
#define CLASS_D(x)	        ("/kungfu/class/" + x)
#define SKILL_D(x)	        ("/kungfu/skill/" + x)
#define CONDITION_D(x)	        ("/kungfu/condition/" + x)

// Added for questing
// by Hop, 1997.05.16
#define QUESTH_D(x)             ("/quest/qhlist" + x)
#define QUESTS_D(x)             ("/quest/qslist" + x)
#define QUESTW_D(x)             ("/quest/qwlist" + x)

// Clonable/Non-inheritable Standard Objects
#define THGOLD_OB               "/clone/money/thousand-gold" 
#define THCASH_OB               "/clone/money/thousand-cash"
#define COIN_OB		        "/clone/money/coin"
#define CORPSE_OB		"/clone/misc/corpse"
#define GOLD_OB		        "/clone/money/gold"
#define LOGIN_OB		"/clone/user/login"
#define MASTER_OB		"/adm/single/master"
#define MAILBOX_OB	        "/clone/misc/mailbox"
#define SILVER_OB		"/clone/money/silver"
#define SIMUL_EFUN_OB	        "/adm/single/simul_efun"
#define USER_OB		        "/clone/user/user"
#define VOID_OB		        "/clone/misc/void"

// Inheritable Standard Objects
#define BANK		        "/inherit/room/bank"
#define BULLETIN_BOARD	        "/inherit/misc/bboard"
#define W_BOARD                 "/inherit/misc/wboard"
#define CHARACTER		"/inherit/char/char"
#define COMBINED_ITEM	        "/inherit/item/combined"
#define EQUIP		        "/inherit/misc/equip"
#define FORCE		        "/inherit/skill/force"
#define HOCKSHOP		"/inherit/room/hockshop"
#define ITEM		        "/inherit/item/item"
#define LIQUID		        "/inherit/food/liquid"
#define MONEY		        "/inherit/item/money"
#define NPC			"/inherit/char/npc"
#define PILL		        "/inherit/medicine/pill"
#define POWDER		        "/inherit/medicine/powder"
#define ROOM		        "/inherit/room/room"
#define SKILL		        "/inherit/skill/skill"

// User IDs

#define ROOT_UID		"Root"
#define BACKBONE_UID	        "Backbone"

// Features

#define F_ACTION		"/feature/action.c"
#define F_ALIAS			"/feature/alias.c"
#define F_APPRENTICE		"/feature/apprentice.c"
#define F_ATTACK		"/feature/attack.c"
#define F_ATTRIBUTE		"/feature/attribute.c"
#define F_AUTOLOAD		"/feature/autoload.c"
#define F_AUTOSAVE              "/feature/autosave.c"
#define F_CLEAN_UP		"/feature/clean_up.c"
#define F_COMMAND		"/feature/command.c"
#define F_CONDITION		"/feature/condition.c"
#define F_DAMAGE		"/feature/damage.c"
#define F_DBASE			"/feature/dbase.c"
#define F_DEALER		"/feature/dealer.c"
#define F_EDIT			"/feature/edit.c"
#define F_EQUIP			"/feature/equip.c"
#define F_FINANCE		"/feature/finance.c"
#define F_FOOD			"/feature/food.c"
#define F_PILL			"/feature/pill.c"
#define F_LIQUID		"/feature/liquid.c"
#define F_MASTER		"/inherit/char/master.c"
#define F_MESSAGE		"/feature/message.c"
#define F_MORE			"/feature/more.c"
#define F_MOVE			"/feature/move.c"
#define F_NAME			"/feature/name.c"
#define F_SAVE			"/feature/save.c"
#define F_SKILL			"/feature/skill.c"
#define F_TEAM			"/feature/team.c"
#define F_TREEMAP		"/feature/treemap.c"
#define F_VENDOR		"/feature/dealer.c"
#define F_SSERVER		"/feature/sserver.c"
#define F_UNIQUE		"/feature/unique.c"

#define driver_version()                __VERSION__
#define base_version()                  MUDLIB_VERSION_NUMBER
#define REBOOTFILE                  LOG_DIR"static/REBOOT"
// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#undef PROFILE_COMMANDS
