// qingke-m.c ������

inherit ITEM; 
inherit F_FOOD; 
 
void create() 
{ 
        set_name("������", ({"qingke mian", "mian"})); 
        set_weight(200); 
        if (clonep()) 
                set_default_object(__FILE__); 
        else { 
                set("long", "һ����з�ζ�������档\n"); 
                set("unit", "��"); 
                set("value", 200); 
                set("food_remaining", 4); 
                set("food_supply", 60); 
        } 
} 
