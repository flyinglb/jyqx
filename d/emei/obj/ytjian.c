//ytjian.c ���콣 
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(CYN "���콣" NOR,({"sky sword","sword","jian"}));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�˽��й������ط򸾴��죬�����������\n");
                set("material", "steel");
                set("no_drop", "��˱���������������󰡡�\n");
                set("no_get", "���ˣ�������ĳ�����\n");
                set("no_put", "��ϧ���ɡ�\n");
                set("value",100);
                set("wield_msg", CYN "���콣�����߰�Ծ�����ʣ�����$N���У������
�貵ĺ��⣬���Ϊ֮��ɫ��\n" NOR);
                set("unwield_msg", CYN "$N���н��⽥����������Ļ����������â��\n" NOR);
       }
       init_sword(300);
       setup();
}

