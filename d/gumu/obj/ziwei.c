#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIC "��ޱ��" NOR, ({ "ziwei-sword" , "jian", "sword"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"һ�������ٿ��ǽ�ʱ������Լ�ĳߣ��������������������\n"
);
               set("weapon_prop/intelligence",2);
 		 set("value", 38000);
	       
                set("material", "steel");
                set("wield_msg", "ֻ��һ���׹�ģ�$N�Ѱ�$nװ�������С�\n");
                set("unequip_msg", "$N�����е�$n�Ѿ����ʡ�\n");
        }

        init_sword(200);
        setup();}
void owner_is_killed(object killer)
{
	set("long","һ�����ɷ����������˽������������������֮һ��������"+HIY+killer->query("name")+NOR+"��\n");
	
}





