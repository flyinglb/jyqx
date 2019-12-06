// snoop.c
// Modify By Byp@MX 

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
        object who;
        string flag, id;
        
        if( !arg ) {
                if( objectp(who = query_snooping(me)) ) {
                        write("你现在正在监听" + who->query("name") + "所收到的讯息。\n");
                        return 1;
                } else return help();
        } else if( arg=="none" ) {
//                      if( objectp(who = query_snooping(me))
//                      && wiz_level(who) >= wiz_level(me) )
//                      tell_object(who, HIW + me->name(1) + "停止监听你所收到的讯息。\n" NOR);
                        snoop(me);
                        write("Ok.\n");
                        return 1;
        } else if( sscanf(arg,"%s %s", flag, id) != 2 ){
                who = find_player(arg);
                if(!who) who = find_living(arg);
                if(!who || !me->visible(who)) return notify_fail("没有这个人。\n");

                if( wiz_level(me) <= wiz_level(who) )
                        return notify_fail("你没有监听" + who->name() + "讯息的权利。\n");

                if( me == who ) return notify_fail("请用 snoop none 解除监听。\n");
                
                snoop(me, who);
                write("你现在开始窃听" + who->name(1) + "所收到的讯息。\n");
                if( userp(who) ) log_file("SNOOP_PLAYER",
                        sprintf("%s(%s) snoops %s on %s.\n", me->name(1), geteuid(me), who->name(1),
                                ctime(time()) ) );
//              if( wizardp(who) && wizhood(me) != "(admin)")
//                      tell_object(who, HIW + me->name(1) + "开始监听你所收到的讯息。\n" + NOR);

                return 1;
        }
        
        who = find_player(id);
        if(!who) who = find_living(id);
        if( (!who || !me->visible(who)) && id != "all") return notify_fail("没有这个人....。\n");
        
        switch(flag) {
                case "add" : 
                        if(id == "all") {
                                users()->set("channel_snooping",1);
                                write("开始监听所有在线用户。\n");
                        } else {
                                who->set("channel_snooping",1);
                                write("开始监听"+who->name()+"\n");
                        }
                        break;
                case "del" : 
                        if(id == "all") {
                                users()->delete("channel_snooping",1);
                                write("取消监听所有在线用户。\n");
                        } else {
                                who->delete("channel_snooping");
                                write("取消监听"+who->name()+"\n");
                        }
                        break;
                default : 
                        return help();
                        break;
        }
        return 1;
}

int help()
{
        write(@TEXT
指令格式(1)：snoop <add | del> <USER ID | all>
指令格式(2)：snoop <USER ID | none>

第一个指令格式是打开或关闭监听某人的交谈信息。
当 user id 为 all 的时候是指所有在线用户。

第二个指令格式是打开或关闭单独监听某人的所有信息。
TEXT
        );
        return 1;
}
