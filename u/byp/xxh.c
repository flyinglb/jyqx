inherit NPC;
#include <ansi.h>

void create()
{
        set_name("小小黄", ({"baby", "xiao xiao huang", "huang" }) );
        set("gender", "女性" );
        set("per", 30);
        set("age", 4);
        set("long", "她脸上永远带着一副可爱的笑脸。\n");
        setup();
}
