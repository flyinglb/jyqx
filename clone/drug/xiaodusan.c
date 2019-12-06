// xiaodusan.c 消毒散

#include <ansi.h>
inherit ITEM;
void create()
{
   set_name(HIW"消毒散"NOR, ({"xiaodu san", "san"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("long", "这是一包消毒散，看上去就和一般的草药没什么分别。");
      set("unit", "包");
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
   if((arg != "san") && (arg != "xiaodu san"))
        return 0;
        
   message_vision("$N服下一包" + name() + "。\n", me);
   if ((int)me->query_condition("zhizhu_poison") > 0) {
        me->apply_condition("zhizhu_poison", 0);
   }
   
   destruct(this_object());
   return 1;
}
