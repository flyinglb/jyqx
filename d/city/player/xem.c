// xem.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("��÷", ({ "xem"}));
	set("gender", "Ů��");
	set("title", HIY"����˶ʿ"HIG"���̵����Ž���"NOR"�����ɵ��Ĵ�����");
	set("age", 40);
	set("class", "bonze");
	set("attitude", "friendly");

	set("kar", 28);
	set("per", 20);
	set("int", 30);
	set("dex", 16);
	set("con", 15);
	set("str", 19);
	set("weiwang", 70);
	set("shen", 107080);
	set("combat_exp", 3688251);
	set("PKS", 4);
	set("MKS", 1032);

	set("max_jing", 580);
	set("jing", 580);
	set("max_qi", 1350);
	set("qi", 1350);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 4040);
	set("neili", 4040);
	set("meili", 60);

	set_skill("literate", 121);
	set_skill("mahayana", 200);
	set_skill("buddhism", 105);
	set_skill("persuading", 130);
	set_skill("force", 252);
	set_skill("unarmed",250);
	set_skill("parry", 260);
	set_skill("dodge", 260);
	set_skill("sword", 250);
	set_skill("blade", 250);
	set_skill("strike", 250);
	set_skill("hand", 250);
	set_skill("claw", 250);
	set_skill("finger", 250);
	set_skill("cuff", 250);
	set_skill("jinding-zhang", 328);
	set_skill("qishang-quan", 328);
	set_skill("yanxing-dao", 328);
	set_skill("linji-zhuang", 278);
	set_skill("tianyu-qijian", 328);
	set_skill("zhutian-bu", 328);
	set_skill("huifeng-jian", 328);
	set_skill("kongming-quan", 328);
	set_skill("tiangang-zhi", 328);
	set_skill("jiuyin-baiguzhao", 310);

	map_skill("force", "linji-zhuang");
	map_skill("dodge", "zhutian-bu");
	map_skill("parry", "huifeng-jian");
	map_skill("sword", "huifeng-jian");
	map_skill("blade", "yanxing-dao");
	map_skill("strike", "jinding-zhang");
	map_skill("cuff", "qishang-quan");
	map_skill("unarmed", "kongming-quan");
	map_skill("finger", "tiangang-zhi");
	map_skill("claw","jiuyin-baiguzhao");
	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"�书"  : (: do_skills :),
	]));

	create_family("������",4, "����");
	setup();
	carry_object(__DIR__"xem_sword")->wield();
	carry_object("/d/city/npc/obj/jinsijia")->wear();
}

int do_skills()
{
message_vision("$N˵�� �����еĻ����书���£�\n"+
"  �������� (blade)                         - ��ɲ� 250/    0\n"+
"  �����ķ� (buddhism)                      - ������� 105/    0\n"+
"  ����צ�� (claw)                          - ��ɲ� 250/    0\n"+
"  ����ȭ�� (cuff)                          - ��ɲ� 250/    0\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 260/    0\n"+
"  ����ָ�� (finger)                        - ��ɲ� 250/    0\n"+
"  �����ڹ� (force)                         - ��ɲ� 252/    0\n"+
"  �����ַ� (hand)                          - ��ɲ� 250/    0\n"+
"���ط������ (huifeng-jian)                - ��ɲ� 328/    0\n"+
"�������� (jinding-zhang)                 - ��ɲ� 328/    0\n"+
"�������׹�ץ (jiuyin-baiguzhao)            - ��ɲ� 310/    0\n"+
"������ȭ (kongming-quan)                   - ��ɲ� 328/    0\n"+
"���ټ�ʮ��ׯ (linji-zhuang)                - ��ɲ� 278/    0\n"+
"  ����д�� (literate)                      - ��Ȼ��� 121/    0\n"+
"  ������͹� (mahayana)                    - ��ɲ� 200/    0\n"+
"  �����м� (parry)                         - ��ɲ� 260/    0\n"+
"  �������� (persuading)                    - ��Ȼ��� 130/    0\n"+
"������ȭ (qishang-quan)                    - ��ɲ� 328/    0\n"+
"  �����Ʒ� (strike)                        - ��ɲ� 250/    0\n"+
"  �������� (sword)                         - ��ɲ� 250/    0\n"+
"�����ָѨ�� (tiangang-zhi)                - ��ɲ� 328/    0\n"+
"  �����潣 (tianyu-qijian)                 - ��ɲ� 328/    0\n"+
"  ����ȭ�� (unarmed)                       - ��ɲ� 250/    0\n"+
"�����е� (yanxing-dao)                     - ��ɲ� 328/    0\n"+
"�����컯�� (zhutian-bu)                  - ��ɲ� 328/    0\n", this_object());

	return 1;
}

int do_hp()
{
message_vision("$N˵�� �ҵĻ���״̬���£�\n\n"+
"�ԩ�������������������������������������������������������������\n"+
"�� �� �� ��  580/  580 (100%)    �� �� �� ��    0 /    0 (+0)\n"+
"�� �� Ѫ �� 1350/ 1350 (100%)    �� �� �� �� 4040 / 4040 (+0)\n"+
"�� ʳ �� ��    0/  290           �� Ǳ �� ��  0\n"+
"�� �� ˮ ��    0/  290           �� �� �� ��  3688251\n"+
"�ԩ�������������������������������������������������������������\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N˵�� �ҵĻ���״�����£�\n\n"+
"������Ů��������˶ʿ���̵����Ž��ڶ����ɵ��Ĵ����� ��÷(Xem)\n"+
"\n"+
" ����һλ��ʮ���Ů�����࣬������һ��һ�ճ�ʱ��������\n"+
" ������[ 44]  ���ԣ�[ 42]  ���ǣ�[ 40]  ����[ 42]\n"+
"\n"+
" <��>  ��������������������������������������������������\n"+
" <��>  ��������������������������������������������������\n"+
"\n"+
" ս��������   508564            ս��������   970895\n"+
" ս���˺���       30            ս��������      100\n"+
"\n"+
" ʳ���������������������������������������������������\n"+
" ��ˮ����������������������������������������������������\n"+
"\n"+
" �㵽ĿǰΪֹ�ܹ�ɱ�� 1036 ���ˣ������� 4 ����������ҡ�\n"+
"\n"+
" ��    ����   107080     Ǳ    �ܣ�   0 (100%)   ʵս���飺  3688251\n"+
" ��    ����       60     �ۺ����ۣ�        0     ����������       70\n"+
"\n", this_object());
	return 1;
}
