#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW "����" NOR,({"mi shu"}));
        set("nickname", BLINK+HIC"����������"NOR);
        set("gender", "Ů��");
        set("age", 18);
        set("long", 
                "����һ��Ư�������Ů���顣\n");

        setup();
        
        carry_object("/d/city2/obj/jinduan")->wear();
}

