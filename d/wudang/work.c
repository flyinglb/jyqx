#include <ansi.h>
inherit ROOM;
int do_fa(string arg);

void create()
{
        set("short", "��ľ��");
        set("long", @LONG
�����Ƿ�ľ����������һƬï�ܵ����֣�һ�ÿ�Ҫ���˲źϱ��Ĺ����Ĵ���
������������еļ����뺷�ķ�ľ�����Ȼ���ķ��������������������ﲻ��
���������ˣ��鲻�Խ����˵����еĸ��ӡ�
LONG
        );
        set("exits", ([
        "east"      : "/d/wudang/wdroad1",
        ]));
           set_temp("tree" , 100000);
       set("objects", ([ /* sizeof() == 1 */
          __DIR__"npc/gongtou" : 1,
         ]));
        set("no_fight", "1");
      set("no_steal", "1");
        setup();
}
void init()
{
     add_action("do_fa","fa");
}

int do_fa(string arg)
{
        object me=this_player(); 
        object ob;
        if (!me->query_temp("gongzuo/famu"))
           return notify_fail("�㻹û���칤���ء�\n");

        if (query_temp("tree")==0)
           return notify_fail("����û������,Ъһ��������ɡ�\n");

        if (!arg)
           return notify_fail("��Ҫ��ʲô��\n");
        if (arg != "��" && arg != "shu" && arg != "mu")
           return notify_fail("��Ҫ��ʲô��\n");

        if ( (int)me->query("jing") < 35 )
           return notify_fail("���Ѿ��۵Ĳ�����,�������С������\n");

        if (me->query_temp("gongzuo/famu")==11)
           return notify_fail("�����㿳���ˣ����ľ�Ͻ���ȥ��\n");  
  message_vision("$N����һ����,���Ŵ����ݺݵĿ�����ȥ��\n",me);
    me->add("jing",-(5+random(5)));
      me->add_temp("gongzuo/famu",1);
  if ( (int)me->query_temp("gongzuo/famu")==11)
 {
   message_vision(CYN"$Nʹ�����̵���������һ��ͷ���������ڵ������ˡ�\n"NOR,me);
        tell_object(me,HIW"ͨ�����������Ǳ�ܺ;��������ˣ�\n" NOR);
         me->add("combat_exp",50+random(100));
       me->add("potential",10+random(20));
                  me->improve_skill("parry", me->query("int"));
     ob=new(__DIR__"obj/muliao.c");
      ob->set( "possession",me->query("id") );
      ob->move(environment(me));
      add_temp("tree",-1);      return 1;
 }
 if (random(10)==1)
 {
  message_vision(RED"$Nһ���������µ��������Ҹ����ţ���ʱ��ð���ǡ�\n"NOR,me);     
       me->receive_damage("jing", 20+random(10));
}
/*
  if (random(5000)==1)
 {
       tell_object(me,HIW"��е���һ����ֵ�������������ӿ����" NOR);
          me->add("str",1);
}
*/
        if (me->query_temp("gongzuo/famu") < 1)
        {
                write("͵���˵��Ͷ��ɹ���̫û�����˰�!\n");
                return 0;
        }
   return 1;
} 

void reset()
{
           set_temp("tree" , 100000);
           ::reset();
}
