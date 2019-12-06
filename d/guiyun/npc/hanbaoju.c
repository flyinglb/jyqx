// hanbaoju.c
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({ "han baoju", "han" }));
	set("title", "��������");
	set("nickname", HIY"������"NOR);
	set("long", "���Ǹ��ְ����ֵ�������ӣ�����һ��������һ�㡣���ֶ���̣�
û�в��ӣ�һ��ͷ��ĳ��棬ȴ������˫��֮�С�һ���������
����Բ������һֻ������������ϡ�\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 10);
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
	set_skill("whip", 70);
	set_skill("riyue-bian", 70);

	map_skill("force", "taixuan-gong");
	map_skill("dodge", "lingxu-bu");
	map_skill("unarmed", "changquan");
	map_skill("whip", "riyue-bian");
	map_skill("parry", "riyue-bian");

	set("inquiry", ([
		"����" : "���������ǵĹ�ͽ����\n",
		"��������" : "�����ɲ��ҵ������������ý������и��˺Žн����߹֣�\n",
		"�����߹�" : "�߹�Ҳ����еģ���\n",
		"�𴦻�" : "������������壬�������ӣ�\n",
		"�����" : "�����Ҵ�硣\n",
		"���"   : "�����Ҷ��硣\n",
		"������"   : "�������ˡ�\n",
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
	carry_object("/clone/weapon/changbian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
