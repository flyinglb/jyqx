// location.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *place_desc = ({
        "客店" ,
        "武庙" ,
        "中心广场" ,
        "青石大道" ,
        "山路" ,
        "大驿道",
        "南大街",
        "北大街",
        "东大街",
        "西大街",
        "赌场",
        "钱庄",
        "当铺",
        "树林"
});

int main(object me, string arg)
{
        object ob, *olist;
        mapping fam;
        int i, i1, cost;

        seteuid(getuid());

        if((time() - (int)me->query_temp("last_location_time") < 3)){
                write("阴阳八卦不是计算机，掐算是要花时间的。\n");
                return 1;
        }

        if (me->is_busy() || me->is_fighting() )
                return notify_fail("你现在正忙着呢。\n");

//      if(environment(me)->query("no_fight") || environment(me)->query("no_magic") )
//              return notify_fail("安全区内不能找人。\n");

        if ( (!(fam = me->query("family")) || fam["family_name"] != "桃花岛") 
        && !wizardp(me) )
                return notify_fail("只有桃花岛弟子才能打探别人的所在！\n");

        if ( me->query_skill("count",1) < 10 )
                return notify_fail("你的阴阳八卦尚未纯熟，无法了解别人的所在！\n");

        if ( !arg )
                return notify_fail("你要掐算谁的所在？\n");

        if ( present(arg, environment(me)) )
                return notify_fail("你要推算的人就在边上，你有问题吧？\n");
/*
        ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("你要打听谁的所在？\n");
        if (!me->visible(ob) ) return notify_fail("你要打听谁的所在？\n");
*/
        olist = livings();
        for(i=0,i1=sizeof(olist);i<i1;i++) {
                if( !olist[i]->id(arg) ) continue;
                if( !me->visible(olist[i]) ) continue;
                ob = olist[i];
                break;
        }
        if (!ob) return notify_fail("你要推测谁的所在？\n") ;
        if ( ob == me )
                return notify_fail("你没这麽笨吧，要别人告诉你自己的所在？\n");

        cost = me->query("max_jing")/(me->query_skill("count",1)/10) - 10;

        if ( me->query("jing") <= cost )
                return notify_fail("现在你太累了，无法去卜算别人的所在。\n");
        
        message_vision("只见$N盘膝坐下，双手内握，口中念念有词……\n",me);
        i = 2+random(2);
//      me->start_busy(random(i-1));
        call_out("location_result",i,me,ob,arg,cost);
        me->receive_damage("jing", cost );
        me->set_temp("last_location_time",time());
        return 1;
}

void location_result(object me, object ob, string target, int cost)
{
        object where;
        int sp, dp;

        message_vision("忽然$N脸露微笑: 有了!\n",me);

        sp = me->query_skill("count",1)*10 + me->query("jing");
        dp = ob->query("kar")*5 + ob->query("jing")*2;
        
        if ( random(sp) < random(dp)/2 ) {
                tell_object(me,"你又颓然坐下，摇了摇头，说道：不对的！\n");
                return;
        }


//      me->receive_damage("jing", cost );
        where = environment(ob);
        if(!where) {
                tell_object(me,"这个人不知道在哪里耶...\n");
                return;
        }
        if ( random(sp) < random(dp) ) 
        {
                if (strsrch(file_name(where), "baituo") >= 0)
                        tell_object(me, ob->name()+"现在在白驼山！\n");
                if (strsrch(file_name(where), "bupingshe") >= 0)
                        tell_object(me, ob->name()+"现在在不平社！\n");
                if (strsrch(file_name(where), "city4") >= 0)
                        tell_object(me, ob->name()+"现在在长安城！\n");
                if (strsrch(file_name(where), "city3") >= 0)
                        tell_object(me, ob->name()+"现在在成都城！\n");
                if (strsrch(file_name(where), "city2") >= 0)
                        tell_object(me, ob->name()+"现在在北京城！\n");
                if (strsrch(file_name(where), "city") >= 0)
                        tell_object(me, ob->name()+"现在在扬州城！\n");
                if (strsrch(file_name(where), "dali") >= 0)
                        tell_object(me, ob->name()+"现在在大理城！\n");
                if (strsrch(file_name(where), "death") >= 0)
                        tell_object(me, ob->name()+"现在在地狱里！\n");
                if (strsrch(file_name(where), "emei") >= 0)
                        tell_object(me, ob->name()+"现在在峨眉山上！\n");
                if (strsrch(file_name(where), "gaochang") >= 0)
                        tell_object(me, ob->name()+"现在在高昌迷宫！\n");
                if (strsrch(file_name(where), "gumu") >= 0)
                        tell_object(me, ob->name()+"现在在活死人墓！\n");
                if (strsrch(file_name(where), "guiyun") >= 0)
                        tell_object(me, ob->name()+"现在在归云庄！\n");
                if (strsrch(file_name(where), "wudujiao") >= 0)
                        tell_object(me, ob->name()+"现在在苗疆！\n");
                if (strsrch(file_name(where), "foshan") >= 0)
                        tell_object(me, ob->name()+"现在在佛山镇！\n");
                if (strsrch(file_name(where), "fuzhou") >= 0)
                        tell_object(me, ob->name()+"现在在福州城！\n");
                if (strsrch(file_name(where), "gaibang") >= 0)
                        tell_object(me, ob->name()+"现在在丐帮里！\n");
                if (strsrch(file_name(where), "guanwai") >= 0)
                        tell_object(me, ob->name()+"现在在关外！\n");
                if (strsrch(file_name(where), "hangzhou") >= 0)
                        tell_object(me, ob->name()+"现在在杭州城！\n");
                if (strsrch(file_name(where), "heishou") >= 0)
                        tell_object(me, ob->name()+"现在在五指山庄！\n");
                if (strsrch(file_name(where), "heimuya") >= 0)
                        tell_object(me, ob->name()+"现在在黑木崖上！\n");
                if (strsrch(file_name(where), "hengshan") >= 0)
                        tell_object(me, ob->name()+"现在在恒山上！\n");
                if (strsrch(file_name(where), "henshan") >= 0)
                        tell_object(me, ob->name()+"现在在衡山上！\n");
                if (strsrch(file_name(where), "henshan") >= 0)
                        tell_object(me, ob->name()+"现在在衡山上！\n");
                if (strsrch(file_name(where), "huanggon") >= 0)
                        tell_object(me, ob->name()+"现在在皇宫大内里！\n");
                if (strsrch(file_name(where), "huashan") >= 0)
                        tell_object(me, ob->name()+"现在在华山上！\n");
                if (strsrch(file_name(where), "jinshe") >= 0)
                        tell_object(me, ob->name()+"现在在金蛇洞！\n");
                if (strsrch(file_name(where), "kunlun") >= 0)
                        tell_object(me, ob->name()+"现在在昆仑山上！\n");
                if (strsrch(file_name(where), "lingjiu") >= 0)
                        tell_object(me, ob->name()+"现在在灵鹫峰上！\n");
                if (strsrch(file_name(where), "lingxiao") >= 0)
                        tell_object(me, ob->name()+"现在在凌霄城！\n");
                if (strsrch(file_name(where), "lingzhou") >= 0)
                        tell_object(me, ob->name()+"现在在灵州城！\n");
                if (strsrch(file_name(where), "meizhuang") >= 0)
                        tell_object(me, ob->name()+"现在在梅庄！\n");
                if (strsrch(file_name(where), "mingjiao") >= 0)
                        tell_object(me, ob->name()+"现在在昆仑山上！\n");
                if (strsrch(file_name(where), "murong") >= 0)
                        tell_object(me, ob->name()+"现在在燕子坞！\n");
                if (strsrch(file_name(where), "piaoxue") >= 0)
                        tell_object(me, ob->name()+"现在在飘雪山庄！\n");
                if (strsrch(file_name(where), "players") >= 0)
                        tell_object(me, ob->name()+"现在在新手盟！\n");
                if (strsrch(file_name(where), "qixinglou") >= 0)
                        tell_object(me, ob->name()+"现在在七星楼！\n");
                if (strsrch(file_name(where), "qingcheng") >= 0)
                        tell_object(me, ob->name()+"现在在青城山上！\n");
                if (strsrch(file_name(where), "quanzhen") >= 0)
                        tell_object(me, ob->name()+"现在在终南山上！\n");
                if (strsrch(file_name(where), "quanzhou") >= 0)
                        tell_object(me, ob->name()+"现在在泉州城！\n");
                if (strsrch(file_name(where), "shaolin") >= 0)
                        tell_object(me, ob->name()+"现在在少林寺里！\n");
                if (strsrch(file_name(where), "shenlong") >= 0)
                        tell_object(me, ob->name()+"现在在神龙岛上！\n");
                if (strsrch(file_name(where), "songshan") >= 0)
                        tell_object(me, ob->name()+"现在在嵩山上！\n");
                if (strsrch(file_name(where), "suzhou") >= 0)
                        tell_object(me, ob->name()+"现在在苏州城！\n");
                if (strsrch(file_name(where), "taishan") >= 0)
                        tell_object(me, ob->name()+"现在在泰山上！\n");
                if (strsrch(file_name(where), "tiezhang") >= 0)
                        tell_object(me, ob->name()+"现在在铁掌山上！\n");
                if (strsrch(file_name(where), "taohua") >= 0)
                        tell_object(me, ob->name()+"现在在桃花岛！\n");
                if (strsrch(file_name(where), "taohuacun") >= 0)
                        tell_object(me, ob->name()+"现在在桃花村！\n");
                if (strsrch(file_name(where), "tianjian") >= 0)
                        tell_object(me, ob->name()+"现在在天剑门！\n");
                if (strsrch(file_name(where), "tianlongsi") >= 0)
                        tell_object(me, ob->name()+"现在在天龙寺里！\n");
                if (strsrch(file_name(where), "village") >= 0)
                        tell_object(me, ob->name()+"现在在华山村！\n");
                if (strsrch(file_name(where), "wizard") >= 0)
                        tell_object(me, ob->name()+"现在在仙界！\n");
                if (strsrch(file_name(where), "wanjiegu") >= 0)
                        tell_object(me, ob->name()+"现在在万劫谷！\n");
                if (strsrch(file_name(where), "wudang") >= 0)
                        tell_object(me, ob->name()+"现在在武当山上！\n");
                if (strsrch(file_name(where), "xiakedao") >= 0)
                        tell_object(me, ob->name()+"现在在侠客岛上！\n");
                if (strsrch(file_name(where), "xiaoyao") >= 0)
                        tell_object(me, ob->name()+"现在在逍遥派里！\n");
                if (strsrch(file_name(where), "xingxiu") >= 0)
                        tell_object(me, ob->name()+"现在在星宿海！\n");
                if ((strsrch(file_name(where), "xuedao") >= 0) ||
                   (strsrch(file_name(where), "xueshan") >= 0))
                        tell_object(me, ob->name()+"现在在大雪山上！\n");
                if (strsrch(file_name(where), "xiangyang") >= 0)
                        tell_object(me, ob->name()+"现在在襄阳城！\n");
                else tell_object(me, ob->name()+"现在在哪里呢？不知道啊！\n");
                return;
        }
        if (random(10)>7)
        {
                printf("%s现在在%s。\n",
                (string)ob->name(), place_desc[random(sizeof(place_desc))]);
                return ;
        }
        printf("%s现在在%s。\n",
                (string)ob->name(),
                (string)where->query("short"));
        return ;
}


int help(object me)
{
        write(@HELP
指令格式: location <玩家的 ID>

这个指令是桃花岛弟子用来得知玩家目前所在的位置。

HELP
        );
        return 1;
}


