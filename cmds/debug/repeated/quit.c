// quit.c
// modified by wind
#include <ansi.h>;
#include <command.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

int slow_quit(object);
string time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";
        
        return time;
}

void create()
{
        seteuid(getuid());
        set("name", "����ָ��");
        set("id", "quit");
        set("channel_id", "���߾���");
}

int main(object me, string arg)
{
        int i;
        object *inv, link_ob, env;
	env = environment(me);

        if( LOGIN_D->get_madlock())
                return notify_fail("ʱ���Ѿ���գ�û�����ܹ��˳����ʱ���ˡ�\n");
        if ( me->is_busy() && !wizardp(me) )
		 return notify_fail("��������æ���������£������˳���Ϸ��\n");
	if ( objectp(env) && env->query("no_quit") )
		return notify_fail("�Բ������ﲻ���˳���\n");
        if (me->query_temp("sleeped")) me->set("marks/insleeping",1);

        if( me->over_encumbranced() )
                return notify_fail("���ϴ��Ķ���̫���ˣ��벻����Ϸ�ˡ�\n");

        link_ob = me->query_temp("link_ob");

        // We might be called on a link_dead player, so check this.
        if( link_ob ) {

                // Are we possessing in others body ?
                if( link_ob->is_character() ) {
                        write("��Ļ��ǻص�" + link_ob->name(1) + "�����ϡ�\n");
                        exec(link_ob, me);
                        link_ob->setup();
                        return 1;
                }

                link_ob->set("last_on", time());
                link_ob->set("last_from", query_ip_name(me));
                link_ob->save();
                destruct(link_ob);
        }
	if ( me->query_temp("will_quit") )
        	return notify_fail("���Ѿ�׼���˳��ˡ�\n");

	me->set_temp("will_quit",1);

	if ( !wizardp(me) )
	{
		call_out("slow_quit", random(5)+1, me);
		write(HIR "������˳���Ϸ�������ļ��У���ȴ� ����\n" NOR);
	}
	else
		slow_quit(me);
	return 1;
}

private int slow_quit(object me)
{
	int i,j;
	object *inv, link_ob;

        if( !wizardp(me) ) {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                        if( !inv[i]->query_autoload() )
                                DROP_CMD->do_drop(me, inv[i]);
        }
    
        write(HIY"лл�����١���ӹȺ������ ��ӭ�´�������\n"NOR);
        message("system", me->name() + "�뿪��Ϸ��\n", environment(me), me);

        CHANNEL_D->do_channel(this_object(), "sys",
                me->name() + "(" + me->query("id") + ")�뿪��Ϸ�ˡ������ " + reclaim_objects() + " ��������\n");
        me->save();
i=me->query("combat_exp")-me->query_temp("temp_exp");
        j=(int)(time()-me->query_temp("temp_time"));
        if (i < 0 ) i=0;
        if (j < 0 ) j=0;
        CHANNEL_D->do_channel(this_object(), "sys",me->name() + "(" + me->query("id") + ")�������߾�������"+i+"������ʱ�䣺"+ time_period(j,me) +"��\n");       
        me->save();
        destruct(me);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : quit | exit

����(��)����ʱ�뿪��Ϸʱ, �����ô�һָ�
HELP
    );
    return 1;
}
