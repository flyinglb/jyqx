// jinshe3.c
// modify by risc 1/10/2001
inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>; 
void setup()
{}
void init()
{
        add_action("do_kan", "kan");
}
void create()
{
        set_name(YEL"��������ܸ��"NOR"�²�", ({ "jinshe-book3","book3", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "paper");
                set("no_drop", "�������������뿪�㡣\n");
                set("no_get", "�������������뿪�Ƕ���\n");
                set("no_put", "�����������ܷ����Ƕ���\n");
                set("long",
        "����һ���ñ�ֽд�ɵ��顣���飺��������ܸ����\n"
        "��Ƥ���ƣ������Ѿ�����ܾ��ˡ�(Ҳ��ֵ��kan)\n");
        }
}

int do_kan(string arg)
{
        object me = this_player();
        object where = environment(me);
        int pxlevel; 
        int neili_lost,jing_lost,times;
        string tmp;

        if(!arg || (sscanf(arg, "%s %d", tmp,times)!=2 )) 
            return notify_fail("ָ���ʽ��kan jinshe-book3 <����>\n");

        if (tmp!="jinshe-book3") return notify_fail("ָ���ʽ��kan jinshe-book3 <����>\n");
        if (times>30 || times<1) return notify_fail("ѧϰ��������һ�Σ����Ҳ���ܳ�����ʮ�Ρ�\n");
        if (where->query("pigging")) return notify_fail("�㻹��ר�Ĺ���ɣ�\n");
        if (me->is_busy()) return notify_fail("��������æ���ء�\n");
        if( me->is_fighting() ) return notify_fail("���޷���ս����ר�������ж���֪��\n");
        if( !me->query_skill("literate", 1)) return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");

        pxlevel = me->query_skill("jinshe-zhang", 1);
        if( (int)me->query("combat_exp") < (int)pxlevel*pxlevel*pxlevel/10 )
            return notify_fail("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
        if( me->query_skill("jinshe-zhang", 1) > 199)
            return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");

        message("vision", me->name() + "��ר�ĵ��ж�"YEL"������ܸ��\n"NOR, environment(me), me);
        write("�㿪ʼ�ж�������ܸ��\n"NOR,);

        neili_lost = 5;
        if( (int)me->query("neili") < neili_lost*times) 
        return notify_fail("�������������޷�������ô������书��\n");
        jing_lost = 15;
        if( (int)me->query("jing") < jing_lost*times )
        return notify_fail("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");

        me->receive_damage("jing", times*jing_lost);
        me->set("neili",(int)me->query("neili")-times*neili_lost);
        me->improve_skill("jinshe-zhang", times*((int)me->query_skill("literate", 1)/3+1));
        write(HIC"���ж���"+chinese_number(times)+"�н�����ܸ�������ĵá�\n"NOR,);
        return 1;
}
