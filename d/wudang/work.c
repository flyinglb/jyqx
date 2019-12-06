#include <ansi.h>
inherit ROOM;
int do_fa(string arg);

void create()
{
        set("short", "伐木场");
        set("long", @LONG
这里是伐木场，四周是一片茂密的树林，一棵棵要几人才合抱的过来的大树
参天而立。场中的几个彪悍的伐木工正热火朝天的奋力砍着树，你来到这里不由
的手痒痒了，情不自禁掂了掂手中的斧子。
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
           return notify_fail("你还没有领工作呢。\n");

        if (query_temp("tree")==0)
           return notify_fail("现在没树砍了,歇一会儿再来吧。\n");

        if (!arg)
           return notify_fail("你要砍什么？\n");
        if (arg != "树" && arg != "shu" && arg != "mu")
           return notify_fail("你要砍什么？\n");

        if ( (int)me->query("jing") < 35 )
           return notify_fail("你已经累的不行了,当心你的小命啊。\n");

        if (me->query_temp("gongzuo/famu")==11)
           return notify_fail("树被你砍倒了，快把木料交回去。\n");  
  message_vision("$N深吸一口气,朝着大树狠狠的砍了下去。\n",me);
    me->add("jing",-(5+random(5)));
      me->add_temp("gongzuo/famu",1);
  if ( (int)me->query_temp("gongzuo/famu")==11)
 {
   message_vision(CYN"$N使出吃奶的气力砍出一斧头，大树终于倒下来了。\n"NOR,me);
        tell_object(me,HIW"通过伐树，你的潜能和经验增加了！\n" NOR);
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
  message_vision(RED"$N一不留神被落下的树杆了砸个正着，顿时眼冒金星。\n"NOR,me);     
       me->receive_damage("jing", 20+random(10));
}
/*
  if (random(5000)==1)
 {
       tell_object(me,HIW"你感到有一种奇怪的力量在身体里涌动！" NOR);
          me->add("str",1);
}
*/
        if (me->query_temp("gongzuo/famu") < 1)
        {
                write("偷别人的劳动成果，太没道德了吧!\n");
                return 0;
        }
   return 1;
} 

void reset()
{
           set_temp("tree" , 100000);
           ::reset();
}
