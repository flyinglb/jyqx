// puyi.c
inherit NPC;
#include <ansi.h>
int ask_meili();
int ask_shu();

void create()
{
	set_name("����", ({ "pu yi", "pu","yi" }) );
	set("gender", "����" );
	set("age", 25);
	set("int", 28);
	set("long","\n���Ǹ����۴��������ˣ�������ת���Ĵ�������ͣ,������ʲô��\n");
	set("attitude", "peaceful");
        set("combat_exp",10000+random(5000));
	set("chat_chance", 3);
	set("chat_msg", ({
	"����ͻȻ˵��: ��������Ҫ������ֵ�߿��Խ������١�\n",
	"���۵����˵: ���������ٸ�Щ�˾�ȥ�ʹ������ϡ�\n",
	"���۶�Ѿ������˵��: ��֪������������ܡ�\n",
	}));
        set("inquiry", ([
                "����" :  (: ask_meili :),
                "����" :  "Ҫ�뵱�ٵý���������ȥ��\n",
                "����" :  "��Ҳ֪�����������飿\n",
                "��" :   (: ask_shu :),
                "��ʮ���¾�" :  (: ask_shu :),
                "����" :  (: ask_shu :),
                "Կ��" :  (: ask_shu :),
	       ]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_meili()
{
command("tell "+this_player()->query("id")+" �����ڵ�����ֵ�� " +(string)(this_player()->query("meili")));
say("\n����˵�����������ֵ�ܸߣ�����ٸ��������������㡣\n"
+"�㻹���Խ���ȥ�����ϣ������������ٶ�����Ϳ��Դ����� ����������\n");
say("������˵���������˹ٻ������񣬸㲻�û�ɱͷ�ġ�\n");
return 1;
}

int accept_object(object who, object ob)
{
	if (ob->query("money_id") && ob->value() >= 1000000) 
	{
		who->set_temp("money2_paid",1);
		return 1;
	}
	return 0;
}

int ask_shu()
{
if (this_player()->query_temp("money2_paid"))
{
this_player()->delete_temp("money2_paid");
say("����˵�����ذ������а�����Կ���ڷ�������\n");
say("������˵�������ʵ������ƭ��ġ�ʵ�ڲ������ͷ�����ҡ�\n");
return 1;
}
say("����˵������ʲôҲ���Ƚ�Ǯ����\n");
say("������˵���һ���һ���ʱ��Ų鵽������µ����ڣ�\n"+
"����һ�������ӣ��ɲ��Ǻ�׬�ġ�\n");
return 1;
} 

