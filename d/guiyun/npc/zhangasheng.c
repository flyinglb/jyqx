// zhangasheng.c
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�Ű���", ({ "zhang asheng", "zhang" }));
	set("title", "��������");
	set("nickname", HIW"Ц����"NOR);
	set("long", "һ����Ŀ��࣬��˵Ҳ�ж�������ʮ�Χ��һ����Χȹ��ȫ
�����壬�����½�¶��ë���׵����ţ����Ӿ�ø߸ߵģ���
����ȫ�Ǵ����ĺ�ë������Ƥ���ϱ��ű��������ļ⵶����
ģ���Ǹ�ɱ�����������\n");
	set("gender", "����");
	set("age", 28);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 18);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 1200);
	set("max_jing", 500);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 20);
	set("combat_exp", 250000);
	set("score", 6000);

	set_skill("force", 65);
	set_skill("taixuan-gong", 65);
	set_skill("dodge", 65);
	set_skill("lingxu-bu", 65);
	set_skill("unarmed", 65);
	set_skill("changquan", 65);
	set_skill("blade", 65);
	set_skill("hujia-daofa", 65);

	map_skill("force", "taixuan-gong");
	map_skill("dodge", "lingxu-bu");
	map_skill("unarmed", "changquan");
	map_skill("blade", "hujia-daofa");
	map_skill("parry", "hujia-daofa");

	set("inquiry", ([
		"����" : "���������ǵĹ�ͽ����\n",
		"��������" : "�����ɲ��ҵ������������ý������и��˺Žн����߹֣�\n",
		"�����߹�" : "�߹�Ҳ����еģ���\n",
		"�𴦻�" : "������������壬�������ӣ�\n",
		"�����" : "�����Ҵ�硣\n",
		"���"   : "�����Ҷ��硣\n",
		"������"   : "���������硣\n",
		"��ϣ��"   : "�������ĸ硣\n",
		"�Ű���"   : "�������ˡ�\n",
		"ȫ��"   : "���������ܡ�\n",
		"��СӨ"   : "���������á�\n",
	]));

	setup();
	carry_object(__DIR__"obj/jiandao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
