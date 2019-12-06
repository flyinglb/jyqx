// judge.c
// modified by wind
#include <ansi.h>

inherit NPC;
void create()
{
        set_name("宝官", ({ "judge" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "他脸上的表情仿佛是看到了你口袋里的钱一般。\n");
        set("per", 25);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        set_skill("parry", 70);
        set("inquiry", ([
                "赌" : "本赌场开放赌「大小」局子，您要是有兴趣不妨玩两把？(ya big|small <数量> <货币类型>)",
        ]) );
        setup();
        add_money("silver", 1);
        set("accept",1);
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/dagger")->wield();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
           remove_call_out("greeting");
           call_out("greeting", 1, ob);
        }
        add_action("do_ya", "ya");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) )
        {
          case 0:
                 say( "快来赌，快来赌啦！\n");
                 break;
          case 1:
                 say( "赢了可是利滚利啊！\n");
                 break;
        }
}

int do_ya(string arg)
{
    int ran,cnt;
    string type0, type1,status;
    object money_ob,me;

    int min, max;
    min = 100;
    max = 1000000;

    me = this_player();

    if (!arg || sscanf(arg, "%s %d %s", type0, cnt,type1) !=3)
      return notify_fail("ya big|small <数量> <货币类型>\n比如：ya big 3 silver\n");
    money_ob = present(type1,me);
    if( !money_ob)
      return notify_fail(HIY"你身上没有这种货币。\n");
    if( cnt<1 )
      return notify_fail("你要压多少啊?\n");
    if( (int)money_ob->query_amount() < cnt)
      return notify_fail("你身上没有那么多" + money_ob->query("name") + "。\n");
    if( cnt*money_ob->query("base_value") < min || cnt*money_ob->query("base_value") >(max+1)) 
      return notify_fail("你的赌注不在限额之内!\n这里的限额是一两白银到一百两黄金\n");
    if ( (type0 != "big") && (type0 != "small") ) 
      return notify_fail("你要押大还是呀小?\n");

    ran=random(10);
    
    if (ran>=5) 
         message_vision(HIY"开！！！："HIM"大！"NOR"\n", me);
    else
         message_vision(HIY"开！！！："HIC"小！"NOR"\n", me);
       

    if ((ran>=5 && type0=="small") || (ran<5 && type0=="big")) status="lose";
    else status="win";

    if ( status == "lose") 
     {
       message_vision(me->query("name") + "输了" + chinese_number(cnt) +money_ob->query("base_unit") + money_ob->query("name") + "。\n", me);
       money_ob->set_amount((int)money_ob->query_amount() - cnt);
       money_ob->move(me);
      }
    else
     {
       message_vision(me->query("name") + "赢了" + chinese_number(cnt) +money_ob->query("base_unit") + money_ob->query("name") + "。\n", me);
       money_ob->set_amount((int)money_ob->query_amount() + cnt);
       money_ob->move(me);
      }
    return 1;
}
