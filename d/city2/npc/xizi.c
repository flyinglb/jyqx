// xizi.c
inherit NPC;
#include <ansi.h>
int ask_meili();

void create()
{
	set_name("Ϸ��", ({ "xi zi", "xi","zi" }) );
	set("gender", "����" );
	set("age", 10+random(40));
	set("int", 28);
	set("long","���Ǹ���Ӣ�������ӡ�\n");
	set("attitude", "peaceful");
	set_skill("literate", 100);
        set("combat_exp",random(10000));
	set("chat_chance", 3);
	set("chat_msg", ({
	"Ϸ��ͻȻ˵��: ��������Ҫ�����������˶�ϲ����\n",
	"Ϸ�ӵ����˵: �ҵ�����ֵ��100��\n",
	"Ϸ��ͻȻ˵��: �����£�Ҫ�뵱�ٲ����װ�������ֵ̫�Ϳɲ��С�\n",
	}));
        set("inquiry", ([
                "����" :  (: ask_meili :),
                "����" :  "Ҫ�뵱�ٵý���������ȥ��\n",
	]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_meili()
{
command("tell "+this_player()->query("id")+" �����ڵ�����ֵ�� " +(string)(this_player()->query("meili")));
say("\nϷ��˵�����������ֵ�ܸߣ���Щ�˼����������书�����㱦����\n"
+"�����㻹����ȥ��������ϣ������������ٶ�����Ϳ��Դ����� ����������\n");
say("Ϸ����˵���������˹ٻ�������ģ��㲻�û�ɱͷ�ġ�\n");
return 1;
}

