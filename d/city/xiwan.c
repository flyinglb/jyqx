#include <ansi.h>
inherit ROOM;
int do_xi(string arg);

void create()
{
        set("short", "���");
        set("long", @LONG
����������¥�ĺ��,������ʦ��æ����Ȼ��졣С��æµ��
������ȥ.����������ù�����ûϴ�����롣
LONG
        );
        set("exits", ([
          "south"      : "/d/city/zuixianlou",
        ]));
          set_temp("wan" , 5000);
//         set("objects",
//           __DIR__"chushi" : 1,
//         ]));
        set("no_fight", "1");
      set("no_steal", "1");
        setup();
}
void init()
{
     add_action("do_xi","xi");
}
int do_xi(string arg)
{
object me;
me=this_player(); 
        if (!me->query_temp("xiwan"))
           return notify_fail("����׸ɣ�\n");

        if (query_temp("wan")==0)
           return notify_fail("�ڴ�ҵĹ�ͬŬ���£��붼ϴ���ˡ����������ɡ�\n");
        if (!arg || (arg != "��" && arg != "wan"))
           return notify_fail("��Ҫϴʲô��\n");
        if ( (int)me->query("jing")<20)
           return notify_fail("���Ѿ��۵Ĳ�����,ϴ��Ҳ�������˰���\n");
        if (me->query_temp("xiwan")==10)
           return notify_fail("�ɵĲ���ˣ�����ȥҪ��Ǯ�ˡ�\n");  
  message_vision("$N��ʼϴ������.\n",me);
    me->add("jing",-(5+random(5)));
      me->add_temp("xiwan",1);
  if ( (int)me->query_temp("xiwan")==10)
 {
   write(CYN"�ɵĲ���ˣ�����ȥҪ��Ǯ�ˡ�\n"NOR);
        tell_object(me,HIW"ͨ��ϴ�룬���Ǳ�ܺ;��������ˣ�\n" NOR);
         me->add("combat_exp",50+random(100));
           me->add("potential",10+random(20));
        me->improve_skill("unarmed");
      add_temp("wan",-1);      return 1;
 }
 if (random(50)==1)
 {
  message_vision(RED"$Nһ��������������!\n"NOR,me);
  message_vision(RED"¥�����������ĺ�������¶������ã�$N������ˣ�\n"NOR,me);     
me->delete_temp("xiwan");
}
/*
     if (random(5000)==1)
{
       tell_object(me,HIW"��е���һ����ֵ�������������ӿ����" NOR);
          me->add("con",1);
}
*/
 return 1;
}
