// zhucong.c
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("���", ({ "zhu cong", "zhu" }));
	set("title", "��������");
	set("nickname", HIB"��������"NOR);
	set("long", "
����������һ������ʿ�ˣ�����ЬƤ����̤��̤��ֱ�죬һ·��
�Ź�Ƿ����Ц��Ц����üŪ�ۣ�һ������������ȫ�����壬�¹�
�����������۹���������˵Ҳ��ʮ����ûϴ���ˣ�����һ������
����ֽ���ȣ���ҡ���С�ͻ����Ц�������������Ǵ̶���\n");
	set("gender", "����");
	set("age", 38);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 19);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 1200);
	set("max_jing", 500);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 20);
	set("combat_exp", 350000);
	set("score", 6000);

	set_skill("force", 75);
	set_skill("taixuan-gong", 75);
	set_skill("dodge", 75);
	set_skill("lingxu-bu", 75);
	set_skill("unarmed", 75);
	set_skill("changquan", 75);
	set_skill("dagger", 75);
	set_skill("shigu-bifa", 75);
	set_skill("parry", 75);
	set_skill("stealing", 75);

	map_skill("force", "taixuan-gong");
	map_skill("dodge", "lingxu-bu");
	map_skill("dagger", "shigu-bifa");
	map_skill("parry", "shigu-bifa");

	set("inquiry", ([
		"����" : "���������ǵĹ�ͽ����\n",
		"��������" : "�����ɲ��ҵ������������ý������и��˺Žн����߹֣�\n",
		"�����߹�" : "�߹�Ҳ����еģ���\n",
		"�𴦻�" : "������������壬�������ӣ�\n",
		"�����" : "�����Ҵ�硣\n",
		"���"   : "�������ˡ�\n",
		"������"   : "���������ܡ�\n",
		"��ϣ��"   : "�������ĵܡ�\n",
		"�Ű���"   : "��������ܡ�\n",
		"ȫ��"   : "���������ܡ�\n",
		"��СӨ"   : "���������á�\n",
	]));

        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :)
        }) );

	setup();
	carry_object(__DIR__"obj/zheshan")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
