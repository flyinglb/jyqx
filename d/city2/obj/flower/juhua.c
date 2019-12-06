#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;

#include "message.h"

void create()
{	
switch (random(3))
  {
	case 0:
 	{ set_name(HIB "Ұ�ջ�" NOR, ({ "ju hua", "flower"})); break; }
	case 1:
  	{ set_name(HIC "ʸ����" NOR, ({ "ju hua", "flower"})); break; }
	case 2:
	{ set_name(HIW "�׾ջ�" NOR, ({ "ju hua", "flower"})); break; }
}
  set_weight(100);
  set("long","һ�����µ�����С"+query("name")+"��ɢ����һ˿˿���㡣\n");
  set("material", "flower");
  set("unit", "��");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 1);
  set("value", 100);
  setup();
}

int init ()
{
  add_action ("do_wear", "wear");
  add_action ("do_wear", "dai");
  add_action ("do_remove", "remove");
  add_action ("do_smell", "smell");
  add_action ("do_smell", "wen");
  call_out("need_water", 10+random(10), environment(this_object()));
  return 1;
}

int do_wear (string arg)
{
//  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower" && arg != "ju hua")
    return 0;
  msg = "$N����һ��"+name+"��������������ʱ�����������ˡ�\n"; 
  flower->set("wear_msg",msg);
  return 0;
}

int do_remove (string arg)
{
//  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower" && arg != "ju hua")
    return 0;

  msg = "$N��"+name+"�����ժ��������\n"; 
  flower->set("unequip_msg",msg);
  return 0;
}

int do_smell (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower" &&  arg != "ju hua")
    return 0;

  msg = "$N��"+name+"���������ţ��ֵ��������Ĺ��ˡ�\n"; 
  message_vision (msg,me);
  return 1;
}
