// newdan.c ������·��
// 99-11-10 15:04 By victori

#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_eat", "eat");  
}
void create()
{
        set_name(HIC"������·��"NOR, ({"new dan", "dan"}));          
        set("unit", "��");
        set("value", 10000);
        set("long", "����һ�����ϵ��������͸��ս��뽭�������ֳԵ�
�ɵ�����˵�����ޱȣ��˼����С�\n");
        setup();
}
int do_eat(string arg)
{
        object me=this_player();
        if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
        if (me->is_busy() )
                return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
        if (me->query("tmarks/��",1)>0)
                return notify_fail("��ʲô������Թ��˻���ԣ���\n");
        if (me->query("combat_exp")>0)
              return notify_fail("��ʲô�����㶼���������˻���ԣ���\n");
        else
        {
        me->set("combat_exp", 5000);                    
        me->set("potential", 5000);
        message_vision(HIW"$N����һ��������·����һ�������ӵ������𣬶�ʱȫ�����������\n"NOR,me);
        tell_object(me,HIY"ڤڤ�к��������������˵������ô����ˬ�ɣ�ף��һ·���ˣ���\n"NOR,);
        me->set("tmarks/��",1);
        me->start_busy(2);
        destruct(this_object());
        return 1;
}}
