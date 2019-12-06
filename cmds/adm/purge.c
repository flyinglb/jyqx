// purge.c
//modify by byp@MX 2000/06/28
//
//�޸������������

#include <ansi.h>
#define SYNTAX  "ָ���ʽ��purge [<δ��������>] | [<ʹ��������> because <ԭ��>] \n"
#define MINDAY 30
#define DAYERRO "���δ������������Ϊ" + CHINESE_D->chinese_number(MINDAY) + "�졣\n"
inherit F_CLEAN_UP;

private int do_purge_players(int day);

int main(object me, string arg)
{
        string name, reason;
        string status, check;
        int day;

        status = wizhood(me);
        if( me!=this_player(1)
        || wiz_level(me) < wiz_level(status) )
                return notify_fail("��û��Ȩ��ʹ�����ָ�\n");

        if( !arg ) return notify_fail(SYNTAX);
        
        if( sscanf(arg, "%s because %s", name, reason)==2 ) {
                
                seteuid(getuid());
                if( file_size(DATA_DIR + "login/" + name[0..0] + "/" + name + __SAVE_EXTENSION__)<0 )
                        return notify_fail("û����λʹ���ߡ�\n");

                rm(DATA_DIR + "login/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
                rm(DATA_DIR + "user/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
                rm(DATA_DIR + "mail/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
                write( "ʹ���� " + capitalize(name) + " ɾ�����ˡ�\n");
                log_file("static/PURGE", sprintf("[%s] %s purged %s because %s.\n",
                ctime(time())[0..15], geteuid(this_player(1)), name, reason));

                return 1;
        }
        
        if( sscanf(arg, "%d %s", day, check) && day >= MINDAY && !check && sscanf(arg, "%s because %s", name, reason)!=2 ) 
                return do_purge_players(day);
        else if( sscanf(arg, "%d %s", day, check) && day < MINDAY && !check && sscanf(arg, "%s because %s", name, reason)!=2 ) 
                return notify_fail(DAYERRO);
        else
                return notify_fail(SYNTAX);

}

private int do_purge_players(int day)
{
        int i, j, ppl_cnt, count;
        string *dir, *ppls, name;
        mixed info;

        seteuid(getuid());
        message("system", "\n*** ������Ҵ��浵�У����Ժ�.... ***\n", users());
        write("�����У�");
        count = 0;
        ppl_cnt = 0;
        dir = get_dir(DATA_DIR + "login/");
        for(i=0; i<sizeof(dir); i++) {
                reset_eval_cost();
                write(dir[i]);
                ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
                ppl_cnt += sizeof(ppls);
                for(j=0; j<sizeof(ppls); j++) {
                        if( sscanf(ppls[j], "%s.o", name)==1 )
                                if( (string)SECURITY_D->get_status(name)!="(player)" )
                                        continue;
                        info = stat(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
                        if( (time()-(int)info[1])/86400 >= day ) {
                                rm(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
                                rm(DATA_DIR + "user/" + dir[i] + "/" + ppls[j]);
                                rm(DATA_DIR + "mail/" + dir[i] + "/" + ppls[j]);
                                count ++;
                        }
                }
        }
        write("\n\nԭ���ܹ��� " + ppl_cnt + " λʹ���ߡ�\n");
        write( count + " ������ " + day + " ��δ���ߵ�ʹ���߱�������ˡ�\n");
        write("�����ܹ��� " + (ppl_cnt - count) + " λʹ���ߡ�\n");
        log_file("static/PURGE", sprintf("[%s] %s cleaned up %d characters who didn't login for more than %d days\n"
                "\t\tResulting statistics: %d characters remaining.\n",
                ctime(time())[0..15], geteuid(this_player(1)), count, day, ppl_cnt - count));


        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ��purge [<δ��������>] | <ʹ��������> because <ԭ��>

���һ��ʹ���߻��������һ�������������ߵ�ʹ���ߡ�
HELP
        );
    return 1;
}

