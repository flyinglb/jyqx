#include <ansi.h>
inherit ROOM;
int do_xi(string arg);

void create()
{
        set("short", "后厨");
        set("long", @LONG
这里是醉仙楼的后厨,几个厨师正忙活的热火朝天。小二忙碌的
走来走去.角落里堆着用过，还没洗的脏碗。
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
           return notify_fail("你想白干？\n");

        if (query_temp("wan")==0)
           return notify_fail("在大家的共同努力下，碗都洗好了。过会再来吧。\n");
        if (!arg || (arg != "碗" && arg != "wan"))
           return notify_fail("你要洗什么？\n");
        if ( (int)me->query("jing")<20)
           return notify_fail("你已经累的不行了,洗碗也会累死人啊！\n");
        if (me->query_temp("xiwan")==10)
           return notify_fail("干的差不多了，可以去要工钱了。\n");  
  message_vision("$N开始洗起碗来.\n",me);
    me->add("jing",-(5+random(5)));
      me->add_temp("xiwan",1);
  if ( (int)me->query_temp("xiwan")==10)
 {
   write(CYN"干的差不多了，可以去要工钱了。\n"NOR);
        tell_object(me,HIW"通过洗碗，你的潜能和经验增加了！\n" NOR);
         me->add("combat_exp",50+random(100));
           me->add("potential",10+random(20));
        me->improve_skill("unarmed");
      add_temp("wan",-1);      return 1;
 }
 if (random(50)==1)
 {
  message_vision(RED"$N一不留神把碗打碎了!\n"NOR,me);
  message_vision(RED"楼上有人气冲冲的喊：这点事都做不好，$N被解雇了！\n"NOR,me);     
me->delete_temp("xiwan");
}
/*
     if (random(5000)==1)
{
       tell_object(me,HIW"你感到有一种奇怪的力量在身体里涌动！" NOR);
          me->add("con",1);
}
*/
 return 1;
}
