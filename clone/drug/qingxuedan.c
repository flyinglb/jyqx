// qingxuedan.c 清血丹

#include <ansi.h>
inherit ITEM;
void create()
{
   set_name(HIR"清血丹"NOR, ({"qingxue dan", "dan"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("long", "这是一粒红灿灿的清血丹。");
      set("unit", "粒");
      set("value", 1000);
   }
   setup();
}

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "fu");
}

int do_eat(string arg)
{
   object me = this_player();

   if(!id(arg) )
        return 0;
   if ((arg != "dan") && (arg != "qingxue dan"))
        return 0;
        
   message_vision("$N吃下一粒" + name() + "。\n", me);
   if ((int)me->query_condition("xiezi_poison") > 0) {
        me->apply_condition("xiezi_poison", 0);
   }
   
   destruct(this_object());
   return 1;
}
