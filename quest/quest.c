#include <ansi.h>

inherit F_CLEAN_UP;
int time_period(int timep, object me);
int main(object me, string arg)
{
        int nowtime = time();
        mapping quest;
        if(!(quest =  me->query("quest")))
               return notify_fail("������û���κ�����\n");
        write("�����ڵ�������" + quest["quest_type"] + "��" + quest["quest"] + "����\n");
        nowtime = (int) me->query("task_time") - time();
        if( nowtime  > 0 )
                time_period(nowtime, me);
        else
                write("�������Ѿ�û���㹻��ʱ����������ˡ�\n");

        return 1;
}
int time_period(int timep, object me)
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
        tell_object(me,"�㻹��" + time + "ȥ�������\n");
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : quest  ���ָ�������ʾ���㵱ǰ������
HELP
        );
        return 1;
}
