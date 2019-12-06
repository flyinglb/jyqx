//flyto
//by wind

#include <ansi.h>
inherit F_CLEAN_UP;

mapping xinfa_types=([
"taoism":         "��ѧ�ķ�",
"buddhism":       "�����ķ�",
"yunlong-xinfa":  "�����ķ�",
"shenlong-xinfa": "�����ķ�",
"kuihua-xinfa":   "�����ķ�",
"mizong-xinfa":   "�����ķ�",
"yunv-xinfa":     "��Ů�ķ�",
]);


int main(object me, string arg)
{
	object obj;
	string msg;
        string *skill;
        int i,canfly;

	if( !arg ) return notify_fail("��Ҫȥ˭���\n");

	if (me->is_ghost())
		return notify_fail("���Ķ�Ҳ�ɲ��ˣ�\n");

	if (me->is_busy())
		return notify_fail("����æ���أ�\n");
	if( me->is_fighting() )
		return notify_fail("ս���в�����ɣ�\n");
	if( me->query("sleeped"))
		return notify_fail("����˯���зɰ��ɣ�\n");

        if(me->query("jing")<15)
	return notify_fail("�����ڵľ����������ķ���ͨ��\n");        
        if(me->query("qi")<15)
	return notify_fail("�����ڵ������������ķ���ͨ��\n");        
        if(me->query("neili")<15)
	return notify_fail("�����ڵ��������������ķ���ͨ��\n");        
        if(me->query("jingli")<50)
	return notify_fail("�����ڵľ������������ķ���ͨ��\n");        


	obj = find_player(arg);
	if(!obj) obj = find_living(arg);
	if(!obj || !me->visible(obj)||!living(obj)) 
	return notify_fail("û�������һ����\n");
        if(environment(me)->query("no_fly"))
	return notify_fail("��������Ӧ���ķ���ͨ��\n");        
        if(obj->query("biwu"))
	return notify_fail("�㲻�ܷ����䳡��\n");        

        canfly=0;
        skill = keys(xinfa_types);
        for (i=0; i<sizeof(skill); i++) {
                if( !me->query_skill(skill[i],1)||!obj->query_skill(skill[i],1)) continue;
                if(random(me->query_skill(skill[i],1))>obj->query_skill(skill[i])/2) {
                           canfly=1;
                           break;
                }
        }
        if(i==7) { 
                me->receive_damage("jing",15);
                me->receive_damage("qi",15);
                me->set("neili",me->query("neili")-15); 
                me->set("jingli",me->query("jingli")-50); 
                return notify_fail("����֮���޿�֮ͨ�ķ���\n");                
        }
        message_vision(HIY "$N����"+xinfa_types[skill[i]]+"֮�ķ���ͨ,��ͼ����"+obj->query("name")+".\n" NOR, me);
        if(userp(obj)) 
                message_vision(HIY ""+me->query("name")+"����"+xinfa_types[skill[i]]+"֮�ķ���ͨ,����ͼ�����㴦��\n" NOR, obj);
        if(canfly&&random(10)>3) {
	        message_vision(HIY "ֻ��һ����������$N����Ӱ�Ѿ������ˡ�\n" NOR, me);
	        me->move(environment(obj));
	        message_vision(HIY "ֻ��һ��������,$N����ӰͻȻ��������ǰ��\n" NOR, me);
        }
        else message_vision(HIR "ֻ��$N���Ϻ������, ���ϱ仯, ȴʼ��û�����,������ʧ���ˡ�\n" NOR, me);
        me->receive_damage("jing",15);
        me->receive_damage("qi",15);
        me->set("neili",me->query("neili")-15); 
        me->set("jingli",me->query("jingli")-50); 
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : flyto <Ŀ��>
 
���ָ������ʹ����ͬ�ķ�����֮ǰ���Ի��ഫ��. Ŀ�������һ�����ŵ���һ�npc.
�����Ƿ�ɹ�ȡ���������Ƿ��п�֮ͨ�ķ����ķ�ǿ����һЩ��������.���Ŀ��npc
���ɼ������Զ��ɻ�ԭ�ء�
HELP
    );
    return 1;
}



