// chkskill 
// by atu@sjfy 
#include <ansi.h>
inherit F_CLEAN_UP;

string *basic_skill = ({"axe","blade",
       "dagger",  //     短兵刃
       "dodge",   //     闪躲术
       "force",    //    内功
       "fork",     //    叉法
       "hammer",    //   锤法
       "iron-cloth",//   硬功
       "literate",//     读写
       "magic",//        法术
       "move",//         轻功
       "parry",//        招架
       "perception",//   听风术
       "scratching",//   符之术
       "cursism" ,//     降头术
       "spells",//       咒文
       "staff",//        杖法
       "stealing",//     妙手术
       "sword",//        剑法
       "throwing",//     暗器
       "unarmed",//      拳脚
       "whip",//         鞭法
       "herb",//         药道
       "spear",//        枪法
       "toxin",//        毒术
}); 
int main(object me, string arg) 
{ 
	int w, val,level; 
	string dir,msg; 
	mixed *files; 
	mapping skl,lrn; 

	seteuid(getuid()); 

	if( !arg ) return notify_fail("指令格式：chkskill skill\n"); 

	skl = me->query_skills(); 
	lrn = me->query_learned(); 
	if (!skl) return notify_fail("你目前并没有学会任何技能。\n"); 
	if (!skl[arg]) return notify_fail("你不会这种技能。\n"); 

	msg = "\n\n   "+to_chinese(arg)+" ("+arg+") \n"; 
	msg += HIG"≡"NOR"─────────────────────────"HIG"≡\n"NOR;

	level=SKILL_D(arg)->effective_level();
	if (!level) level=5;
	msg += sprintf(CYN"   系  数：%d﹪\n",level*10); 

	val = sizeof(basic_skill); 
	while (val--) { 
		if (SKILL_D(arg)->valid_enable(basic_skill[val])) { 
			w++; 
			if(w==1) msg +="   用  途："; 
			else msg +="           "; 
			msg += to_chinese(basic_skill[val])+
				" ("+basic_skill[val]+")\n"; 
		} 
	} 
	msg += NOR"  ─────────────────────────\n"; 
	write(msg); 
/*
	if(SKILL_D(arg)->type() != "martial") { 
		write("「"+to_chinese(arg)+"」不属于武技，没有特殊攻击或者运用。\n"); 
		return 1; 
	} 
*/
	if(member_array(arg, basic_skill)!= -1) { 
		write("「"+to_chinese(arg)+"」属于基本技能，没有特殊攻击或者运用。\n"); 
		write(HIG"\n≡"NOR"─────────────────────────"HIG"≡\n"NOR);
		return 1; 
	} 
	if ( SKILL_D(arg)->perform_action_file()) { 
		dir=SKILL_D(arg)->perform_action_file(); 
	} else if ( SKILL_D(arg)->cast_spell_file()) { 
		dir=SKILL_D(arg)->cast_spell_file(); 
	} else if ( SKILL_D(arg)->exert_function_file()) { 
		dir=SKILL_D(arg)->exert_function_file(); 
	} else if ( SKILL_D(arg)->scribe_spell_file()) { 
		dir=SKILL_D(arg)->scribe_spell_file(); 
	} else dir="daemon/class/null"; 

	dir = replace_string(dir,"/0","/"); 
	files = get_dir(dir); 
	if( !sizeof(files) ) { 
		write("目前「"+to_chinese(arg)+"」没有任何特殊攻击。\n"); 
		return 1;
	} 
	w = 0; 
	msg = CYN"  特殊攻击(perform)"HIW; 
	if(SKILL_D(arg)->valid_enable("force") ) msg = CYN"  特殊运用 (exert)"HIW; 
	if (SKILL_D(arg)->valid_enable("spells") ) msg = CYN"  特殊运用(cast)"HIW; 
	if (SKILL_D(arg)->valid_enable("scratching") ) msg = CYN"  特殊运用(scribe)"HIW; 
	write(msg+"\n");
	msg="";
	foreach (string file in files){ 
		if(file[strlen(file)-2..strlen(file)] != ".c") continue; 
		file= replace_string(file,".c",""); 
		msg+=sprintf("       %-15s     ",file); 
		if(w%2)
			msg+="\n";
		w++;
	} 
	msg += HIG"\n≡"NOR"────────────────"HIR" ☆"HIY"世纪风云"HIR"☆ "NOR"──"HIG"≡\n"NOR;
	if (w == 0) msg += "「"+to_chinese(arg)+"」正在整理中。\n"; 
	else 
		msg += "  「"HIG+to_chinese(arg)+NOR"」目前共有"HIG+chinese_number(w)+NOR"种特殊应用。\n"; 
	write(msg+"\n"); 
	return 1; 
} 

int help(object me) 
{ 
write(@HELP 
指令格式: chkskill [<功夫名>] 

列出这种功夫所有的特殊攻击，前题是你必须会这项技能。 

范例： 
chkskill yiqiforce 

会列出所有混元一气功的exert。 
HELP); 
	return 1; 
} 
