//LUCAS 2000-6-18
// �������

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_give","��ô���ľƣ����������ˣ�\n");
    set("no_drop","��ô��������ƣ����˶��ϧѽ��\n");
    set("no_sell","���������ƶ�Ҫ��,��̫��������˰ɡ�\n");
  }
  add_action("do_drink", "drink");
}

void create()
{
  set_name( YEL "�������" NOR , ({"shenyang yujiu", "jiu"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ����Ƶ�ճ��ҩ�ƣ��������ǵ����,��֮��ѧ��������档\n");
    set("value", 0);
    set("drug_type", "��Ʒ");
  }
  set("is_monitored",1);
  setup();
}

int do_drink(string arg)
{
  object me = this_player();
  if (arg!="jiu" && arg!="shenyang yujiu")   return 0;
  
  me->set("eff_jing", (int)me->query("max_jing"));
  me->set("jing", (int)me->query("max_jing"));
  me->set("eff_qi", (int)me->query("max_qi"));
  me->set("qi", (int)me->query("max_qi"));
  me->set("neili", (int)me->query("max_neili"));
  me->set("jingli", (int)me->query("max_jingli"));
 message_vision(HIW "$N�ٱ����²������,ֻ��С���������ϳ壬�����ؿڼ����
���հ���������,ֻ��ͨ���ں�,�ĺ���̩��\n" NOR, me);
  destruct(this_object());
  return 1;
}

