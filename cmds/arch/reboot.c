// reboot.c

#include <login.h>
#include <mudlib.h>

string wiz_name,wiz_id;
protected void do_shutdown()
{
        shutdown(0);
}

int main(object me, string arg)
{
        string wiz_status;
        me = this_player () ;

        if( me != this_player(1) ) return 0;
        
        wiz_status = wizhood(me);
        if(query_wiz_level(wiz_status) < query_wiz_level("(arch)"))
                return notify_fail("ֻ�� (arch) ���ϵ���ʦ������������" + CHINESE_MUD_NAME + "\n");
        if(arg == "none") {
                remove_call_out("countdown");
                message("system",HIY"��"+CHINESE_MUD_NAME+"�������������ȡ����\n"NOR, users());
                return 1;
        }
        wiz_name = me->query("name");
        wiz_id = me->query("id");
        if(arg == "now") {
                if(query_wiz_level(wiz_status) < query_wiz_level("(admin)"))
                        return notify_fail("ֻ�� (admin) ��ʦ����Ȩ��������" + CHINESE_MUD_NAME + "\n");
                message("system",HIR+"�����ע�⣡"+HIY"��"+CHINESE_MUD_NAME+"��"NOR+"����"+WHT"ʮ����"NOR+
                "������������\n���������������̣�����\n" NOR,users() );
                call_out("countdown", 10, 1);
        } else {
                message("system",HIR+"�����ע�⣡"+HIY"��"+CHINESE_MUD_NAME+"��"NOR+"����"+WHT"������"NOR+
                "������������\n��ץ��ʱ������׼������������ʱ���̣���\n" NOR,users() );
                call_out("countdown", 60, 3);
        }
        return 1;
}

protected void countdown(int min)
{
        min--;
        if( min ) {
                message("system",HIR+"��ע�⣡����"+WHT+"����" + chinese_number(min) + "����"+NOR+
                "��ʱ��ϵͳ��Ҫ���������ˣ�\n��ץ��ʱ����̣���\n"+NOR,users() );
                call_out("countdown", 60, min);
        } else {
                message("system",HIW+"��������"+HIY+"��"+CHINESE_MUD_NAME+"��"+NOR+
                " ����\n���Ժ�һ�����ٵ�½����лл��\n"NOR,users() );
                write_file(REBOOTFILE,sprintf("%s��%s��:%d",wiz_name,wiz_id,time()),1);
                do_shutdown();
        }
}


int help (object me)
{
        write(@HELP
ָ���ʽ: reboot [now]
 
��������Ϸ, ϵͳ�Ὺʼ������ʱ, �������������𶯡�
�� now ѡ��ʱ��ϵͳ����ʮ���������������ã�����
HELP);
        return 1;
}

