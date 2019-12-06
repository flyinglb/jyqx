//modified by wind
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;

#include "message.h"

void create()
{
  set_name(HIY "��" NOR, ({ "gui hua", "flower"}));
  set_weight(100);
  set("material", "flower");
  set("long","һ���ƵĹ𻨣�ɢ����һ˿˿���㡣\n");
  set("unit", "��");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 1);
  set("value", 1500);
  setup();
}

int init ()
{
  add_action ("do_wear", "wear");
  add_action ("do_remove", "remove");
  add_action ("do_smell", "smell");
  add_action ("do_smell", "wen");
  return 1;
}

int do_wear (string arg)
{
//  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower" && arg != "gui hua")
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

  if (arg != "flower" && arg != "gui hua")
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

  if (arg != "flower"&& arg != "gui hua")
    return 0;

  msg = "$N��"+name+"���������ţ��ֵ��������Ĺ��ˡ�\n"; 
  message_vision (msg,me);
  return 1;
}
