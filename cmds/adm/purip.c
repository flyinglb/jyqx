// purip.c
// Created by Eatdami@MX (10/12/2000)

#define SYNTAX  "指令格式：purip [IP]  because <原因>] \n"
inherit F_CLEAN_UP;

private int do_purge_players(string ip);

int main(object me, string arg)
{
        string ip, reason;
        string status;

        status = SECURITY_D->get_status(me);
        if(query_wiz_level(status) < query_wiz_level("(admin)"))
                return notify_fail("你没有权力使用这个指令。\n");

        if( !arg ) return notify_fail(SYNTAX);
        
        if( sscanf(arg, "%s because %s", ip, reason)==2 ) {
                do_purge_players(ip);
                return 1;
        }
        
        else
                return notify_fail(SYNTAX);

}

private int do_purge_players(string ip)
{
        int i, j, ppl_cnt, count;
        string *dir, *ppls, name;
        object ob;

        seteuid(getuid());
//        message("system", "\n*** 整理玩家存档数据中，请稍候.... ***\n", users());
        write("\n*** 整理玩家存档数据中，请稍候.... ***\n");
        write("处理中：");
        count = 0;
        ppl_cnt = 0;
        dir = get_dir(DATA_DIR + "login/");
        for(i=0; i<sizeof(dir); i++) {
                reset_eval_cost();
                write(dir[i]+"\n");
                ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
                ppl_cnt += sizeof(ppls);
                for(j=0; j<sizeof(ppls); j++) {
                        if( sscanf(ppls[j], "%s.o", name)==1 )
                                if( (string)SECURITY_D->get_status(name)!="(player)" )
                                        continue;
                        if( find_player(name) )
                                continue;
                        else {
                                ob = new(LOGIN_OB);
                                ob->set("id",name);
                                if( catch(ob->restore()) )
                                        write("error player:"+name+"\n");
                        }
                        if( ob->query("last_from") == ip ) {
//                                rm(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
//                                rm(DATA_DIR + "user/" + dir[i] + "/" + ppls[j]);
                                write("evil player:"+name+"\n");
                                count ++;
                        }
                        destruct(ob);
                }
        }
        write("\n\n原来总共有 " + ppl_cnt + " 位使用者。\n");
        write( count + " 个破坏者 IP: " + ip + " 被清除掉了。\n");
        write("现在总共有 " + (ppl_cnt - count) + " 位使用者。\n");
        log_file("static/PURIP", sprintf("[%s] %s cleaned up %d characters who is a fucking evil ( IP: %s ) \n"
                "\t\tResulting statistics: %d characters remaining.\n",
                ctime(time())[0..15], geteuid(this_player(1)), count, ip, ppl_cnt - count));


        return 1;
}

int help(object me)
{
write(@HELP
指令格式：purge < IP >  because <原因>

清除所有破坏者IP上的使用者。
HELP
        );
    return 1;
}

