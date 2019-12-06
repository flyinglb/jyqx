// purip.c
// Created by Eatdami@MX (10/12/2000)

#define SYNTAX  "ָ���ʽ��purip [IP]  because <ԭ��>] \n"
inherit F_CLEAN_UP;

private int do_purge_players(string ip);

int main(object me, string arg)
{
        string ip, reason;
        string status;

        status = SECURITY_D->get_status(me);
        if(query_wiz_level(status) < query_wiz_level("(admin)"))
                return notify_fail("��û��Ȩ��ʹ�����ָ�\n");

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
//        message("system", "\n*** ������Ҵ浵�����У����Ժ�.... ***\n", users());
        write("\n*** ������Ҵ浵�����У����Ժ�.... ***\n");
        write("�����У�");
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
        write("\n\nԭ���ܹ��� " + ppl_cnt + " λʹ���ߡ�\n");
        write( count + " ���ƻ��� IP: " + ip + " ��������ˡ�\n");
        write("�����ܹ��� " + (ppl_cnt - count) + " λʹ���ߡ�\n");
        log_file("static/PURIP", sprintf("[%s] %s cleaned up %d characters who is a fucking evil ( IP: %s ) \n"
                "\t\tResulting statistics: %d characters remaining.\n",
                ctime(time())[0..15], geteuid(this_player(1)), count, ip, ppl_cnt - count));


        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ��purge < IP >  because <ԭ��>

��������ƻ���IP�ϵ�ʹ���ߡ�
HELP
        );
    return 1;
}

