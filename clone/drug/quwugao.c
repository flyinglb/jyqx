// quwugao.c 去乌膏

#include <ansi.h>
inherit ITEM;
void create()
{
   set_name(HIB"去乌膏"NOR, ({"quwu gao", "gao"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("long", "这是一盒去乌膏，看上去盒子到是挺好看的。");
      set("unit", "盒");
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

   if(!id(arg))
        return 0;
   if((arg != "gao") && (arg != "quwu gao"))
        return 0;
        
   message_vision("$N服下一盒" + name() + "。\n", me);
   if ((int)me->query_condition("chanchu_poison") > 0) {
        me->apply_condition("chanchu_poison", 0);}
   if ((int)me->query_condition("ice_poison") > 0) {
        me->apply_condition("ice_poison", 0);
   }
   
   destruct(this_object());
   return 1;
}
