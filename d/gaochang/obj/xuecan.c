// medicine: xuecan.c
// by mei 
inherit ITEM;
void setup()
{}
void create()
{
        set_name(HIW "ѩ��" NOR, ({ "xue can", "can" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ֻ���ڼ�����ĵط����������ġ�ͨ��ѩ�׵�"+HIW+"ѩ��"+NOR+"��\n");
                set("value", 100);
        }
        setup();
}
int move(mixed dest, int silently)
{
    if (objectp(dest)){
        if (userp(dest))
         dest->apply_condition("xuecan_poison", 30);
    }
    return ::move(dest,silently);
}

