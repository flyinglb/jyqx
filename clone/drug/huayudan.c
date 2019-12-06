// huayudan.c 化淤丹

#include <ansi.h>
inherit ITEM;
void create()
{
   set_name(HIY"化淤丹"NOR, ({"huayu dan", "dan"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("long", "这是一粒黄色的丹药，故名思意是用来化淤的。");
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

   if(!id(arg))
        return 0;
   if((arg != "dan") && (arg != "huayu dan"))
        return 0;
        
   message_vision("$N服下一粒" + name() + "。\n", me);
   if ((int)me->query_condition("wugong_poison") > 0) {
        me->apply_condition("wugong_poison", 0);
   }
   
   destruct(this_object());
   return 1;
}
