// sengmao.c
 
#include <ansi.h> 
#include <armor.h> 
 
inherit HEAD; 
 
void create() 
{ 
        set_name( HIR "ɮñ" NOR, ({ "seng mao", "mao" }) ); 
        set_weight(500); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "��"); 
                set("long", "����һ����ɮ����ɮñ��\n"); 
                set("value", 100); 
                set("material", "head"); 
                set("armor_prop/armor", 10); 
                set("xueshan",1); 
        } 
        setup(); 
} 
