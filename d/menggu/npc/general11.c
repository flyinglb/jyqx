#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������", ({ "borshu" }) );
        set("title", YEL"�Ŀ�"NOR);
        set("gender", "����");
        set("age", 58);
        set("per", 23);
        set("long",
"���ǳɼ�˼�����ڵ����Ѻ͹������ųơ��Ŀ���֮һ��\n");
        set("combat_exp", 100000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 20);
}
