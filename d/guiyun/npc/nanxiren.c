// nanxiren.c
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("��ϣ��", ({ "nan xiren", "nan" }));
	set("title", "��������");
	set("nickname", HIG"��ɽ����"NOR);
	set("long", "
���Ǹ�����ģ���ĺ��ӣ���ʮ��������ͣ�һ���಼�¿㣬����
���˸��ֲ������㴩��Ь�����ִ�ţ�����ľګ��\n");
	set("gender", "����");
	set("age", 30);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 15);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 1200);
	set("max_jing", 500);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 20);
	set("combat_exp", 300000);
	set("score", 6000);

	set_skill("force", 70);
	set_skill("taixuan-gong", 70);
	set_skill("dodge", 70);
	set_skill("lingxu-bu", 70);
	set_skill("unarmed", 70);
	set_skill("changquan", 70);
	set_skill("staff", 70);
	set_skill("juemen-gun", 70);
	set_skill("axe", 70);
	set_skill("duanyun-fu", 70);

	map_skill("force", "taixuan-gong");
	map_skill("dodge", "lingxu-bu");
	map_skill("unarmed", "changquan");
	map_skill("staff", "juemen-gun");
	map_skill("parry", "juemen-gun");
	map_skill("axe", "duanyun-fu");

	set("inquiry", ([
		"����" : "���������ǵĹ�ͽ����\n",
		"��������" : "�����ɲ��ҵ������������ý������и��˺Žн����߹֣�\n",
		"�����߹�" : "�߹�Ҳ����еģ���\n",
		"�𴦻�" : "������������壬�������ӣ�\n",
		"�����" : "�����Ҵ�硣\n",
		"���"   : "�����Ҷ��硣\n",
		"������"   : "���������硣\n",
		"��ϣ��"   : "�������ˡ�\n",
		"�Ű���"   : "��������ܡ�\n",
		"ȫ��"   : "���������ܡ�\n",
		"��СӨ"   : "���������á�\n",
	]));

	setup();
	carry_object(__DIR__"obj/biandan");
	carry_object(__DIR__"obj/axe")->wield();
	carry_object(__DIR__"obj/green_cloth")->wear();
}
