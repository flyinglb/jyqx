#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
    set_name( HIM "�Ž�" HIY" ����" NOR, ({ "tianqing" }) );
    set_weight(5000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("dynamic_quest", "/d/npc/duanyu");
            set("long", "����˵��һ����֪����һ���������׵ı�����\n");
          }
    init_sword(120);
    setup();
}
