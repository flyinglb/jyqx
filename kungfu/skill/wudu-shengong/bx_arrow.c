// bx_arrow.c ��Ѫ��

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        string msg;
        
        if( !target ) target = offensive_target(me);
        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��Ѫ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        if((int)me->query_skill("duji",1) < 60)
                return notify_fail("�㶾��̫��,�޷�ʹ����һ������\n");

        if((int)me->query_skill("wudu-shengong",1) < 80)
                return notify_fail("���嶾�񹦵Ĺ����������޷����ñ�Ѫ����\n");
        
        if((int)me->query("max_neili") < 500)
                return notify_fail("��������Ϊ����, �޷���Ѫ�ɼ���\n");

        if((int)me->query("neili") < 200)
                return notify_fail("����������, �޷���Ѫ�ɼ���\n");
        /*Ҳ����Ҫ���ж�
        if( ((int)me->query("qi")/(int)me->query("max_qi")) 
        < (int)me->query("max_qi")/10)
                return notify_fail("����Ѫ����, �޷���Ѫ��\n");
        */
        msg = HIR"ͻȻ" + me->name() + "˫Ŀ���࣬��" + target->name() 
              + "ŭ�������"+ (me->query("gender")=="Ů��")?"��":"��" + "����ƴ�ˣ�\n"
              + HIW + "ֻ��"+ me->name() + "һҧ��⣬��ʱ���ﺬ��һ�ڶ�Ѫ��"
              + "�ſھ���" + target->name() + "���˹�ȥ\n" + NOR;
        //�ɹ������������˺�
        //if() ...
        
        //�����˺�
        me->add("max_neili",random(50)+50);
        if(me->query("max_neili") < 0)
                me->set("max_neili",0);
        me->die();
        return 1;
}
