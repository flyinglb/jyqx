//dragon blade ������
#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(CYN "������" NOR,({"dragon blade","dao"}));
        set_weight(50000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�˽��й������ط򸾴��죬�����������\n");
                set("material", "steel");
                set("no_drop", "��˱���������������󰡡�\n");
                set("no_get", "���ˣ�������ĳ�����\n");
                set("no_put", "��ϧ���ɡ�\n");
                set("no_steal", 1);
                set("value",100);
                set("wield_msg", CYN "������Ծ������ ��������貵ĺ��⣬���Ϊ֮��ɫ��\n" NOR);
                set("unwield_msg", CYN "$N���н��⽥����������Ļ����������â��\n" NOR);
       }
       init_blade(600);
       setup();
}
