// qiankun-xinfa Ǭ����Ų���ķ�
// by King 97.05
// Modify by risc 1/10/2001

#include <ansi.h>

inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_kan","kan");
}

void create()
{
        set_name("��Ƥ", ({ "qiankunbook", "skin" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", 
"����һ����Ƥ��һ����ë��һ��⻬����һ���ǡ�����ʥ
���ķ���Ǭ����Ų�ơ�ʮһ���֡�ԭ����������ֵ�һ��
����Ǭ����Ų�ơ��ķ����ഫ��������ɽ������������
�������ž����书���ͺúÿ�(kan)�Ȿ��ɡ�\n");
                set("value", 50000);
                set("material", "paper");

        }
}

int do_kan(string arg)
{
        object me = this_player();
        object where = environment(me);
        int qklevel, lvl,neili_lost,jing_lost;
        int times;
        string tmp;

        if(!arg||(sscanf(arg, "%s %d", tmp,times)!=2 ))
            return notify_fail("ָ���ʽ��kan qiankunbook <����>\n");
        if (tmp!="qiankunbook") return notify_fail("ָ���ʽ��kan qiankunbook <����>\n");
        if (times>30 || times<1) return notify_fail("ѧϰ��������һ�Σ����Ҳ���ܳ�����ʮ�Ρ�\n");
        if (where->query("pigging")) return notify_fail("�㻹��ר�Ĺ���ɣ�\n");
        if (me->is_busy()) return notify_fail("��������æ���ء�\n");
        if( me->is_fighting() ) return notify_fail("���޷���ս����ר�������ж���֪��\n");
        if( !me->query_skill("literate", 1)) return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
        
        if( (int)me->query("neili") < 1000 ) {
        write( HIC"��Ȼ���������Ϣһ�ң�֪�����ã�\n"NOR);
        me->unconcious();
        return 1;
        }
        if( !me->query_skill("jiuyang-shengong", 1) )
        return notify_fail("��û�о����������ͣ����ܶ�Ǭ����Ų�ơ�\n");

        jing_lost=40-(int)me->query("int");
        if( (int)me->query("jing") < times*jing_lost)
            return notify_fail("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");

        qklevel = me->query_skill("qiankun-danuoyi", 1);
        neili_lost = qklevel/10;
        if( neili_lost < 5) neili_lost = 5;
        lvl = qklevel/20;
        if( lvl < 1) lvl = 1;

        if ( me->query("gender") == "����" && qklevel > 99)
            return notify_fail("�����첻�㣬��ѧ��ȥ�����߻���ħ��\n");
        if ((int)me->query_skill("force", 1) < 150)
            return notify_fail("����ô������ڹ�����ѧǬ����Ų�ƣ�\n");
        if ((int)me->query("max_neili", 1) < 2500)
            return notify_fail("����ô����������ѧǬ����Ų�ƣ�\n");
        if ((int)me->query_skill("force", 1) < lvl)
            return notify_fail("��Ļ����ڹ���򻹲�����С���߻���ħ��\n");
        if ((int)(me->query("max_neili", 1)/15) < lvl)
            return notify_fail("���������򻹲�����С���߻���ħ��\n");
        if( (int)me->query("combat_exp") < (int)qklevel*qklevel*qklevel/10 )
            return notify_fail("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
            
        message("vision", me->name() + "ר���ж�Ǭ����Ų�ƣ���ɫ������죬����"+ 
                lvl + "�Ρ�\n", environment(me), me);
        me->receive_damage("jing", times*jing_lost);
        me->set("neili",(int)me->query("neili")-times*neili_lost);
        if( !me->query_skill("qiankun-danuoyi", 1) ) me->set_skill("qiankun-danuoyi", 0);
        me->improve_skill("qiankun-danuoyi", times*((int)me->query_skill("literate", 1)/3+1));
        write("���ж�"+chinese_number(times)+"�С�Ǭ����Ų�ơ��ķ��������ĵá�\n");
        return 1;
}
