#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( YEL "�嶾�ܴ�" NOR, ({ "wudumizhuan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("dynamic_quest", "/d/quanzhou/npc/limochou");
            set("long", "��Ī���Լ�׫д�Ŀ̶��ܴ���\n");
          }
    setup();
}
