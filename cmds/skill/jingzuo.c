// jingzuo.c
// Dec.11 1997 by Venus

void wakeup(object me, object where);
void del_jingzuoed(object me);

int main(object me, string arg)
{
//      mapping fam;
        object where = environment(me);

        seteuid(getuid());

//        if ((!(fam = me->query("family")) || fam["family_name"] != "峨嵋派"))
//             return notify_fail("只有峨嵋派才能静坐！\n");
        if (where->query("no_sleep_room"))
             return notify_fail("这里太纷杂，你没法静心静坐。\n");
        if (!where->query("sleep_room"))
             return notify_fail("这里太纷杂，你没法静心静坐。\n");
        if (me->query("eff_jing")<50)
             return notify_fail("你受伤太重，没法静坐。\n");
        if (me->is_busy())
             return notify_fail("你正忙着呢！\n");
        if (me->is_fighting())
             return notify_fail("战斗中想静坐？你不要命啦！\n");
	me->save();
//        if (me->query("mud_age") - me->query("jingzuo_time") < 120)
        if (time() - me->query("jingzuo_time") < 120)
             return notify_fail("你刚才静坐过，现在头脑一片空白。\n");
        if (me->query_skill("mahayana",1) < 120)
             return notify_fail("你的大乘般涅磐功还太浅薄了，没法静心静坐。\n");
        if (where->query("sleep_room"))
        {
             write("你往床上盘膝一坐，开始静坐。\n");
             write("不一会儿，你神游天外，物我两忘。\n");
             me->set_temp("block_msg/all",1);
             message_vision("$N一躬身，坐在床上，闭目端念，静心打坐。\n",me);
             where->set("no_fight", 1);
             where->add_temp("jingzuo_person", 1);

             me->set("no_get", 1);
             me->set("no_get_from", 1);
             me->disable_player("<静坐中>");
             call_out("wakeup",random(25)+1 , me, where);

             return 1;
        } else return notify_fail("这里太纷杂，你没法静心静坐。\n");
}

void wakeup(object me,object where)
{
       int skillslvl,addp,intpot;

       skillslvl = (int) me->query_skill("mahayana",1);
       //exppot = (int)(me->query("combat_exp")/20000);
       intpot = (int)(me->query_int()/10);
       addp = (int)(random(skillslvl)/4+intpot);
       //addc = (int)(random(skillslvl)/3+exppot);
       me->add("jing",-15);
       me->add("eff_jing",-3);
       me->add("potential",addp);
      if (me->query("potential")-me->query("learned_points")>600)
      {
           me->set("potential",me->query("learned_points")+600);
      }
       //me->add("combat_exp",addc);
       me->enable_player();
       message_vision("$N静坐完毕，缓缓睁眼，长长吐了一口气。\n",me);
       me->set_temp("block_msg/all", 0);
//     me->set("jingzuo_time", me->query("mud_age"))
       me->set("jingzuo_time", time());
       write("你静坐完毕，好累的感觉。\n");

       where->delete("no_fight");
       where->add_temp("jingzuo_person", -1);
       me->delete("no_get");
       me->delete("no_get_from");
       return;
}

int help(object me)
{
        write(@HELP
指令格式 : jingzuo <精点数>

这个指令是峨嵋派弟子用以静坐修道的命令.

HELP
        );
        return 1;
}
