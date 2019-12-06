// score.c

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

//string *gift_ranking = ({"����֮ѡ","�µ�", "����", "�е�", "����", "�ϵ�",
//	"����֮ѡ"});

string bar_string = "��������������������������������������������������";
string blank_string = "��������������������������������������������������";
//string bar_string = "�������������������������������������������������";
//string blank_string= "�񡪡���������������������������������������������";

string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string color);

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
	object ob;
	mapping my;
	string line, str, skill_type;
	object weapon;
	int attack_points, dodge_points, parry_points;

	seteuid(getuid(me));

	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
	} else
		return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");

	my = ob->query_entire_dbase();

	line = sprintf( BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(ob), ob->short(1) );
	if (userp(ob))
	line += sprintf(" ����һ%s%s��%s���µ�%s%s��%s����\n",
		ob->query("unit"),
		chinese_number(ob->query("age")), 
		chinese_number((ob->query("mud_age")-(ob->query("age")-14)*86400)/7200 + 1 ), 
		ob->query("gender"),
		ob->query("race"),
		CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) );
	else
	line += sprintf(" ����һ%s%s���%s%s��%s����\n",
		ob->query("unit"),
		chinese_number(ob->query("age")), 
		ob->query("gender"),
		ob->query("race"),
		CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) );

	if( 1 || wizardp(me) || (int)ob->query("age") >= 18 ) {
		line += sprintf(
			" ������[%s]  ���ԣ�[%s]  ���ǣ�[%s]  ����[%s]\n\n", 
			display_attr(my["str"], ob->query("str")),
			display_attr(my["int"], ob->query("int")),
			display_attr(my["con"], ob->query("con")),
			display_attr(my["dex"], ob->query("dex")));
	}

	if (userp(ob))
	{
		if( mapp(my["family"]) ) {
			if( my["family"]["master_name"] )
				line = sprintf("%s ���ʦ����%s��",
					line, my["family"]["master_name"] );
		}
		if ((int)ob->query("balance") > 0)
			line += "             ��" + MONEY_D->money_str((int)ob->query("balance")) + "��\n";
		else
			line += "             ��û�д�\n";
		if (!ob->query("couple/couple_name"))
		{
			if (ob->query("gender")=="Ů��")
				if (ob->query("age")<30) line += " �����ڴ��ֹ��С�\n\n";
				else line += " �����ڻ��Ǹ�������塣\n\n";
			else
			line += " �㻹�Ǹ������\n\n";
		}
		else
			line += " ��İ����� "+ob->query("couple/couple_name")+"��\n\n";
	}

	line += " <��>  " + tribar_graph(my["jing"], my["eff_jing"], my["max_jing"], GRN) + "\n";
	line += " <��>  " + tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], HIR) + "\n";
//	line += " <��>  " + tribar_graph(my["sen"], my["eff_sen"], my["max_sen"], HIB) + "\n";

	if( objectp(weapon = ob->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		skill_type = "unarmed";

	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);

//    if (wizardp(me))
	line += sprintf("\n ս�������� " HIW "%8d" NOR "\t\tս�������� " HIW "%8d\n" NOR,
		attack_points/100 + 1, (dodge_points + (weapon? parry_points: (parry_points/10)))/100 + 1,);
	line += sprintf(" ս���˺��� " HIW "%8d" NOR "\t\tս�������� " HIW "%8d\n\n" NOR,
		ob->query_temp("apply/damage"), ob->query_temp("apply/armor"));
//    else line += "\n";

	line += " ʳ�" + tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), YEL) + "\n";
	line += " ��ˮ��" + tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), CYN) + "\n";

	line += sprintf("\n �㵽ĿǰΪֹ�ܹ�ɱ�� %d ���ˣ������� %d ����������ҡ�\n",
		my["MKS"] + my["PKS"], my["PKS"]);
	line += sprintf(" �㵽ĿǰΪֹ�ܹ����� %d ���ˣ������� %d ���Ƿ�����������\n\n",
		my["dietimes"], my["dietimes"] - my["normal_die"]);

//	line += sprintf("     ���� " RED "%d\n" NOR, ob->query("shen") );
	if (ob->query("shen") >=0)
		line += sprintf(" ��    ���� " RED "%8d\t" NOR, ob->query("shen") );
	else
		line += sprintf(" ��    ���� " RED "%8d\t" NOR, ob->query("shen") );

	line += sprintf(" Ǳ    �ܣ� " HIY "%3d (%3d%%)\t" NOR,
		(int)ob->query("potential") - (int)ob->query("learned_points"),
		(1 + (int)ob->query("learned_points")) * 100 / (1 + (int)ob->query("potential")) );
	line += sprintf(" ʵս���飺 " HIM "%8d\n" NOR, ob->query("combat_exp") );
	line += sprintf(" ��    ���� " HIC "%8d\t" NOR, ob->query("meili") );
	line += sprintf(" ���������� " HIC "%8d\t" NOR, ob->query("score") );
	line += sprintf(" ���������� " HIC "%8d\n" NOR, ob->query("weiwang") );

	write(line);
	return 1;
}

string display_attr(int gift, int value)
{
	if( value > gift ) return sprintf( HIY "%3d" NOR, value );
	else if( value < gift ) return sprintf( CYN "%3d" NOR, value );
	else return sprintf("%3d", value);
}

string status_color(int current, int max)
{
	int percent;

	if( max ) percent = current * 100 / max;
	else percent = 100;

	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}

string tribar_graph(int val, int eff, int max, string color)
{
	return color + bar_string[0..(val*25/max)*2-1]
		+ ((eff > val) ? blank_string[(val*25/max)*2..(eff*25/max)*2-1] : "") + NOR;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : score
           score <��������>                   (��ʦר��)

���ָ�������ʾ��(��)��ָ������(������)�Ļ������ϡ�
�������ϵ��趨����� 'help setup'��

see also : hp
HELP
    );
    return 1;
}
