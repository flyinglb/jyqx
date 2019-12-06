//modified by wind

#include <ansi.h>
#include <dbase.h>

inherit ITEM;

#include "message.h"

void create()
{
  set_name("����", ({ "seed"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","һ��СС�Ļ��ѡ�\n");
    set("unit", "��");
    set("value", 100);
  }
  setup();
  call_out("need_water", 3, environment(this_object()));
}

int init ()
{
  add_action ("do_water", "water");
  this_object()->set("water",0);
  return 1;
}

void grow (object where)
{
  object me = this_object();
  object who = environment(me);
//  string name = me->query("name");
//  string msg;

  if (! living(who))
    return;

  if (me->query("dried"))
    return;

  if (me->query("id") == "seed")
  {
    if (random(6) == 0)
    {
      message_vision ("�������ѿ���¶����һ����ѿ��\n",who);
      me->set_name("��ѿ", ({ "germ"}));
      //me->set("name","��ѿ");
      //me->set("id","germ");
      me->set("long","һ�����ڳ����С��ѿ��\n");
      me->set("unit", "��");
    }
    else
      message_vision ("���Ѷ���һ�£��ʹ���һ��㡣\n",who);
    return;
  }

  if (me->query("id") == "germ")
  {
    if (random(9) == 0)
    {
      message_vision ("��ѿ���ڳ����ˣ��ڷ��л����ҡ߮��\n",who);
      me->set_name("�̲�", ({ "plant"}));
      //me->set("name","�̲�");
      //me->set("id","plant");
      me->set("long","һ����׳���̲ݣ������л�����\n");
      me->set("unit", "��");
    }
    else
      message_vision ("��ѿ����һ��������һ�ء�\n",who);
    return;
  }

  if (me->query("id") == "plant")
  {
    if (random(12) == 0)
    {
      object flower;
      message_vision ("�̲��ϵĻ��������ˣ��������ˣ�\n",who);
      flower = new (__DIR__"flower");
      flower->move(who);
      destruct(me);
    }
    else
    {
      switch (random(3))
      {
        case 0:
          { message_vision ("�̲��ڷ����������衣\n",who); break; }
        case 1:
          { message_vision ("�̲�Ҫ�����ˡ�\n",who); break; }
        case 2:
          { message_vision ("�̲�΢Ц�š�\n",who); break; }
      }
    }
  }
}

void need_water (object where)
{
  object me = this_object();
  object who = environment(me);
  string name = me->query("name");
  string msg;

  if (!who || !living(who))
    return;

  if (me->query("id") == "seed")
  {
    call_out ("need_water",3,where);
    return;
  }

  switch (me->query("water"))
  {
    case 0:
      { msg = name+"������һ�㡣\n"; break; }
    case 1:
      { msg = name+"�е����ˣ�����һ��ˮ�ɡ�\n"; break; }
    case 2:
      { msg = name+"��ʼ�����ˡ�\n"; break; }
    case 3:
      { msg = name+"�Ѿ�ʧȥ����ɫ�Ĺ���\n"; break; }
    case 4:
      { msg = name+"����ȥ����ȱˮ������һϢ�ˡ�\n"; break; }
    case 5:
      { msg = name+"�ɿ��ˡ�\n";
        me->set("name","��"+name);
        me->set("dried",1);
        break; }
  }
  message_vision (msg,who);
  me->set("water",me->query("water")+1);
  call_out ("need_water",random(10)+10,where);
  remove_call_out ("grow");
  call_out ("grow",random(5)+5,where);
}

int do_water (string arg)
{
  object me = this_object();
  object who = this_player();
  string name = me->query("name");
  string msg;

  if (arg != me->query("id"))
    return 0;

  if (me->query("water") >= 5)
  {
    message_vision ("$N����ˮһ�ε�����"+name+"�ϡ�\n",who);
    return 1;
  }

  switch (random(9))
  {
    case 0:
      { msg = "$N�ں���ˮ������"+name+"�ϡ�\n"; break; }
    case 1:
      { msg = "$N��һ����ˮ����"+name+"�ϡ�\n"; break; }
    case 2:
      { msg = "$N�����ץסϸϸ��С�꣬����"+name+"�ϡ�\n"; break; }
    case 3:
      { msg = "$NС�ĵ�����һ���¶ˮ������"+name+"�ϡ�\n"; break; }
    case 4:
      { msg = "$Nһ����ʹ����ˮ����"+name+"�ϡ�\n";break; }
    case 5:
      { msg = "$N˫������"+name+"���쵽�����С���С���\n";break; }
    case 6:
      { msg = "$N��ϸ������һֻС���ӣ���ˮ����"+name+"�ϡ�\n";break; }
    case 7:
      { msg = "$N�����Ұ������ĳ�¶������"+name+"�ϡ�\n";break; }
    case 8:
      { msg = "$N����ָպ����ˮ��һ������"+name+"�ϡ�\n";break; }
  }
  message_vision (msg,who);
  me->set("water",0);
  remove_call_out ("grow");
  call_out ("grow",random(5)+5,who);
  return 1;
}
