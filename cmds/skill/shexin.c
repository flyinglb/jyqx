      // shexin.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        //string dest, cmd, verb;
        string dest, cmd;
        object ob;
        mapping fam;

        seteuid(getuid());

        if( me != this_player() ) return 0;
        if( environment(me)->query("no_fight") )
                return notify_fail("这里禁止战斗。\n");
        if ((!(fam = me->query("family")) || fam["family_name"] != "雪山寺"))
             return notify_fail("只有雪山弟子才能行使慑心术！\n");          
        if (me->query_skill("necromancy",1) < 40)
             return notify_fail("你的降伏法还太浅薄了，没法行使慑心术。\n");
        if (me->query_skill("force",1) < 100)
             return notify_fail("你的内功不够，小心被人反慑心了。\n");
        if (me->query("neili",1) < 500)
             return notify_fail("你的内力不足，小心被人反慑心了。\n");

        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("指令格式: shexin <某人> to <指令>\n");

//      if (!ob = get_object( dest ) )
        if( !objectp(ob = present(dest, environment(me))))
                return notify_fail("找不到" + dest + "。\n");
        if( !living(ob) )
                return notify_fail("这个物件不能被慑心。\n");
        if( wiz_level(me) < wiz_level(ob) )
                return notify_fail("你没法对" + ob->name() + "行使慑心术。\n");

message_vision("
$N的一对眼睛半眯着，只如两道细缝，但细缝中莹然有光，眼神甚是清朗。
$n微觉不妥，要想转头避开$N的眼光，可是一双眼睛竟似被$N的目光吸住了，
不由自主的凝视着他。\n", me, ob);
        if( random(me->query_skill("necromancy",1)) < random(ob->query_skill("force",1)) * 2 )
        {
message_vision("突然$n猛地一阵清醒，于是，$n大喝一声：你活腻了，敢来对我施慑心术？\n", me, ob);
                if( ob->query("age")>17) ob->fight_ob(me);
                return 1;
        }

        if (strsrch(cmd, "give ") >= 0)
        {
message_vision("于是，$n迷迷糊糊也不知道是递了些什么给$N。\n", me, ob);
        }
        else
        {
            if (strsrch(cmd, "go ") >= 0)
            {
                if( !userp(ob) )
                    return notify_fail("你只能对玩家行使慑心术。\n");
message_vision("结果，$n迷迷糊糊也不知道怎么回事就往前摸着走开了。\n", me, ob);
            }
            else
            {
                if (strsrch(cmd, "follow ") >= 0)
                {
                    if( !userp(ob) )
                        return notify_fail("你只能对玩家行使慑心术。\n");
message_vision("果然，$n迷迷糊糊地就跟在$N的屁股后面走了。\n", me, ob);
                }
                else
return notify_fail("你只能慑心人家做：give、go和follow。\n");
            }
        }
        if( wizardp(ob) )
return notify_fail("巫师不能被你慑心。\n");

        if( userp(ob) )
                log_file("shexin_player", sprintf("[%s] %s shexin %s to %s\n",
                        ctime(time()), geteuid(me), geteuid(ob), cmd));
        return ob->force_me(cmd);
}

int help(object me)
{
        write(@Help
 指令格式: shexin <某人> to <指令>

 shexin sb to give sth to sb
 shexin sb to follow sb
 shexin sb to go <dir>

利用慑心术诱惑某人做把身上的东西给你, 或往那里离开，或者
跟着你。当然你必须是雪山派弟子，且有相当的降伏法修为。
对方如果内功深厚，而你学艺不精，必然也会招致以牙还牙。当心！
Help
        );
        return 1;
}

