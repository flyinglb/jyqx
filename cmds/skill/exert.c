// exert.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string force, who;
        
        seteuid(getuid());

        if( me->is_busy() )
                return notify_fail("( ����һ��������û����ɣ�����ʩ���ڹ���)\n");

        if( !arg ) 
                return notify_fail("��Ҫ���ڹ���ʲô��\n");
        if( sscanf(arg, "%s %s", force, who) !=2 ) {
                force = arg;
        }
        if( force == "roar" && (string)environment(me)->query("short") == "��̨")
                return notify_fail("��̨�ϲ��������ڹ����õġ�\n");
                
        if( (environment(me)->query("no_fight") || environment(me)->query("sleep_room"))
        && ( force != "heal")
        && ( force != "jingheal")
        && ( force != "regenerate")
        && ( force != "recover")
        && ( force != "powerup")
        && ( force != "transfer")
        && ( force != "lifeheal")
        && ( force != "sneaky")
        && ( force != "daxiao")
        && ( force != "longhe")
        && ( force != "zhixin")
        && ( force != "shield") )
                return notify_fail("�����ֹս����\n");

        if( stringp(force = me->query_skill_mapped("force")) ) {
                notify_fail("����ѧ���ڹ���û�����ֹ��ܡ�\n");
                if( SKILL_D(force)->exert_function(me, arg) ) {
                        if( random(120) < (int)me->query_skill("force") )
                                me->improve_skill(force, 1, 1);
                        return 1;
                } else if( SKILL_D("force")->exert_function(me, arg) ) {
                        if( random(120) < (int)me->query_skill("force", 1) )
                                me->improve_skill("force", 1, 1);
                        return 1;
                }
                return 0;
        }

        return notify_fail("�������� enable ָ��ѡ����Ҫʹ�õ��ڹ���\n");
}

int help (object me)
{
        write(@HELP
ָ���ʽ��exert|yun <��������> [<ʩ�ö���>]

����������һЩ���칦�ܣ������Ҫָ��<��������>��<ʩ�ö���>����п��ޡ�
����ʹ��ĳһ���ڹ������칦��֮ǰ����������� enable ָ����ָ����Ҫʹ��
���ڹ���

��ο� help force �ɵ�֪һЩ�󲿷��ڹ����еĹ��ܣ����������õ��ڹ�����
��û�иù��ܣ���һ�Ի�ο�����˵����֪��

ע�������ı��Լ����ڹ�����ԭ�����������������ֱ��ת����ȥ������
    �ӣ���ʼ��

HELP
        );
        return 1;
}
