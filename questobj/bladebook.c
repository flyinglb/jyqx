#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( RED "���ҵ���" NOR, ({ "daopu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("dynamic_quest", "/d/guanwai/npc/hufei");
            set("long", " ���ֻ�͵�ߵľ������ס�\n");
          }
    setup();
}
