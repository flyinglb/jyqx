#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
    set_name( WHT "���佣" NOR, ({ "zhenwujian" }) );
    set_weight(3000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("dynamic_quest", "/kungfu/class/wudang/zhang");
            set("long", "�䵱�ɵ�����֮����\n");
          }
  init_sword(400);
    setup();
}
