inherit ITEM;
void create()
{
    set_name("����", ({ "skeleton" }));
    set_weight(500);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long",
            "һ�߿�Ǭ�ĺ��ǡ�\n");
        set("value", 0);
        set("no_get","�ⶫ��һ����ɢ�����Ǳ��ɣ�\n");
    }
}
