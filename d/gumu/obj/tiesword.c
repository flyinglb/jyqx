#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( CYN "������" NOR, ({ "xuantiesword", "xuantie sword", "sword" }) );
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"һ��ʮ�ֳ��ص��������˽������������������֮һ�������������\n"
);
               set("weapon_prop/intelligence",2);
 		 set("value", 38000);
	       
                set("material", "steel");
	        set("no_give", "�������������뿪�㡣\n");
	        set("no_drop", "�������������뿪�㡣\n");
	        set("no_get", "�������������뿪�Ƕ���\n");
                set("wield_msg", "ֻ������һ����$N�Ѱ�$nװ�������С�\n");
                set("unequip_msg", "$N�����е�$n�Ѿ����ʡ�\n");
                set("is_xuantie-sword", 1);
        }

        init_sword(600);
        setup();}
void owner_is_killed(object killer)
{
	set("long","һ��ʮ�ֳ��ص��������˽������������������֮һ��������"+HIY+killer->query("name")+NOR+"��\n");
	
}





