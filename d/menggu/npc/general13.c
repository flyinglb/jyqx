#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������", ({ "chilaowen" }) );
        set("title", YEL"�Ŀ�"NOR);
        set("gender", "����");
        set("age", 50);
        set("per", 18);
        set("long",
"���ǳɼ�˼�����ڵ����Ѻ͹������ųơ��Ŀ���֮һ��\n");
        set("combat_exp", 100000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 20);
}
