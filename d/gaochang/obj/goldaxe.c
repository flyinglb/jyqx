// yuxiao.c
#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
    set_name(YEL "�ƽ�" NOR, ({"axe","gold axe"}));
    set_weight(210000);

    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "����һ��"+YEL+"�ƽ�"+NOR+"����ĸ�ͷ������ĩ���ƺ���Щ�ɶ���\n");
        set("value", 500000);
        set("flag",1);
        set("get_��1",1);
        set("material", "gold");
        set("wield_msg", "$N�ӱ��ϰγ�һ��"+YEL+"�ƽ�"+NOR+"���������С�\n");
        set("unwield_msg", "$N��һ��"+YEL+"�ƽ�"+NOR+"���ڱ��ϡ�\n");
          set("weapon_prop/dodge", 50);
      }  
    init_axe(500,1);
    setup();
    }
void init()
{
      if (environment()==this_user())
            add_action("do_pick","pick");
}
   
int do_pick(string arg)
{
        object me,ob,ob1;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (query("get_��1"))
        if( arg=="����") {
             ob=new("/d/gaochang/obj/yu");
            if (ob->move(me)){
                     write("��Ť�����������м���һ�����\n");
                         add("get_��1",-1);   {
             ob1=new("/d/gaochang/obj/goldaxe1");
             this_object()->move(environment(me));
             ob1->move(me);
             destruct(this_object());
             return 1;
        }         
             }else
                     write("��Ť����������������ʲôҲû�С�\n");
             return 1;
       }
        return 0;
}

