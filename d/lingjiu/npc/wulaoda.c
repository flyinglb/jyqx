// NPC jiuyi.c

#include <ansi.h>

inherit NPC;
string ask_me();

void create()
{
	set_name("���ϴ�", ({ "wu laoda", "wu"}));
	set("long",@LONG
�������������������ϴ�
����ı��ͯ��δ����������ڴˡ�
LONG	    
	   );
//	set("title", "����һƷ�ø���");
	set("gender", "����");
//	set("nickname", HIR "�׶��ھ���֮��" NOR);
	set("age", 40);
	set("shen_type",-1);
	set("attitude", "peaceful");

	set("str", 27);
	set("int", 23);
	set("con", 24);
	set("dex", 30);

	
	set("max_qi", 1000);
 	set("qi", 1000);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 0);

	set("combat_exp", 1000000);
	set("score", 100000);

	set("inquiry", ([
		"�����ܵ���" : (: ask_me :),
	]));
	set("chat_chance", 3);
        set("chat_msg", ({
"���ϴ��૵��������ܵ�������Ǻö�����\n",
        }) );
	set("wan_count", 1);
	setup();
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "���չ�")
		return RANK_D->query_respect(this_player()) + 
		"������Ҫ���չ�֮���ɱ����أ�";
	if (query("wan_count") < 1)
		return "������˼���Ѿ����˽����ȵ��ˣ����´������ɡ�";
	add("wan_count", -1);
	ob = new(__DIR__"obj/baiyunwan");
	ob->move(this_player());
	return "����������������ҵķ��ϣ���Ű����ܵ���͸���ɡ�";
}
