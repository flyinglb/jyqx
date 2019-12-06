// abab.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("���ɵ���", ({ "abab"}));
	set("gender", "����");
	set("title", HIY"����˶ʿ"HIG"���������Ž���"NOR"�����ɵڶ�������");
	set("nickname", HIY"��ң������ү"NOR);
	set("long", "����һλ��ʮ�����ҵ������ˣ�����޳���üĿ���㣬��
��ɢ����һ�����˵�������������Ц�����Ŀ����㡣\n");
	set("age", 36);
	set("class", "taoist");
	set("attitude", "friendly");

	set("kar", 25);
	set("per", 29);
	set("int", 20);
	set("dex", 19);
	set("con", 21);
	set("str", 20);
	set("weiwang", 70);
	set("shen", -184200);
	set("combat_exp", 591339);
	set("PKS", 12);
	set("MKS", 935);

	set("max_jing", 420);
	set("jing", 420);
	set("max_qi", 971);
	set("qi", 971);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 2140);
	set("neili", 2140);
	set("meili", 40);

	set_skill("literate", 121);
	set_skill("force", 147);
	set_skill("unarmed",100);
	set_skill("parry", 103);
	set_skill("dodge", 108);
	set_skill("sword", 144);
	set_skill("cuff", 101);
	set_skill("hand", 101);
	set_skill("claw", 82);
	set_skill("strike", 97);

	set_skill("pixie-jian", 175);
	set_skill("huagong-dafa", 148);
	set_skill("jiuyin-baiguzhao", 82);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "pixie-jian");
	map_skill("parry", "pixie-jian");
	map_skill("sword", "pixie-jian");
	map_skill("claw","jiuyin-baiguzhao");

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"skill" : (: do_skills :),
		"score" : (: do_score :),
		"�书"  : (: do_skills :),
	]));

	create_family("������",2, "����");
	setup();
	carry_object(__DIR__"abab_sword")->wield();
	carry_object("/d/city/npc/obj/jinsijia")->wear();
}

int do_skills()
{
message_vision("$N˵�� �����еĻ����书���£�\n"+
"�ԩ�������������������������������������������������������������\n"+
"  ����צ�� (claw)                          - �������  82/    0\n"+
"  ����ȭ�� (cuff)                          - ������� 101/    0\n"+
"  �����Ṧ (dodge)                         - ������� 108/    0\n"+
"  �����ڹ� (force)                         - �����뻯 147/    0\n"+
"  �����ַ� (hand)                          - ������� 101/    0\n"+
"�������� (huagong-dafa)                  - �����뻯 148/    0\n"+
"�������׹�ץ (jiuyin-baiguzhao)            - �������  82/    0\n"+
"  ����д�� (literate)                      - ��Ȼ��� 121/    0\n"+
"  �����м� (parry)                         - ������� 103/    0\n"+
"����а���� (pixie-jian)                    - �Ƿ��켫 175/    0\n"+
"  �����Ʒ� (strike)                        - �������  97/    0\n"+
"  �������� (sword)                         - �����뻯 144/    0\n"+
"  ����ȭ�� (unarmed)                       - ������� 100/    0\n"+
"�ԩ�������������������������������������������������������������\n", this_object());

	return 1;
}

int do_hp()
{
message_vision("$N˵�� �ҵĻ���״̬���£�\n\n"+
"�ԩ�������������������������������������������������������������\n"+
"�� �� �� ��  420/  420 (100%)    �� �� �� ��    0 /    0 (+0)\n"+
"�� �� Ѫ ��  971/  971 (100%)    �� �� �� �� 2140 / 2140 (+0)\n"+
"�� ʳ �� ��    0/  300           �� Ǳ �� ��  0\n"+
"�� �� ˮ ��    0/  300           �� �� �� ��  591339\n"+
"�ԩ�������������������������������������������������������������\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N˵�� �ҵĻ���״�����£�\n\n"+
"�� ħ  �� ������˶ʿ���������Ž��������ɵڶ������ӡ���ң������ү�����ɵ���(Abab)\n"+
"\n"+
" ����һλ��ʮ������������࣬������һ��һ�ճ�ʱ��������\n"+
" ������[ 30]  ���ԣ�[ 32]  ���ǣ�[ 35]  ����[ 29]\n"+
"\n"+
" <��>  ��������������������������������������������������\n"+
" <��>  ��������������������������������������������������\n"+
"\n"+
" ս��������    55941            ս��������    95685\n"+
" ս���˺���       30            ս��������      100\n"+
"\n"+
" ʳ���������������������������������������������������\n"+
" ��ˮ����������������������������������������������������\n"+
"\n"+
" �㵽ĿǰΪֹ�ܹ�ɱ�� 947 ���ˣ������� 12 ����������ҡ�\n"+
"\n"+
" ��    ����  -184200     Ǳ    �ܣ�   0 (100%)   ʵս���飺   591339\n"+
" ��    ����       40     �ۺ����ۣ�        0     ����������       70\n"+
"\n", this_object());
	return 1;
}
