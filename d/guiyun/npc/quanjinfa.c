// quanjinfa.c
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("ȫ��", ({ "quan jinfa", "quan" }));
	set("title", "��������");
	set("nickname", HIC"��������"NOR);
	set("long", "���������ģ�ͷ��Сձñ���׾���Ƥ����������һ�˳ӣ�һ
����¨�����Ǹ�С�̷���\n");
	set("gender", "����");
	set("age", 25);
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
	set_skill("club", 65);
	set_skill("zhongping-qiang", 65);

	map_skill("force", "taixuan-gong");
	map_skill("dodge", "lingxu-bu");
	map_skill("unarmed", "changquan");
	map_skill("club", "zhongping-qiang");
	map_skill("parry", "zhongping-qiang");

	set("inquiry", ([
		"����" : "���������ǵĹ�ͽ����\n",
		"��������" : "�����ɲ��ҵ������������ý������и��˺Žн����߹֣�\n",
		"�����߹�" : "�߹�Ҳ����еģ���\n",
		"�𴦻�" : "������������壬�������ӣ�\n",
		"�����" : "�����Ҵ�硣\n",
		"���"   : "�����Ҷ��硣\n",
		"������"   : "���������硣\n",
		"��ϣ��"   : "�������ĸ硣\n",
		"�Ű���"   : "��������硣\n",
		"ȫ��"   : "�������ˡ�\n",
		"��СӨ"   : "���������á�\n",
	]));

	setup();
	carry_object(__DIR__"obj/gancheng")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
