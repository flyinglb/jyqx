                 // tong-box.c

inherit ITEM;

void create()
{
        set_name("ͭ��", ({"tong he", "he"}));
        set_weight(50000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long","��ͭ�����Ӻܹ֣����濴���ƺ��Ǻܶ���ص���ϣ����ҷǳ��ء�\n");
                set("unit", "��");
        }
}

void init()
{
        if(environment()!=this_player()) return;
        add_action("do_open","open");
}

int do_open(string arg)
{
        object me, obj;
        me = this_player();

        if(!arg || (arg != "tong he" && arg != "he")) return 0;
        message_vision(HIY "$N��ͭ�з����˵��ϣ������˼������أ�ֻ��һ������춯��ͭ�о�Ȼ����˸�ͭ�ˡ�\n" NOR, me);
        obj = new("/d/npc/tong-ren");
        obj->move(environment(me));
        this_object()->move(VOID_OB);
        destruct(this_object());
        return 1;
}
