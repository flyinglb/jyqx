// cnba.c
#include <ansi.h>
inherit NPC;
int do_skills();
void create()
{
	set_name("����", ({ "cnba"}));
	set("gender", "����");
	set("title", HIR"�ڸ��ѧʿ"NOR"ؤ��ڶ�ʮ������");
	set("age", 61);
	set("class", "beggar");
	set("attitude", "friendly");

	set("kar", 27);
	set("per", 22);
	set("int", 22);
	set("dex", 15);
	set("con", 20);
	set("str", 24);
	set("weiwang", 70);
	set("shen", 154468);
	set("combat_exp", 1771911);
	set("PKS", 53);
	set("MKS", 1716);

	set("max_jing", 625);
	set("jing", 625);
	set("max_qi", 1948);
	set("qi", 1948);
	set("max_jingli", 693);
	set("jingli", 693);
	set("max_neili", 2790);
	set("neili", 2790);
	set("meili", 60);

	set_skill("literate", 170);
	set_skill("force", 251);
	set_skill("unarmed",7);
	set_skill("parry", 160);
	set_skill("dodge", 250);
	set_skill("sword", 250);
	set_skill("cuff", 99);
	set_skill("hand", 99);
	set_skill("claw", 195);
	set_skill("strike", 99);
	set_skill("taoism", 149);
	set_skill("hubo", 99);
	set_skill("club", 2);
	set_skill("whip", 2);
	set_skill("throwing", 14);
	set_skill("array", 23);
	set_skill("staff", 4);
	set_skill("finger", 78);
	set_skill("stealing", 99);
	set_skill("checking", 74);
	set_skill("blade", 5);
	set_skill("begging", 42);
	set_skill("qimen-wuxing", 100);

	set_skill("shenxing-baibian", 82);
	set_skill("lingboweibu", 5);
	set_skill("taiji-jian", 247);
	set_skill("qiankun-danuoyi", 30);
	set_skill("taiji-quan", 106);
	set_skill("shenkong-xing", 4);
	set_skill("liangyi-jian", 10);
	set_skill("taiji-shengong", 193);
	set_skill("tiyunzong", 191);
	set_skill("kongming-quan", 89);
	set_skill("jiuyin-baiguzhao", 174);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	map_skill("claw","jiuyin-baiguzhao");
	map_skill("unarmed","taiji-quan");
	prepare_skill("claw","jiuyin-baiguzhao");

	set("inquiry", ([
		"skill" : (: do_skills :),
		"�书"  : (: do_skills :),
	]));

	create_family("ؤ��", 20, "����");
	setup();
	carry_object(__DIR__"abab_sword")->wield();
	carry_object("/d/city/npc/obj/jinsijia")->wear();
}

int do_skills()
{
message_vision("$N˵�� �����еĻ����书���£�\n"+
"  ������ (array)                         - �����ž�  23/    0\n"+
"  �л����� (begging)                       - ��������  42/    0\n"+
"  �������� (blade)                         - ��ѧէ��   5/    0\n"+
"  ����;˵ (checking)                      - ������  74/    0\n"+
"  ����צ�� (claw)                          - һ����ʦ 195/    0\n"+
"  �������� (club)                          - ��ѧէ��   2/    0\n"+
"  ����ȭ�� (cuff)                          - �������  99/    0\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 250/    0\n"+
"  ����ָ�� (finger)                        - ������  78/    0\n"+
"  �����ڹ� (force)                         - ��ɲ� 251/    0\n"+
"  �����ַ� (hand)                          - �������  99/    0\n"+
"  ���һ��� (hubo)                          - ����С��  99/    0\n"+
"�������׹�ץ (jiuyin-baiguzhao)            - �Ƿ��켫 174/    0\n"+
"  ����ȭ (kongming-quan)                   - �������  89/    0\n"+
"  ���ǽ��� (liangyi-jian)                  - ��ѧէ��  10/    0\n"+
"  �貨΢�� (lingboweibu)                   - ��ѧէ��   5/    0\n"+
"  ����д�� (literate)                      - ������˫ 170/    0\n"+
"  �����м� (parry)                         - �Ƿ��켫 160/    0\n"+
"  Ǭ����Ų�� (qiankun-danuoyi)             - ��ͨƤë  30/    0\n"+
"  �������� (qimen-wuxing)                  - ������� 100/    0\n"+
"  ����� (shenkong-xing)                   - ��ѧէ��   4/    0\n"+
"  ���аٱ� (shenxing-baibian)              - �������  82/    0\n"+
"  �����ȷ� (staff)                         - ��ѧէ��   4/    0\n"+
"  ���ֿտ� (stealing)                      - �������  99/    0\n"+
"  �����Ʒ� (strike)                        - �������  99/    0\n"+
"  �������� (sword)                         - ��ɲ� 250/    0\n"+
"��̫������ (taiji-jian)                    - ��ɲ� 247/    0\n"+
"��̫��ȭ (taiji-quan)                      - ������� 106/    0\n"+
"��̫���� (taiji-shengong)                - һ����ʦ 193/    0\n"+
"  ��ѧ�ķ� (taoism)                        - ��Ȼ��ͨ 149/    0\n"+
"  �������� (throwing)                      - ��ѧէ��  14/    0\n"+
"�������� (tiyunzong)                       - һ����ʦ 191/    0\n"+
"  ����ȭ�� (unarmed)                       - ��ѧէ��   7/    0\n"+
"  �����޷� (whip)                          - ��ѧէ��   2/    0\n", this_object());   

	return 1;
}

