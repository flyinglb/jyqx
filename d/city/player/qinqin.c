// qinqin.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("˾��ݼݼ", ({ "qinqin"}));
	set("gender", "Ů��");
	set("title", HIY"����˶ʿ"NOR"��ɽ�ɵ�ʮ��������");
	set("age", 32);
	set("class", "swordsman");
	set("attitude", "friendly");

	set("kar", 24);
	set("per", 22);
	set("int", 33);
	set("dex", 20);
	set("con", 14);
	set("str", 18);
	set("weiwang", 70);
	set("shen", 248860);
	set("combat_exp", 2002380);
	set("PKS", 6);
	set("MKS", 1412);

	set("max_jing", 808);
	set("jing", 808);
	set("max_qi", 956);
	set("qi", 956);
	set("max_jingli", 720);
	set("jingli", 720);
	set("max_neili", 2530);
	set("neili", 2530);
	set("meili", 60);

	set_skill("literate", 120);
	set_skill("taoism", 178);
	set_skill("force", 208);
	set_skill("unarmed",101);
	set_skill("parry", 180);
	set_skill("dodge", 185);
	set_skill("sword", 272);
	set_skill("cuff", 100);
	set_skill("hand", 100);
	set_skill("claw", 100);
	set_skill("strike", 100);
	set_skill("finger", 100);

	set_skill("shenxing-baibian", 272);
	set_skill("lonely-sword", 272);
	set_skill("poyu-quan", 186);
	set_skill("taiji-quan", 98);
	set_skill("zhemei-shou", 270);
	set_skill("taiji-jian", 97);
	set_skill("liangyi-jian", 178);
	set_skill("feiyan-huixiang", 177);
	set_skill("huashan-sword", 248);
	set_skill("tiyunzong", 272);
	set_skill("zixia-shengong", 150);
	set_skill("hunyuan-zhang", 174);
	set_skill("jiuyin-baiguzhao", 270);

	map_skill("force", "zixia-shengong");
	map_skill("dodge", "shenxing-baibian");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("unarmed","taiji-quan");
	map_skill("cuff","poyu-quan");
	map_skill("strike","hunyuan-zhang");
	map_skill("hand","zhemei-shou");
	map_skill("claw","jiuyin-baiguzhao");
	prepare_skill("cuff","poyu-quan");
	prepare_skill("strike","hunyuan-zhang");

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"�书"  : (: do_skills :),
	]));

	create_family("��ɽ��",13, "����");
	setup();
	carry_object(__DIR__"qinqin_sword")->wield();
	carry_object("/d/city/npc/obj/jinsijia")->wear();
}

int do_skills()
{
message_vision("$N˵�� �����еĻ����书���£�\n"+
"  ����צ�� (claw)                          - ������� 100/    0\n"+
"  ����ȭ�� (cuff)                          - ������� 100/    0\n"+
"  �����Ṧ (dodge)                         - һ����ʦ 185/    0\n"+
"  ������� (feiyan-huixiang)               - �Ƿ��켫 177/    0\n"+
"  ����ָ�� (finger)                        - ������� 100/    0\n"+
"  �����ڹ� (force)                         - ��ɲ� 208/    0\n"+
"  �����ַ� (hand)                          - ������� 100/    0\n"+
"  ��ɽ���� (huashan-sword)                 - ��ɲ� 248/    0\n"+
"����Ԫ�� (hunyuan-zhang)                   - �Ƿ��켫 174/    0\n"+
"�������׹�ץ (jiuyin-baiguzhao)            - ��ɲ� 270/    0\n"+
"  ���ǽ��� (liangyi-jian)                  - �Ƿ��켫 178/    0\n"+
"  ����д�� (literate)                      - ��Ȼ��� 120/    0\n"+
"�����¾Ž� (lonely-sword)                  - ��ɲ� 272/    0\n"+
"  �����м� (parry)                         - һ����ʦ 180/    0\n"+
"����ʯ����ȭ (poyu-quan)                   - һ����ʦ 186/    0\n"+
"�����аٱ� (shenxing-baibian)              - ��ɲ� 272/    0\n"+
"  �����Ʒ� (strike)                        - ������� 100/    0\n"+
"  �������� (sword)                         - ��ɲ� 272/    0\n"+
"  ̫������ (taiji-jian)                    - �������  97/    0\n"+
"��̫��ȭ (taiji-quan)                      - �������  98/    0\n"+
"  ��ѧ�ķ� (taoism)                        - ������˫ 178/    0\n"+
"  ������ (tiyunzong)                       - ��ɲ� 272/    0\n"+
"  ����ȭ�� (unarmed)                       - ������� 101/    0\n"+
"����ɽ��÷�� (zhemei-shou)                 - ��ɲ� 270/    0\n"+
"����ϼ�� (zixia-shengong)                - �����뻯 150/    0\n", this_object());

	return 1;
}

int do_hp()
{
message_vision("$N˵�� �ҵĻ���״̬���£�\n\n"+
"�ԩ�������������������������������������������������������������\n"+
"�� �� �� ��  808/  808 (100%)    �� �� �� ��  720 /  720 (+0)\n"+
"�� �� Ѫ ��  956/  956 (100%)    �� �� �� �� 2530 / 2530 (+0)\n"+
"�� ʳ �� ��    0/  280           �� Ǳ �� ��  0\n"+
"�� �� ˮ ��    0/  280           �� �� �� ��  2002380\n"+
"�ԩ�������������������������������������������������������������\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N˵�� �ҵĻ���״�����£�\n\n"+
"������Ů��������˶ʿ��ɽ�ɵ�ʮ�������� ˾��ݼݼ(Qinqin)\n"+
"\n"+
" ����һλ��ʮ�����Ů�����࣬������һ��һ�ճ�ʱ��������\n"+
" ������[ 28]  ���ԣ�[ 45]  ���ǣ�[ 34]  ����[ 38]\n"+
"\n"+
" <��>  ��������������������������������������������������\n"+
" <��>  ��������������������������������������������������\n"+
"\n"+
" ս��������   229987            ս��������   531755\n"+
" ս���˺���       30            ս��������      100\n"+
"\n"+
" ʳ���������������������������������������������������\n"+
" ��ˮ����������������������������������������������������\n"+
"\n"+
" �㵽ĿǰΪֹ�ܹ�ɱ�� 1418 ���ˣ������� 6 ����������ҡ�\n"+
"\n"+
" ��    ����   248860     Ǳ    �ܣ�   0 (100%)   ʵս���飺  2002380\n"+
" ��    ����       60     �ۺ����ۣ�        0     ����������       70\n"+
"\n", this_object());
	return 1;
}
