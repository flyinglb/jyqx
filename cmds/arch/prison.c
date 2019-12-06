//prison.c 关押某人
// Byp@MX

inherit F_CLEAN_UP;
#define MAX_P_TIME 24*60
void do_release(object me);

int main(object me, string arg)
{
        object who;
        int ptime;
        if(!wizardp(me))
                return notify_fail("你想干什么？\n");
        if(!arg)
                return notify_fail("你关谁？\n");
        if( sscanf(arg, "%s %d", arg, ptime)!=2 )
                ptime = 60;
        
        who = find_player(arg);
        
        if(!who) 
                return notify_fail("没有这个玩家。\n");
                
        if(wizardp(who)) 
                return notify_fail("不能关巫师！\n");

//        if(!who->query_temp("warrning")) 
//                return notify_fail("不要不告而杀，请先用 warning 命令警告他吧。\n")

        if(ptime > MAX_P_TIME)
                return notify_fail("对玩家惩罚请不要过于严厉！\n");
        
        seteuid(getuid());
        who->move("/d/wizard/prison");
        who->set("prison/start_time", time());
        who->set("prison/release_time", ptime);
        who->set("startroom",base_name(environment(who)));
        who->save();
        who->disable_player(HIR"<关押中>"NOR);

        CHANNEL_D->do_channel(this_object(), "rumor", "听说"
        + who->name() + "因为捣乱被关进了金庸黑狱！\n");
        
        who->set_temp("block_msg/all", 1);
        call_out("do_release",60, who);
        return 1;
}

void do_release(object who)
{
        if(!objectp(who)) return;
        if((int)who->query("prison/release_time") > 0) {
                who->add("prison/release_time", -1);
                //加这句是因为系统会自动 enable_player()
                who->disable_player(HIR"<关押中>"NOR);
                who->save();
                call_out("do_release",60, who);
                return;
        }
        who->enable_player();
        who->set_temp("block_msg/all",0);
        who->delete("prison");
        who->move("/d/city/wumiao");
        who->set("startroom","/d/city/wumiao");
        message("vision", "你忽然发现前面多了一个人影，不过那人影又好像已经在那里\n"
                "很久了，只是你一直没发觉。\n", environment(who), who);
        tell_object(who, 
        HIG"MUD 是大家娱乐休闲的地方，需要你我的共同维护与关爱，请遵守玩家规则！\n"
        HIR"刑期已满，你被释放了！\n"NOR);
        return ;
}

int help(object me)
{
  write(@HELP
指令格式 : prison <ID> [<time>]
 
这是用来惩罚那些捣乱的玩家，将他们关押进黑牢。
时间的单位为分钟，如果没有 time 选项则默认关押
一小时。如果没有充分理由请不要使用此命令。
HELP
    );
    return 1;
}
