//modified by wind
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;

#include "message.h"

void create ()
{
  set_name(HIM "九百九十九朵小红玫瑰" NOR, ({ "flowers"}));
  set_weight(100);
  set("long","色彩艳丽的"+query("name")+"。\n");
  set("unit", "把");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 2);
  set("value", 50000);
  set("unequip_msg","$N将"+query("name")+"轻轻地摘下来……。\n");
  set("wear_msg", "$N戴上"+query("name")+"，不禁想起年少时曾经的梦中人。\n");
  setup();
}


