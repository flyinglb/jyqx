// qiaofu.c
#include <ansi.h>

inherit NPC;
void create()
{
        set_name("�Է�", ({ "qiaofu" }) );
        set("gender", "����" );
        set("age", 30);
	set("per", 30);
        set("long", "һλ��ɫ�ں죬��Ȼ�Եõ��Է�\n");
        set("combat_exp", 100000);
        set("attitude", "friendly");
//      set("env/wimpy", 60);
	set_skill("dodge", 60);
	set_skill("unarmed", 60);
	set_skill("parry", 60);

  	set("chat_chance",10);
  	set("chat_msg",({
        "ֻ���Է򳪵����Ƽ������Ͼ��֣����»Ĳ�·��Ѱ��\n",
        "�Է򳪵�����ɽ���������꣬�Ͻ���ʱ�ɴ��\n",
	"�Է򳪵���������ã���ľ�������Ʊ߹ȿ����У���н���ƣ���Ц�����顣\n",
	"�Է������������괦�����ɼ�������������ͥ��\n",
        (:random_move:)
    	}));
        setup();
        add_money("coin", 50);
set("inquiry", ([
"name": "��Ҷ����Ұ�ţ��ƽ����ɽ�����ʱҲ��Щҩ�ģ�\n",
"here": "���������ڣ���˵ɽ����λ����������\n",
]) );
        carry_object("/d/city/obj/cloth")->wear();
}
