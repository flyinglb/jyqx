// quwugao.c ȥ�ڸ�

#include <ansi.h>
inherit ITEM;
void create()
{
   set_name(HIB"ȥ�ڸ�"NOR, ({"quwu gao", "gao"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("long", "����һ��ȥ�ڸ࣬����ȥ���ӵ���ͦ�ÿ��ġ�");
      set("unit", "��");
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
        
   message_vision("$N����һ��" + name() + "��\n", me);
   if ((int)me->query_condition("chanchu_poison") > 0) {
        me->apply_condition("chanchu_poison", 0);}
   if ((int)me->query_condition("ice_poison") > 0) {
        me->apply_condition("ice_poison", 0);
   }
   
   destruct(this_object());
   return 1;
}
