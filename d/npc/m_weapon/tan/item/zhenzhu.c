//zhenzhu.c
inherit ITEM;
void create()
{
        set_name( "ҹ����", ({ "yeming zhu","zhu"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ��ҹ���飬���Ƶķ�����͵Ĺ⣬����������װ�εĺö�����\n");
                set("value", 10000);
                set("material", "iron");
              }
}
