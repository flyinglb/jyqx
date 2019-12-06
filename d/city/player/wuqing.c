// wuqing.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("����", ({ "wuqing"}));
	set("gender", "����");
	set("title", HIY"����˶ʿ"HIG"���������Ž���"HIR"���̻���"NOR);
	set("age", 48);
	set("class", "eunach");
	set("attitude", "friendly");

	set("kar", 10);
	set("per", 25);
	set("int", 26);
	set("dex", 18);
	set("con", 25);
	set("str", 16);
	set("weiwang", 30);
	set("shen", 64400);
	set("combat_exp", 1233655);
	set("PKS", 36);
	set("MKS", 1151);

	set("max_jing", 582);
	set("jing", 582);
	set("max_qi", 1221);
	set("qi", 1221);
	set("max_jingli", 267);
	set("jingli", 267);
	set("max_neili", 2046);
	set("neili", 2046);
	set("meili", 60);

	set_skill("literate", 121);
	set_skill("taoism", 102);
	set_skill("claw", 187);
	set_skill("force", 210);
	set_skill("unarmed",95);
	set_skill("parry", 232);
	set_skill("dodge", 201);
	set_skill("sword", 232);
	set_skill("hand", 187);
	set_skill("cuff", 182);
	set_skill("strike", 182);
	set_skill("finger", 177);
	set_skill("begging", 24);
	set_skill("checking", 26);
	set_skill("qimen-wuxing", 24);

	set_skill("tiyunzong", 195);
	set_skill("liangyi-jian", 181);
	set_skill("taiji-shengong", 106);
	set_skill("taiji-quan", 98);
	set_skill("pixie-jian", 202);
	set_skill("shenghuo-ling", 148);
	set_skill("qishang-quan", 43);
	set_skill("jiuyin-baiguzhao", 220);
	set_skill("dagou-bang", 62);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "pixie-jian");
	map_skill("parry", "pixie-jian");
	map_skill("sword", "pixie-jian");
	map_skill("unarmed","taiji-quan");
	map_skill("claw","jiuyin-baiguzhao");
	map_skill("staff","dagou-bang");
	map_skill("cuff","qishang-quan");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"�书"  : (: do_skills :),
	]));

	create_family("����",35, "����");
	setup();
	carry_object(__DIR__"wuqing_sword")->wield();
	carry_object("/d/city/npc/obj/jinsijia")->wear();
}

int do_skills()
{
message_vision("$N˵�� �����еĻ����书���£�\n"+
"  �л����� (begging)                       - ��ͨƤë  24/    0\n"+
"  ����;˵ (checking)                      - ��ͨƤë  26/    0\n"+
"  ����צ�� (claw)                          - һ����ʦ 187/    0\n"+
"  ����ȭ�� (cuff)                          - һ����ʦ 182/    0\n"+
"���򹷰��� (dagou-bang)                    - ������  62/    0\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 201/    0\n"+
"  ����ָ�� (finger)                        - �Ƿ��켫 177/    0\n"+
"  �����ڹ� (force)                         - ��ɲ� 210/    0\n"+
"  �����ַ� (hand)                          - һ����ʦ 187/    0\n"+
"�������׹�ץ (jiuyin-baiguzhao)            - ��ɲ� 220/    0\n"+
"  ���ǽ��� (liangyi-jian)                  - һ����ʦ 181/    0\n"+
"  ����д�� (literate)                      - ��Ȼ��� 121/    0\n"+
"  �����м� (parry)                         - ��ɲ� 232/    0\n"+
"����а���� (pixie-jian)                    - ��ɲ� 202/    0\n"+
"  �������� (qimen-wuxing)                  - �����ž�  24/    0\n"+
"������ȭ (qishang-quan)                    - ��������  43/    0\n"+
"  ʥ��� (shenghuo-ling)                 - �����뻯 148/    0\n"+
"  �����Ʒ� (strike)                        - һ����ʦ 182/    0\n"+
"  �������� (sword)                         - ��ɲ� 232/    0\n"+
"��̫��ȭ (taiji-quan)                      - �������  98/    0\n"+
"��̫���� (taiji-shengong)                - ������� 106/    0\n"+
"  ��ѧ�ķ� (taoism)                        - ������� 102/    0\n"+
"  ������ (tiyunzong)                       - һ����ʦ 195/    0\n"+
"  ����ȭ�� (unarmed)                       - �������  95/    0\n", this_object());

	return 1;
}

int do_hp()
{
message_vision("$N˵�� �ҵĻ���״̬���£�\n\n"+
"�ԩ�������������������������������������������������������������\n"+
"�� �� �� ��  582/  582 (100%)    �� �� �� ��  267 /  267 (+0)\n"+
"�� �� Ѫ �� 1221/ 1221 (100%)    �� �� �� �� 2046 / 2046 (+0)\n"+
"�� ʳ �� ��    0/  260           �� Ǳ �� ��  0\n"+
"�� �� ˮ ��    0/  260           �� �� �� ��  1233655\n"+
"�ԩ�������������������������������������������������������������\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N˵�� �ҵĻ���״�����£�\n\n"+
"����������������˶ʿ���������Ž������̻��� ����(Wuqing)\n"+
"\n"+
" ����һλ��ʮ������������࣬������һ��һ�ճ�ʱ��������\n"+
" ������[ 34]  ���ԣ�[ 38]  ���ǣ�[ 46]  ����[ 38]\n"+
"\n"+
" <��>  ��������������������������������������������������\n"+
" <��>  ��������������������������������������������������\n"+
"\n"+
" ս��������   135465            ս��������   277643\n"+
" ս���˺���       30            ս��������      100\n"+
"\n"+
" ʳ���������������������������������������������������\n"+
" ��ˮ����������������������������������������������������\n"+
"\n"+
" �㵽ĿǰΪֹ�ܹ�ɱ�� 1151 ���ˣ������� 36 ����������ҡ�\n"+
"\n"+
" ��    ����    64400     Ǳ    �ܣ�   0 (100%)   ʵս���飺  1233655\n"+
" ��    ����       60     �ۺ����ۣ�        0     ����������       30\n"+
"\n", this_object());
	return 1;
}
