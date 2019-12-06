//LUCAS 2000-6-18
#include <ansi.h>

inherit ITEM;

int do_drink(string);
void init();

void init()
{
  add_action("do_drink", "drink");
}

void create()
{
  set_name( HIR "����Ѫ" NOR , ({"she xue", "blood"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ�ܹ��ߵ�ѪҺ,�����ȳ�,�����������͵ġ�\n");
    set("value", 1000);
    set("drug_type", "��Ʒ");
  }
  set("is_monitored",1);
  setup();
}

int do_drink(string arg)
{
  object me = this_player();
  if (arg!="blood" && arg!="she xue")   return 0;
  
  me->add("max_neili", 5);
  message_vision(HIR "$Nֻ��һ�����ߴ��ʺ�ֱͨ������,Ȼ���������һ�Ż������������\n" NOR, me);
  destruct(this_object());
  return 1;
}

