// huayudan.c ���ٵ�

#include <ansi.h>
inherit ITEM;
void create()
{
   set_name(HIY"���ٵ�"NOR, ({"huayu dan", "dan"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("long", "����һ����ɫ�ĵ�ҩ������˼�����������ٵġ�");
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
   if((arg != "dan") && (arg != "huayu dan"))
        return 0;
        
   message_vision("$N����һ��" + name() + "��\n", me);
   if ((int)me->query_condition("wugong_poison") > 0) {
        me->apply_condition("wugong_poison", 0);
   }
   
   destruct(this_object());
   return 1;
}
