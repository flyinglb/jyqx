// kuzhi.c ��֦
#include <weapon.h>
inherit SWORD;
int do_snap(string arg);
void create()
{
    set_name("��֦", ({ "ku zhi","zhi" }) );
    set_weight(350);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "һ���ɿݵ���֦������������(snap)�����Ρ�\n");
        set("unit", "��");
        set("value", 10);
        set("flag",2);
        set("wield_msg", "$Nץ��һ��$n���������е�������\n");
    }
    init_sword(1,2);
    setup();
}
void init()
{
    add_action("do_snap","snap");
}
int do_snap(string arg)
{
     object kuzhi;
     if( !arg || !id(arg) )
         return notify_fail("������ʲô��\n");
     if (query("name")=="�ϵ��Ŀ�֦") return 0;
        set_name("�ϵ��Ŀ�֦", ({ "duan zhi","zhi" }) );
        set("long", "һ���ϵ��Ŀ�֦��\n");
        set("value", 0);
     if (environment()){
        if (environment()==this_player())
                message_vision("$N���ְѿ�֦�۳����Ρ�\n", this_player());
        else
                message_vision("$Nһ�Űѿ�֦�ȳ����Ρ�\n", this_player());
        kuzhi=new(__FILE__);
        kuzhi->do_snap("zhi");
        kuzhi->move(environment(this_object()));
    }
    return 1;
}

