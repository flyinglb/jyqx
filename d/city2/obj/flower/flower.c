// modified by wind

#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;

#include "message.h"

void create()
{
  seteuid(getuid());

  switch (random(14))
  {
    case 0:
      { set_name(HIB "��õ��" NOR, ({ "flower"})); break; }
    case 1:
      { set_name(HIB "��������" NOR, ({ "flower"})); break; }
    case 2:
      { set_name(HIW "��ѩ��" NOR, ({ "flower"})); break; }
    case 3:
      { set_name(HIR "Ұ������" NOR, ({ "flower"})); break; }
    case 4:
      { set_name(HIW "���¶" NOR, ({ "flower"})); break; }
    case 5:
      { set_name(HIW "˯ܽ��" NOR, ({ "flower"})); break; }
    case 6:
      { set_name(HIC "��Ǿޱ" NOR, ({ "flower"})); break; }
    case 7:
      { set_name(HIR "������" NOR, ({ "flower"})); break; }
    case 8:
      { set_name(HIM "������" NOR, ({ "flower"})); break; }
    case 9:
      { set_name(HIW "��õ��" NOR, ({ "flower"})); break; }
    case 10:
      { set_name(HIG "�����" NOR, ({ "flower"})); break; }
    case 11:
      { set_name(HIW "ѩ��÷" NOR, ({ "flower"})); break; }
    case 12:
      { set_name(HIB "������" NOR, ({ "flower"})); break; }
    case 13:
      { set_name(HIW "˯��" NOR, ({ "flower"})); break; }
  }
  set_weight(100);
  set("long","һ��ɫ��������"+query("name")+"��\n");
  set("unit", "��");
  set("value", 1000);
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 15);
  setup();
}

int init ()
{
  add_action ("do_wear", "wear");
  add_action ("do_wear", "dai");
  add_action ("do_remove", "remove");
  add_action ("do_smell", "smell");
  add_action ("do_smell", "wen");
  add_action ("do_water", "water");
  add_action ("do_fix", "fix");
  call_out("need_water", 10+random(10), environment(this_object()));
  return 1;
}

int do_wear (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower")
    return 0;
  if( me->query("gender") == "����") {
   write("Ů�˲Ŵ�������һ���������߲��߰�����\n");
    return 1; }
  switch (random(9))
  {
    case 0:
      { msg = "$N����һ��"+name+"��������������ʱ�����������ˡ�\n"; break; }
    case 1:
      { msg = "$N����"+name+"����Ĭ�����������������̡�\n"; break; }
    case 2:
      { msg = "$N����"+name+"���ڷ��ʣ����һЦ��\n"; break; }
    case 3:
      { msg = "$N��һ��"+name+"������ǰ������ס�������¡�\n"; break; }
    case 4:
      { msg = "$N��"+name+"������ǰ���Ǹ���Ϥ�������ѿڶ�����\n"; break; }
    case 5:
      { msg = "$N��"+name+"������ǰ�����ﲻ��һ�ȡ�\n"; break; }
    case 6:
      { msg = "$N��"+name+"�������������һ�ǣ�Ȼ�������ǰ��\n"; break; }
    case 7:
      { msg = "$NС�ĵذ�"+name+"���ڷ����ϡ�\n"; break; }
    case 8:
      { msg = "$N����������һ˦����"+name+"�������档\n"; break; }
  }
  //message_vision (msg,me);
  flower->set("wear_msg",msg);
  return 0;
}

int do_remove (string arg)
{
//  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower")
    return 0;

  msg = "$N��"+name+"�����ժ��������\n"; 
  //message_vision (msg,me);
  flower->set("unequip_msg",msg);
  return 0;
}

int do_smell (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower")
    return 0;

  switch (random(9))
  {
    case 0:
      { msg = "$N������"+name+"���������Ǻ���Ϥ������ζ��\n"; break; }
    case 1:
      { msg = "$N��ͷ����һ��"+name+"��Ť��ͷȥ����һ�������硣\n"; break; }
    case 2:
      { msg = "$N����"+name+"һ�ᣬ��ˮ���ڻ����ϡ�\n"; break; }
    case 3:
      { msg = "$N��һ��"+name+"���ڱ����£��밡�밡����\n"; break; }
    case 4:
      { msg = "$N����"+name+"����һ�£�������Ϧ�Ǻ�Ϧ��\n"; break; }
    case 5:
      { msg = "$N��"+name+"���������ţ��ֵ��������Ĺ��ˡ�\n"; break; }
    case 6:
      { msg = "$N������"+name+"����һ�ţ�˼�������細���ϸ�ꡣ\n"; break; }
    case 7:
      { msg = "$N������"+name+"���ճյ����Ŵ���Ʈ����С�ꡣ\n"; break; }
    case 8:
      { msg = "$N��"+name+"����һ�ᣬ����������������ĺδ�����\n"; break; }
  }
  message_vision (msg,me);
  return 1;
}

int do_fix (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower")
    return 0;

  msg = "$N��"+name+"С�ĵ���ʪ���˿����á�\n";
  flower->set("fixed",1);
  message_vision (msg,me);
  return 1;
}

void need_water (object where)
{
  object flower = this_object();
  object who = environment(flower);
  string name = flower->query("name");
  string msg;
  object seed;

  if (!who || !living(who))
    return;

  if (flower->query("fixed"))
    return;

  switch (flower->query("water"))
  {
    case 0:
      { msg = "�紵����"+name+"��$N����ǰ�����һ�¡�\n"; break; }
    case 1:
      { msg = name+"�е���ˣ�Ŷ������һ��ˮ�ˡ�\n"; break; }
    case 2:
      { msg = name+"��������ͷ��\n"; break; }
    case 3:
      { msg = name+"̧��ͷ�������ؿ���$N��\n"; break; }
    case 4:
      { msg = name+"���ѵ�������ֱ���ˣ���ˮ������\n"; break; }
    case 5:
      { msg = name+"���ڸɿ��ˡ�\n"; flower->set("name","��"+name); break; }
    default:   //added by mon 8/31/97
      {  
        if(flower->query("water")>10 && random(10)==0) {
          message_vision(name+
	  "�����𣬻�����ƬƬ���꣮����\n"+
	  "�ٿ�ʱ��ֻ��һ���ںڵĻ��ѻ�����$N���ϡ�\n"
	  ,who);
	  seed = new (__DIR__"seed");
          seed->move(who);
          destruct(flower);
	  return;
	}
      }
  }
  if(msg)message_vision (msg,who);
  flower->set("water",flower->query("water")+1);
  call_out ("need_water",random(50)+50,where);
}

int do_water (string arg)
{
  object flower = this_object();
  object who = this_player();
  string name = flower->query("name");
  string msg;

  if (arg != "flower")
    return 0;

  if (flower->query("water") >= 5)
  {
    message_vision ("$N����ˮһ�ε�����"+name+"�ϡ�\n",who);
    return 1;
  }

  switch (random(9))
  {
    case 0:
      { msg = "$N�ں���ˮ������"+name+"�Ļ����ϡ�\n"; break; }
    case 1:
      { msg = "$N��һ����ˮ����"+name+"�ϡ�\n"; break; }
    case 2:
      { msg = "$N�����ץסϸϸ��С�꣬����"+name+"�ϡ�\n"; break; }
    case 3:
      { msg = "$NС�ĵ�����һ���¶ˮ������"+name+"�Ļ����ϡ�\n"; break; }
    case 4:
      { msg = "$Nһ����ʹ����ˮ����"+name+"�Ļ����ϡ�\n";break; }
    case 5:
      { msg = "$N˫������"+name+"���쵽�����С���С���\n";break; }
    case 6:
      { msg = "$N��ϸ������һֻС���ӣ���ˮ����"+name+"�ϡ�\n";break; }
    case 7:
      { msg = "$N�����Ұ������ĳ�¶������"+name+"�Ļ����ϡ�\n";break; }
    case 8:
      { msg = "$N����ָպ����ˮ��һ������"+name+"�Ļ����ϡ�\n";break; }
  }
  message_vision (msg,who);
  message_vision (name+"����¶���������Ц�ݡ�\n",who);
  flower->set("water",0);
  return 1;
}
