// fandog.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("����", ({ "fandog"}));
	set("gender", "����");
	set("long","����һֻ���ֲ�����Ȯ�����ϵ�ëû�м�����
��ȴ��ƽ���貣������һ˿�������͹�
ˮ������ֻ�۾�ˮ����ģ����������ؿ���
��......��Ү����Ү������ǹ�Ӧ��һ����
�������˸�Ӧ��һ���ú���\n");
	set("title", HIY"���ֲ�ʿ"HIG"���������Ž���"NOR"ؤ���ʮ�˴�����");
	set("nickname", HIY"ûëȮ"NOR);
	set("age", 46);
	set("class", "eunach");
	set("attitude", "friendly");

	set("kar", 10);
	set("per", 25);
	set("int", 23);
	set("dex", 20);
	set("con", 21);
	set("str", 16);
	set("weiwang", 70);
	set("shen", 239340);
	set("combat_exp", 2137847);
	set("PKS", 4);
	set("MKS", 2629);

	set("max_jing", 593);
	set("jing", 593);
	set("max_qi", 1251);
	set("qi", 1251);
	set("max_jingli", 500);
	set("jingli", 500);
	set("max_neili", 3260);
	set("neili", 3260);
	set("meili", 60);

	set_skill("literate", 135);
	set_skill("taoism", 100);
	set_skill("hubo", 100);
	set_skill("force", 253);
	set_skill("unarmed",250);
	set_skill("parry", 255);
	set_skill("dodge", 253);
	set_skill("sword", 250);
	set_skill("blade", 250);
	set_skill("staff", 250);
	set_skill("shenxing-baibian", 20);
	set_skill("yunlong-jian", 250);
	set_skill("pixie-jian", 250);
	set_skill("houquan", 238);
	set_skill("xianglong-zhang", 278);
	set_skill("xiaoyaoyou", 278);
	set_skill("huntian-qigong", 200);
	set_skill("dagou-bang", 278);
	set_skill("kongming-quan", 214);

	map_skill("force", "huntian-qigong");
	map_skill("dodge", "pixie-jian");
	map_skill("parry", "pixie-jian");
	map_skill("sword", "pixie-jian");
	map_skill("unarmed","xianglong-zhang");
	map_skill("staff","dagou-bang");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"�书"  : (: do_skills :),
	]));

	create_family("ؤ��",18, "����");
	setup();
	carry_object(__DIR__"fandog_sword")->wield();
	carry_object("/d/city/npc/obj/jinsijia")->wear();
}

int do_skills()
{
message_vision("$N˵�� �����еĻ����书���£�\n"+
"  �������� (blade)                         - ��ɲ� 250/    0\n"+
"���򹷰��� (dagou-bang)                    - ��ɲ� 278/    0\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 253/    0\n"+
"  �����ڹ� (force)                         - ��ɲ� 253/    0\n"+
"  ��ȭ (houquan)                           - ��ɲ� 238/    0\n"+
"  ���һ��� (hubo)                          - ������� 100/    0\n"+
"���������� (huntian-qigong)                - ��ɲ� 200/    0\n"+
"  ����ȭ (kongming-quan)                   - ��ɲ� 214/    0\n"+
"  ����д�� (literate)                      - ��Ȼ��� 135/    0\n"+
"  �����м� (parry)                         - ��ɲ� 255/    0\n"+
"����а���� (pixie-jian)                    - ��ɲ� 250/    0\n"+
"  ���аٱ� (shenxing-baibian)              - ��ͨƤë  20/    0\n"+
"  �����ȷ� (staff)                         - ��ɲ� 250/    0\n"+
"  �������� (sword)                         - ��ɲ� 250/    0\n"+
"  ��ѧ�ķ� (taoism)                        - ������� 100/    0\n"+
"  ����ȭ�� (unarmed)                       - �����뻯 250/    0\n"+
"������ʮ���� (xianglong-zhang)             - ��ɲ� 278/    0\n"+
"  ��ң�� (xiaoyaoyou)                      - ��ɲ� 278/    0\n"+
"  ������ (yunlong-jian)                    - ��ɲ� 250/    0\n", this_object());

	return 1;
}
int do_hp()
{
message_vision("$N˵�� �ҵĻ���״̬���£�\n\n"+
"�ԩ�������������������������������������������������������������\n"+
"�� �� �� ��  593/  593 (100%)    �� �� �� ��  500 /  500 (+0)\n"+
"�� �� Ѫ �� 1251/ 1251 (100%)    �� �� �� �� 3260 / 3260 (+0)\n"+
"�� ʳ �� ��    0/  260           �� Ǳ �� ��  0\n"+
"�� �� ˮ ��    0/  260           �� �� �� ��  2137847\n"+
"�ԩ�������������������������������������������������������������\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N˵�� �ҵĻ���״�����£�\n\n"+
"���������������ֲ�ʿ���������Ž���ؤ���ʮ�˴����ӡ�ûëȮ������(Fandog)\n"+
"\n"+
" ����һλ��ʮ������������࣬������һ��һ�ճ�ʱ��������\n"+
" ������[ 41]  ���ԣ�[ 36]  ���ǣ�[ 46]  ����[ 45]\n"+
"\n"+
" <��>  ��������������������������������������������������\n"+
" <��>  ��������������������������������������������������\n"+
"\n"+
" ս��������   269452            ս��������   581755\n"+
" ս���˺���       30            ս��������      100\n"+
"\n"+
" ʳ���������������������������������������������������\n"+
" ��ˮ����������������������������������������������������\n"+
"\n"+
" �㵽ĿǰΪֹ�ܹ�ɱ�� 2633 ���ˣ������� 4 ����������ҡ�\n"+
"\n"+
" ��    ����   239340     Ǳ    �ܣ�   0 (100%)   ʵս���飺  2137847\n"+
" ��    ����       60     �ۺ����ۣ�        0     ����������       70\n"+
"\n", this_object());
	return 1;
}
