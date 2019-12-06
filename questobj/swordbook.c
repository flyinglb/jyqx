#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIM "冲灵剑谱" NOR, ({ "jianpu" }) );
    set_weight(5000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("dynamic_quest", "/kungfu/class/huashan/linghu");
            set("long", "这是令狐冲为了纪念岳灵珊说所写下的剑谱。\n");
          }
    setup();
}
