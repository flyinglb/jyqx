// score.c
#define PKTIME_LIMIT 36000
#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string color);

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
       object ob;
       mapping my;
        string line, skill_type, parry_type;
       object weapon;
       int attack_points, dodge_points, parry_points;
	int continue_pks=0;
       seteuid(getuid(me));

       if(!arg)
                ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
	} else
		return notify_fail("��ֻ���Բ쿴�Լ���״̬��\n");

	my = ob->query_entire_dbase();
	line=HIG"��"NOR"��������������������������������������������������������������������"HIG"��\n"NOR;
	line+= sprintf("  %s\n", ob->short(1) );
	line+=HIG"��"NOR"��������������������������������������������������������������������"HIG"��\n"NOR;
	line+=sprintf(
GRN"    ��"WHT"����"GRN"��"WHT"%s"GRN"      -------------------------      ��"WHT"����"GRN"��"WHT"%s\n"
GRN"    ��"WHT"����"GRN"��"WHT"%s"GRN"      -------------------------    ��"WHT"��"GRN"��"WHT"%s\n"
                            display_attr(my["int"], ob->query_int()),
                        display_attr(my["con"], ob->query_con()),
                        display_attr(my["str"], ob->query_str()),
                        display_attr(my["agi"], ob->query_agi()),
	line+="  �������������������������������������������������������������������� \n"NOR;
	line += sprintf("     ����һ%s%s%s���%s%s������%s��\n",
                ob->query("unit"),
                ob->query("national"),
                chinese_number(ob->query("age")), 
                ob->query("gender"),
                ob->query("race"),
                CHINESE_D->chinese_date(((int)ob->query("birthday") - 5256000) * 60) );
	if ((int)my["mud_age"]-(int)my["last_pk_time"]<PKTIME_LIMIT )
		continue_pks=my["continue_pks"];
	line += sprintf(" �㹲ɱ��%s���ˣ�%sλ��ң�����PK%sλ������ɱ��%s�Ρ�\n",
		chinese_number(my["MKS"] + my["PKS"]), chinese_number(my["PKS"]),
		chinese_number(continue_pks),chinese_number(my["KILLED"])	);
	line += sprintf(" ĿǰΪֹ�������"HIG"%s"NOR"��"HIR"����ʹ��"NOR"��"HIG"%s"NOR"��"HIW"һ��ʹ��"NOR"��\n",
		chinese_number(my["special_score"]),chinese_number(my["TASK"]) );
	if(my["married"])
		line += sprintf("     ��Ļ������������������%s�λ飬������%s�λ顣\n",chinese_number(my["married"]),
			chinese_number(my["divorced"]) );
//	else if(my["marry"])
	if( mapp(my["family"]) ) {
		if( my["family"]["master_name"] )
			line+=sprintf("     ���ʦ����%s��",my["family"]["master_name"] );
			line += sprintf( " ������ʦ����"CYN"%d"NOR"����ҳ϶ȡ�\n" ,
me->query("class_score/"+my["family"]["family_name"]) );

	}
	line+="  �������������������������������������������������������������������� \n";
	line += sprintf(GRN"              ��"WHT"������Ʒ"GRN"��"WHT"%5d          " NOR, (int)ob->query("created_item") );
	line += sprintf(GRN"��"WHT"���췿��"GRN"��" WHT "  %d\n" NOR,(int)ob->query("created_room") );
	if( objectp(weapon = ob->query_temp("weapon")) ){
		skill_type = weapon->query("skill_type");
		parry_type = "parry";
	}else{
		skill_type = "unarmed";
		parry_type = "unarmed";
	}
	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, parry_type, SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);

	line +=sprintf(GRN"              ��"WHT"�� �� ��"GRN"��"WHT"%5d          "GRN"��"WHT"�� �� ��"GRN"��"WHT"  %d\n" NOR,
                ob->query_temp("apply/armor"),(dodge_points/2 + (weapon? parry_points: (parry_points/2))) + 1);
	line +=sprintf(GRN"              ��"WHT"ɱ �� ��"GRN"��"WHT"%5d          "GRN"��"WHT"�� �� ��"GRN"��"WHT"  %d\n" NOR,
                ob->query_temp("apply/damage"),attack_points + 1);
if ((int)ob->query("shen")<0)
	line +=sprintf(GRN"              ��"WHT"�� �� ��"GRN"��"WHT"%5d          "GRN"��"WHT"а    ��"GRN"��"WHT"  %d\n"NOR,ob->query("gift_points") - 
                       ob->query("used_gift_points"),-ob->query("shen"));
else
	line +=sprintf(GRN"              ��"WHT"�� �� ��"GRN"��"WHT"%5d          "GRN"��"WHT"��    ��"GRN"��"WHT"  %d\n"NOR,ob->query("gift_points") - 
                       ob->query("used_gift_points"),ob->query("shen"));
	line+=HIG"��"NOR"����������������������������"HIR" ��"HIY"�½�ӹȺϺ��II"HIR"�� "NOR"��������������������������"HIG"��\n"NOR;
       write(line);
       return 1;
}

string display_attr(int gift, int value)
{
        if( value > gift ) return sprintf( HIY "%3d /%3d" NOR, value,gift );
        else if( value < gift ) return sprintf( HIC "%3d /%3d" NOR, value,gift );
        else return sprintf("%3d /%3d", value,gift);
}

string status_color(int current, int max)
{
        int percent;

        if( max ) percent = current * 100 / max;
        else percent = 100;

        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return GRN;
        if( percent >= 10 ) return HIR;
        return RED;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : score
           
���ָ�������ʾ��Ļ������ϣ�
	see also : hp
HELP);
    return 1;
}
