// hanxiaoyin.c
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("��СӨ", ({ "han xiaoyin", "han" }));
	set("title", "��������");
	set("nickname", HIR"ԽŮ��"NOR);
	set("long", "����Լʮ�˾�����ͣ��������������۾���Ƥ����ѩ��¶��һ
ͷ���ư���㷢�����ǽ���ˮ������\n");
	set("gender", "Ů��");
	set("age", 18);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 18);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 1000);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 20);
	set("combat_exp", 200000);
	set("score", 6000);

	set_skill("force", 60);
	set_skill("taixuan-gong", 60);
	set_skill("dodge", 60);
	set_skill("lingxu-bu", 60);
	set_skill("unarmed", 60);
	set_skill("changquan", 60);
	set_skill("sword", 60);
	set_skill("yunu-sword", 60);

	map_skill("force", "taixuan-gong");
	map_skill("dodge", "lingxu-bu");
	map_skill("unarmed", "changquan");
	map_skill("sword", "yunu-sword");
	map_skill("parry", "yunu-sword");

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
		"ȫ��"   : "���������硣\n",
		"��СӨ"   : "�������ˡ�\n",
	]));

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
