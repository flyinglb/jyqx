//ytjian.c ���콣 
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(BLINK+HIC "���콣" NOR,({"sky sword","sword","jian"}));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�˽��й������ط򸾴��죬�����������\n");
                set("material", "steel");
                set("no_drop", "��˱���������������󰡡�\n");
                set("no_get", "���ˣ�������ĳ�����\n");
                set("no_beg", 1);
                set("no_steal", 1);
                set("value",100);
                set("wield_msg", BLINK""HIC "���콣�����߰�Ծ�����ʣ�����$N���У�������貵ĺ��⣬���Ϊ֮��ɫ��\n" NOR);
                set("unwield_msg", BLINK""HIC "$N���н��⽥����������Ļ����������â��\n" NOR);
       }
       init_sword(1000);
       setup();
}

void owner_is_killed()
{
       destruct(this_object());
}
int query_autoload()
{
                return 1;
}
/*
void init()
{
        if( wizardp(environment()) )
                init_sword(1000);
        else
                init_sword(500);
}
*/
