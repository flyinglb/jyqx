// benyin.c
inherit NPC;
inherit F_MASTER;

string ask_me();
void create()
{
	set_name("����", ({ "ben yin","yin"}) );
	set("gender", "����" );
	set("title", "�����µ�ʮ�ߴ�ס��");
	set("long", "һ������������ɮ�ˣ�����������ס�ַ��ɡ�\n");
	set("class", "bonze");
	set("age", 43);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 800000);
	set("score", 1000000);

	set_skill("force", 120);
	set_skill("dodge", 180);
	set_skill("parry", 120);
	set_skill("finger", 185);
	set_skill("sword", 120);
	set_skill("tiannan-step", 180);
	set_skill("kurong-changong", 120);
	set_skill("duanjia-sword", 120);
	set_skill("six-finger", 180);
	set_skill("buddhism", 100);
	set_skill("literate", 80);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("parry", "six-finger");
	map_skill("finger", "six-finger");
	map_skill("sword", "duanjia-sword");
	prepare_skill("finger","six-finger");
	set("inquiry" ,([
	"������" : (:ask_me():),
	"��������" : "��ʩ�������Ǵ�ʲô����ɣ���\n",
	"������" :  "��ʩ������������ҽ��������ɣ���\n",
	]));

	create_family("����μ�",17,"��ɮ");
	setup();
	carry_object("/d/xueshan/obj/b-jiasha")->wear();
}

string ask_me()
{
	object me=this_player();
	if(me->query_temp("marks/ask_temp0"))
		{
		me->set_temp("marks/ask_temp1",1);
		return "�����Ǳ��µ�����֮����������ǰ������ʧ��ʩ�������һش��\n         ���ı�����л����\n";
		}
	else
		return "��ʩ���������ԡ���\n";
}

int accept_object(object who, object ob)
{
        if (  (string)ob->query("id") == "jin he")
	{
		message_vision("�����ϲ��������лʩ����ʩ��������Ե�ˣ��뵽Ĳ����ȡ����֮����\n", who);
		who->set_temp("marks/find_temp",1);
		who->move("/d/tianlongsi/banruotai");
		return 1;
	}
	return 0;
}
#include "ben.h"
