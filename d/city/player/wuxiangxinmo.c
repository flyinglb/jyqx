// wuxiangxinmo.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("������ħ", ({ "wuxiangxinmo"}));
	set("gender", "����");
	set("age", 14);
	set("class", "bonze");
	set("attitude", "friendly");

	set("kar", 27);
	set("per", 18);
	set("int", 19);
	set("dex", 15);
	set("con", 21);
	set("str", 25);
//	set("weiwang", 30);
	set("shen", 0);
	set("combat_exp", 0);
//	set("PKS", 0);
//	set("MKS", 0);

	set("max_jing", 100);
	set("jing", 100);
	set("max_qi", 100);
	set("qi", 100);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 0);
	set("neili", 0);
//	set("meili", 0);

	set_skill("persuading", 1);
	set_skill("checking", 1);
	set_skill("unarmed", 1);
	set_skill("hand", 1);
	set_skill("sword", 1);
	set_skill("blade", 1);
	set_skill("force", 1);
	set_skill("literate", 1);
	set_skill("cuff", 1);
	set_skill("array", 1);
	set_skill("begging", 1);
	set_skill("parry", 1);
	set_skill("whip", 1);
	set_skill("throwing", 1);
	set_skill("claw", 1);
	set_skill("staff", 1);
	set_skill("taoism", 1);
	set_skill("strike", 1);
	set_skill("club", 1);
	set_skill("dodge", 1);
	set_skill("finger", 1);
	set_skill("hammer", 1);

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"�书"  : (: do_skills :),
	]));

	create_family("�������",101, "����");
	setup();
	carry_object(__DIR__"wuxiang_sword")->wield();
	carry_object("/d/city/npc/obj/jinsijia")->wear();
}

int do_skills()
{
message_vision("$N˵�� �����еĻ����书���£�\n"+
"  ������ (array)                         - ��ѧէ��   1/    0\n"+
"  �л����� (begging)                       - ��ѧէ��   1/    0\n"+
"  �������� (blade)                         - ��ѧէ��   1/    0\n"+
"  ����;˵ (checking)                      - ��ѧէ��   1/    0\n"+
"  ����צ�� (claw)                          - ��ѧէ��   1/    0\n"+
"  �������� (club)                          - ��ѧէ��   1/    0\n"+
"  ����ȭ�� (cuff)                          - ��ѧէ��   1/    0\n"+
"  �����Ṧ (dodge)                         - ��ѧէ��   1/    0\n"+
"  ����ָ�� (finger)                        - ��ѧէ��   1/    0\n"+
"  �����ڹ� (force)                         - ��ѧէ��   1/    0\n"+
"  �������� (hammer)                        - ��ѧէ��   1/    0\n"+
"  �����ַ� (hand)                          - ��ѧէ��   1/    0\n"+
"  ����д�� (literate)                      - ��ѧէ��   1/    0\n"+
"  �����м� (parry)                         - ��ѧէ��   1/    0\n"+
"  �������� (persuading)                    - ��ѧէ��   1/    0\n"+
"  �����ȷ� (staff)                         - ��ѧէ��   1/    0\n"+
"  �����Ʒ� (strike)                        - ��ѧէ��   1/    0\n"+
"  �������� (sword)                         - ��ѧէ��   1/    0\n"+
"  ��ѧ�ķ� (taoism)                        - ��ѧէ��   1/    0\n"+
"  �������� (throwing)                      - ��ѧէ��   1/    0\n"+
"  ����ȭ�� (unarmed)                       - ��ѧէ��   1/    0\n"+
"  �����޷� (whip)                          - ��ѧէ��   1/    0\n", this_object());

	return 1;
}

int do_hp()
{
message_vision("$N˵�� �ҵĻ���״̬���£�\n\n"+
"�ԩ�������������������������������������������������������������\n"+
"�� �� �� ��  100/  100 (100%)    �� �� �� ��    0 /    0 (+0)\n"+
"�� �� Ѫ ��  100/  100 (100%)    �� �� �� ��    0 /    0 (+0)\n"+
"�� ʳ �� ��    0/  350           �� Ǳ �� ��  0\n"+
"�� �� ˮ ��    0/  350           �� �� �� ��  0\n"+
"�ԩ�������������������������������������������������������������\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N˵�� �ҵĻ���״�����£�\n\n"+
"�� С���� ��������̵�һ����һ������ ������ħ(Wuxiangxinmo)\n"+
"\n"+
" ����һλʮ������������࣬������һ��һ�ճ�ʱ��������\n"+
" ������[ 25]  ���ԣ�[ 19]  ���ǣ�[ 21]  ����[ 15]\n"+
"\n"+
" <��>  ��������������������������������������������������\n"+
" <��>  ��������������������������������������������������\n"+
"\n"+
" ս��������        1            ս��������        1\n"+
" ս���˺���       30            ս��������      100\n"+
"\n"+
" ʳ���������������������������������������������������\n"+
" ��ˮ����������������������������������������������������\n"+
"\n"+
" �㵽ĿǰΪֹ�ܹ�ɱ�� 0 ���ˣ������� 0 ����������ҡ�\n"+
"\n"+
" ��    ����        0     Ǳ    �ܣ�   0 (100%)   ʵս���飺        0\n"+
" ��    ����        0     �ۺ����ۣ�        0     ����������        0\n"+
"\n", this_object());
	return 1;
}
