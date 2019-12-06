// chkskill 
// by atu@sjfy 
#include <ansi.h>
inherit F_CLEAN_UP;

string *basic_skill = ({"axe","blade",
       "dagger",  //     �̱���
       "dodge",   //     ������
       "force",    //    �ڹ�
       "fork",     //    �淨
       "hammer",    //   ����
       "iron-cloth",//   Ӳ��
       "literate",//     ��д
       "magic",//        ����
       "move",//         �Ṧ
       "parry",//        �м�
       "perception",//   ������
       "scratching",//   ��֮��
       "cursism" ,//     ��ͷ��
       "spells",//       ����
       "staff",//        �ȷ�
       "stealing",//     ������
       "sword",//        ����
       "throwing",//     ����
       "unarmed",//      ȭ��
       "whip",//         �޷�
       "herb",//         ҩ��
       "spear",//        ǹ��
       "toxin",//        ����
}); 
int main(object me, string arg) 
{ 
	int w, val,level; 
	string dir,msg; 
	mixed *files; 
	mapping skl,lrn; 

	seteuid(getuid()); 

	if( !arg ) return notify_fail("ָ���ʽ��chkskill skill\n"); 

	skl = me->query_skills(); 
	lrn = me->query_learned(); 
	if (!skl) return notify_fail("��Ŀǰ��û��ѧ���κμ��ܡ�\n"); 
	if (!skl[arg]) return notify_fail("�㲻�����ּ��ܡ�\n"); 

	msg = "\n\n   "+to_chinese(arg)+" ("+arg+") \n"; 
	msg += HIG"��"NOR"��������������������������������������������������"HIG"��\n"NOR;

	level=SKILL_D(arg)->effective_level();
	if (!level) level=5;
	msg += sprintf(CYN"   ϵ  ����%d��\n",level*10); 

	val = sizeof(basic_skill); 
	while (val--) { 
		if (SKILL_D(arg)->valid_enable(basic_skill[val])) { 
			w++; 
			if(w==1) msg +="   ��  ;��"; 
			else msg +="           "; 
			msg += to_chinese(basic_skill[val])+
				" ("+basic_skill[val]+")\n"; 
		} 
	} 
	msg += NOR"  ��������������������������������������������������\n"; 
	write(msg); 
/*
	if(SKILL_D(arg)->type() != "martial") { 
		write("��"+to_chinese(arg)+"���������似��û�����⹥���������á�\n"); 
		return 1; 
	} 
*/
	if(member_array(arg, basic_skill)!= -1) { 
		write("��"+to_chinese(arg)+"�����ڻ������ܣ�û�����⹥���������á�\n"); 
		write(HIG"\n��"NOR"��������������������������������������������������"HIG"��\n"NOR);
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
		write("Ŀǰ��"+to_chinese(arg)+"��û���κ����⹥����\n"); 
		return 1;
	} 
	w = 0; 
	msg = CYN"  ���⹥��(perform)"HIW; 
	if(SKILL_D(arg)->valid_enable("force") ) msg = CYN"  �������� (exert)"HIW; 
	if (SKILL_D(arg)->valid_enable("spells") ) msg = CYN"  ��������(cast)"HIW; 
	if (SKILL_D(arg)->valid_enable("scratching") ) msg = CYN"  ��������(scribe)"HIW; 
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
	msg += HIG"\n��"NOR"��������������������������������"HIR" ��"HIY"���ͷ���"HIR"�� "NOR"����"HIG"��\n"NOR;
	if (w == 0) msg += "��"+to_chinese(arg)+"�����������С�\n"; 
	else 
		msg += "  ��"HIG+to_chinese(arg)+NOR"��Ŀǰ����"HIG+chinese_number(w)+NOR"������Ӧ�á�\n"; 
	write(msg+"\n"); 
	return 1; 
} 

int help(object me) 
{ 
write(@HELP 
ָ���ʽ: chkskill [<������>] 

�г����ֹ������е����⹥����ǰ��������������ܡ� 

������ 
chkskill yiqiforce 

���г����л�Ԫһ������exert�� 
HELP); 
	return 1; 
} 
