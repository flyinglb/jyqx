inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name(HIC "���������" NOR, ({"heiyugao"}));
        set("unit", "��");
        set("long", "����һ��ǧ�꼫�������Ƶĵĺ��������,��˵������������\n");
        setup();
}

int do_eat(string arg)
{
if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
if(arg=="heiyugao")
{
       this_player()->set_temp("nopoison", 1);
       this_player()->receive_curing("jing", 200);
       this_player()->receive_curing("qi", 200);
       tell_object(this_player(), HIG "��ֻ��һ���������߾�������ѭ����һ�����죬������
�������ˣ�\n" NOR );
       destruct(this_object());
}
return 1;
}
